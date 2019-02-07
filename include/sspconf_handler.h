#ifndef _SSPCONF_HANDLER_H_
#define _SSPCONF_HANDLER_H_

#include <errno.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "msg_handle.h"

#define SSPCONF_PREFIX "SSPCONF"
#define SSPCONF_SUFIX "OK"

class SSPCONFHandler : public MsgHandle
{
   public:
    SSPCONFHandler(const char *prefix, const char *sufix);
    int resolve(char *body);
    int mountBody(char byte);

   protected:
    u8_t m_test;
};

#endif
