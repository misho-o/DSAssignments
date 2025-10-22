
#include <iostream>
using namespace std;
//TASK 7
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};


void display(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

// a. Insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// b. Insert at beginning
void insertBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// c. Insert at given position
void insertAtPosition(Node*& head, int val, int pos) {
    if (pos < 1) {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1) {
        insertBeginning(head, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// d. Delete any node by value
void deleteNode(Node*& head, int val) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node *curr = head, *prev = NULL;

    // Case 1: head node to be deleted
    if (curr->data == val) {
        // Only one node case
        if (curr->next == head) {
            delete curr;
            head = NULL;
            return;
        }

        // Find last node
        Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        head = head->next;
        delete curr;
        return;
    }

    // Case 2: non-head node
    do {
        prev = curr;
        curr = curr->next;
    } while (curr != head && curr->data != val);

    if (curr == head) {
        cout << "Value " << val << " not found in list.\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
}

int main() {
    Node* head = NULL;

    // Insert at end
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Initial list:\n";
    display(head);

    
    insertBeginning(head, 5);
    cout << "\nAfter inserting 5 at beginning:\n";
    display(head);

    
    insertAtPosition(head, 25, 4);
    cout << "\nAfter inserting 25 at position 4:\n";
    display(head);

    
    deleteNode(head, 20);
    cout << "\nAfter deleting 20:\n";
    display(head);

    return 0;
}

