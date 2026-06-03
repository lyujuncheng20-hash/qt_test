cmake_minimum_required(VERSION 3.16)

# 使用 OUTPUT_TARGETS 捕获 Qt 自动生成的插件目标
qt_add_qml_module(countermodule
    SHARED
    URI counter.module
    VERSION 1.0
    SOURCES
        Counter.cpp
        Counter.h
    OUTPUT_TARGETS counter_targets
)

# 这样主程序链接此模块后，就能直接 #include "Counter.h"
target_include_directories(countermodule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(countermodule PRIVATE
    Qt6::Core
    Qt6::Qml
)
