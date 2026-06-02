cmake_minimum_required(VERSION 3.16)

# 将项目名称和语言标准保留
project(untitled VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# 1. 查找 Qt6 组件
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

# 告诉 Qt 自动统一管理所有子模块的输出目录（Qt 6.5+ 的推荐做法）
qt_standard_project_setup(REQUIRES 6.5)

# 2. 引入子文件夹（必须在定义主程序目标之前）
add_subdirectory(modules/counter)
add_subdirectory(modules/logger)

# 3. 定义主程序可执行文件（【修正】将目标名改为 untitled，避免与项目通用名冲突）
add_executable(untitled
    main.cpp
)

# 4. 配置主程序的 QML 模块
qt_add_qml_module(untitled
    URI untitled             # 【修正】URI 改为 untitled
    VERSION 1.0
    QML_FILES
        qml/Main.qml         # 这会让 Main.qml 的资源路径确定为 "qrc:/qt/qml/untitled/qml/Main.qml"
)

# 5. 链接库
target_link_libraries(untitled
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    logger_module            # 你的 Logger 头文件接口库

    # 【核心正确配置】同时链接 C++ 目标和底层 QML 插件目标，绕过 MinGW 的 DEPENDS Bug
    counter_module
    counter_moduleplugin
)
