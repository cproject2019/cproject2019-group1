/*********************************************************************************
*函数:
Write_Data_To_File(WRONG_WORDLIST * pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount)
*描述：
向data.txt写入本次游戏数据
*被本函数调用：
无
*本函数被调用：
Write_Data_To_File(WRONG_WORDLIST * pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount) 
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdio.h>
#include"Define_Struct.h"

void Write_Data_To_File(WRONG_WORDLIST * pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount)
{
	WRONG_WORDLIST * pointer;
	FILE * fp;

	fopen_s(&fp, "Text_File\\data.txt", "a");						//打开data.txt,向其中只写数据
	if (NULL == fp)	printf("There is no data.txt");		//形式上保留对文件不存在的反馈

	/*向data.txt写入相应参数*/
	fprintf(fp, "%d\t%d\t%d\t%d\t%d", fileRowAmount, length, gameTime, numberOfSuccessWords, targetStringAmount);
	for (pointer = pNewWronglistHead; NULL != pointer; pointer = pointer->next)
	{
		fprintf(fp, "\t%s", pointer->word);
	}
	fprintf(fp, "\n");
	fclose(fp);
}