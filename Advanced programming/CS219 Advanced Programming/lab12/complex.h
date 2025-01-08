#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>  

class Complex {
private:
    double real;  // 实部
    double imag;  // 虚部

public:
    
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    double getReal() const { return real; }

    double getImag() const { return imag; }


    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }


    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

 
    Complex operator*(double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    Complex operator~() const {
        return Complex(real, -imag);
    }
    friend Complex operator*(double scalar, const Complex& c) {
        return Complex(c.real * scalar, c.imag * scalar);
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }


    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // 重载 << 操作符 (输出复数)
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i";
        return os;
    }

    // 重载 >> 操作符 (输入复数)
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }

};

#endif
