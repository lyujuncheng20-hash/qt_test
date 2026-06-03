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

# ... 前面查找组件和重定向 bin 的代码保持不变 ...

# 2. 引入子文件夹
add_subdirectory(qml)         # 引入你的统一 qml 目录
add_subdirectory(modules/counter)
add_subdirectory(modules/logger)

# 3. 定义主程序可执行文件
add_executable(app_target src/main.cpp)
target_include_directories(app_target PRIVATE modules/counter)

# 4. 配置主程序的 QML 模块
qt_add_qml_module(app_target
    URI app_target
    VERSION 1.0
    # 🔴 关键核心：告诉主程序，你依赖 app_ui 模块。
    # 这样 CMake 会在编译时自动把 app_ui 的 Qmldir 和插件注册信息注入到主程序的运行环境中！
    DEPENDENCIES
        app_ui
)

# 5. 链接库
target_link_libraries(app_target
    PRIVATE
    Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2
    logger_module
    countermodule

    ui_module               # 🔴 确保链接了 ui_module
)
