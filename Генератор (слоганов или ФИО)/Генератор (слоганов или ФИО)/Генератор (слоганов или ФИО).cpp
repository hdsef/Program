// Генератор (слоганов или ФИО).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "generator.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	generator s;
	s.output();
	_gettch();
    return 0;
}

