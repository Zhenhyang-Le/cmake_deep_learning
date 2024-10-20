#include <iostream>
#include "CfgManager.h"
#include "MathLib.h"

#define CONFIG_FILE "stuff_demo.conf"

int main(void) {
#ifdef Debug
    std::cout << "This is a Debug version." << std::endl;
#else
    std::cout << "This is a Release version." << std::endl;
#endif

    MathLib math;
    CfgManager config(CONFIG_FILE);

    std::cout << "Hello, " << config.getTarget() << "!" << std::endl;
    int cfg_num = config.getConfigNum();
    std::cout << "cfg_num is " << cfg_num << "!" << std::endl;

    int sum = math.add(3, 4); // 使用MathLib的add函数

    std::cout << "Sum= " << sum << ", sum+cfg_num= " << sum + cfg_num << std::endl;

    return 0;
}