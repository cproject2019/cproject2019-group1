/*********************************************************************************
*函数:
Search_Wordlist(TARGET_WORDLIST * pTargetHead, ALL_WORDLIST * pAllHead)
*描述：
根据Sunday算法从单词总表中匹配出含有制定字符串的单词并建立链表
*被本函数调用：
FindIndex(char * target, char temp) 
*本函数被调用：
Create_Game_Wordlist(int wordMaxSize, int length) 
*作者：
郑文俊
**********************************************************************************/


#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Define_Struct.h"

RESULT_WORDLIST* Search_Wordlist(TARGET_WORDLIST* pTargetHead, ALL_WORDLIST* pAllHead)
{
	int FindIndex(char *target, char temp);
	void Delete_Target_Wordlist(TARGET_WORDLIST* p);	//删除释放targetlist链表所有节点

	TARGET_WORDLIST* pTarget;
	ALL_WORDLIST* pAll;
	RESULT_WORDLIST *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = (RESULT_WORDLIST*)malloc(sizeof(RESULT_WORDLIST));//分配地址
	end = head;         //若是空链表则头尾节点一样

	int count = 1;
	for (pTarget = pTargetHead; NULL != pTarget; pTarget = pTarget->next)
	{
		for (pAll = pAllHead; NULL != pAll; pAll = pAll->next)
		{
			int i = 0, j = 0, srclen = strlen(pAll->word), tarlen = strlen(pTarget->target);
			int temp = 0, index = -1;
			while (i < srclen)
			{
				if ((pAll->word)[i] == (pTarget->target)[j])
				{
					if (tarlen - 1 == j)
					{
						node = (RESULT_WORDLIST*)malloc(sizeof(RESULT_WORDLIST));
						node->num = count;
						strncpy_s(node->word, pAll->word, 17);
						end->next = node;
						end = node;
						count++;
					}
					i++; j++;
				}
				else						//发现不相等位置
				{
					temp = tarlen - j + i;  //字符串后面的第一个字符位置
					index = FindIndex(pTarget->target, (pAll->word)[temp]);
					if (-1 == index)
					{
						i = temp + 1;		//未找到位置，后移
					}
					else
					{
						i = temp - index;	 //找到位置
					}
					j = 0;
				}
			}
		}
	}
	end->next = NULL;

	Delete_Target_Wordlist(pTargetHead);	//删除释放targetlist链表所有节点

	return head->next;
}

int FindIndex(char *target, char temp) {
	int i = 0;
	if (target == NULL)
	{
		printf("搜索词为空...");
		exit(-1); //异常退出
	}
	for (i = strlen(target) - 1; i >= 0; i--)
	{
		if (target[i] == temp)	return i;
	}
	return -1;  //未找到字符匹配位置
}
