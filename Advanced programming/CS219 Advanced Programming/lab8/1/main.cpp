// main.cpp
#include <iostream>
#include "swap.h"

int main() {
    int x, y;
    std::cout << "Please input two integers: ";
    std::cin >> x >> y;

    std::cout << "Before swap: " << x << "," << y << std::endl;
    swap(x, y);
    std::cout << "After swap: " << x << "," << y << std::endl;

    return 0;
}
