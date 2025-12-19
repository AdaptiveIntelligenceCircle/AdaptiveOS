#include <stdio.h>
#include "safe_mode_trigger.h"

int trigger_safe_mode(
    const authority_token_t *token, 
    const char *reason
)
{
    if (token == NULL || authority_token_validate(token) != 0)
    return -1; 

    printf("SAFE MODE"); 
    printf("Activated by token :  %s\n", token -> token_id); 
    printf("Reason : %s\n", reason); 

    // governance enforces safe mode (stub).. // 
    return 0; 
}