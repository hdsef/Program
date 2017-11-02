#include "list.h"



link_list::link_list()
{
}


link_list::~link_list()
{

}
void link_list::delete_list(List* list) {
	list->tright = 0;
	while (list->tleft != 0)
	{
		Node *temp = 0;
		temp = list->tleft;
		list->tleft = list->tleft->right;
		delete temp;
	}
}

void link_list::errors()
{
	printf_s("введены не корректные значения");
	_gettch();
	exit(1);
}

void link_list::pushright(List* list, int x) {
	Node* note = new Node;
	(*note).val = x;
	(*note).left = (*list).tright;
	if (list->tright != 0)
		list->tright->right = note;
	list->tright = note;

	if (list->tleft == NULL) {
		list->tleft = note;
	}
	list->size++;
}

void link_list::pushleft(List* list, int x)
{
	Node* note = new Node;
	(*note).val = x;
	(*note).right = (*list).tleft;
	if (list->tleft != 0)
		list->tleft->left = note;
	(*list).tleft = note;
	if ((*list).tright == NULL)
	{
		(*list).tright = note;
	}
	(*list).size++;
}

void link_list::printlist(List* list)
{
	Node* temp = (*list).tleft;
	while (temp != 0)
	{
		printf_s("%d ", (*temp).val);
		temp = (*temp).right;
	}
	printf_s("\n");
}

void link_list::vstavka(List* list, int x, int n) //вставка между n и n+1-элементами, крайний левый считать нулевым
{
	if (n < 0 || n >= list->size)
	{
		errors();
	}
	else
	{
		Node *note = new Node, *t = list->tleft;
		for (int i = 0; i < n - 1; i++)
		{
			t = t->right;
		}
		note->val = x;
		note->right = t->right;
		note->left = t;
		t->right = note;
		list->size++;
	}
}

void link_list::masssort(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void link_list::listsort(List* list)
{
	int *a = new int[list->size];
	Node *t = list->tleft;
	for (int i = 0; i < list->size; i++)
	{
		a[i] = t->val;
		t = t->right;
	}
	masssort(a, list->size);
	t = list->tleft;
	for (int i = 0; i < list->size; i++)
	{
		t->val = a[i];
		t = t->right;
	}
	t = NULL;
	delete a;
}