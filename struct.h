#ifndef __STRUCT_H_
#define __STRUCT_H_
#include <stdbool.h> 
typedef struct book {
	int number;  // 书号 
	char name[20]; // 书名 
	double price;  // 书的价钱
	struct book * next;
} Node, *LinkList;  // Linklist等价于struct node *
LinkList head;  // 声明变量以便全局使用 
void display(LinkList L);
bool InsertBook(LinkList L, LinkList book);
bool DeleteBook(LinkList L, int x);
bool ChangePrice(LinkList L, int x, double y);
#endif
