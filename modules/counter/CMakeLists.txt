cmake_minimum_required(VERSION 3.16)

# 定义 QML 模块
qt_add_qml_module(counter_module
    URI counter.module
    VERSION 1.0
    SOURCES
        Counter.cpp
        Counter.h
)

# 确保头文件包含路径正确
target_include_directories(counter_module PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(counter_module PRIVATE
    Qt6::Core
    Qt6::Qml
)
