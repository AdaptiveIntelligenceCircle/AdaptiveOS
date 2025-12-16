#pragma once 

namespace adaptive :: plugin :: common
{
    struct Version
    {
        int major; 
        int minor; 
        int patch; 

        bool compatible_with(const Version &other) const
        {
            return major == other.major; 
        }
    }; 
}