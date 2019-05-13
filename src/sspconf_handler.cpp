#include "sspconf_handler.h"

SSPCONFHandler::SSPCONFHandler(char *prefix, char *suffix, char *init_body,
                               char *delimiter, u8_t argc)
    : EventCommand(prefix, suffix, init_body, delimiter, argc)
{
    printk("prefix %s\n", prefix);
    printk("suffix %s\n", suffix);
}

int SSPCONFHandler::resolve()
{
    printk("The 1 argument is: %s\n", m_argv[0]);
    printk("The 2 argument is: %s\n", m_argv[1]);
    printk("The 3 argument is: %s\n", m_argv[2]);
    return 0;
}
