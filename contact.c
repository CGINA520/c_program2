#define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"
#include <string.h>

//    ��ʼ��
void Initcontact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;
}

//   �����ϵ�� 
void Addcontact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("��������\n");
		scanf("%s", ps->date[ps->size].name);
		printf("��������\n");
		scanf("%d", &ps->date[ps->size].age);
		printf("�����Ա�\n");
		scanf("%s", ps->date[ps->size].sex );
		printf("����סַ\n");
		scanf("%s", ps->date[ps->size].addr );
		printf("����绰����\n");
		scanf("%s", ps->date[ps->size].tele );

		ps->size++;
		printf("��ӳɹ�\n");
	}
}

//   ��ʾͨѶ¼    
void Showcontact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ��������ϵ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-20s\t%-20s\n","����","����","�Ա�","�绰","סַ");
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

//   ���Һ���
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

//   ɾ����ϵ��
void Delcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����Ҫɾ������ϵ������->\n");
	scanf("%s", name);
	int pos=Find(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�ҵ���ϵ�˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j <ps->size -1 ; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

//   ������ϵ��
void Searchcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����Ҫ���ҵ���ϵ������->\n");
	scanf("%s", name);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("���ҵ���ϵ�˲�����\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-20s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
			printf("%-20s\t%-4d\t%-5s\t%-20s\t%-20s\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}

//   �޸���ϵ��
void Modifycontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����Ҫ�޸ĵ���ϵ������->\n");
	scanf("%s", name);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("�Ҳ�������ϵ��\n");
	}
	else
	{
		printf("��������\n");
		scanf("%s", ps->date[pos].name);
		printf("��������\n");
		scanf("%d", &ps->date[pos].age);
		printf("�����Ա�\n");
		scanf("%s", ps->date[pos].sex);
		printf("����סַ\n");
		scanf("%s", ps->date[pos].addr);
		printf("����绰����\n");
		scanf("%s", ps->date[pos].tele);
	}
}