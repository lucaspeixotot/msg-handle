#include "sspconf_handler.h"

LOG_MODULE_REGISTER(sspconf_handler, 4);

SSPCONFHandler::SSPCONFHandler(const char *prefix, const char *sufix, const char *init_body,
                               const char *delimiter, u8_t argc, struct k_mem_pool *memoryPool,
                               u8_t bodyLength)
    : EventCommand(prefix, sufix, init_body, delimiter, argc, memoryPool, bodyLength)
{
}

int SSPCONFHandler::resolve()
{
    LOG_DBG("The 1 argument is: %s", m_argv[0]);
    LOG_DBG("The 2 argument is: %s", m_argv[1]);
    LOG_DBG("The 3 argument is: %s", m_argv[2]);
    return 0;
}
