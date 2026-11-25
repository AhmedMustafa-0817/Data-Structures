#include <iostream>
using namespace std;

enum Status
{
    EMPTY,
    OCCUPIED,
    DELETED
};

class HashTable
{
private:
    static const int SIZE = 11;
    int keys[SIZE];
    Status status[SIZE];

    int probe(int key, int i)
    {
        return (key % SIZE + i * i) % SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            keys[i] = -1;
            status[i] = EMPTY;
        }
    }

    int search(int key)
    {
        for (int i = 0; i < SIZE; i++)
        {
            int index = probe(key, i);
            if (status[index] == EMPTY)
                return -1;
            if (status[index] == OCCUPIED && keys[index] == key)
                return index;
        }
        return -1;
    }

    void insert(int key)
    {
        int firstDeleted = -1;
        int firstEmpty = -1;

        for (int i = 0; i < SIZE; i++)
        {
            int index = probe(key, i);

            if (status[index] == OCCUPIED && keys[index] == key)
            {
                cout << "Transaction " << key << " already exists at index " << index
                     << ". Duplicate rejected." << endl;
                return;
            }

            if (status[index] == DELETED && firstDeleted == -1)
                firstDeleted = index;

            if (status[index] == EMPTY)
            {
                firstEmpty = index;
                break;
            }
        }

        int target = (firstDeleted != -1) ? firstDeleted : firstEmpty;

        if (target == -1)
        {
            cout << "Table is full. Cannot insert " << key << endl;
            return;
        }

        keys[target] = key;
        status[target] = OCCUPIED;
        cout << "Inserted " << key << " at index " << target;
        if (target == firstDeleted)
            cout << " (reused deleted slot)";
        cout << endl;
    }

    void remove(int key)
    {
        int index = search(key);
        if (index == -1)
        {
            cout << "Cannot remove " << key << ": not found" << endl;
            return;
        }
        status[index] = DELETED;
        cout << "Transaction " << key << " expired and removed from index " << index << endl;
    }

    void find(int key)
    {
        int index = search(key);
        if (index != -1)
            cout << "Transaction " << key << " found at index " << index << endl;
        else
            cout << "Transaction " << key << " not found (unsuccessful search)" << endl;
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "[" << i << "] ";
            if (status[i] == OCCUPIED)
                cout << keys[i] << "  (OCCUPIED)";
            else if (status[i] == DELETED)
                cout << "---  (DELETED)";
            else
                cout << "---  (NEVER USED)";
            cout << endl;
        }
    }
};

int main()
{
    HashTable ht;

    cout << "--- 1. Inserting transactions ---" << endl;
    int codes[6] = {22, 33, 44, 55, 66, 77};
    for (int i = 0; i < 6; i++)
        ht.insert(codes[i]);

    cout << endl << "--- 2. Searching 55 and 77 ---" << endl;
    ht.find(55);
    ht.find(77);

    cout << endl << "--- 3. Expiring 33 ---" << endl;
    ht.remove(33);

    cout << endl << "--- 4. Searching 66 again ---" << endl;
    ht.find(66);

    cout << endl << "--- 5. Registering 88 ---" << endl;
    ht.insert(88);

    cout << endl << "--- 6. Registering 55 again ---" << endl;
    ht.insert(55);

    cout << endl << "--- 7. Removing 44 ---" << endl;
    ht.remove(44);

    cout << endl << "--- 8. Registering 99 ---" << endl;
    ht.insert(99);

    cout << endl << "--- 9. Final hash table ---" << endl;
    ht.display();

    return 0;
}
