/*********************************************************************************
*函数:
Welcome(void) 
*描述：
实现过场动画的绘制
*被本函数调用：
无
*本函数被调用：
main(void)
*作者：
黎晏源
**********************************************************************************/

#pragma once
#include<graphics.h>
#include<easyx.h>

void Welcome(void)//初始过场动画生成函数
{
	initgraph(800, 480);
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(100, 0, TEXT("楷体"));
	for (int i = 255; i >= 0; i = i - 5)
	{
		settextcolor(RGB(i, i, i));//文字颜色根据参数i的值变化，颜色逐渐加深
		outtextxy(100, 160, TEXT("Rescue Apples"));
		Sleep(30);//设置变化间隔时间
	}//实现文字颜色随时间变深，最终浮现
	Sleep(20);
	for (int i = 0; i <= 255; i = i + 5)
	{
		settextcolor(RGB(i, i, i));//文字颜色根据参数i的值变化，颜色逐渐变浅
		outtextxy(100, 160, TEXT("Rescue Apples"));
		Sleep(20);//设置变化间隔时间
	}//实现文字颜色随时间逐渐变浅，最终消失
}