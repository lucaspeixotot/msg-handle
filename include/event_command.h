#ifndef _GENERAL_COMMAND_H_
#define _GENERAL_COMMAND_H_


#include <string.h>

#include "msg_handler.h"


enum mount_state { READING_INIT_BODY, READING_PAYLOAD, READING_SUFFIX, END_MSG };

class EventCommand : public MsgHandler
{
   public:
    EventCommand(const char *prefix, const char *suffix, const char *initBody,
                 const char *delimiter, u8_t argc, struct k_mem_pool *memoryPool, u8_t bodyLength);
    int mountBody(char byte);
    virtual int resolve()
    {
        return -EINVAL;
    }

   protected:
    const char *m_delimiter;
    const char *m_initBody;
    mount_state m_state;
    u8_t m_currentChar;
    u8_t m_currentArg;
    u8_t m_suffix_i;
    char *m_argv[10];
    u8_t m_argc;
    void resetRead();
};

#endif
