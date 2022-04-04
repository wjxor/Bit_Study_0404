//control.c

#include "std.h"

#define DATA_MAX	5

// int		g_id[DATA_MAX];
// char	g_name[DATA_MAX][20];
// char	g_phone[DATA_MAX][20];

member g_members[DATA_MAX];


//g_id의 모든 값들을 -1으로 초기화..
//g_name과 g_phone의 모든 문자열을 "" 초기화 
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

//전역변수의 모든 값들 출력
//예) 
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
* 비어있는 공간에만 값을 저장하고 싶다..............
* [변수 선언 및 사용자 입력을 통한 초기화]
* 저장할 위치(0~9) : 
* 저장할 값 : 
* [연산] 전역변수의 해당 위치에 저장할 값 저장!* 
* [결과 출력]
*/
void con_insert()
{
	printf("[insert(저장)\n\n");

	int idx, id;
	char name[20], phone[20];

	printf("저장할 위치(0~%d) : ", DATA_MAX-1);
	scanf_s("%d", &idx);

	printf("아이디 : ");			scanf_s("%d", &id);
	char dummy = getchar();
	printf("이름 : ");			gets_s(name, sizeof(name));
	printf("전화번호 : ");		gets_s(phone, sizeof(phone));

	if (g_members[idx].id == -1)
	{
		g_members[idx].id = id;
		strcpy_s(g_members[idx].name, sizeof(g_members[idx].name), name);
		strcpy_s(g_members[idx].phone, sizeof(g_members[idx].phone), phone);
		printf("저장되었습니다\n");
	}
	else
	{
		printf("이미 저장된 위치입니다\n");
	}
}


/*
* 사용자로부터 정수를 입력받는다.
* 입력된 정수가 전역배열에 저장되어 있는지 검색.....[선형검색]
* 결과 출력
* - 저장된 인덱스 :
* - 저장된 값 : 
*/
void con_select()
{
	printf("select(검색)\n\n");

	int id;
	printf("찾고자 하는 정수 입력 : ");
	scanf_s("%d", &id);

	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_members[i].id == id)
		{
			printf("저장된 인덱스 : %d\n", i);
			printf("아 이 디 : %d\n", g_members[i].id);
			printf("이   름 : %s\n", g_members[i].name);
			printf("전화번호 : %s\n", g_members[i].phone);
			return;
		}		
	}
	printf("없다\n");
}

//사용자로부터 아이디와 전화번호를 입력받는다.
//숫자가 저장된 인덱스를 검색(con_select)
//찾으면 전역변수의 해당 인덱스에 수정할 숫자를 저장한다.

//결과를 출력한다.
void con_update()
{
	printf("update(수정)\n\n");

	int find_id;
	char phone[20];

	printf("찾고자 하는 아이디 : "); 
	scanf_s("%d", &find_id);
	char duyym = getchar();

	printf("변경할 전화번호 : ");
	gets_s(phone, sizeof(phone));

	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_members[i].id == find_id)
		{
			strcpy_s(g_members[i].phone, sizeof(g_members[i]).phone, phone);
			printf("변경되었습니다\n");
			return;
		}
	}
	printf("없다\n"); 
}

//사용자로부터 삭제할 숫자를 입력받는다.

//입력한 숫자를 검색한다.
//찾으면 전역변수의 해당 인덱스의 값을 -1을 저장한다.
void con_delete()
{
	printf("delete(삭제)\n\n");

	int del_id;

	printf("삭제할 아이디 입력 : ");
	scanf_s("%d", &del_id);

	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_members[i].id == del_id)
		{
			g_members[i].id = -1;
			strcpy_s(g_members[i].name, sizeof(g_members[i].name), "-");
			strcpy_s(g_members[i].phone, sizeof(g_members[i].phone), "-");
			printf("삭제되었습니다\n");
			return;
		}
	}
	printf("없다\n");
}