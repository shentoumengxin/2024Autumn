#include <iostream>
#include "function.h"

int main() {
    int a ,b;
    std::cout<<"Input two Integer:";
    std::cin>>a>>b;
    std::cout << "Addition: " << add(a, b) << std::endl;
    std::cout << "Subtraction: " << subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << multiply(a, b) << std::endl;

    try {
        std::cout << "Division: " << divide(a, b) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
