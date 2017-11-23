H5.1.8
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct LList
{
	Node *head;
};

void deleteMax(LList &l)
{
	if (l.head == NULL)
	{
		cout << "The list is empty!!!" << endl;
		return;
	}
	if (l.head->next == NULL)
	{
		delete l.head;
		l.head = NULL;
		return;
	}
	Node *cur = l.head->next;
	Node *tmp = l.head;
	Node *max = l.head;
	while (cur != NULL)
	{
		if (max->data < cur->data)
			max = cur;
		cur = cur->next;
		tmp = tmp->next;
	}
	if (max->data < l.head->data)
	{
		tmp = l.head;
		l.head = l.head->next;
		delete tmp;
		tmp = NULL;
	}
	else
	{
		Node *tmp2 = max;
		tmp->next = max->next;
		delete tmp2;
		tmp2 = NULL;
	}
}