#include "rollback_manager.h"
#include "snapshot_store.h"

namespace adaptive::plugin::rollback {

bool RollbackManager::prepare_snapshot(const std::string& ext_id) {
    Snapshot snap;
    snap.ext_id = ext_id;
    snap.snapshot_id = "snap_" + ext_id;
    snap.state_hash = "STATE_HASH_PLACEHOLDER";

    SnapshotStore::instance().save_snapshot(snap);
    return true;
}

bool RollbackManager::rollback(const std::string& ext_id) {
    if (!SnapshotStore::instance().has_snapshot(ext_id)) {
        return false;
    }

    Snapshot snap = SnapshotStore::instance().get_snapshot(ext_id);
    return restore_state(snap.snapshot_id);
}

bool RollbackManager::restore_state(const std::string& snapshot_id) {
    // Skeleton:
    // - restore memory
    // - restore config
    // - reset execution context
    (void)snapshot_id;
    return true;
}

}
