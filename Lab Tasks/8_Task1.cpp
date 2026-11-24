#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *left;
        node *right;

        node()
        {
            data = 0;
            left = NULL;
            right = NULL;
        }
};

class BinarySearchTree
{
    private:
        node *root;
        int rejectedInsertions;

        node* InsertNewNode(node *current, int pData, int depth, int &insertedDepth)
        {
            if(current == NULL)
            {
                node *newNode = new node();
                newNode->data = pData;
                insertedDepth = depth;
                return newNode;
            }

            if(pData == current->data)
            {
                insertedDepth = -1;
                return current;
            }
            else if(pData < current->data)
            {
                current->left = InsertNewNode(current->left, pData, depth + 1, insertedDepth);
            }
            else
            {
                current->right = InsertNewNode(current->right, pData, depth + 1, insertedDepth);
            }

            return current;
        }

        void Inorder(node *current)
        {
            if(current != NULL)
            {
                Inorder(current->left);
                cout << current->data << " ";
                Inorder(current->right);
            }
        }

        void Postorder(node *current)
        {
            if(current != NULL)
            {
                Postorder(current->left);
                Postorder(current->right);
                cout << current->data << " ";
            }
        }

        int CountNodes(node *current)
        {
            if(current == NULL)
                return 0;

            return 1 + CountNodes(current->left) + CountNodes(current->right);
        }

        int TreeHeight(node *current)
        {
            if(current == NULL)
                return -1;

            int leftHeight = TreeHeight(current->left);
            int rightHeight = TreeHeight(current->right);

            if(leftHeight > rightHeight)
                return leftHeight + 1;
            return rightHeight + 1;
        }

    public:
        BinarySearchTree()
        {
            root = NULL;
            rejectedInsertions = 0;
        }

        void InsertNode(int pData)
        {
            int insertedDepth = -1;
            root = InsertNewNode(root, pData, 0, insertedDepth);

            if(insertedDepth == -1)
            {
                cout << pData << " duplicate, rejected" << endl;
                rejectedInsertions++;
            }
            else
            {
                cout << pData << " inserted at depth " << insertedDepth << endl;
            }
        }

        void SearchNode(int pData)
        {
            node *current = root;
            cout << "SEARCH " << pData << ": path ";

            while(current != NULL)
            {
                cout << current->data;

                if(current->data == pData)
                {
                    cout << ", found" << endl;
                    return;
                }

                cout << " ";
                if(pData < current->data)
                    current = current->left;
                else
                    current = current->right;
            }

            cout << ", not found" << endl;
        }

        void PrintTraversals()
        {
            cout << "Inorder: ";
            Inorder(root);
            cout << endl;

            cout << "Postorder: ";
            Postorder(root);
            cout << endl;
        }

        void PrintStatistics()
        {
            cout << "Nodes " << CountNodes(root)
                 << ", Height " << TreeHeight(root)
                 << ", Rejected " << rejectedInsertions << endl;
        }
};

int main()
{
    BinarySearchTree tree;

    // Insert the initial product codes in the given order.
    tree.InsertNode(50);
    tree.InsertNode(30);
    tree.InsertNode(70);
    tree.InsertNode(20);
    tree.InsertNode(40);
    tree.InsertNode(60);
    tree.InsertNode(80);

    // Perform the operations in the given order.
    tree.InsertNode(65);
    tree.InsertNode(35);
    tree.InsertNode(60);
    tree.InsertNode(90);
    tree.SearchNode(35);
    tree.SearchNode(75);
    tree.SearchNode(65);

    tree.PrintTraversals();
    tree.PrintStatistics();

    return 0;
}
