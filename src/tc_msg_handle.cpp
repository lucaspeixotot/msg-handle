#include "tc_msg_handle.hpp"

MsgHandle::MsgHandle(const char *prefix, const char *sufix) : m_prefix(prefix), m_sufix(sufix)
{
}

const char *MsgHandle::prefix()
{
    return m_prefix;
}

const char *MsgHandle::findPattern(const char *msg, const char *pattern)
{
    return strstr(msg, pattern);
}

char *strtok(char *str, const char *delimiter)
{
    static char *temp;

    char *nextDelimiter = strstr(str, delimiter);
    *nextDelimiter      = "\0";
}


char *MsgHandle::splitPick(const char *msg, const char *delimiter, u8_t n)
{
    char *msgCopy;
    strcpy(msgCopy, msg);

    char *choice = strtok(msgCopy, delimiter);

    while (choice != nullptr) {
        n--;
        if (n == 0) {
            break;
        }
        choice = strtok(nullptr, delimiter);
    }

    return choice;
}

