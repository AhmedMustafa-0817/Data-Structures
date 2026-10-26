#include<iostream>
#include<iomanip>
using namespace std;

class node
{
public:
    int val;
    node *next, *prev;

    node()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
};

class CircularLinkedList
{
private:
    node *head;

public:

    CircularLinkedList()
    {
        head = NULL;
    }

    void insertNode(int pVal)
    {
        node *newNode = new node();
        newNode->val = pVal;

        // Empty list
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            node *temp = head;

            // Find last node
            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void deleteNode()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
        }

        // Only one node
        else if (head->next == head)
        {
            cout << "Node Deleted: " << head->val << endl;

            delete head;
            head = NULL;
        }

        // More than one node
        else
        {
            node *last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            cout << "Node Deleted: " << last->val << endl;

            node *pre = last->prev;

            pre->next = head;
            head->prev = pre;

            delete last;
        }
    }

    void deletePosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

        node *curr = head;
        int currPos = 0;

        // Find position
        while (currPos < pos)
        {
            curr = curr->next;
            currPos++;

            if (curr == head)
            {
                cout << "Invalid Position" << endl;
                return;
            }
        }

        // Only one node
        if (curr->next == curr)
        {
            cout << "Node Deleted: " << curr->val << endl;

            delete curr;
            head = NULL;
            return;
        }

        cout << "Node Deleted: " << curr->val << endl;

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        // If deleting head
        if (curr == head)
        {
            head = curr->next;
        }

        delete curr;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        node *temp = head;
        int i = 0;

        cout << "Linked List:" << endl;
        cout << "Head Pointer = " << head << endl;

        do
        {
            cout << " Node " << i
                 << "(" << temp << ")"
                 << " | Previous = " << setw(8) << temp->prev
                 << " | Data = " << temp->val
                 << " | Next = " << temp->next
                 << endl;

            temp = temp->next;
            i++;

        } while (temp != head);
    }

    void PrintInReverse()
    {
        if (head == NULL)
        {
            cout << "List is Empty";
            return;
        }

        node *curr = head->prev;   // last node

        do
        {
            cout << curr->val << " ";
            curr = curr->prev;

        } while (curr != head->prev);
    }
};


int main()
{
    CircularLinkedList link;

    link.insertNode(10);
    link.insertNode(20);
    link.insertNode(30);

    link.printList();

    // link.deleteNode();
    // link.printList();

    // link.deletePosition(1);
    // link.printList();

    cout << endl << "Print linked list in Reverse order: ";
    link.PrintInReverse();

    return 0;
}