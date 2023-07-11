/*2052316 信07 李祎娜*/
/* -----------------------------------------
	 本文件功能：
	1、放main函数  执行消灭星星完整版的功能
	2、初始化屏幕
	3、调用公共菜单函数（public_menu）并返回选项
	4、根据选项调用菜单各项对应的执行函数（.cpp中）
	5.注：由于时间限制，本程序仅真正实现了消灭星星完整版
   ----------------------------------------- */
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
#include "90-02-b1-gmw.h"
using namespace std;
int main()
{
	
	while (1) {
		char select;
		int line, column;// 是该数组的行列大小【8-10】
		int li = 0, co = 0;//是键盘输入的要消除的行列
		char temp[256] = " ";
		cct_setfontsize("新宋体", 16);
		cct_cls();
		int star_array[STARMAX][STARMAX] = { 0 };
		char menu[][1024] = { {"消灭星星用gmw函数集完成的完整版"},
							 {"G.伪图形界面完整版\0"},
							 {"Q.退出\0"},
							 { "\0" } };
		int x;
		select = public_menu(menu, 2);
		if (select >= 'a' && select <= 'z') {
			select -= 32;//转为大写
		}
		x = select - 'A';
		
	
		//得到的x是0-6的值，其中x==6代表伪图形界面完整版
		if (select !='G') {
			putchar(select);
			continue;
		}
		cct_cls();
		
		get_line_column(&line, &column);//从键盘读数组行列大小
		while (1) {
			for (int i = 0; i < line; i++) {
				for (int j = 0; j < column; j++) {
					star_array[i][j] = 0;
				}
			}
			star_array_setup(line, column, star_array);

			gmw_popstar_full_version(line, column, star_array);
			pause_enter(NULL);

		}
		
	}
}