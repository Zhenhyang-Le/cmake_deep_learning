default_target: all
.PHONY : default_target

# $(info Compiler: $(wildcard ./build/Makefile))

# 清理命令
clean:
	rm -rf ./build 
	rm -rf ./release

# 默认目标
ifeq ("${cmd}","")
all:  build
else
all:  ${cmd}
endif

# 通过 "make cmd=help" 运行，等同于 "make help"
${cmd}: ./build/Makefile
	cmake --build build --target $@

# 配置项目
configure: 
	cmake --fresh -DCMAKE_BUILD_TYPE=Release -B build -S .

# 编译项目
build: configure pkg_download_proj math config p03-remote_install_lib_demo
	@echo "====== done ====="

# 构建 pkg_download_proj
pkg_download_proj:
	cmake --build build --target $@

# 构建 math
math: configure
	cmake --build build --target $@

# 构建 config
config: configure
	cmake --build build --target $@

# 构建 remote_install_lib_demo
p03-remote_install_lib_demo: configure
	cmake --build build --target $@

# 构建 help
help: ./build/Makefile
# ifeq ("$(wildcard ./build/Makefile)","")
# 	$(error ./build/Makefile does not exist. Please run 'make' to create it.)
# 	exit 1
# endif
	cmake --build build --target $@

# 运行程序
run: ./release/app/p03-remote_install_lib_demo
	@cp -f ./etc/* ./release/app/
	@cd ./release/app && ./p03-remote_install_lib_demo

# 伪目标，用于防止与文件名冲突
.PHONY: clean all build pkg_download_proj math config remote_install_lib_demo help run ${cmd}
