#include "sale.h"
#include <iostream>
#include <algorithm> 
#include <numeric>  

namespace SALES {
    
    void setSales(Sales& s, const double ar[], int n) {
        for (int i = 0; i < n; i++) {
            s.sales[i] = ar[i];
        }

        for (int i = n; i < QUARTERS; i++) {
            s.sales[i] = 0.0;
        }

        s.average = std::accumulate(s.sales, s.sales + n, 0.0) / n;
        s.max = *std::max_element(s.sales, s.sales + n);
        s.min = *std::min_element(s.sales, s.sales + n);
    }

    void showSales(const Sales& s, int n) {
        std::cout << "Sales: ";
        for (int i = 0; i < n; i++) {
            std::cout << s.sales[i] << " ";
        }
        std::cout << "\nAverage: " << s.average << std::endl;
        std::cout << "Max: " << s.max << std::endl;
        std::cout << "Min: " << s.min << std::endl;
    }
}