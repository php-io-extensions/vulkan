<?php

declare(strict_types=1);

/*
 * Every stub declaration is what the loaded extension exposes: the stubs are
 * the source of truth, so a binding missing from the build fails here.
 * vk_metal.stub.php is built on macOS only.
 */

function stubFiles(): array
{
    $files = glob(__DIR__ . '/../stubs/*.stub.php') ?: [];
    if (PHP_OS_FAMILY !== 'Darwin') {
        $files = array_values(array_filter(
            $files,
            static fn (string $file): bool => ! str_ends_with($file, 'vk_metal.stub.php'),
        ));
    }
    sort($files);

    return $files;
}

function stubDeclarations(): array
{
    $declared = [];

    foreach (stubFiles() as $stub) {
        $class = null;
        foreach (file($stub) as $line) {
            if (preg_match('/^(?:final\s+)?(?:class|enum)\s+(\w+)/', $line, $m)) {
                $class = $m[1];
                $declared[$class] ??= [];
            } elseif ($class !== null && preg_match('/^\s+(?:public|private)\s+(?:static\s+)?function\s+(\w+)/', $line, $m)) {
                $declared[$class][] = $m[1];
            }
        }
    }

    return $declared;
}

it('exposes every class, method, function and constant the stubs declare', function (): void {
    foreach (stubDeclarations() as $class => $methods) {
        expect(class_exists($class) || enum_exists($class))->toBeTrue("{$class} is missing");

        foreach ($methods as $method) {
            expect(method_exists($class, $method))->toBeTrue("{$class}::{$method}() is missing");
        }
    }

    foreach (stubFiles() as $stub) {
        foreach (file($stub) as $line) {
            if (preg_match('/^function\s+(\w+)/', $line, $m)) {
                expect(function_exists($m[1]))->toBeTrue("{$m[1]}() is missing");
            } elseif (preg_match('/^const\s+(\w+)/', $line, $m)) {
                expect(defined($m[1]))->toBeTrue("{$m[1]} is missing");
            }
        }
    }
});

it('reports its version', function (): void {
    expect(phpversion('vulkan'))->toBe('0.10.0');
});
