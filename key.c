#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"  // ����ȫ�ֱ���head 
void key()
{
	int key, x;
	scanf("%d", &key);
	LinkList book = (LinkList)malloc(sizeof(Node));  // ����һ����ʱ�鼮���
	book->next = NULL;
	switch (key)
	{
		case 1:  // ����鼮 
			printf("�������鼮��Ϣ(��š���������Ǯ):");
			scanf("%d%s%lf", &book->number, book->name, &book->price);
			InsertBook(head, book);
			break;
		case 2:  // ɾ���鼮 
			printf("������Ҫɾ������ţ�");
			scanf("%d", &x);
			if (DeleteBook(head, x))  // �������ɾ��
				printf("delete finish\n");
			else
				printf("delete error\n");
			break;
		case 3:  // ����鼮 
			display(head);
			break;
		case 4:
			printf("�����ҡ�\n");
			break;
		case 5:
			printf("�˳��ɹ�\n");
			exit(EXIT_SUCCESS);
			break;
	} 
}
