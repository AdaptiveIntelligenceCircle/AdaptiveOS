#pragma once 

#include "common_types.h"

typedef struct 
{
    node_id_t node; 
    module_id_t module; 
    event_id_t event; 
    trace_id_t trace; 
    
} common_identity_t; 