cmake_minimum_required(VERSION 3.10)  # 设置CMake的最低版本要求
project(MyBasicApp VERSION 1.0)      # 定义项目名称和版本

# 包含子目录
add_subdirectory(lib/MathLib)        # 添加MathLib库的子目录
add_subdirectory(lib/UtilsLib)       # 添加UtilsLib库的子目录
add_subdirectory(src)                # 添加源代码的子目录
