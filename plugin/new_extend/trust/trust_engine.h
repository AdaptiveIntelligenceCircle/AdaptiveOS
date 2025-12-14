#pragma once 
#include <string> 
#include "trust_score.h"
using namespace std; 

namespace adaptive :: plugin :: trust
{
    class TrustEngine
    {
        public: 
        TrustScore get_score(const string &ext_id) const; 
        void update_score(const string &ext_id, double delta); 
    }; 
}