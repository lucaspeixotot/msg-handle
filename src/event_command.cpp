#include "event_command.h"


LOG_MODULE_REGISTER(event_command, 4);

EventCommand::EventCommand(const char *prefix, const char *suffix, const char *initBody,
                           const char *delimiter, u8_t argc, struct k_mem_pool *memoryPool,
                           u8_t bodyLength)
    : MsgHandler(prefix, suffix, memoryPool, bodyLength),
      m_delimiter(delimiter),
      m_initBody(initBody),
      m_argc(argc)
{
    resetRead();
}

int EventCommand::mountBody(char byte)
{
    LOG_DBG("Mounting the body");
    LOG_DBG("%d", strlen(m_suffix));
    switch (m_state) {
    case READING_INIT_BODY:
        if (m_currentChar == 255) {
            if (byte == m_initBody[0]) {
                m_currentArg++;
                m_currentChar++;
                m_state = READING_PAYLOAD;
                LOG_DBG("Receiving the first byte");
                return 0;
            }
            LOG_INF("The message is broken, discarding it");
            return -EINVAL;
        }
        break;
    case READING_PAYLOAD:
        if (byte == m_suffix[0]) {
            if (m_currentArg != m_argc) {
                LOG_INF("The message is broken, discarding it");
                resetRead();
                return -EINVAL;
            }
            m_body[m_currentChar] = '\0';
            m_argv[0]             = (m_body + 0);
            if (strlen(m_suffix) == 1) {
                LOG_INF("The message was readed successfuly");
                resolve();
                resetRead();
                return END_MSG;
            } else {
                m_state = READING_SUFFIX;
            }
            break;
        }
        if (byte == m_delimiter[0]) {
            m_argv[m_currentArg++]  = (m_body + m_currentChar + 1);
            m_body[m_currentChar++] = '\0';
            LOG_DBG("Reading a new delimiter, moving to %d° argument", m_currentArg);
        } else {
            LOG_DBG("Adding a new byte to %d° argument", m_currentArg);
            m_body[m_currentChar++] = byte;
        }
        break;
    case READING_SUFFIX:
        if (byte != m_suffix[m_suffix_i++]) {
            return -EINVAL;
        }
        if (m_suffix_i == strlen(m_suffix)) {
            LOG_INF("The message was readed successfuly");
            resolve();
            resetRead();
            return END_MSG;
        }
        break;
    default:
        break;
    };


    return 0;
}

void EventCommand::resetRead()
{
    m_currentChar = 255;
    m_state       = READING_INIT_BODY;
    m_suffix_i    = 1;
    m_currentArg  = 0;
}
