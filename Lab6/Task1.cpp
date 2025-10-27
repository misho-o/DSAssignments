#include <iostream>
#include <string>
using namespace std;


struct node{
	string value;
	node* next;
	
	node(){
		value ="";
		next = NULL;
	}
};



class Stack{
	node* head;
	node* top;

	
	public:
		Stack(){
			head = NULL;
			top = NULL;
		}
		void push(string value){
			
			node* newNode = new node;
			newNode->value = value;
			
			if(top == NULL){
				head = newNode;
				top = newNode;
				cout<<"==ADDED FIRST NODE=="<<endl;
				
				return;
			}
			//if top aint null then add newNode to top next and make that top
			
			node* temp = head;
	
			head = newNode;
			head->next = temp;
			cout<<"ADDED NEW NODE TO TOP"<<endl;
		}
		
		
		void pop(){
			
			if(head==NULL){
				cout<<"==STACK UNDERFLOW=="<<endl;
				return;
			}
			
			if(head->next ==NULL){
				head = NULL;
				top = NULL;
				
				cout<<"==STACK EMPTY==";
				return;
				
			}
			node* temp = head;
			head = head->next;
			top = head;
			delete temp;
			cout<<"==POPPED AN ELEMENT=="<<endl;
			}
			
			
		void display(){
			node* temp = head;
			while(temp != NULL){
				cout<<temp->value<<endl;
				temp= temp->next;
			}
		}	
	
		};

int main() {
    
	Stack st;
	st.push("first");
	st.push("second");
	st.push("third");
	st.push("fouth");
	st.push("last");

	st.display();
	cout<<"AFTER POPPING: "<<endl;
	st.pop();
	
	st.display();
    return 0;
}

