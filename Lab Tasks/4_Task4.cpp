#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
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
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool deleteAtPosition(int position)
    {
        if (position < 1 || head == nullptr)
            return false;

        Node* current = head;

        for (int i = 1; i < position && current != nullptr; i++)
            current = current->next;

        if (current == nullptr)
            return false;

        if (current->prev != nullptr)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next != nullptr)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete current;

        return true;
    }

    void displayForward()
    {
        cout << "Forward: ";

        Node* temp = head;

        while (temp != nullptr)
        {
            cout << temp->data;

            if (temp->next != nullptr)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << "\n";
    }

    void displayBackward()
    {
        cout << "Backward: ";

        Node* temp = tail;

        while (temp != nullptr)
        {
            cout << temp->data;

            if (temp->prev != nullptr)
                cout << " <-> ";

            temp = temp->prev;
        }

        cout << "\n";
    }

    void verifyPointers()
    {
        bool correct = true;

        Node* current = head;

        if (head != nullptr && head->prev != nullptr)
            correct = false;

        if (tail != nullptr && tail->next != nullptr)
            correct = false;

        while (current != nullptr)
        {
            if (current->next != nullptr &&
                current->next->prev != current)
            {
                correct = false;
            }

            if (current->prev != nullptr &&
                current->prev->next != current)
            {
                correct = false;
            }

            current = current->next;
        }

        if (correct)
            cout << "Pointer verification: Correct\n";
        else
            cout << "Pointer verification: Incorrect\n";
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

    ~DoublyLinkedList()
    {
        clear();
    }
};

int main()
{
    DoublyLinkedList list;

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

    cout << "\nOriginal list:\n";
    list.displayForward();
    list.displayBackward();

    int position;

    cout << "\nEnter position to delete: ";
    cin >> position;

    if (list.deleteAtPosition(position))
    {
        cout << "\nAfter deletion:\n";
        list.displayForward();
        list.displayBackward();
        list.verifyPointers();
    }
    else
    {
        cout << "Invalid position\n";
    }

    return 0;
}