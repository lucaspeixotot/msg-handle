#include "msg_handler.h"

LOG_MODULE_REGISTER(msg_handler, 4);

MsgHandler::MsgHandler(const char *prefix, const char *suffix, struct k_mem_pool *memoryPool,
                       u8_t bodyLength)
    : m_prefix(prefix), m_suffix(suffix)
{
    m_body = (char *) k_mem_pool_malloc(memoryPool, bodyLength);
    if (!m_body) {
        LOG_ERR(
            "Error allocating memory to the msg handler named %s, there is no %d bytes available",
            prefix, bodyLength);
    }
}


const char *MsgHandler::prefix()
{
    return m_prefix;
}

const char *MsgHandler::suffix()
{
    return m_suffix;
}
