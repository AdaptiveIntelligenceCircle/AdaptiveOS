#include <stdio.h>
#include "governance_bridge.h"

int governance_submit_decision(
    const hitl_decision_record_t * decision, 
    const authority_token_t *token
)
{
    if (!decision || !token )
    {
        return -1; 
    }

    printf("Governance bridge");
    printf("Decision : %d\n" , decision -> decision); 
    printf("Scope : %d\n", decision -> scope); 
    printf("Token : %s\n", token -> token_id);
    
    // governance validates + enforces (stub).. 
    return 0; 
}