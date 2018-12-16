#include <iostream>
#include <chrono>
#include <thread>

#include "Calc.h"

int main()
{
    using namespace std::chrono_literals;
    Calc calc;
    while (true) {
        auto a = rand();
        auto b = rand();
        std::cout << a << " + " << b << " = " << calc.sum(a, b) << std::endl;
        std::cout << a << " - " << b << " = " << calc.minus(a, b) << std::endl;
        std::this_thread::sleep_for(1s);
    }
    return 0;
}