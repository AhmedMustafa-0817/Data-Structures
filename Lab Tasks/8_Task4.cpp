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
    int nodes;

    Node* insert(Node* r, int x, int depth) {
        if (r == NULL) {
            cout << x << " inserted at depth " << depth << "\n";
            nodes++;
            return new Node(x);
        }

        if (x < r->data) r->left = insert(r->left, x, depth + 1);
        else if (x > r->data) r->right = insert(r->right, x, depth + 1);

        return r;
    }

    bool search(Node* r, int x) {
        if (r == NULL) return false;
        if (r->data == x) return true;
        if (x < r->data) return search(r->left, x);
        return search(r->right, x);
    }

    Node* findMin(Node* r) {
        while (r->left != NULL)
            r = r->left;
        return r;
    }

    Node* removeSuccessor(Node* r, int x) {
        if (r->data == x) {
            Node* temp = r->right;
            delete r;
            return temp;
        }

        r->left = removeSuccessor(r->left, x);
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
            nodes--;

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

            Node* temp = findMin(r->right);
            int succ = temp->data;

            cout << x << " depth " << depth << ", two children, replaced by " << succ << "\n";
            kinds[2]++;

            r->data = succ;
            r->right = removeSuccessor(r->right, succ);
        }

        return r;
    }

    Node* findLCA(Node* r, int a, int b) {
        if (r == NULL) return NULL;

        if (a < r->data && b < r->data)
            return findLCA(r->left, a, b);

        if (a > r->data && b > r->data)
            return findLCA(r->right, a, b);

        return r;
    }

    void kthLargest(Node* r, int k, int& count, int& ans) {
        if (r == NULL) return;

        kthLargest(r->right, k, count, ans);

        count++;

        if (count == k) {
            ans = r->data;
            return;
        }

        if (count < k)
            kthLargest(r->left, k, count, ans);
    }

    void postorder(Node* r) {
        if (r == NULL) return;

        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
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
        nodes = 0;

        for (int i = 0; i < 3; i++)
            kinds[i] = 0;
    }

    void insert(int x) {
        root = insert(root, x, 0);
    }

    void del(int x) {
        root = remove(root, x, 0);
    }

    void LCA(int a, int b) {
        if (!search(root, a) || !search(root, b)) {
            cout << "LCA " << a << " " << b << ": LCA not possible\n";
            return;
        }

        Node* ans = findLCA(root, a, b);

        cout << "LCA " << a << " " << b << " = " << ans->data << "\n";
    }

    void KTH(int k) {
        int count = 0;
        int ans = -1;

        if (k <= 0 || k > nodes) {
            cout << "KTH " << k << " = none\n";
            return;
        }

        kthLargest(root, k, count, ans);

        cout << "KTH " << k << " = " << ans << "\n";
    }

    void display() {
        cout << "Postorder: ";
        postorder(root);

        cout << "\nHeight " << height(root);
        cout << "\nNodes " << nodes;

        cout << "\nDeletion kinds: no child " << kinds[0]
             << ", one child " << kinds[1]
             << ", two children " << kinds[2] << "\n";
    }
};

int main() {
    BST t;

    int arr[] = {50, 25, 75, 10, 35, 60, 90, 5, 30, 40, 55, 65};

    for (int i = 0; i < 12; i++)
        t.insert(arr[i]);

    cout << "\n";

    t.LCA(30, 40);
    t.LCA(5, 40);
    t.LCA(55, 90);
    t.LCA(30, 99);

    cout << "\n";

    t.insert(62);
    t.del(75);
    t.KTH(3);
    t.del(25);
    t.KTH(8);
    t.del(5);
    t.del(35);

    cout << "\n";

    t.display();

    return 0;
}