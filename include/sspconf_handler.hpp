#ifndef _SSPCONF_HANDLER_HPP_
#define _SSPCONF_HANDLER_HPP_

#include <errno.h>
#include <misc/printk.h>
#include <zephyr/types.h>

#include "tc_msg_handle.hpp"

#define SSPCONF_PREFIX "SSPCONF"
#define SSPCONF_SUFIX "OK"

class SSPCONFHandler : public MsgHandle
{
   public:
    SSPCONFHandler(const char *prefix, const char *sufix);
    int resolve(char *body);

   protected:
    u8_t m_test;
};

#endif
