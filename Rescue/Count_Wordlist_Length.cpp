/*********************************************************************************
*函数:
Count_Wordlist_Length(WORDLIST * p)
*描述：
数出单词链表节点数
*被本函数调用：
无
*本函数被调用：
Create_Game_Wordlist(int wordMaxSize, int length)
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdio.h>
#include"Define_Struct.h"

int Count_Wordlist_Length(WORDLIST* p)
{
	WORDLIST* pointer = p;					//指针初始化为首节点
	if (NULL == pointer)	return 0;
	while (NULL != pointer->next)
	{
		pointer = pointer->next;			//指向末节点
	}
	return pointer->num;
}