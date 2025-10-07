#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
//TASK 1:b
//Insert the node in doubly linked list at any position, and display the nodes after that delete the node at any position and again display the updated list.
int static nodes = 0;
struct node {
	int value;
	node* prev;
	node* next;

	node(int val = 0) {
		nodes++;
		value = val;
		prev = NULL;
		next = NULL;
		cout << "EXISTING NODES: " << nodes << endl;
	}
};

class doublyList {
private:
	node* head; //simply a nodeP with no node in it
public:
	doublyList() {
		head = NULL;
	}

	void display() {
		node* temp = head;

		while (temp != NULL) {
			cout << temp->value << "->";
			temp = temp->next;
		}
		cout << "\n";
	}
	void insertFromLast() {

		node* temp = head;

		int x;
		cout << "ENTER VALUE: ";
		cin >> x;
		node *n = new node;
		n->value = x;

		//if head is empty then assign an new node as head
		if (head == NULL) {
			head = n;

			cout << "VALUE INSERTED AT HEAD" << endl;
			return;
		}

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
		n->prev = temp;
		n->value = x;

		cout << "NODE ADDED!" << endl;
		display();
	}
	void deleteAtPos() {
		int pos;

		cout << "ENTER NODE POSITION YOU WANT TO DELETE " << "CHOOSE FROM 1-" << nodes << endl;
		cin >> pos;

		//check if pos valid
		if (!validPos) {
			return;
		}
		node* temp = head;
		for (int i = 1; i <= nodes; i++) {
			cout << "CURRENTLY ON NODE " << i << endl;
			if (i == pos) {
				node* back = temp->prev;
				node* forward = temp->next; //if forward null then last node

				if (temp->prev == NULL) {

					forward->prev = NULL;
					cout << "NODE REMOVED FROM HEAD" << endl;
					delete temp;
					nodes--;
					display();
					return;
				}
				//if the node is last

				if (temp->next == NULL) {
					back->next = NULL;
					delete temp;
					nodes--;
					cout << "NODE REMOVED FROM LAST POS" << endl;
					display();
					return;
				}


				back->next = forward;
				forward->prev = back;

				delete temp;
				nodes--;
				cout << "NODE REMOVED AT POSITION " << pos << endl;
				display();
				return;
			}
			cout << "MOVING TO NEXT NODE..." << endl;
			temp = temp->next;


		}

	}
	bool validPos(int pos,int nodes) {
		if (pos <= nodes && pos >= 1) {
			cout << "position exists" << endl;
			cout << "ENTER VALUE:" << endl;
			cin >> x;
			return true;
		}
		else {
			cout << "position DOESNT exists" << endl;

			return false;
		}
	}
	void insertAtPos() {
		int pos;
		int x;
		cout << "ENTER NODE POSITION YOU WANT TO ADD A NEW NODE TO " << "CHOOSE FROM 1-" << nodes << endl;
		cin >> pos;

		if (!validPos) {
			return;
		}
		
		node* temp = head;

		node* n = new node;
		n->value = x;

		for (int i = 1; i <= pos; i++) {
			cout << "CURRENTLY ON NODE " << i << endl;
			if (i == pos) {

				if (temp->prev == NULL) {
					n->next = temp;
					n->prev = NULL;
					temp->prev = n;
					head = n;  // very important
					cout << "NODE INSERTED AT HEAD" << endl;
					display();
					return;
				}

				// inserting in middle or end
				node* backTemp = temp->prev;
				backTemp->next = n;
				n->prev = backTemp;
				n->next = temp;
				temp->prev = n;

				cout << "NODE ADDED AT POSITION " << pos << endl;
				display();
				return;
			}
			cout << "MOVING TO NEXT NODE..." << endl;
			temp = temp->next;


		}

	}
};


int main(int argc, char** argv) {

	doublyList list;

	list.insertFromLast();
	list.insertFromLast();
	list.insertFromLast();
	list.insertAtPos();
	list.deleteAtPos();
	return 0;
}