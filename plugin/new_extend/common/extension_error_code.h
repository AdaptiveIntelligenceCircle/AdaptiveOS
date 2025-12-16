#pragma once 

#include <iostream>

namespace adaptive :: plugin :: common
{
    enum class ErrorCode
    {
        OK = 0, 

        INVALID_ARGUEMENT, 
        INVALID_STATE, 
        PERMISSION_DENIED, 

        COMPABILITY_ERROR, 
        SIGNATURE_ERROR, 
        SANDBOX_ERROR, 

        INTERNAL_ERROR
    }; 
}