#include <stdio.h>
#include "protocol_adapter.h"

int protocol_send_command(
    const protocol_command_t *cmd, 
    const authority_token_t *token 
)
{
    if (cmd == NULL || token == NULL || authority_token_validate(token) != 0)
    {
        return -1; 
    }

    printf("Protocol Adapter - Sending Command\n"); 
    printf("Target : %s\n", cmd -> target);
    printf("Action : %s\n", cmd -> action); 
    printf("token : %s\n", token -> token_id); 

    // translate to adaptive OS protocol // 
    return 0; 
}