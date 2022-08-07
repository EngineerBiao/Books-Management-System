#ifndef __STRUCT_H_
#define __STRUCT_H_
#include <stdbool.h> 
typedef struct book {
	int number;  // 书号 
	char name[20]; // 书名 
	double price;// 书的价钱
	struct book * next;
} Node, *LinkList;
extern LinkList head;  // 声明变量以便全局使用 
void display(LinkList L);
void InsertBook(LinkList L, LinkList book);
bool DeleteBook(LinkList L, int x);
#endif
