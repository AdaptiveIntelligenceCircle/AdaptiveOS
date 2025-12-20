#ifndef INTERVENTION_ROUTER_H 
#define INTERVENTION_ROUTER_H 

#include "../include/authority_tokens.h"
#include "../control/context/control_context.h"

typedef enum
{
    INTERVENTION_OVERRIDE, 
    INTERVENTION_SAFE_MODE, 
    INTERVENTION_EMERGENCY
} intervention_type_t; 

int route_intervention(
    const authority_token_t* token, 
    intervention_type_t type, 
    const control_context_t *context, 
    const char *reason 
); 

#endif 