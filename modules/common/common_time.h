#pragma once 

#include <stdint.h>
#include <stdio.h>

typedef struct 
{
    uint64_t logical_tick; 
    uint64_t monotonic_ns; 
} common_time_t; 