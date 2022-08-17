#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
void SaveFile(const char * file, LinkList L)  // 保存到文件(每次修改链表时就调用此函数)
{
	FILE *fp;
	fp = fopen(file, "w+");  // 选项"w+"可以清空文件之前内容 
	L = L->next;
	while (L != NULL)
	{
		fprintf(fp, "%d\t%s\t%f\n", L->number, L->name, L->price);  // 注意是fp而不是file 
		L = L->next;
	}
	fclose(fp);
}
void ReadFile(const char * file, LinkList L)  // 读取文件
{
	FILE *fp;
	fp = fopen(file, "r");
	if (fp == NULL) 
		fp = fopen(file, "w+");  // 创建文件 
	LinkList node = (LinkList)malloc(sizeof(Node));
	node->next = NULL;
	while (fscanf(fp, "%d%s%lf", &node->number, node->name, &node->price) == 3) // 读到文件结尾会返回EOF 
	{
		InsertBook(L, node);
		node = (LinkList)malloc(sizeof(Node));  // 每次插入新的都需要创建内存 
		node->next = NULL;
	}	
	free(node);  // 最后会多出来一次内存分配 
	fclose(fp);
}
