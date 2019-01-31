#ifndef _TC_MSG_HANDLE_HPP_
#define _TC_MSG_HANDLE_HPP_

#include <errno.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "string.h"

class MsgHandle
{
   public:
    MsgHandle(const char *key);
    virtual int resolve(const char *content)
    {
        return -EINVAL;
    };
    const char *key();

   private:
    const char *m_key;
};

#endif
