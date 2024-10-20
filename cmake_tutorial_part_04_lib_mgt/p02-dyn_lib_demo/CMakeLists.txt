# 设置项目名称和最低版本要求
cmake_minimum_required(VERSION 3.10)
project(p02-dyn_lib_demo)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加lib目录
add_subdirectory(lib/MathLib)

# 添加app目录
add_subdirectory(app)

