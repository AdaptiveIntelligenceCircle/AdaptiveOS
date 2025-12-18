#ifndef OVERRIDE_MANAGER_H
#define OVERRIDE_MANAGER_H 

#include "../include/authority_tokens.h"

typedef enum 
{
    OVERRIDE_NONE, 
    OVERRIDE_PAUSE, 
    OVERRIDE_ISOLATE, 
    OVERRIDE_FORCE_ROLLBACK
}override_action_t; 

int override_request(
    const authority_token_t * token, 
    override_action_t action, 
    const char *reason 
); 

#endif 