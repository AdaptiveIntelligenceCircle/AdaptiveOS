#include "../include/ai_core.h"
#include "../../common/logging.h"

using namespace std; 

extern "C"{
    // ham nay se duoc microkernel goi khi load module.. 
    void module_init()
    {
        LOG_INFO("Adaptive AI module loaded"); 
        AdaptiveAIEngine :: instance().intialize(); 
    }

    // Cac hook ma kernel se goi.. 
    void on_file_access(const char *path, const char *process)
    {
        AdaptiveAIEngine :: instance().onFileAccess(path, process); 
    }

    void on_network_packet(const char *src_ip, const char *data_hash)
    {
        AdaptiveAIEngine :: instance().onNetworkPacket(src_ip, data_hash);
    }
}
