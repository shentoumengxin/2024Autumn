#include <iostream>
#include "Rectangle.h"

int main() {
    // Create two Rectangle objects
    Rectangle r1; // Default rectangle (1 x 1)
    Rectangle r2(4, 35.2); // Custom rectangle (4 x 35.2)

    // Display information for the first rectangle
    std::cout << "Rectangle 1:" << std::endl;
    r1.display();

    // Display information for the second rectangle
    std::cout << "Rectangle 2:" << std::endl;
    r2.display();

    // Display the number of Rectangle objects created
    std::cout << "Number of Rectangle objects: " << Rectangle::getCount() << std::endl;

    return 0;
}
