#include "compability_checker.h"

using namespace std; 

namespace adaptive :: plugin :: compability
{
    common::result<bool> CompabilityChecker::check(
    const CompabilityProfile& profile
) const {
    // Skeleton:
    // - compare OS version
    // - compare protocol version
    // - compare ABI flags

    if (!profile.required_os.compatible_with(profile.required_os)) {
        return { common::ErrorCode::COMPABILITY_ERROR, false };
    }

    if (!profile.required__protocol.compatible_with(profile.required__protocol)) {
        return { common::ErrorCode::COMPABILITY_ERROR, false };
    }

    return { common::ErrorCode::OK, true };
}

}