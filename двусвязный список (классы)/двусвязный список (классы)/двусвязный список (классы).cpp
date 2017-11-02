// двусвязный список (классы).cpp : Defines the entry point for the console application.
//


#include "list.h"

int main()
{
	srand(time(NULL));
	link_list q;
	List* l = new List;
	for (int i = 1; i <= 10; i++)
	{
		int a = rand() % 20;
		q.pushright(l, a);
	}
	q.printlist(l);
	q.vstavka(l, 57, 3);
	q.printlist(l);
	q.listsort(l);
	q.printlist(l);
	q.delete_list(l);
	_gettch();
	delete l;
	return 0;
}

