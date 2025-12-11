#pragma once 
#include <string> 

#include <algorithm> 
#include <vector> 

#include <unordered_map>
#include <optional>

#include <iostream> 
using namespace std; 

namespace protocol :: core
{
    // Handshake manager .. 
    // Perform authenticated handshake .. 
    // returns a session_id on success. 
    // - expected to run over an already semi transport (TCP, Unix sock).. 
    // - For simplicity, we provide an abstract perform handshake.. 
    // local id, remote id, auth token or cert -> returns session_id.. 
    // TODO : integrate with real certificates (x.509) or PSK storage.. 

    class HandshakeManager
    {
        public: 
        HandshakeManager(); 
        ~HandshakeManager(); 

        // Initiator side : propose handshake and return session id on 
        optional<string> initiate(const string &local_id, 
        const string &remote_id, const string &auth_credential); 

        // Responder side : accept handshake request payload and return session_id
        optional<string> respond(const string &request_payload, 
        const string &auth_credential);

        private: 
        
        // internal helpers : build/verify tokens, anti-replay store.. 
        unordered_map<string, uint64_t> recent_nonces; 
    }; 
} // namespace protocol.. 
