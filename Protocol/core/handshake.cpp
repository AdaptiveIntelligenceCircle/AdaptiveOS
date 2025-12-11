#include "handshake.h"
using namespace std; 

#include <chrono>
#include <random> 

namespace protocol :: core
{
    HandshakeManager :: HandshakeManager(){}
    HandshakeManager :: ~HandshakeManager(){}

    optional<string> HandshakeManager :: initiate(const string &local_id, 
    const string &remote_id, const string &auth_credential)
    {
        // NOTE : This is an abstracted handshake. For production: 
        // 1) Create ephemeral ECDH key pair.. 
        // 2) Sign ephemeral public with local certificate/private key.. 
        // 3) Send to remote, receive remote ephemeral pub + signature.. 
        // 4) Verify remote signature, compute shared secret, derive session key...
        // 5) return session id.. 

        // Here : we simulate by verifying auth_credential (PSK) matches.. 
        if (auth_credential.empty()) return nullopt; 

        // Create session id from local + remote + timestamp.. 
        string sid = local_id + "-" + remote_id + "-" + to_string(chrono :: system_clock :: now().time_since_epoch().count());
        // IN real world, handshake must delegate to EncryptionLayer to 
        return sid;  
    } 

    optional<string> HandshakeManager :: respond(const string &resquest_payload
    , const string &auth_credential){
        // decode payload, verify signature/Credential, create session,, 
        if (auth_credential.empty()) return nullopt; 

        // accept and mirror session id generation (in production)
        string sid = "resp-" + to_string(chrono :: system_clock :: now().time_since_epoch().count()); 
    }
} // namespace protocol.. 
