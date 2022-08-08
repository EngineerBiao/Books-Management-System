#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct book {
	int number;  // ��� 
	char name[20]; // ���� 
	double price;// ��ļ�Ǯ
	struct book * next;
} Node, *LinkList;
LinkList head;
void display(LinkList L)
{
	L = L->next;
	if (L)
	{
		printf("���\t����\t��Ǯ\n");
		while (L != NULL)
		{
			printf("%d\t%s\t%.1f\n", L->number, L->name, L->price);
			L = L->next;
		}
	}
	else
		printf("Ŀǰ�����鼮\n");
}
bool InsertBook(LinkList L, LinkList book)  // �����˳����� 
{
	LinkList node = L;
	if (node->next != NULL)  // ��������ҵ���Ӧλ�� 
	{
		while (node->next != NULL && node->next->number <= book->number)
		{
			if (node->next->number == book->number)  // �ж�����Ƿ��ظ� 
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
	if (L->next == NULL)  // û���ҵ���� 
		return false;
	else
	{
		L->next->price = y;
		return true;
	}	
		
}


