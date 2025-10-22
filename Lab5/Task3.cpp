#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
int lengthTailRec(Node* head, int count = 0) {
    
    
    if (head == NULL)
        return count;

    
    return lengthTailRec(head->next, count + 1);
}

int main() {
    
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};

    int len = lengthTailRec(head);
    cout << "Length of linked list: " << len << endl;

    return 0;
}
