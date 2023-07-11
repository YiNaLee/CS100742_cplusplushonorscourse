/*2052316 信07 李祎娜*/
//本cpp功能：利用hdc画图函数完成led显示特效；
/*对应菜单项2.3两项*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
#include "../include/cmd_console_tools.h"
#include "../include/cmd_hdc_tools.h"
#include"../include/menu_combine.h"
#include "../include/cmd_gmw_tools.h"
#include "../include/basic_public.h"

using namespace std;
/************************************************************************************
函数名称：simplified_Chinese_low_version()
函数参数：
函数功能：实现demo的菜单项2.模拟LED信息显示-简体中文-用*表示每个点
  -- 显示时，窗口字体为新宋6，完成后按回车返回
对应菜单项2功能
************************************************************************************/
void simplified_Chinese_low_version()
{
	FILE* fphzk16;
	cct_setfontsize("新宋体", 6);
	cct_setconsoleborder(320, 98, 320,98);//设置窗口
	
	unsigned char storage[] = "在《白·问》白岩松专访林郑月娥节目中，白岩松谈及香港有意让公务员到内地单位“挂职”。对此，特首林郑月娥表示，特区政府一直都\0";//测试用文本
	unsigned char buffer[32] = {0};//存放点阵信息
	int k,j,i,cnt;
	unsigned char key[8] = {
	   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};//方便查找，
	
	int flag;//记录要画的点
	for ( cnt = 0; cnt<120; cnt+=2) {
		int offset = (94 * (unsigned int)(storage[cnt] - 0xa0 - 1) \
			+ (storage[cnt+1] - 0xa0 - 1)) * 32;
		fphzk16 = fopen("HZK16", "rb");
		if (fphzk16 == NULL) {
			cout << "无法打开字库文件HZK16\n";
			public_pause_enter("请按任意键继续. . .");
			return;
		}
		if (fphzk16 == 0) {
			return;
		}
		else {
			fseek(fphzk16, offset, SEEK_SET);
			fread(buffer, 1, 32, fphzk16);//读取一共32个点阵信息
			fclose(fphzk16);
		}
		//下面要开始画图
		cct_setcolor(0,10);//绿色
		cct_gotoxy((cnt % 20) * 16, (cnt / 20) * 16);
		for (k = 0; k < 16; k++) {
			for (j = 0; j < 2; j++) {
				for (i = 0; i < 8; i++) {
					flag = buffer[k * 2 + j] & key[i];
					
					printf("%s ", flag ? "*" : " ");
				}
			}
			cct_gotoxy((cnt % 20) * 16, (cnt / 20) * 16 + k + 1);
		}
		//还要将buffer清空
		for (int a = 0; a < 32; a++) {
			buffer[a] = 0;
		}
	}
	public_pause_enter();
	cct_setfontsize("新宋体",16);
	cct_setconsoleborder(120, 30);
	public_cin_end_to_continue();
	cct_cls();
	cct_setcolor();
	return;
}
/************************************************************************************
函数名称：traditional_Chinese_low_version()
函数参数：
函数功能：实现demo的菜单3.3.模拟LED信息显示-繁体中文-hdc_porint画每个点
  -- 画点时，每个点直径为6，完成后按回车返回
  -- 每个点之间有2ms延时
************************************************************************************/
void traditional_Chinese_low_version()
{
	//要用到hdc的函数集，其中画点的延时为2ms
	FILE* fphzk16f;
	cct_setfontsize("新宋体", 16);
	cct_setconsoleborder(123,38,123,38);//设置窗口
	unsigned char storage[] = "在《白·问》白岩松专访林郑月娥节目中，白岩松谈及香港有意让公务员到内地单位“挂职”。对此，特首林郑月娥表示，特区政府一直都\0";//测试用文本
	unsigned char buffer[32] = { 0 };//存放点阵信息
	int k, j, i, cnt;
	unsigned char key[8] = {
	   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};//方便查找，

	int flag;//记录要画的点
	hdc_cls();//先清屏，否则无法画
	//每个点之间有两秒的延时
	for (cnt = 0; cnt < 120; cnt += 2) {
		int offset = (94 * (unsigned int)(storage[cnt] - 0xa0 - 1) \
			+ (storage[cnt + 1] - 0xa0 - 1)) * 32;
		fphzk16f = fopen("HZK16F", "rb");
		if (fphzk16f == NULL) {
			cout << "无法打开字库文件HZK16F\n";
			public_pause_enter("请按任意键继续. . .");
			return;
		}
		if (fphzk16f == 0) {
			return;
		}
		else {
			fseek(fphzk16f, offset, SEEK_SET);
			fread(buffer, 1, 32, fphzk16f);//读取一共32个点阵信息
			fclose(fphzk16f);
		}
		//下面要开始画图
		//此处的画图要调用hdc工具集
		
		//cct_gotoxy((cnt % 20) * 16, (cnt / 20) * 16);
		for (k = 0; k < 16; k++) {
			for (j = 0; j < 2; j++) {
				for (i = 0; i < 8; i++) {
					flag = buffer[k * 2 + j] & key[i];
					if (flag) {
						if (j==0) {
							//hdc_circle(100, 100, 10, true, RGB(255, 255, 0));
							hdc_point(((cnt%20/2) * 16 + i)*6, ((cnt / 20) * 16 + k + 1) *6, 6, RGB(255, 255, 0));//画点，要确定该点的坐标
						}
						else {//j==1
							hdc_point(((cnt%20/2) * 16 + 8+i)*6, ((cnt / 20) * 16 + k + 1) *6,6, RGB(255, 255, 0));//画点，要确定该点的坐标
						}
						//cout << " ";
					}
					else {
						//printf("%s ", flag ? "*" : " ");
						;
					}
					
				}
			}
			//cct_gotoxy((cnt % 20) * 16, (cnt / 20) * 16 + k + 1);
		}
		//还要将buffer清空
		for (int a = 0; a < 32; a++) {
			buffer[a] = 0;
		}
	}
	public_pause_enter();
	cct_cls();
	cct_setfontsize("新宋体", 16);
	cct_setconsoleborder(100, 100);//设置窗口
	public_cin_end_to_continue();
	cct_setcolor();
	return;
}
