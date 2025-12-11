#include "sync_manager.h"
#include <algorithm>

namespace protocol::core 
{

SyncManager::SyncManager(const string& local_node_id) : node_id(local_node_id) 
{
    merge_fn = [](const ValueEntry& local, const ValueEntry& remote)->string 
    {
        // default: last-writer-wins by comparing max counter per node
        uint64_t lmax=0, rmax=0;
        for (auto &v: local.versions) lmax = max(lmax, v.counter);
        for (auto &v: remote.versions) rmax = max(rmax, v.counter);
        return (rmax > lmax) ? remote.value : local.value;
    };
}

void SyncManager::put(const string& key, const string& value) 
{
    lock_guard<mutex> lock(mtx);
    ValueEntry entry;
    entry.value = value;
    entry.versions.push_back({node_id, local_counter++});
    store[key] = entry;
}

optional<ValueEntry> SyncManager::get(const string& key) const 
{
    lock_guard<mutex> lock(mtx);
    auto it = store.find(key);
    if (it==store.end()) return nullopt;
    return it->second;
}

void SyncManager::merge_remote(const string& key, const ValueEntry& remote) 
{
    lock_guard<mutex> lock(mtx);
    auto it = store.find(key);
    if (it==store.end()) 
    {
        store[key] = remote;
        return;
    }
    // detect if remote dominates or conflict
    bool remote_dominates = false;
    bool local_dominates = false;
    for (auto &rv: remote.versions) 
    {
        bool found = false;
        for (auto &lv: it->second.versions) if (lv.node_id == rv.node_id && lv.counter >= rv.counter) { found = true; break; }
        if (!found) remote_dominates = true;
    }
    for (auto &lv: it->second.versions) 
    {
        bool found = false;
        for (auto &rv: remote.versions) if (rv.node_id == lv.node_id && rv.counter >= lv.counter) { found = true; break; }
        if (!found) local_dominates = true;
    }
    if (remote_dominates && !local_dominates) 
    {
        it->second = remote;
        return;
    }
    if (!remote_dominates && local_dominates) 
    {
        return;
    }

    // conflict: call merge_fn
    string merged = merge_fn(it->second, remote);
    ValueEntry newentry;
    newentry.value = merged;
    // merge versions union
    newentry.versions = it->second.versions;
    for (auto &v : remote.versions) 
    {
        bool exists=false;
        for (auto &vv: newentry.versions) if (vv.node_id==v.node_id && vv.counter==v.counter) { exists=true; break; }
        if (!exists) newentry.versions.push_back(v);
    }
    
    it->second = newentry;
}

void SyncManager::set_merge_fn(MergeFn fn) 
{
    lock_guard<mutex> lock(mtx);
    merge_fn = move(fn);
}

unordered_map<string, ValueEntry> SyncManager::snapshot() const 
{
    lock_guard<mutex> lock(mtx);
    return store;
}

void SyncManager::restore_from_snapshot(const unordered_map<string, ValueEntry>& snap) 
{
    lock_guard<mutex> lock(mtx);
    store = snap;
}
} // namespace

