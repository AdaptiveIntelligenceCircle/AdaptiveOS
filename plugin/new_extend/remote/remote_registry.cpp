#include "remote_registry.h"
#include <stdexcept>

using namespace std; 
#include <iostream> 

namespace adaptive :: plugin :: remote
{
    RemoteRegistry &RemoteRegistry :: instance()
    {
        static RemoteRegistry inst; 
        return inst; 
    }

    void RemoteRegistry :: register_extension(const 
    string &ext_id, const RemoteRecord &record)
    {
        records_[ext_id] = record; 
    }

    bool RemoteRegistry :: has_record(const string &ext_id) const 
    {
        return records_.count(ext_id) > 0; 
    }

    RemoteRecord RemoteRegistry :: get_record(const string &ext_id) const 
    {
        auto it =  records_.find(ext_id); 
        if (it == records_.end()){
            throw runtime_error("Remote record not found"); 
        }
        return it -> second; 
    }
}