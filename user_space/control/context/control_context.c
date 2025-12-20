#include <string.h>
#include <time.h>
#include "control_context.h"

void init_control_context(
    control_context_t *ctx, 
    control_context_type_t type, 
    const char *source 
)
{
    if (!ctx) return; 

    memset(ctx, 0, sizeof(*ctx)) ; 

    ctx -> type = type; 
    ctx -> timestamp = time(NULL); 
    if (source)
    strncpy(ctx -> source, source, sizeof(ctx-> source) - 1);
}