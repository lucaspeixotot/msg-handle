#include "tc_msg_handle.hpp"

MsgHandle::MsgHandle(const char *key) : m_key(key)
{
}

int MsgHandle::resolve(const char *content)
{
    int err = 0;
    return err;
}

const char *MsgHandle::key()
{
    return m_key;
}
