/**!
 * @file version.h
 * @author Rodrigo Peixoto (rodrigopex@ic.ufal.br)
 * @brief
 * @version 0.1
 * @date 2018-11-21
 *
 * @copyright Copyright (c) ic.ufal.br 2018
 *
 */
#ifndef _VERSION_H_
#define _VERSION_H_

#include <zephyr/types.h>

#include "current_version.h"


typedef struct {
    u8_t major;
    u8_t minor;
    u16_t build;
} version_t;

const version_t *version_instance();
u8_t version_get_major();
u8_t version_get_minor();
u16_t version_get_build();

#endif  // _IC_VERSION_H_
