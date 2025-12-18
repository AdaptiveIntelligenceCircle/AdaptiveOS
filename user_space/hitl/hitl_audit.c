#include <stdio.h>
#include "hitl_types.h"

int hitl_audit_log(const hitl_session_t * session, 
const hitl_decision_record_t * decision)
{
    if (!session || !decision) return -1; 

    printf("AUDIT\n");
    printf("session : %s\n", session -> session_id); 
    printf("scope :%d\n", decision -> scope); 
    printf("reason : %s\n", decision -> reason); 
    printf("action :%d\n", decision -> decision); 

    return 0; 
}