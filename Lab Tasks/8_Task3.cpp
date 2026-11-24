#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class BST {
    Node* root;
    int kinds[3];

    Node* insert(Node* r, int x) {
        if (r == NULL) return new Node(x);

        if (x < r->data) r->left = insert(r->left, x);
        else if (x > r->data) r->right = insert(r->right, x);

        return r;
    }

    bool search(Node* r, int x) {
        if (r == NULL) return false;
        if (r->data == x) return true;
        if (x < r->data) return search(r->left, x);
        return search(r->right, x);
    }

    int findFloor(Node* r, int x) {
        int ans = -1;

        while (r != NULL) {
            if (r->data == x) return x;
            if (r->data < x) {
                ans = r->data;
                r = r->right;
            }
            else r = r->left;
        }

        return ans;
    }

    int findCeil(Node* r, int x) {
        int ans = -1;

        while (r != NULL) {
            if (r->data == x) return x;
            if (r->data > x) {
                ans = r->data;
                r = r->left;
            }
            else r = r->right;
        }

        return ans;
    }

    Node* maxNode(Node* r) {
        while (r->right != NULL)
            r = r->right;
        return r;
    }

    Node* remove(Node* r, int x, int depth) {
        if (r == NULL) return NULL;

        if (x < r->data) {
            r->left = remove(r->left, x, depth + 1);
        }
        else if (x > r->data) {
            r->right = remove(r->right, x, depth + 1);
        }
        else {
            if (r->left == NULL && r->right == NULL) {
                cout << x << " depth " << depth << ", no child\n";
                kinds[0]++;
                delete r;
                return NULL;
            }

            if (r->left == NULL || r->right == NULL) {
                cout << x << " depth " << depth << ", one child\n";
                kinds[1]++;

                Node* temp = (r->left != NULL) ? r->left : r->right;
                delete r;
                return temp;
            }

            Node* temp = maxNode(r->left);
            int pred = temp->data;

            cout << x << " depth " << depth << ", two children, replaced by " << pred << " (next smaller)\n";
            kinds[2]++;

            r->data = pred;
            r->left = removePredecessor(r->left, pred);
        }

        return r;
    }

    Node* removePredecessor(Node* r, int x) {
        if (r->data == x) {
            Node* temp = r->left;
            delete r;
            return temp;
        }

        r->right = removePredecessor(r->right, x);
        return r;
    }

    void range(Node* r, int low, int high, int& count, int& sum) {
        if (r == NULL) return;

        if (r->data > low) range(r->left, low, high, count, sum);

        if (r->data >= low && r->data <= high) {
            count++;
            sum += r->data;
        }

        if (r->data < high) range(r->right, low, high, count, sum);
    }

    void preorder(Node* r) {
        if (r == NULL) return;
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(Node* r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    int height(Node* r) {
        if (r == NULL) return -1;

        int l = height(r->left);
        int rr = height(r->right);

        return 1 + ((l > rr) ? l : rr);
    }

public:
    BST() {
        root = NULL;
        for (int i = 0; i < 3; i++)
            kinds[i] = 0;
    }

    void insert(int x) {
        root = insert(root, x);
    }

    void floor(int x) {
        int ans = findFloor(root, x);

        if (ans == -1) cout << "FLOOR " << x << " = none\n";
        else cout << "FLOOR " << x << " = " << ans << "\n";
    }

    void ceil(int x) {
        int ans = findCeil(root, x);

        if (ans == -1) cout << "CEIL " << x << " = none\n";
        else cout << "CEIL " << x << " = " << ans << "\n";
    }

    void del(int x) {
        root = remove(root, x, 0);
    }

    void showRange(int low, int high) {
        int count = 0, sum = 0;
        range(root, low, high, count, sum);

        cout << "RANGE " << low << ".." << high
             << ": count " << count << ", sum " << sum << "\n";
    }

    void display() {
        cout << "Preorder: ";
        preorder(root);

        cout << "\nInorder: ";
        inorder(root);

        cout << "\nHeight " << height(root) << "\n";

        cout << "Deletion kinds: no child " << kinds[0]
             << ", one child " << kinds[1]
             << ", two children " << kinds[2] << "\n";
    }
};

int main() {
    BST t;

    int arr[] = {45, 25, 65, 15, 35, 55, 85, 30, 40, 60, 75, 95};

    for (int i = 0; i < 12; i++)
        t.insert(arr[i]);

    t.floor(58);
    t.ceil(96);
    t.ceil(65);

    t.del(25);
    t.del(65);
    t.del(15);

    t.ceil(65);
    t.showRange(30, 60);

    t.display();

    return 0;
}