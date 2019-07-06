/*********************************************************************************
*����:
Rewrite_Wrong_Wordlist(WRONG_WORDLIST * wrongWordlistHead, int * pTargetStringAmount)
*������
��д���󵥴������Ѵ��󵥴ʸ�д��Ŀ���ַ�����
*�����������ã�
��
*�����������ã�
Write_In_Data(WRONG_WORDLIST * wrongWordlistHead, int length, int gameTime, int numberOfSuccessWords) 
*���ߣ�
֣�Ŀ�
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

	while ((NULL != pointer1) && (pointer1->wrongLocation < 2))	//pointer1ָ���һ������λǰ������2����ĸ�Ľڵ�
	{
		WRONG_WORDLIST * pTemp = pointer1;
		pointer1 = pointer1->next;
		free(pTemp);
	}

	if (NULL == pointer1)					//���û�е�������Ҫ��
	{
		targetStringAmount = 0;
	}
	else
	{
		pNewWronglistHead = pointer1;		//pNewWronglistHeadָ��������
		pointer2 = pointer1;

		/*ֻ��������λǰ������2����ĸ�Ľڵ�*/
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