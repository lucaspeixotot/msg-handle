#ifndef _SSPCONF_HANDLER_HPP_
#define _SSPCONF_HANDLER_HPP_

#include <errno.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "tc_msg_handle.hpp"

#define PREFIX "SSPCONF"
#define SUFIX "\n"

class SSPCONFHandler : Public MsgHandle
{
   public:
    SSPCONFHandler(const char *prefix, const char *sufix);
    int resolve(const char *content);

   protected:
    u8_t m_test;
};

#endif
