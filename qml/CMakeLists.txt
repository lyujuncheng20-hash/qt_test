# qml/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

# 物理ディレクトリとqmldirの生成を保証するため、STATICを削除
qt_add_qml_module(ui_module
    URI app_ui
    VERSION 1.0
    QML_FILES
        Main.qml
        counterview/CounterView.qml
        base/BaseButton.qml

    RESOURCES
        assets/images/info.png
)
