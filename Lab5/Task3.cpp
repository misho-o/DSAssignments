#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


bool searchTail(Node* head, int key) {
    if (head == NULL)
        return false;
    if (head->data == key)
        return true;
    return searchTail(head->next, key);
}
bool searchNonTail(Node* head, int key) {
  
    if (head == NULL)
        return false;
        
    if (head->data == key)
        return true;


    bool foundInRest = searchNonTail(head->next, key);

    return foundInRest;
}


int main() {
    
    Node* head = new Node{5, NULL};
    head->next = new Node{10, NULL};
    head->next->next = new Node{15, NULL};

    int key = 10;
    if (searchNonTail(head, key))
        cout << key << " found in the list.\n";
    else
        cout << key << " not found in the list.\n";

    return 0;
}

