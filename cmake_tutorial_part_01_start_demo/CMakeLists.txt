# 指定CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和使用的编程语言
project(MyProject LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 定义可执行文件的目标和源文件
add_executable(product_cmake_test demo_cpp_main.cpp)
