#include <iostream>
#include <vector>
#include <memory>

class Matrix {
private:
    std::vector<float> data;  
    int row_count;
    int col_count;

public:

    Matrix(int rows, int cols) : row_count(rows), col_count(cols), data(rows * cols) {}


    Matrix(const Matrix& other) : row_count(other.row_count), col_count(other.col_count), data(other.data) {}

    ~Matrix() {}

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            row_count = other.row_count;
            col_count = other.col_count;
            data = other.data; 
        }
        return *this;
    }

    // Element access
    float& operator()(int row, int col) {
        return data[row * col_count + col];
    }

    const float& operator()(int row, int col) const {
        return data[row * col_count + col];
    }

    // Matrix addition
    Matrix operator+(const Matrix& other) const {
        Matrix result(*this);  // Copy constructor
        for (int i = 0; i < row_count * col_count; ++i) {
            result.data[i] += other.data[i];
        }
        return result;
    }

    // Print matrix
    void print() const {
        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < col_count; ++j) {
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix a(3, 4);
    Matrix b(3, 4);
    a(1, 2) = 3;
    b(2, 3) = 4;

    Matrix c = a + b;
    Matrix d = a;
    

    std::cout << "a is:" << std::endl;
    a.print();
    std::cout << "b is:" << std::endl;
    b.print();
    std::cout << "c is:" << std::endl;
    c.print();
    std::cout << "Before assignment, d is:" << std::endl;
    d.print();
    d = b;
    std::cout << "After assignment, d is:" << std::endl;
    d.print();

    return 0;
}
