#pragma once 

#include "common_ids.h"

typedef struct 
{
    trace_id_t parent; 
    trace_id_t current; 
} common_trace_t; 