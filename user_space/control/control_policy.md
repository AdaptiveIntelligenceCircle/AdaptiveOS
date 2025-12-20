# Control Policy

> **Scope:** This document defines how the `control/` layer operates, escalates, and interacts with governance in Adaptive OS / AIForDriver.
>
> `control/` is not an execution authority. It is an **intervention policy layer**.

---

## 1. Purpose of Control Policy

The control policy exists to:

* Define *when* human intervention is allowed
* Define *how* intervention is routed
* Prevent uncontrolled or emotional overrides
* Preserve system invariants during crisis situations

The control layer translates **human intent** into **governable intervention requests**.

---

## 2. Design Principles

### 2.1 Separation of Powers

* **HITL**: decision authority
* **Control**: intervention execution request
* **Governance**: final arbiter
* **Kernel / Runtime**: enforcement only

No layer may collapse these roles.

---

### 2.2 Least Authority

Control actions:

* Require valid `authority_token`
* Are scoped and time-limited
* Cannot self-upgrade privileges

Emergency power is explicit, not implicit.

---

### 2.3 Non-Bypass Rule

Control actions:

* Must pass through governance
* Must be auditable
* Must be reversible when possible

Direct kernel manipulation is forbidden.

---

## 3. Control Context Model

Every control action operates within a **control context**.

### Context Types

* `CONTROL_CTX_ANOMALY`
* `CONTROL_CTX_SECURITY`
* `CONTROL_CTX_SYSTEM_HEALTH`
* `CONTROL_CTX_EXTERNAL`

The context defines:

* Risk level
* Escalation path
* Required scope

---

## 4. Intervention Types

### 4.1 Override

**Purpose:** Pause, isolate, or temporarily block components.

Characteristics:

* Reversible
* Limited scope
* Requires APPROVE or OVERRIDE authority

Used for:

* Suspected false positives
* Runtime instability

---

### 4.2 Safe Mode

**Purpose:** Reduce system capability to minimum safe operation.

Characteristics:

* System-wide impact
* Preserves core monitoring
* Blocks extensions and remote execution

Used for:

* System-wide uncertainty
* Cascading failures

---

### 4.3 Emergency

**Purpose:** Immediate containment or shutdown.

Characteristics:

* Irreversible without reboot or recovery
* Highest audit requirement
* Requires EMERGENCY authority

Used for:

* Active compromise
* Physical or human safety risk

---

## 5. Escalation Policy

Escalation occurs when:

* Authority token is insufficient
* Context severity exceeds scope
* Timeouts occur

Escalation paths:

* Control → HITL
* Control → Governance Review

Control may *request* escalation but never *grant* authority.

---

## 6. Audit & Accountability

Every control action must generate:

* Context snapshot
* Token reference
* Human identity (abstracted)
* Timestamp
* Outcome

Audit records are:

* Append-only
* Tamper-resistant
* Required for post-incident review

---

## 7. Failure Modes

### 7.1 Control Failure

If control fails:

* System continues under governance rules
* No automatic fallback to override

### 7.2 Human Error

If human input is invalid:

* Action is rejected
* Escalation is suggested
* Incident is logged

---

## 8. Prohibited Actions

Control layer MUST NOT:

* Modify kernel state directly
* Execute plugin logic
* Bypass consent checks
* Alter trust scores

---

## 9. Alignment with Adaptive Intelligence Circle

This control policy:

* Preserves long-term autonomy
* Prevents authoritarian override models
* Aligns with human-centered governance

Human authority is preserved without destabilizing the system.

---

*End of document.*
