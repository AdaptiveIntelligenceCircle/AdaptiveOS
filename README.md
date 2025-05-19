# AdaptiveOS

AdaptiveOS/
├── microkernel/               # Microkernel core
│   ├── src/                   # Code nguồn kernel
│   │   ├── core.c             # Quản lý tiến trình, giao tiếp
│   │   ├── ipc.c              # Inter-Process Communication (message passing)
│   │   └── scheduler.c        # Lập lịch tiến trình
│   └── Makefile               # Biên dịch kernel
├── modules/                   # Các module độc lập
│   ├── adaptive_ai/           # Module Adaptive AI
│   │   ├── src/               # Code nguồn
│   │   │   ├── ai_core.cpp    # Logic chính của Adaptive AI
│   │   │   ├── meta_learn.cpp # Meta-learning
│   │   │   └── hitl_interface.cpp # Giao diện HITL
│   │   └── Makefile
│   ├── networking/            # Module mạng
│   │   ├── src/
│   │   │   └── netfilter.c    # Phân tích gói tin
│   │   └── Makefile
│   └── filesystem/            # Module file system
│       ├── src/
│       │   └── vfs.c          # Virtual File System
│       └── Makefile
├── user_space/                # Công cụ user-space
│   ├── src/
│   │   ├── main.c             # Chương trình chính
│   │   └── hitl_ui.c          # Giao diện người dùng cho HITL
│   └── Makefile
├── plugins/                   # Plugins phân tán
│   ├── src/
│   │   ├── plugin_server.c    # Server nhận message từ các module
│   │   └── plugin_client.c    # Client gửi message
│   └── Makefile
└── docs/                      # Tài liệu
    └── README.md
