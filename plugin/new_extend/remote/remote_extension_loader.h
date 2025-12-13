#pragma once 
#include <string> 

#include <iostream> 
using namespace std;

namespace adaptive :: plugin :: remote
{
    enum class RemoteLoadResult
    {
        ACCEPTED, 
        REJECTED, 
        QUARANTINED
    }; 

    class RemoteExtensionLoader
    {
        public: 
        RemoteLoadResult fetch_and_stage(const string &uri); 

        bool verify_signature(const string &package_path); 
        bool check_compability(const string &manifest); 

        private:
        bool validate_schema(const string &manifest); 
    }; 
}