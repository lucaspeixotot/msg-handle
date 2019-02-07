#include "sspconf_handler.h"

SSPCONFHandler::SSPCONFHandler(const char *prefix, const char *sufix) : MsgHandle(prefix, sufix)
{
}

int SSPCONFHandler::resolve(char *body)
{
    char bodyCopy[50];
    strcpy(bodyCopy, body);
    printk("body: %s\n", bodyCopy);
    char *pass = splitPick(bodyCopy, " ", 2);
    printk("password: %s\n", pass);
    return 0;
}

int SSPCONFHandler::mountBody(char byte)
{
    printk("hahahaha-> %c\n", byte);
}
