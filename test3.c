#define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"

void menu()
{
	printf("**********************************\n");
	printf("****   1.add        2.del     ****\n");
	printf("****   3.search     4.modify  ****\n");
	printf("****   5.show       6.sort    ****\n");
	printf("*********    0.exit    ***********\n");
}



int main()
{
	int input = 0;
	struct Contact con;
	Initcontact(&con);
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch(input)
		{ 
		case ADD:
			Addcontact(&con);
			break;
		case DEL:
			Delcontact(&con);
			break;
		case SEARCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}