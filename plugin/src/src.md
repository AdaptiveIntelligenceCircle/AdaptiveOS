# src – Legacy Plugin Layer

> **Purpose:** document the role of the `src/` folder as the **legacy plugin layer** within Adaptive OS.

---

## 1. Role of `src/`

The `src/` directory contains:

* Original plugin implementations
* Early extension logic
* Non-governed execution paths

This layer is preserved to:

* Maintain backward compatibility
* Avoid forced rewrites
* Support gradual migration

> `src/` is legacy by design, not by accident.

---

## 2. Execution Model

Plugins in `src/`:

* Execute without Plugin v2 governance
* May not have sandbox or rollback
* Rely on legacy safety assumptions

As a result, they are:

* Restricted in scope
* Monitored externally when possible

---

## 3. Relationship to Plugin v2

`src/` plugins:

* Are not managed by `new_extend`
* Do not participate in lifecycle states
* Cannot access governance APIs

However, they may be:

* Observed by DIP
* Introspected by IBCS
* Wrapped by adapters for migration

---

## 4. Migration Path

Legacy plugins may transition through:

1. Observation mode
2. Governed execution via adapters
3. Native Plugin v2 rewrite

Migration is:

* Optional
* Explicit
* Human-approved

---

## 5. Safety Constraints

Legacy plugins:

* Must not access protocol core
* Must not override system invariants
* Must not bypass kernel protections

Violations result in isolation or deprecation.

---

## 6. Deprecation Policy

Over time:

* New development targets Plugin v2
* `src/` becomes maintenance-only
* High-risk legacy plugins are retired

Deprecation is planned, not abrupt.

---

## 7. Design Invariants

* `src/` remains isolated from governance
* Legacy behavior does not gain authority
* Compatibility does not imply endorsement

---

*End of document.*

