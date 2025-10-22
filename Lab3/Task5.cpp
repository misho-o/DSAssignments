#include <iostream>
using namespace std;
//TASK 5:
struct Node {
    char data;       
    
    Node* next;
    Node(char val) {
        data = val;
        next = NULL;
    }
};


void insertEnd(Node*& head, char val) {
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


void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
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

bool isPalindrome(Node* head) {
    if (!head || !head->next)
        return true;

    Node* slow = head;
    Node* fast = head;

    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    
    Node* secondHalf = reverseList(slow->next);

    
    Node* firstHalf = head;
    Node* temp = secondHalf;
    bool palindrome = true;

    while (temp) {
        if (firstHalf->data != temp->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    slow->next = reverseList(secondHalf);

    return palindrome;
}

int main() {
    Node* head = NULL;

    char arr[] = {'B', 'O', 'R', 'R', 'O', 'W', 'O', 'R', 'R', 'O', 'B'};

    for (int i =0;i<11;i++){
    	insertEnd(head, arr[i]);
	}
        

    cout << "Linked List:\n";
    display(head);

    if (isPalindrome(head))
        cout << "\nLinked List is a Palindrome.\n";
    else
        cout << "\nLinked List is NOT a Palindrome.\n";

    return 0;
}
