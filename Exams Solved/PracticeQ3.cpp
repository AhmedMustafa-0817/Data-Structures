#include<iostream>
using namespace std;
#include<string>

class node {
    public:
    int id; int score; node* next; node* prev; int examined;

    node() {
        id=0; score=0; next=nullptr; prev=nullptr; examined=0;
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

    void addNode(int id, int score) {
        node* newNode = new node();
        newNode->id = id;
        newNode->id = score;
        if (head== nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        node* temp = head;
        while(temp->next!=head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
        count ++;
    }

    void deleteNode(int id) {
        if (head==nullptr) {
            return;
        }
        if (head->next == head && head->id == id) {
            delete head;
            head = nullptr;
            return ;
        }
        node* temp = head;
        while(temp->next != head) {
            if (temp->id == id) {
                break;
            }
            else {
                temp = temp->next;
            }
        }
        if (temp==head) {
            head = temp->next;
        }
        node* pre = temp->prev;
        pre->next = temp->next;
        temp->next->prev = pre;
        delete temp;
    }

    void examination() {
        node* temp = head;
        while(head->next != head) {
            temp->examined+=1;
            node* T = temp;
            if (temp->score%2 == 0) {
                temp = temp->next->next;
            }
            else {
                temp = temp->prev->prev;
            }
            if (temp->examined>=3) {
                
                deleteNode(T->id);
            }
        }
        cout << endl << head->id;
    }
};

int main() {
    linkedList list;

    // Adding participants (ID, Score)
    list.addNode(1, 4);
    list.addNode(2, 3);
    list.addNode(3, 8);
    list.addNode(4, 5);

    list.examination();

    return 0;
}