#ifndef SAFE_MODE_TRIGGER_H 
#define SAFE_MODE_TRIGGER_H 

#include "../include/authority_tokens.h"

int trigger_safe_mode(
    const authority_token_t *token,
    const char *reason 
);
#endif 