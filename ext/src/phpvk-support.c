/*
 * phpvk-support.c — marshalling only. See phpvk-support.h.
 */

#include "phpvk-support.h"

#include <string.h>

zend_long phpvk_arg_long(zval *z)
{
    if (!z) {
        return 0;
    }
    if (Z_TYPE_P(z) == IS_LONG) {
        return Z_LVAL_P(z);
    }
    if (Z_TYPE_P(z) == IS_DOUBLE) {
        return (zend_long) Z_DVAL_P(z);
    }
    if (Z_TYPE_P(z) == IS_TRUE) {
        return 1;
    }
    if (Z_TYPE_P(z) == IS_FALSE || Z_TYPE_P(z) == IS_NULL) {
        return 0;
    }
    if (Z_TYPE_P(z) == IS_STRING) {
        return ZEND_STRTOL(Z_STRVAL_P(z), NULL, 10);
    }

    return 0;
}

double phpvk_arg_double(zval *z)
{
    if (!z) {
        return 0.0;
    }
    if (Z_TYPE_P(z) == IS_DOUBLE) {
        return Z_DVAL_P(z);
    }
    if (Z_TYPE_P(z) == IS_LONG) {
        return (double) Z_LVAL_P(z);
    }
    if (Z_TYPE_P(z) == IS_TRUE) {
        return 1.0;
    }
    if (Z_TYPE_P(z) == IS_STRING) {
        return zend_strtod(Z_STRVAL_P(z), NULL);
    }

    return 0.0;
}

int phpvk_arg_bool(zval *z)
{
    if (!z) {
        return 0;
    }

    return zend_is_true(z) ? 1 : 0;
}

uint64_t phpvk_arg_u64(zval *z)
{
    /*
     * Reinterpretation, not conversion. PHP's int is signed 64-bit, so -1 is
     * the only way to write UINT64_MAX (VK_WHOLE_SIZE) and this is what makes
     * it work. Anything above PHP_INT_MAX cannot be written at all and wraps.
     */
    return (uint64_t) phpvk_arg_long(z);
}

const char *phpvk_arg_string(zval *z)
{
    if (!z || Z_TYPE_P(z) != IS_STRING) {
        return NULL;
    }

    return Z_STRVAL_P(z);
}

void *phpvk_arg_ptr(zval *z)
{
    zend_long bits = phpvk_arg_long(z);

    if (bits == 0) {
        return NULL;
    }

    return (void *) (uintptr_t) bits;
}

/* ------------------------------------------------------------- members ---- */

HashTable *phpvk_members(zval *members, const char *ctx)
{
    if (!members || Z_TYPE_P(members) == IS_NULL) {
        return NULL;
    }
    if (Z_TYPE_P(members) != IS_ARRAY) {
        php_error_docref(NULL, E_WARNING, "%s: members must be an array", ctx);

        return NULL;
    }

    return Z_ARRVAL_P(members);
}

int phpvk_check_keys(HashTable *ht, const char *const names[], size_t n, const char *ctx)
{
    zend_string *key;
    zend_ulong index;
    int ok = 1;

    if (!ht) {
        return 1;
    }

    ZEND_HASH_FOREACH_KEY(ht, index, key)
    {
        size_t i;
        int known = 0;

        if (!key) {
            php_error_docref(NULL, E_WARNING,
                "%s: unknown member '" ZEND_LONG_FMT "'", ctx, (zend_long) index);
            ok = 0;
            continue;
        }
        for (i = 0; i < n; i++) {
            if (strcmp(ZSTR_VAL(key), names[i]) == 0) {
                known = 1;
                break;
            }
        }
        if (!known) {
            php_error_docref(NULL, E_WARNING, "%s: unknown member '%s'", ctx, ZSTR_VAL(key));
            ok = 0;
        }
    }
    ZEND_HASH_FOREACH_END();

    return ok;
}

zval *phpvk_member_sub(HashTable *ht, const char *key)
{
    if (!ht) {
        return NULL;
    }

    return zend_hash_str_find(ht, key, strlen(key));
}

zend_long phpvk_member_long(HashTable *ht, const char *key)
{
    return phpvk_arg_long(phpvk_member_sub(ht, key));
}

uint64_t phpvk_member_u64(HashTable *ht, const char *key)
{
    return phpvk_arg_u64(phpvk_member_sub(ht, key));
}

double phpvk_member_double(HashTable *ht, const char *key)
{
    return phpvk_arg_double(phpvk_member_sub(ht, key));
}

int phpvk_member_bool(HashTable *ht, const char *key)
{
    zval *v = phpvk_member_sub(ht, key);

    return v ? phpvk_arg_bool(v) : 0;
}

void *phpvk_member_ptr(HashTable *ht, const char *key)
{
    return phpvk_arg_ptr(phpvk_member_sub(ht, key));
}

int phpvk_member_chars(HashTable *ht, const char *key, char *dst, size_t n, const char *ctx)
{
    zval *v = phpvk_member_sub(ht, key);
    size_t len;

    if (n == 0) {
        return 1;
    }
    memset(dst, 0, n);
    if (!v || Z_TYPE_P(v) != IS_STRING) {
        return 1;
    }
    len = Z_STRLEN_P(v);

    /*
     * A string that does not fit is refused by name, not truncated. The
     * sibling rule for T[N] refuses an over-long array; silently dropping the
     * tail of a device name or an extension name would be the same silent
     * omission in string clothing.
     */
    if (len > n - 1) {
        php_error_docref(NULL, E_WARNING,
            "%s.%s: string is %zu byte(s), the member holds %zu plus a NUL",
            ctx, key, len, n - 1);

        return -1;
    }
    memcpy(dst, Z_STRVAL_P(v), len);

    return 1;
}

int phpvk_member_array_len(HashTable *ht, const char *key, size_t max, const char *ctx)
{
    zval *v = phpvk_member_sub(ht, key);
    uint32_t n;

    if (!v || Z_TYPE_P(v) == IS_NULL) {
        return 0;
    }
    if (Z_TYPE_P(v) != IS_ARRAY) {
        php_error_docref(NULL, E_WARNING, "%s.%s: member must be an array", ctx, key);

        return -1;
    }
    n = zend_hash_num_elements(Z_ARRVAL_P(v));
    if ((size_t) n > max) {
        php_error_docref(NULL, E_WARNING,
            "%s.%s: array has %u elements, the member holds " ZEND_LONG_FMT,
            ctx, key, (unsigned int) n, (zend_long) max);

        return -1;
    }

    return (int) n;
}

zval *phpvk_member_array_at(HashTable *ht, const char *key, uint32_t index)
{
    zval *v = phpvk_member_sub(ht, key);
    HashTable *inner;
    zval *entry;
    uint32_t i = 0;

    if (!v || Z_TYPE_P(v) != IS_ARRAY) {
        return NULL;
    }
    inner = Z_ARRVAL_P(v);

    /*
     * Positional, not keyed: the member table says "array of N", and the
     * caller's array is read in its own order. A list and a map with the
     * same order pack identically, which is the least surprising rule that
     * needs no opinion about keys.
     */
    ZEND_HASH_FOREACH_VAL(inner, entry)
    {
        if (i == index) {
            return entry;
        }
        i++;
    }
    ZEND_HASH_FOREACH_END();

    return NULL;
}
