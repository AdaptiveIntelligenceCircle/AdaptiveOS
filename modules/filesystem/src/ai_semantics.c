#include "../../filesystem/vfs.h"
#include <string.h>

// Gia su kernel da map ham on file access cua adaptive 
extern void on_file_access(const char *path, const char *process); 

int vfs_read(const char *path, char *buf , size_t size)
{
    printf("reading file with AI semantics : %c", to_string(path)); 
    on_file_access(path, "current_process"); 

    int trust = vfs_trust_score(path); 
    if (trust < 30){
        printf("Low trust file accessed :" + string(size)); 
    }
    // .. thuc hien doc file that.. 
    return 0 ; 
}