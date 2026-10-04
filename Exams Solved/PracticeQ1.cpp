#include<iostream>
using namespace std;
#include<string>

// max waiting area space = 10
// max tickets = 10
const int MAX = 10;

class person {
    public:
    int tickets;
    static int id;
    int ID;

    person(int t) {
        id++;
        ID=id;
        tickets=t;
    }
};
int person::id = 0;

class watingQueue {
    person* area[MAX];
    int front;
    int rear;
    int num;

    public:
    watingQueue() {
        front = -1; rear = -1; num=0;
        for(int i=0; i<MAX; i++) {
            area[i] = nullptr;
        }
    }

    void addToQueue(int tickets) {
        if ((rear+1)%MAX == front) {
            cout << "full";
            return;
        }
        if (front==-1) {
            front = 0;
        }
        person* temp = new person(tickets);
        rear = (rear+1)%MAX;
        area[rear] = temp;
        num++;
    }

    int removeFromQueue() {
        if (front==-1) {
            cout << "empty queue" ; return 0;
        }
        int val = area[front]->tickets;
        area[front]=nullptr;
        if (front==rear) { // last person removed
            front=-1; rear=-1;
        }
        else {
            front = (front+1)%MAX;
        }
        num--;
        return val;
    }

    void display() {
        cout << "customer at front : " << area[front]->ID;
        cout << "\ncustomer at rear : " << area[rear]->ID;
        cout << "\nnum = " << num << endl;
    }

    void serve() {
        int val = removeFromQueue();
        if (val==0) { 
            cout << "no waiting list\n";
        }
        else {
            if (val>MAX) {
                cout << "requested number of tickets is unavailable\n";
            }
            else {
                cout << "served\n";
            }
        }
    }

};


int main() {
    watingQueue Q;
    Q.addToQueue(20);
    Q.addToQueue(3);
    Q.addToQueue(8);
    Q.addToQueue(12);
    Q.display();
    Q.removeFromQueue();
    Q.serve();
    Q.serve();
    Q.serve();
    Q.removeFromQueue();
}