#include "hitl_interface.h"
#include "../include/hitl_timeout_escalation.h"

/* internal symbols */
int hitl_normalize_decision(
    hitl_session_t*, hitl_decision_t,
    const char*, hitl_decision_record_t*
);
int hitl_apply_policy(
    const hitl_decision_record_t*
);
int hitl_audit_log(
    const hitl_session_t*,
    const hitl_decision_record_t*
);

int hitl_init(void) {
    return 0;
}

int hitl_request_decision(
    hitl_session_t* session,
    const char* reason,
    hitl_decision_record_t* out_decision,
    authority_token_t* out_token
) {
    if (hitl_check_timeout(session) == 1)
        return -2;

    int rc = hitl_normalize_decision(
        session,
        HITL_DECISION_APPROVE,
        reason,
        out_decision
    );
    if (rc != 0) return rc;

    rc = hitl_apply_policy(out_decision);
    if (rc != 0) return rc;

    rc = authority_token_issue(
        out_decision->scope,
        out_token
    );
    if (rc != 0) return rc;

    hitl_audit_log(session, out_decision);
    return 0;
}
