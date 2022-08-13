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
	fp = fopen(file, "r");  // 文件不存在会返回0
	if (fp == NULL || fp == 0)
		fp = fopen(file, "w+");  // 创建文件 
	LinkList node = L->next;
	while (fscanf(fp, "%d%s%lf", &node->number, node->name, &node->price) != EOF && fscanf(fp, "%d%s%lf", &node->number, node->name, &node->price) != 0) // 读到文件结尾会返回EOF 
		InsertBook(L, node);
} 
