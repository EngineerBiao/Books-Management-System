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
void InsertBook(LinkList L, LinkList book)  // �����˳����� 
{
	LinkList node = L;
	if (node->next != NULL)  // ��������ҵ���Ӧλ�� 
	{
		while (node->next != NULL && node->next->number < book->number)
		{
			node = node->next;
		}
	}
	book->next = node->next;
	node->next = book;
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



