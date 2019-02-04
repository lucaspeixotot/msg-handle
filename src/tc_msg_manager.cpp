#include "tc_msg_manager.hpp"

MsgManager MsgManager::m_instance = MsgManager();

int MsgManager::subscribe(MsgHandle *msgHandle)
{
    if (msgHandle == nullptr) {
        return -EINVAL;
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
        return err;
    }

    content = content + strlen(p);

    for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
        if (!strcmp(p, m_handles[i]->prefix())) {
            err = m_handles[i]->resolve(content);
            break;
        }
    }
    return err;
}

