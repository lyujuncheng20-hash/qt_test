cmake_minimum_required(VERSION 3.16)

project(test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# 1. 查找 Qt6 组件
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

# 2. 引入子文件夹（必须在主程序 target 之前，确保 counter_module 目标已被定义）
add_subdirectory(modules/counter)
add_subdirectory(modules/logger)

# 3. 定义主程序可执行文件
add_executable(untitled
    main.cpp
)

# 4. 配置主程序的 QML 模块
qt_add_qml_module(untitled
    URI untitled
    VERSION 1.0
    QML_FILES
        qml/Main.qml
    DEPENDS
        counter.module # 【核心修复】这里使用模块的正式 URI "counter.module" 代替 "counter_module"
)

# 5. 链接库
target_link_libraries(untitled
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    counter_module   # C++ 链接仍然使用目标名
    logger_module
)
