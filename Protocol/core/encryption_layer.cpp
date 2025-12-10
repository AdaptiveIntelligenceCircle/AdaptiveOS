#include "encryption_layer.h"
using namespace std; 

#include <random>
#include <sstream>

#include <iomanip>
#include <cstring> 

#include <openssl/evp.h>
#include <openssl/rand.h>

#include <openssl/err.h>
using namespace std; 

namespace protocol :: core
{
    EncryptionLayer :: EncryptionLayer()
    {
        #ifdef OPENSSL_ENABLED
        use_openssl = true; 
        OpenSSL_add_all_algorithms(); 
        ERR_load_crypto_strings(); 
        #else 
        //use_openssl = false; 
        #endif 
    }

    EncryptionLayer::~EncryptionLayer() 
    {
        #ifdef OPENSSL_ENABLED
        EVP_cleanup();
        ERR_free_strings();
        #endif
    }

    // generate random key .. 
    vector<uint8_t> EncryptionLayer :: generate_key_bytes(size_t n)
    {
        vector<uint8_t> out(n); 
        #ifdef OPENSSL_ENABLED
    RAND_bytes(out.data(), static_cast<int>(n));
    #else
    // dev fallback
    random_device rd;
    for (size_t i=0;i<n;++i) out[i] = static_cast<uint8_t>(rd() & 0xFF);
    #endif

    return out; 
    }

    string EncryptionLayer :: create_session(const string &session_id_hint)
    {
        lock_guard<mutex> lock(mtx); 
        string sid = session_id_hint.empty() ? to_string(chrono :: system_clock :: now().time_since_epoch().count()) : session_id_hint; 
        Session s; 
        s.id = sid; 
        s.key = generate_key_bytes(32); // 256 bytes symmetric... 
        s.created = chrono :: system_clock :: now(); 
        s.nonce_counter = 0; 
        s.valid = true; 
        sessions[sid] = s; 
        // last_nonces[sid] = 0; 
        return sid; 
    }

    bool EncryptionLayer :: rotate_session(const string &session_id)
    {
        lock_guard<mutex> lock(mtx); 
        auto it = sessions.find(session_id); 
        if (it == sessions.end()) return false;
        it -> second.key = generate_key_bytes(32); 
        it -> second.nonce_counter = 0; 
        it -> second.created = chrono :: system_clock :: now(); 
        return true; 
    }

    bool EncryptionLayer :: revoke_session(const string &session_id)
    {
        lock_guard<mutex> lk(mtx); 
        auto it = sessions.find(session_id); 
        if (it == sessions.end()) return false; 
        it -> second.valid = false; 
        return true; 
    }

    bool EncryptionLayer :: has_session(const string &session_id) const 
    {
        lock_guard<mutex> lock(mtx); 
        auto it = sessions.find(session_id); 
        return it != sessions.end() and it -> second.valid; 
    }

    uint64_t EncryptionLayer :: next_nonce(Session &s)
    {
        return ++s.nonce_counter; 
    }

    // NOTE : simplified, uses AES-GCM if openssl enabled, otherwise XOR + HMAC stub (dev only).. 
    optional<vector<uint8_t>> EncryptionLayer :: encrypt(const string &session_id, 
    const vector<uint8_t> &plaintext, const vector<uint8_t> &aad)
    {
        lock_guard<mutex> lock(mtx); 
        auto it = sessions.find(session_id); 
        if (it == sessions.end() or !it -> second.valid) return nullopt; 
        Session &s = it -> second; 
        uint64_t nonce = next_nonce(s); 

        #ifdef OPENSSL_ENABLED
        // AES 256  - GCM : nonce 12 bytes (96 bytes).. 
        uint8_t iv[12] = {0}; 
        memcpy(iv + 4 , &nonce, sizeof(uint64_t)); 
        // simple meaning : last 8 bytes = nonce..
        
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new(); 
        vector<uint8_t> out(plaintext.size() + 16);
        int len = 0, outlen = 0;  

        if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL)) { EVP_CIPHER_CTX_free(ctx); return nullopt; }
        if (!EVP_EncryptInit_ex(ctx, NULL, NULL, s.key.data(), iv)) { EVP_CIPHER_CTX_free(ctx); return nullopt; }

        if (!aad.empty()){
            if (!EVP_EncryptUpdate(ctx, out.data(), &len, aad.data(), static_cast<int>(aad.size()))){
                EVP_CIPHER_CTX_free(ctx); 
                return nullopt;
            }
        }

        if (!EVP_EncryptUpdate(ctx, out.data(), &len, plaintext.data(), static_cast<int>(plaintext.size()))) 
        { 
            EVP_CIPHER_CTX_free(ctx); return nullopt; 
        }
        outlen = len;
        if (!EVP_EncryptFinal_ex(ctx, out.data()+outlen, &len)) 
        { 
            EVP_CIPHER_CTX_free(ctx); 
            return std::nullopt; 
        }
        outlen += len;
        uint8_t tag[16];
    if (!EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, 16, tag)) 
    { 
        EVP_CIPHER_CTX_free(ctx); 
        return nullopt; 
    }
    EVP_CIPHER_CTX_free(ctx);

    // output : 
    vector<uint8_t> packet; 
    packet.reserve(8 + outlen + 16); 
    for (int i = 0 ; i < 8 ; i++) {
        packet.push_back((uint8_t)((nonce >> (56 - i*8)) & 0xFF))); 
    }
    packet.insert(packet.end(), out.begin(), out.begin() + outlen); 
    packet.insert(packet.end(), tag, tag + 10); 
    return packet; 

    #else 
    // DEV fallback : XOR key stream + append simple 
    vector<uint8_t> packet; 
    packet.reserve(8 + plaintext.size() + 4);

    // write nonce 
    for (int i = 0 ; i < 8 ; i++) {
        packet.push_back((uint8_t)((nonce >> (56 - i*8)) & 0xFF));
    }
    // XOr 
    for (size_t i=0;i<plaintext.size();++i) 
    {
        uint8_t k = s.key[i % s.key.size()];
        packet.push_back(plaintext[i] ^ k);
    }
    // simple checksum (XOR of bytes)
    uint8_t chk = 0;
    for (size_t i=0;i<packet.size();++i) 
    chk ^= packet[i];
    // append 4 bytes chk (same repeated)
    for (int j=0;j<4;j++) 
    packet.push_back(chk);
    return packet;
        #endif 
    }
    optional<vector<uint8_t>> EncryptionLayer::decrypt(const string& session_id,
    const vector<uint8_t>& ciphertext, const vector<uint8_t>& aad) 
    {

    lock_guard<mutex> lock(mtx);
    auto it = sessions.find(session_id);
    if (it==sessions.end() || !it->second.valid) 
    return nullopt;
    Session& s = it->second;

#ifdef OPENSSL_ENABLED
    if (ciphertext.size() < 8 + 16) 
    return nullopt;
    // read nonce
    uint64_t nonce = 0;
    for (int i=0;i<8;i++)
    { 
        nonce = (nonce<<8) | ciphertext[i]; 
    }
    // check replay
    auto last = last_nonces.find(session_id);
    if (last != last_nonces.end() && nonce <= last->second) 
    return nullopt;
    // extract ciphertext body and tag
    size_t cstart = 8;
    size_t tagpos = ciphertext.size() - 16;
    vector<uint8_t> ciph(ciphertext.begin()+cstart, ciphertext.begin()+tagpos);
    uint8_t tag[16];
    memcpy(tag, ciphertext.data()+tagpos, 16);

    uint8_t iv[12] = {0};
    memcpy(iv+4, &nonce, sizeof(uint64_t));
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL)) 
    { 
        EVP_CIPHER_CTX_free(ctx); 
        return nullopt; 
    }
    if (!EVP_DecryptInit_ex(ctx, NULL, NULL, s.key.data(), iv)) 
    { 
        EVP_CIPHER_CTX_free(ctx); 
        return nullopt; 
    }

    if (!aad.empty()) 
    { 
        int len; 
        if (!EVP_DecryptUpdate(ctx, NULL, &len, aad.data(), static_cast<int>(aad.size()))) 
        { 
            EVP_CIPHER_CTX_free(ctx); 
            return nullopt; 
        } 
    }

    vector<uint8_t> plain(ciph.size());
    int outlen=0, len=0;
    if (!EVP_DecryptUpdate(ctx, plain.data(), &len, ciph.data(), static_cast<int>(ciph.size()))) 
    { 
        EVP_CIPHER_CTX_free(ctx); return nullopt; 
    }

    outlen = len;
    if (!EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, 16, tag)) 
    { 
        EVP_CIPHER_CTX_free(ctx); return nullopt; 
    }

    if (EVP_DecryptFinal_ex(ctx, plain.data()+outlen, &len) <= 0) 
    { 
        EVP_CIPHER_CTX_free(ctx); return nullopt; 
    }

    outlen += len;
    EVP_CIPHER_CTX_free(ctx);
    plain.resize(outlen);
    last_nonces[session_id] = nonce;
    return plain;

#else
    // DEV fallback: validate checksum, xor back, check nonce monotonic
    if (ciphertext.size() < 8 + 4) 
    return nullopt;
    uint64_t nonce = 0;

    for (int i=0;i<8;i++)
    { 
        nonce = (nonce<<8) | ciphertext[i]; 
    }

    #ifdef OPENSSL_ENABLED

    auto last = last_nonces.find(session_id);
    if (last != last_nonces.end() && nonce <= last->second) 
    return nullopt;

    uint8_t chk = 0;
    for (size_t i=0;i<ciphertext.size()-4;++i) 
    chk ^= ciphertext[i];

    // verify appended chk
    uint8_t ex_chk = ciphertext[ciphertext.size()-1];
    if (chk != ex_chk) 
    return nullopt;

    // xor back
    size_t plen = ciphertext.size() - 8 - 4;
    vector<uint8_t> plain;
    plain.reserve(plen);

    for (size_t i=0;i<plen;++i) 
    {
        uint8_t enc = ciphertext[8+i];
        uint8_t k = s.key[i % s.key.size()];
        plain.push_back(enc ^ k);
    }

    last_nonces[session_id] = nonce;
    return plain;
    #endif

    #endif 
    }
}