#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double width;
    double height;
    static int countOfObject; // Static data member to track the count of objects

public:
    
    Rectangle(); 
    Rectangle(double w, double h);

    // Getter methods
    double getWidth() const;
    double getHeight() const;

    // Setter methods
    void setWidth(double w);
    void setHeight(double h);

    
    double getArea() const;
    double getPerimeter() const;

    // Method to display the rectangle information
    void display() const;

   
    static int getCount();
};

#endif
