/*********************************************************************************
*����:
Search_Wordlist(TARGET_WORDLIST * pTargetHead, ALL_WORDLIST * pAllHead)
*������
����Sunday�㷨�ӵ����ܱ���ƥ��������ƶ��ַ����ĵ��ʲ���������
*�����������ã�
FindIndex(char * target, char temp) 
*�����������ã�
Create_Game_Wordlist(int wordMaxSize, int length) 
*���ߣ�
֣�Ŀ�
**********************************************************************************/


#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Define_Struct.h"

RESULT_WORDLIST* Search_Wordlist(TARGET_WORDLIST* pTargetHead, ALL_WORDLIST* pAllHead)
{
	int FindIndex(char *target, char temp);
	void Delete_Target_Wordlist(TARGET_WORDLIST* p);	//ɾ���ͷ�targetlist�������нڵ�

	TARGET_WORDLIST* pTarget;
	ALL_WORDLIST* pAll;
	RESULT_WORDLIST *head, *node, *end;//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣻
	head = (RESULT_WORDLIST*)malloc(sizeof(RESULT_WORDLIST));//�����ַ
	end = head;         //���ǿ�������ͷβ�ڵ�һ��

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
				else						//���ֲ����λ��
				{
					temp = tarlen - j + i;  //�ַ�������ĵ�һ���ַ�λ��
					index = FindIndex(pTarget->target, (pAll->word)[temp]);
					if (-1 == index)
					{
						i = temp + 1;		//δ�ҵ�λ�ã�����
					}
					else
					{
						i = temp - index;	 //�ҵ�λ��
					}
					j = 0;
				}
			}
		}
	}
	end->next = NULL;

	Delete_Target_Wordlist(pTargetHead);	//ɾ���ͷ�targetlist�������нڵ�

	return head->next;
}

int FindIndex(char *target, char temp) {
	int i = 0;
	if (target == NULL)
	{
		printf("������Ϊ��...");
		exit(-1); //�쳣�˳�
	}
	for (i = strlen(target) - 1; i >= 0; i--)
	{
		if (target[i] == temp)	return i;
	}
	return -1;  //δ�ҵ��ַ�ƥ��λ��
}
