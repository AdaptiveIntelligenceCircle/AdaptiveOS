# Contributing to Adaptive OS

Adaptive OS là dự án mã nguồn mở hướng tới việc xây dựng một hệ điều hành thích nghi (Adaptive Operating System) có khả năng tự điều chỉnh, bảo vệ và học hỏi.

## 🧭 Mục tiêu
Mọi đóng góp đều cần hướng đến 3 nguyên tắc:
1. **Stability First** – Mọi thay đổi phải đảm bảo hệ thống vẫn ổn định trong môi trường mô phỏng và thực.
2. **Transparency and Modularity** – Code cần dễ đọc, dễ kiểm thử và có thể thay thế từng mô-đun độc lập.
3. **Ethical Adaptivity** – Không đưa vào mã có nguy cơ xâm phạm quyền riêng tư, gian lận, hoặc can thiệp bất hợp pháp vào hành vi hệ thống khác.

---

## 🧑‍💻 Cách đóng góp
1. **Fork** repository và tạo nhánh mới (`feature/<tên_tính_năng>` hoặc `fix/<mã_vấn_đề>`).
2. Viết code theo quy chuẩn:
   - C++23, Rust hoặc Lua được chấp nhận.
   - Tất cả các module nằm trong thư mục `/modules/` phải tuân theo interface trong `/core/`.
3. Chạy toàn bộ test trước khi mở pull request:
   ```bash
   ./scripts/run_tests.sh
``` 
