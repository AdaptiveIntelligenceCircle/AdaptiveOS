#include <string.h>
#include <stdio.h>

#include <time.h>
#include "hitl_types.h"

static void generate_session_id(char *buf, size_t sz)
{
    snprintf(buf, sz, "HITL- %d", time(NULL));
}

int hitl_open_session(hitl_scope_t scope, hitl_session_t *out)
{
    if (!out) return -1; 
    
    memset(out, 0, sizeof(*out)); 
    generate_session_id(out -> session_id, sizeof(out -> session_id)); 

    out -> scope = scope; 
    out -> states = HITL_SESSION_OPEN; 
    out -> expires_at = time(NULL) + 300; 

    return 0; 
}

int hitl_close_session(hitl_session_t *session)
{
    if (!session) return -1; 
    session -> states = HITL_SESSION_CLOSED; 
    return 0; 
}