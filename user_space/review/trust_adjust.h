#ifndef TRUST_ADJUST_H 
#define TRUST_ADJUST_H 

typedef enum 
{
    TRUST_INCREASE, 
    TRUST_DECREASE,
    TRUST_FREEZE, 
    TRUST_RESET 
} trust_action_t; 

int adjust_trust(
    const char *entity_id, 
    trust_action_t action, 
    const char *reason 
);
#endif 