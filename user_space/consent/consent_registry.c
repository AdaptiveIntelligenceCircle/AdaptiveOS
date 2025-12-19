#include <stdio.h>
#include <string.h>

#include "consent_registry.h"

static consent_record_t registry[16]; 

int register_consent
(
    const consent_record_t *record 
)
{
    if (!record) return -1; 

    for (int i = 0 ; i < 16 ; i++)
    {
        if (!registry[i].active)
        {
            registry[i] = *record; 
            registry[i].active = 1; 

            printf("Consent - Registered\n"); 
            printf("Subject ID : %s\n", record ->subject_id); 
            printf("Scope : %d\n", record -> scope); 
            return 0; 
        }
    }
    return -2; 
}

int check_consent
(
    const char *subject_id, 
    permission_scope_t scope 
)
{
    for (int i = 0 ; i < 16 ; i++)
    {
        if (registry[i].active && strcmp(registry[i].subject_id, subject_id) == 0 
        && registry[i].scope == scope)
        {
            return 1; 
        }
    }
    return 0; 
}