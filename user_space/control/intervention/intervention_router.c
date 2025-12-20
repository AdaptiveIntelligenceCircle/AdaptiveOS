#include <stdio.h>
#include "intervention_router.h"
#include "override_manager.h"
#include "safe_mode_trigger.h"

#include "emergency_console.h"

int route_intervention(
    const authority_token_t *token, 
    intervention_type_t type, 
    const control_context_t *ctx, 
    const char *reason 
)
{
    if (!token || !ctx)
    {
        return -1; 
    }

    printf("CONTROL ROUTER\n"); 
    printf(" ctx : %s\n", ctx -> context_id); 
    printf(" Reason : %s\n", reason); 

    switch (type)
    {
    case INTERVENTION_OVERRIDE:
        /* code */
        return override_request(token, OVERRIDE_PAUSE, reason); 
        break;
    case INTERVENTION_SAFE_MODE: 
        return trigger_safe_mode(token, reason); 
    case INTERVENTION_EMERGENCY: 
        return emergency_shutdown(token, reason); 
    default:
        return -2;
        break;
    }
}
