#include<iostream>
using namespace std;
#include<string>

class node {
    public:
    string sName;
    string sArtist;
    node* next;
    node* prev;

    node(string name="", string artist="") {
        sName = name; sArtist = artist;
    }
};

class PList {
    private:
    node* head;
    node* tail;
    int count;

    public:
    PList() {
        head=nullptr; tail=nullptr; count=0;
    }

    void removeSong(int position) {
        if (count == 0) {
            cout << "no node to remove";
            return;
        }
        if (position<1 || position>count) {
            cout << "pos out of range";
            return;
        }

        if (count ==1 && position==1) {
            node* temp = head;
            delete temp;
            head=nullptr; tail=nullptr;
        }
        int index = 0;
        node* temp = head;
        node* Ptemp = tail;
        while(index < position) {
            Ptemp = temp;
            temp = temp->next;
            index++;
        }
        if(temp==head) {
            head = temp->next;
        }
        if (temp==tail) {
            tail = Ptemp;
        }
        Ptemp->next = temp->next;
        temp->next->prev = Ptemp;
        delete temp;
    }

    void display() {
        if (head == NULL) {
        cout << "List is empty " << endl;
        return; 
        }
        node* temp = head;
        do {
        cout << temp->sName << " " << temp->sArtist << " ";
        temp = temp->next;
        } while (temp != head);
        cout << endl; 
    } 

    ~PList() { 
        node *temp = head;
        while (temp != NULL) {
        node *current = temp;
        temp = temp->next;
        delete current; }
        head = NULL;
        tail = NULL;
        count = 0; 
    }
};

int main() {
    PList myList();
    myList.display();
    myList.removeSong(3);
    myList.display();
    return 0;
}