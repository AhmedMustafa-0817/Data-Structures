#include<iostream>
using namespace std;

class node {
    public:
    node* left; node* right; int data;

    node() {
        left = nullptr; right=nullptr;
    }
};

class BST {
    node* root;

    public:
    BST() {
        root = nullptr;
    }

    void insertNode(node* &current, int val) {
        if (val==0) {
            cout << "cant add";
            return;
        }
        if (current != nullptr) {
            if (current->data == val) {
                insertNode(root, val/2);
            }
            else if (current->data > val) {
                insertNode(current->left, val);
            }
            else if (current->data < val) {
                insertNode(current->right, val);
            }
        }
        else if (current ==nullptr) {
            node* newNode = new node();
            newNode->data = val;
            current = newNode;
            if (root == nullptr) {  // this becomes invalid cuz root will be assigned automatically
                root = current;
            }
        }
        return; 
    }

    void insert(int val) {
        insertNode(root, val);
    }
};

int main() {
    BST T;
    T.insert(10);
    T.insert(5);
    T.insert(8);
    T.insert(2);
    T.insert(8);
}