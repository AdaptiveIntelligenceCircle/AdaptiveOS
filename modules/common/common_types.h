#pragma once 
#include <stdint.h>

#include <stdio.h>
#include <stdbool.h>

typedef uint64_t node_id_t; 
typedef uint64_t module_id_t; 
typedef uint64_t event_id_t;
typedef uint64_t trace_id_t; 

typedef enum  
{
    COMMON_OK = 0, 
    COMMON_PENDING, 
    COMMON_REJECTED, 
    COMMON_ESCALATED, 
    COMMON_UNKNOWN
} common_status_t; 

