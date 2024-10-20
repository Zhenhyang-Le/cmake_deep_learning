
# 创建一个可执行文件
add_executable(app main.cpp)

# 设置可执行文件的输出路径
set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/target/bin
)

# 链接 MathLib 静态库
target_link_libraries(app PRIVATE MathLib)

add_custom_target(other_app_target
    COMMAND ${CMAKE_COMMAND} -E echo "Custom command executed."
)

target_compile_definitions(app PRIVATE -D${CMAKE_BUILD_TYPE})
message(STATUS "Build type: CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
