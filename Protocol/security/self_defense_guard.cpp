#include "self_defense.h"
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std; 

namespace protocol :: security
{
    SelfDefense :: SelfDefense(){}
    SelfDefense :: ~SelfDefense(){}

    void SelfDefense :: note_publish(const string &session_id, const string &topic)
    {
        publish_count[session_id]++; 
        // immediate heuristic : if micro -flood detected. 
        if (publish_count[session_id] > publish_threshold *10)
        {
            cout << "Self-Defense : extreme publish flood" << endl;
            if (quarantine_node) quarantine_node(session_id);  
        }
    }

    void SelfDefense :: note_receive(const string &session_id, const string &topic)
    {
        receive_count[session_id]++;
    }

    void SelfDefense :: register_revoke_session_cb(function<void(const string &)> cb)
    {
        revoke_session = cb; 
    }

    void SelfDefense :: register_quaratine_cb(function<void(const string &)> cb)
    {
        quarantine_node = cb; 
    }

    void SelfDefense :: register_disable_module_cb(function<void(const string &)> cb)
    {
        disable_module = cb; 
    }

    void SelfDefense :: allow_module(const string &module)
    {
        module_allowed[module] = true; 
    }

    void SelfDefense :: disallow_module(const string &module)
    {
        // for each session, if publish_count > threshold -> revoke.. 
        for (auto &p : publish_count)
        {
            if (p.second > publish_threshold)
            {
                cout << "Self Defense : excessive publish" << endl; 
                if (revoke_session) revoke_session(p.first); 
            }
        }
        publish_count.clear(); 
        receive_count.clear(); 
    }
}
