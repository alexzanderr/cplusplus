#include <iostream>

using namespace std;

int main() {
    const int n = 10;
    int v[n] = {-1, 1, -1, 3, 4, -1, 6, 7, 8, -1};
             //  0  1   2  3  4   5  6  7  8   9
    int start = 0;
    int stop = 0;

    for(int i = 1; i < n; i++) {
        if (v[i] != -1) {
            stop++;
        } else {
            // daca este activ
            stop++;
            cout << "[" << start + 1 << ", " << stop - 1 << "]\n";
            cout << "Length: " << stop - start - 1 << "\n";
            start = stop;
        }
    }
}