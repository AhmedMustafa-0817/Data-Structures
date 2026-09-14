#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertBack(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeDuplicates()
    {
        Node* current = head;

        while (current != nullptr)
        {
            Node* previous = current;
            Node* runner = current->next;

            while (runner != nullptr)
            {
                if (runner->data == current->data)
                {
                    previous->next = runner->next;

                    if (runner == tail)
                        tail = previous;

                    delete runner;

                    runner = previous->next;
                }
                else
                {
                    previous = runner;
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        cout << "List: ";

        while (temp != nullptr)
        {
            cout << temp->data;

            if (temp->next != nullptr)
                cout << " -> ";

            temp = temp->next;
        }

        cout << "\n";
        cout << "Head: " << head->data << "\n";
        cout << "Tail: " << tail->data << "\n";
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
    }

    ~SinglyLinkedList()
    {
        clear();
    }
};

int main()
{
    SinglyLinkedList list;

    int n;

    cout << "Enter number of values: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;

        cout << "Enter value: ";
        cin >> value;

        list.insertBack(value);
    }

    cout << "\nBefore removing duplicates:\n";
    list.display();

    list.removeDuplicates();

    cout << "\nAfter removing duplicates:\n";
    list.display();

    return 0;
}