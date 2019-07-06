/*********************************************************************************
*函数:
Create_Game_Wordlist(int wordMaxSize, int length) 
*描述：
建立游戏单词列表
*被本函数调用：
Count_Data_File_Row()
Count_Wordlist_Length(WORDLIST *pAllWordlistHead)
Create_All_Wrodlist(int wordMaxSize)
Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST *, ALL_WORDLIST *)
Read_In_Target_List(int dataFileRowAmount)
Search_Wordlist(TARGET_WORDLIST *, ALL_WORDLIST *)
*本函数被调用：
Game(void) 
*作者：
郑文俊
**********************************************************************************/


#pragma once
#include"Define_Struct.h"

PLAY_WORDLIST* Create_Game_Wordlist(int wordMaxSize, int length)
{
	int allWordlistLength;									//wordlist.txt的行数
	int dataFileRowAmount;									//data.txt的行数
	ALL_WORDLIST* pAllWordlistHead;							//单词总链表头
	TARGET_WORDLIST* pTargetHead;							//目标字符串链表头
	RESULT_WORDLIST* pResultHead;							//匹配查找结果单词链表头
	PLAY_WORDLIST* pPlayWordlistHead;						//游戏单词链表头

	int Count_Wordlist_Length(WORDLIST* pAllWordlistHead);	//计算链表节点数函数
	int Count_Data_File_Row(void);							//计算data.txt行数函数
	ALL_WORDLIST* Create_All_Wrodlist(int wordMaxSize);		//建立单词总链表ALL_WORDLIST函数
	TARGET_WORDLIST* Read_In_Target_List(int dataFileRowAmount);//从data.txt读入目标字符串TARGET_WORDLIST函数
	RESULT_WORDLIST* Search_Wordlist(TARGET_WORDLIST*, ALL_WORDLIST*);//从单词总链表中匹配查找含有目标字符的单词函数
	PLAY_WORDLIST* Create_Play_Wordlist(int allWordlistLength, int length, RESULT_WORDLIST*, ALL_WORDLIST*);//建立游戏单词链表函数


	pAllWordlistHead = Create_All_Wrodlist(wordMaxSize);			//建立单词总链表ALL_WORDLIST

	allWordlistLength = Count_Wordlist_Length(pAllWordlistHead);	//计算ALL_WORDLIST节点数

	dataFileRowAmount = Count_Data_File_Row();						//计算data.txt的行数

	pTargetHead = Read_In_Target_List(dataFileRowAmount);			//读入目标字符串TARGET_WORDLIST,若没有字符串或没有data文件，返回NULL

	pResultHead = Search_Wordlist(pTargetHead, pAllWordlistHead);	//用Sunday算法匹配含有目标字符串TRGET_WORDLIST的单词，若没有，返回NULL

	pPlayWordlistHead = Create_Play_Wordlist(allWordlistLength, length, pResultHead, pAllWordlistHead);	//建立游戏单词列表PLAY_WORDLIST

	return pPlayWordlistHead;
}
