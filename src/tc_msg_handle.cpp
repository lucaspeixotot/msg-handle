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

char *MsgHandle::strtok(char *str, const char *tokens)
{
    // Making a static string to be used again on next function call.
    static char *temp;

    // If string passed to function is not null, copy it to our static variable
    if (str != NULL) {
        temp = (char *) malloc(strlen(str));
        strcpy(temp, str);
    }

    // If the string passed is NULL and even the copy is NULL, we are done and return NULL.
    else if (temp == NULL)
        return NULL;

    // If only the string passed is NULL and the copy still has data, work with it.
    else {
        str = temp;
    }

    int chars = 0, len = strlen(tokens), flag = 0;

    // Run the loop till we find a token or our copy is fully parsed.
    while (*temp) {
        for (int i = 0; i < len; i++) {
            if (*temp == tokens[i]) {
                if (chars == 0) {
                    flag = 1;
                    str++;
                } else {
                    temp++;
                    str[chars] = '\0';
                    return str;
                }
            }
        }
        if (flag == 0)
            chars++;
        temp++;
        flag = 0;
    }
    temp       = NULL;
    str[chars] = '\0';
    return str;
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

