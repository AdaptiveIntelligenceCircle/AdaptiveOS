#pragma once 

#include "common_ids.h"
#include "common_types.h"
#include "common_time.h"

typedef struct 
{
    common_identity_t id; 
    common_time_t time; 
    uint32_t type; 
    void* payload; 
    
} common_event_t; 