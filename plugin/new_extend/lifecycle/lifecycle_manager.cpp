#include "lifecycle_manager.h"
#include <unordered_map>
#include <mutex> 

using namespace std; 

namespace adaptive :: plugin :: lifecycle 
{
    static unordered_map<string, ExtensionState> g_states; 
    static mutex g_state_mutex; 

    void LifeCycleManager :: initialize(const string &ext_id)
    {
        lock_guard <mutex> lock(g_state_mutex); 
        g_states[ext_id] = ExtensionState :: CREATED; 
    }

    ExtensionState LifeCycleManager :: current_state(const string &ext_id) const 
    {
        auto it = g_states.find(ext_id); 
        if (it == g_states.end()){
            return ExtensionState :: TERMINATED; 
        }
        return it -> second; 
    }

    bool LifeCycleManager :: is_terminal(ExtensionState state) const 
    {
        return state == ExtensionState :: TERMINATED; 
    }

    bool LifeCycleManager :: transition(const string &ext_id,
    ExtensionState from, ExtensionState to)
    {
        lock_guard<mutex> lock(g_state_mutex); 
        auto it = g_states.find(ext_id); 
        if (it == g_states.end()) return false; 
        if (it -> second != from) return false; 
        if (!is_valid_transition(from,to)) return false; 

        it -> second = to; 
        return true; 
    }

    bool LifeCycleManager :: is_valid_transition(ExtensionState from, 
    ExtensionState to ) const 
    {
        switch(from)
        {
            case ExtensionState :: CREATED: 
            return to == ExtensionState :: VALIDATING;
            
            case ExtensionState :: VALIDATING: 
            return to == ExtensionState :: SANDBOXING; 

            case ExtensionState::SANDBOXING:
            return to == ExtensionState::SNAPSHOTTED;

            case ExtensionState::SNAPSHOTTED:
            return to == ExtensionState::RUNNING;

            case ExtensionState::RUNNING:
            return to == ExtensionState::DEGRADED ||
                   to == ExtensionState::FROZEN ||
                   to == ExtensionState::ISOLATED;

            case ExtensionState::DEGRADED:
            return to == ExtensionState::RUNNING ||
                   to == ExtensionState::FROZEN ||
                   to == ExtensionState::ROLLED_BACK;

            case ExtensionState::FROZEN:
            return to == ExtensionState::RUNNING ||
                   to == ExtensionState::ISOLATED;

            case ExtensionState::ROLLED_BACK:
            return to == ExtensionState::SNAPSHOTTED;

            case ExtensionState::ISOLATED:
            return to == ExtensionState::TERMINATED;

            default:
            return false;
        }
    }
}