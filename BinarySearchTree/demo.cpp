#include <iostream>
#include <string>

using namespace std;

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

BSTNode* getNewNode(int data)
{
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTNode* insertNode(BSTNode* root, int data)
{
	if(root == NULL)
	{
		root = getNewNode(data);
		return root;
	}
	else if(data <= root->data)
	{
		root->left = insertNode(root->left,data);
	}
	else
		root->right = insertNode(root->right,data);
	return root;
}

BSTNode* findMin(BSTNode *root)
{
	while(root->left != NULL)
		root = root->left;
	return root;
}

BSTNode* deleteNode(BSTNode *root, int data)
{
	if(root == NULL)
		return root;
	else if (data < root->data)
		root->left = deleteNode(root->left,data);
	else if (data > root->data)
		root->right = deleteNode(root->right,data);
	else
	{
		//case 1: No child
		if(root->left == NULL && root->right == NULL)
		{
			delete[] root;
			root = NULL;
		}
		//case 2: 1 Child
		else if(root->left == NULL)
		{
			BSTNode *temp = root;
			root = root->right;
			delete[] temp;
		}
		else if(root->right == NULL)
		{
			BSTNode *temp = root;
			root = root->left;
			delete[] temp;
		}
		//case 3: 2 children
		else
		{
			BSTNode* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
		return root;
	}
}


bool searchData(BSTNode* root, int dataSearch)
{
	if(root == NULL)
		return false;
	else if(dataSearch == root->data)
		return true;
	else if (dataSearch <= root->data)
		return searchData(root->left,dataSearch);
	else 
		return searchData(root->right,dataSearch);
}

void preorder(BSTNode* root,string &path)
{
	if(root == NULL)
		return;
	path = path + to_string(root->data) + " ";
	preorder(root->left,path);
	preorder(root->right,path);
}

void inorder(BSTNode* root,string &path)
{
	if(root == NULL)
		return;
	inorder(root->left,path);
	path = path + to_string(root->data) + "";
	inorder(root->right,path);
}

void postorder(BSTNode* root, string &path)
{
	if(root == NULL)
		return ;
	postorder(root->left,path);
	postorder(root->right,path);
	path = path + to_string(root->data) + " ";
}

string printTree(BSTNode* root, string type)
{
	string result;
	if(type == "NLR")
		preorder(root,result);
	else if(type == "LNR")
		inorder(root,result);
	else if(type == "LRN")
		postorder(root,result);
	else 
	{
		cout << "Error: Permission denied !!!" << endl;
	}
	return result;
}

int main()
{
	return 0;
}