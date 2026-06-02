cmake_minimum_required(VERSION 3.16)

project(qt_test VERSION 1.0 LANGUAGES CXX)

# 【核心新增】强行开启 QML 语言服务器的路径生成，专治 IDE 报 Failed to import
set(QT_QML_GENERATE_QMLLS_INI ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# 1. 查找 Qt6 组件
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

set(QML_IMPORT_PATH ${CMAKE_BINARY_DIR}/qml CACHE STRING "QML Import Paths" FORCE)

# 规范化项目的全局 QML 输出路径
qt_standard_project_setup(REQUIRES 6.5)

# 2. 引入子文件夹（必须在定义主程序 app_target 之前）
add_subdirectory(modules/counter)
add_subdirectory(modules/logger)
add_subdirectory(qml/base)

# 3. 定义主程序可执行文件
add_executable(app_target
    main.cpp
)

# 4. 配置主程序的 QML 模块
qt_add_qml_module(app_target
    URI app_target
    VERSION 1.0
    QML_FILES
        qml/Main.qml
)

# 5. 链接库
target_link_libraries(app_target
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    logger_module

    # 【核心修正】同时链接 C++ 目标和其关联的插件目标
    countermodule
    countermoduleplugin

    basemodule
    basemoduleplugin
)

# 6. 【核心修正】让 Qt 自动处理可执行文件的静态 QML 插件导入
qt_import_qml_plugins(app_target)
