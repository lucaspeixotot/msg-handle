#include "tc_msg_manager.hpp"

MsgManager MsgManager::m_instance = MsgManager();

int MsgManager::handlePrefix(const u8_t *msg, const u8_t *pattern)
{
    int err             = 0;
    const char *m       = (const char *) msg;
    const char *p       = (const char *) pattern;
    const char *content = strstr(m, p);

    if (content == nullptr) {
        return 0;
    } else {
        content = content + strlen(p);
    }

    for (u8_t i = 0; i < MAX_MSG_HANDLES; i++) {
        if (!strcmp(p, m_handles[i]->key())) {
            err = m_handles[i]->resolve(content);
            break;
        }
    }
    return err;
}

