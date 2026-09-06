#include<iostream>

using namespace std;

class node{
	public:
		int val;
		node *next;
		node(){
			val = 0;
			next = NULL;
		}
};

class LinkedList{
	private: 
		node *head;
		
	public:
		LinkedList()
		{ head = NULL; }
		
		void insertNode(int pVal)
		{
			cout<<endl<<"Insert Nodde Function Call";
			node *newNode = new node();
			newNode->val = pVal;

			if (head == NULL)
				{ head = newNode; }
			else
			{
				node *temp = head;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}
				
		void deleteNode(){
			cout<<endl<<"Delete Node Function Call"<<endl;
			if (head == NULL)
				{  cout<<"List is Empty"<<endl; }
			
			else if (head->next == NULL)
			{
				cout<<"Node Deleted: "<<head->val<<endl;
				
				delete(head);
				head = NULL;
			}
			else{
				node *temp = head;
				while (temp->next->next != NULL) 
				{
					temp = temp->next;
				}
				cout<<"Node Deleted: "<<temp->next->val<<endl;
				
				delete(temp->next);
				// set the next of 2nd last node to NULL
				temp->next = NULL;
			}					
		
		}
		
		void deletePosition(int pos)
		{
			cout<<endl<<"Delete a Particular Node Function Call"<<endl;
			int currPos = 0;
			if (head == NULL)
			{
				cout<<"List is Empty"<<endl;
			}
			else
			{
				node *pre, *curr;
				if (pos == 0) 
				{
					cout<<"Node Deleted: "<<head->val<<endl;
					curr = head;
					head = head->next;
					delete(curr);
				}
				else
				{
					pre = curr = head;
					while(currPos != pos)
					{
						currPos++; 
						pre = curr;
						curr = curr->next;
					}
					cout<<"Element Deleted: "<<curr->val<<endl;
					pre->next = curr->next;
					//free(ptr);
				}
			}
		}
		
		void printList()
		{
			cout<<endl<<"PrintList Function Call"<<endl;
			if (head == NULL)
			{
				cout<<"List is empty"<<endl;
			}
			else
			{
				node *temp = head;
				cout<<"Linked List: ";
				while (temp != NULL)
				{
					cout<<temp->val<<" ";
					temp = temp->next;
				}
			}
		}	
			
};


int main() {
	LinkedList link;// = new LinkedList();
	link.insertNode(10);
	link.insertNode(20);
	link.insertNode(30);
	
	link.printList();
	link.deleteNode();
	link.printList();
	link.deletePosition(3);
	link.printList();

	return 0;
}
