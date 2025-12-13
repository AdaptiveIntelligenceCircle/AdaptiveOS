#pragma once 
#include <string> 

#include "lifecycle_state.h"
using namespace std; 

namespace adaptive :: plugin :: lifecycle 
{
    class LifeCycleManager
    {
        public: 
        void initialize(const string &ext_id); 

        bool transition(const string &ext_id, ExtensionState from, 
        ExtensionState to); 

        ExtensionState current_state(const string &ext_id) const; 

        bool is_terminal(ExtensionState state) const; 

        private: 
        bool is_valid_transition(ExtensionState from, ExtensionState to) const; 
    }; 
}