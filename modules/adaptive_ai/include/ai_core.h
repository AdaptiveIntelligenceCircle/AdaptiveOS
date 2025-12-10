#pragma once 
#include <string> 
using namespace std; 

class AdaptiveAIEngine
{
    public: 
    static AdaptiveAIEngine &instance () ; 

    void intialize(); 
    void onFileAccess(const string &path, const string &process);
    void onNetworkPacket(const string &src_ip, const string &data_hash);
    void onNetworkPacket (const string &src_ip, const string &);
    void requestHumanDecision(const string &context); 
    
    private:
    AdaptiveAIEngine() = default; 
};  