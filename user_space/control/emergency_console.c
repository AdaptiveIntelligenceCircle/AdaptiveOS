#include <stdio.h>
#include "emergency_console.h"

int emergency_shutdown(
    const authority_token_t* token,
    const char* reason
) {
    if (!token || token->scope != HITL_SCOPE_EMERGENCY)
        return -1;

    printf("[EMERGENCY]\n");
    printf("  SYSTEM SHUTDOWN INITIATED\n");
    printf("  token : %s\n", token->token_id);
    printf("  reason: %s\n", reason);

    /* Governance decides final action */
    return 0;
}
