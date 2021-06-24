
#include <iostream>
#include <fstream>

using namespace std;

#define limit 10000

// this is a structe for linked lists
struct Node {
    int value;
    Node *next;
    int degree = 0;
};

Node* Nodes[limit];

void AddNode(Node *head, int value) {
    head->degree++;

    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = nullptr;

    Node *iter = head->next;
    for(; iter->next != nullptr; iter = iter->next) {}
    iter->next = new_node;
}

void AddNode(Node *head, Node* node) {
    head->degree++;

    Node *iter = head->next;
    for(; iter->next != nullptr; iter = iter->next) {}
    iter->next = node;
}

// this function returns a new list because 
// i dont want to implement with exmpty head 
// node that points to the list
Node* DeleteNode(Node *head, int value) {
    Node *new_list;
    if (head->value == value) {
        for (Node *iter = head->next; iter != nullptr; iter = iter->next) {
            AddNode(new_list, iter->value);
        }
    } else {
        for (Node *iter = head->next; iter->next != nullptr; iter = iter->next) {
            if (iter->value != value) {
                AddNode(new_list, iter->value);
            }
        }
    }
    return new_list;
}

void AllocateNodes(int nodesNumber) {
    for(int i = 1; i <= nodesNumber; i++) {
        Nodes[i] = new Node;
        Nodes[i]->value = i;
        Nodes[i]->next = nullptr;
    }
}

void ReadNodesFromFile(ifstream& file, int edgesNumber) {
    for(int i = 0; i < edgesNumber; i++) {
        int x, y;
        file >> x >> y;
        AddNode(Nodes[x], y);
        AddNode(Nodes[y], x);
    }
}