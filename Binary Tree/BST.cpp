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

        node* InsertNewNode(node *current, int pData)
        {
            // Empty position found
            if(current == NULL)
            {
                node *newNode = new node();
                newNode->data = pData;

                return newNode;
            }

            if(pData < current->data)   // Move to left subtree
            {
                current->left = InsertNewNode(current->left, pData);
            }
            else
            {	            			// Move to right subtree
                current->right = InsertNewNode(current->right, pData);
            }

            return current;
        }

        node* MinValueNode(node *current)
        {
            node *temp = current;

			// Find min_node from right-sub tree.
			// Current is pointing to right-sub tree 
            while(temp != NULL && temp->left != NULL)
            {
                temp = temp->left;
            }
            return temp;
        }

        node* DeleteNode(node *current, int pData)
        {
            if(current == NULL)
            {
                return current;
            }

            if(pData < current->data)
            {
                current->left = DeleteNode(current->left, pData);
            }
            else if(pData > current->data)
            {
                current->right = DeleteNode(current->right, pData);
            }
            else
            {
				// CASE 1: Node has no child
				if(current->left == NULL && current->right == NULL)
					{
						delete current;
						return NULL;
					}

				// CASE 2: Node has only one child (right) 
				else if(current->left == NULL)
					{
						node *temp = current->right;
						delete current;
						return temp;
					}

				// CASE 2: Node has only one child (left)
				else if(current->right == NULL)
					{
						node *temp = current->left;
						delete current;
						return temp;
					}

				// CASE 3: Node has two children
				else
					{
						node *temp = MinValueNode(current->right);
						current->data = temp->data;
					    current->right = DeleteNode(current->right, temp->data);
					}				
            }
            return current;
        }

		void Inorder(node *current)		// INORDER TRAVERSAL (Left -> Root -> Right)
		{					
			if(current != NULL)
			{
				Inorder(current->left);

				cout << current->data << " ";

				Inorder(current->right);
			}
		}

		void Preorder(node *current)	// PREORDER TRAVERSAL (Root -> Left -> Right)
		{
			if(current != NULL)
			{
				cout << current->data << " ";

				Preorder(current->left);

				Preorder(current->right);
			}
		}

		void Postorder(node *current)	// POSTORDER TRAVERSAL (Left -> Right -> Root)
		{
			if(current != NULL)
			{
				Postorder(current->left);

				Postorder(current->right);

				cout << current->data << " ";
			}
		}

    public:
        BinarySearchTree()
        {
            root = NULL;
        }

        void InsertNode(int pData)
        {
            root = InsertNewNode(root, pData);
        }

        void SearchNode(int pData)
        {
            node *current = root;

            while(current != NULL)
            {
                if(current->data == pData)
                {
                    cout << endl<<"Value Found = "<< current->data << endl;
                    return;
                }
                else if(pData < current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            cout << endl<< "Value Not Found" << endl;
        }

        void PrintTree()
        {
            cout << endl<< "Inorder Traversal: ";
            if(root == NULL)
            {
                cout << "Tree is Empty";
            }
            else
            {
                Inorder(root);
            }
            cout << endl;
        }

        void DeleteNode(int pData)
        {
            root = DeleteNode(root, pData);
        }

		void PrintTree(int choice)
		{
			if(root == NULL)
			{
				cout<<endl<<"Tree is Empty"<<endl;
				return;
			}

			switch(choice)
			{
				case 1:
					{  	cout<<endl<<"Inorder Traversal: ";
						Inorder(root);
						break;
					}

				case 2:
				   {   	cout<<endl<<"Preorder Traversal: ";
						Preorder(root);
						break;
				   }
				case 3:
					{	cout<<endl<<"Postorder Traversal: ";
						Postorder(root);
						break;
					}

				default:
					cout<<endl<<"Invalid Choice";
					break;
			}
			cout<<endl;
		}
		
};



// ---------------------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------------------

int main()
{
    BinarySearchTree tree;

    // Create BST
    tree.InsertNode(40);
    tree.InsertNode(30);
    tree.InsertNode(60);
    tree.InsertNode(20);
    tree.InsertNode(35);
    tree.InsertNode(50);
    tree.InsertNode(70);
 
    cout<<endl<<"Pre order  : ";  tree.PrintTree(2);
    cout<<endl<<"In order   : ";   tree.PrintTree(1);
    cout<<endl<<"Post order : "; tree.PrintTree(3);
 
//    tree.DeleteNode(40);

    /*
                40

              /    \

            30      60

                      \

                       65

                         \

                          70
    */




    return 0;
}