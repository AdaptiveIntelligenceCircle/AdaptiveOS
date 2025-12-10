#pragma once 
#include <vector> 

#include <string> 
#include <cstdint>

#include <optional> 
#include <mutex> 

#include <chrono> 
using namespace std; 

#include <map> 
#include <unordered_map>

// Encryption Layer .. 
// - AHEAD encrypt/decrypt with associated data.. 
// - SessionKey management : create session ,  rotate, revoke.. 
// - Nonce policy + replay window (simple sliding..)

// production : compile with OpenSSL_ENABLED to use AES-GCM/HMAC
// Fallback : developer - only XOR/HMAC stub (not secure).. 

namespace protocol :: core
{
    struct Session
    {
        string id; 
        vector<uint8_t> key; 
        chrono :: system_clock :: time_point created; 
        uint64_t nonce_counter = 0; 
        bool valid = true; 
    }; 

    class EncryptionLayer
    {
        public: 
        EncryptionLayer(); 
        ~EncryptionLayer(); 

        // Create ephemeral session(returns session id).. 
        string create_session(const string &session_id_hint = ""); 

        // rotate a session key.. 
        bool rotate_session(const string &session_id); 

        // Revole session.. 
        bool revoke_session(const string &session_id); 

        // Ahead encrypt: returns cipher text || tag, using session.. 
        optional<vector<uint8_t>> encrypt(const string &session_id, 
        const vector<uint8_t> &plaintext, const vector<uint8_t> &aad);

        // A head decrypt:returns plaintext if verifies and not relayed.. 
        optional<vector<uint8_t>> decrypt(const string &session_id,
        const vector<uint8_t> &ciphertext, const vector<uint8_t> &aad ); 

        // Check session exists.. 
        bool has_session(const string &session_id) const ;
        
        private: 
        mutable mutex mtx; 
        unordered_map<string, Session> sessions; 

        // replay protection : per - session last seen nonce window (simple).. 
        vector<uint8_t> generate_key_bytes(size_t n); 
        uint64_t next_nonce(Session &s); 

        // Real crypto impl (ifdef).. 
        bool use_control = false; 
    }; 
}