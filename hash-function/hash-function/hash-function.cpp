// hash-function.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MD5.h"

int main()
{
	MD5 a;
	std::cout << a.get_md5("I wanna kill everybody, when i test it on my computer, so I need to chill out and nom nom nom") << std::endl;
	system("pause");
	return 0;
}
