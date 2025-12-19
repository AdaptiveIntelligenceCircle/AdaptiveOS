#ifndef ROLBACK_APPROVAL_H
#define ROLLBACK_APPROVAL_H 

#include "../include/authority_tokens.h"

int approve_rollback(
    const authority_token_t *token, 
    const char *target, 
    const char *reason 
);

#endif 

