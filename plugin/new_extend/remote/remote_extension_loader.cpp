#include "remote_extension_loader.h"
#include <filesystem> 

#include "remote_registry.h"
#include <fstream> 
using namespace std; 

namespace adaptive :: plugin :: remote
{
    RemoteLoadResult RemoteExtensionLoader :: fetch_and_stage(
        const string &uri
    )
    {
        // Giai doan nay chi fetch + stage.. 
        // KHong load, khong execute..
        if (uri.empty())
        {
            return RemoteLoadResult :: REJECTED; 
        }

        // Gia lap : sau nay thay bang HTTPS/ P2P / secure fetch.. 
        if (!filesystem :: exists(uri)){
            return RemoteLoadResult :: REJECTED; 
        }

        // Chua verify thi cho vao quarantine.. 
        if (!verify_signature(uri)){
            return RemoteLoadResult :: QUARANTINED; 
        }
        return RemoteLoadResult :: ACCEPTED; 

        bool verified = verify_signature(uri);

    RemoteRecord record;
    record.uri = uri;
    record.hash = "TODO_HASH";
    record.verified = verified;

    // ext_id sẽ do governance/lifecycle gán sau
    RemoteRegistry::instance().register_extension(uri, record);

    return verified
        ? RemoteLoadResult::ACCEPTED
        : RemoteLoadResult::QUARANTINED;
    }

    bool RemoteExtensionLoader :: verify_signature(const 
    string &package_path)
    {
        if (package_path.find(".signed") == string :: npos)
        {
            return false; 
        }
        return true; 
    }

    bool RemoteExtensionLoader :: check_compability(
        const string &manifest 
    )
    {
        return validate_schema(manifest); 
    }

    bool RemoteExtensionLoader :: validate_schema(const string &manifest)
    {
        // Skeleton : Json/ YAML schema validation.. 
        if (manifest.empty()) return false; 
        return true; 
    }
} // namespace std; 