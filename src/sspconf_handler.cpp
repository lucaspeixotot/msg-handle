#include "sspconf_handler.hpp"

SSPCONFHandler::SSPCONFHandler(const char *prefix, const char *sufix) : MsgHandle(prefix, sufix)
{
}

int SSPCONFHandler::resolve(const char *content)
{
    printk("Resolvendo %s\n", content);
    return 0;
}
