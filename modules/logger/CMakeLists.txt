# 定义一个接口库（Header-only 库）
add_library(logger_module INTERFACE)

# 核心修改：明确声明该模块包含的文件
# target_sources 加上 INTERFACE 参数，可以把头文件挂载到该目标上
# 这样 IDE（如 Qt Creator）的项目树里就能正常显示 Logger.h 了
target_sources(logger_module INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger.h
)

# 配置头文件包含路径，让主程序能直接 #include "Logger.h"
target_include_directories(logger_module INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})