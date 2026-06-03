# qml/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

# 🔴 修复：去掉 STATIC，让 CMake 真正去生成物理文件夹和 qmldir
qt_add_qml_module(ui_module
    URI app_ui
    VERSION 1.0
    QML_FILES
        Main.qml
        counterview/CounterView.qml
        base/BaseButton.qml
)
