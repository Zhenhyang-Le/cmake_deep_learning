
# 定义一个名为 "MathLib" 的静态库
add_library(MathLib STATIC mathlib.cpp)

# 设置库的输出路径。变量CMAKE_SOURCE_DIR表示构建运行的CMakeLists.txt所在的目录
set_target_properties(MathLib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/target/lib
)

# 设置包含目录，即为目标添加头文件包含路径， CMAKE_CURRENT_SOURCE_DIR表示当前CMakeLists.txt所在的目录
target_include_directories(MathLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
