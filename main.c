#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "key.h"
#include "struct.h" 
#include "file.h" 
LinkList head;
int main()
{
	head = (LinkList)malloc(sizeof(Node)); 
	head->next = NULL;  // 初始化头结点head
	ReadFile("books.txt", head);  // 把文件里的信息传给head头结点形成链表 
	while (1)
	{
		int a;
		menu();
		key();
		printf("\n\n");
		system("pause");  // 等待用户信号 
		system("cls");
	}
	return  0;
} 
