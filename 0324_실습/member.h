#pragma once

// Ÿ�Ը� : struct tagMember
// ����� ���� : 3��
// Ÿ���� ũ�� : 44byte

// ������ �ִ� Ÿ���� ���ο� �ĺ��ڸ� ����!
typedef unsigned int unit;

typedef struct tagMember member;
struct tagMember
{
	int id;
	char name[20];
	char phone[20];
};