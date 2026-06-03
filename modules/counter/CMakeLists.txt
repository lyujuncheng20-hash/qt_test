cmake_minimum_required(VERSION 3.16)

qt_add_qml_module(countermodule
    SHARED
    URI CounterModule
    VERSION 1.0
    SOURCES
        Counter.cpp
        Counter.h
    OUTPUT_TARGETS counter_targets
)

# メインプログラムから #include "Counter.h" を可能にする設定
target_include_directories(countermodule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(countermodule PRIVATE
    Qt6::Core
    Qt6::Qml
)
