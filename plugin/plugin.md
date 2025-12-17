# Plugin System Overview – `extend` vs `new_extend`

> **Purpose:** clearly distinguish the roles, responsibilities, and architectural differences between the legacy `extend/` system and the governed `new_extend/` system inside Adaptive OS / Adaptive Intelligence Circle (AIC).

This document prevents confusion, misuse, and accidental authority leakage.

---

## 1. Why Two Extension Systems Exist

Adaptive OS intentionally maintains **two parallel extension systems**:

* `extend/` – legacy, pragmatic, fast iteration
* `new_extend/` – governed, secure, long-term evolution

This is **not technical debt**.
It is a **strategic layering decision**.

> Evolution requires overlap. Replacement requires rupture.

---

## 2. High-Level Comparison

| Dimension           | `extend/` (Legacy)    | `new_extend/` (Plugin v2) |
| ------------------- | --------------------- | ------------------------- |
| Primary Goal        | Functionality         | Governance & Safety       |
| Trust Model         | Implicit / contextual | Zero-trust by default     |
| Authority Control   | Distributed           | Centralized (Governance)  |
| Sandbox             | Optional / partial    | Mandatory                 |
| Rollback            | Ad-hoc                | Mandatory                 |
| Lifecycle           | Informal              | Formal state machine      |
| Remote Support      | Weak / implicit       | Strict & staged           |
| Introspection       | Limited               | First-class               |
| Long-term Stability | Low                   | High                      |

---

## 3. The `extend/` System

### 3.1 Purpose

`extend/` exists to:

* Support early experimentation
* Enable rapid feature development
* Maintain compatibility with existing code

It prioritizes **developer velocity** over governance.

---

### 3.2 Characteristics

* Plugins may hold implicit authority
* Safety mechanisms are decentralized
* Rollback is not guaranteed
* Sandbox is not enforced uniformly

This is acceptable **only because `extend/` is bounded**.

---

### 3.3 Limitations

`extend/` is **not suitable** for:

* Untrusted code
* Remote extensions
* Long-running adaptive behavior
* Security-critical workflows

---

## 4. The `new_extend/` System (Plugin v2)

### 4.1 Purpose

`new_extend/` is designed to:

* Govern untrusted and adaptive extensions
* Enforce authority boundaries
* Support decades-long system evolution

It prioritizes **system sovereignty** over convenience.

---

### 4.2 Core Principles

* Zero trust
* Explicit authority
* Mandatory rollback
* Observable behavior
* Human-in-the-loop governance

---

### 4.3 Structural Overview

```
new_extend/
├── governance/
├── lifecycle/
├── remote/
├── rollback/
├── rules/
├── sandbox/
├── trust/
├── common/
└── compatibility/
```

Each module has **strictly limited authority**.

---

## 5. Authority Model Comparison

### `extend/`

* Authority is fragmented
* Plugins may influence execution directly
* Safety relies on discipline

### `new_extend/`

* Governance is the sole authority
* Plugins are always subjects
* Safety is structural, not optional

> In `new_extend`, power is designed, not assumed.

---

## 6. Execution Flow Comparison

### `extend/`

```
Plugin → Execution → Error Handling (if any)
```

### `new_extend/`

```
Plugin → Sandbox → Snapshot → Governance → Lifecycle → Execution
                                      ↓
                                  Rollback / Isolation
```

---

## 7. Migration Relationship

`extend/` and `new_extend/` are **not competitors**.

Migration strategy:

* Existing plugins remain in `extend/`
* New plugins target `new_extend/`
* Selected legacy plugins may be wrapped

Migration is:

* Gradual
* Reversible
* Human-approved

---

## 8. What Must Never Happen

* `extend/` plugins bypass governance
* `extend/` plugins gain rollback authority
* `new_extend/` rules are applied retroactively to legacy code
* The two systems silently merge

These are **architecture violations**.

---

## 9. Design Invariants

* `extend/` optimizes for speed, not sovereignty
* `new_extend/` optimizes for sovereignty, not speed
* Only `new_extend/` may host untrusted or remote code
* Governance authority is never optional

---

## 10. Long-Term Direction

Over time:

* `extend/` becomes maintenance-only
* `new_extend/` becomes the default
* Governance becomes non-negotiable

This transition is evolutionary, not revolutionary.

> **Legacy is respected.
> Sovereignty is enforced.**

---

*End of document.*

