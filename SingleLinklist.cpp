#include<iostream>

using namespace std;

class node {
public:
    int val;
    node *next;
    node() {
        val = 0;
        next = NULL;
    }
};

class LinkedList {
private:
    node *head;

public:
    LinkedList() { 
        head = NULL; 
    }


    void insertNode(int pVal) {
        node *newNode = new node();
        newNode->val = pVal;

        if (head == NULL) { 
            head = newNode; 
        } else {
            node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteNode() {
        if (head == NULL) {  
            cout << "List is Empty" << endl; 
        } else if (head->next == NULL) {
            cout << "Node Deleted: " << head->val << endl;
            delete(head);
            head = NULL;
        } else {
            node *temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            cout << "Node Deleted: " << temp->next->val << endl;
            delete(temp->next);
            temp->next = NULL;
        }
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            node *temp = head;
            cout << "Linked List: ";
            while (temp != NULL) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

	// my funcs HW

    void InsertNode_AtTail(int Val) {
        node *newNode = new node();
        newNode->val = Val;

        if (head == NULL) { 
            head = newNode; 
        } else {
            node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void InsertNode_FromHead(int val) {
        node *newNode = new node();
        newNode->val = val;
        
        newNode->next = head;
        head = newNode; // The head pointer is updated to point to this new node
        
        cout << "Inserted " << val << " at Head." << endl;
    }


    void InsertNode_AtIndex(int val, int index) {
        // Scenario 1: User wants to insert at the very beginning (index 0)
        if (index == 0) {
            InsertNode_FromHead(val);
            return;
        }

        // Scenario 2: Traverse to find the (index - 1) position
        node *temp = head;
        int currentIndex = 0;

        // We stop at the node just BEFORE the target index
        while (temp != NULL && currentIndex < index - 1) {
            temp = temp->next;
            currentIndex++;
        }

        // Scenario 3: If temp is NULL, the index is out of bounds (e.g. index 5 in a 2-node list)
        if (temp == NULL) {
            cout << "Cannot insert at index " << index << ". List is too short!" << endl;
            return;
        }

        // Successfully found the position. Link the new node.
        node *newNode = new node();
        newNode->val = val;
        
        newNode->next = temp->next; // Point new node to the next node
        temp->next = newNode;       // Point the previous node to the new node
        
        cout << "Inserted " << val << " at index " << index << "." << endl;
    }



    void DeleteNode_FromHead() {
        if (head == NULL) {
            cout << "List is already Empty, cannot delete from Head." << endl;
            return;
        }
        
        node *temp = head;      // Store the current head
        head = head->next;      // Move head to the next node
        cout << "Node Deleted from Head: " << temp->val << endl;
        delete(temp);           // Free the memory
    }

    void DeleteNode_AtTail() {
        // This is exactly what the original deleteNode() does. 
        deleteNode();
    }

    void DeleteNode_AtIndex(int index) {
        if (head == NULL) {
            cout << "List is Empty, cannot delete." << endl;
            return;
        }

        // Scenario 1: Deleting the first node (index 0)
        if (index == 0) {
            DeleteNode_FromHead();
            return;
        }

        // Scenario 2: Traverse to find the node BEFORE the target index
        node *temp = head;
        int currentIndex = 0;

        while (temp != NULL && temp->next != NULL && currentIndex < index - 1) {
            temp = temp->next;
            currentIndex++;
        }

        // If temp is NULL or temp->next is NULL, the index is out of bounds
        if (temp == NULL || temp->next == NULL) {
            cout << "Cannot delete at index " << index << ". Index out of bounds!" << endl;
            return;
        }

        // temp->next is the node we want to delete
        node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next; // Bypass the deleted node
        
        cout << "Node Deleted at index " << index << ": " << nodeToDelete->val << endl;
        delete(nodeToDelete); // Free the memory
    }

    void DeleteNode_ByValue(int val) {
        if (head == NULL) {
            cout << "List is Empty. Value not found." << endl;
            return;
        }

        // Scenario 1: The value is at the head node
        if (head->val == val) {
            DeleteNode_FromHead();
            return;
        }

        // Scenario 2: Value is somewhere else. We need to track the current and previous nodes.
        node *temp = head;
        node *prev = NULL;

        while (temp != NULL && temp->val != val) {
            prev = temp;
            temp = temp->next;
        }

        // If temp became NULL, we reached the end without finding the value
        if (temp == NULL) {
            cout << "Value " << val << " not found in the list. Cannot delete." << endl;
            return;
        }

        // Value found. Bypass it and delete.
        prev->next = temp->next;
        cout << "Node with value " << val << " deleted." << endl;
        delete(temp);
    }



    void UpdateNode_AtIndex(int val, int index) {
        node *temp = head;
        int currentIndex = 0;

        // Traverse until we hit the desired index or the end of the list
        while (temp != NULL && currentIndex != index) {
            temp = temp->next;
            currentIndex++;
        }

        // If temp is NULL, the index doesn't exist
        if (temp == NULL) {
            cout << "Update failed. Index " << index << " is out of bounds." << endl;
            return;
        }

        // Otherwise, update the value
        temp->val = val;
        cout << "Node at index " << index << " updated to new value: " << val << endl;
    }

    // Note: I added a second parameter 'newVal' because updating requires knowing 
    // both the old value to search for, and the new value to replace it with.
    void UpdateNode_ByValue(int oldVal, int newVal) {
        node *temp = head;

        // Search for the node containing the old value
        while (temp != NULL && temp->val != oldVal) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Update failed. Value " << oldVal << " not found." << endl;
            return;
        }

        // Found it. Update the value.
        temp->val = newVal;
        cout << "Node with value " << oldVal << " updated to " << newVal << "." << endl;
    }



    void SearchNode_ByValue(int val) {
        node *temp = head;
        int position = 0;
        bool found = false;

        // Traverse the entire list
        while (temp != NULL) {
            if (temp->val == val) {
                cout << "Value " << val << " found at index " << position << "." << endl;
                found = true;
                break; // Stop searching once we find it
            }
            temp = temp->next;
            position++;
        }

        // If the loop finished and found is still false
        if (!found) {
            cout << "Node not exists." << endl;
        }
    }
};

int main() {
    LinkedList link;
    
    // Initial Testing (from original code)
    link.insertNode(10);
    link.insertNode(20);
    link.insertNode(30);
    link.printList();

    cout << "\n--- Testing New Operations ---" << endl;
    
    // Testing Insertions
    link.InsertNode_FromHead(5);         // List: 5, 10, 20, 30
    link.InsertNode_AtIndex(15, 2);      // List: 5, 10, 15, 20, 30
    link.InsertNode_AtIndex(99, 10);     // Out of bounds test
    link.printList();

    // Testing Deletions
    link.DeleteNode_FromHead();          // Removes 5
    link.DeleteNode_AtIndex(2);          // Removes 20
    link.DeleteNode_ByValue(30);         // Removes 30
    link.DeleteNode_ByValue(100);        // Not found test
    link.printList();

    // Testing Updates
    link.UpdateNode_AtIndex(100, 0);     // Updates 10 to 100
    link.UpdateNode_ByValue(15, 500);    // Updates 15 to 500
    link.printList();

    // Testing Search
    link.SearchNode_ByValue(500);        // Should find at index 1
    link.SearchNode_ByValue(999);        // Should say not exists

    return 0;
}