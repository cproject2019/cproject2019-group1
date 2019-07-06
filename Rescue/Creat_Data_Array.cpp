/*********************************************************************************
*函数:
Creat_Data_Array(int * speedArray, int * accuracyArray, int gameTimeAmount)
*描述：
从data.txt中读取最后十次游戏的数据创建两个数组储存速度、正确率信息
*被本函数调用：
无
*本函数被调用：
Score_Interface(void)
*作者：
郑文俊
**********************************************************************************/

#pragma once
#include<stdio.h>

void Creat_Data_Array(int* speedArray, int* accuracyArray, int gameTimeAmount)
{
	FILE* fp;
	fopen_s(&fp, "Text_File\\data.txt", "r");
	if (10 < gameTimeAmount)//最多只读取最后十次数据
	{
		for (int i = 0; i < gameTimeAmount - 10;)
		{
			if ('\n' == fgetc(fp))	i++;
		}
	}
	for (int i = 0; i<10 && i<gameTimeAmount; i++)
	{
		int temp = 0, tempLength, tempGameTime, numberOfSuccessWords;
		fscanf_s(fp, "%d", &temp);
		fscanf_s(fp, "%d%d%d ", &tempLength, &tempGameTime, &numberOfSuccessWords);
		*(speedArray+i) = (int)(60 * tempLength / tempGameTime);//建立打字速度数组，单位：个/min
		*(accuracyArray+i) = (int)(100 * numberOfSuccessWords / tempLength);//建立正确率数组，单位：%
		char tempchar = fgetc(fp);
		while ('\n' != tempchar && EOF != tempchar)
		{
			tempchar = fgetc(fp);
		}
	}
	fclose(fp);
}