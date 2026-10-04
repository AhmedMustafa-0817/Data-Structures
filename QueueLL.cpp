#include<iostream>
using namespace std;

class node
{
    public:
    int val;
    node *next;

    node()
    {
        val = 0;
        next = NULL;
    }
};


class LinkedList
{
private:
    node *head; // front of queue pointer
    node *tail; // rear pointer
    int NodeCount;
    int MaxNodes;

public:

    LinkedList(int limit)
    {
        head = NULL;
        tail = NULL;

        NodeCount = 0;
        MaxNodes = limit;
    }


    // Check whether Queue is empty
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }


    // Check whether Queue has reached its maximum limit
    bool isFull()
    {
        if (NodeCount == MaxNodes)
            return true;
        else
            return false;
    }


    // ENQUEUE operation
    void enqueue(int pVal)
    {
        if (isFull())
        {
            cout << endl << "QUEUE is Full";
            return;
        }

        node *newNode = new node();
        newNode->val = pVal;

        // Case 1: Queue is empty
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        // Case 2: Queue already contains nodes
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        NodeCount++;
    }


    // DEQUEUE operation
    void dequeue()
    {
        if (isEmpty())
        {
            cout << endl << "QUEUE is Empty";
        }
        else
        {
            node *temp = head;

            head = head->next;

            cout << endl
                 << "In the result of Dequeue operation "
                 << temp->val
                 << " is extracted from the QUEUE";

            delete temp;

            NodeCount--;

            // If the last node was removed
            if (head == NULL)
            {
                tail = NULL;
            }
        }
    }


    // Display Queue
    void printList()
    {
        if (isEmpty())
        {
            cout << endl << "QUEUE is Empty";
        }
        else
        {
            node *temp = head;

            cout << endl << "QUEUE = ";

            while (temp != NULL)
            {
                cout << temp->val << ",  ";
                temp = temp->next;
            }
        }
    }
};


int main()
{
    LinkedList queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.printList();

    queue.dequeue();

    queue.printList();

    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);

    queue.printList();

    // Queue has reached maximum capacity
    queue.enqueue(70);

    return 0;
}