// candybar.cpp
#include "candybar.h"
#include <iostream>
#include <cstring>

using namespace std;

void set(CandyBar & cb) {
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb.brand, LEN);
    cout << "Enter weight of the Candy bar: ";
    cin >> cb.weight;
    cout << "Enter calories (an integer value) in the Candy bar: ";
    cin >> cb.calories;
    cin.ignore();
}

void set(CandyBar* const cb) {
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb->brand, LEN);
    cout << "Enter weight of the Candy bar: ";
    cin >> cb->weight;
    cout << "Enter calories (an integer value) in the Candy bar: ";
    cin >> cb->calories;
    cin.ignore(); 
}

void show(const CandyBar & cb) {
    cout << "Brand: " << cb.brand << "\n";
    cout << "Weight: " << cb.weight << "\n";
    cout << "Calories: " << cb.calories << "\n";
}

void show(const CandyBar* cb) {
    cout << "Brand: " << cb->brand << "\n";
    cout << "Weight: " << cb->weight << "\n";
    cout << "Calories: " << cb->calories << "\n";
}
