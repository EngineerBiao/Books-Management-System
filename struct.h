#ifndef __STRUCT_H_
#define __STRUCT_H_
#include <stdbool.h> 
typedef struct book {
	int number;  // ��� 
	char name[20]; // ���� 
	double price;// ��ļ�Ǯ
	struct book * next;
} Node, *LinkList;
extern LinkList head;  // ���������Ա�ȫ��ʹ�� 
void display(LinkList L);
void InsertBook(LinkList L, LinkList book);
bool DeleteBook(LinkList L, int x);
#endif
