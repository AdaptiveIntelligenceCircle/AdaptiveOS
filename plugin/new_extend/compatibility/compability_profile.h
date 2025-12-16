#pragma once 
#include "../common/version.h"

using namespace std; 

namespace adaptive :: plugin :: compability
{
    struct CompabilityProfile
    {
        common :: Version required_os; 
        common :: Version required__protocol; 
    }; 
}