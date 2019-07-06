/*********************************************************************************
*函数:
Rewrite_Wrong_Wordlist(WRONG_WORDLIST * wrongWordlistHead, int * pTargetStringAmount)
*描述：
改写错误单词链表（把错误单词改写成目标字符串）
*被本函数调用：
无
*本函数被调用：
Write_In_Data(WRONG_WORDLIST * wrongWordlistHead, int length, int gameTime, int numberOfSuccessWords) 
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<string.h>
#include<stdlib.h>
#include"Define_Struct.h"

WRONG_WORDLIST* Rewrite_Wrong_Wordlist(WRONG_WORDLIST* wrongWordlistHead, int* pTargetStringAmount)
{
	WRONG_WORDLIST * pointer1 = wrongWordlistHead;
	WRONG_WORDLIST * pointer2 = wrongWordlistHead;
	WRONG_WORDLIST * pNewWronglistHead = NULL;
	int targetStringAmount = 0;

	while ((NULL != pointer1) && (pointer1->wrongLocation < 2))	//pointer1指向第一个错误位前不少于2个字母的节点
	{
		WRONG_WORDLIST * pTemp = pointer1;
		pointer1 = pointer1->next;
		free(pTemp);
	}

	if (NULL == pointer1)					//如果没有单词满足要求
	{
		targetStringAmount = 0;
	}
	else
	{
		pNewWronglistHead = pointer1;		//pNewWronglistHead指向新链表
		pointer2 = pointer1;

		/*只保留错误位前不少于2个字母的节点*/
		do
		{
			if (pointer2->wrongLocation >= 2)
			{
				strncpy_s(pointer2->word, (pointer2->word) + (pointer2->wrongLocation) - 2, 3);
				(pointer2->word)[3] = '\0';
				pointer1 = pointer2;
				pointer2 = pointer2->next;
				targetStringAmount++;
			}
			else
			{
				pointer1->next = pointer2->next;
				free(pointer2);
				pointer2 = pointer1->next;
			}
		} while (NULL != pointer2);
	}
	*pTargetStringAmount = targetStringAmount;

	return pNewWronglistHead;
}