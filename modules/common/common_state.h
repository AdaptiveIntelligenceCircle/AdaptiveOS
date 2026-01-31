#pragma once 
#include "common_types.h"

typedef enum  
{
    STATE_INIT, 
    STATE_ACTIVE, 
    STATE_DEGRADED, 
    STATE_QUARANTINED, 
    STATE_TERMINATED
} common_state_t; 