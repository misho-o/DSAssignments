
#include <iostream>
using namespace std;
//TASK 2
struct Node {
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = NULL;
    }
};

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

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to rotate the list
void rotateList(Node*& head, int k) {
    if (!head || k == 0) return;

    // Count total nodes
    Node* temp = head;
    int count = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Connect last node to head (make circular)
    temp->next = head;

    // If k >= count, adjust
    k = k % count;

    // Traverse to the node before new head
    int steps = count - k;
    Node* newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    head = newTail->next;
    newTail->next = NULL;
}

int main() {
    Node* head = NULL;

    int values[] = {5, 3, 1, 8, 6, 4, 2};
    for (int v=0;v<7;v++)
        insertEnd(head, v);

    cout << "Original list: ";
    display(head);

    int k;
    cout << "Enter number of elements to move: ";
    cin >> k;

    rotateList(head, k);

    cout << "After rotation: ";
    display(head);

    return 0;
}
