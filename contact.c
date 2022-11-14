#define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"
#include <string.h>

//    初始化
void Initcontact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;
}

//   添加联系人 
void Addcontact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法输入\n");
	}
	else
	{
		printf("输入名字\n");
		scanf("%s", ps->date[ps->size].name);
		printf("输入年龄\n");
		scanf("%d", &ps->date[ps->size].age);
		printf("输入性别\n");
		scanf("%s", ps->date[ps->size].sex );
		printf("输入住址\n");
		scanf("%s", ps->date[ps->size].addr );
		printf("输入电话号码\n");
		scanf("%s", ps->date[ps->size].tele );

		ps->size++;
		printf("添加成功\n");
	}
}

//   显示通讯录    
void Showcontact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空，请添加联系人\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-20s\t%-20s\n","姓名","年龄","性别","电话","住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-20s\t%-20s\n",
				ps->date [i].name, 
			    ps->date[i].age ,
				ps->date [i].sex ,
				ps->date [i].tele ,
				ps->date[i].addr );
		}
	}
}

//   查找函数
static int Find(struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->date[i].name, name) == 0)
			return i;
	}
	return -1;
}

//   删除联系人
void Delcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("输入要删除的联系人姓名->\n");
	scanf("%s", name);
	int pos=Find(ps, name);
	if (pos == -1)
	{
		printf("要找的联系人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j <ps->size -1 ; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

//   查找联系人
void Searchcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("输入要查找的联系人姓名->\n");
	scanf("%s", name);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("查找的联系人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-20s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
			printf("%-20s\t%-4d\t%-5s\t%-20s\t%-20s\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}

//   修改联系人
void Modifycontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("输入要修改的联系人姓名->\n");
	scanf("%s", name);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("找不到该联系人\n");
	}
	else
	{
		printf("输入名字\n");
		scanf("%s", ps->date[pos].name);
		printf("输入年龄\n");
		scanf("%d", &ps->date[pos].age);
		printf("输入性别\n");
		scanf("%s", ps->date[pos].sex);
		printf("输入住址\n");
		scanf("%s", ps->date[pos].addr);
		printf("输入电话号码\n");
		scanf("%s", ps->date[pos].tele);
	}
}