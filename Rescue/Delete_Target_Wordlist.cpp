/*********************************************************************************
*����:
Delete_Target_Wordlist(TARGET_WORDLIST * pTargetHead)
*������
ɾ��TARGET_WORDLIST����
*�����������ã�
��
*�����������ã�
Search_Wordlist(TARGET_WORDLIST * pTargetHead, ALL_WORDLIST * pAllHead)
*���ߣ�
֣�Ŀ�
**********************************************************************************/

#pragma once
#include<stdlib.h>
#include"Define_Struct.h"

void Delete_Target_Wordlist(TARGET_WORDLIST* pTargetHead)
{
	TARGET_WORDLIST* pointer1, *pointer2;
	pointer1 = pointer2 = pTargetHead;		//ָ���ʼ��Ϊ����ͷ

	while (NULL != pointer1)
	{
		pointer2 = pointer2->next;
		free(pointer1);
		pointer1 = pointer2;
	}
}
