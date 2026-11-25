#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int appNo;
    string name;
    Node *next;

    Node(int a, string n)
    {
        appNo = a;
        name = n;
        next = NULL;
    }
};

class HashTable
{
private:
    static const int SIZE = 10;
    Node *table[SIZE];

    int hash(int key)
    {
        return key % SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    Node *find(int key)
    {
        Node *curr = table[hash(key)];
        while (curr != NULL)
        {
            if (curr->appNo == key)
                return curr;
            curr = curr->next;
        }
        return NULL;
    }

    bool insert(int key, string name)
    {
        if (find(key) != NULL)
        {
            cout << "Application " << key << " already exists. Insertion rejected." << endl;
            return false;
        }

        int index = hash(key);
        Node *newNode = new Node(key, name);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            Node *curr = table[index];
            while (curr->next != NULL)
                curr = curr->next;
            curr->next = newNode;
        }
        return true;
    }

    void search(int key)
    {
        Node *result = find(key);
        if (result != NULL)
            cout << "Found: Application " << result->appNo << " -> " << result->name
                 << " (index " << hash(key) << ")" << endl;
        else
            cout << "Application " << key << " not found" << endl;
    }

    bool remove(int key)
    {
        int index = hash(key);
        Node *curr = table[index];
        Node *prev = NULL;

        while (curr != NULL && curr->appNo != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Cannot remove application " << key << ": not found" << endl;
            return false;
        }

        if (prev == NULL)
        {
            table[index] = curr->next;
            cout << "Removed application " << key << " (first node of chain " << index << ")" << endl;
        }
        else if (curr->next == NULL)
        {
            prev->next = NULL;
            cout << "Removed application " << key << " (last node of chain " << index << ")" << endl;
        }
        else
        {
            prev->next = curr->next;
            cout << "Removed application " << key << " (middle node of chain " << index << ")" << endl;
        }

        delete curr;
        return true;
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "[" << i << "] ";
            Node *curr = table[i];
            if (curr == NULL)
                cout << "EMPTY";
            while (curr != NULL)
            {
                cout << "(" << curr->appNo << ", " << curr->name << ")";
                if (curr->next != NULL)
                    cout << " -> ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable ht;

    int numbers[10] = {27, 37, 17, 42, 52, 62, 34, 44, 54, 24};
    string names[10] = {"Ali", "Sara", "Ahmed", "Hina", "Zain", "Ayesha", "Usman", "Fatima", "Hamza", "Maryam"};

    cout << "--- Inserting records ---" << endl;
    for (int i = 0; i < 10; i++)
        ht.insert(numbers[i], names[i]);
    ht.display();

    cout << endl << "--- Searching 62 and 72 ---" << endl;
    ht.search(62);
    ht.search(72);

    cout << endl << "--- Removing 27 and 54 ---" << endl;
    ht.remove(27);
    ht.remove(54);

    cout << endl << "--- Registering 47 (Daniyal) ---" << endl;
    ht.insert(47, "Daniyal");

    cout << endl << "--- Registering 47 again (duplicate check) ---" << endl;
    ht.insert(47, "Daniyal");

    cout << endl << "--- Searching 37, 54 and 47 ---" << endl;
    ht.search(37);
    ht.search(54);
    ht.search(47);

    cout << endl << "--- Final hash table ---" << endl;
    ht.display();

    cout << endl << "--- Extra deletion checks ---" << endl;
    ht.remove(27);
    ht.remove(24);
    ht.remove(52);
    ht.remove(42);

    cout << endl << "--- Hash table after extra deletions ---" << endl;
    ht.display();

    return 0;
}
