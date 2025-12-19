#ifndef PERMISSION_SCOPE_H
#define PERMISSION_SCOPE_H 

typedef enum
{
    PERMISSION_NONE, 
    PERMISSION_READ, 
    PERMISSION_EXECUTE, 
    PERMISSION_EXTEND, 
    PERMISSION_REMOTE
} permission_scope_t; 

int permission_scope_is_allowed
(
    permission_scope_t scope 
); 

#endif 