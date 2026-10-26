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

class DoublyLinkedList
{
private:
    node *head;

public:

    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertNode(int pVal)
    {
        node *newNode = new node();
        newNode->val = pVal;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteNode()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
        }

        // Only one node
        else if (head->next == NULL)
        {
            cout << "Node Deleted: " << head->val << endl;

            delete head;
            head = NULL;
        }

        // More than one node
        else
        {
            node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            cout << "Node Deleted: " << temp->val << endl;

            temp->prev->next = NULL;

            delete temp;
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
        while (currPos < pos && curr != NULL)
        {
            curr = curr->next;
            currPos++;
        }

        // Position does not exist
        if (curr == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        cout << "Node Deleted: " << curr->val << endl;

        // Deleting head
        if (curr == head)
        {
            head = curr->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }
        }

        // Deleting any other node
        else
        {
            curr->prev->next = curr->next;

            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
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

        while (temp != NULL)
        {
            cout << " Node " << i
                 << "(" << temp << ")"
                 << " | Previous = " << setw(8) << temp->prev
                 << " | Data = " << temp->val
                 << " | Next = " << temp->next
                 << endl;

            temp = temp->next;
            i++;
        }
    }

    void PrintInReverse()
    {
        if (head == NULL)
        {
            cout << "List is Empty";
            return;
        }

        node *curr = head;

        // Go to last node
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        // Move backwards
        while (curr != NULL)
        {
            cout << curr->val << " ";
            curr = curr->prev;
        }
    }
};


int main()
{
    DoublyLinkedList link;

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