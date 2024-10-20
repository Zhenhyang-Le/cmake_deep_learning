
set(LIB_NAME "math")  

# 直接设置变量，可以包含多个源文件
set(OBJ_FILES "MathLib.cpp")
# file(GLOB_RECURSE OBJ_FILES "*.cpp")

# 定义动态库
add_library(${LIB_NAME} SHARED ${OBJ_FILES})

# 设置库的输出路径
set_target_properties(${LIB_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/release/lib/lib${LIB_NAME}
)

# 设置包含目录，即为目标添加头文件包含路径
target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
