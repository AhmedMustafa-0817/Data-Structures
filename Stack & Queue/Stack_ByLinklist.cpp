#include<iostream>
#include<vector>
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

class LinkedList
{
private:
    node *head;
    int NodeCount;
    int MaxNodes;

public:

    LinkedList(int limit)
    {
        head = NULL;
        NodeCount = 0;
        MaxNodes = limit;
    }

    bool isEmpty()
    {
        return NodeCount == 0;
    }

    bool isFull()
    {
        return NodeCount == MaxNodes;
    }

    void push(int pVal)
    {
        if (isFull())
        {
            cout << endl << "STACK is Full";
            return;
        }

       node *newNode = new node();
       newNode->val = pVal;

       if (head == NULL)
          {
			head = newNode;	        
		  }
	  else 
		 {
			newNode->next = head;
	        head = newNode;
		 }	
        NodeCount++;

        cout << endl << pVal
             << " is pushed into the STACK";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << endl << "STACK is Empty";
            return;
        }

        node *temp = head;
        head = head->next;

        cout << endl << temp->val
             << " is popped from the STACK";

        delete temp;

        NodeCount--;
    }

    void printList()
    {
        if (isEmpty())
        {
            cout << endl << "STACK is Empty";
            return;
        }

        node *temp = head;

        cout << endl << "TOP -> ";

        while (temp != NULL)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
};