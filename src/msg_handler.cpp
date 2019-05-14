#include "msg_handler.h"

MsgHandler::MsgHandler(const char *prefix, const char *suffix)
{
    memset(m_body, 0, BODY_LENGTH);
    memset(m_prefix, 0, PREFIX_LENGTH);
    memset(m_suffix, 0, SUFFIX_LENGTH);

    strcpy(m_prefix, prefix);
    strcpy(m_suffix, suffix);
}


char *MsgHandler::prefix()
{
    //memset(prefix, 0, PREFIX_LENGTH);
    //strcpy(prefix, m_prefix);

    return m_prefix;
}

char *MsgHandler::suffix()
{
    //memset(suffix, 0, SUFFIX_LENGTH);
    //strcpy(suffix, m_sufix);

    return m_suffix;
}
