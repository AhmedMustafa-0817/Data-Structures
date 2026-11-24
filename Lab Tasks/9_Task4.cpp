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

    int countNodes(Node* n) {
        if (n == NULL) return 0;
        return 1 + countNodes(n->left) + countNodes(n->right);
    }

    Node* kthSmallest(Node* n, int& k) {
        if (n == NULL) return NULL;
        Node* found = kthSmallest(n->left, k);
        if (found != NULL) return found;
        k--;
        if (k == 0) return n;
        return kthSmallest(n->right, k);
    }

    Node* kthLargest(Node* n, int& k) {
        if (n == NULL) return NULL;
        Node* found = kthLargest(n->right, k);
        if (found != NULL) return found;
        k--;
        if (k == 0) return n;
        return kthLargest(n->left, k);
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

    void inorder(Node* n) {
        if (n == NULL) return;
        inorder(n->left);
        cout << n->key << " ";
        inorder(n->right);
    }
};

int main() {
    AVLTree tree;
    int values[10] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 65};
    for (int i = 0; i < 10; i++) tree.insert(values[i]);

    cout << "AVL tree:";
    tree.printTree(tree.root, 0);
    cout << "\nInorder: ";
    tree.inorder(tree.root);
    cout << endl;

    int total = tree.countNodes(tree.root);
    int k;
    cout << "\nEnter k (1 to " << total << "): ";
    cin >> k;

    if (k < 1 || k > total) {
        cout << "Invalid k" << endl;
        return 0;
    }

    int k1 = k;
    Node* small = tree.kthSmallest(tree.root, k1);
    int k2 = k;
    Node* large = tree.kthLargest(tree.root, k2);

    cout << k << "th smallest key: " << small->key << endl;
    cout << k << "th largest key: " << large->key << endl;

    cout << "\nRoot: " << tree.root->key << endl;
    cout << "Left side height: " << tree.height(tree.root->left) << endl;
    cout << "Right side height: " << tree.height(tree.root->right) << endl;
    return 0;
}
