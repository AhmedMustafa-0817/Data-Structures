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

    void insertFront(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        if (tail == nullptr)
            tail = newNode;
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

    bool insertAtPosition(int value, int position)
    {
        if (position < 1)
            return false;

        if (position == 1)
        {
            insertFront(value);
            return true;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr)
            return false;

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr)
            tail = newNode;

        return true;
    }

    bool deleteFront()
    {
        if (head == nullptr)
            return false;

        Node* temp = head;
        head = head->next;

        delete temp;

        if (head == nullptr)
            tail = nullptr;

        return true;
    }

    bool deleteBack()
    {
        if (head == nullptr)
            return false;

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }

        Node* temp = head;

        while (temp->next != tail)
            temp = temp->next;

        delete tail;

        tail = temp;
        tail->next = nullptr;

        return true;
    }

    bool deleteAtPosition(int position)
    {
        if (position < 1 || head == nullptr)
            return false;

        if (position == 1)
            return deleteFront();

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr)
            return false;

        Node* deleteNode = temp->next;

        temp->next = deleteNode->next;

        if (deleteNode == tail)
            tail = temp;

        delete deleteNode;

        return true;
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
        int choice;

        cout << "Enter value: ";
        cin >> value;

        cout << "1. Insert at front\n";
        cout << "2. Insert at back\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            list.insertFront(value);
        else if (choice == 2)
            list.insertBack(value);
        else
            cout << "Invalid choice\n";
    }

    cout << "\nInitial list:\n";
    list.display();

    int choice;

    do
    {
        cout << "\n1. Delete front\n";
        cout << "2. Delete back\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete at position\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (list.deleteFront())
                list.display();
            else
                cout << "List is empty\n";
        }
        else if (choice == 2)
        {
            if (list.deleteBack())
                list.display();
            else
                cout << "List is empty\n";
        }
        else if (choice == 3)
        {
            int value, position;

            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            if (list.insertAtPosition(value, position))
                list.display();
            else
                cout << "Invalid position\n";
        }
        else if (choice == 4)
        {
            int position;

            cout << "Enter position: ";
            cin >> position;

            if (list.deleteAtPosition(position))
                list.display();
            else
                cout << "Invalid position\n";
        }
        else if (choice == 5)
        {
            list.display();
        }

    } while (choice != 6);

    return 0;
}