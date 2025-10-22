

#include <iostream>
using namespace std;

//TASK 6
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
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void display(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

void deleteValue(Node*& head, int val) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    
    if (head->data == val) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << val << " deleted from the list.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Value " << val << " not found in the list.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    cout << val << " deleted from the list.\n";
}

int main() {
    Node* head = NULL;

    
    int arr[] = {10, 20, 30, 40, 50};
    for (int i =0;i<5;i++){
        insertEnd(head, arr[i]);
    	
	}
    

    cout << "Original List:\n";
    display(head);

    int val;
    cout << "\nEnter value to delete: ";
    cin >> val;

    deleteValue(head, val);

    cout << "\nUpdated List:\n";
    display(head);

    return 0;
}
