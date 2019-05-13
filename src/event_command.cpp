#include "event_command.h"

EventCommand::EventCommand(char *prefix, char *suffix, char *initBody,
                           char *delimiter, u8_t argc)
    : MsgHandler(prefix, suffix),
      m_argc(argc)
{
    memset(m_delimiter, 0, DELIMITER_LENGTH);
    strcpy(m_delimiter, delimiter);

    memset(m_initBody, 0, INIT_BODY_LENGTH);
    strcpy(m_initBody, initBody);


    resetRead();
}

int EventCommand::mountBody(char byte)
{
    printk("Mounting the body\n");
    printk("%d", strlen(m_suffix));
    switch (m_state) {
    case READING_INIT_BODY:
        if (m_currentChar == 255) {
            if (byte == m_initBody[0]) {
                m_currentArg++;
                m_currentChar++;
                m_state = READING_PAYLOAD;
                printk("Receiving the first byte\n");
                return 0;
            }
            printk("The message is broken, discarding it\n");
            return -EINVAL;
        }
        break;
    case READING_PAYLOAD:
        if (byte == m_suffix[0]) {
            if (m_currentArg != m_argc) {
                printk("The message is broken, discarding it\n");
                resetRead();
                return -EINVAL;
            }
            m_body[m_currentChar] = '\0';
            m_argv[0]             = (m_body + 0);
            if (strlen(m_suffix) == 1) {
                printk("The message was readed successfuly\n");
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
            printk("Reading a new delimiter, moving to %d° argument\n", m_currentArg);
        } else {
            printk("Adding a new byte to %d° argument\n", m_currentArg);
            m_body[m_currentChar++] = byte;
        }
        break;
    case READING_SUFFIX:
        if (byte != m_suffix[m_suffix_i++]) {
            return -EINVAL;
        }
        if (m_suffix_i == strlen(m_suffix)) {
            printk("The message was readed successfuly\n");
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
