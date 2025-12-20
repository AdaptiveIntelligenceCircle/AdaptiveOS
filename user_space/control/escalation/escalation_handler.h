#ifndef escalation_handler_h 
#define escalation_handler_h

#include "../include/authority_tokens.h"
#include "../control/context/control_context.h"

int escalate_control
(
    const authority_token_t *token, 
    const control_context_t *ctx, 
    const char *reason 
); 

#endif 