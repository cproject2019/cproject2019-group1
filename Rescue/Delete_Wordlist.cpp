/*********************************************************************************
*函数:
Delete_Wordlist(WORDLIST * p) 
*描述：
删除WRONG_WORDLIST链表
*被本函数调用：
无
*本函数被调用：
Game(void)
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdlib.h>
#include"Define_Struct.h"

void Delete_Wordlist(WORDLIST* p)
{
	WORDLIST* pointer1, *pointer2;
	pointer1 = pointer2 = p;		//指针初始化为链表头

	while ( NULL != pointer1)
	{
		pointer2 = pointer2->next;
		free(pointer1);
		pointer1 = pointer2;
	}
}