#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"  // 存有全局变量head 
void key()
{
	int key, x;
	scanf("%d", &key);
	LinkList book = (LinkList)malloc(sizeof(Node));  // 创建一个临时书籍结点
	book->next = NULL;
	switch (key)
	{
		case 1:  // 添加书籍 
			printf("请输入书籍信息(书号、书名、价钱):");
			scanf("%d%s%lf", &book->number, book->name, &book->price);
			InsertBook(head, book);
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
