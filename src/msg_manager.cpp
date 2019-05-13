#include "msg_manager.h"

MsgManager MsgManager::m_instance = MsgManager();

int MsgManager::subscribe(MsgHandler *msgHandler)
{
    if (msgHandler == nullptr) {
        return -EINVAL;
    }
    u8_t available          = 1;
    u8_t nextIndexAvailable = 0;

    for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
        if (m_handles[i] == nullptr) {
            nextIndexAvailable = i;
            break;
        }
        if (!strcmp(m_handles[i]->prefix(), msgHandler->prefix())) {
            available = 0;
        }
    }

    if (available) {
        printk("A new handler with prefix \"%s\" was added.\n", msgHandler->prefix());
        m_handles[nextIndexAvailable] = msgHandler;
        return 0;
    }
    printk("Already exists a handler with this prefix\n");


    return 0;
}

void MsgManager::nextState(event e)
{
    switch (m_state) {
    case NO_MESSAGE:
        if (e == MATCH) {
            printk("State: READING_PREFIX\n");
            m_state = READING_PREFIX;
            m_i     = 1;
        }
        break;
    case READING_PREFIX:
        if (e == NOT_MATCH) {
            printk("State: NO_MESSAGE\n");
            m_state = NO_MESSAGE;
        } else if (e == PREFIX_COMPLETE) {
            printk("State: READING_BODY\n");
            m_i     = 0;
            m_state = READING_BODY;
        }
        break;
    case READING_BODY:
        if (e == BODY_BROKEN) {
            printk("State: NO_MESSAGE\n");
            resetCandidates();
            m_state = NO_MESSAGE;
        }
        break;
    default:
        break;
    };
}

void MsgManager::receiveByte(char byte)
{
    printk("Byte received: %c\n", byte);
    event e = NULL_EVENT;
    if (m_state == NO_MESSAGE) {
        e    = NOT_MATCH;
        byte = upperCase(byte);
        for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
            if (m_handles[i] == nullptr) {
                break;
            }
            if (m_handles[i]->prefix()[0] == byte) {
                m_candidates[i] = 1;
                e               = MATCH;
            }
        }
    } else if (m_state == READING_PREFIX) {
        e    = NOT_MATCH;
        byte = upperCase(byte);
        for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
            if (m_handles[i] == nullptr) {
                break;
            }
            if (m_candidates[i]) {
                if (m_handles[i]->prefix()[m_i] == byte) {
                    printk("%s continues\n", m_handles[i]->prefix());
                    e = MATCH;
                    if (m_i == strlen(m_handles[i]->prefix()) - 1) {
                        e             = PREFIX_COMPLETE;
                        m_handleIndex = i;
                        break;
                    }
                } else {
                    m_candidates[i] = 0;
                    printk("%s is out\n", m_handles[i]->prefix());
                    printk("%c != %c\n", byte, m_handles[i]->prefix()[m_i]);
                }
            }
        }
        m_i++;
    } else if (m_state == READING_BODY) {
        e = BODY_OK;
        if (m_handles[m_handleIndex]->mountBody(byte)) {
            e = BODY_BROKEN;
        }
    }
    nextState(e);
}

void MsgManager::resetCandidates()
{
    for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
        if (m_handles[i] == nullptr) {
            break;
        }
        m_candidates[i] = 0;
    }
}

char MsgManager::upperCase(char byte)
{
    if (byte >= 97 && byte <= 122) {
        byte = byte - 32;
    }
    return byte;
}
