#include <iostream>

using namespace std;

struct NODE
{
	int data;
	NODE *left;
	NODE *right;
	int height;
};

int height(NODE *root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else 
		return b;
}

int getBalance(NODE *root)
{
	if (root == NULL)
		return 0;
	else
	{
		int tempHeight = height(root->right) - height(root->left);
		return tempHeight;
	}
}

bool isAVL(NODE *root)
{
	if (getBalance(root) > 1 || getBalance(root) < -1)
		return false;
	else 
		return true;
}