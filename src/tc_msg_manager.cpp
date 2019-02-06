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
    int err             = 0;
    const char *m       = (const char *) msg;
    const char *p       = (const char *) pattern;
    const char *content = strstr(m, p);

    if (content == nullptr) {
        return 0;
    }

    content = content + strlen(p);

    for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
        if (m_handles[i] != nullptr && !strcmp(p, m_handles[i]->prefix())) {
            err = m_handles[i]->resolve(content);
            break;
        }
    }
    return err;
}
