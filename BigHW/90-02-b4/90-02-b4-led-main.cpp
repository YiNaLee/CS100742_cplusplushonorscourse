/*2052316 信07 李祎娜*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
#include"90-02-b4-led.h"
using namespace std;

#include "../include/cmd_hdc_tools.h"
#include "../include/cmd_console_tools.h"
#include"../include/menu_combine.h"
#include "../include/cmd_gmw_tools.h"
int  main()
{
	//设置字体为点阵字体
	cct_setfontsize("点阵",16 );
	cct_setconsoleborder(123, 38, 123, 38);//窗口大小
	while (1) {
		cct_setcolor();
		char menu[][1024] = { 
							 {"1.模拟LED信息显示-简体中文-用*表示每个点\0"},
							 {" -- 显示时，窗口字体为新宋6，完成后按回车返回\0"},
			                 {"\n"},
							 {"2.模拟LED信息显示-繁体中文-hdc_porint画每个点\0"},
							 {"-- 画点时，每个点直径为6，完成后按回车返回\0"},
							 {"-- 每个点之间有2ms延时\0"},
							 {"\n"},
			                 {"3.交互输入：屏幕大小、颜色、字符模式下字体的大小简体/繁体字库等内容"},
							 {"\n"},
			                 {"0.退出\0"},
							 { "\0" } };
		int x;
		char select;

		select = public_menu(menu, 1);
		x = select - '0';
		if (x == 0)//0 退出程序
			break;
		/*else if (x == 1) {//请输入一个汉字或全角符号(输入y表示结束):
			//从汉字库中读取某个汉字的点阵信息
			cct_cls();
			cin_one_Chinese_character();
		}*/
		else if (x == 1) {
			cct_cls();
			simplified_Chinese_low_version();
		}
		else if (x == 2) {
			cct_cls();
			//test_to_draw();
			traditional_Chinese_low_version();
		}
		else if (x == 3) {
			cct_cls();
			interactive_input();
		}
		cct_cls();/*清理屏幕*/
		cct_setcolor();
	}
	return 0;
}
