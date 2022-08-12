#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "key.h"
#include "struct.h"  // 存有全局变量head 
int main()
{
	head = (LinkList)malloc(sizeof(Node)); 
	head->next = NULL;  // 初始化头结点head
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
