<?php
/**
 * registry.php — the one walk of the vendored Khronos `vk.xml`.
 *
 * scripts/gen-vk-src.php turns what this returns into src/*.{h,c}, and
 * scripts/audit-registry.php re-measures the same thing against the same
 * file. They share this walk on purpose: an audit that re-implements the
 * generator's reading of the registry audits the re-implementation, not the
 * registry.
 *
 * Nothing here decides how anything crosses into PHP — that is the type
 * table in gen-vk-src.php. This file only says what the registry contains:
 * which commands and which structs are in scope, per class, and what their
 * parameters and members are declared as.
 *
 * Scope constants live here so both readers see one definition (spec §2).
 */

declare(strict_types=1);

/**
 * Feature block -> command class. The registry splits each core version into
 * an internal VK_BASE_/VK_COMPUTE_/VK_GRAPHICS_ trio plus the public
 * VK_VERSION_1_x that depends on them; all four merge into one class.
 */
const VK_FEATURES = [
    'VK_VERSION_1_0' => 'VK10',
    'VK_VERSION_1_1' => 'VK11',
    'VK_VERSION_1_2' => 'VK12',
    'VK_VERSION_1_3' => 'VK13',
    'VK_VERSION_1_4' => 'VK14',
];

/** Extension -> command class, or null for "structs only, no command class". */
const VK_EXTENSIONS = [
    'VK_KHR_surface' => 'KHRSurface',
    'VK_KHR_swapchain' => 'KHRSwapchain',
    'VK_KHR_wayland_surface' => 'KHRWaylandSurface',
    'VK_KHR_xcb_surface' => 'KHRXcbSurface',
    'VK_KHR_xlib_surface' => 'KHRXlibSurface',
    'VK_EXT_metal_surface' => 'EXTMetalSurface',
    'VK_EXT_metal_objects' => 'EXTMetalObjects',
    'VK_EXT_debug_utils' => 'EXTDebugUtils',
    'VK_KHR_portability_enumeration' => null,
    'VK_KHR_portability_subset' => null,
    'VK_EXT_layer_settings' => null,
];

/** Loader levels, mirrored from src/phpvk-bridge.h. */
const VK_LEVEL_GLOBAL = 0;
const VK_LEVEL_INSTANCE = 1;
const VK_LEVEL_DEVICE = 2;

function vkRegistryFail(string $msg): never
{
    fwrite(STDERR, "registry: {$msg}\n");
    exit(1);
}

/**
 * Does this element apply to the `vulkan` API? An absent api attribute means
 * "all"; `vulkansc` alone means "not us". Substring matching would be wrong:
 * "vulkansc" contains "vulkan".
 */
function vkApiApplies(DOMElement $el): bool
{
    $api = $el->getAttribute('api');
    if ($api === '') {
        return true;
    }

    return in_array('vulkan', array_map('trim', explode(',', $api)), true);
}

/**
 * Parse one <member> or <param> into its parts.
 *
 * The registry spells a declaration as text around <type> and <name>
 * children, so the pieces are read positionally rather than by regex over
 * the whole thing:
 *
 *   <member optional="true">const <type>void</type>* <name>pNext</name></member>
 *     pre="const " type="void" mid="*" name="pNext" post=""
 *   <member><type>char</type> <name>deviceName</name>[<enum>VK_MAX…</enum>]</member>
 *     post="[VK_MAX…]" -> dims ["VK_MAX…"]
 *
 * @return array{type: string, name: string, ptr: int, const: bool, dims: list<string>, ctype: string, raw: string}
 */
function vkParseDecl(DOMElement $el, string $ctx): array
{
    $pre = '';
    $type = '';
    $mid = '';
    $name = '';
    $post = '';
    $stage = 0;

    foreach ($el->childNodes as $node) {
        if ($node->nodeType === XML_ELEMENT_NODE && $node->nodeName === 'comment') {
            continue;
        }
        $text = $node->textContent;
        if ($node->nodeType === XML_ELEMENT_NODE && $node->nodeName === 'type' && $stage === 0) {
            $type = trim($text);
            $stage = 1;
            continue;
        }
        if ($node->nodeType === XML_ELEMENT_NODE && $node->nodeName === 'name' && $stage <= 1) {
            $name = trim($text);
            $stage = 2;
            continue;
        }
        if ($stage === 0) {
            $pre .= $text;
        } elseif ($stage === 1) {
            $mid .= $text;
        } else {
            $post .= $text;
        }
    }

    if ($type === '' || $name === '') {
        vkRegistryFail("{$ctx}: declaration has no <type> or <name>: "
            . preg_replace('/\s+/', ' ', trim($el->textContent)));
    }
    /*
     * A shape the member table cannot express is recorded, not fatal, here:
     * the registry is full of declarations this binding never touches (NV
     * cluster acceleration structures carry bit-fields), and the whole file
     * is parsed before scope is known. The generator turns an unsupported
     * shape into a hard failure naming the member when — and only when — it
     * is reached by something in scope.
     */
    $unsupported = null;
    if (str_contains($post, ':')) {
        $unsupported = 'bit-field';
    }

    $dims = [];
    if (preg_match_all('/\[([^\]]*)\]/', $post, $dm)) {
        foreach ($dm[1] as $d) {
            $d = trim($d);
            if ($d === '') {
                $unsupported ??= 'unsized array';
            }
            $dims[] = $d;
        }
    }

    $ptr = substr_count($mid, '*');
    $isConst = str_contains($pre, 'const');
    $ctype = preg_replace('/\s+/', ' ', trim(trim($pre) . ' ' . $type . ' ' . trim($mid)));

    return [
        'type' => $type,
        'name' => $name,
        'ptr' => $ptr,
        'const' => $isConst,
        'dims' => $dims,
        'ctype' => $ctype,
        'unsupported' => $unsupported,
        'raw' => preg_replace('/\s+/', ' ', trim($el->textContent)),
    ];
}

/**
 * Load the registry.
 *
 * @return array{
 *   types: array<string, array<string, mixed>>,
 *   commands: array<string, array<string, mixed>>,
 *   blocks: array<string, array{commands: list<string>, types: list<string>}>,
 *   constants: array<string, string>,
 * }
 *   blocks is keyed by feature or extension name and holds what its
 *   <require> elements name, aliases included (callers filter).
 *   constants is the "API Constants" block, raw C text per name.
 */
function vkRegistryLoad(string $xmlPath): array
{
    if (!is_file($xmlPath)) {
        vkRegistryFail("missing {$xmlPath}");
    }
    $doc = new DOMDocument();
    $doc->preserveWhiteSpace = true;
    if (!$doc->load($xmlPath, LIBXML_NOCDATA)) {
        vkRegistryFail("cannot parse {$xmlPath}");
    }
    $xp = new DOMXPath($doc);

    // ---- types -------------------------------------------------------
    $types = [];
    foreach ($xp->query('/registry/types/type') as $t) {
        /** @var DOMElement $t */
        if (!vkApiApplies($t)) {
            continue;
        }
        $name = $t->getAttribute('name');
        if ($name === '') {
            $nameEl = $t->getElementsByTagName('name')->item(0);
            $name = $nameEl ? trim($nameEl->textContent) : '';
        }
        if ($name === '') {
            continue;
        }
        $category = $t->getAttribute('category');
        $alias = $t->getAttribute('alias');
        $entry = [
            'name' => $name,
            'category' => $category,
            'alias' => $alias !== '' ? $alias : null,
            'parent' => $t->getAttribute('parent') !== '' ? $t->getAttribute('parent') : null,
            'dispatchable' => null,
            'underlying' => null,
            'members' => [],
            'text' => preg_replace('/\s+/', ' ', trim($t->textContent)),
        ];

        if ($category === 'handle' && $alias === '') {
            $entry['dispatchable'] = str_contains($entry['text'], 'VK_DEFINE_NON_DISPATCHABLE_HANDLE') ? false : true;
        }
        if (in_array($category, ['bitmask', 'basetype'], true) && $alias === '') {
            $inner = $t->getElementsByTagName('type')->item(0);
            $entry['underlying'] = $inner ? trim($inner->textContent) : null;
            // `typedef void* VkRemoteAddressNV;` — a basetype that is a pointer.
            $entry['underlyingPtr'] = substr_count($entry['text'], '*');
        }
        if (in_array($category, ['struct', 'union'], true) && $alias === '') {
            foreach ($t->getElementsByTagName('member') as $m) {
                /** @var DOMElement $m */
                if (!vkApiApplies($m)) {
                    continue;
                }
                $entry['members'][] = vkParseDecl($m, $name);
            }
        }

        // A name can appear twice (api-split definitions); the vulkan one wins.
        if (!isset($types[$name]) || $types[$name]['category'] === '') {
            $types[$name] = $entry;
        }
    }

    // ---- commands ----------------------------------------------------
    $commands = [];
    foreach ($xp->query('/registry/commands/command') as $c) {
        /** @var DOMElement $c */
        if (!vkApiApplies($c)) {
            continue;
        }
        $aliasName = $c->getAttribute('name');
        if ($aliasName !== '') {
            $commands[$aliasName] = [
                'name' => $aliasName,
                'alias' => $c->getAttribute('alias'),
                'ret' => null,
                'params' => [],
            ];
            continue;
        }
        $proto = $c->getElementsByTagName('proto')->item(0);
        if (!$proto) {
            continue;
        }
        $decl = vkParseDecl($proto, 'proto');
        $params = [];
        foreach ($c->childNodes as $node) {
            if ($node->nodeType !== XML_ELEMENT_NODE || $node->nodeName !== 'param') {
                continue;
            }
            /** @var DOMElement $node */
            if (!vkApiApplies($node)) {
                continue;
            }
            $params[] = vkParseDecl($node, $decl['name']);
        }
        $commands[$decl['name']] = [
            'name' => $decl['name'],
            'alias' => null,
            'ret' => $decl,
            'params' => $params,
        ];
    }

    // ---- feature / extension require sets ----------------------------
    $blocks = [];
    $collect = static function (DOMElement $el) use (&$blocks): void {
        $name = $el->getAttribute('name');
        $blocks[$name] ??= ['commands' => [], 'types' => []];
        foreach ($el->getElementsByTagName('require') as $req) {
            /** @var DOMElement $req */
            if (!vkApiApplies($req)) {
                continue;
            }
            foreach ($req->childNodes as $node) {
                if ($node->nodeType !== XML_ELEMENT_NODE) {
                    continue;
                }
                /** @var DOMElement $node */
                if (!vkApiApplies($node)) {
                    continue;
                }
                if ($node->nodeName === 'command') {
                    $blocks[$name]['commands'][] = $node->getAttribute('name');
                } elseif ($node->nodeName === 'type') {
                    $blocks[$name]['types'][] = $node->getAttribute('name');
                }
            }
        }
    };

    foreach ($xp->query('/registry/feature') as $f) {
        /** @var DOMElement $f */
        if (!vkApiApplies($f)) {
            continue;
        }
        $collect($f);
    }
    foreach ($xp->query('/registry/extensions/extension') as $e) {
        /** @var DOMElement $e */
        $supported = array_map('trim', explode(',', $e->getAttribute('supported')));
        if (!in_array('vulkan', $supported, true)) {
            continue;
        }
        $collect($e);
    }

    // ---- API constants -----------------------------------------------
    /*
     * `<enums name="API Constants">` holds the hardcoded numbers the header
     * boilerplate defines — VK_UUID_SIZE, VK_MAX_MEMORY_TYPES and the rest.
     * They are registry content, not a crossing decision, and they are the
     * only way to know how long a `T[VK_SOMETHING]` member is without
     * asking a C compiler. The generated C never needs them (it writes
     * `sizeof(s->m) / sizeof(s->m[0])`); the struct guard does.
     *
     * The raw C text is kept, not a parsed number: several of these are
     * `(~0U)` and friends, which are not lengths and must not look like one.
     */
    $constants = [];
    foreach ($xp->query('/registry/enums[@name="API Constants"]/enum') as $e) {
        /** @var DOMElement $e */
        if (!vkApiApplies($e)) {
            continue;
        }
        $name = $e->getAttribute('name');
        $value = $e->getAttribute('value');
        if ($name === '' || $value === '' || isset($constants[$name])) {
            continue;
        }
        $constants[$name] = $value;
    }

    return [
        'types' => $types,
        'commands' => $commands,
        'blocks' => $blocks,
        'constants' => $constants,
    ];
}

/**
 * How many elements a `T[dim]` member holds.
 *
 * A dim is either a decimal literal or the name of an API constant whose
 * value is one. Anything else — an expression, a constant that is really a
 * sentinel — is a hard failure naming the member, because guessing a length
 * would make a guard that passes on the wrong number of bytes.
 */
function vkArrayLength(string $dim, array $reg, string $ctx): int
{
    $raw = $dim;
    if (!preg_match('/^\d+$/', $raw)) {
        $raw = $reg['constants'][$dim] ?? '';
        if ($raw === '') {
            vkRegistryFail("{$ctx}: array length '{$dim}' is not an API constant the registry defines");
        }
    }
    if (!preg_match('/^(\d+)U?$/i', trim($raw), $m)) {
        vkRegistryFail("{$ctx}: array length '{$dim}' resolves to '{$raw}', which is not a count");
    }

    return (int) $m[1];
}

/**
 * The registry's internal sub-blocks that merge into one core class.
 *
 * @return list<string>
 */
function vkFeatureBlockNames(string $feature): array
{
    if (!preg_match('/^VK_VERSION_(\d+)_(\d+)$/', $feature, $m)) {
        vkRegistryFail("not a core feature name: {$feature}");
    }

    return [
        "VK_BASE_VERSION_{$m[1]}_{$m[2]}",
        "VK_COMPUTE_VERSION_{$m[1]}_{$m[2]}",
        "VK_GRAPHICS_VERSION_{$m[1]}_{$m[2]}",
        $feature,
    ];
}

/**
 * Resolve a command's dispatch level from its first parameter, by walking the
 * handle `parent` chain. Nothing here is per-command knowledge: a first
 * parameter that is not a handle at all (vkCreateInstance takes a
 * VkInstanceCreateInfo*) is global.
 */
function vkCommandLevel(array $command, array $types): int
{
    $params = $command['params'];
    if ($params === []) {
        return VK_LEVEL_GLOBAL;
    }
    $first = $params[0];
    if ($first['ptr'] > 0) {
        return VK_LEVEL_GLOBAL;
    }

    $chain = [];
    $cursor = $first['type'];
    $seen = [];
    while ($cursor !== null && isset($types[$cursor]) && !isset($seen[$cursor])) {
        $seen[$cursor] = true;
        if (($types[$cursor]['category'] ?? '') !== 'handle') {
            break;
        }
        $chain[] = $cursor;
        $parent = $types[$cursor]['parent'] ?? null;
        // A handle may name several possible parents ("VkDevice,VkInstance").
        $cursor = $parent === null ? null : trim(explode(',', $parent)[0]);
    }

    if ($chain === []) {
        return VK_LEVEL_GLOBAL;
    }
    if (in_array('VkDevice', $chain, true)) {
        return VK_LEVEL_DEVICE;
    }
    if (in_array('VkInstance', $chain, true)) {
        return VK_LEVEL_INSTANCE;
    }

    return VK_LEVEL_GLOBAL;
}

/**
 * Everything in scope, bucketed per class, in the order the classes are
 * declared. A command or struct belongs to the FIRST bucket that requires it
 * — "the block it first appeared in", the same rule ext-opengl uses.
 *
 * Struct scope is the union of what the blocks require and every struct or
 * union reachable from those by value; a pointer member is bits and is never
 * followed, so it pulls nothing in.
 *
 * @return array{
 *   commands: array<string, array{class: string, block: string, kind: string, names: list<string>}>,
 *   structs: array<string, array{bucket: string, names: list<string>}>,
 *   order: list<string>,
 * }
 */
function vkRegistryScope(array $reg): array
{
    $types = $reg['types'];
    $blocks = $reg['blocks'];

    $commandBuckets = [];
    $structBuckets = [];
    $assignedCommand = [];
    $assignedStruct = [];
    $order = [];

    $isBindableStruct = static function (string $name) use ($types): bool {
        $t = $types[$name] ?? null;

        return $t !== null
            && in_array($t['category'], ['struct', 'union'], true)
            && $t['alias'] === null;
    };

    $addBucket = function (string $key, string $label, string $kind, array $blockNames)
        use ($reg, $blocks, &$commandBuckets, &$structBuckets, &$assignedCommand, &$assignedStruct, &$order, $isBindableStruct, $types): void {
        $commandBuckets[$key] ??= ['class' => $label, 'block' => $key, 'kind' => $kind, 'names' => []];
        $structBuckets[$key] ??= ['bucket' => $key, 'names' => []];
        $order[] = $key;

        foreach ($blockNames as $blockName) {
            $block = $blocks[$blockName] ?? null;
            if ($block === null) {
                continue;
            }
            foreach ($block['commands'] as $cmd) {
                $entry = $reg['commands'][$cmd] ?? null;
                if ($entry === null || $entry['alias'] !== null || isset($assignedCommand[$cmd])) {
                    continue;
                }
                $assignedCommand[$cmd] = $key;
                $commandBuckets[$key]['names'][] = $cmd;
            }
            foreach ($block['types'] as $typeName) {
                if (!$isBindableStruct($typeName) || isset($assignedStruct[$typeName])) {
                    continue;
                }
                $assignedStruct[$typeName] = $key;
                $structBuckets[$key]['names'][] = $typeName;
            }
        }
    };

    foreach (VK_FEATURES as $feature => $class) {
        $addBucket($class, $class, 'feature', vkFeatureBlockNames($feature));
    }
    foreach (VK_EXTENSIONS as $extension => $class) {
        $addBucket($class ?? 'EXT:' . $extension, $class ?? '', 'extension', [$extension]);
        // The bucket key doubles as the audit marker key, so remember the
        // registry name it was measured from.
        $commandBuckets[$class ?? 'EXT:' . $extension]['block'] = $extension;
        $structBuckets[$class ?? 'EXT:' . $extension]['bucket'] = $class ?? 'EXT:' . $extension;
    }

    // ---- transitive by-value struct closure --------------------------
    $queue = [];
    foreach ($structBuckets as $key => $bucket) {
        foreach ($bucket['names'] as $n) {
            $queue[] = [$n, $key];
        }
    }
    while ($queue !== []) {
        [$name, $key] = array_shift($queue);
        foreach ($types[$name]['members'] ?? [] as $member) {
            if ($member['ptr'] > 0) {
                continue;   // a pointer is bits; it is never followed
            }
            $mt = $member['type'];
            if (!$isBindableStruct($mt) || isset($assignedStruct[$mt])) {
                continue;
            }
            $assignedStruct[$mt] = $key;
            $structBuckets[$key]['names'][] = $mt;
            $queue[] = [$mt, $key];
        }
    }

    return [
        'commands' => $commandBuckets,
        'structs' => $structBuckets,
        'order' => $order,
    ];
}
