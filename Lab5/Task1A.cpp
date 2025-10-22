#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* insertAtEnd(Node* head, int value) {
    if (head == nullptr) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }
    head->next = insertAtEnd(head->next, value);
    return head;
}

void displayReverse(Node* head) {
    if (head == nullptr)
        return;
    displayReverse(head->next); 
    cout << head->data << " ";   
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    cout << "Linked List in Reverse Order: ";
    displayReverse(head);
    cout << endl;

    return 0;
}
