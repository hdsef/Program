#include "stdafx.h"
#include "stack.h"
#include "DataB.h"

const char *db_file_name = "stack_db_file.bin\0";

int main(int argc, char **argv) {
	DataB DataBase;
	Stack Stack;
	DBFile* db = DataBase.initialize(db_file_name);
	top* s = new top;
	s->top = 0;
	Stack.push(s, 1);
	Stack.push(s, 3);
	Stack.push(s, 2);
	DataBase.new_db(db);
	DataBase.save_stack_to_db(db, s);
	DataBase.close_db(db);
	delete(s);

	DataBase.open_db(db);
	top *new_data = new top;
	new_data->top = 0;
	DataBase.read_from_db(db, new_data);
	DataBase.close_db(db);
	printf_s("%d ", Stack.pop(new_data));
	printf_s("%d ", Stack.pop(new_data));
	printf_s("%d ", Stack.pop(new_data));

	delete(new_data);
	DataBase.free_db(db);

	return 0;
}
