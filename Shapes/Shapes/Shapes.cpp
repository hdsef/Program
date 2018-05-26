// Shapes.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Shape.h"
#include "Triangle.h"
#include "Squar.h"
int main()
{
	Triangle a(1, 1, 2, 3, 4, 5);
	Squar b(1, 1, 2, 2, 3, 3, 4, 4);
	printf_s("%d %d",a.correct(),b.correct());
    return 0;
}

