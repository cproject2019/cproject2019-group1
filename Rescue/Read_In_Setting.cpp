/*********************************************************************************
*函数:
Read_In_Setting(int * pInterval, int * pLength, int * pSoundEffect, int * pSong, int * pWordMaxSize)
*描述：
从setting中读取设置参数
*被本函数调用：
无
*本函数被调用：
Game(void)
Setting_Interface(void)
*作者：
晁雨欣
**********************************************************************************/

#pragma once
#include<stdio.h>
#include<Windows.h>

void Read_In_Setting(int* pInterval, int* pLength, int* pSoundEffect, int* pSong, int* pWordMaxSize)
{
	FILE* fp;
	fopen_s(&fp, "Text_File\\setting.txt", "rb");		//打开setting文件

	if (NULL != fp)							//若打开成功则从setting.txt中读取设置参数
	{
		fscanf_s(fp, "%d\t%d\t%d\t%d\t%d ", pSong, pInterval, pLength, pSoundEffect, pWordMaxSize);
	}
	else									//若setting.txt打开失败，则新建之，并使用默认设置
	{
		fopen_s(&fp, "Text_File\\setting.txt", "a");
		MessageBox(NULL, TEXT("Failed to read \"Setting.txt\". System defaults will be used"), TEXT("Warning"), MB_SYSTEMMODAL);
		*pSong = 1;
		*pInterval = 10;
		*pLength = 5;
		*pSoundEffect = 1;
		*pWordMaxSize = 10;
		fprintf(fp, "%d\t%d\t%d\t%d\t%d", *pSong, *pInterval, *pLength, *pSoundEffect, *pWordMaxSize);
	}
	fclose(fp);
}