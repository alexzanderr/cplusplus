
#include <iostream>
using namespace std;

#define limit 1005

void PrintAdjacencyMatrix(int matrix[][limit], int nodesNumber) {
    cout << '[';
    for(size_t index = 1; index < nodesNumber; index++) {
        if (index > 1) {
            cout << " [";
        } else {
            cout << "[";
        }

        for(size_t jndex = 1; jndex < nodesNumber ; jndex++) {
            cout << matrix[index][jndex] << ", ";
        }
        cout << matrix[index][nodesNumber] << "]\n";
    }
    cout << " [";
    for(size_t jndex = 1; jndex < nodesNumber ; jndex++) {
        cout << matrix[nodesNumber][jndex] << ", ";
    }
    cout << matrix[nodesNumber][nodesNumber] << "]]" << endl;
}