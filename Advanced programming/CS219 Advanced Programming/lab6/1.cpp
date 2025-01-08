#include <iostream>
using namespace std;

void display() {
    // Display the calculator menu
    cout << "Calculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
}

int Add(int a, int b) {
    return a + b;
}

int Subtract(int a, int b) {
    return a - b;
}

int Multiply(int a, int b) {
    return a * b;
}

int Divide(int a, int b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error: Division by zero!" << endl;
        return 0; // return 0 when division by zero occurs
    }
}

int Modulus(int a, int b) {
    if (b != 0)
        return a % b;
    else {
        cout << "Error: Modulus by zero!" << endl;
        return 0; // return 0 when modulus by zero occurs
    }
}

int main() {
    int choice;
    int num1, num2;
    char continueChoice;

    display();  // Display menu options

    do {
        cout << "Choose operation (1-5): ";
        cin >> choice;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "Result: " << Add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << Subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << Multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << Divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Result: " << Modulus(num1, num2) << endl;
                break;
            default:
                cout << "Invalid choice. Please choose a valid operation." << endl;
                break;
        }

        cout << "Press Y/y to continue, N/n to exit: ";
        cin >> continueChoice;

    } while (continueChoice == 'Y' || continueChoice == 'y');

    cout << "Done!" << endl;

    return 0;
}
