
# 创建一个可执行文件
add_executable(app main.cpp)

# 设置可执行文件的输出路径。这里输出到 ${CMAKE_SOURCE_DIR}/target/bin 目录下，也就是p01-statc_lib_demo/target/bi目录下
set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/target/bin
)

# 链接 MathLib 静态库
target_link_libraries(app PRIVATE MathLib)

# 添加编译选项
target_compile_definitions(app PRIVATE -D${CMAKE_BUILD_TYPE})
message(STATUS "Build type: CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
