#pragma once

/*单词总链表,检索结果单词链表，游戏单词链表*/
typedef struct wordlist
{
	int num;				//编号
	char word[17];			//单词
	struct wordlist *next;	//指向下一节点的指针
}WORDLIST, ALL_WORDLIST, RESULT_WORDLIST, PLAY_WORDLIST;

/*错误单词链表*/
typedef struct wronglist
{
	char word[17];			//出错单词
	int wrongLocation;		//出错位点
	int wrongTime = 0;		//出错次数
	struct wronglist *next;	//指向下一节点的指针
}WRONG_WORDLIST;

/*目标字符串链表*/
typedef struct targetlist
{
	char target[4];			//目标字符串
	struct targetlist* next;//指向下一节点的指针
}TARGET_WORDLIST;