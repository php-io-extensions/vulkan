/*
 * NEGATIVE CONTROL for gen-zep.php: the annotation promises two parameters
 * and the C prototype has one. The generator must refuse and write nothing.
 */

#ifndef FIXTURE_DRIFT_H
#define FIXTURE_DRIFT_H

#include <php.h>

/*@zep VK\VK10 vkFakeOne(int instance, int extra) -> int */
zend_long phpvk_vk10_vkfakeone(zval *instance);

#endif
