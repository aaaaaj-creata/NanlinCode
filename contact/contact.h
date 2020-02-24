#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int  _age;
}Contact;

//typedef struct Contact Contact;

typedef struct ContactBook
{
	Contact* _con_array;
	size_t _size;		// ÁªÏµÈË¸öÊý
	size_t _capacity;	// ÈÝÁ¿
}ContactBook;

void ContactBookInit(ContactBook* pbook);
void ContactBookDestory(ContactBook* pbook);
void ContactBookAppend(ContactBook* pbook, Contact* con);
void ContactBookDelete(ContactBook* pbook, const char* name);
Contact* ContactBookFind(ContactBook* pbook, const char* name);
void ContactBookSave(ContactBook* pbook, const char* file);
void ContactBookLoad(ContactBook* pbook, const char* file);
void ContactPrint(ContactBook* pbook);
