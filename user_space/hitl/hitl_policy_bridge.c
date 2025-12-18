#include <stdio.h>
#include "hitl_types.h"

int hitl_apply_policy(const hitl_decision_record_t * decision)
{
    if (!decision) return -1; 

    // hard authority boundary.. // 
    if (decision -> decision == HITL_DECISION_EMERGENCY && decision -> scope != HITL_SCOPE_EMERGENCY)
    {
        return -2; // forbidden.. 
    }

    // forward to governance (stub).. // 
    printf("HITL - decision forwarded : % d |reason : %s\n", 
    decision ->decision, decision -> reason); 

    return 0; 
}