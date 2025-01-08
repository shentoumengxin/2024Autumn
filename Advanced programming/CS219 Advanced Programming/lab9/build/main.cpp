// main.cpp
#include "candybar.h"

using namespace std;

int main() {
    CandyBar cb;
    set(cb);
    show(cb);

    CandyBar* cbPtr = new CandyBar;
    set(cbPtr);
    show(cbPtr);

    delete cbPtr;
    return 0;
}
