#ifndef _TC_MSG_HANDLE_HPP_
#define _TC_MSG_HANDLE_HPP_

#include <errno.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "string.h"

class MsgHandle
{
   public:
    MsgHandle(const char *prefix, const char *sufix);
    virtual int resolve(const char *content)
    {
        return -EINVAL;
    };
    const char *prefix();
    const char *findPattern(const char *msg, const char *pattern);
    char *splitPick(const char *msg, const char *delimiter, u8_t n);
    char *strtok(char *str, const char *delimiter);

   private:
    const char *m_prefix;
    const char *m_sufix;
};

#endif
