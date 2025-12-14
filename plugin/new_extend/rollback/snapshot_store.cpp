#include "snapshot_store.h"
#include <stdexcept>

namespace adaptive::plugin::rollback {

SnapshotStore& SnapshotStore::instance() {
    static SnapshotStore store;
    return store;
}

void SnapshotStore::save_snapshot(const Snapshot& snapshot) {
    snapshots_[snapshot.ext_id] = snapshot;
}

bool SnapshotStore::has_snapshot(const std::string& ext_id) const {
    return snapshots_.count(ext_id) > 0;
}

Snapshot SnapshotStore::get_snapshot(const std::string& ext_id) const {
    auto it = snapshots_.find(ext_id);
    if (it == snapshots_.end()) {
        throw std::runtime_error("No snapshot available");
    }
    return it->second;
}

}
