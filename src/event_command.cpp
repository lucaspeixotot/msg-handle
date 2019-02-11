#include "event_command.h"


LOG_MODULE_REGISTER(event_command, 3);

EventCommand::EventCommand(const char *prefix, const char *sufix, const char *initBody,
                           const char *delimiter, u8_t argc, struct k_mem_pool *memoryPool,
                           u8_t bodyLength)
    : MsgHandler(prefix, sufix, memoryPool, bodyLength),
      m_delimiter(delimiter),
      m_initBody(initBody),
      m_argc(argc)
{
    resetRead();
}


int EventCommand::mountBody(char byte)
{
    LOG_DBG("Mounting the body");
    LOG_DBG("%d", m_currentChar);
    if (m_currentChar == 255) {
        if (byte == m_initBody[0]) {
            m_currentArg++;
            m_currentChar++;
            LOG_DBG("Receiving the first byte");
            return 0;
        }
        LOG_INF("The message is broken, discarding it");
        return -EINVAL;
    }

    if (byte == m_sufix[0]) {
        if (m_currentArg != m_argc) {
            LOG_INF("The message is broken, discarding it");
            resetRead();
            return -EINVAL;
        }
        m_body[m_currentChar] = '\0';
        LOG_INF("The message was readed successfuly");
        m_argv[0] = (m_body + 0);
        resolve();
        resetRead();
        return END_MSG;
    }

    if (byte == m_delimiter[0]) {
        m_argv[m_currentArg++]  = (m_body + m_currentChar + 1);
        m_body[m_currentChar++] = '\0';
        LOG_DBG("Reading a new delimiter, moving to %d° argument", m_currentArg);
    } else {
        LOG_DBG("Adding a new byte to %d° argument", m_currentArg);
        m_body[m_currentChar++] = byte;
    }

    return 0;
}
