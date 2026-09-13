/*
 * phpvk-support.h — the only marshalling layer.
 *
 * Every generated binding body — command bodies and struct fill/read bodies
 * alike — reaches PHP values through these helpers and through nothing else.
 * They are pure translation: no Vulkan call is ever made here, and none of
 * them decides anything about how the API is used.
 *
 * The pointer rule (binding-rules.md): every pointer, in or out, that is not
 * a `const char *` command parameter crosses the boundary as raw pointer bits
 * in a PHP int, 0 = NULL. PHP builds and reads those bytes with
 * Bridge::alloc/write/read, Bridge::cstring, the struct tier and
 * pack()/unpack().
 *
 * The member helpers are the struct tier's half of the same job. They are
 * deliberately dumb: a missing key is zero, an unknown key is a refusal, and
 * nothing is defaulted — not even sType.
 *
 * This header carries no binding annotations of its own; the parity guard
 * skips it for that reason.
 */

#ifndef PHPVK_SUPPORT_H
#define PHPVK_SUPPORT_H

#include <php.h>
#include <stdint.h>
#include <stddef.h>

/* ---- scalars in ---- */

zend_long phpvk_arg_long(zval *z);
double phpvk_arg_double(zval *z);
int phpvk_arg_bool(zval *z);

/*
 * 64-bit unsigned in. PHP has no unsigned int, so this is the signed value
 * reinterpreted: -1 is UINT64_MAX, which is how a caller writes
 * VK_WHOLE_SIZE. A value above PHP_INT_MAX cannot be written directly and
 * wraps; that is the documented cost of the flat table.
 */
uint64_t phpvk_arg_u64(zval *z);

/* ---- strings in ---- */

/* Borrowed NUL-terminated bytes; NULL when the zval is not a string. */
const char *phpvk_arg_string(zval *z);

/* ---- pointers in ---- */

/* Raw pointer bits -> void *; 0 -> NULL. No validation: see the
 * pointer-bits-only trap. */
void *phpvk_arg_ptr(zval *z);

/* ---- struct members ---- */

/*
 * The member array for one struct.
 *
 * A NULL zval or PHP null means "no members": returns NULL silently and the
 * caller zero-fills. Anything else that is not an array warns
 * "<ctx>: members must be an array" and returns NULL too, so the caller must
 * distinguish the two cases by looking at the zval, not at the result.
 */
HashTable *phpvk_members(zval *members, const char *ctx);

/*
 * Every key present must be one of `names`. Warns
 * "<ctx>: unknown member '<key>'" once per offending key and returns 0 when
 * any key is unknown, 1 otherwise. A typo must not silently vanish.
 */
int phpvk_check_keys(HashTable *ht, const char *const names[], size_t n, const char *ctx);

/* Absent key -> 0 / 0.0 / NULL, in every one of these. */
zend_long phpvk_member_long(HashTable *ht, const char *key);
uint64_t phpvk_member_u64(HashTable *ht, const char *key);
double phpvk_member_double(HashTable *ht, const char *key);
int phpvk_member_bool(HashTable *ht, const char *key);
void *phpvk_member_ptr(HashTable *ht, const char *key);

/* The raw zval for a nested struct/union member, or NULL when absent. */
zval *phpvk_member_sub(HashTable *ht, const char *key);

/*
 * char[n] member: NUL-pads dst and copies the key's string into it. Returns 1
 * on success — including for an absent key, which zero-fills like every other
 * missing member. Returns -1 after warning
 * ("<ctx>.<key>: string is N byte(s), the member holds M plus a NUL") when
 * the string does not fit: an over-long string is refused by name, exactly as
 * an over-long scalar array is, because nothing here is silently truncated
 * (spec §7). dst is left zeroed in that case and the fill stops.
 */
int phpvk_member_chars(HashTable *ht, const char *key, char *dst, size_t n, const char *ctx);

/*
 * Scalar array member: returns the element count, or -1 after warning when
 * the value is not an array or has more than `max` elements
 * ("<ctx>.<key>: array has N elements, the member holds M"). An absent key
 * returns 0, which zero-fills.
 */
int phpvk_member_array_len(HashTable *ht, const char *key, size_t max, const char *ctx);

/* The i-th value of an array member, or NULL. Used by the array loops. */
zval *phpvk_member_array_at(HashTable *ht, const char *key, uint32_t index);

#endif /* PHPVK_SUPPORT_H */
