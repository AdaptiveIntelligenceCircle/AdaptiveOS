# Governance – Authority Boundaries

> This document defines **non-negotiable authority boundaries** inside the Plugin v2 system.

Breaking any boundary described here is considered a **system integrity failure**, not a bug.

---

## 1. Purpose of Authority Boundaries

Authority boundaries exist to:

* Prevent privilege escalation
* Eliminate circular control
* Preserve human oversight
* Maintain long-term system stability

> Power must be explicit, limited, and revocable.

---

## 2. Authority Hierarchy

```
Kernel / Protocol Core
        ↑
Governance (Final Authority)
        ↑
Lifecycle / Rollback / Sandbox (Executors)
        ↑
Rules / Trust (Signal Providers)
        ↑
Plugins (Subjects)
```

Authority **never flows downward**.

---

## 3. Governance Authority

Governance has exclusive authority to:

* Admit or deny plugin execution
* Degrade plugin capabilities
* Freeze execution
* Trigger rollback
* Isolate plugins
* Permanently revoke plugins

Governance decisions are:

* Final
* Non-overridable
* Logged and introspectable

---

## 4. Lifecycle Boundaries

Lifecycle may:

* Transition plugin states
* Enforce valid state machines

Lifecycle may NOT:

* Skip states
* Reverse terminal states
* Override governance verdicts
* Decide policy

Lifecycle is an **executor**, not a judge.

---

## 5. Rollback Boundaries

Rollback may:

* Restore verified safe snapshots
* Reset execution context

Rollback may NOT:

* Create snapshots arbitrarily
* Roll back without governance approval
* Select rollback targets independently

Rollback exists to protect the system, not plugins.

---

## 6. Sandbox Boundaries

Sandbox may:

* Restrict system calls
* Limit resource usage
* Isolate network and IPC

Sandbox may NOT:

* Approve execution
* Modify trust scores
* Disable governance controls

Sandbox is always subordinate to governance.

---

## 7. Rules Engine Boundaries

Rules may:

* Observe behavior
* Propose actions
* Provide explanations

Rules may NOT:

* Change lifecycle states
* Trigger rollback
* Modify capabilities

Rules generate **proposals, not commands**.

---

## 8. Trust Engine Boundaries

Trust may:

* Maintain numeric trust scores
* React to observed behavior

Trust may NOT:

* Grant permissions
* Override sandbox
* Approve execution

Trust is a **signal**, not an authority.

---

## 9. Remote Loader Boundaries

Remote loader may:

* Fetch remote artifacts
* Verify signatures
* Stage plugins for review

Remote loader may NOT:

* Execute plugins
* Assign trust
* Modify lifecycle states

Remote input is treated as hostile by default.

---

## 10. Plugin Boundaries

Plugins may:

* Execute within granted capabilities
* Emit observable signals

Plugins may NOT:

* Modify governance
* Escalate privileges
* Disable sandbox or rollback
* Access kernel or protocol core

Plugins are **subjects**, never authorities.

---

## 11. Boundary Enforcement

Authority boundaries are enforced by:

* Static architecture constraints
* Runtime checks
* Governance verification
* Audit and introspection

Boundary violations trigger:

* Immediate isolation
* Forensic logging
* Governance review

---

## 12. Human Authority

Ultimate authority remains with humans:

* Humans define governance policy
* Humans approve migration
* Humans audit critical decisions

Automation assists governance.
Humans retain control.

---

## 13. Design Invariants

* No module controls itself
* No execution without approval
* No trust without observation
* No rollback without authority
* No plugin above governance

---

*End of document.*
