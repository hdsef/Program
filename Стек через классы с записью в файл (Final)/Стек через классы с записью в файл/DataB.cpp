#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "DataB.h"
#include <stdlib.h>
#include <string.h>
#include "stack.h"


DataB::DataB()
{
}


DataB::~DataB()
{
}



DBFile* DataB::initialize(const char *db_file_name) {
	//TODO
	DBFile *db_file = (DBFile *)malloc(sizeof(DBFile));
	db_file->file_ptr = NULL;
	strncpy_s(db_file->file_name, db_file_name, FILE_NAME_MAX_LEN);
	return db_file;
}

void DataB::open_db(DBFile *db) {
	//TODO
	db->file_ptr = fopen(db->file_name, "ab+");
}

void DataB::new_db(DBFile *db) {
	db->file_ptr = fopen(db->file_name, "w");
}

void DataB::close_db(DBFile *db) {
	//TODO
	fclose(db->file_ptr);
}

void DataB::save_stack_to_db(DBFile *db, top *data) {
	while (data->top != 0)
	{
		fwrite(data->top, sizeof(node), 1, db->file_ptr);
		node* tmp = data->top;
		data->top = data->top->prev;
		free(tmp);
	}
}

void DataB::read_from_db(DBFile *db, top *data) {
	node *next = 0;
	while (1)
	{
		node* elem = (node*)malloc(sizeof(node));
		fread(elem, sizeof(node), 1, db->file_ptr);
		//elem->prev = 0;
		if (data->top == 0)
			data->top = elem;
		if (next != 0)
		{
			next->prev = elem;
		}
		next = elem;
		if (elem->prev == 0)
			break;
	}
}

void DataB::free_db(DBFile *db) {
	free(db);
}
