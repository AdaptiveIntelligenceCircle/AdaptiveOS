#include "compability_checker.h"

using namespace std; 

namespace adaptive :: plugin :: compability
{
    common::result<bool> CompatibilityChecker::check(
    const CompatibilityProfile& profile
) const {
    // Skeleton:
    // - compare OS version
    // - compare protocol version
    // - compare ABI flags

    if (!profile.required_os.compatible_with(profile.required_os)) {
        return { common::ErrorCode::COMPATIBILITY_ERROR, false };
    }

    if (!profile.required_protocol.compatible_with(profile.required_protocol)) {
        return { common::ErrorCode::COMPATIBILITY_ERROR, false };
    }

    return { common::ErrorCode::OK, true };
}

}