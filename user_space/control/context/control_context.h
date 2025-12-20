#ifndef CONTROL_CONTEXT_H 
#define CONTROL_CONTEXT_H 

#include <time.h>

typedef enum 
{
    CONTROL_CTX_ANOMALY, 
    CONTROL_CTX_SECURITY, 
    CONTROL_CTX_SYSTEM_HEALTH, 
    CONTROL_CTX_EXTERNAL
}control_context_type_t; 

typedef struct 
{
    /* data */
    char context_id[64]; 
    control_context_type_t type; 
    char source[64]; 
    time_t timestamp; 

}control_context_t ;

#endif 