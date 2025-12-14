#pragma once 
#include <string> 

using namespace std; 

namespace adaptive :: plugin :: sandbox
{
    struct SandboxProfile
    {
        bool allow_network = false;
        bool allow_filesystem = false; 
        bool allow_ipc = false; 
    }; 
}