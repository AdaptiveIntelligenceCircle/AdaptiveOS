#ifndef GOVERNANCE_BRIDGE_H
#define GOVERNANCE_BRIDGE_H

#include "../hitl/hitl_types.h"
#include "../include/authority_tokens.h"

int governance_submit_decision(
    const hitl_decision_record_t* decision,
    const authority_token_t* token
);

#endif
