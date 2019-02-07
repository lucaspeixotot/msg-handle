#ifndef _MSG_MANAGER_H_
#define _MSG_MANAGER_H_

// Includes
#include <misc/printk.h>
#include <zephyr/types.h>

#include "msg_handler.h"
#include "string.h"


// Defines
#define MAX_MSG_HANDLES 10

enum state { NO_MESSAGE, READING_PREFIX, READING_BODY, READING_SUFIX };

class MsgManager
{
   public:
    int subscribe(MsgHandler *msgHandler);
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
    MsgHandler *m_handles[MAX_MSG_HANDLES];
};

#endif
