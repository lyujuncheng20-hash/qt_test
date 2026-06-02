cmake_minimum_required(VERSION 3.16)

qt_add_qml_module(basemodule
    STATIC
    URI base.components
    VERSION 1.0
    QML_FILES
        BaseButton.qml
    OUTPUT_TARGETS base_targets
)
