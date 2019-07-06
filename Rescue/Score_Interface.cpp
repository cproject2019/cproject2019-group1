/*********************************************************************************
*函数:
Score_Interface(void)
*描述：
分两个界面展示游戏历史数据
*被本函数调用：
Accuracy(int *accuracyArray)
Count_Data_File_Row()
Creat_Data_Array(int *speedArray, int *accuracyArray, int gameTimeAmount)
Speed(int *speedArray, int *accuracyArray)
*本函数被调用：
Main_Interface(void)
*作者：
黎晏源
**********************************************************************************/

#pragma once

void Score_Interface(void)
{
	int dataFileRowAmount;							//data.txt的行数
	int speedArray[10] = { 0 }, accuracyArray[10] = { 0 };
	
	int Count_Data_File_Row(void);					//数出data.txt的行数
	void Creat_Data_Array(int* speedArray, int* accuracyArray, int gameTimeAmount);//从data.txt中读取历史数据并计算出近十次的正确率和打字速度函数
	void Speed(int* speedArray, int* accuracyArray);//展示打字速度函数
	void Accuracy(int* accuracyArray);				//展示准确率函数


	dataFileRowAmount = Count_Data_File_Row();		//data.txt的行数


	int gameTimeAmount = dataFileRowAmount - 1;

	Creat_Data_Array(speedArray, accuracyArray, gameTimeAmount);//读取历史数据

	Speed(speedArray, accuracyArray);	//展示打字速度

	Accuracy(accuracyArray);			// 展示准确率
}