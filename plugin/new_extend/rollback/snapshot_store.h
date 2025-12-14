#pragma once 
#include <string> 

#include <unordered_map>
using namespace std; 

namespace adaptive :: plugin :: rollback
{
    struct Snapshot
    {
        string snapshot_id;
        string ext_id; 
        string state_hash;  
    };

    class SnapshotStore
    {
        public: 
        static SnapshotStore &instance(); 

        void save_snapshot(const Snapshot &snapshot); 
        bool has_snapshot(const string &ext_id) const; 
        Snapshot get_snapshot(const string &ext_id) const; 

        private: 
        SnapshotStore() = default; 
        unordered_map<string, Snapshot> snapshots_; 
    }; 
}