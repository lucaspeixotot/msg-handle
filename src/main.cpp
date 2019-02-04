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
#include "sspconf_handler.hpp"
#include "tc_msg_manager.hpp"


void main(void)
{
    printk("Firmware version: %d.%d.%d\n", version_get_major(), version_get_minor(),
           version_get_build());
    const u8_t msg[]  = "SSPCONF 00802507C08D,t2 794851 ?";
    const u8_t func[] = "SSPCONF";
    SSPCONFHandler sspconf(PREFIX, SUFIX);

    // printk("%s\n", sspconf.prefix());
    MsgManager::instance()->handlePrefix(msg, func);

    while (1) {
    }
}

