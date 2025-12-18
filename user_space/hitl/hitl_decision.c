#include <string.h>
#include <time.h>

#include "hitl_types.h"

int hitl_nomralize_decision
(
    hitl_session_t *session, 
    hitl_decision_t decision, 
    const char *reason, 
    hitl_decision_record_t *out
)
{
    if (!session || !out || session -> states != HITL_SESSION_OPEN)
    {
        return -1;
    }

    time_t now = time(NULL); 
    if (now > session -> expires_at)
    return -2; 

    memset(out, 0 , sizeof(*out)); 
    out -> decision = decision; 
    out -> scope = session -> scope; 
    out -> timestamp = now; 

    if (reason)
    strncpy(out -> reason, reason, sizeof(out -> reason) - 1);
     
    return 0; 
}