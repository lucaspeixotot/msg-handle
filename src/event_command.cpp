#include "event_command.h"


LOG_MODULE_REGISTER(event_command, 4);

EventCommand::EventCommand(const char *prefix, const char *sufix, const char *initBody,
                           const char *delimiter, u8_t argc)
    : MsgHandler(prefix, sufix), m_delimiter(delimiter), m_initBody(initBody), m_argc(argc)
{
    // m_argv = (char **) malloc(argc);
    resetRead();
}


int EventCommand::mountBody(char byte)
{
    LOG_DBG("Mounting the body");
    if (!m_currentChar) {
        if (byte == m_initBody[0]) {
            m_argv[m_currentArg++] = m_body;
            m_currentChar++;
            LOG_DBG("Receiving the first byte");
            return 0;
        }
        return -EINVAL;
    }

    if (byte == m_sufix[0]) {
        if (m_currentArg != m_argc) {
            LOG_DBG("The message is broken, discarding it");
            resetRead();
            return -EINVAL;
        }
        m_body[m_currentChar] = '\0';
        LOG_DBG("End of message, let's resolve it");
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
