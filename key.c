#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"  // ����ȫ�ֱ���head 
#include "key.h"
void key()
{
	int key, x;  
	double y;  // x��yΪ��ʱ�洢���� 
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
					while (book->price < 0)
					{
						printf("��������ȷ�ļ�Ǯ��");
						scanf("%lf", &book->price);
					}
					if( !InsertBook(head, book) )
					{
						free(book);
						printf("����ظ�(�����鼮)\n");
					}
					else
						printf("��ӳɹ�\n");
					printf("�����������(-1�˳�):");
				}
			}
			break;
		case 2:  // ɾ���鼮 
			printf("������Ҫɾ������ţ�");
			scanf("%d", &x);
			if (DeleteBook(head, x))  // �������ɾ��
				printf("ɾ���ɹ�\n");
			else
				printf("��Ų�����\n");
			break;
		case 3:  // ����鼮
			display(head);
			break;
		case 4:  // �޸ļ�Ǯ 
			
			printf("������Ҫ�޸ļ�Ǯ�����:");
			scanf("%d", &x);
			printf("������Ҫ�޸�Ϊ����Ǯ:");
			scanf("%lf", &y);
			if (ChangePrice(head, x, y))
				printf("�޸ĳɹ�\n");
			else
				printf("û���ҵ����\n");
			break;
		case 5:
			printf("�˳��ɹ�\n");
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("��������ȷ������\n");
			while ((x = getchar()) != '\n');  // ��ջ�����,�����������һֱ���������������� 
			break;
	} 
}
