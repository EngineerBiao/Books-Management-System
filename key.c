#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"  // ����ȫ�ֱ���head 
void key()
{
	int key, x;
	scanf("%d", &key);
	switch (key)
	{
		case 1:  // ����鼮 
			printf("���������:");
			while (1)
			{
				LinkList book = (LinkList)malloc(sizeof(Node));  // ����һ����ʱ�鼮���(һ��Ҫ��whileѭ���ﴴ������Ϊ�� 
				book->next = NULL;								 // �������鼮ÿ�ζ���Ҫ�����µ��ڴ�ռ�)
				scanf("%d", &book->number);
				if (book->number == -1)
				{
					free(book);
					printf("��ӽ���\n");
					break;
				}
				else
				{
					printf("�����������ͼ�Ǯ(�ո�ֿ�):");
					scanf("%s%lf", book->name, &book->price);
					InsertBook(head, book);
					printf("�����������(-1�˳�):");
				}
			}
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
