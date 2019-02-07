#ifndef _MSG_HANDLE_H_
#define _MSG_HANDLE_H_

#include <errno.h>
#include <logging/log.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "stdlib.h"
#include "string.h"

class MsgHandle
{
   public:
    MsgHandle(const char *prefix, const char *sufix);
    virtual int resolve(char *content)
    {
        return -EINVAL;
    };
    const char *prefix();
    const char *sufix();
    char *splitPick(char *msg, const char *delimiter, u8_t n);
    char *strtok(char *str, const char *delimiter);
    virtual int mountBody(char byte) = 0;

   protected:
    const char *m_prefix;
    const char *m_sufix;
    char m_body[100];
    char *m_temp;
};

#endif
