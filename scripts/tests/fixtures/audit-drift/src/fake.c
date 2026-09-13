/*
 * The struct tier's emitted shape, in miniature. The member-level half of
 * audit-registry.php reads these bodies back, so a fixture that only carried
 * annotations would be auditing half the law.
 */

static const char *const phpvk_names_VkFakeInfo[] = {"value"};

int phpvk_fill_VkFakeInfo(VkFakeInfo *s, zval *members, const char *ctx)
{
    HashTable *ht;

    memset(s, 0, sizeof(*s));
    if (!members || Z_TYPE_P(members) == IS_NULL) {
        return 1;
    }
    ht = phpvk_members(members, ctx);
    if (!ht || !phpvk_check_keys(ht, phpvk_names_VkFakeInfo, 1, ctx)) {
        return 0;
    }
    s->value = (uint32_t) phpvk_member_long(ht, "value");

    return 1;
}

void phpvk_read_VkFakeInfo(zval *out, const VkFakeInfo *s)
{
    array_init(out);
    add_assoc_long(out, "value", (zend_long) s->value);
}
