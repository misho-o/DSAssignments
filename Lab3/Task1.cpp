
#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;

    node() {
        value = 0;
        next = NULL;
    }
};


void arrToList(int arr[], int size, node*& head) {
    node* temp = head;

    for (int i = 0; i < size; i++) {
        node* newNode = new node;
        newNode->value = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}


void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int num[5] = {1, 2, 3, 4, 5};

    node* head = NULL;

    arrToList(num, 5, head);
    display(head);

    return 0;
}

