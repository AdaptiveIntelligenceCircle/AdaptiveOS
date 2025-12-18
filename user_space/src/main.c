#include <stdio.h>
#include "../hitl/hitl_interface.h"
// #include "../hitl/hitl_interface.c"

int main ()
{
    hitl_session_t session; 
    hitl_decision_record_t decision; 

    hitl_init(); 
    hitl_open_session(HITL_SCOPE_APPROVE, &session); 

    hitl_request_decision(
        &session, 
        "Rollback requested due to anomaly", 
        &decision 
    ); 

    hitl_close_session(&session); 
    return 0; 
}