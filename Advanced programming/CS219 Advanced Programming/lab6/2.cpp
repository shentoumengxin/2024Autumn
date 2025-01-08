#include <iostream>
using namespace std;

int fill_array(double arr[], int size) {
    int count = 0;
    double input;
    while (count < size) {
        cout << "Enter value #" << count + 1 << ": ";
        cin >> input;
        if (!cin) {
            cin.clear(); 
            cout << "Non-numeric input detected. Stopping input.\n";
            break;
        }
        arr[count] = input;
        count++;
    }

    return count;  
}

void show_array(double *arr, int size) {
    cout << "Array contents:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse_array(double *arr, int start, int end) {
    if (start >= end) {
        return;  // Base case
    }
    double temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse_array(arr, start + 1, end - 1);
}

int main() {
    int size;
   
    cout << "Enter the size of the array: ";
    cin >> size;
    double *arr = new double[size];

    int actual_size = fill_array(arr, size);
    show_array(arr, actual_size);
    reverse_array(arr, 0, actual_size - 1);
    show_array(arr, actual_size);
    delete[] arr;

    return 0;
}
