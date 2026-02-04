# Security Policy

Adaptive OS has a self-defense mechanism; however, we still welcome security bug reports.

## 📬 Security Bug Report
- Email address: `<security_contact_email>`
- We will not publicly disclose bug details until they are patched.

## ⚙️ Processing Procedure
1. Receive and confirm within 72 hours.

2. Patch within 14 days.

3. Publish and acknowledge contributions.

## 🔐 Area
All the source code in:

``` plaintext
/adaptive/
│
├── /core/              # Kernel-level AI plugins
├── /context/           # Context data
├── /human_feedback/    # Feedback and simulate human-in-loop
├── /trust_profiles/    # Trust agent/human
├── /ai_plugins/        # Plugin AI 
├── /recovery/          # Self - repair module
├── /sandbox/           # Testing (low-trust)
└── /apps/              # Applications that runs in Adaptive OS

```
