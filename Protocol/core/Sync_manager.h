#pragma once 
#include <string> 

#include <unordered_map>
#include <mutex> 

#include <optional>
#include <vector> 

#include <functional>
using namespace std; 

// Sync Manager .. 
namespace protocol :: core
{
    struct Version
    {
        string node_id; 
        uint64_t counter; 
    };

    struct ValueEntry
    {
        string value; // opaque string payload (could be JSON).. 
        vector<Version> versions; // vector - check entries.. 
    };
    
    using MergeFn = function<string(const ValueEntry &local, const ValueEntry &remote)>; 

    class SyncManager
    {
        public:  
        SyncManager(const string &local_node_id); 

        // put key with local increment.. 
        void put(const string &key, const string &value); 

        // get key 
        optional<ValueEntry> get(const string &key) const; 

        // incoming remote update :  merge into local.. 
        void merge_remote(const string &key, const ValueEntry &remote);

        // set merge fucntion (custom conflict resolver).. 
        void set_merge_fn(MergeFn fn); 

        // snapshot / restore .. 
        unordered_map<string, ValueEntry> snapshot() const; 
        void restore_from_snapshot(const unordered_map<string, ValueEntry> &snap);

        private: 
        mutable mutex mtx; 
        unordered_map<string, ValueEntry> store; 
        string node_id; 
        MergeFn merge_fn; 

        uint64_t local_counter = 1; 
    }; 
} // namespace protocol; 
