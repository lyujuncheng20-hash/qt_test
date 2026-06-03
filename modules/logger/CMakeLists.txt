cmake_minimum_required(VERSION 3.16)

# 定义日志模块并配置为 SHARED 动态库形态
qt_add_qml_module(loggermodule
    SHARED
    URI logger.module
    VERSION 1.0
    SOURCES
        Logger.cpp
        Logger.h
    OUTPUT_TARGETS logger_targets
)

# 将当前源码目录设为 PUBLIC，允许主程序直接 #include "Logger.h"
target_include_directories(loggermodule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(loggermodule PRIVATE
    Qt6::Core
    Qt6::Qml
)
