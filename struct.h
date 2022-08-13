#ifndef __STRUCT_H_
#define __STRUCT_H_
#include <stdbool.h> 
typedef struct book {
	int number;  // ��� 
	char name[20]; // ���� 
	double price;  // ��ļ�Ǯ
	struct book * next;
} Node, *LinkList;  // Linklist�ȼ���struct node *
LinkList head;  // ���������Ա�ȫ��ʹ�� 
void display(LinkList L);
bool InsertBook(LinkList L, LinkList book);
bool DeleteBook(LinkList L, int x);
bool ChangePrice(LinkList L, int x, double y);
#endif
