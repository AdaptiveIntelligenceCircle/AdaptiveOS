#include "rule_engine.h"
using namespace std ; 

namespace adaptive :: plugin :: rules
{
    RuleResult RuleEngine :: evaluate(const string &ext_id)
    {
        (void) ext_id; 

        // Skeleton 
        // --inspect behavior logs.. 
        // --inspect trust delta.. 
        // --inspect violation counters.. 
        return default_result(); 
    }

    RuleResult RuleEngine :: default_result() const 
    {
        return {RuleAction :: NONE, "no rule triggered"}; 
    }
}