add_library(MathLib STATIC mathlib.cpp)  # 创建一个名为MathLib的静态库

# 为目标添加头文件包含路径
target_include_directories(MathLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
