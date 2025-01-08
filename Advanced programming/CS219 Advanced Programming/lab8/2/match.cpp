// match.cpp
#include "match.h"
#include <cstddef> // For NULL

const char* match(const char* s, char ch) {
    while (*s != '\0') {
        if (*s == ch) {
            return s;
        }
        s++;
    }
    return NULL;
}
