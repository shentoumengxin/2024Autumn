#include <iostream>
#include "Rectangle.h"

int Rectangle::countOfObject = 0; // Initialize the static data member

// Default constructor
Rectangle::Rectangle() : width(1), height(1) {
    countOfObject++;
}

// Parameterized constructor
Rectangle::Rectangle(double w, double h) : width(w), height(h) {
    countOfObject++;
}

// Getter for width
double Rectangle::getWidth() const {
    return width;
}

// Getter for height
double Rectangle::getHeight() const {
    return height;
}

// Setter for width
void Rectangle::setWidth(double w) {
    width = w;
}

// Setter for height
void Rectangle::setHeight(double h) {
    height = h;
}

// Method to calculate the area of the rectangle
double Rectangle::getArea() const {
    return width * height;
}

// Method to calculate the perimeter of the rectangle
double Rectangle::getPerimeter() const {
    return 2 * (width + height);
}

// Method to display the rectangle's information
void Rectangle::display() const {
    std::cout << "Width: " << width << ", Height: " << height
              << ", Area: " << getArea() << ", Perimeter: " << getPerimeter() << std::endl;
}

// Static method to return the count of created objects
int Rectangle::getCount() {
    return countOfObject;
}
