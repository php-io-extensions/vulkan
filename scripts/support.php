<?php

declare(strict_types=1);

/*
 * The support list: every command of the Vulkan registry at 1.4.309, the header floor this extension
 * builds against, marked bound when a stub declares the PHP function of the same name.
 *
 *   php84 scripts/support.php           writes SUPPORT.md and the README badge
 *   php84 scripts/support.php --check   exits 1 when either differs (the date is not compared)
 *
 * vk.xml is read at the Vulkan-Headers v1.4.309 tag, cached under scripts/.support-cache/. A member
 * is a command a core version or a supported extension requires for the `vulkan` API: Vulkan SC only
 * commands, alias commands (a promoted extension's second name for a core command), and the commands
 * of deprecated or obsoleted extensions are not members. Each sits under the first version or
 * extension that requires it, versions first.
 */

const SUPPORT_LABEL = 'Vulkan API';
const SUPPORT_VERSION = '1.4.309';
const SUPPORT_URL = 'https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/v' . SUPPORT_VERSION . '/registry/vk.xml';

/** @return array<string, list<string>> version or extension => sorted command names */
function support_counted(string $registry): array
{
    $xml = simplexml_load_string($registry);
    if ($xml === false) {
        throw new RuntimeException('Cannot read vk.xml.');
    }
    $aliases = [];
    $forVulkan = [];
    // A command can be defined twice, once per API (vkCreateDevice): it is Vulkan's when either definition is.
    foreach ($xml->xpath('/registry/commands/command') as $command) {
        $name = (string) ($command['name'] ?? $command->proto->name);
        if (isset($command['alias'])) {
            $aliases[$name] = true;
        }
        if (! isset($command['api']) || support_for_vulkan((string) $command['api'])) {
            $forVulkan[$name] = true;
        }
    }
    $owners = [];
    foreach ($xml->xpath('/registry/feature') as $feature) {
        if (support_for_vulkan((string) $feature['api'])) {
            $owners[(string) $feature['name']] = $feature;
        }
    }
    foreach ($xml->xpath('/registry/extensions/extension') as $extension) {
        if (support_for_vulkan((string) $extension['supported']) && ! isset($extension['deprecatedby']) && ! isset($extension['obsoletedby'])) {
            $owners[(string) $extension['name']] = $extension;
        }
    }
    $counted = [];
    $seen = [];
    foreach ($owners as $owner => $node) {
        foreach ($node->require as $require) {
            if (isset($require['api']) && ! support_for_vulkan((string) $require['api'])) {
                continue;
            }
            foreach ($require->command as $command) {
                $name = (string) $command['name'];
                if (isset($aliases[$name]) || ! isset($forVulkan[$name]) || isset($seen[$name])) {
                    continue;
                }
                $seen[$name] = true;
                $counted[$owner][] = $name;
            }
        }
    }
    foreach ($counted as &$names) {
        sort($names, SORT_STRING);
    }
    unset($names);

    return $counted;
}

/** An `api` / `supported` list that names the Vulkan API (not only Vulkan SC, not `disabled`). */
function support_for_vulkan(string $apis): bool
{
    return in_array('vulkan', explode(',', $apis), true);
}

/** The free functions the stubs declare. @return array<string, true> */
function support_bound(string $stubDir): array
{
    $bound = [];
    foreach (glob(rtrim($stubDir, '/') . '/*.stub.php') ?: [] as $file) {
        foreach (support_functions(file_get_contents($file)) as $function) {
            $bound[$function] = true;
        }
    }

    return $bound;
}

/**
 * The top-level functions of one stub, without class methods.
 * @return list<string>
 */
function support_functions(string $source): array
{
    $tokens = token_get_all($source);
    $out = [];
    $depth = 0;
    foreach ($tokens as $i => $token) {
        if ($token === '{' || (is_array($token) && in_array($token[0], [T_CURLY_OPEN, T_DOLLAR_OPEN_CURLY_BRACES], true))) {
            $depth++;
        } elseif ($token === '}') {
            $depth--;
        } elseif (is_array($token) && $token[0] === T_FUNCTION && $depth === 0) {
            for ($j = $i + 1; is_array($tokens[$j]) && $tokens[$j][0] === T_WHITESPACE; $j++) {
            }
            if (is_array($tokens[$j]) && $tokens[$j][0] === T_STRING) {
                $out[] = $tokens[$j][1];
            }
        }
    }

    return array_values(array_unique($out));
}

/**
 * @param array<string, list<string>> $counted
 * @param array<string, true> $bound
 */
function support_render(array $counted, array $bound, string $library, string $date): string
{
    $sections = [];
    $hits = 0;
    $total = 0;
    $countedKeys = [];
    foreach ($counted as $owner => $keys) {
        $lines = [];
        $ownerHits = 0;
        foreach ($keys as $key) {
            $countedKeys[$key] = true;
            $isBound = isset($bound[$key]);
            $ownerHits += $isBound ? 1 : 0;
            $lines[] = '- [' . ($isBound ? 'x' : ' ') . "] `{$key}`";
        }
        $hits += $ownerHits;
        $total += count($keys);
        $sections[] = "## {$owner} ({$ownerHits} / " . count($keys) . ")\n\n" . implode("\n", $lines) . "\n";
    }
    $outside = array_map(static fn (string $f): string => "- `{$f}`", array_keys(array_diff_key($bound, $countedKeys)));
    sort($outside, SORT_STRING);

    return '# ' . SUPPORT_LABEL . " support\n\n"
        . support_summary($library, $hits, $total, $date) . "\n\n"
        . 'Generated by `php84 scripts/support.php` from the Vulkan ' . SUPPORT_VERSION . " registry (vk.xml) and `stubs/`. One line per command: `[x]` bound, `[ ]` not bound.\n\n"
        . implode("\n", $sections)
        . "\n## Bound outside the measured library\n\n"
        . "Functions the stubs declare that are not registry commands (the extension's own, alias names, deprecated extensions); none of them is counted.\n\n"
        . (count($outside) === 0 ? "None.\n" : implode("\n", $outside) . "\n");
}

function support_summary(string $library, int $hits, int $total, string $date): string
{
    return sprintf('%s — %d / %d members bound (%.1f%%) — %s', $library, $hits, $total, $total === 0 ? 0 : 100 * $hits / $total, $date);
}

function support_badge(string $label, int $bound, int $total): string
{
    $percent = sprintf('%.1f', $total === 0 ? 0 : 100 * $bound / $total);
    $message = str_replace('%20', '_', rawurlencode("{$percent}% ({$bound}/{$total})"));

    return "[![{$label}](https://img.shields.io/badge/" . str_replace(' ', '_', $label) . "-{$message}-blue?style=flat-square)](SUPPORT.md)";
}

/** Two support lists alike but for the date of their summary line. */
function support_same(string $a, string $b): bool
{
    $undated = static fn (string $s): string => preg_replace('/ — \d{4}-\d{2}-\d{2}$/m', '', $s);

    return $undated($a) === $undated($b);
}

/** The README with the badge line set: replaced where it is, else after the CI badge. */
function support_readme(string $readme, string $badge): string
{
    $lines = explode("\n", $readme);
    foreach ($lines as $i => $line) {
        if (str_starts_with($line, '[![' . SUPPORT_LABEL . ']')) {
            $lines[$i] = $badge;

            return implode("\n", $lines);
        }
    }
    foreach ($lines as $i => $line) {
        if (str_starts_with($line, '[![CI]')) {
            array_splice($lines, $i + 1, 0, [$badge]);

            return implode("\n", $lines);
        }
    }
    throw new RuntimeException('The README has no CI badge line to put the API badge after.');
}

/** @return array{int, int} bound and total, read back from a support list's summary line */
function support_totals(string $md): array
{
    preg_match('/ (\d+) \/ (\d+) members bound/', $md, $m);

    return [(int) $m[1], (int) $m[2]];
}

/** A pinned upstream file, downloaded once into the cache. */
function support_fetch(string $url, string $cache): string
{
    if (! is_file($cache)) {
        $body = @file_get_contents($url);
        if ($body === false) {
            throw new RuntimeException("Cannot download {$url}.");
        }
        @mkdir(dirname($cache), 0777, true);
        file_put_contents($cache, $body);
    }

    return file_get_contents($cache);
}

function support_main(array $argv): int
{
    $root = dirname(__DIR__);
    try {
        $counted = support_counted(support_fetch(SUPPORT_URL, "{$root}/scripts/.support-cache/vulkan-" . SUPPORT_VERSION . '/vk.xml'));
    } catch (RuntimeException $e) {
        fwrite(STDERR, $e->getMessage() . "\n");

        return 2;
    }
    $md = support_render($counted, support_bound("{$root}/stubs"), 'Vulkan ' . SUPPORT_VERSION, date('Y-m-d'));
    [$hits, $total] = support_totals($md);
    $readme = support_readme(file_get_contents("{$root}/README.md"), support_badge(SUPPORT_LABEL, $hits, $total));

    if (in_array('--check', $argv, true)) {
        $current = is_file("{$root}/SUPPORT.md") ? file_get_contents("{$root}/SUPPORT.md") : '';
        $same = support_same($current, $md) && $readme === file_get_contents("{$root}/README.md");
        fwrite(STDOUT, $same ? "SUPPORT.md and the badge are current.\n" : "SUPPORT.md or the badge differs: run php84 scripts/support.php.\n");

        return $same ? 0 : 1;
    }
    file_put_contents("{$root}/SUPPORT.md", $md);
    file_put_contents("{$root}/README.md", $readme);
    fwrite(STDOUT, "{$hits} / {$total}\n");

    return 0;
}

if (PHP_SAPI === 'cli' && isset($argv[0]) && realpath($argv[0]) === __FILE__) {
    exit(support_main($argv));
}
