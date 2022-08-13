#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"
void display(LinkList L)
{
	L = L->next;
	if (L)
	{
		printf("书号%*s书名%*s价钱\n", 4, "", 14, "");
		while (L != NULL)
		{
			printf("%-8d%-18s%.1f\n", L->number, L->name, L->price);
			L = L->next;
		}
	}
	else
		printf("目前暂无书籍\n");
}
bool InsertBook(LinkList L, LinkList book)  // 按书号顺序插入 
{
	LinkList node = L;
	if (node->next != NULL)  // 根据书号找到对应位置 
	{
		while (node->next != NULL && node->next->number <= book->number)
		{
			if (node->next->number == book->number)  // 判断书号是否重复 
				return false;
			node = node->next;
		}
	}
	book->next = node->next;
	node->next = book;
	return true;
}
bool DeleteBook(LinkList L, int x)
{
	LinkList p = L->next;
	while (p != NULL && p->number != x)
	{
		L = p;
		p = p->next;
	}
	if (p != NULL)
	{
		L->next = p->next;
		free(p);
		return true;
	}
	else
		return false;
}
bool ChangePrice(LinkList L, int x, double y)
{
	while (L->next != NULL && L->next->number != x)
		L = L->next;
	if (L->next == NULL)  // 没有找到书号 
		return false;
	else
	{
		L->next->price = y;
		return true;
	}	
		
}


