/*********************************************************************************
*����:
Create_All_Wrodlist(int wordMaxSize)
*������
ʵ�ִӴʿⴴ���ܵ�������
*�����������ã�
Main_Interface()
*�����������ã�
Create_Game_Wordlist(int wordMaxSize, int length)
*���ߣ�
֣�Ŀ�
**********************************************************************************/

#pragma once
#include<stdio.h>
#include<string.h>
#include <windows.h>
#include"Define_Struct.h"

ALL_WORDLIST *Create_All_Wrodlist(int wordMaxSize) {
	/*���ļ�*/
	FILE* fp;
	fopen_s(&fp, "Text_File\\wordlist.txt", "r");					//��wordlist.txt
	if (NULL == fp)										//wordlist.txtȱʧ����ʾ������������
	{
		MessageBox(NULL, TEXT("\"wordlist.txt\"is missing."), TEXT("Warning"), MB_SYSTEMMODAL);
		void Main_Interface(void);
		Main_Interface();
	}

	/*��������*/
	ALL_WORDLIST *head, *node, *end;					//����ͷ�ڵ㣬��ͨ�ڵ㣬ĩ�ڵ㣻
	head = (ALL_WORDLIST*)malloc(sizeof(ALL_WORDLIST));	//�����ַ
	end = head;											//���ǿ�������ͷβ�ڵ�һ��
	int i = 1;
	char * find;
	char tempWord[30];

	while ((fgets(tempWord, 30, fp)) != NULL)
	{
		find = strchr(tempWord, '\n');
		if (find)	*find = '\0';
		if (wordMaxSize >= strlen(tempWord))	//ֻ�������Ȳ�����wordMaxSize�ĵ���
		{
			node = (ALL_WORDLIST*)malloc(sizeof(ALL_WORDLIST));
			node->num = i;
			strncpy_s(node->word, tempWord, 17);
			end->next = node;
			end = node;
			i++;
		}
	}
	end->next = NULL;	//��������
	fclose(fp);

	return head->next;
}
