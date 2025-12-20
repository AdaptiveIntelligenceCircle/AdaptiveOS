#include <stdio.h>
#include "escalation_handler.h"

int escalate_control(
    const authority_token_t *token, 
    const control_context_t *ctx, 
    const char *reason
)
{
    printf("Escalation Handler - Escalating Control\n");
    printf("Ctx : %s\n", ctx ? ctx -> source : "unknown"); 
    printf("Reason : %s\n", reason); 

    // escalation goes back to HITL / governance 
    return 0 ; 
}