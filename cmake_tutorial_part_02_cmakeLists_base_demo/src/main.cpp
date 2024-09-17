#include <iostream>
#include "mathlib.h"
#include "utilslib.h"

int main() {
    MathLib math;
    UtilsLib utils;

    int sum = math.add(3, 4);           // 使用MathLib的add函数
    int square = utils.square(5);       // 使用UtilsLib的square函数

    std::cout << "Sum: " << sum << ", Square: " << square << std::endl;

    return 0;
}
