# Plugin v2 – Migration Strategy

> **Objective:** introduce Plugin System v2 without breaking the existing ecosystem of Adaptive OS / Adaptive Intelligence Circle (AIC).

---

## 1. Migration Philosophy

Migration to Plugin v2 follows three non-negotiable principles:

1. **No forced rewrite** – existing plugins must continue to work
2. **No authority regression** – new system must never weaken security
3. **No big-bang transition** – migration is incremental and observable

> Plugin v2 is an *overlay*, not a replacement.

---

## 2. Coexistence Model

```
plugin/
├── src/                # Plugin v1 (unchanged)
├── extend/             # Legacy extensions (unchanged)
└── new_extend/         # Plugin v2 (governed)
```

* Plugin v1 and legacy `extend/` continue to operate
* Plugin v2 runs **in parallel**, under stricter rules
* No automatic promotion from v1 → v2

---

## 3. Migration Levels

### Level 0 – Legacy Mode (Default)

* Existing plugins run unchanged
* Observed by DIP / IBCS if available
* No governance enforcement

---

### Level 1 – Observed Mode

Legacy plugins are:

* Wrapped by lifecycle observers
* Logged for behavior patterns
* Measured by trust engine (read-only)

> No intervention, only data collection.

---

### Level 2 – Governed Execution

Selected plugins:

* Are reloaded through `new_extend`
* Gain sandbox + snapshot
* Are subject to governance decisions

Legacy code remains untouched.

---

### Level 3 – Native Plugin v2

* Plugin explicitly targets v2 interfaces
* Provides manifest + compatibility profile
* Fully governed, reversible, introspectable

---

## 4. Migration Flow (Legacy → v2)

```
Legacy Plugin
     ↓ (observe)
Trust & Rules
     ↓ (no action)
Governance Recommendation
     ↓ (manual / policy)
Lifecycle Adapter
     ↓
Plugin v2 Execution
```

Migration is **opt-in**, not automatic.

---

## 5. Backward Compatibility Rules

* ABI compatibility is required per major version
* Incompatible plugins are rejected, not punished
* Compatibility failure does NOT affect trust score

---

## 6. Risk Containment

During migration:

* All Plugin v2 executions require rollback
* Legacy plugins are never force-sandboxed
* Remote plugins are **never auto-migrated**

---

## 7. Governance During Migration

Governance responsibilities:

* Approve candidate plugins for migration
* Enforce stricter rules only in v2
* Maintain invariant consistency

Governance **never retroactively controls legacy plugins**.

---

## 8. Human-in-the-Loop Requirement

Migration decisions require:

* Explicit human approval
* Clear audit trail
* Reversible execution

> Automation assists migration.
> Humans authorize it.

---

## 9. Success Criteria

Migration is considered successful when:

* Plugin v1 continues operating safely
* Plugin v2 absorbs new development
* Governance becomes the default authority

---

## 10. Failure Handling

If migration fails:

* Rollback to legacy execution
* Preserve logs and metrics
* No plugin is permanently blocked

Failure is treated as **learning**, not error.

---

*End of document.*
