
#include <iostream>
using namespace std;

// this is a structe for linked lists
struct Node {
    int value;
    Node *next;
};

void AddNode(Node *head, int value) {
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = nullptr;

    Node *iter = head->next;
    for(; iter->next != nullptr; iter = iter->next) {}
    iter->next = new_node;
}

void AddNode(Node *head, Node* node) {
    Node *iter = head->next;
    for(; iter->next != nullptr; iter = iter->next) {}
    iter->next = node;
}