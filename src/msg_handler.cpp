#include "msg_handler.h"

MsgHandler::MsgHandler(const char *prefix, const char *sufix) : m_prefix(prefix), m_sufix(sufix)
{
    m_temp = nullptr;
    resetRead();
}


void MsgHandler::resetRead()
{
    m_currentChar = 255;
    m_currentArg  = 0;
}

const char *MsgHandler::prefix()
{
    return m_prefix;
}

const char *MsgHandler::sufix()
{
    return m_sufix;
}

char *MsgHandler::strtok(char *str, const char *tokens)
{
    int i   = 0;
    int len = strlen(tokens);

    /* check in the tokens */
    if (len == 0)
        printk("tokens are empty\n");

    /* if the original string has nothing left */
    if (!str && !m_temp)
        return NULL;

    /* initialize the m_temp during the first call */
    if (str && !m_temp)
        m_temp = str;

    /* find the start of the substring, skip tokens */
    char *p_start = m_temp;
    while (true) {
        for (i = 0; i < len; i++) {
            if (*p_start == tokens[i]) {
                p_start++;
                break;
            }
        }

        if (i == len) {
            m_temp = p_start;
            break;
        }
    }

    /* return NULL if nothing left */
    if (*m_temp == '\0') {
        m_temp = NULL;
        return m_temp;
    }

    /* find the end of the substring, and
        replace the delimiter with null */
    while (*m_temp != '\0') {
        for (i = 0; i < len; i++) {
            if (*m_temp == tokens[i]) {
                *m_temp = '\0';
                break;
            }
        }

        m_temp++;
        if (i < len)
            break;
    }

    return p_start;
}

char *MsgHandler::splitPick(char *msg, const char *delimiter, u8_t n)
{
    char *choice = strtok(msg, delimiter);

    while (choice != nullptr) {
        n--;
        if (n == 0) {
            break;
        }
        choice = strtok(nullptr, delimiter);
    }

    return choice;
}
