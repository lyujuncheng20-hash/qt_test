cmake_minimum_required(VERSION 3.16)

qt_add_qml_module(basemodule
    STATIC  # 👈 核心：声明为静态库
    URI base.components
    VERSION 1.0
    QML_FILES
        BaseButton.qml
    PLUGIN_TARGET base_components_plugin # 👈 给静态插件命名，供主程序链接
    OUTPUT_TARGETS base_targets
)

qt_target_qml_sources(basemodule
    PREFIX "base/components" # 👈 让图片在虚拟文件系统中和你的组件并排躺在一起
    RESOURCES
        "../../assets/images/info.png" # 👈 安全地引入外部物理路径的图片
)
