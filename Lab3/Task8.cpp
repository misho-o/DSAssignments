#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};


void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Perform the required operation
void rearrangeList(Node*& head) {
    if (!head || !head->next)
        return;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even; // Start of alternate nodes

    // Separate the alternate nodes
    while (odd->next && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    
    evenHead = reverseList(evenHead);

    
    odd->next = evenHead;
}

int main() {
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 4);
    insertEnd(head, 9);
    insertEnd(head, 1);
    insertEnd(head, 3);
    

    cout << "Original list: ";
    printList(head);

    rearrangeList(head);

    cout << "Modified list: ";
    printList(head);

    return 0;
}

