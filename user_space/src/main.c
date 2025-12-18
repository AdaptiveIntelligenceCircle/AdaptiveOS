#include <stdio.h>
#include "../hitl/hitl_interface.h"

int main() {
    hitl_session_t session;
    hitl_decision_record_t decision;
    authority_token_t token;

    hitl_init();

    if (hitl_open_session(HITL_SCOPE_APPROVE, &session) != 0) {
        printf("Failed to open HITL session\n");
        return 1;
    }

    int rc = hitl_request_decision(
        &session,
        "Rollback requested due to anomaly",
        &decision,
        &token
    );

    if (rc == 0) {
        printf("Decision OK\n");
        printf("Authority token: %s\n", token.token_id);
    } else {
        printf("Decision failed: %d\n", rc);
    }

    hitl_close_session(&session);
    return 0;
}
