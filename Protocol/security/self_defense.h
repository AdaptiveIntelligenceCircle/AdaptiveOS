#pragma once 
#include <string> 

#include <functional>
#include <unordered_map>

using namespace std; 

namespace protocol :: security
{
    struct Alert
    {
        string code; 
        string detail; 
        double severity; // 0.1 
    }; 

    class SelfDefense
    {
        public: 
        SelfDefense(); 
        ~SelfDefense(); 

        // monitor API : called by MessageBroker/EncryptionLayer.. 
        void note_publish(const string &session_id, const string &topic);
        void note_receive(const string &session_id, const string &topic); 
        
        // register callbacks to apply counter measures.. 
        void register_revoke_session_cb(function<void(const string &)>cb);
        void register_quaratine_cb(function<void(const string &)> cb); 
        void register_disable_module_cb(function<void(const string &)>cb); 

        // whitelist / blacklist modules..
        void allow_module(const string &module); 
        void disallow_module(const string &module); 

        // periodic scan to escalate or clear alerts.. 
        void periodic_check() ; 

        private: 
        unordered_map<string, int> publish_count; 
        unordered_map<string, int> receive_count; 

        unordered_map<string, bool> module_allowed; 

        function<void(const string&)> revoke_session; 
        function<void(const string &)> quarantine_node; 
        function<void(const string&)> disable_module; 

        // thresholds (configurable).. 
        int publish_threshold = 100;
    };
} // namespace std; 