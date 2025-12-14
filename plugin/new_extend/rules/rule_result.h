#pragma once 
#include <string> 

using namespace std; 

namespace adaptive :: plugin :: rules
{
    enum class RuleAction
    {
        NONE, 
        DEGRADE, 
        FREEZE, 
        ROLLBACK, 
        ISOLATE
    }; 

    struct RuleResult
    {
        RuleAction action;
        string reason; 
    }; 
}