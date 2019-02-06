#include "sspconf_handler.hpp"

SSPCONFHandler::SSPCONFHandler(const char *prefix, const char *sufix) : MsgHandle(prefix, sufix)
{
}

int SSPCONFHandler::resolve(char *body)
{
    char pass[50];
    printk("VOU COPIAR");
    strcpy(pass, body);
    printk("COPIEI\n");
    printk("pass: %s\n", pass);
    splitPick(pass, " ", 3);
    printk("pass: %s\n", pass);
    return 0;
}
