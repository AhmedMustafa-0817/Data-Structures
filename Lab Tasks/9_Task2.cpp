#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) {
        key = k;
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

    void updateHeight(Node* n) {
        n->height = 1 + max(height(n->left), height(n->right));
    }

    int getBalance(Node* n) {
        if (n == NULL) return 0;
        return height(n->left) - height(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;
        x->right = y;
        y->left = t2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;
        y->left = x;
        x->right = t2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int key) {
        if (node == NULL) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        updateHeight(node);
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void insert(int key) { root = insert(root, key); }

    void leftRotateRoot() {
        if (root != NULL && root->right != NULL)
            root = leftRotate(root);
    }

    void printTree(Node* n, int space) {
        if (n == NULL) return;
        space += 6;
        printTree(n->right, space);
        cout << endl;
        for (int i = 6; i < space; i++) cout << " ";
        cout << n->key << endl;
        printTree(n->left, space);
    }

    void preorder(Node* n) {
        if (n == NULL) return;
        cout << n->key << " ";
        preorder(n->left);
        preorder(n->right);
    }

    void inorder(Node* n) {
        if (n == NULL) return;
        inorder(n->left);
        cout << n->key << " ";
        inorder(n->right);
    }

    void display() {
        printTree(root, 0);
        cout << "\nPreorder: ";
        preorder(root);
        cout << "\nInorder: ";
        inorder(root);
        cout << "\nRoot: " << root->key << ", Height: " << height(root) << endl;
    }
};

int main() {
    AVLTree tree;
    int values[7] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) tree.insert(values[i]);

    cout << "Initial AVL tree:";
    tree.display();

    tree.insert(55);
    cout << "\nAfter inserting 55:";
    tree.display();

    tree.leftRotateRoot();
    cout << "\nAfter left rotation on root:";
    tree.display();
    return 0;
}
