#ifndef _SSPCONF_HANDLER_H_
#define _SSPCONF_HANDLER_H_

#include <errno.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "event_command.h"

#define SSPCONF_PREFIX "SSPCONF"
#define SSPCONF_SUFFIX "---"

class SSPCONFHandler : public EventCommand
{
   public:
    SSPCONFHandler(char *prefix, char *suffix, char *init_body,
                   char *delimiter, u8_t argc);
    int resolve();

   protected:
    u8_t m_test;
};

#endif
