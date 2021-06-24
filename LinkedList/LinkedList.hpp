#include <iostream>

using namespace std;

struct LinkedListNode {
    int value;
    LinkedListNode* next;
};

void AddNode(LinkedListNode* head, LinkedListNode* new_node) {
    if (head == nullptr) {
        cout << "Its impossible to add node to non-existent linked list." << endl;
    } else {
        LinkedListNode* iter = head->next;
        if (iter != nullptr) {
            for (; iter->next != nullptr; iter = iter->next) {}
            iter->next = new_node;
            new_node->next = nullptr;
        } else {
            head->next = new_node;
        }
    }
}

void RemoveNode(LinkedListNode* head, int value) {
    // this function removes the first 
    // occurence of the value in the linked list
    if (head == nullptr) {
        cout << "You cant remove nodes from an non-existent list." << endl;
    } else if (head->next == nullptr) {
        cout << "You cant remove node from an empty list." << endl;
    } else {
        LinkedListNode* iter = head->next;
        if (iter->value == value) {
            if (iter->next != nullptr) {
                head->next = iter->next;
            } else {
                head->next = nullptr;
            }
        } else {
            LinkedListNode* after = nullptr;
            for (; iter->next != nullptr; iter = iter->next) {
                if (iter->next->value == value) {
                    if (iter->next->next != nullptr) {
                        after = iter->next->next;
                    }
                    break;
                }
            }
            if (after != nullptr) {
                iter->next = after;
            } else {
                iter->next = nullptr;
            }
        }
    }
}

void AddNode(LinkedListNode* head, int value) {
    if (head == nullptr) {
        cout << "You cant add node to nullptr!" << endl;
    } else {
        LinkedListNode* iter = head->next;
        if (iter != nullptr) {
            for (; iter->next != nullptr; iter = iter->next) {}
            iter->next = new LinkedListNode;
            iter->next->value = value;
            iter->next->next = nullptr;
        } else {
            LinkedListNode* new_node = new LinkedListNode;
            new_node->value = value;
            new_node->next = nullptr;
            head->next = new_node;
        }
    }
}

void PrintList(LinkedListNode* head) {
    if (head == nullptr) {
        cout << "Empty list." << endl;
    } else {
        cout << "[ ";
        LinkedListNode* iter = head->next;
        for (; iter->next != nullptr; iter = iter->next) {
            cout << "(" << iter->value << ") -> ";
        }
        cout << "(" << iter->value << ") ]" << endl;
    }
}

void FreeMemory(LinkedListNode* head) {
    LinkedListNode* iter = head;
    while (iter != nullptr) {
        LinkedListNode* storage = iter->next;
        delete iter;
        iter = storage;
    }
}

LinkedListNode* ReversedLinkedList(LinkedListNode* head) {
    if (head != nullptr) {
        LinkedListNode *new_list = new LinkedListNode;
        new_list->next = new LinkedListNode;
        new_list->next->value = head->next->value;
        new_list->next->next = nullptr;

        for (LinkedListNode *iter = head->next->next; iter != nullptr; iter = iter->next) {
            LinkedListNode *new_node = new LinkedListNode;
            new_node->value = iter->value;
            new_node->next = new_list->next;
            new_list->next = new_node;
            // delete new_node;
        }
        return new_list;
    } else {
        return nullptr;
    }
}