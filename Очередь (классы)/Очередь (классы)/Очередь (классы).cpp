// Î÷åðåäü
//
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "queue.h"

int main()
{
	srand(time(NULL));
	queue q;
	List* l = new List;
	for (int i = 1; i <= 10; i++)
	{
		int a = rand() % 20;
		q.push(l, a);
	}
	q.printlist(l);
	q.pop(l);
	q.pop(l);
	q.printlist(l);
	_gettch();
	delete(l);
	return 0;
}
