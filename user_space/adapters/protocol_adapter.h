#ifndef PROTOCOL_ADAPTER_H
#define PROTOCOL_ADAPTER_H

#include "../include/authority_tokens.h"

typedef struct 
{
    char target[64]; 
    char action[64];  
}protocol_command_t; 

int protocol_send_command
(
    const protocol_command_t* cmd, 
    const authority_token_t *token 
);  

#endif