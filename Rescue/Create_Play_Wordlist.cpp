#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<process.h>
#include"Define_Struct.h"



/*********************************************************************************
*����:
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*������
ʵ�ִӸ�����ʷ���ݴ�����Ϸ�����б�
*�����������ã�
Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST * pResultHead, PLAY_WORDLIST * pAllPartHead)
Count_Wordlist_Length(WORDLIST *)
Create_All_Part(int allWordlistLength, int allWordNumber, int resultWordNumber, ALL_WORDLIST * pAllWordlistHead)
Randomize_Play_Wordlist(int length, PLAY_WORDLIST * pOrderedPlayWordlistHead)
*�����������ã�
Create_Game_Wordlist(int wordMaxSize, int length)
*���ߣ�
֣�Ŀ�
**********************************************************************************/
PLAY_WORDLIST* Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST* pResultHead, ALL_WORDLIST* pAllWordlistHead)
{
	int Count_Wordlist_Length(WORDLIST*);					//����ƥ������������ĳ���
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
	pAllPartHead = Create_All_Part(allWordlistLength, allWordNumber, resultWordNumber, pAllWordlistHead);	//�ӵ����ܱ��������ȡ������Ϸ����
	pOrderedPlayWordlistHead = Add_Result_Part(resultWordNumber, resultLength, pResultHead, pAllPartHead);		//�Ӽ�����������в��ظ��س�ȡ������������������ǰ��

	PLAY_WORDLIST* pRandomPlayWordlistHead;
	PLAY_WORDLIST* Randomize_Play_Wordlist(int length, PLAY_WORDLIST*pOrderedPlayWordlistHead);
	pRandomPlayWordlistHead = Randomize_Play_Wordlist(length, pOrderedPlayWordlistHead);		//����Ϸ������������

	return pRandomPlayWordlistHead;
}



/*********************************************************************************
*����:
Create_All_Part(int allWordlistLength, int allWordNumber, int resultWordNumber, ALL_WORDLIST * pAllWordlistHead)
*������
ʵ�ִӵ����ܱ��������ȡ������Ϸ���������һ����
*�����������ã�
��
*�����������ã�
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*���ߣ�
֣�Ŀ�
**********************************************************************************/
PLAY_WORDLIST* Create_All_Part(int allWordlistLength, int allWordNumber, int resultWordNumber, ALL_WORDLIST* pAllWordlistHead)
{
	int allRandomArray[30];
	srand(time(NULL) + _getpid()*_getpid());
	for (int i = 0; i < allWordNumber; i++)			//�������������
	{
		int  left = 1, right = allWordlistLength;
		allRandomArray[i] = (rand() % (right - left + 1) + left);
	}
	for (int i = 0; i < allWordNumber - 1; i++)		//�������������������˳������
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

	PLAY_WORDLIST *head, *node, *end;//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣻
	head = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));//�����ַ
	end = head;         //���ǿ�������ͷβ�ڵ�һ��

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
	end->next = NULL;	//��������

	return head->next;
}



/*********************************************************************************
*����:
Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST * pResultHead, PLAY_WORDLIST * pAllPartHead)
*������
ʵ�ִӵ����ܱ��и�����ǰ��Ϸ���������ȡ���ʽ�����Ϸ�����������һ����
*�����������ã�
��
*�����������ã�
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*���ߣ�
֣�Ŀ�
**********************************************************************************/
PLAY_WORDLIST* Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST* pResultHead, PLAY_WORDLIST* pAllPartHead)
{
	if (resultLength > resultWordNumber)
	{
		int resultRandomArray[30];
		srand(time(NULL) + _getpid()*_getpid());	//�õ�ǰʱ����̱߳�������������
		int  left = 1, right = resultLength;
		int candidate;
		for (int i = 0; i < resultWordNumber; )
		{
			candidate = rand() % (right - left + 1) + left;
			int flag = 1;
			for (int j = 0; j < i; j++)	//��֤�������ظ��������
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
		for (int i = 0; i < resultWordNumber - 1; i++)		//��������ʹ���������˳������
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

		PLAY_WORDLIST *head, *node, *end;//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣻
		head = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));//�����ַ
		end = head;         //���ǿ�������ͷβ�ڵ�һ��
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
		end->next = pAllPartHead;	//��������
		void Delete_Wordlist(WORDLIST*);
		Delete_Wordlist(pResultHead);	//ɾ���ͷ��������нڵ�

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
*����:
Randomize_Play_Wordlist(int length, PLAY_WORDLIST * pOrderedPlayWordlistHead)
*������
�������ɵ���Ϸ���������������
*�����������ã�
Delete_Wordlist(WORDLIST *)
*�����������ã�
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST * pResultHead, ALL_WORDLIST * pAllWordlistHead)
*���ߣ�
֣�Ŀ�
**********************************************************************************/
PLAY_WORDLIST* Randomize_Play_Wordlist(int length, PLAY_WORDLIST*pOrderedPlayWordlistHead)
{
	int playRandomArray[30];
	srand(time(NULL) + _getpid()*_getpid());
	int  left = 1, right = length;
	int candidate;
	for (int i = 0; i < length; )		//����������Ϸ�����ȵĲ��ز�©��һά���������
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

	PLAY_WORDLIST *head, *node, *end;//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣻
	head = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));//�����ַ
	end = head;         //���ǿ�������ͷβ�ڵ�һ��

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
	Delete_Wordlist(pOrderedPlayWordlistHead);	//ɾ���ͷ��������нڵ�

	return head->next;
}