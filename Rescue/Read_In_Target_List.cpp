/*********************************************************************************
*����:
Read_In_Target_List(int dataFileRowAmount)
*������
���ļ��ж�ȡ��ʷ�����ַ�������Ŷ
*�����������ã�
��
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


TARGET_WORDLIST* Read_In_Target_List(int dataFileRowAmount)
{
	FILE* fp;
	fopen_s(&fp, "Text_File\\data.txt", "r");	//��data.txt������ļ�ȱʧ�����½��հ��ļ�

	TARGET_WORDLIST *head, *node, *end;	//����ͷ�ڵ㣬��ͨ�ڵ㣬β���ڵ㣻
	head = (TARGET_WORDLIST*)malloc(sizeof(TARGET_WORDLIST));	//�����ַ
	end = head;		//���ǿ�������ͷβ�ڵ�һ��

	/*�ƶ�ָ��*/
	if (dataFileRowAmount <= 1)						//����Ϸ����Ϊ0���򷵻�NULL
	{
		head->next = NULL;
	}
	else if (dataFileRowAmount >= 4)				//����Ϸ������3�μ����ϣ�ָ���ƶ���������2����Ϸ���ݿ�ͷ
	{
		for (int i = 0; i < dataFileRowAmount - 3;)
		{
			if ('\n' == fgetc(fp))	i++;
		}
	}

	/*��ȡ�������(��һ��)��Ϸ��Ŀ���ַ���*/
	for (int i = 1; i < dataFileRowAmount && i < 3; i++)
	{
		int currentMistakeNumber = 0, temp = 0;
		fscanf_s(fp, "%d%d%d%d%d\t", &temp, &temp, &temp, &temp, &currentMistakeNumber);
		for (int i = 0; i < currentMistakeNumber; i++) {
			node = (TARGET_WORDLIST*)malloc(sizeof(TARGET_WORDLIST));
			fgets(node->target, 4, fp);
			(node->target)[3] = '\0';
			fseek(fp, 1, SEEK_CUR);
			end->next = node;
			end = node;
		}
		end->next = NULL;//��������
	}
	fclose(fp);

	return head->next;
}
