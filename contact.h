#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

struct People
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct People date[MAX];
	int size;
};

void Initcontact(struct Contact* ps);
void Addcontact(struct Contact* ps);
void Showcontact(const struct Contact* ps);
void Delcontact(struct Contact* ps);
void Searchcontact(struct Contact* ps);
void Modifycontact(struct Contact* ps);