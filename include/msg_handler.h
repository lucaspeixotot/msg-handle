#ifndef _MSG_HANDLE_H_
#define _MSG_HANDLE_H_

#include <errno.h>
#include <logging/log.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "stdlib.h"
#include "string.h"

#define MAX_BODY_LENGTH 80

class MsgHandler
{
   public:
    MsgHandler(const char *prefix, const char *sufix);
    virtual int resolve()
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
    u8_t m_currentChar;
    u8_t m_currentArg;
    char m_body[MAX_BODY_LENGTH];
    char *m_temp;

    void resetRead();
};

#endif
