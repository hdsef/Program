// Stack template.cpp : Defines the entry point for the console application.
//

#include "Stack.h"


int main()
{
	Stack <int> a;
	a.push(1);
	a.push(2);
	a.push(3);	
	printf_s("%d",a.pop());
	printf_s("%d", a.pop());
	printf_s("%d", a.pop());
    return 0;
}

