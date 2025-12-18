#include <time.h>
#include "../include/hitl_timeout_escalation.h"

int hitl_check_timeout(hitl_session_t *session)
{
    if (!session) return -1; 

    if (session -> states != HITL_SESSION_OPEN)
    return 0;
    
    if (time(NULL) > session -> expires_at)
    {
        session -> states = HITL_SESSION_EXPIRED; 
        return 1; // escalated// 
    }
    return 0; 
}