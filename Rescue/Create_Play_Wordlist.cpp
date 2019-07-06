#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<process.h>
#include"Define_Struct.h"



/*********************************************************************************
*函数:
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*描述：
实现从根据历史数据创建游戏单词列表
*被本函数调用：
Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST * pResultHead, PLAY_WORDLIST * pAllPartHead)
Count_Wordlist_Length(WORDLIST *)
Create_All_Part(int allWordlistLength, int allWordNumber, int resultWordNumber, ALL_WORDLIST * pAllWordlistHead)
Randomize_Play_Wordlist(int length, PLAY_WORDLIST * pOrderedPlayWordlistHead)
*本函数被调用：
Create_Game_Wordlist(int wordMaxSize, int length)
*作者：
郑文俊
**********************************************************************************/
PLAY_WORDLIST* Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST* pResultHead, ALL_WORDLIST* pAllWordlistHead)
{
	int Count_Wordlist_Length(WORDLIST*);					//数出匹配结果单词链表的长度
	int resultLength = Count_Wordlist_Length(pResultHead);
	int resultWordNumber, allWordNumber;

	if (resultLength > (2 * length / 3))
	{
		resultWordNumber = (int)(2 * length / 3);
	}
	else
	{
		resultWordNumber = resultLength;
	}
	allWordNumber = length - resultWordNumber;

	PLAY_WORDLIST* pAllPartHead;
	PLAY_WORDLIST* pOrderedPlayWordlistHead;

	PLAY_WORDLIST* Create_All_Part(int allWordlistLength, int allWordNumber, int resultWordNumber, ALL_WORDLIST* pAllWordlistHead);
	PLAY_WORDLIST* Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST* pResultHead, PLAY_WORDLIST* pAllPartHead);
	pAllPartHead = Create_All_Part(allWordlistLength, allWordNumber, resultWordNumber, pAllWordlistHead);	//从单词总表中随机抽取建立游戏链表
	pOrderedPlayWordlistHead = Add_Result_Part(resultWordNumber, resultLength, pResultHead, pAllPartHead);		//从检索结果链表中不重复地抽取建立链表并接在上述表前面

	PLAY_WORDLIST* pRandomPlayWordlistHead;
	PLAY_WORDLIST* Randomize_Play_Wordlist(int length, PLAY_WORDLIST*pOrderedPlayWordlistHead);
	pRandomPlayWordlistHead = Randomize_Play_Wordlist(length, pOrderedPlayWordlistHead);		//让游戏链表的随机排列

	return pRandomPlayWordlistHead;
}



/*********************************************************************************
*函数:
Create_All_Part(int allWordlistLength, int allWordNumber, int resultWordNumber, ALL_WORDLIST * pAllWordlistHead)
*描述：
实现从单词总表中随机提取建立游戏单词链表的一部分
*被本函数调用：
无
*本函数被调用：
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*作者：
郑文俊
**********************************************************************************/
PLAY_WORDLIST* Create_All_Part(int allWordlistLength, int allWordNumber, int resultWordNumber, ALL_WORDLIST* pAllWordlistHead)
{
	int allRandomArray[30];
	srand(time(NULL) + _getpid()*_getpid());
	for (int i = 0; i < allWordNumber; i++)			//生成随机数数组
	{
		int  left = 1, right = allWordlistLength;
		allRandomArray[i] = (rand() % (right - left + 1) + left);
	}
	for (int i = 0; i < allWordNumber - 1; i++)		//交换排序，让随机数数组顺序排列
	{
		for (int j = i + 1; j < allWordNumber; j++)
		{
			if (allRandomArray[i] > allRandomArray[j])
			{
				int temp = allRandomArray[i];
				allRandomArray[i] = allRandomArray[j];
				allRandomArray[j] = temp;
			}
		}
	}

	PLAY_WORDLIST *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));//分配地址
	end = head;         //若是空链表则头尾节点一样

	ALL_WORDLIST* pAllList = pAllWordlistHead;
	int i = 0;
	while (i < allWordNumber || pAllList != NULL)
	{
		if (pAllList->num == allRandomArray[i])
		{
			node = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));
			node->num = resultWordNumber + i + 1;
			strncpy_s(node->word, pAllList->word, 17);
			end->next = node;
			end = node;
			i++;
		}
		else
		{
			pAllList = pAllList->next;
		}
	}
	end->next = NULL;	//结束创建

	return head->next;
}



/*********************************************************************************
*函数:
Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST * pResultHead, PLAY_WORDLIST * pAllPartHead)
*描述：
实现从单词总表中根据以前游戏错误情况提取单词建立游戏单词链表的另一部分
*被本函数调用：
无
*本函数被调用：
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*作者：
郑文俊
**********************************************************************************/
PLAY_WORDLIST* Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST* pResultHead, PLAY_WORDLIST* pAllPartHead)
{
	if (resultLength > resultWordNumber)
	{
		int resultRandomArray[30];
		srand(time(NULL) + _getpid()*_getpid());	//用当前时间和线程编号做随机数种子
		int  left = 1, right = resultLength;
		int candidate;
		for (int i = 0; i < resultWordNumber; )
		{
			candidate = rand() % (right - left + 1) + left;
			int flag = 1;
			for (int j = 0; j < i; j++)	//保证生成无重复的随机数
			{
				if (candidate == resultRandomArray[j])
				{
					flag = 0;
					break;
				}
			}
			if (1 == flag)
			{
				resultRandomArray[i] = candidate;
				i++;
			}
		}
		for (int i = 0; i < resultWordNumber - 1; i++)		//交换排序，使随机数数组顺序排列
		{
			for (int j = i + 1; j < resultWordNumber; j++)
			{
				if (resultRandomArray[i] > resultRandomArray[j])
				{
					int temp = resultRandomArray[i];
					resultRandomArray[i] = resultRandomArray[j];
					resultRandomArray[j] = temp;
				}
			}
		}

		PLAY_WORDLIST *head, *node, *end;//定义头节点，普通节点，尾部节点；
		head = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));//分配地址
		end = head;         //若是空链表则头尾节点一样
		RESULT_WORDLIST* pResultList = pResultHead;
		int i = 0;
		while (i < resultWordNumber || pResultList != NULL)
		{
			if (pResultList->num == resultRandomArray[i])
			{
				node = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));
				node->num = i + 1;
				strncpy_s(node->word, pResultList->word, 17);
				end->next = node;
				end = node;
				i++;
			}
			else
			{
				pResultList = pResultList->next;
			}
		}
		end->next = pAllPartHead;	//结束创建
		void Delete_Wordlist(WORDLIST*);
		Delete_Wordlist(pResultHead);	//删除释放链表所有节点

		return head->next;

	}
	else if (resultLength > 0)
	{
		PLAY_WORDLIST* pointer;
		for (pointer = pResultHead; NULL != pointer->next; pointer = pointer->next);
		pointer->next = pAllPartHead;
		return pResultHead;
	}
	else
	{
		return pAllPartHead;
	}
}



/*********************************************************************************
*函数:
Randomize_Play_Wordlist(int length, PLAY_WORDLIST * pOrderedPlayWordlistHead)
*描述：
把已生成的游戏单词链表随机排序
*被本函数调用：
Delete_Wordlist(WORDLIST *)
*本函数被调用：
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*作者：
郑文俊
**********************************************************************************/
PLAY_WORDLIST* Randomize_Play_Wordlist(int length, PLAY_WORDLIST*pOrderedPlayWordlistHead)
{
	int playRandomArray[30];
	srand(time(NULL) + _getpid()*_getpid());
	int  left = 1, right = length;
	int candidate;
	for (int i = 0; i < length; )		//生成满足游戏链表长度的不重不漏的一维随机数数组
	{
		candidate = (rand() % (right - left + 1) + left);
		int flag = 1;
		for (int j = 0; j < i; j++)
		{
			if (candidate == playRandomArray[j])
			{
				flag = 0;
				break;
			}
		}
		if (1 == flag)
		{
			playRandomArray[i] = candidate;
			i++;
		}
	}

	PLAY_WORDLIST *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));//分配地址
	end = head;         //若是空链表则头尾节点一样

	for (int i = 0; i < length; i++)
	{
		PLAY_WORDLIST* pOrderedPlayWordlist = pOrderedPlayWordlistHead;
		while (pOrderedPlayWordlist->num != playRandomArray[i])
		{
			pOrderedPlayWordlist = pOrderedPlayWordlist->next;
		}
		node = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));
		node->num = i + 1;
		strncpy_s(node->word, pOrderedPlayWordlist->word, 17);
		end->next = node;
		end = node;
	}
	end->next = NULL;

	void Delete_Wordlist(WORDLIST*);
	Delete_Wordlist(pOrderedPlayWordlistHead);	//删除释放链表所有节点

	return head->next;
}