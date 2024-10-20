# 设置项目名称和最低版本要求
# cmake_minimum_required(VERSION 3.10)
# project(libconfuse)

# 定制化代码
set(pkg_LIB_NAME "confuse")
set(pkg_TAG "3.3")
set(pkg_NAME "${pkg_LIB_NAME}-${pkg_TAG}")
set(pkg_TAR_NAME "${pkg_NAME}.tar.gz")
set(pkg_download_URL "https://github.com/libconfuse/libconfuse/releases/download/v${pkg_TAG}/${pkg_TAR_NAME}")
set(pkg_download_URL "http://127.0.0.1:8000/${pkg_TAR_NAME}") # 注意是在本地confuse-3.3.tar.gz包所在的目录下运行 python3 -m http.server 命令，它会在本地启动http服务。然后在另外一个窗口运行make命令即可

# 以下为通用代码。
set(pkg_BASE_DIR ${CMAKE_BINARY_DIR}/opensource/lib/lib${pkg_LIB_NAME})
set(pkg_SOURCE_DIR ${pkg_BASE_DIR}/src)
set(pkg_DOWNLOAD_DIR ${pkg_BASE_DIR}/download)
set(pkg_BINARY_DIR ${pkg_BASE_DIR}/build)
set(pkg_INSTALL_DIR ${CMAKE_SOURCE_DIR}/release/lib/lib${pkg_LIB_NAME})

# ### 下载方式1
include(ExternalProject)
ExternalProject_Add(pkg_download_proj
    PREFIX ${pkg_BASE_DIR}
    URL ${pkg_download_URL}
    SOURCE_DIR ${pkg_BINARY_DIR}  # 使用tar解压之后，源文件会解压到 SOURCE_DIR 指定的这个目录下
    BINARY_DIR ${pkg_BINARY_DIR}  # configure和build阶段会在 BINARY_DIR 指定的这个目录下编译
    DOWNLOAD_DIR ${pkg_DOWNLOAD_DIR}
    INSTALL_DIR ${pkg_INSTALL_DIR}

    DOWNLOAD_COMMAND wget ${pkg_download_URL}   # 或使用 curl --noproxy 127.0.0.1 -o  ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME} ${pkg_download_URL}
    UPDATE_COMMAND ""
    PATCH_COMMAND tar --strip-components=1 -xzf ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}
    CONFIGURE_COMMAND ./configure --prefix=${pkg_INSTALL_DIR}
    BUILD_COMMAND  make -j9
    INSTALL_COMMAND make install
    TEST_COMMAND ""
)

# ### 下载方式2
# include(ExternalProject)
# ExternalProject_Add(pkg_download_proj
#     PREFIX ${pkg_BASE_DIR}  # 临时文件目录
#     URL ${pkg_download_URL}
#     SOURCE_DIR ${pkg_SOURCE_DIR}
#     INSTALL_DIR ${pkg_INSTALL_DIR}
#     DOWNLOAD_DIR ${pkg_DOWNLOAD_DIR} # 包下载存放目录
#     DOWNLOAD_COMMAND wget ${pkg_download_URL}
#     UPDATE_COMMAND ""
#     PATCH_COMMAND ""
#     CONFIGURE_COMMAND "" # 不需要配置步骤
#     BUILD_COMMAND ""    # 不需要构建步骤
#     INSTALL_COMMAND ""  # 不需要安装步骤
#     TEST_COMMAND ""
#     # DOWNLOAD_NO_EXTRACT FALSE  # 如果不设置DOWNLOAD_NO_EXTRACT，其会自动解压到 ${pkg_SOURCE_DIR} 目录下。下面的extract_pkg 可以注释掉
# )

# # 添加自定义解压步骤。 
# ExternalProject_Add_Step(pkg_download_proj extract_pkg
#     COMMAND ${CMAKE_COMMAND} -E echo "Extracting pkg..."
#     COMMAND tar --strip-components=1 -xzvf ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}
#     DEPENDEES download # 依赖于下载步骤
#     WORKING_DIRECTORY ${pkg_SOURCE_DIR}  # 解压目录
# )

# ExternalProject_Add_Step(pkg_download_proj build_install_pkg
#     COMMAND ${CMAKE_COMMAND} -E echo "Build and install pkg..."
#     COMMAND cd ${pkg_SOURCE_DIR} && ./configure --prefix=${pkg_INSTALL_DIR} && make -j9 && make install
#     DEPENDEES extract_pkg # 依赖于解压步骤
#     WORKING_DIRECTORY ${pkg_SOURCE_DIR}  # 解压目录
# )

# ExternalProject_Add_StepTargets(pkg_download_proj extract_pkg build_install_pkg)


### 下载方式3
# file(MAKE_DIRECTORY ${pkg_DOWNLOAD_DIR})
# file(MAKE_DIRECTORY ${pkg_SOURCE_DIR})

# # 添加自定义命令来下载源码包
# add_custom_command(
#     OUTPUT ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}
#     COMMAND mkdir -p ${pkg_DOWNLOAD_DIR}
#     COMMAND wget ${pkg_download_URL} 
#     WORKING_DIRECTORY ${pkg_DOWNLOAD_DIR}
#     COMMENT "Downloading ${pkg_TAR_NAME} from ${pkg_download_URL}"
# )

# # 添加自定义目标，依赖于下载的文件
# add_custom_target(pkg_download DEPENDS ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME})

# # 添加自定义命令来解压、配置、编译和安装
# add_custom_command(
#     TARGET pkg_download POST_BUILD
#     COMMAND tar --strip-components=1 -xzvf ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}
#     COMMAND ${CMAKE_COMMAND} -E chdir ${pkg_SOURCE_DIR} ./configure --prefix=${pkg_INSTALL_DIR}
#     COMMAND ${CMAKE_COMMAND} -E chdir ${pkg_SOURCE_DIR} make -j9
#     COMMAND ${CMAKE_COMMAND} -E chdir ${pkg_SOURCE_DIR} make install
#     WORKING_DIRECTORY ${pkg_SOURCE_DIR}
#     COMMENT "Configuring, building and installing ${pkg_LIB_NAME}"
# )

# # 添加自定义目标，依赖于pkg_download目标
# add_custom_target(pkg_download_proj DEPENDS pkg_download)


# ### 下载方式4
# 确保下载目录和源代码目录存在
# file(MAKE_DIRECTORY ${pkg_DOWNLOAD_DIR})
# file(MAKE_DIRECTORY ${pkg_SOURCE_DIR})

# include(FetchContent)
# # 使用 FetchContent_Declare 声明外部项目
# FetchContent_Declare(
#     ${pkg_LIB_NAME}
#     DOWNLOAD_COMMAND wget ${pkg_download_URL} -O ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}
# )

# # 使用 FetchContent_MakeAvailable 或手动更新和获取属性
# FetchContent_GetProperties(${pkg_LIB_NAME})
# if(NOT ${pkg_LIB_NAME}_POPULATED)
#     FetchContent_Populate(${pkg_LIB_NAME})  # 或者 FetchContent_MakeAvailable(${pkg_LIB_NAME})
#     # 添加自定义命令来解压、配置、编译和安装
#     add_custom_command(
#         OUTPUT ${pkg_SOURCE_DIR}/populated
#         COMMAND tar --strip-components=1 -xzvf ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}
#         COMMAND ${CMAKE_COMMAND} -E chdir ${pkg_SOURCE_DIR} ./configure --prefix=${pkg_INSTALL_DIR}
#         COMMAND ${CMAKE_COMMAND} -E chdir ${pkg_SOURCE_DIR} make -j9
#         COMMAND ${CMAKE_COMMAND} -E chdir ${pkg_SOURCE_DIR} make install
#         WORKING_DIRECTORY ${pkg_SOURCE_DIR}
#         COMMENT "Configuring, building and installing ${pkg_LIB_NAME}"
#         VERBATIM
#     )
#     add_custom_target(${pkg_LIB_NAME}_build DEPENDS ${pkg_SOURCE_DIR}/populated)
# endif()

# # 添加自定义目标，依赖于 ${pkg_LIB_NAME}_build 目标
# add_custom_target(pkg_download_proj DEPENDS ${pkg_LIB_NAME}_build)



### 下载方式5
# # 确保下载目录存在
# file(MAKE_DIRECTORY ${pkg_DOWNLOAD_DIR})
# file(MAKE_DIRECTORY ${pkg_SOURCE_DIR})

# # 使用 execute_process 下载文件
# if(NOT EXISTS "${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}")
#     message(STATUS "Downloading ${pkg_TAR_NAME}...")
#     execute_process(
#         COMMAND wget ${pkg_download_URL}
#         RESULT_VARIABLE curl_result
#         OUTPUT_VARIABLE output
#         ERROR_VARIABLE error
#         WORKING_DIRECTORY ${pkg_DOWNLOAD_DIR}
#     )

#     if(NOT curl_result EQUAL 0)
#         message(FATAL_ERROR "Failed to download ${pkg_TAR_NAME}, error:${error}")
#     endif()
# endif()

# # # 添加自定义命令来解压、配置、编译和安装
# add_custom_target(pkg_download_proj ALL
#     COMMAND tar --strip-components=1 -xzvf ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}
#     COMMAND ./configure --prefix=${pkg_INSTALL_DIR}
#     COMMAND  make -j9
#     COMMAND  make install
#     WORKING_DIRECTORY ${pkg_SOURCE_DIR}
#     COMMENT "Configuring, building and installing ${pkg_LIB_NAME}"
# )


### 下载方式6 -no（以下代码需要设置代理，目前我服务器上没有下载成功。暂时搁置。推荐通过其他方式去实现下载功能）
# # 确保下载目录存在
# file(MAKE_DIRECTORY ${pkg_DOWNLOAD_DIR})
# file(MAKE_DIRECTORY ${pkg_SOURCE_DIR})

# if(NOT EXISTS "${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}")
#     message(STATUS "Downloading ${pkg_TAR_NAME}...")

#     # 设置环境变量以绕过代理
#     # set(ENV{no_proxy} "127.0.0.1")

#     # 使用 file (DOWNLOAD ...) 函数下载文件
#     file(DOWNLOAD
#     URL ${pkg_download_URL}
#     STATUS download_status
#     SHOW_PROGRESS
#     TIMEOUT 30
#     )

#   # 检查下载是否成功
#   list(GET download_status 0 status_code)
#   list(GET download_status 1 error_message)
#   if(NOT status_code EQUAL 0)
#     message(FATAL_ERROR "Failed to download pkg_proj: ${error_message}")
#   endif()
# endif()

# # # 添加自定义命令来解压、配置、编译和安装
# add_custom_target(pkg_download_proj ALL
#     COMMAND tar --strip-components=1 -xzvf ${pkg_DOWNLOAD_DIR}/${pkg_TAR_NAME}
#     COMMAND ./configure --prefix=${pkg_INSTALL_DIR}
#     COMMAND  make -j9
#     COMMAND  make install
#     WORKING_DIRECTORY ${pkg_SOURCE_DIR}
#     COMMENT "Configuring, building and installing ${pkg_LIB_NAME}"
# )

