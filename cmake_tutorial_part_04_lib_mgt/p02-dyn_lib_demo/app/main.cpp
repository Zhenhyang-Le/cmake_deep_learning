#include <iostream>
#include "mathlib.h"

int main() {
    MathLib math;

#ifdef Debug
    std::cout << "This is a Debug version." << std::endl;
#else
    std::cout << "This is a Release version." << std::endl;
#endif

    int sum = math.add(3, 4);           // 使用MathLib的add函数

    std::cout << "Sum: " << sum  << std::endl;

    return 0;
}
