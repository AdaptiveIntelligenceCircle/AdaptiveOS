#pragma once
#include <string>
using namespace std; 

namespace adaptive::plugin::rollback 
{

class RollbackManager 
{
public:
    bool prepare_snapshot(const string& ext_id);
    bool rollback(const string& ext_id);

private:
    bool restore_state(const string& snapshot_id);
};

}
