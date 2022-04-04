#pragma once

// 타입명 : struct tagMember
// 멤버의 갯수 : 3개
// 타입의 크기 : 44byte

// 기존에 있는 타입의 새로운 식별자를 정의!
typedef unsigned int unit;

typedef struct tagMember member;
struct tagMember
{
	int id;
	char name[20];
	char phone[20];
};