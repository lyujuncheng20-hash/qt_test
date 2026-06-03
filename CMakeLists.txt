cmake_minimum_required(VERSION 3.16)

project(qt_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# ==============================================================================
# 将整个项目的编译输出统一重定向到 bin 目录
# ==============================================================================
set(UA_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR})

set(QML_IMPORT_PATH ${UA_OUTPUT_DIR} CACHE STRING "QML Import Paths" FORCE)

# 1. 查找 Qt6 组件
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

# 规范化项目的全局 QML 输出路径
qt_standard_project_setup(REQUIRES 6.5)

# 2. 引入子文件夹
add_subdirectory(qml/base)
add_subdirectory(modules/counter)
add_subdirectory(modules/logger)

# 3. 定义主程序可执行文件
add_executable(app_target
    src/main.cpp
)

# 让主程序能顺利找到 counter 模块的头文件
target_include_directories(app_target PRIVATE modules/counter)

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

    countermodule          # 动态库 (SHARED)，会自动输出到 bin/

    basemodule             # 静态库 (STATIC)，直接打包进 exe
    base_components_plugin # 👈 强制链接静态插件目标，阻止被编译器剔除
)
