# qml/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

# 将整个 qml 目录作为一个统一的静态 QML 模块
qt_add_qml_module(ui_module
    STATIC
    URI app_ui
    VERSION 1.0
    QML_FILES
        Main.qml
        counterview/CounterView.qml
        base/BaseButton.qml
)
