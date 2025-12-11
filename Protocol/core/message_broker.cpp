#include "message_broker.h"
using namespace std; 

#include <iostream>
#include <algorithm>

namespace protocol :: core
{
    MessageBroker :: MessageBroker(){}
    MessageBroker :: ~MessageBroker(){}

    SubcriberId MessageBroker :: subcribe(const string &topic, Callback cb)
    {
        lock_guard <mutex> lock(mtx); 
        SubcriberId id = next_id++; 
        subs.push_back({
            id, topic, cb
        }); 
        return id; 
    }

    void MessageBroker :: unsubcribe(SubcriberId id)
    {
        lock_guard<mutex> lock(mtx); 
        subs.erase(remove_if(subs.begin(), subs.end(),[&](const SubEntry& s){ return s.id==id; } ), subs.end()); 
    }

    void MessageBroker :: publish(const string &topic, const Msg &payload, const MsgOptions &opt)
    {
        vector<Callback> cbs; 
        {
            lock_guard<mutex> lock(mtx); 
            // simple ACL check : if topic has ACL and no subcriber rollback...
            auto acl_it = topic_acl.find(topic); 
            for (auto &s : subs)
            {
                if (s.topic != topic) continue; 
                // if acl exists, we assume subscriber role membership.. 
                cbs.push_back(s.cb); 
            }
        }
        // Deliver outside lock.. 
        for (auto &cb : cbs){
            try {
                cb(topic, payload); 
            }
            catch(const exception &e){
                cerr <<"Broker call" << e.what() << endl; 
            }
            catch(...)
            {
                cout << "Broker callback unknown error\n"; 
            }
        }
    }
    void MessageBroker :: set_topic_acl(const string &topic, const vector<string> &allowed_roles)
    {
        lock_guard<mutex> lock(mtx); 
        topic_acl[topic] = allowed_roles; 
    }
} // namespace protocol.. 