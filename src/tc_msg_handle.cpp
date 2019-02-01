#include "tc_msg_handle.hpp"

MsgHandle::MsgHandle(const char *key) : m_key(key)
{
}

const char *MsgHandle::key()
{
    return m_key;
}
