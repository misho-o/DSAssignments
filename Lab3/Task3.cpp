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

// Function to insert a node at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display the list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

// Function to arrange even numbers before odd numbers
void arrangeEvenOdd(Node*& head) {
    if (!head) return;

    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            // Even number
            if (evenHead == NULL) {
                evenHead = evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        } else {
            // Odd number
            if (oddHead == NULL) {
                oddHead = oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
    }

    // If there are no evens or no odds
    if (evenHead == NULL || oddHead == NULL)
        return;

    // Join even and odd lists
    evenTail->next = oddHead;
    oddTail->next = NULL;
    head = evenHead;
}

int main() {
    Node* head = NULL;

    // Example input
    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    for (int i = 0;i<10;i++){
    	insertEnd(head, arr[i]);
	}
        

    cout << "Original List:\n";
    display(head);

    arrangeEvenOdd(head);

    cout << "\nModified List (Even before Odd):\n";
    display(head);

    return 0;
}

