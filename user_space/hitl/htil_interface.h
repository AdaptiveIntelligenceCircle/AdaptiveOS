#include <stdio.h>

typedef enum 
{
    HITL_DECISION_APPROVE, 
    HTIL_DECISION_DENY, 
    HITL_DECISION_DEFER,
    HITL_DECISION_EMERGENCY
}hitl_decision_t; 

int hitl_request_decision(
    const char *context_id, 
    const char *reason, 
    hitl_decision_t *out_decision
); 