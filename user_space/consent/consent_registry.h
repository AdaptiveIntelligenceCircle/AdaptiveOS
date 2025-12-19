#ifndef CONSENT_REGISTRY_H 
#define CONSENT_REGISTRY_H 

#include "permission_scope.h"

typedef struct 
{
    char subject_id[64]; 
    permission_scope_t scope; 
    int active; 
} consent_record_t;

int register_consent
(
    const consent_record_t *record 
); 

int check_consent
(
    const char *subject_id, 
    permission_scope_t scope 
); 

#endif 