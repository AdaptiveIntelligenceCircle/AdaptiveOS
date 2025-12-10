#include <string> 
#include <iostream> 
using namespace std; 

extern void on_network_packet(const char *src_ip, const char *data_hash); 

void analyze_packet(const char *src_ip, const uint8_t *payload, size_t len)
{
    string hash = compute_sha256(payload, len); 
    cout << "Packet from" << string(src_ip) + "hash:" + hash << endl; 

    on_network_packet(src_ip, hash.c_str()); 

    // quyet dinh drop/route dua tren AI trust score.. 
}