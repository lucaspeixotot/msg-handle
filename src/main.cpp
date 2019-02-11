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

#include "firmware_version.h"
#include "msg_manager.h"
#include "sspconf_handler.h"

// uart
#include <misc/byteorder.h>
#include <stdio.h>
#include <uart.h>
#include <zephyr.h>

#define K_MEM_POOL_DEFINE_CPP(name, minsz, maxsz, nmax, align)                           \
    char __aligned(align)                                                                \
        _mpool_buf_##name[_ALIGN4(maxsz * nmax) + _MPOOL_BITS_SIZE(maxsz, minsz, nmax)]; \
    struct sys_mem_pool_lvl _mpool_lvls_##name[_MPOOL_LVLS(maxsz, minsz)];               \
    struct k_mem_pool name __in_section(_k_mem_pool, static, name) = {                   \
        base : {                                                                         \
            buf : _mpool_buf_##name,                                                     \
            max_sz : maxsz,                                                              \
            n_max : nmax,                                                                \
            n_levels : _MPOOL_LVLS(maxsz, minsz),                                        \
            max_inline_level : 0,                                                        \
            levels : _mpool_lvls_##name,                                                 \
            flags : SYS_MEM_POOL_KERNEL,                                                 \
        },                                                                               \
    }

K_MEM_POOL_DEFINE_CPP(memoryPool, 32, 256, 1, 4);

LOG_MODULE_REGISTER(main, 4);

void uart_callback(struct device *uart_dev)
{
    u8_t recvData;

    if (!uart_irq_update(uart_dev)) {
        LOG_ERR("UART is not workin properly");
        return;
    }

    if (uart_irq_rx_ready(uart_dev)) {
        uart_fifo_read(uart_dev, &recvData, 1);
    }

    MsgManager::instance()->receiveByte((char) recvData);
}


void initUart(struct device *uart_dev)
{
    uart_dev = device_get_binding("UART_0");

    if (uart_dev == nullptr) {
        LOG_ERR("The UART device was not finded.");
        return;
    }

    uart_irq_callback_set(uart_dev, uart_callback);
    uart_irq_rx_enable(uart_dev);
}

class SsppinHandler : public EventCommand
{
   public:
    SsppinHandler(const char *prefix, const char *sufix, const char *init_body,
                  const char *delimiter, u8_t argc, struct k_mem_pool *memoryPool, u8_t bodyLength)
        : EventCommand(prefix, sufix, init_body, delimiter, argc, memoryPool, bodyLength)
    {
    }
    int resolve()
    {
        LOG_DBG("The 1 argument from ssppin handler is: %s", m_argv[0]);
        LOG_DBG("The 2 argument from ssppin handler is: %s", m_argv[1]);
        return 0;
    }

   protected:
};

class LeattmtuHandler : public EventCommand
{
   public:
    LeattmtuHandler(const char *prefix, const char *sufix, const char *init_body,
                    const char *delimiter, u8_t argc, struct k_mem_pool *memoryPool,
                    u8_t bodyLength)
        : EventCommand(prefix, sufix, init_body, delimiter, argc, memoryPool, bodyLength)
    {
    }
    int resolve()
    {
        LOG_DBG("The 1 argument from leattmtu handler is: %s", m_argv[0]);
        LOG_DBG("The 2 argument from leattmtu handler is: %s", m_argv[1]);
        return 0;
    }

   protected:
};

void main(void)
{
    LOG_WRN("Firmware version: %d.%d.%d\n", version_get_major(), version_get_minor(),
            version_get_build());
    SSPCONFHandler sspconf(SSPCONF_PREFIX, SSPCONF_SUFIX, " ", " ", 3, &memoryPool, 32);
    LeattmtuHandler leattmtu("LEATTMTU", "\r", ":", ",", 2, &memoryPool, 32);
    SsppinHandler ssppin("SSPPIN", "\r", " ", " ", 2, &memoryPool, 32);

    MsgManager::instance()->subscribe(&sspconf);
    MsgManager::instance()->subscribe(&leattmtu);
    MsgManager::instance()->subscribe(&ssppin);
    struct device uart_dev;
    initUart(&uart_dev);

    while (1) {
        k_sleep(1);
    }
}

