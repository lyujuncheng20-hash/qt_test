cmake_minimum_required(VERSION 3.16)

project(test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# 1. 查找 Qt6 组件
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

# 【核心修复】告诉 QML 工具链去哪里寻找你的本地模块
# 这样 QML 预编译器在解析 Main.qml 中的 "import counter.module 1.0" 时才不会报错
list(APPEND QMAKE_PROGRAM_ARGS "-importPath" "${CMAKE_CURRENT_BINARY_DIR}/modules/counter")
set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/modules" CACHE STRING "QML Import Paths" FORCE)

# 2. 引入子文件夹
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
    # 注意：如果上面设置了 QML_IMPORT_PATH，有时可以先去掉 DEPENDS
    # 让其通过下方的 target_link_libraries 强行进行 C++ 链式装载
)

# 5. 链接库
target_link_libraries(untitled
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    counter_module   # 确保 C++ 目标被正确引入
    logger_module
)
