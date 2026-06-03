cmake_minimum_required(VERSION 3.16)

project(qt_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# ==============================================================================
# 配置开发环境与输出重定向
# ==============================================================================
# 开启编译命令导出，方便 QML 语言服务器 (qmlls) 自动识别模块，无需 .qmlls.ini
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 将所有可执行程序和 QML 模块插件统一输出到 bin 目录
set(UA_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR})
set(QT_QML_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR} CACHE PATH "QML output directory" FORCE)

# ==============================================================================
# 查找 Qt6 组件与基础设置
# ==============================================================================
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

# 规范化项目的全局 QML 构建拓扑结构
qt_standard_project_setup(REQUIRES 6.5)

# ==============================================================================
# 引入子模块
# ==============================================================================
add_subdirectory(qml)         # 界面 UI 模块
add_subdirectory(modules/counter) # 计数器 C++ 业务模块
add_subdirectory(modules/logger)  # 日志 C++ 业务模块

# ==============================================================================
# 定义主程序目标
# ==============================================================================
add_executable(app_target src/main.cpp)

# 配置头文件搜索路径
target_include_directories(app_target PRIVATE modules/counter)
target_include_directories(app_target PRIVATE modules/logger)

# 配置主程序的 QML 属性，声明其依赖的 QML 模块 URI
qt_add_qml_module(app_target
    URI app_target
    VERSION 1.0
    DEPENDENCIES
        app_ui
        counter.module
        logger.module
)

# 链接业务动态库及 Qt 核心库
target_link_libraries(app_target
    PRIVATE
    Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2
    countermodule
    loggermodule
    ui_module
)
