/*********************************************************************************
*����:
Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST * pTemp, WRONG_WORDLIST ** wrongWordlistHead, WRONG_WORDLIST * pTempWrongWordlist)
*������
��Ϸ����
*�����������ã�
Main_Interface()
Sound_Effect(int)
*�����������ã�
Game(void) 
*���ߣ�
������
**********************************************************************************/

#pragma once
#include <conio.h>
#include <graphics.h>
#include <easyx.h>//�������TCHAR��ʶ������easyx�е�outtextxyֻ����������ַ�
#include"Define_Struct.h"

int Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST* pTemp, WRONG_WORDLIST** wrongWordlistHead, WRONG_WORDLIST* pTempWrongWordlist)
{
	void Main_Interface();
	void Sound_Effect(int);

	TCHAR word[17];//����ĵ���
	TCHAR inputChar;//������ַ�
	TCHAR inputString[17];//������ַ���
	IMAGE imgApple;//ƻ��ͼƬ
	int numberOfSuccessWords = 0;//��ȷ������

	for (int numberOfWord = 1; numberOfWord <= length; numberOfWord++)
	{
		int position;//�򵽵��ʵĵڼ�����ĸ
		position = 0;//�ӵ�һ����ĸ����
		int wrongTimes = 0;//�õ��ʵĴ������
		strcpy_s(word, pTemp->word);//�������л�ô���ĵ���
		for (int i = 0; i <= 16; i++)//�����ַ�����ʼ��
		{
			inputString[i] = '\0';
		}

		loadimage(&imgApple, "Resource_File\\apple.jpg", 100, 100);//��ƻ��ͼƬ���ڹ�����Ŀ��
		int y = 40;//ƻ���������ʼֵ
		int x;//ƻ��������
		x = rand() % 861 + 20;//����20~880�������,����ֵ��x,ʵ��ƻ����������������

		for (int time = 1; time <= 300; time++)//ʵ��ƻ���������
		{
			BeginBatchDraw();//������ͼ��������˸
			y = y + 1;
			putimage(x, y, &imgApple);//ƻ��ÿ���½�һ�����ص�
			SetWorkingImage(&imgApple);
			setbkcolor(getpixel(50, 50));
			settextcolor(BLACK);
			outtextxy(20, 50, word);
			SetWorkingImage();//��ƻ�����������ĵ���
			EndBatchDraw();//������ͼ��������˸

			if (_kbhit())
			{
				inputChar = _getche();

				if (inputChar == 27)
				{
					mciSendString("stop bgmusic", NULL, 0, NULL);
					mciSendString("close bgmusic", NULL, 0, NULL);
					Main_Interface();
				}

				else if (inputChar == word[position])
				{
					settextcolor(BLACK);
					outtextxy(370 + 10 * position, 460, inputChar);
					inputString[position] = inputChar;//����ȷ������ַ�ƴ�ӵ���ȷ������ַ�������
					position++;
				}

				else
				{
					Sound_Effect(soundEffect);//������Ч����
					wrongTimes++;//�õ��ʴ��������һ
					if (*wrongWordlistHead == NULL)//����õ����ǵ�һ�����󵥴�
					{
						WRONG_WORDLIST *node;
						node = (WRONG_WORDLIST*)malloc(sizeof(WRONG_WORDLIST));
						strcpy_s(node->word, word);
						node->wrongLocation = position;
						node->next = NULL;
						*wrongWordlistHead = node;
						pTempWrongWordlist = node;
					}
					else//�õ��ʲ��ǵ�һ�����󵥴�
					{
						WRONG_WORDLIST *node;
						node = (WRONG_WORDLIST*)malloc(sizeof(WRONG_WORDLIST));
						strcpy_s(node->word, word);
						node->wrongLocation = position;
						node->next = NULL;
						pTempWrongWordlist->next = node;
						pTempWrongWordlist = node;
					}
				}
			}

			if (0 == strcmp(inputString, word))//��ⵥ���Ƿ���ȷ���� 
			{
				if (wrongTimes == 0) numberOfSuccessWords++;
				setfillcolor(getpixel(5, 5));//��ȡ������ɫ
				solidrectangle(350, 450, 600, 480);//����������ȷ����������
				solidrectangle(x - 5, y - 5, x + 105, y + 105);//�þ���ɫ���ƻ����ͼƬ��ס
				pTemp = pTemp->next;
				break;
			}

			Sleep(interval);//ÿinterval�����½�һ�����ص�
			setfillcolor(getpixel(5, 5));
			solidrectangle(x - 5, y - 5, x + 105, y + 105);//�þ���ɫ���ƻ����ͼƬ��ס

			if (time == 300)//��ƻ���ѵ��䵽����
			{
				if (numberOfWord == length)
				{
					pTemp = NULL;
				}
				else
				{
					pTemp = pTemp->next;
				}
				setfillcolor(getpixel(5, 5));
				solidrectangle(350, 450, 600, 480);//����δ�ڵ���ǰ���룬��������
			}
		}
	}
	return numberOfSuccessWords;
}