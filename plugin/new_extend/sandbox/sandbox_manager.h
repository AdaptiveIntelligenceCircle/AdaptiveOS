#pragma once 
#include <string> 

using namespace std ; 

#include "sandbox_profile.h"

namespace adaptive :: plugin :: sandbox
{
    class SandboxManager
    {
        public: 
        bool attach(const string &ext_id, const SandboxProfile &profile);
        bool detach(const string &ext_id);

        bool is_active(const string &ext_id) const; 
    }; 
}