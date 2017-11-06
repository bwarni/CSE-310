//Michael Warnick
//CSE 310: Algorithms and Data Structures
//HW 3: 100 Points
//Due Sunday, June 18th by 11:59 pm Online


#include <iostream>
#include <cstdlib>
using namespace std;

/*

a) Insert	-
b) Post Order Traversal	-
c) Pre Order Traversal	-
d) Find Max	-
e) Remove Max
f) Successor (see slides for the algorithm)
g) Delete
*/

class BinarySearchTree
{
private:
	class node
	{
	public:
		node* left;
		node* right;
		node* parent;
		int key;
		string data;
	};

	
public:
	node* root;
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void INORDER_TREE_WALK(node*);
    void POSTORDER_TREE_WALK(node*);
	void PREORDER_TREE_WALK(node*);
	void FIND_MAX(node*);
	void REMOVE_MAX(node*);
	void TREE_INSERT(int );
	void SUCCESSOR(int );


};

void BinarySearchTree::TREE_INSERT(int d)
{
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	z->key = d;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;
	node* parent = NULL;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
		
}

//Inorder (Left, Root, Right) 
void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " " << x->key << " ";
		if (x->right) INORDER_TREE_WALK(x->right);
	}
}

//Postorder (Left, Right, Root)
void BinarySearchTree::POSTORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) POSTORDER_TREE_WALK(x->left);
		if (x->right) POSTORDER_TREE_WALK(x->right);
		cout << " " << x->key << " ";
	}
}

//Preorder (Root, Left, Right)
void BinarySearchTree::PREORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		cout << " " << x->key << " ";
		if (x->left) PREORDER_TREE_WALK(x->left);
		if (x->right) PREORDER_TREE_WALK(x->right);
	}
}

void BinarySearchTree::FIND_MAX(node* x)
{
	if (x != NULL)
	{
		while(x->right != NULL){
			x = x->right;
		}
		cout << " " << x->key << " ";

	}
	else{
		cout << "BST is Empty! Add nodes before finding max." << endl;
	}
}

void BinarySearchTree::REMOVE_MAX(node* x)
{
	node* temp = NULL;
	if (x != NULL)
	{
		while(x->right != NULL){
			x = x->right;
		}
		delete(x); 
        //x = NULL;
		//cout << " " << x->key << " ";

	}
	else{
		cout << "BST is Empty! Add nodes before finding max." << endl;
	}
}




int main()
{
	BinarySearchTree bst;
	int choice, key;
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insert a Node " << endl;
		cout << " 2. Pre-Order Traversal " << endl;
        cout << " 3. Post-Order Traversal " << endl;
		cout << " 4. In-Order Traversal " << endl;
		cout << " 5. Find Max " << endl;
		cout << " 6. Remove Max " << endl;
		cout << " 7. Successor " << endl;
		cout << " 8. Delete a Node " << endl;
		cout << " 9. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << " Enter key (int value) to be inserted : ";
			cin >> key;
			bst.TREE_INSERT(key);
			break;
		case 2: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.PREORDER_TREE_WALK(bst.root);
			break;
		case 3: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.POSTORDER_TREE_WALK(bst.root);
			break;
		case 4: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.INORDER_TREE_WALK(bst.root);
			break;
		case 5: cout << endl;
			cout << " Find Max " << endl;
			cout << " -------------------" << endl;
			bst.FIND_MAX(bst.root);
			break;
		case 6: cout << endl;
			cout << " Remove Max " << endl;
			cout << " -------------------" << endl;
			bst.REMOVE_MAX(bst.root);
			break;
        case 7: cout << endl;
			cout << " Enter key (int value) to find its successor : " << endl;
			cin >> key;
			//bst.findMin(bst.root);
			break;
		case 8: cout << endl;
			cout << " Delete a Node " << endl;
			cout << " -------------------" << endl;
			bst.INORDER_TREE_WALK(bst.root);
			break;
		case 9: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}