#include "msg_manager.h"

LOG_MODULE_REGISTER(msg_manager, 3);

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
        LOG_INF("A new handler with prefix \"%s\" was added.", msgHandler->prefix());
        m_handles[nextIndexAvailable] = msgHandler;
        return 0;
    }
    LOG_INF("Already exists a handler with this prefix");


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
                LOG_INF("State: READING_PREFIX");
                m_candidates[i] = 1;
                m_state         = READING_PREFIX;
                m_i             = 1;
            }
        }
    } else if (m_state == READING_PREFIX) {
        u8_t msgBroken = 255;
        for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
            if (m_handles[i] == nullptr) {
                break;
            }
            if (m_candidates[i]) {
                if (m_handles[i]->prefix()[m_i] == byte) {
                    LOG_DBG("%s continues", m_handles[i]->prefix());
                    msgBroken = 0;
                    if (m_i == strlen(m_handles[i]->prefix()) - 1) {
                        LOG_INF("State: READING_BODY");
                        m_handleIndex = i;
                        m_i           = 0;
                        m_state       = READING_BODY;
                        return;
                    }
                } else {
                    m_candidates[i] = 0;
                    LOG_DBG("%s is out", m_handles[i]->prefix());
                    LOG_DBG("%c != %c", byte, m_handles[i]->prefix()[m_i]);
                }
            }
        }
        if (msgBroken) {
            LOG_INF("State: NO_MESSAGE");
            m_state = NO_MESSAGE;
        } else {
            m_i++;
        }
    } else if (m_state == READING_BODY) {
        if (m_handles[m_handleIndex]->mountBody(byte)) {
            LOG_INF("State: NO_MESSAGE");
            resetCandidates();
            m_state = NO_MESSAGE;
        }
    }
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
