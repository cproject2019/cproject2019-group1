/*********************************************************************************
*����:
Delete_Wordlist(WORDLIST * p) 
*������
ɾ��WRONG_WORDLIST����
*�����������ã�
��
*�����������ã�
Game(void)
*���ߣ�
֣�Ŀ�
**********************************************************************************/

#pragma once
#include<stdlib.h>
#include"Define_Struct.h"

void Delete_Wordlist(WORDLIST* p)
{
	WORDLIST* pointer1, *pointer2;
	pointer1 = pointer2 = p;		//ָ���ʼ��Ϊ����ͷ

	while ( NULL != pointer1)
	{
		pointer2 = pointer2->next;
		free(pointer1);
		pointer1 = pointer2;
	}
}