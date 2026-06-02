cmake_minimum_required(VERSION 3.16)

# 将 base 文件夹里的组件打包为静态 QML 模块
qt_add_qml_module(basemodule
    STATIC
    URI base.components
    VERSION 1.0
    QML_FILES
        BaseButton.qml
)
