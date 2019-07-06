/*********************************************************************************
*����:
Score_Interface(void)
*������
����������չʾ��Ϸ��ʷ����
*�����������ã�
Accuracy(int *accuracyArray)
Count_Data_File_Row()
Creat_Data_Array(int *speedArray, int *accuracyArray, int gameTimeAmount)
Speed(int *speedArray, int *accuracyArray)
*�����������ã�
Main_Interface(void)
*���ߣ�
����Դ
**********************************************************************************/

#pragma once

void Score_Interface(void)
{
	int dataFileRowAmount;							//data.txt������
	int speedArray[10] = { 0 }, accuracyArray[10] = { 0 };
	
	int Count_Data_File_Row(void);					//����data.txt������
	void Creat_Data_Array(int* speedArray, int* accuracyArray, int gameTimeAmount);//��data.txt�ж�ȡ��ʷ���ݲ��������ʮ�ε���ȷ�ʺʹ����ٶȺ���
	void Speed(int* speedArray, int* accuracyArray);//չʾ�����ٶȺ���
	void Accuracy(int* accuracyArray);				//չʾ׼ȷ�ʺ���


	dataFileRowAmount = Count_Data_File_Row();		//data.txt������


	int gameTimeAmount = dataFileRowAmount - 1;

	Creat_Data_Array(speedArray, accuracyArray, gameTimeAmount);//��ȡ��ʷ����

	Speed(speedArray, accuracyArray);	//չʾ�����ٶ�

	Accuracy(accuracyArray);			// չʾ׼ȷ��
}