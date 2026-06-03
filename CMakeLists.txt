cmake_minimum_required(VERSION 3.16)

project(qt_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# すべてのビルド成果物（バイナリ/QMLプラグイン）を同一のbinディレクトリに出力
set(UA_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR})
set(QT_QML_OUTPUT_DIRECTORY ${UA_OUTPUT_DIR} CACHE PATH "QML output directory" FORCE)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)
qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(qml)
add_subdirectory(modules/counter)
add_subdirectory(modules/logger)

add_executable(app_target src/main.cpp)

target_include_directories(app_target PRIVATE modules/counter)
target_include_directories(app_target PRIVATE modules/logger)

# 各C++およびUIモジュールの依存関係を定義
qt_add_qml_module(app_target
    URI app_target
    VERSION 1.0
    DEPENDENCIES
        app_ui
)

target_link_libraries(app_target
    PRIVATE
    Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2
    countermodule
    loggermodule
    ui_module
)
