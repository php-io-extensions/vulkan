<?php
/**
 * Shared plumbing for the Mac-side guards' self-tests.
 *
 * A guard that cannot fail is not a guard, so every one of them is run
 * against a fixture that breaks exactly the thing it is supposed to catch,
 * and against one that does not.
 */

declare(strict_types=1);

/**
 * Run a script and return [exitCode, combined output].
 *
 * @return array{0: int, 1: string}
 */
function runScript(string $script, array $args = []): array
{
    $cmd = escapeshellarg(PHP_BINARY) . ' ' . escapeshellarg($script);
    foreach ($args as $a) {
        $cmd .= ' ' . escapeshellarg($a);
    }
    $output = [];
    $code = 0;
    exec($cmd . ' 2>&1', $output, $code);

    return [$code, implode("\n", $output)];
}

/**
 * Copy a fixture into a scratch directory so a guard that writes (gen-zep
 * does) cannot dirty the committed tree.
 */
function stageFixture(string $fixture): string
{
    $dir = sys_get_temp_dir() . '/phpvk-fixture-' . bin2hex(random_bytes(6));
    mkdir($dir, 0755, true);

    $it = new RecursiveIteratorIterator(
        new RecursiveDirectoryIterator($fixture, FilesystemIterator::SKIP_DOTS),
        RecursiveIteratorIterator::SELF_FIRST
    );
    foreach ($it as $item) {
        $target = $dir . '/' . substr($item->getPathname(), strlen($fixture) + 1);
        if ($item->isDir()) {
            mkdir($target, 0755, true);
            continue;
        }
        if (!is_dir(dirname($target))) {
            mkdir(dirname($target), 0755, true);
        }
        copy($item->getPathname(), $target);
    }

    register_shutdown_function(static function () use ($dir): void {
        removeTree($dir);
    });

    return $dir;
}

function removeTree(string $dir): void
{
    if (!is_dir($dir)) {
        return;
    }
    $it = new RecursiveIteratorIterator(
        new RecursiveDirectoryIterator($dir, FilesystemIterator::SKIP_DOTS),
        RecursiveIteratorIterator::CHILD_FIRST
    );
    foreach ($it as $item) {
        $item->isDir() ? rmdir($item->getPathname()) : unlink($item->getPathname());
    }
    rmdir($dir);
}

final class Expect
{
    private array $problems = [];

    public function __construct(private readonly string $name)
    {
    }

    public function that(bool $ok, string $what): void
    {
        if (!$ok) {
            $this->problems[] = $what;
        }
    }

    public function finish(string $token): never
    {
        if ($this->problems !== []) {
            foreach ($this->problems as $p) {
                fwrite(STDERR, "{$this->name}: {$p}\n");
            }
            exit(1);
        }
        echo "{$token}\n";
        exit(0);
    }
}
