# Test Scenario: Anomaly → HITL → Control → Rollback

> **Purpose:** This document demonstrates an end-to-end reference scenario showing how an anomaly propagates through HITL, control intervention, and rollback approval.
>
> This is a **conceptual + executable mental model**, not a production test.

---

## 1. Scenario Overview

**Situation:**

* A runtime anomaly is detected in a driver behavior module.
* The system is uncertain whether this is a false positive or a real fault.
* Automatic rollback is *not allowed* without human authority.

**Goal:**

* Safely contain the system
* Obtain human decision
* Execute rollback through governance

---

## 2. Actors Involved

| Actor            | Role                         |
| ---------------- | ---------------------------- |
| Sensor / Runtime | Detect anomaly               |
| Governance       | Boundary enforcement         |
| HITL             | Human decision authority     |
| Control          | Intervention routing         |
| Review           | Post-incident accountability |

---

## 3. Step-by-Step Flow

### Step 1: Anomaly Detection

```text
Runtime detects abnormal driver behavior
Confidence: 0.62 (below auto-action threshold)
```

Action:

* Runtime raises `ANOMALY_EVENT`
* Governance blocks automatic rollback

---

### Step 2: Governance Requests HITL

```text
Condition:
- Authority boundary crossed
- Automated action insufficient
```

Governance action:

* Creates HITL decision request
* Specifies context: `CONTROL_CTX_ANOMALY`

---

### Step 3: HITL Session Opened

```c
hitl_open_session(HITL_SCOPE_APPROVE, &session);
```

Session properties:

* Scope: APPROVE
* TTL: 5 minutes
* Context: anomaly investigation

---

### Step 4: Human Decision (HITL)

Human evaluates:

* Logs
* Anomaly trace
* Recent system behavior

Decision:

```text
APPROVE rollback of affected module
Reason: false positive after config drift
```

```c
hitl_request_decision(
    &session,
    "Rollback requested due to anomaly",
    &decision,
    &token
);
```

Output:

* Decision record
* Authority token (scoped)

---

### Step 5: Control Intervention

Control context created:

```c
control_context_t ctx;
init_control_context(&ctx, CONTROL_CTX_ANOMALY, "runtime");
```

Intervention routed:

```c
route_intervention(
    &token,
    INTERVENTION_OVERRIDE,
    &ctx,
    "Temporarily pause module before rollback"
);
```

Effect:

* Affected module paused
* No system-wide impact

---

### Step 6: Rollback Approval

Rollback approval step:

```c
approve_rollback(
    &token,
    "driver_behavior_module",
    "Human-approved rollback"
);
```

Governance validates:

* Token scope
* Consent
* Rollback policy

Rollback executed.

---

### Step 7: Post-Incident Review

```c
review_incident(
    "INC-2025-ANOM-001",
    INCIDENT_MINOR,
    "False positive anomaly; safe rollback applied"
);
```

Optional trust adjustment:

```c
adjust_trust(
    "driver_behavior_module",
    TRUST_FREEZE,
    "Prevent aggressive adaptation temporarily"
);
```

---

## 4. Authority & Safety Guarantees

Throughout the scenario:

* No kernel state was modified directly
* No plugin bypassed governance
* No rollback occurred without human approval
* Every step was auditable

---

## 5. Failure Variants (What-If)

### If HITL times out

* Escalation triggered
* System remains paused
* No rollback occurs

### If token scope insufficient

* Control rejects intervention
* HITL re-requested with higher scope

### If rollback denied

* System resumes monitoring
* Trust score reduced

---

## 6. Why This Scenario Matters

This flow demonstrates:

* Human sovereignty without chaos
* Safe intervention without panic
* Rollback without authoritarian override

It proves the system is **governable, auditable, and humane**.

---

*End of scenario.*
