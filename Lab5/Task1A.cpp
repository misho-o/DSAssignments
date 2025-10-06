#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
//TASK 1:A
struct node{
	
	int value;
	node *next;
	
};

class linkedList{
	private:
		node *head;
	public:
		linkedList(){
			head = NULL;
			
		}	
		
		node* getHead(){
			return head;
		}
		
		void addnode(){
			int x;
			cout<<"ENTER VALUE:";
			cin>>x;
			node *n = new node;
			n->value = x;
			n->next = NULL;
			
			node *temp = head;
			if (head==NULL){
				head = n;
				cout<<"node added to head"<<endl;
				return;
			}else{
				while(temp->next!=NULL){
				
				temp = temp->next;
				}
				temp->next = n;
				cout<<"node added"<<endl;
			}
			
			
						
		}
		
		
		
		void printRec(node *head){
			
			node *temp = head;
			if(temp==NULL){
				return;
			}
			printRec(temp->next);
			cout<<temp->value<<"->";
			
		}	
};

int main(int argc, char** argv) {
	
	
	linkedList list;
	list.addnode();
	list.addnode();
	list.addnode();
	node *head = list.getHead();
	
	
	list.printRec(head);
	return 0;
}
