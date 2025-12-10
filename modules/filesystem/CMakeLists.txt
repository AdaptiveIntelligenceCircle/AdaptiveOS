cmake_minimum_required(VERSION 3.14)
project(Filesystem_Module LANGUAGES C)

add_library(filesystem SHARED
    src/vfs.c
    src/ai_semantics.c
)

target_include_directories(filesystem PUBLIC include ../common/include)
target_link_libraries(filesystem PRIVATE common)
set_target_properties(filesystem PROPERTIES PREFIX "" SUFFIX ".so")