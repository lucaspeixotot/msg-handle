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
#include <zephyr/types.h>

#include "ic_version.h"
#include "sspconf_handler.hpp"
#include "tc_msg_manager.hpp"

LOG_MODULE_REGISTER(main);

void uart_callback(struct device *uart_dev)
{
    u8_t recvData;
    /* Verify uart_irq_update() */
    if (!uart_irq_update(uart_dev)) {
        printk("retval should always be 1\n");
        return;
    }
    /* Verify uart_irq_rx_ready() */
    if (uart_irq_rx_ready(uart_dev)) {
        /* Verify uart_fifo_read() */
        uart_fifo_read(uart_dev, &recvData, 1);
    }
    MsgManager::instance()->receiveByte((char) recvData);
}


void initUart(struct device *uart_dev)
{
    uart_dev = device_get_binding("UART_0");

    uart_irq_callback_set(uart_dev, uart_callback);
    uart_irq_rx_enable(uart_dev);
}

void main(void)
{
    printk("Firmware version: %d.%d.%d\n", version_get_major(), version_get_minor(),
           version_get_build());
    const u8_t msg[]  = "SSPCONF 00802507C08D,t2 794851 ?OK";
    const u8_t func[] = "SSPCONF";
    SSPCONFHandler sspconf(SSPCONF_PREFIX, SSPCONF_SUFIX);

    // printk("%s\n", sspconf.prefix());
    MsgManager::instance()->subscribe(&sspconf);
    // MsgManager::instance()->handlePrefix(msg, func);
    struct device uart_dev;
    initUart(&uart_dev);

    while (1) {
    }
}

