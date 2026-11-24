#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *left;
        node *right;
        int height;

        node()
        {
            data = 0;
            left = NULL;
            right = NULL;
            height = 1;
        }
};

class AVLTree
{
    private:
        node *root;

        int GetHeight(node *current)
        {
            if(current == NULL)
            {
                return 0;
            }
            return current->height;
        }

        int Maximum(int a, int b)
        {
            return (a > b) ? a : b;
        }
int GetBalance(node *current)
{
    if(current == NULL)
    {
        return 0;
    }
    return GetHeight(current->left) - GetHeight(current->right);
}

node* RightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    // Perform Rotation
    x->right = y;
    y->left = T2;

    // Update Heights
    y->height = 1 + Maximum(
            GetHeight(y->left),
            GetHeight(y->right)
        );
    x->height = 1 + Maximum(
            GetHeight(x->left),
            GetHeight(x->right)
        );

    // x becomes new root
    return x;
}

node* LeftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    // Perform Rotation
    y->left = x;
    x->right = T2;

    // Update Heights
    x->height = 1 + Maximum(
            GetHeight(x->left),
            GetHeight(x->right)
        );
    y->height = 1 + Maximum(
            GetHeight(y->left),
            GetHeight(y->right)
        );

    // y becomes new root
    return y;
}

// -------------------------------------------------
// INSERT NODE
// -------------------------------------------------
node* InsertNewNode(node *current, int pData)
{
    // STEP 1: NORMAL BST INSERTION
    if(current == NULL)
    {
        node *newNode = new node();
        newNode->data = pData;
        return newNode;
    }

    if(pData < current->data)
    {
         current->left = InsertNewNode(current->left, pData);
    }
    else if(pData > current->data)
    {
         current->right = InsertNewNode(current->right, pData);
    }
    else
    {
         // Duplicate values are not inserted
         return current;
    }

    // STEP 2: UPDATE HEIGHT
    current->height = 1 + Maximum(
            GetHeight(current->left),
            GetHeight(current->right)
        );

    // STEP 3: CALCULATE BALANCE FACTOR
    int balance = GetBalance(current);

    // STEP 4: CHECK FOUR AVL CASES

    // CASE 1: LL
    if(balance > 1 && pData < current->left->data)
    {
        return RightRotate(current);
    }
    // CASE 2: RR
    if(balance < -1 && pData > current->right->data)
    {
        return LeftRotate(current);
    }

    // CASE 3: LR
    if(balance > 1 && pData > current->left->data)
    {
        current->left = LeftRotate(current->left);
        return RightRotate(current);
    }

    // CASE 4: RL
    if(balance < -1 && pData < current->right->data)
    {
        current->right = RightRotate(current->right);
        return LeftRotate(current);
    }

    return current;
}

// -------------------------------------------------
// FIND MINIMUM VALUE NODE (Inorder Successor)
// -------------------------------------------------
node* MinValueNode(node *current)
{
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// -------------------------------------------------
// DELETE NODE
// -------------------------------------------------
node* DeleteNode(node *current, int key)
{
    // STEP 1: NORMAL BST DELETION
    if(current == NULL)
    {
        cout << endl << key << " not found in tree" << endl;
        return current;
    }

    if(key < current->data)
{
    current->left = DeleteNode(current->left, key);
}
else if(key > current->data)
{
     current->right = DeleteNode(current->right, key);
}
else
{
     // Node with 0 or 1 child
     if(current->left == NULL || current->right == NULL)
     {
         node *temp = (current->left != NULL)
                         ? current->left
                         : current->right;

        // No child
        if(temp == NULL)
        {
             temp = current;
             current = NULL;
        }
        // One child
        else
        {
             *current = *temp;
        }

        delete temp;
    }
    // Node with 2 children
    else
    {
         node *temp = MinValueNode(current->right);
         current->data = temp->data;
         current->right =
             DeleteNode(current->right, temp->data);
    }
}

// If tree had only one node
if(current == NULL)
{
    return current;
}

// STEP 2: UPDATE HEIGHT
current->height = 1 + Maximum(
        GetHeight(current->left),
             GetHeight(current->right)
        );

    // STEP 3: CALCULATE BALANCE FACTOR
    int balance = GetBalance(current);

    // STEP 4: CHECK FOUR AVL CASES

    // CASE 1: LL
    if(balance > 1 && GetBalance(current->left) >= 0)
    {
        return RightRotate(current);
    }

    // CASE 2: LR
    if(balance > 1 && GetBalance(current->left) < 0)
    {
        current->left = LeftRotate(current->left);
        return RightRotate(current);
    }

    // CASE 3: RR
    if(balance < -1 && GetBalance(current->right) <= 0)
    {
        return LeftRotate(current);
    }

    // CASE 4: RL
    if(balance < -1 && GetBalance(current->right) > 0)
    {
        current->right = RightRotate(current->right);
        return LeftRotate(current);
    }

    return current;
}

// -------------------------------------------------
// INORDER TRAVERSAL
// -------------------------------------------------
void Inorder(node *current)
{
    if(current != NULL)
    {
        Inorder(current->left);
        cout << current->data << " ";
        Inorder(current->right);
    }
}
    // -------------------------------------------------
    // PREORDER TRAVERSAL
    // -------------------------------------------------
    void Preorder(node *current)
    {
        if(current != NULL)
        {
            cout << current->data << " ";
            Preorder(current->left);
            Preorder(current->right);
        }
    }

    // -------------------------------------------------
    // POSTORDER TRAVERSAL
    // -------------------------------------------------
    void Postorder(node *current)
    {
        if(current != NULL)
        {
            Postorder(current->left);
            Postorder(current->right);
            cout << current->data << " ";
        }
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    void InsertNode(int pData)
    {
        root = InsertNewNode(root, pData);
    }

    void Delete(int key)
    {
        root = DeleteNode(root, key);
    }

    void PrintTree()
    {
        if(root == NULL)
        {
            cout << endl << "Tree is Empty" << endl;
            return;
        }

        cout << "Inorder Traversal: ";
        Inorder(root);
        cout << endl;

        cout << "Preorder Traversal: ";
        Preorder(root);
        cout << endl;

        cout << "Postorder Traversal: ";
        Postorder(root);
        cout << endl;
    }
};


int main()
{
    AVLTree tree;

    tree.InsertNode(30);
    tree.InsertNode(20);
    tree.InsertNode(40);
    tree.InsertNode(10);
    tree.InsertNode(25);
    tree.InsertNode(50);
    tree.InsertNode(5);

    cout << "Before Deletion:" << endl;
    tree.PrintTree();

    tree.Delete(40);

    cout << endl << "After Deleting 40:" << endl;
    tree.PrintTree();

    tree.Delete(20);

    cout << endl << "After Deleting 20:" << endl;
    tree.PrintTree();

    return 0;
}