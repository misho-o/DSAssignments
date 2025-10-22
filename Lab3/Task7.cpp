#include <iostream>
using namespace std;



// TASK 8
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = tail = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

DoublyLinkedList concatenate(DoublyLinkedList& L, DoublyLinkedList& M) {
    DoublyLinkedList result;
	//different cases
    // If L is empty
    if (!L.head)
        return M;

    // If M is empty
    if (!M.head)
        return L;

    // Link L.tail -> M.head
    L.tail->next = M.head;
    M.head->prev = L.tail;

    // Set result head and tail
    result.head = L.head;
    result.tail = M.tail;

    return result;
}

int main() {
    DoublyLinkedList L, M;

    
    L.insertEnd(1);
    L.insertEnd(2);
    L.insertEnd(3);

    
    M.insertEnd(4);
    M.insertEnd(5);
    M.insertEnd(6);

    cout << "List L: ";
    L.display();

    cout << "List M: ";
    M.display();


    DoublyLinkedList result = concatenate(L, M);

    cout << "\nAfter concatenation: ";
    result.display();

    return 0;
}

