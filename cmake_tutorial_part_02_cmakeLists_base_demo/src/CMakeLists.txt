add_executable(App main.cpp)  # 创建一个名为App的可执行文件

# 链接MathLib和UtilsLib库到App可执行文件
target_link_libraries(App PRIVATE MathLib UtilsLib)

add_custom_target(other_app_target
    COMMAND ${CMAKE_COMMAND} -E echo "Custom command executed."
)

target_compile_definitions(App PRIVATE -D${CMAKE_BUILD_TYPE})
message(STATUS "Build type: CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

# 为目标添加头文件包含路径
target_include_directories(App PRIVATE ${CMAKE_SOURCE_DIR}/lib)
