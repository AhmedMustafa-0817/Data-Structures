#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* left;
    Node* right;
    int height;
    Node(int r) {
        roll = r;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    Node* root;
    AVLTree() { root = NULL; }

    int height(Node* n) {
        if (n == NULL) return 0;
        return n->height;
    }

    int max(int a, int b) { return (a > b) ? a : b; }

    int getBalance(Node* n) {
        if (n == NULL) return 0;
        return height(n->left) - height(n->right);
    }

    Node* rightRotate(Node* y) {
        cout << "  Right rotation at node " << y->roll << endl;
        Node* x = y->left;
        Node* t2 = x->right;
        x->right = y;
        y->left = t2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        cout << "  Left rotation at node " << x->roll << endl;
        Node* y = x->right;
        Node* t2 = y->left;
        y->left = x;
        x->right = t2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* insert(Node* node, int roll) {
        if (node == NULL) {
            cout << "  Placed " << roll << " as a new leaf" << endl;
            return new Node(roll);
        }
        if (roll < node->roll) {
            cout << "  " << roll << " < " << node->roll << ", go left" << endl;
            node->left = insert(node->left, roll);
        } else if (roll > node->roll) {
            cout << "  " << roll << " > " << node->roll << ", go right" << endl;
            node->right = insert(node->right, roll);
        } else {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && roll < node->left->roll)
            return rightRotate(node);
        if (balance < -1 && roll > node->right->roll)
            return leftRotate(node);
        if (balance > 1 && roll > node->left->roll) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && roll < node->right->roll) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void insert(int roll) {
        cout << "Inserting " << roll << ":" << endl;
        root = insert(root, roll);
    }

    void printTree(Node* n, int space) {
        if (n == NULL) return;
        space += 6;
        printTree(n->right, space);
        cout << endl;
        for (int i = 6; i < space; i++) cout << " ";
        cout << n->roll << endl;
        printTree(n->left, space);
    }

    void preorder(Node* n) {
        if (n == NULL) return;
        cout << n->roll << " ";
        preorder(n->left);
        preorder(n->right);
    }

    void inorder(Node* n) {
        if (n == NULL) return;
        inorder(n->left);
        cout << n->roll << " ";
        inorder(n->right);
    }
};

int main() {
    AVLTree tree;
    int rolls[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) tree.insert(rolls[i]);

    cout << "\nAVL tree before inserting 15:";
    tree.printTree(tree.root, 0);
    cout << "\nPreorder: ";
    tree.preorder(tree.root);
    cout << "\nHeight: " << tree.height(tree.root) << endl;

    cout << "\n";
    tree.insert(15);

    cout << "\nAVL tree after inserting 15:";
    tree.printTree(tree.root, 0);
    cout << "\nPreorder: ";
    tree.preorder(tree.root);
    cout << "\nInorder: ";
    tree.inorder(tree.root);
    cout << "\nHeight of AVL tree after inserting 15: " << tree.height(tree.root) << endl;
    return 0;
}
