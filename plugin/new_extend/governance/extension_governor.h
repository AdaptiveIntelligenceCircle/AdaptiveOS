#pragma once 
#include <string> 

#include <memory> 
#include "capability_model.h"

using namespace std ;

namespace adaptive :: plugin :: governance
{
    enum class GovernanceVerdict
    {
        ALLOW, 
        DENY, 
        DEGRADE, 
        FREEZE, 
        ROLLBACK, 
        ISOLATE, 
        REVOKE
    }; 

    struct GovernanceContext
    {
        string extension_id; 
        double trust_score; 
        CapabilityProfile capabilities;
        bool sandbox_ready; 
        bool snapshot_ready; 
    }; 

    class ExtensionGovernor
    {
        public: 
        static ExtensionGovernor &instance(); 

        GovernanceVerdict evaluate_admission(const GovernanceContext &ctx); 
        GovernanceVerdict evaluate_runtime(const GovernanceContext &ctx); 

        void enforce_verdict(const string &extension_id, GovernanceVerdict verdict);

        private: 
        ExtensionGovernor () = default; 
    }; 
}