cmake_minimum_required(VERSION 3.16)

# 【核心修复】显式指定该 QML 模块为 STATIC 静态库
qt_add_qml_module(countermodule
    STATIC
    URI counter.module
    VERSION 1.0
    SOURCES
        Counter.cpp
        Counter.h
)

# 确保头文件包含路径正确
target_include_directories(countermodule PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(countermodule PRIVATE
    Qt6::Core
    Qt6::Qml
)
