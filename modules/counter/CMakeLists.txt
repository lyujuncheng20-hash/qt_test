cmake_minimum_required(VERSION 3.16)

qt_add_qml_module(counter_module
    URI counter.module
    VERSION 1.0
    SOURCES
        Counter.cpp
        Counter.h
)

# 【修复】让包含路径变成项目根目录
target_include_directories(counter_module PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(counter_module PRIVATE
    Qt6::Core
    Qt6::Qml
)
