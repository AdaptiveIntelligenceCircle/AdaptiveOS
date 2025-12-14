#include "trust_engine.h"
#include <unordered_map>

#include <algorithm>
using namespace std;

namespace adaptive :: plugin :: trust
{
    static unordered_map<string, double> g_scores; 
    TrustScore TrustEngine :: get_score(const string &ext_id) const 
    {
        auto it = g_scores.find(ext_id); 
        if (it == g_scores.end()){
            return {0.5}; // neutral default.. 
        }
        return {
            it -> second 
        }; 
    }

    void TrustEngine :: update_score(const string &ext_id, double delta)
    {
        double &score = g_scores[ext_id];
        score = clamp(score + delta, 0.0, 1.0);  
    }

}