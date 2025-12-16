#pragma once 

#include "extension_error_code.h"
using namespace std; 

namespace adaptive :: plugin :: common
{
    template<typename T> 
    struct result
    {
        ErrorCode code; 
        T value;
        
        book ok() const{
            return code == ErrorCode :: OK; 
        }
    }; 
}