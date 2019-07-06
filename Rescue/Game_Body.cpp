/*********************************************************************************
*函数:
Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST * pTemp, WRONG_WORDLIST ** wrongWordlistHead, WRONG_WORDLIST * pTempWrongWordlist)
*描述：
游戏主体
*被本函数调用：
Main_Interface()
Sound_Effect(int)
*本函数被调用：
Game(void) 
*作者：
晁雨欣
**********************************************************************************/

#pragma once
#include <conio.h>
#include <graphics.h>
#include <easyx.h>//如果不用TCHAR标识符，则easyx中的outtextxy只能输出单个字符
#include"Define_Struct.h"

int Game_Body(int song, int interval, int length, int soundEffect, int wordMaxSize, PLAY_WORDLIST* pTemp, WRONG_WORDLIST** wrongWordlistHead, WRONG_WORDLIST* pTempWrongWordlist)
{
	void Main_Interface();
	void Sound_Effect(int);

	TCHAR word[17];//待打的单词
	TCHAR inputChar;//输入的字符
	TCHAR inputString[17];//输入的字符串
	IMAGE imgApple;//苹果图片
	int numberOfSuccessWords = 0;//正确单词数

	for (int numberOfWord = 1; numberOfWord <= length; numberOfWord++)
	{
		int position;//打到单词的第几个字母
		position = 0;//从第一个字母打起
		int wrongTimes = 0;//该单词的错误次数
		strcpy_s(word, pTemp->word);//从链表中获得待打的单词
		for (int i = 0; i <= 16; i++)//输入字符串初始化
		{
			inputString[i] = '\0';
		}

		loadimage(&imgApple, "Resource_File\\apple.jpg", 100, 100);//把苹果图片放在工程项目下
		int y = 40;//苹果纵坐标初始值
		int x;//苹果横坐标
		x = rand() % 861 + 20;//产生20~880的随机数,并赋值给x,实现苹果横坐标的随机生成

		for (int time = 1; time <= 300; time++)//实现苹果下落过程
		{
			BeginBatchDraw();//批量绘图，避免闪烁
			y = y + 1;
			putimage(x, y, &imgApple);//苹果每次下降一个像素点
			SetWorkingImage(&imgApple);
			setbkcolor(getpixel(50, 50));
			settextcolor(BLACK);
			outtextxy(20, 50, word);
			SetWorkingImage();//在苹果上输出待打的单词
			EndBatchDraw();//批量绘图，避免闪烁

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
					inputString[position] = inputChar;//把正确输入的字符拼接到正确输入的字符串后面
					position++;
				}

				else
				{
					Sound_Effect(soundEffect);//触发音效函数
					wrongTimes++;//该单词错误次数加一
					if (*wrongWordlistHead == NULL)//如果该单词是第一个错误单词
					{
						WRONG_WORDLIST *node;
						node = (WRONG_WORDLIST*)malloc(sizeof(WRONG_WORDLIST));
						strcpy_s(node->word, word);
						node->wrongLocation = position;
						node->next = NULL;
						*wrongWordlistHead = node;
						pTempWrongWordlist = node;
					}
					else//该单词不是第一个错误单词
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

			if (0 == strcmp(inputString, word))//检测单词是否正确输入 
			{
				if (wrongTimes == 0) numberOfSuccessWords++;
				setfillcolor(getpixel(5, 5));//获取背景颜色
				solidrectangle(350, 450, 600, 480);//单词输入正确，清空输入框
				solidrectangle(x - 5, y - 5, x + 105, y + 105);//用矩形色块把苹果的图片挡住
				pTemp = pTemp->next;
				break;
			}

			Sleep(interval);//每interval毫秒下降一个像素点
			setfillcolor(getpixel(5, 5));
			solidrectangle(x - 5, y - 5, x + 105, y + 105);//用矩形色块把苹果的图片挡住

			if (time == 300)//当苹果已掉落到地面
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
				solidrectangle(350, 450, 600, 480);//单词未在掉落前输入，清空输入框
			}
		}
	}
	return numberOfSuccessWords;
}