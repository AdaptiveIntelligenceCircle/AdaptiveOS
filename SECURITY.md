# Security Policy

Adaptive OS có cơ chế tự phòng thủ, tuy nhiên chúng tôi vẫn chào đón báo cáo lỗi bảo mật.

## 📬 Báo cáo lỗi bảo mật
- Gửi email: `<security_contact_email>`
- Không công khai chi tiết lỗi cho đến khi được vá.

## ⚙️ Quy trình xử lý
1. Tiếp nhận và xác nhận trong 72 giờ.
2. Vá lỗi trong vòng 14 ngày.
3. Công bố và ghi nhận đóng góp.

## 🔐 Phạm vi
Bao gồm tất cả mã trong:
``` plaintext
/adaptive/
│
├── /core/              # Kernel-level AI plugins
├── /context/           # Dữ liệu ngữ cảnh
├── /human_feedback/    # Feedback và mô phỏng human-in-loop
├── /trust_profiles/    # Hồ sơ độ tin cậy của agent/human
├── /ai_plugins/        # Các plugin AI độc lập
├── /recovery/          # Module tự phục hồi
├── /sandbox/           # Khu vực thử nghiệm (low-trust)
└── /apps/              # Ứng dụng người dùng chạy trên Adaptive OS
```
