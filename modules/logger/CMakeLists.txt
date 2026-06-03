cmake_minimum_required(VERSION 3.16)

# 使用 OUTPUT_TARGETS 捕获 Qt 自动生成的插件目标
qt_add_qml_module(loggermodule
    SHARED
    URI logger.module
    VERSION 1.0
    SOURCES
        Logger.cpp
        Logger.h
    OUTPUT_TARGETS logger_targets
)

# 这样主程序链接此模块后，就能直接 #include "Logger.h"
target_include_directories(loggermodule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(loggermodule PRIVATE
    Qt6::Core
    Qt6::Qml
)
