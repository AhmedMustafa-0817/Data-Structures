#include<iostream>
#include<queue>
#include<vector>
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
        int noChildDeletions;
        int oneChildDeletions;
        int twoChildDeletions;

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

        node* MinValueNode(node *current)
        {
            while(current != NULL && current->left != NULL)
                current = current->left;

            return current;
        }

        node* DeleteNode(node *current, int pData)
        {
            if(current == NULL)
                return NULL;

            if(pData < current->data)
                current->left = DeleteNode(current->left, pData);
            else if(pData > current->data)
                current->right = DeleteNode(current->right, pData);
            else
            {
                if(current->left == NULL && current->right == NULL)
                {
                    delete current;
                    return NULL;
                }
                else if(current->left == NULL)
                {
                    node *temp = current->right;
                    delete current;
                    return temp;
                }
                else if(current->right == NULL)
                {
                    node *temp = current->left;
                    delete current;
                    return temp;
                }
                else
                {
                    node *temp = MinValueNode(current->right);
                    current->data = temp->data;
                    current->right = DeleteNode(current->right, temp->data);
                }
            }

            return current;
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
            noChildDeletions = 0;
            oneChildDeletions = 0;
            twoChildDeletions = 0;
        }

        void InsertNode(int pData)
        {
            int insertedDepth = -1;
            root = InsertNewNode(root, pData, 0, insertedDepth);

            if(insertedDepth == -1)
                cout << pData << " duplicate, rejected" << endl;
            else
                cout << pData << " inserted at depth " << insertedDepth << endl;
        }

        void DeleteValue(int pData)
        {
            node *current = root;
            int depth = 0;

            while(current != NULL && current->data != pData)
            {
                if(pData < current->data)
                    current = current->left;
                else
                    current = current->right;
                depth++;
            }

            if(current == NULL)
            {
                cout << pData << " not found, deletion skipped" << endl;
                return;
            }

            if(current->left == NULL && current->right == NULL)
            {
                cout << pData << " depth " << depth << ", no child" << endl;
                noChildDeletions++;
            }
            else if(current->left == NULL || current->right == NULL)
            {
                cout << pData << " depth " << depth << ", one child" << endl;
                oneChildDeletions++;
            }
            else
            {
                node *replacement = MinValueNode(current->right);
                cout << pData << " depth " << depth << ", two children, replaced by "
                     << replacement->data << endl;
                twoChildDeletions++;
            }

            root = DeleteNode(root, pData);
        }

        void PrintLevelOrder()
        {
            if(root == NULL)
            {
                cout << "Level order:" << endl;
                cout << "Level widths:" << endl;
                cout << "Widest level -1" << endl;
                cout << "Height -1" << endl;
                return;
            }

            queue<node*> nodes;
            vector<int> widths;
            nodes.push(root);

            cout << "Level order: ";
            while(!nodes.empty())
            {
                int levelSize = nodes.size();
                widths.push_back(levelSize);

                for(int i = 0; i < levelSize; i++)
                {
                    node *current = nodes.front();
                    nodes.pop();
                    cout << current->data << " ";

                    if(current->left != NULL)
                        nodes.push(current->left);
                    if(current->right != NULL)
                        nodes.push(current->right);
                }
            }
            cout << endl << endl;

            cout << "Level widths: ";
            int widestLevel = 0;
            for(int i = 0; i < widths.size(); i++)
            {
                cout << widths[i] << " ";
                if(widths[i] > widths[widestLevel])
                    widestLevel = i;
            }
            cout << endl;
            cout << "Widest level " << widestLevel << endl;
            cout << "Height " << TreeHeight(root) << endl;
            cout << "Deletion kinds: no child " << noChildDeletions
                 << ", one child " << oneChildDeletions
                 << ", two children " << twoChildDeletions << endl;
        }
};

int main()
{
    BinarySearchTree tree;

    // Insert the initial product codes in the given order.
    tree.InsertNode(40);
    tree.InsertNode(20);
    tree.InsertNode(60);
    tree.InsertNode(10);
    tree.InsertNode(30);
    tree.InsertNode(50);
    tree.InsertNode(70);
    tree.InsertNode(5);
    tree.InsertNode(15);
    tree.InsertNode(25);
    tree.InsertNode(35);

    // Perform the operations in the given order.
    tree.InsertNode(55);
    tree.DeleteValue(20);
    tree.InsertNode(12);
    tree.DeleteValue(60);
    tree.DeleteValue(5);

    tree.PrintLevelOrder();

    return 0;
}
