#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
void SaveFile(const char * file, LinkList L)  // ���浽�ļ�(ÿ���޸�����ʱ�͵��ô˺���)
{
	FILE *fp;
	fp = fopen(file, "w+");  // ѡ��"w+"��������ļ�֮ǰ���� 
	L = L->next;
	while (L != NULL)
	{
		fprintf(fp, "%d\t%s\t%f\n", L->number, L->name, L->price);  // ע����fp������file 
		L = L->next;
	}
	fclose(fp);
}
void ReadFile(const char * file, LinkList L)  // ��ȡ�ļ�
{
	FILE *fp;
	fp = fopen(file, "r");
	if (fp == NULL) 
		fp = fopen(file, "w+");  // �����ļ� 
	LinkList node = (LinkList)malloc(sizeof(Node));
	node->next = NULL;
	while (fscanf(fp, "%d%s%lf", &node->number, node->name, &node->price) == 3) // �����ļ���β�᷵��EOF 
	{
		InsertBook(L, node);
		node = (LinkList)malloc(sizeof(Node));  // ÿ�β����µĶ���Ҫ�����ڴ� 
		node->next = NULL;
	}	
	free(node);  // ��������һ���ڴ���� 
	fclose(fp);
}
