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
        cout << "Right rotation at " << y->key << endl;
        Node* x = y->left;
        Node* t2 = x->right;
        x->right = y;
        y->left = t2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        cout << "Left rotation at " << x->key << endl;
        Node* y = x->right;
        Node* t2 = y->left;
        y->left = x;
        x->right = t2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int key, bool& rotated) {
        if (node == NULL) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key, rotated);
        else if (key > node->key)
            node->right = insert(node->right, key, rotated);
        else
            return node;

        updateHeight(node);
        int balance = getBalance(node);

        if (balance > 1 || balance < -1) {
            rotated = true;
            cout << "Node " << node->key << " is unbalanced (BF = " << balance << ")" << endl;
        }

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

    void insert(int key) {
        bool rotated = false;
        root = insert(root, key, rotated);
        cout << "Inserted " << key;
        if (rotated) cout << " (rotations applied)";
        else cout << " (tree stays balanced)";
        cout << endl;
    }

    void printBalanceFactors(Node* n) {
        if (n == NULL) return;
        printBalanceFactors(n->left);
        cout << "Node " << n->key << " -> Height: " << n->height
             << ", Balance Factor: " << getBalance(n) << endl;
        printBalanceFactors(n->right);
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
};

int main() {
    AVLTree tree;
    int values[5] = {10, 5, 15, 3, 7};
    for (int i = 0; i < 5; i++) tree.insert(values[i]);

    cout << "\nTree before inserting 12:";
    tree.printTree(tree.root, 0);

    cout << "\nStep 1: Insert 12" << endl;
    tree.insert(12);

    cout << "\nStep 2: Balance factor of each node" << endl;
    tree.printBalanceFactors(tree.root);

    cout << "\nStep 3: Height of tree = " << tree.height(tree.root) << endl;

    cout << "\nStep 4: ";
    if (tree.getBalance(tree.root) >= -1 && tree.getBalance(tree.root) <= 1)
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is unbalanced" << endl;

    cout << "\nStep 5: Final balanced AVL tree:";
    tree.printTree(tree.root, 0);
    cout << "\nPreorder: ";
    tree.preorder(tree.root);
    cout << "\nInorder: ";
    tree.inorder(tree.root);
    cout << endl;
    return 0;
}
