/*********************************************************************************
*函数:
Delete_Wrong_Wordlist(WRONG_WORDLIST * p)
*描述：
删除WORDLIST链表
*被本函数调用：
无
*本函数被调用：
Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST * pResultHead, PLAY_WORDLIST * pAllPartHead)
Game(void)
Randomize_Play_Wordlist(int length, PLAY_WORDLIST * pOrderedPlayWordlistHead)
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdlib.h>
#include"Define_Struct.h"

void Delete_Wrong_Wordlist(WRONG_WORDLIST* p)
{
	WRONG_WORDLIST* pointer1, *pointer2;
	pointer1 = pointer2 = p;		//指针初始化为链表头

	while (NULL != pointer1)
	{
		pointer2 = pointer2->next;
		free(pointer1);
		pointer1 = pointer2;
	}
}