#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"  // 存有全局变量head 
void key()
{
	int key, x;
	scanf("%d", &key);
	switch (key)
	{
		case 1:  // 添加书籍 
			printf("请输入书号:");
			while (1)
			{
				LinkList book = (LinkList)malloc(sizeof(Node));  // 创建一个临时书籍结点(一定要在while循环里创建，因为连 
				book->next = NULL;								 // 续输入书籍每次都需要分配新的内存空间)
				scanf("%d", &book->number);
				if (book->number == -1)
				{
					free(book);
					printf("添加结束\n");
					break;
				}
				else
				{
					printf("请输入书名和价钱(空格分开):");
					scanf("%s%lf", book->name, &book->price);
					InsertBook(head, book);
					printf("继续输入书号(-1退出):");
				}
			}
			break;
		case 2:  // 删除书籍 
			printf("请输入要删除的书号：");
			scanf("%d", &x);
			if (DeleteBook(head, x))  // 根据书号删除
				printf("delete finish\n");
			else
				printf("delete error\n");
			break;
		case 3:  // 浏览书籍 
			display(head);
			break;
		case 4:
			printf("【查找】\n");
			break;
		case 5:
			printf("退出成功\n");
			exit(EXIT_SUCCESS);
			break;
	} 
}
