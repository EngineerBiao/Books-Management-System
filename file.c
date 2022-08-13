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
	fp = fopen(file, "r");  // �ļ������ڻ᷵��0
	if (fp == NULL || fp == 0)
		fp = fopen(file, "w+");  // �����ļ� 
	LinkList node = L->next;
	while (fscanf(fp, "%d%s%lf", &node->number, node->name, &node->price) != EOF && fscanf(fp, "%d%s%lf", &node->number, node->name, &node->price) != 0) // �����ļ���β�᷵��EOF 
		InsertBook(L, node);
} 
