/*********************************************************************************
*函数:
Create_All_Wrodlist(int wordMaxSize)
*描述：
实现从词库创建总单词链表
*被本函数调用：
Main_Interface()
*本函数被调用：
Create_Game_Wordlist(int wordMaxSize, int length)
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdio.h>
#include<string.h>
#include <windows.h>
#include"Define_Struct.h"

ALL_WORDLIST *Create_All_Wrodlist(int wordMaxSize) {
	/*打开文件*/
	FILE* fp;
	fopen_s(&fp, "Text_File\\wordlist.txt", "r");					//打开wordlist.txt
	if (NULL == fp)										//wordlist.txt缺失则提示并返回主界面
	{
		MessageBox(NULL, TEXT("\"wordlist.txt\"is missing."), TEXT("Warning"), MB_SYSTEMMODAL);
		void Main_Interface(void);
		Main_Interface();
	}

	/*创建链表*/
	ALL_WORDLIST *head, *node, *end;					//定义头节点，普通节点，末节点；
	head = (ALL_WORDLIST*)malloc(sizeof(ALL_WORDLIST));	//分配地址
	end = head;											//若是空链表则头尾节点一样
	int i = 1;
	char * find;
	char tempWord[30];

	while ((fgets(tempWord, 30, fp)) != NULL)
	{
		find = strchr(tempWord, '\n');
		if (find)	*find = '\0';
		if (wordMaxSize >= strlen(tempWord))	//只保留长度不长于wordMaxSize的单词
		{
			node = (ALL_WORDLIST*)malloc(sizeof(ALL_WORDLIST));
			node->num = i;
			strncpy_s(node->word, tempWord, 17);
			end->next = node;
			end = node;
			i++;
		}
	}
	end->next = NULL;	//结束创建
	fclose(fp);

	return head->next;
}
