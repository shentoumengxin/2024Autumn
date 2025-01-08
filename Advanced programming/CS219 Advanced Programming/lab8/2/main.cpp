
#include <iostream>
#include "match.h"

int main() {
    char str[100];
    char ch;

    std::cout << "Please input a string: ";
    std::cin.getline(str, 100);

    std::cout << "Please input a character: ";
    std::cin >> ch;

    const char* result = match(str, ch);

    if (result != NULL) {
        std::cout << result << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}
