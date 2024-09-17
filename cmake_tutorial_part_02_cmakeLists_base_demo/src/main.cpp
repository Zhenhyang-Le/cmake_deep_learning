#include <iostream>
#include "mathlib.h"
#include "utilslib.h"

int main() {
    MathLib math;
    UtilsLib utils;

#ifdef Debug
    std::cout << "This is a Debug version." << std::endl;
#else
    std::cout << "This is a Release version." << std::endl;
#endif

    int sum = math.add(3, 4);           // 使用MathLib的add函数
    int square = utils.square(5);       // 使用UtilsLib的square函数

    std::cout << "Sum: " << sum << ", Square: " << square << std::endl;

    return 0;
}

/*
配置和生成构建系统的过程，并指定了构建目录: cmake -S . -B build

指定的构建目录中启动构建过程： cmake --build build


make help 所有支持的目标文件：如下：
[root@10 build]# make help
The following are some of the valid targets for this Makefile:
... all (the default if no target is provided)
... clean
... depend
... edit_cache
... rebuild_cache
... App
... MathLib
... UtilsLib

可以使用make App单独编译执行文件
也可以使用make UtilsLib 单独编译 libUtilsLib.a 静态库

cmake --build build --target App

*/ 