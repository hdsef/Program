// Hash table with array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Hash_table.h"

int main()
{
	Hash_table tabl;
	tabl.put("Prusakov", 1000);
	tabl.put("Ivanov", 2000);
	tabl.put("Chistokov", 3000);
	tabl.put("Petrovich", 4000);
	//tabl.delete_n("Ivanov");
	tabl.get("Prusakov");
	tabl.all_keys();
	printf_s("\n");
	tabl.all_vals();
	printf_s("\n");
	printf_s("\n");
	tabl.size_change(3);
	tabl.all_keys();
    return 0;
}

