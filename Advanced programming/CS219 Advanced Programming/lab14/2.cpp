
#include <iostream>

// 基类 CStereoShape
class CStereoShape {
private:
    static int numberOfObject;

public:
    CStereoShape() {
        numberOfObject++;
        std::cout << "CStereoShape 构造函数被调用。总对象数: " << numberOfObject << std::endl;
    }

    CStereoShape(const CStereoShape& other) {
        numberOfObject++;
        std::cout << "CStereoShape 拷贝构造函数被调用。总对象数: " << numberOfObject << std::endl;
    }

    virtual ~CStereoShape() {
        numberOfObject--;
        std::cout << "CStereoShape 析构函数被调用。剩余对象数: " << numberOfObject << std::endl;
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

// 派生类 CCube
class CCube : public CStereoShape {
private:
    double length;
    double width;
    double height;

public:
    // 无参构造函数，创建默认立方体
    CCube() : length(1.0), width(1.0), height(1.0) {
        std::cout << "CCube 无参构造函数被调用。" << std::endl;
    }

    // 带参数的构造函数，对应立方体的长度、宽度和高度
    CCube(double l, double w, double h) : length(l), width(w), height(h) {
        std::cout << "CCube 带参数构造函数被调用。" << std::endl;
    }

    // 拷贝构造函数
    CCube(const CCube& other) : CStereoShape(other), length(other.length), width(other.width), height(other.height) {
        std::cout << "CCube 拷贝构造函数被调用。" << std::endl;
    }

    // 重写 GetArea，计算立方体的表面积
    virtual double GetArea() const override {
        double area = 2 * (length * width + length * height + width * height);
        std::cout << "CCube::GetArea() = " << area << std::endl;
        return area;
    }

    // 重写 GetVolume，计算立方体的体积
    virtual double GetVolume() const override {
        double volume = length * width * height;
        std::cout << "CCube::GetVolume() = " << volume << std::endl;
        return volume;
    }

    // 重写 Show，打印立方体的描述
    virtual void Show() const override {
        std::cout << "立方体描述: 长度 = " << length
                  << ", 宽度 = " << width
                  << ", 高度 = " << height
                  << ", 表面积 = " << GetArea()
                  << ", 体积 = " << GetVolume() << std::endl;
    }
};

// 示例使用
int main() {
    std::cout << "当前 CStereoShape 对象数: " << CStereoShape::GetNumOfObject() << std::endl;

    CStereoShape shape;
    shape.GetArea();
    shape.GetVolume();
    shape.Show();

    std::cout << "当前 CStereoShape 对象数: " << CStereoShape::GetNumOfObject() << std::endl;

    {
        CCube cube1;
        cube1.GetArea();
        cube1.GetVolume();
        cube1.Show();

        CCube cube2(3.0, 4.0, 5.0);
        cube2.GetArea();
        cube2.GetVolume();
        cube2.Show();

        CCube cube3 = cube2;
        cube3.Show();

        std::cout << "当前 CStereoShape 对象数: " << CStereoShape::GetNumOfObject() << std::endl;
    }

    std::cout << "CCube 对象销毁后，当前 CStereoShape 对象数: " << CStereoShape::GetNumOfObject() << std::endl;

    return 0;
}
