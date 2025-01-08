// main.cpp
#include <iostream>
#include "sale.h"

int main() {
    SALES::Sales s;
    int n;

    std::cout << "Input n: ";
    std::cin >> n;

    if (n < 1 || n > SALES::QUARTERS) {
        std::cout << "n is not correct.\nAborted" << std::endl;
        return 1;
    }

    double salesInput[SALES::QUARTERS];
    std::cout << "Please input " << n << " double values: ";
    for (int i = 0; i < n; i++) {
        std::cin >> salesInput[i];
    }

    SALES::setSales(s, salesInput, n);
    SALES::showSales(s, n);

    return 0;
}
