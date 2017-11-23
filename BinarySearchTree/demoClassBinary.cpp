#include <iostream>

using namespace std;

class BSTNode
{
private:
	int data;
	BSTNode *left;
	BSTNode *right;
public:
	BSTNode()
	{
	}
	BSTNode(int dataNew)
	{
		this->data = dataNew;
		this->left = this->right = NULL;
	}
	~BSTNode()
	{
	}
	BSTNode* insertNode(int dataInsert);
	BSTNode* findMin();
	BSTNode* deleteNode(int dataDel);
};

BSTNode* BSTNode::insertNode(int dataInsert)
{
	if(this == NULL)
	{
		this->data = dataInsert;
		return this;
	}
	else if (dataInsert <= this->data)
		this->left = this->left->insertNode(dataInsert);
	else 
		this->right = this->right->insertNode(dataInsert);
	return this;
}

BSTNode* BSTNode::findMin()
{
	while(this->left != NULL)
		this->left = this->left->left;
	return this;
}

BSTNode* BSTNode::deleteNode(int dataDel)
{
	if (this == NULL)
		return this;
	else if (dataDel <= this->data)
		this->left = this->left->deleteNode(dataDel);
	else if (dataDel > this->data)
		this->right = this->right->deleteNode(dataDel);
	else
	{
		//case 1: No child
		if (this->left == NULL && this->right == NULL)
		{
			delete[] this;
		}
		//case 2: One child
		else if(this->left == NULL)
		{
			BSTNode *temp = this;
			this->left = this->left->left;
			delete[] temp;
		}
		else if(this->right == NULL)
		{
			BSTNode *temp = this;
			this->right = this->right->right;
			delete[] temp;
		}
		//case 3: two child
		else
		{
			BSTNode *temp =this->right->findMin();
			this->data = temp->data;
			this->right = this->right->deleteNode(temp->data);
		}
		return this;
	}
}

int main()
{
	return 0;
}