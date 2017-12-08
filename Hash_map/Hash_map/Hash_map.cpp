// Hash_map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "list.h"

int main()
{
	link_list hash_table;
	hash_table.put("Prusakov", 1000);
	hash_table.put("Ivanov", 2000);
	hash_table.put("Fedorov", 3000); 
	hash_table.put("Petrov", 4000);
	hash_table.put("Sidorov", 5000);
	hash_table.printbalance();
	printf_s("\n");
	hash_table.printkey();
	printf_s("\n");
	hash_table.delete_node("Petrov");
	hash_table.put("Fedorov", 9000);
	hash_table.printbalance();
	printf_s("\n");
	hash_table.printkey();
	printf_s("\n");
	printf_s("%d", hash_table.get("Ivanov"));
	system("pause");
    return 0;
}

