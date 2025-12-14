#pragma once 
#include <string> 

#include <vector> 
#include "rule_result.h"

using namespace std; 


namespace adaptive :: plugin :: rules
{
    class RuleEngine
    {
        public: 
        RuleResult evaluate(const string &ext_id); 

        private: 
        RuleResult default_result() const; 
    }; 
}