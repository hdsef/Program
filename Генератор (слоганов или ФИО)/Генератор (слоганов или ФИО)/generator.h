#pragma once
#include <iostream>
#include <clocale>
#include <time.h>
class generator
{
private:
	char name[4][20] = {"Кирилл","Руслан","Иван","Никита"};
	char surname[4][20] = { "Аллаяров","Аистов","Анисеня","Байдин" };
	char patronymic[4][20] = {"Константинович","Садуллаевич","Ильич","Сергеевич	"};
public:
	generator();
	~generator();
	void output();
};

