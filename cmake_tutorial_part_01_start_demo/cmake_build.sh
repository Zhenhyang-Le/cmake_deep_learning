#!/bin/bash
export LC_ALL=C

# 获取脚本所在目录的绝对路径
curDIR=$(cd $(dirname $0); pwd)
projectMainDir="${curDIR}/build"
product_main_exe_name="product_cmake_test"

function printResultBanner()
{
    echo -e "\n=========================================================>"
    echo -e "$1!!!"
    echo -e "=========================================================<"
}

# 检查并创建构建目录
if [ ! -d ${projectMainDir} ];then
    mkdir -p ${projectMainDir}
fi

# 生成可执行文件并检查构建是否成功
cd ${projectMainDir}
rm -rf * && cmake .. && cmake .. && make clean && make
if [ $? -ne 0 ];then
    printResultBanner "FAILED : make compile errors and not continue !"
    exit 1
fi

# 运行可执行程序
printResultBanner "INFO : Start To Run The Executable!!!"
${projectMainDir}/${product_main_exe_name}
if [ $? -ne 0 ];then
    printResultBanner "FAILED : run [${projectMainDir}/${product_main_exe_name}] errors and not continue !"
    exit 1
fi

# 给出成功提示
printResultBanner "SUCCESS : Congratulations, all test cases have passed successfully!!!"
exit 0
