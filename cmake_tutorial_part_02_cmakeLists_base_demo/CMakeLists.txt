cmake_minimum_required(VERSION 3.10)  # 设置CMake的最低版本要求
project(MyBasicApp VERSION 1.0)      # 定义项目名称和版本

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")

# 包含子目录
add_subdirectory(lib/MathLib)        # 添加MathLib库的子目录
add_subdirectory(lib/UtilsLib)       # 添加UtilsLib库的子目录
add_subdirectory(src)                # 添加源代码的子目录

# =================================================
# 安装
# 设置安装目录，以下表示安装在当前目录的myapp_install目录下，没有目录会自动创建
set(CMAKE_INSTALL_PREFIX "myapp_install")
# 安装可执行文件：
# install(TARGETS App
#         RUNTIME DESTINATION bin)
install(TARGETS App
        DESTINATION bin PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE WORLD_EXECUTE WORLD_READ)
# 安装库文件：
install(TARGETS MathLib UtilsLib
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)
# 安装头文件：
        install(FILES "lib/MathLib/mathlib.h" "lib/UtilsLib/utilslib.h"
        DESTINATION include)
# 安装其他文件，暂时没有
# install(DIRECTORY "path/to/data"
#         DESTINATION share/mybasicapp)


# =================================================
# 打包
include(CPack)

set(CPACK_PACKAGE_NAME "MyBasicApp")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "Your Name <youremail@example.com>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyBasicApp - A Simple C++ Application")

# 选择打包格式
set(CPACK_GENERATOR "TGZ;DEB;RPM") 

# 配置依赖关系
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14), libgcc1 (>= 1:3.0)")
