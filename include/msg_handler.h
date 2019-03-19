#ifndef _MSG_HANDLE_H_
#define _MSG_HANDLE_H_

#include <errno.h>
#include <logging/log.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "stdlib.h"
#include "string.h"


class MsgHandler
{
   public:
    MsgHandler(const char *prefix, const char *suffix, struct k_mem_pool *memoryPool,
               u8_t bodyLength);
    virtual int resolve()
    {
        return -EINVAL;
    };
    const char *prefix();
    const char *suffix();
    char *splitPick(char *msg, const char *delimiter, u8_t n);
    char *strtok(char *str, const char *delimiter);
    virtual int mountBody(char byte) = 0;

   protected:
    const char *m_prefix;
    const char *m_suffix;
    char *m_body;
};

#endif
