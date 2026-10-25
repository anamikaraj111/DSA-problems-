// Reverse a doubly linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void appendNode(Node*& head, Node*& tail, int value) {
    Node* node = new Node(value);

    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }

    tail->next = node;
    node->prev = tail;
    tail = node;
}

Node* reverseDoublyLL(Node* head) {
    Node* newHead = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* originalNext = current->next;
        current->next = current->prev;
        current->prev = originalNext;
        newHead = current;
        current = originalNext;
    }

    return newHead;
}

void printList(const Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " ";
        }
        head = head->next;
    }
    cout << endl;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    appendNode(head, tail, 10);
    appendNode(head, tail, 20);
    appendNode(head, tail, 30);
    appendNode(head, tail, 40);

    head = reverseDoublyLL(head);
    printList(head);

    deleteList(head);
    return 0;
}
