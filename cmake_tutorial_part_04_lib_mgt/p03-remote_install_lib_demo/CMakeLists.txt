# 设置项目名称和最低版本要求
cmake_minimum_required(VERSION 3.10)
project(p03-remote_install_lib_demo VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# # 添加lib目录
# add_subdirectory(lib/libmath)

# # 添加ConfuseLib目录
# add_subdirectory(lib/ConfuseLib)

# # 添加app目录
# add_subdirectory(app)

# 添加子目录
add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(opensource)
