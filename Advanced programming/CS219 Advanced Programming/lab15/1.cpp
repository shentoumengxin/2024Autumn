#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double newX, double newY) : x(newX), y(newY) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

class Line {
private:
    Point p1, p2;       
    double distance;    

public:

    Line(const Point& xp1, const Point& xp2) : p1(xp1), p2(xp2) {
        double dx = p2.getX() - p1.getX();
        double dy = p2.getY() - p1.getY();
        distance = sqrt(dx * dx + dy * dy);
    }

    Line(const Line& q) : p1(q.p1), p2(q.p2), distance(q.distance) {
        cout << "calling the copy constructor of Line" << endl;
    }


    double getDistance() const {
        return distance;
    }
};

int main() {
    Point a(8, 9), b(1, -1);
    cout << "test point a: x = " << a.getX() << ", y = " << a.getY() << endl;
    cout << "test point b: x = " << b.getX() << ", y = " << b.getY() << endl;

    Line l1(a, b); // 使用构造函数初始化线段
    cout << "line1: " << l1.getDistance() << endl;

    Line l2(l1);   // 使用拷贝构造函数初始化线段
    cout << "line2: " << l2.getDistance() << endl;

    return 0;
}
