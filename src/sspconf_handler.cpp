#include "sspconf_handler.hpp"

SSPCONFHandler::SSPCONFHandler(const char *prefix, const char *sufix) : MsgHandle(prefix, sufix)
{
}

int SSPCONFHandler::resolve(const char *content)
{
    payload(content);
    printk("payload: %s\n", m_content);
    char *pass = splitPick(m_content, " ", 2);
    printk("pass: %s\n", pass);
    return 0;
}
