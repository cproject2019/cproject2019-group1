/*********************************************************************************
*函数:
Write_In_Data(WRONG_WORDLIST * wrongWordlistHead, int length, int gameTime, int numberOfSuccessWords)
*描述：
从错误单词链表中提取关键词字符串把并把它其他游戏数据写入data.txt
*被本函数调用：
Count_Data_File_Row()
Rewrite_Wrong_Wordlist(WRONG_WORDLIST *p, int *pTargetStringAmount)
Write_Data_To_File(WRONG_WORDLIST *pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount)
*本函数被调用：
Game(void)
*作者：
郑文俊
**********************************************************************************/
#pragma once
#include"Define_Struct.h"

void Write_In_Data(WRONG_WORDLIST * wrongWordlistHead, int length, int gameTime, int numberOfSuccessWords)
{
	int fileRowAmount;									//data.txt的行数
	int targetStringAmount;								//目标字符串链表的节点个数
	int* pTargetStringAmount = &targetStringAmount;
	WRONG_WORDLIST* pNewWronglistHead;					//改写出的目标字符串链表的头

	int Count_Data_File_Row(void);						//数出data.txt的行数函数
	WRONG_WORDLIST* Rewrite_Wrong_Wordlist(WRONG_WORDLIST* p, int* pTargetStringAmount);//改写错误单词链表函数
	void Write_Data_To_File(WRONG_WORDLIST * pNewWronglistHead, int fileRowAmount, int length, int gameTime, int numberOfSuccessWords, int targetStringAmount);	//向data.txt写入数据函数


	fileRowAmount = Count_Data_File_Row();

	pNewWronglistHead = Rewrite_Wrong_Wordlist(wrongWordlistHead, pTargetStringAmount);	

	/*写入文件格式：int游戏编号 \t int单词总数 \t int总时间(秒) \tint正确个数 \t int目标字符串个数 \t 字符串1 \t 字符串2...\n*/
	Write_Data_To_File(pNewWronglistHead, fileRowAmount, length, gameTime, numberOfSuccessWords, targetStringAmount);
}