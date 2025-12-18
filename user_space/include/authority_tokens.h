#ifndef AUTHORITY_TOKEN_H 
#define AUTHORITY_TOKEN_H 

#include <time.h>
#include "../hitl/hitl_types.h"

typedef struct 
{
    char token_id[64]; 
    hitl_scope_t scope; 
    time_t issued_at;
    time_t expires_at; 
    int valid; 
} authority_token_t; 

int authority_token_issue(
    hitl_scope_t scope, 
    authority_token_t *out
);  

int authority_token_validate(
    const authority_token_t *token  
); 
#endif 