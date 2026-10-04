#include<iostream>
using namespace std;
#include<string>

class node {
    public:
    int id; int level; node* next;

    node(int i=0, int l=0) {
        id=i; level=l; next=nullptr;
    }
};

class linkedList {
    private:
    node* head;
    int count;

    public:
    linkedList() {
        head=nullptr; count=0;
    }

    void addGuard(int i, int L) {
        node* newNode = new node(i, L);
        if (head==nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else {
            node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next=newNode;
            newNode->next = head;
        }
        count++;
    }

    void compareGuards() {
        if (count < 3) {
            return;
        }
        node* prev1 = head;
        while(prev1->next != head) {
            prev1 = prev1->next;
        }
        node* node1 = head;
        
        for (int i=0; i<count; i++) {
            node* node2 = node1->next->next;
            node* prev2= node1->next;
            
            if (node1->level < node2->level) {
                node* temp = node2->next;
                prev1->next = node2;
                node2->next = node1->next;
                prev2->next = node1;
                node1->next = temp;
                if (node1==head) {
                    head = node2;
                }

                prev1 = node2;
                node1 = node2->next;
            }
            else { // no swapped
                prev1 = node1;
                node1 = node1->next;
            }
            
    }


    }

    void display() {
        node* temp=head;
        for (int i=0; i<count; i++) {
            cout << temp->id << " " << temp->level << endl;
            temp = temp->next;
        }
    }
};


int main() {
    linkedList L1;
    L1.addGuard(1, 50);
    L1.addGuard(2, 20);
    L1.addGuard(3, 100);
    L1.addGuard(4, 10);
    L1.display();
    L1.compareGuards();
    L1.display();
}