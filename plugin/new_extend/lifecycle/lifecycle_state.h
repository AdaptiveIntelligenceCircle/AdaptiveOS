#include <iostream>
using namespace std; 

#include <string> 
#include <algorithm>

enum class ExtensionState
{
    CREATED, 
    VALIDATING, 
    SANDBOXING, 
    SNAPSHOTTED, 
    RUNNING, 
    DEGRADED, 
    FROZEN, 
    ROLLED_BACK, 
    ISOLATED, 
    TERMINATED
}; 