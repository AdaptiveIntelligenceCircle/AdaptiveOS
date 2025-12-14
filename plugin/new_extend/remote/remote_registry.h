#pragma once 
#include <string> 

#include <unordered_map>
using namespace std; 

namespace adaptive :: plugin :: remote
{
    struct RemoteRecord
    {
        string uri; 
        string hash; 
        bool verified; 
    }; 

    class RemoteRegistry
    {
        public: 
        static RemoteRegistry &instance(); 

        void register_extension(const string &ext_id, 
        const RemoteRecord &record); 

        bool has_record(const string &ext_id) const; 
        RemoteRecord get_record(const string &ext_id) const;
        
        private : 
        RemoteRegistry() = default;
        unordered_map<string, RemoteRecord> records_; 
    }; 
}