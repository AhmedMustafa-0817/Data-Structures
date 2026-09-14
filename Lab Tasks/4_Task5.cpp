#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularDoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    CircularDoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertBack(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            newNode->next = newNode;
            newNode->prev = newNode;

            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;

            tail->next = newNode;
            head->prev = newNode;

            tail = newNode;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node* current = head;

        cout << "Circular list: ";

        do
        {
            cout << current->data;

            current = current->next;

            if (current != head)
                cout << " <-> ";

        } while (current != head);

        cout << "\n";
    }

    Node* moveForward(Node* current, int steps)
    {
        for (int i = 0; i < steps; i++)
            current = current->next;

        return current;
    }

    Node* moveBackward(Node* current, int steps)
    {
        for (int i = 0; i < steps; i++)
            current = current->prev;

        return current;
    }

    void clear()
    {
        if (head == nullptr)
            return;

        Node* current = head->next;

        while (current != head)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;

        head = nullptr;
        tail = nullptr;
    }

    ~CircularDoublyLinkedList()
    {
        clear();
    }

    Node* getHead()
    {
        return head;
    }
};

int main()
{
    CircularDoublyLinkedList list;

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

    list.display();

    if (list.getHead() != nullptr)
    {
        Node* current = list.getHead();

        int steps;
        int direction;

        cout << "Enter number of steps: ";
        cin >> steps;

        cout << "1. Forward\n";
        cout << "2. Backward\n";
        cout << "Enter direction: ";
        cin >> direction;

        if (direction == 1)
            current = list.moveForward(current, steps);
        else if (direction == 2)
            current = list.moveBackward(current, steps);
        else
        {
            cout << "Invalid direction\n";
            return 0;
        }

        cout << "Current node: " << current->data << "\n";
        cout << "Next node: " << current->next->data << "\n";
        cout << "Previous node: " << current->prev->data << "\n";
    }

    return 0;
}