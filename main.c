#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "key.h"
#include "struct.h"  // ����ȫ�ֱ���head 
int main()
{
	head = (LinkList)malloc(sizeof(Node)); 
	head->next = NULL;  // ��ʼ��ͷ���head
	while (1)
	{
		int a;
		menu();
		key();
		printf("\n\n");
		system("pause");  // �ȴ��û��ź� 
		system("cls");
	}
	return  0;
} 
