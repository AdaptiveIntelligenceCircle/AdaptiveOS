#include <stdio.h>
#include "override_manager.h"

int override_request(
    const authority_token_t *token, 
    override_action_t action, 
    const char *reason
)
{
    if (!token || authority_token_validate(token) != 0)
    return -1; 

    printf("Control - Override requested\n");
    printf("Token : %s\n", token -> token_id); 
    printf("action : %d\n", action); 
    printf("reason : %s\n", reason ? reason : "N/A"); 

    // forward to governance layer (stub).. 
    return 0; 
}