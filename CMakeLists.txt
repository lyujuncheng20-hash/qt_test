cmake_minimum_required(VERSION 3.16)

project(qt_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# 告诉 CMake 导出编译命令，这能让 QML 语言服务器在没有 .qmlls.ini 的情况下自动识别整个项目结构
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 将可执行程序的编译输出重定向到 bin 目录
set(UA_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR})
set(QT_QML_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR} CACHE PATH "QML output directory" FORCE)

# 查找 Qt6 组件
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

# 🔴 关键：规范化项目的全局 QML 输出路径，这会代替 .qmlls.ini 告诉 IDE 去哪里找生成的 qmldir
qt_standard_project_setup(REQUIRES 6.5)

# 2. 引入子文件夹
add_subdirectory(qml)
add_subdirectory(modules/counter)
add_subdirectory(modules/logger)

# 3. 定义主程序可执行文件
add_executable(app_target src/main.cpp)
target_include_directories(app_target PRIVATE modules/counter)
target_include_directories(app_target PRIVATE modules/logger)

# 4. 配置主程序的 QML 模块
qt_add_qml_module(app_target
    URI app_target
    VERSION 1.0
    DEPENDENCIES
        app_ui
        counter.module
        logger.module
)

# 5. 链接库
target_link_libraries(app_target
    PRIVATE
    Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2
    loggermodule
    countermodule
    ui_module
)
