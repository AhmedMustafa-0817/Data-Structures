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
    static const int SIZE = 13;
    int keys[SIZE];
    Status status[SIZE];
    int collisions;

    int h1(int key)
    {
        return key % SIZE;
    }

    int h2(int key)
    {
        return 7 - (key % 7);
    }

    int probe(int key, int i)
    {
        return (h1(key) + i * h2(key)) % SIZE;
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

public:
    HashTable()
    {
        collisions = 0;
        for (int i = 0; i < SIZE; i++)
        {
            keys[i] = -1;
            status[i] = EMPTY;
        }
    }

    void insert(int key)
    {
        if (search(key) != -1)
        {
            cout << "Patient " << key << " already registered. Duplicate rejected." << endl;
            return;
        }

        int target = -1;
        int occupiedSeen = 0;

        for (int i = 0; i < SIZE; i++)
        {
            int index = probe(key, i);

            if (status[index] == OCCUPIED)
            {
                occupiedSeen++;
            }
            else
            {
                target = index;
                break;
            }
        }

        if (target == -1)
        {
            cout << "No available position found for patient " << key << endl;
            return;
        }

        keys[target] = key;
        status[target] = OCCUPIED;
        collisions += occupiedSeen;
        cout << "Patient " << key << " stored at index " << target
             << " (collisions: " << occupiedSeen << ")" << endl;
    }

    void find(int key)
    {
        int index = search(key);
        if (index != -1)
            cout << "Patient " << key << " found at index " << index << endl;
        else
            cout << "Patient " << key << " not found" << endl;
    }

    void remove(int key)
    {
        int index = search(key);
        if (index == -1)
        {
            cout << "Cannot remove patient " << key << ": not found" << endl;
            return;
        }
        status[index] = DELETED;
        cout << "Patient " << key << " removed from index " << index << endl;
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
                cout << "---  (EMPTY)";
            cout << endl;
        }
        cout << "Total collisions: " << collisions << endl;
    }
};

int main()
{
    HashTable ht;

    cout << "--- 1. Inserting patients ---" << endl;
    int ids[8] = {18, 31, 44, 57, 70, 83, 96, 109};
    for (int i = 0; i < 8; i++)
        ht.insert(ids[i]);

    cout << endl << "--- 2. Searching 83 and 120 ---" << endl;
    ht.find(83);
    ht.find(120);

    cout << endl << "--- 3. Removing 44 ---" << endl;
    ht.remove(44);

    cout << endl << "--- 4. Registering 135 ---" << endl;
    ht.insert(135);

    cout << endl << "--- 5. Searching 135 and 44 ---" << endl;
    ht.find(135);
    ht.find(44);

    cout << endl << "--- 6. Registering 148 ---" << endl;
    ht.insert(148);

    cout << endl << "--- 7. Registering 83 again ---" << endl;
    ht.insert(83);

    cout << endl << "--- 8. Removing 57 ---" << endl;
    ht.remove(57);

    cout << endl << "--- 9. Final hash table ---" << endl;
    ht.display();

    return 0;
}
