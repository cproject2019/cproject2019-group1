/*********************************************************************************
*����:
Play_Songs(int song)
*������
���ű�������
*�����������ã�
��
*�����������ã�
Load_Game(int song)
*���ߣ�
������
**********************************************************************************/

#pragma once
#include <graphics.h>

void Play_Songs(int song)
{
	switch (song)
	{
	case 1: mciSendString("open Resource_File\\bgm1.mp3 alias bgmusic", NULL, 0, NULL); mciSendString("play bgmusic repeat", 0, 0, 0); break;
	case 2: mciSendString("open Resource_File\\bgm2.mp3 alias bgmusic", NULL, 0, NULL); mciSendString("play bgmusic repeat", 0, 0, 0); break;
	case 3: mciSendString("open Resource_File\\bgm3.mp3 alias bgmusic", NULL, 0, NULL); mciSendString("play bgmusic repeat", 0, 0, 0); break;
	}
}