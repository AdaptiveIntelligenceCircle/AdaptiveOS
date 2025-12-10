# AdaptiveOS Microkernel Architecture

## Tổng quan
AdaptiveOS sử dụng kiến trúc microkernel thế hệ mới kết hợp hybrid modular design, cho phép:
- Load/unload module tại runtime (hot-plug)
- Tích hợp sâu Adaptive AI Engine vào mọi quyết định hệ thống
- Độc lập hoàn toàn với hardware (hiện tại hỗ trợ x86_64, RISC-V đang phát triển)

## Các thành phần cốt lõi của Microkernel

```
microkernel/
├── src/
│   ├── main.c              # Boot entry + kernel init
│   ├── scheduler.c         # Cooperative + preemptive hybrid scheduler
│   ├── ipc.c               # Message passing (ZeroMQ-inspired)
│   ├── module_loader.c     # dlopen()/dlsym() wrapper + signature verification
│   ├── memory_manager.c    # Slab allocator + AI-aware page policy
│   └── ai_bridge.c         # Gọi trực tiếp vào adaptive_ai.so hooks
├── include/
└── boot/

```

## Cơ chế load module động
```c
void* handle = dlopen("/modules/adaptive_ai.so", RTLD_NOW | RTLD_GLOBAL);
void (*module_init)() = dlsym(handle, "module_init");
module_init();  // Adaptive AI tự đăng ký các hook
```
