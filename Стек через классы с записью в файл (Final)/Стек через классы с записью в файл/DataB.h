#pragma once
#include <stdio.h>
#include "Stack.h"
#define FILE_NAME_MAX_LEN 60

typedef struct db_file_s {
	FILE *file_ptr;
	char file_name[FILE_NAME_MAX_LEN];
} DBFile;

class DataB
{
public:
	DataB();
	~DataB();
	DBFile* initialize(const char *db_file_name);
	void open_db(DBFile *db);
	void new_db(DBFile *db);
	void close_db(DBFile *db);
	void save_stack_to_db(DBFile *db, top *data);
	void read_from_db(DBFile *db, top *data);
	void free_db(DBFile *db);
};

