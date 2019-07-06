/*********************************************************************************
*函数:
Count_Data_File_Row(void)
*描述：
数出data.txt的行数
*被本函数调用：
无
*本函数被调用：
Create_Game_Wordlist(int wordMaxSize, int length)
Score_Interface(void)
Write_In_Data(WRONG_WORDLIST * wrongWordlistHead, int length, int gameTime, int numberOfSuccessWords)
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdio.h>
#include"Define_Struct.h"

int Count_Data_File_Row(void)
{
	FILE *fp = NULL;
	int fileRow = 1;										//文件行数初始化
	
	fopen_s(&fp, "Text_File\\data.txt", "a+");							//打开data.txt，若不存在，建立之
	if (NULL == fp)		printf("There is no data.txt");		//形式上保留对文件不存在的反馈
	while (!feof(fp))
	{
		if ('\n' == fgetc(fp))	fileRow++;					//读到'\n'则行数+1
	}
	fclose(fp);
	return fileRow;
}
