/*********************************************************************************
*����:
Read_In_Setting(int * pInterval, int * pLength, int * pSoundEffect, int * pSong, int * pWordMaxSize)
*������
��setting�ж�ȡ���ò���
*�����������ã�
��
*�����������ã�
Game(void)
Setting_Interface(void)
*���ߣ�
������
**********************************************************************************/

#pragma once
#include<stdio.h>
#include<Windows.h>

void Read_In_Setting(int* pInterval, int* pLength, int* pSoundEffect, int* pSong, int* pWordMaxSize)
{
	FILE* fp;
	fopen_s(&fp, "Text_File\\setting.txt", "rb");		//��setting�ļ�

	if (NULL != fp)							//���򿪳ɹ����setting.txt�ж�ȡ���ò���
	{
		fscanf_s(fp, "%d\t%d\t%d\t%d\t%d ", pSong, pInterval, pLength, pSoundEffect, pWordMaxSize);
	}
	else									//��setting.txt��ʧ�ܣ����½�֮����ʹ��Ĭ������
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