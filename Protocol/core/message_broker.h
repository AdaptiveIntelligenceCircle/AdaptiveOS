#pragma once 
#include <functional>

#include <string> 
#include <unordered_map>

#include <vector> 
#include <mutex> 

#include <memory> 
using namespace std; 

namespace protocol :: core
{
    enum class QoS {
        AT_MOST_ONCE = 0, AT_LEAST_ONCE = 1
    }; 

    struct MsgOptions
    {
        QoS qos = QoS :: AT_LEAST_ONCE; 
        int priority = 0; // higher -> deliver earlier
    }; 

    using Msg = vector<uint8_t>; 
    using SubcriberId = uint64_t; 
    using Callback = function<void(const string &topic, const Msg &payload)>;
    
    class MessageBroker 
    {
        public: 
        MessageBroker(); 
        ~MessageBroker(); 

        // subcriber to a topic, returns subcriber id.. 
        SubcriberId subcribe(const string &topic, Callback cb); 

        // unsubcriber .. 
        void unsubcribe(SubcriberId id); 

        // publish a message.. 
        void publish(const string &topic, const Msg &payload, const MsgOptions &opt = {}); 

        // set topic ACL : allowed roles/ tags (simple)... 
        void set_topic_acl(const string &topic, const vector<string> &allowed_roles);
        
        private: 
        mutable mutex mtx; 
        SubcriberId next_id; 
        struct SubEntry{
            SubcriberId id; 
            string topic; 
            Callback cb; 
        }; 

        vector<SubEntry> subs; 

        unordered_map<string, vector<string>> topic_acl;
    }; 
} // namespace protocol.. 
