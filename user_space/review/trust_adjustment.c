#include <stdio.h>
#include "trust_adjust.h"

int adjust_trust 
(
    const char *entity_id, 
    trust_action_t action, 
    const char *reason 
)
{
    if (!entity_id)
    {
        return -1; 
    }

    printf("REVIEW - Trust Adjustment\n"); 
    printf("Entity ID : %s\n", entity_id); 

    printf("Action : %d\n", action); 
    printf("Reason : %s\n", reason ? reason : "N/A"); 

    // trust engine applied changes.. 
    return 0; 
}