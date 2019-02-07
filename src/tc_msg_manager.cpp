#include "tc_msg_manager.hpp"

MsgManager MsgManager::m_instance = MsgManager();

int MsgManager::subscribe(MsgHandle *msgHandle)
{
    if (msgHandle == nullptr) {
        return -EINVAL;
    }
    u8_t available          = 1;
    u8_t nextIndexAvailable = 0;

    for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
        if (m_handles[i] != nullptr) {
            if (!strcmp(m_handles[i]->prefix(), msgHandle->prefix())) {
                available = 0;
            }
        }
        if (m_handles[i] == nullptr) {
            nextIndexAvailable = i;
            break;
        }
    }

    if (available) {
        m_handles[nextIndexAvailable] = msgHandle;
    }

    return 0;
}

int MsgManager::handlePrefix(const u8_t *msg, const u8_t *pattern)
{
    int err = 0;
    // const char *m       = (const char *) msg;
    // const char *p       = (const char *) pattern;
    // const char *content = strstr(m, p);

    // if (content == nullptr) {
    // return 0;
    //}

    // content = content + strlen(p);

    // for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
    // if (m_handles[i] != nullptr && !strcmp(p, m_handles[i]->prefix())) {
    // err = m_handles[i]->resolve(content);
    // break;
    //}
    //}
    return err;
}

void MsgManager::receiveByte(char byte)
{
    printk("%c\n", byte);
    if (m_state == NO_MESSAGE) {
        printk("-NO_MESSAGE\n");
        for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
            if (m_handles[i] == nullptr) {
                break;
            }
            if (m_handles[i]->prefix()[0] == byte) {
                printk("POSSIBLE PREFIX\n");
                m_state = READING_PREFIX;
                m_i     = 1;
            }
        }
    } else if (m_state == READING_PREFIX) {
        printk("-READING_PREFIX\n");
        u8_t msgBroken = -1;
        for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
            if (m_handles[i] == nullptr) {
                break;
            }
            if (m_handles[i]->prefix()[m_i] == byte) {
                msgBroken = 0;
                m_i++;
                if (m_i == strlen(m_handles[i]->prefix())) {
                    m_handleIndex = i;
                    m_i           = 0;
                    m_state       = READING_BODY;
                }
                break;
            }
        }
        if (msgBroken) {
            printk("PREFIX BROKEN\n");
            m_state = NO_MESSAGE;
        }
    } else if (m_state == READING_BODY) {
        printk("-READING_BODY\n");
        if (m_handles[m_handleIndex]->sufix()[0] == byte) {
            m_i     = 1;
            m_state = READING_SUFIX;
            return;
        }
        msg[m_i++] = byte;
    } else if (m_state == READING_SUFIX) {
        printk("-READING_PREFIX\n");
        if (m_handles[m_handleIndex]->sufix()[m_i++] != byte) {
            m_state = NO_MESSAGE;
        }
        if (m_i == strlen(m_handles[m_handleIndex]->sufix())) {
            m_handles[m_handleIndex]->resolve(msg);
            m_state = NO_MESSAGE;
        }
    }
}
