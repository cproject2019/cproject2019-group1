/*********************************************************************************
*����: 
Game
*������
��Ϸ�����幦��ʵ��
*�����������ã�
Create_Game_Wordlist(int wordMaxSize, int length) 
Delete_Wordlist(WORDLIST *p)
Delete_Wordlist(WRONG_WORDLIST *p)
Game_Body(int, int, int, int, int, PLAY_WORDLIST *, WRONG_WORDLIST **, WRONG_WORDLIST *)
Load_Game(int)
Outcome(int, int)
Read_In_Setting(int *pInterval, int *pLength, int *pSoundEffect, int *pSong, int *pWordMaxSize)
Start_Game()
Write_In_Data(WRONG_WORDLIST *, int length, int gameTime, int numberOfSuccessWords)
*�����������ã�
Main_Interface(void)
*���ߣ�
������
**********************************************************************************/

#pragma once
#include <time.h>
#include<process.h>
#include <graphics.h>
#include"Define_Struct.h"

void Game(void)
{
	int gameTime;//��Ϸʱ��
	int numberOfSuccessWords;//��ȷ������
	int song;//����
	int interval;//����ʱ����
	int length;//��Ϸ���ʱ���
	int soundEffect;//�Ƿ�����Ч
	int wordMaxSize;//��ĵ��ʳ���
	time_t startingTime;//��ʼʱ��
	time_t endingTime;//����ʱ��
	PLAY_WORDLIST* pTemp;//��Ϸ����ͷ���
	WRONG_WORDLIST* wrongWordlistHead;//ָ����󵥴������ͷָ��
	WRONG_WORDLIST* pTempWrongWordlist;//ָ����󵥴������н���ָ��

	void Read_In_Setting(int* pInterval, int* pLength, int* pSoundEffect, int* pSong, int* pWordMaxSize);//�������ò���
	void Create_Setting_File(FILE*, int*, int*, int*, int*, int*);//���������ļ�����
	void Load_Game(int);//��Ϸ�����ʼ������
	void Start_Game();//��ʼ��Ϸ����
	int Game_Body(int, int, int, int, int, PLAY_WORDLIST*, WRONG_WORDLIST**, WRONG_WORDLIST*);//��Ϸ���庯��
	void Write_In_Data(WRONG_WORDLIST *, int length, int gameTime, int numberOfSuccessWords);//��data.txtд����Ϸ����
	void Outcome(int, int);//��Ϸ�������
	void Delete_Wordlist(WORDLIST* p); //ɾ����Ϸ�д�����WORDLIST����
	void Delete_Wrong_Wordlist(WRONG_WORDLIST* p); //ɾ����Ϸ�д�����WRONG_WORDLIST����
	PLAY_WORDLIST* Create_Game_Wordlist(int wordMaxSize, int length);//������Ϸ��������

	srand(time(NULL) + _getpid()*_getpid());//����rand()����������ӣ���֤ÿ����Ϸ������в�һ��

	/*�������ò���*/
	Read_In_Setting(&interval, &length, &soundEffect, &song, &wordMaxSize);

	/*��Ϸ���������ʼ��*/
	pTemp = (PLAY_WORDLIST*)malloc(sizeof(PLAY_WORDLIST));
	pTemp = Create_Game_Wordlist(wordMaxSize, length);//������Ϸ��������
	wrongWordlistHead = (WRONG_WORDLIST*)malloc(sizeof(WRONG_WORDLIST));//ָ����󵥴������ͷָ��
	wrongWordlistHead = NULL;
	pTempWrongWordlist = (WRONG_WORDLIST*)malloc(sizeof(WRONG_WORDLIST));//ָ����󵥴������н���ָ��
	pTempWrongWordlist = NULL;

	/*��ʼ��Ϸ*/
	Load_Game(song);//��Ϸ��������
	Start_Game();//��Ϸ��ʼ�����ж�
	startingTime = time(NULL);//��ȡ��Ϸ��ʼʱ��
	numberOfSuccessWords = Game_Body(song, interval, length, soundEffect, wordMaxSize, pTemp, &wrongWordlistHead, pTempWrongWordlist);//��Ϸ����

	/*��Ϸ����*/
	endingTime = time(NULL);//��ȡ��Ϸ����ʱ��
	gameTime = endingTime - startingTime;//��Ϸ��ʱ��
	mciSendString("stop bgmusic", NULL, 0, NULL);//ֹͣ���ű�������
	mciSendString("close bgmusic", NULL, 0, NULL);//��ͣ��������
	Write_In_Data(wrongWordlistHead, length, gameTime, numberOfSuccessWords);//���ú�������¼��Ϸ���

	/*չʾ��Ϸ���*/
	Outcome(numberOfSuccessWords, length);

	/*ɾ����Ϸ�д���������*/
	Delete_Wordlist(pTemp);
	Delete_Wrong_Wordlist(wrongWordlistHead);
	Delete_Wrong_Wordlist(pTempWrongWordlist);
}