#include <stdio.h>
#include "rollback_approval.h"

int approve_rollback
(
    const authority_token_t *token, 
    const char *target, 
    const char *reason 
)
{
    if (!token || authority_token_validate(token) != 0)
    {
        return -1; 
    }

    printf("Approve Rollback request\n"); 
    printf("Target : %s\n", target); 

    printf("Token ID : %s\n", token -> token_id); 
    printf("Reason : %s\n", reason);

    // Governance executes rollback .. 
    return 0; 
}