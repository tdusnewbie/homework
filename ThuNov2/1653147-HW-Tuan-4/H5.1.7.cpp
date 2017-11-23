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

Node* Delete_1st_item_in_list(LList &l)
{
	if (l.head != NULL)
	{
		Node *tmp;
		tmp = l.head;
		l.head = l.head->next;
		delete tmp;
		tmp = NULL;
	}
	if (l.head == NULL)
		return NULL;
	return l.head;
}