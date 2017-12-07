#include <iostream>
#include <cmath>

using namespace std;

class HashTable
{
private:
	struct Node
	{
		int key;
		Node *pNext;
	};
	Node **item;
	int size;
	int hash(int k);
public:
	HashTable(int m);
	~HashTable();
	void insert(int k);
	bool search(int k);
};

int HashTable::hash(int k)
{
	double A = (sqrt(5)-1)/2;
	return floor(m*(k*A%1));
}

HashTable::HashTable(int m)
{
	size = m;
	*item = new Node[m];
	for(int i = 0; i<m; i++)
	{
		item[i] = NULL;
	}
}

HashTable::~HashTable(){}

void HashTable::insert(int k)
{
	int hashValue = hash(k);
	Node *temp = new Node;
	temp->key = k;
	temp->pNext = NULL;
	Node *head = item[hashValue];
	if(head == NULL)
	{
		head = temp;
		return;
	}
	while(head->pNext == NULL)
	{
		head = head->pNext;
	}
	head->pNext = temp;
}

bool HashTable::search(int k)
{
	int hashValue = hash(k);
	Node *head = item[hashValue];
	while(head == NULL)
	{
		if(head->key == k)
			return true;
		head = head->pNext;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}