#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"  // 存有全局变量head 
#include "key.h"
void key()
{
	int key, x;  
	double y;  // x和y为临时存储变量 
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
					while (book->price < 0)
					{
						printf("请输入正确的价钱：");
						scanf("%lf", &book->price);
					}
					if( !InsertBook(head, book) )
					{
						free(book);
						printf("书号重复(已有书籍)\n");
					}
					else
						printf("添加成功\n");
					printf("继续输入书号(-1退出):");
				}
			}
			break;
		case 2:  // 删除书籍 
			printf("请输入要删除的书号：");
			scanf("%d", &x);
			if (DeleteBook(head, x))  // 根据书号删除
				printf("删除成功\n");
			else
				printf("书号不存在\n");
			break;
		case 3:  // 浏览书籍
			display(head);
			break;
		case 4:  // 修改价钱 
			
			printf("请输入要修改价钱的书号:");
			scanf("%d", &x);
			printf("请输入要修改为多少钱:");
			scanf("%lf", &y);
			if (ChangePrice(head, x, y))
				printf("修改成功\n");
			else
				printf("没有找到书号\n");
			break;
		case 5:
			printf("退出成功\n");
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("请输入正确的数字\n");
			while ((x = getchar()) != '\n');  // 清空缓冲区,否则接下来会一直读到缓冲区的数据 
			break;
	} 
}
