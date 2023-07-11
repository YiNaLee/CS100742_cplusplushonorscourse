/*2052316 信07 李祎娜*/
/*注：由于时间限制，本程序仅真正实现了扫雷图形化完整版*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include"../include/menu_combine.h"
#include "../include/cmd_gmw_tools.h"
#include "90-01-b2-gmw.h"
/* -----------------------------------------
	 本文件功能：
	1、放main函数  执行扫雷的功能
	2、初始化屏幕
	3、调用公共菜单函数（public_menu）并返回选项
	4、根据选项调用菜单各项对应的执行函数（.cpp中）
	5.注：由于时间限制，本程序仅真正实现了扫雷图形化完整版
   ----------------------------------------- */
using namespace std;
int main()
{
	//cct_setconsoleborder(100, 40);
	cct_setfontsize("新宋体", 24);
	while (1) {
		cct_setfontsize("新宋体", 24);
		char menu[][1024] = { {"扫雷用gmw函数集实现的完整版：" },
							 {"9.伪图形界面完整版\0"},
							 {"0.退出游戏\0"},
							 { "\0" } };
		int x;
		char select;

		select = public_menu(menu, 1);
		x = select - '0';
		if (x == 0)//0 退出程序
			break;
		if (x == 9) {
			int nandu = difficulty_choice();
			graph_gmw_mine_sweeper(nandu);
		}
		cct_cls();/*清理屏幕*/
	}
	return 0;
}