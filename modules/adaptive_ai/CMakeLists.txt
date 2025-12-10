cmake_minimum_required(VERSION 3.14)
project(AdaptiveAI_Module LANGUAGES CXX)

find_package(Torch REQUIRED)  # nếu dùng PyTorch C++ API (LibTorch)

add_library(adaptive_ai SHARED
    src/ai_core.cpp
    src/meta_learn.cpp
    src/hitl_interface.cpp
    src/ai_plugin.cpp
)

target_include_directories(adaptive_ai PUBLIC include ../common/include)
target_link_libraries(adaptive_ai PRIVATE common "${TORCH_LIBRARIES}")
target_compile_features(adaptive_ai PUBLIC cxx_std_17)

# Đảm bảo xuất ra .so để kernel load động
set_target_properties(adaptive_ai PROPERTIES PREFIX "" SUFFIX ".so")