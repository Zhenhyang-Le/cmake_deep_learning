
# 定义一个名为 "MathLib" 的动态库
add_library(MathLib SHARED mathlib.cpp)

# 设置库的输出路径
set_target_properties(MathLib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/target/lib
)

# 设置包含目录，即为目标添加头文件包含路径
target_include_directories(MathLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
