#include "generator.h"



generator::generator()
{
}


generator::~generator()
{
}

void generator::output() {
	srand(time(NULL));
	printf_s("%s ", surname[rand() % 4]);
	printf_s("%s ", name[rand() % 4]);
	printf_s("%s ", patronymic[rand() % 4]);
}