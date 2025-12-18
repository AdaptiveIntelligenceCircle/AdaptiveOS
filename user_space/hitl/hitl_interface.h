// #include <stdio.h>

// typedef enum 
// {
//     HITL_DECISION_APPROVE, 
//     HTIL_DECISION_DENY, 
//     HITL_DECISION_DEFER,
//     HITL_DECISION_EMERGENCY
// }hitl_decision_t; 

// int hitl_request_decision(
//     const char *context_id, 
//     const char *reason, 
//     hitl_decision_t *out_decision
// ); 

#ifndef HITL_INTERFACE_H
#define HITL_INTERFACE_H

#include "hitl_types.h"
#include "../include/authority_tokens.h"

int hitl_init(void);

int hitl_open_session(
    hitl_scope_t scope,
    hitl_session_t* out
);

int hitl_request_decision(
    hitl_session_t* session,
    const char* reason,
    hitl_decision_record_t* out_decision,
    authority_token_t* out_token
);

int hitl_close_session(
    hitl_session_t* session
);

#endif
