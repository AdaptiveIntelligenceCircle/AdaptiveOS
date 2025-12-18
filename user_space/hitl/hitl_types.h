#ifndef HITL_TYPES_H 
#define HITL_TYPES_H 

#include <time.h>

typedef enum
{
    HITL_DECISION_APPROVE, 
    HITL_DECISION_DENY, 
    HTIL_DECISION_DEFER, 
    HITL_DECISION_EMERGENCY
}hitl_decision_t; 


typedef enum 
{
    HITL_SCOPE_VIEW, 
    HITL_SCOPE_APPROVE, 
    HITL_SCOPE_OVERRIDE, 
    HITL_SCOPE_EMERGENCY
}hitl_scope_t; 

typedef enum 
{
    HITL_SESSION_OPEN, 
    HITL_SESSION_CLOSED, 
    HITL_SESSION_EXPIRED
} hitl_session_state_t;

typedef struct 
{

    char session_id [64]; 
    hitl_scope_t scope; 
    time_t expires_at; 
    hitl_session_state_t states; 

}hitl_session_t; 

typedef struct 
{
    hitl_decision_t decision; 
    hitl_scope_t scope; 
    char reason[256]; 
    time_t timestamp; 
} hitl_decision_record_t; 

#endif 