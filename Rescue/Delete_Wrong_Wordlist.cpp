/*********************************************************************************
*����:
Delete_Wrong_Wordlist(WRONG_WORDLIST * p)
*������
ɾ��WORDLIST����
*�����������ã�
��
*�����������ã�
Add_Result_Part(int resultWordNumber, int resultLength, RESULT_WORDLIST * pResultHead, PLAY_WORDLIST * pAllPartHead)
Game(void)
Randomize_Play_Wordlist(int length, PLAY_WORDLIST * pOrderedPlayWordlistHead)
*���ߣ�
֣�Ŀ�
**********************************************************************************/

#pragma once
#include<stdlib.h>
#include"Define_Struct.h"

void Delete_Wrong_Wordlist(WRONG_WORDLIST* p)
{
	WRONG_WORDLIST* pointer1, *pointer2;
	pointer1 = pointer2 = p;		//ָ���ʼ��Ϊ����ͷ

	while (NULL != pointer1)
	{
		pointer2 = pointer2->next;
		free(pointer1);
		pointer1 = pointer2;
	}
}