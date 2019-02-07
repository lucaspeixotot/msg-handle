#ifndef _TC_MSG_MANAGER_HPP_
#define _TC_MSG_MANAGER_HPP_

// Includes
#include <misc/printk.h>
#include <zephyr/types.h>

#include "string.h"
#include "tc_msg_handle.hpp"

// uart
#include <misc/byteorder.h>
#include <stdio.h>
#include <uart.h>
#include <zephyr.h>

// Defines
#define MAX_MSG_HANDLES 10

enum state { NO_MESSAGE, READING_PREFIX, READING_BODY, READING_SUFIX };

class MsgManager
{
   public:
    int handlePrefix(const u8_t *msg, const u8_t *pattern);
    int subscribe(MsgHandle *msgHandle);
    void receiveByte(char byte);
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
        m_state = NO_MESSAGE;
    };

    static MsgManager m_instance;
    state m_state;
    u8_t m_i;
    u8_t m_handleIndex;
    MsgHandle *m_handles[MAX_MSG_HANDLES];
    char msg[50];
};

#endif
