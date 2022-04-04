//app.c

#include "std.h"

void app_init()
{
	logo();
	con_init();
}

void app_run()
{
	while (1)  //for(; ; )
	{
		system("cls");
		con_printall();
		char idx = menuprint();
		switch (idx)
		{
		case '1':	con_insert();        	break;
		case '2':	con_select();			break;
		case '3':	con_update();		    break;
		case '4':	con_delete();			break;
		case '5':	return; //???
		default: printf("�߸� �Է��ϼ̽��ϴ�.\n"); 
		}
		system("pause");
	}
}

void app_exit()
{
	ending();
}

void logo()
{
	system("cls");
	printf("**********************************************\n");
	printf(" ��ۺ�Ʈ �ܱ� 55�� ����\n");
	printf(" C��� ����\n");
	printf(" ����ü�� �̿��� ȸ�� ���� ���α׷�\n");
	printf(" 2022-04-04\n");
	printf(" ccm\n");
	printf("**********************************************\n");
	system("pause");		//#include <conio.h>
}

char menuprint()
{
	printf("**********************************************\n");
	printf(" [1] insert(����)\n");
	printf(" [2] select(�˻�)\n");
	printf(" [3] update(����)\n");
	printf(" [4] delete(����)\n");
	printf(" [5] exit(���α׷� ����\n");
	printf("**********************************************\n");

	//scanf_s, getchar
	return _getch();		//#include <conio.h>
}

void ending()
{	
	system("cls");
	printf("**********************************************\n");
	printf(" ���α׷��� �����մϴ�.\n");
	printf("**********************************************\n");
	system("pause");
}