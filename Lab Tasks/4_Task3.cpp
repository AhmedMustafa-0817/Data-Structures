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

    void rearrange()
    {
        Node* evenHead = nullptr;
        Node* evenTail = nullptr;

        Node* oddHead = nullptr;
        Node* oddTail = nullptr;

        Node* current = head;

        while (current != nullptr)
        {
            Node* nextNode = current->next;
            current->next = nullptr;

            if (current->data % 2 == 0)
            {
                if (evenHead == nullptr)
                {
                    evenHead = current;
                    evenTail = current;
                }
                else
                {
                    evenTail->next = current;
                    evenTail = current;
                }
            }
            else
            {
                if (oddHead == nullptr)
                {
                    oddHead = current;
                    oddTail = current;
                }
                else
                {
                    oddTail->next = current;
                    oddTail = current;
                }
            }

            current = nextNode;
        }

        if (evenHead == nullptr)
        {
            head = oddHead;
            tail = oddTail;
        }
        else
        {
            head = evenHead;
            evenTail->next = oddHead;

            if (oddHead == nullptr)
                tail = evenTail;
            else
                tail = oddTail;
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

    cout << "\nBefore rearrangement:\n";
    list.display();

    list.rearrange();

    cout << "\nAfter rearrangement:\n";
    list.display();

    return 0;
}