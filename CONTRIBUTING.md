# Contributing to Adaptive OS

Adaptive OS is an open-source project aimed at building an adaptive operating system capable of self-adjustment, protection, and learning.

## 🧭 Goals
All contributions must adhere to 3 principles:
1. **Stability First** – All changes must ensure the system remains stable in both simulated and real environments.

2. **Transparency and Modularity** – Code should be easy to read, easy to test, and allow for independent module replacement.

3. **Ethical Adaptivity** – Do not include code that risks privacy violations, fraud, or illegal interference with other system behavior.

---

## 🧑‍💻 How to Contribute
1. **Fork** the repository and create a new branch (`feature/<feature_name>` or `fix/<issue_code>`).

2. Write code according to standards:

- C++23, Rust, or Lua are accepted.

- All modules in the `/modules/` directory must conform to the interface in `/core/`.

3. Run all tests before opening a pull request:

```bash

./scripts/run_tests.sh
