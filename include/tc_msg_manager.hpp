#ifndef _TC_MSG_MANAGER_HPP_
#define _TC_MSG_MANAGER_HPP_

// Includes
#include <misc/printk.h>
#include <zephyr/types.h>

#include "string.h"
#include "tc_msg_handle.hpp"

// Defines
#define MAX_MSG_HANDLES 10

class MsgManager
{
   public:
    int handlePrefix(const u8_t *msg, const u8_t *pattern);
    int subscribe(MsgHandle msgHandle);
    static MsgManager *instance()
    {
        return &m_instance;
    }

   private:
    MsgManager()
    {
        for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
            m_handles[i] = nullptr;
        }
    };
    static MsgManager m_instance;
    MsgHandle *m_handles[MAX_MSG_HANDLES];
};

#endif
