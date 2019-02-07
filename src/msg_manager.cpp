#include "msg_manager.h"

LOG_MODULE_REGISTER(msg_manager, 4);

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
        LOG_INF("A new handler with prefix \"%s\" was added.", msgHandle->prefix());
        m_handles[nextIndexAvailable] = msgHandle;
    }

    return 0;
}

void MsgManager::receiveByte(char byte)
{
    LOG_DBG("Byte received: %c", byte);
    if (m_state == NO_MESSAGE) {
        for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
            if (m_handles[i] == nullptr) {
                break;
            }
            if (m_handles[i]->prefix()[0] == byte) {
                LOG_DBG("State: READING_PREFIX");
                m_state = READING_PREFIX;
                m_i     = 1;
            }
        }
    } else if (m_state == READING_PREFIX) {
        u8_t msgBroken = -1;
        for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
            if (m_handles[i] == nullptr) {
                break;
            }
            if (m_handles[i]->prefix()[m_i] == byte) {
                msgBroken = 0;
                m_i++;
                if (m_i == strlen(m_handles[i]->prefix())) {
                    LOG_DBG("State: READING_BODY");
                    m_handleIndex = i;
                    m_i           = 0;
                    m_state       = READING_BODY;
                }
                break;
            }
        }
        if (msgBroken) {
            LOG_DBG("State: NO_MESSAGE");
            m_state = NO_MESSAGE;
        }
    } else if (m_state == READING_BODY) {
        if (m_handles[m_handleIndex]->mountBody(byte)) {
            m_state = NO_MESSAGE;
        }
    }
}
