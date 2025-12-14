#include "sandbox_manager.h"
#include <unordered_set>

using namespace std; 

namespace adaptive :: plugin :: sandbox
{
    static unordered_set<string> g_active; 

    bool SandboxManager :: attach(const string &ext_id, 
    const SandboxProfile &profile)
    {
        (void) profile;
        g_active.insert(ext_id); 
        return true; 
    }

    bool SandboxManager :: detach(const string &ext_id)
    {
        return g_active.erase(ext_id) > 0; 
    }

    bool SandboxManager :: is_active(const string&ext_id) const 
    {
        return g_active.count(ext_id) > 0; 
    }
}