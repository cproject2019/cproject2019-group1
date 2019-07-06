/*********************************************************************************
*函数: 
Game
*描述：
游戏的主体功能实现
*被本函数调用：
Create_Game_Wordlist(int wordMaxSize, int length) 
Delete_Wordlist(WORDLIST *p)
Delete_Wordlist(WRONG_WORDLIST *p)
Game_Body(int, int, int, int, int, PLAY_WORDLIST *, WRONG_WORDLIST **, WRONG_WORDLIST *)
Load_Game(int)
Outcome(int, int)
Read_In_Setting(int *pInterval, int *pLength, int *pSoundEffect, int *pSong, int *pWordMaxSize)
Start_Game()
Write_In_Data(WRONG_WORDLIST *, int length, int gameTime, int numberOfSuccessWords)
*本函数被调用：
Main_Interface(void)
*作者：
晁雨欣
**********************************************************************************/

#pragma once
#include <time.h>
#include<process.h>
#include <graphics.h>
#include"Define_Struct.h"

void Game(void)
{
	int gameTime;//游戏时间
	int numberOfSuccessWords;//正确单词数
	int song;//歌曲
	int interval;//下落时间间隔
	int length;//游戏单词表长度
	int soundEffect;//是否开启音效
	int wordMaxSize;//最长的单词长度
	time_t startingTime;//开始时间
	time_t endingTime;//结束时间
	PLAY_WORDLIST* pTemp;//游戏链表头结点
	WRONG_WORDLIST* wrongWordlistHead;//指向错误单词链表的头指针
	WRONG_WORDLIST* pTempWrongWordlist;//指向错误单词链表中结点的指针

	void Read_In_Setting(int* pInterval, int* pLength, int* pSoundEffect, int* pSong, int* pWordMaxSize);//读入设置参数
	void Create_Setting_File(FILE*, int*, int*, int*, int*, int*);//建立设置文件函数
	void Load_Game(int);//游戏界面初始化函数
	void Start_Game();//开始游戏函数
	int Game_Body(int, int, int, int, int, PLAY_WORDLIST*, WRONG_WORDLIST**, WRONG_WORDLIST*);//游戏主体函数
	void Write_In_Data(WRONG_WORDLIST *, int length, int gameTime, int numberOfSuccessWords);//向data.txt写入游戏数据
	void Outcome(int, int);//游戏结果函数
	void Delete_Wordlist(WORDLIST* p); //删除游戏中创建的WORDLIST链表
	void Delete_Wrong_Wordlist(WRONG_WORDLIST* p); //删除游戏中创建的WRONG_WORDLIST链表
	PLAY_WORDLIST* Create_Game_Wordlist(int wordMaxSize, int length);//建立游戏单词链表

	srand(time(NULL) + _getpid()*_getpid());//生成rand()随机序列种子，保证每次游戏随机序列不一样

	/*读入设置参数*/
	Read_In_Setting(&interval, &length, &soundEffect, &song, &wordMaxSize);

	/*游戏数据链表初始化*/
	pTemp = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));
	pTemp = Create_Game_Wordlist(wordMaxSize, length);//建立游戏单词链表
	wrongWordlistHead = (WRONG_WORDLIST*)malloc(sizeof(WRONG_WORDLIST));//指向错误单词链表的头指针
	wrongWordlistHead = NULL;
	pTempWrongWordlist = (WRONG_WORDLIST*)malloc(sizeof(WRONG_WORDLIST));//指向错误单词链表中结点的指针
	pTempWrongWordlist = NULL;

	/*开始游戏*/
	Load_Game(song);//游戏界面生成
	Start_Game();//游戏开始条件判断
	startingTime = time(NULL);//获取游戏开始时间
	numberOfSuccessWords = Game_Body(song, interval, length, soundEffect, wordMaxSize, pTemp, &wrongWordlistHead, pTempWrongWordlist);//游戏主体

	/*游戏结束*/
	endingTime = time(NULL);//获取游戏结束时间
	gameTime = endingTime - startingTime;//游戏总时间
	mciSendString("stop bgmusic", NULL, 0, NULL);//停止播放背景音乐
	mciSendString("close bgmusic", NULL, 0, NULL);//关停背景音乐
	Write_In_Data(wrongWordlistHead, length, gameTime, numberOfSuccessWords);//调用函数，记录游戏结果

	/*展示游戏结果*/
	Outcome(numberOfSuccessWords, length);

	/*删除游戏中创建的链表*/
	Delete_Wordlist(pTemp);
	Delete_Wrong_Wordlist(wrongWordlistHead);
	Delete_Wrong_Wordlist(pTempWrongWordlist);
}