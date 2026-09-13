/*
 * NEGATIVE CONTROL for check-parity.php's whole-file scan.
 *
 * This file carries no binding annotation at all, so the composite guard —
 * which only inspects annotated bodies — never looks at it. It still must not
 * be allowed to call a Vulkan command by name.
 */

#include "phpvk-support.h"

void phpvk_helper_that_should_not_exist(void)
{
    vkDeviceWaitIdle(NULL);
}
