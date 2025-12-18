#ifndef EMERGENCY_CONSOLE_H
#define EMERGENCY_CONSOLE_H

#include "../include/authority_tokens.h"

int emergency_shutdown(
    const authority_token_t* token,
    const char* reason
);

#endif
