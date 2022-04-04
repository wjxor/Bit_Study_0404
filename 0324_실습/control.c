//control.c

#include "std.h"

#define DATA_MAX	5

// int		g_id[DATA_MAX];
// char	g_name[DATA_MAX][20];
// char	g_phone[DATA_MAX][20];

member g_members[DATA_MAX];


//g_id�� ��� ������ -1���� �ʱ�ȭ..
//g_name�� g_phone�� ��� ���ڿ��� "" �ʱ�ȭ 
void con_init()
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		g_members[i].id = -1;
		strcpy_s(g_members[i].name, sizeof(g_members[i].name), "-");
		strcpy_s(g_members[i].phone, sizeof(g_members[i].phone), "-");

		// g_id[i]		= -1;
		// strcpy_s(g_name[i], sizeof(g_name[i]), "-");
		// strcpy_s(g_phone[i], sizeof(g_phone[i]), "-");
	}
}

//���������� ��� ���� ���
//��) 
//  -------------------------------------------------------------
//  [0] id  name phone
//  [1] id  name phone
//  [2] id  name phone
//  [3] id  name phone
//  [4] id  name phone
//-----------------------------------------------------------------
void con_printall()
{
	printf("--------------------------------------------------------------------------\n");
	for (int i = 0; i < DATA_MAX; i++)
	{
		printf("[%2d] %4d %8s %10s\n",i, 
				g_members[i].id, g_members[i].name, g_members[i].phone);
	}
	printf("--------------------------------------------------------------------------\n");
}

/*
* ����ִ� �������� ���� �����ϰ� �ʹ�..............
* [���� ���� �� ����� �Է��� ���� �ʱ�ȭ]
* ������ ��ġ(0~9) : 
* ������ �� : 
* [����] ���������� �ش� ��ġ�� ������ �� ����!* 
* [��� ���]
*/
void con_insert()
{
	printf("[insert(����)\n\n");

	int idx, id;
	char name[20], phone[20];

	printf("������ ��ġ(0~%d) : ", DATA_MAX-1);
	scanf_s("%d", &idx);

	printf("���̵� : ");			scanf_s("%d", &id);
	char dummy = getchar();
	printf("�̸� : ");			gets_s(name, sizeof(name));
	printf("��ȭ��ȣ : ");		gets_s(phone, sizeof(phone));

	if (g_members[idx].id == -1)
	{
		g_members[idx].id = id;
		strcpy_s(g_members[idx].name, sizeof(g_members[idx].name), name);
		strcpy_s(g_members[idx].phone, sizeof(g_members[idx].phone), phone);
		printf("����Ǿ����ϴ�\n");
	}
	else
	{
		printf("�̹� ����� ��ġ�Դϴ�\n");
	}
}


/*
* ����ڷκ��� ������ �Է¹޴´�.
* �Էµ� ������ �����迭�� ����Ǿ� �ִ��� �˻�.....[�����˻�]
* ��� ���
* - ����� �ε��� :
* - ����� �� : 
*/
void con_select()
{
	printf("select(�˻�)\n\n");

	int id;
	printf("ã���� �ϴ� ���� �Է� : ");
	scanf_s("%d", &id);

	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_members[i].id == id)
		{
			printf("����� �ε��� : %d\n", i);
			printf("�� �� �� : %d\n", g_members[i].id);
			printf("��   �� : %s\n", g_members[i].name);
			printf("��ȭ��ȣ : %s\n", g_members[i].phone);
			return;
		}		
	}
	printf("����\n");
}

//����ڷκ��� ���̵�� ��ȭ��ȣ�� �Է¹޴´�.
//���ڰ� ����� �ε����� �˻�(con_select)
//ã���� ���������� �ش� �ε����� ������ ���ڸ� �����Ѵ�.

//����� ����Ѵ�.
void con_update()
{
	printf("update(����)\n\n");

	int find_id;
	char phone[20];

	printf("ã���� �ϴ� ���̵� : "); 
	scanf_s("%d", &find_id);
	char duyym = getchar();

	printf("������ ��ȭ��ȣ : ");
	gets_s(phone, sizeof(phone));

	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_members[i].id == find_id)
		{
			strcpy_s(g_members[i].phone, sizeof(g_members[i]).phone, phone);
			printf("����Ǿ����ϴ�\n");
			return;
		}
	}
	printf("����\n"); 
}

//����ڷκ��� ������ ���ڸ� �Է¹޴´�.

//�Է��� ���ڸ� �˻��Ѵ�.
//ã���� ���������� �ش� �ε����� ���� -1�� �����Ѵ�.
void con_delete()
{
	printf("delete(����)\n\n");

	int del_id;

	printf("������ ���̵� �Է� : ");
	scanf_s("%d", &del_id);

	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_members[i].id == del_id)
		{
			g_members[i].id = -1;
			strcpy_s(g_members[i].name, sizeof(g_members[i].name), "-");
			strcpy_s(g_members[i].phone, sizeof(g_members[i].phone), "-");
			printf("�����Ǿ����ϴ�\n");
			return;
		}
	}
	printf("����\n");
}