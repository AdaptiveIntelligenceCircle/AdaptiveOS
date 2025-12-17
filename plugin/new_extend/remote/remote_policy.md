# Remote Policy

> **Scope:** define mandatory policies governing all remote extensions and external code fetched into Adaptive OS Plugin System v2.

---

## 1. Purpose

The Remote Policy exists to:

* Protect Adaptive OS from untrusted remote inputs
* Prevent implicit trust propagation
* Enforce uniform admission criteria
* Preserve system invariants under adversarial conditions

> Remote code is always treated as hostile until proven otherwise.

---

## 2. Policy Enforcement Point

Remote policy is enforced at **multiple layers**:

1. Remote Loader (staging gate)
2. Compatibility Checker
3. Governance (final authority)

Failure at any layer results in **immediate rejection or quarantine**.

---

## 3. Allowed Remote Sources

Remote sources must satisfy **all** of the following:

* Explicitly whitelisted domain, fingerprint, or registry
* Cryptographic identity available
* Versioned artifact manifests

Implicit sources are forbidden.

---

## 4. Mandatory Verification

Every remote extension must pass:

* Signature verification
* Hash integrity validation
* Manifest schema validation
* Compatibility checks

Verification failures:

* Do not reduce trust score
* Are not treated as malicious
* Are logged for audit

---

## 5. Staging and Quarantine

Remote extensions are first **staged**, never executed directly.

Outcomes:

* **Accepted**: eligible for governance evaluation
* **Quarantined**: verification incomplete or suspicious
* **Rejected**: policy violation

Quarantined artifacts:

* Cannot be executed
* Cannot request privileges
* Require explicit review

---

## 6. Governance Admission Rules

Governance evaluates remote extensions based on:

* Compatibility profile
* Sandbox readiness
* Snapshot availability
* Initial trust score

Governance may:

* Allow execution
* Degrade capabilities
* Deny admission
* Permanently block source

---

## 7. Execution Constraints

All admitted remote extensions:

* Must run inside sandbox
* Must have rollback snapshot
* Must emit observability signals

Additional constraints may be applied dynamically.

---

## 8. Trust Policy

Remote extensions:

* Start with neutral or reduced trust
* Are subject to faster trust decay
* Never inherit trust from source

Trust does not imply permission.

---

## 9. Rollback and Isolation

On anomaly or violation:

* Execution is frozen
* Governance evaluates impact
* Rollback is preferred
* Isolation is enforced if needed

Repeated failures escalate severity.

---

## 10. Network and IO Restrictions

Default remote execution profile:

* No outbound network
* No persistent storage
* Restricted IPC

Exceptions require explicit governance approval.

---

## 11. Audit and Logging

All remote-related events must be:

* Logged immutably
* Timestamped
* Traceable to source identity

Audit logs are human-reviewable.

---

## 12. Policy Invariants

* Remote execution is never implicit
* No remote code bypasses governance
* No execution without rollback
* No source trust inheritance

---

*End of document.*
