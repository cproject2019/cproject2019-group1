/*********************************************************************************
*函数:
Play_Songs(int song)
*描述：
播放背景音乐
*被本函数调用：
无
*本函数被调用：
Load_Game(int song)
*作者：
晁雨欣
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