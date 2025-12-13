#pragma once 
#include <string> 

#include <set> 
using namespace std; 

namespace adaptive :: plugin :: governance 
{
    // Capability = quyen duoc cap cho extension.. 
    // Ma la quyen hanh vi cap he thong// 

    enum class Capability
    {
        READ_SENSOR, 
        WRITE_CONTROL_HINT, 
        EMIT_EVENT, 
        REGISTER_RULE,
        REQUEST_SYNC, 
        REMOTE_COMMUNICATION, 
        PERSIST_STATE
    }; 

    struct CapabilityProfile
    {
        set<Capability> allowed; 
        set<Capability> denied; 

        bool allows(Capability cap) const 
        {
            return allowed.count(cap) and !denied.count(cap); 
        }
    }; 
} // namespace 