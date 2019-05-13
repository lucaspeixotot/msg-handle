#ifndef _MSG_HANDLE_H_
#define _MSG_HANDLE_H_

#include <errno.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "stdlib.h"
#include "string.h"
#include "globals.h"


class MsgHandler
{
   public:
    MsgHandler(char *prefix, char *suffix);
    virtual int resolve()
    {
        return -EINVAL;
    };
    virtual int mountBody(char byte) = 0;
    char *prefix();
    char *suffix();

   protected:
    char m_prefix[PREFIX_LENGTH];
    char m_suffix[SUFFIX_LENGTH];
    char m_body[BODY_LENGTH];
};

#endif
