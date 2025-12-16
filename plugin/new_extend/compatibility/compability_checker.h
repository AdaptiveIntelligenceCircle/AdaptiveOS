#pragma once 
#include "compability_profile.h"
#include "../common/extension_result.h"

using namespace std ; 

namespace adaptive :: plugin :: compability
{
    class CompabilityChecker
    {
        public: 
        common :: result<bool> check(
            const CompabilityChecker &profile 
        ) const ; 
    }; 
}