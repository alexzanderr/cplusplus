
#include <iostream>
#include <cstring>
using namespace std;

int randint(const int &start, const int &stop) {
    return rand() % stop + start;
}

char randchar(const char *array) {
    const int size = strlen(array);
    return array[rand() % (size - 1)];
}