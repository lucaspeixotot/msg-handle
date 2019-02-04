/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2018-12-25
 *
 * @copyright Copyright (c) 2018
 *
 */

#include <logging/log.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "ic_version.h"
#include "tc_msg_manager.hpp"


void main(void)
{
    printk("Firmware version: %d.%d.%d\n", version_get_major(), version_get_minor(),
           version_get_build());
    const u8_t msg[]  = "CONNECT 0x10 0x1234";
    const u8_t func[] = "CONNECT";

    MsgManager::instance()->handlePrefix(msg, func);

    while (1) {
    }
}

