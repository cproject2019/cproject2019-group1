/*********************************************************************************
*函数:
Delete_Target_Wordlist(TARGET_WORDLIST * pTargetHead)
*描述：
删除TARGET_WORDLIST链表
*被本函数调用：
无
*本函数被调用：
Search_Wordlist(TARGET_WORDLIST * pTargetHead, ALL_WORDLIST * pAllHead)
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdlib.h>
#include"Define_Struct.h"

void Delete_Target_Wordlist(TARGET_WORDLIST* pTargetHead)
{
	TARGET_WORDLIST* pointer1, *pointer2;
	pointer1 = pointer2 = pTargetHead;		//指针初始化为链表头

	while (NULL != pointer1)
	{
		pointer2 = pointer2->next;
		free(pointer1);
		pointer1 = pointer2;
	}
}
