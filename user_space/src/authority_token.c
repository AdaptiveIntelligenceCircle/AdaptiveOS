#include "../include/authority_tokens.h"
#include <stdio.h>

#include <time.h>
#include <string.h>

static void generate_token_id(char *buf, size_t sz)
{
    snprintf(buf, sz, "AUTH- %ld", time(NULL)); 
}

int authority_token_issue(hitl_scope_t scope, authority_token_t *out)
{
    if (!out) return -1; 
    memset(out, 0, sizeof(*out)); 
    generate_token_id(out -> token_id, sizeof(out -> token_id)); 

    out -> scope = scope; 
    out -> issued_at = time(NULL); 
    out -> expires_at = out -> issued_at + 300 ; 
    out -> valid = 1; 

    return 0; 
}

int authority_token_validate(const authority_token_t *token)
{
    if (!token || ! token -> valid)  return -1; 
    if (time(NULL) > token -> expires_at) return -2; 
    return 0; 
}