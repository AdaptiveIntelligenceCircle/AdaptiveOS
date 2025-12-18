# Human In The Loop model Overview. 

1. **Triết lý của `user_space/` trong Adaptive OS / AIC**
2. **Thiết kế folder `user_space/` (đề xuất nâng cấp)**
3. **Nâng cấp HITL: từ “callback” → “governance role”**

---

## 1. Vai trò thật sự của `user_space/`

`user_space/` **không phải UI**, **không phải app layer**, và **cũng không phải debug tool**.

👉 `user_space/` là **Human Authority Interface**.

> Nếu kernel là “luật vật lý”,
> governance là “hiến pháp”,
> thì `user_space/` là **nơi con người thực thi chủ quyền cuối cùng**.

### Invariant quan trọng

* Kernel **không được phụ thuộc** user_space
* Plugin **không được gọi trực tiếp** user_space
* User_space **chỉ tác động thông qua governance hooks**

---

## 2. Thiết kế folder `user_space/` (đề xuất)

### Hiện tại

```
user_space/
└── src/
    ├── hitl/
    │   └── ...
    └── main.c
```

👉 Đây là **MVP hợp lý**, nhưng **chưa đủ cho hệ sinh thái lớn**.

---

### Thiết kế nâng cấp (không phá cũ)

```
user_space/
├── src/
│   ├── main.c
│   │
│   ├── hitl/                    # Human-in-the-loop (core)
│   │   ├── hitl_interface.h
│   │   ├── hitl_session.c
│   │   ├── hitl_decision.c
│   │   ├── hitl_policy_bridge.c
│   │   └── hitl_audit.c
│   │
│   ├── control/                 # Explicit human control
│   │   ├── override_manager.c
│   │   ├── emergency_console.c
│   │   └── safe_mode_trigger.c
│   │
│   ├── review/                  # Human review, not control
│   │   ├── incident_review.c
│   │   ├── rollback_approval.c
│   │   └── trust_adjustment.c
│   │
│   ├── consent/                 # Human consent layer
│   │   ├── consent_registry.c
│   │   └── permission_scope.c
│   │
│   └── adapters/                # Connect user_space ↔ governance
│       ├── governance_bridge.c
│       └── protocol_adapter.c
│
├── include/
│   ├── user_space.h
│   ├── hitl_types.h
│   └── authority_tokens.h
│
└── docs/
    ├── user_space.md
    └── hitl_model.md
```

---

## 3. HITL: Nâng cấp như thế nào là **đúng**?

### ❌ HITL kiểu sai (rất nhiều hệ thống mắc)

* AI gặp vấn đề → hỏi người
* Người trả lời → AI làm tiếp
* Con người = chatbot fallback

👉 Đây **không phải Human-in-the-Loop**, mà là **Human-as-API**.

---

### ✅ HITL đúng trong Adaptive OS

> Con người **không trả lời câu hỏi**
> Con người **ra quyết định có chủ quyền**

---

### 3.1 HITL được chia thành 3 tầng

#### 1️⃣ Decision Authority (QUYẾT ĐỊNH)

* Cho phép / từ chối plugin
* Cho phép rollback hay không
* Cho phép mở rộng quyền hay không

➡ File liên quan:

* `hitl_decision.c`
* `rollback_approval.c`

---

#### 2️⃣ Override Authority (CAN THIỆP)

* Dừng hệ thống
* Ép safe-mode
* Cô lập module

➡ File liên quan:

* `override_manager.c`
* `emergency_console.c`

---

#### 3️⃣ Review Authority (ĐÁNH GIÁ)

* Điều chỉnh trust score
* Phê duyệt migration
* Đánh giá incident

➡ File liên quan:

* `incident_review.c`
* `trust_adjustment.c`

---

### 3.2 Điều cực kỳ quan trọng: Authority Token

Con người **không gọi hàm kernel trực tiếp**.

Thay vào đó:

```
Human Action
   ↓
Authority Token
   ↓
Governance
   ↓
Kernel / Plugin
```

➡ `authority_tokens.h`

* Có scope
* Có thời hạn
* Có audit trail

---

## 4. Có cần nâng cấp HITL không?

### Câu trả lời chính xác:

> **Không cần “nhiều HITL hơn”
> mà cần “HITL đúng vai trò”**

### Khi nào HITL được kích hoạt?

* Không phải mọi anomaly
* Chỉ khi:

  * authority boundary bị chạm
  * rollback ảnh hưởng hệ thống
  * trust crossing threshold

---

## 5. Tóm tắt ngắn gọn

* `user_space/` = **Human Sovereignty Layer**
* HITL không phải UI, không phải chatbot
* Nâng cấp HITL bằng:

  * phân quyền rõ
  * authority token
  * governance bridge
* Thiết kế này:

  * không phá Adaptive OS
  * không xung đột AIC
  * mở rộng được 10–20 năm

---

