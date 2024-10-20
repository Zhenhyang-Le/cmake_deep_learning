# 包含应用程序的源文件。注意此处可以添加多个文件
set(APP_SOURCES main.cpp)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${APP_SOURCES})

# ======= 添加宏定义
target_compile_definitions(${PROJECT_NAME} PRIVATE -D${CMAKE_BUILD_TYPE})
message(STATUS "Build type: CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

# ======= 添加依赖的头文件
# 为目标添加头文件包含路径。注意添加的头文件位于源文件目录下，不是在release目录下
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/lib/libmath
    ${CMAKE_SOURCE_DIR}/lib/libconfig
    ${CMAKE_SOURCE_DIR}/release/lib/libconfuse/include
    )

# ======= 添加依赖的库路径和库文件
# 定义一个函数来解析库路径和名称，并生成库依赖字符串
function(add_library_dependency lib_path_lib_name out_var)
    # 使用正则表达式匹配库名（以'-l'开头）
    string(REGEX MATCH "-l[^ ]+" lib_name "${lib_path_lib_name}")
    string(REGEX REPLACE "([ ]+)([^ ]*)([ ]*-l[^ ]+)$" "\\2" lib_path "${lib_path_lib_name}")
    set(${out_var} "-L${lib_path} -Wl,-rpath,'${lib_path}' ${lib_name}" PARENT_SCOPE)
endfunction()

# 初始化库依赖列表
set(APP_DEP_LIBS "")

# 定义库的路径和名称列表
set(LIB_PATHS
    "${CMAKE_SOURCE_DIR}/release/lib/libmath -lmath"
    "${CMAKE_SOURCE_DIR}/release/lib/libconfuse/lib -lconfuse"
    "${CMAKE_SOURCE_DIR}/release/lib/libconfig -lconfig"
)

# 使用循环遍历库列表并添加依赖
foreach(LIB_PATH ${LIB_PATHS})
    add_library_dependency("${LIB_PATH}" APP_TMP_LIBS)
    list(APPEND APP_DEP_LIBS "${APP_TMP_LIBS}")
endforeach()

# 链接库
target_link_libraries(${PROJECT_NAME} PRIVATE ${APP_DEP_LIBS})

# ======= 设置最终生成的文件路径
# 设置输出路径
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/release/app/
)







