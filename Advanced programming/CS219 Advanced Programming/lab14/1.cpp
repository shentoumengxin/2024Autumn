#include <iostream>

class CStereoShape {
private:
    static int numberOfObject;

public:
    CStereoShape() {
        numberOfObject++;
        std::cout << "CStereoShape Constructor called. Total objects: " << numberOfObject << std::endl;
    }

    CStereoShape(const CStereoShape& other) {
        numberOfObject++;
        std::cout << "CStereoShape Copy Constructor called. Total objects: " << numberOfObject << std::endl;
    }

    virtual ~CStereoShape() {
        numberOfObject--;
        std::cout << "CStereoShape Destructor called. Remaining objects: " << numberOfObject << std::endl;
    }

    virtual double GetArea() const {
        std::cout << "CStereoShape::GetArea()" << std::endl;
        return 0.0;
    }

    virtual double GetVolume() const {
        std::cout << "CStereoShape::GetVolume()" << std::endl;
        return 0.0;
    }

    virtual void Show() const {
        std::cout << "CStereoShape::Show()" << std::endl;
    }

    static int GetNumOfObject() {
        return numberOfObject;
    }
};

int CStereoShape::numberOfObject = 0;

class CCube : public CStereoShape {
private:
    double side;

public:
    CCube(double s) : side(s) {
        std::cout << "CCube Constructor called." << std::endl;
    }

    virtual ~CCube() {
        std::cout << "CCube Destructor called." << std::endl;
    }

    virtual double GetArea() const override {
        std::cout << "CCube::GetArea()" << std::endl;
        return 6 * side * side;
    }

    virtual double GetVolume() const override {
        std::cout << "CCube::GetVolume()" << std::endl;
        return side * side * side;
    }

    virtual void Show() const override {
        std::cout << "CCube with side length: " << side << std::endl;
    }
};

int main() {
    std::cout << "Number of CStereoShape objects: " << CStereoShape::GetNumOfObject() << std::endl;

    CStereoShape shape;
    shape.GetArea();
    shape.GetVolume();
    shape.Show();

    std::cout << "Number of CStereoShape objects: " << CStereoShape::GetNumOfObject() << std::endl;

    {
        CCube cube(3.0);
        cube.GetArea();
        cube.GetVolume();
        cube.Show();

        std::cout << "Number of CStereoShape objects: " << CStereoShape::GetNumOfObject() << std::endl;
    }

    std::cout << "Number of CStereoShape objects after cube is destroyed: " 
              << CStereoShape::GetNumOfObject() << std::endl;

    return 0;
}
