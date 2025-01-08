#include <iostream>
#include "complex.h"
using namespace std;

int main() {
    // 创建两个复数对象
    Complex a(3, 4);
    Complex b(2, 6);
    
    // 输出复数 a 和 b
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    // 输出 b 的共轭复数
    cout << "~b = " << ~b << endl;
    
    // 进行加法、减法、乘法操作
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    
    // 乘以常数的操作
    cout << "2 * a = " << 2 * a << endl;
    cout << "a * 2 = " << a * 2 << endl;
    
    // 比较两个复数对象是否相等
    Complex c = b;
    cout << "b == c? " << boolalpha << (b == c) << endl;
    cout << "b != c? " << (b != c) << endl;
    cout << "a == b? " << (a == b) << endl;

    // 输入一个复数并输出
    Complex d;
    cout << "Enter a complex number (real part and imaginary part): ";
    cin >> d;
    cout << "You entered: " << d << endl;
    
    return 0;
}
