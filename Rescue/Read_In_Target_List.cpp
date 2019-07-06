/*********************************************************************************
*函数:
Read_In_Target_List(int dataFileRowAmount)
*描述：
从文件中读取历史错误字符串链表哦
*被本函数调用：
无
*本函数被调用：
Create_Game_Wordlist(int wordMaxSize, int length) 
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Define_Struct.h"


TARGET_WORDLIST* Read_In_Target_List(int dataFileRowAmount)
{
	FILE* fp;
	fopen_s(&fp, "Text_File\\data.txt", "r");	//打开data.txt，如果文件缺失，则新建空白文件

	TARGET_WORDLIST *head, *node, *end;	//定义头节点，普通节点，尾部节点；
	head = (TARGET_WORDLIST*)malloc(sizeof(TARGET_WORDLIST));	//分配地址
	end = head;		//若是空链表则头尾节点一样

	/*移动指针*/
	if (dataFileRowAmount <= 1)						//若游戏次数为0，则返回NULL
	{
		head->next = NULL;
	}
	else if (dataFileRowAmount >= 4)				//若游戏次数在3次及以上，指针移动到倒数第2次游戏数据开头
	{
		for (int i = 0; i < dataFileRowAmount - 3;)
		{
			if ('\n' == fgetc(fp))	i++;
		}
	}

	/*读取最后两次(或一次)游戏的目标字符串*/
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
		end->next = NULL;//结束创建
	}
	fclose(fp);

	return head->next;
}
