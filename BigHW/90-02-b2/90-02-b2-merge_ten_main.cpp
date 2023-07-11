/*2052316 信07 李祎娜*/
/* -----------------------------------------
	 本文件功能：
	1、放main函数  执行合成十完整版的功能
	2、初始化屏幕
	3、调用公共菜单函数（public_menu）并返回选项
	4、根据选项调用菜单各项对应的执行函数（.cpp中）
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
#include"../include/basic_public.h"
#include "90-02-b2-merge_ten.h"
using namespace std;
int main()
{

	while (1) {
		char select;
		int line=0, column=0,target=0;// 是该数组的行列大小和合成目标
		int li = 0, co = 0;//是键盘输入的要消除的行列
		char temp[256] = " ";
		cct_setfontsize("新宋体", 16);
		cct_cls();
		int merge_array[MERGE_MAX_SCALE][MERGE_MAX_SCALE] = { 0 };//定义了一个12*12的适当放大的数组，
		//和消灭星星的数组大小相同;
		char menu[][1024] = { {"1.命令行找出可合成项并标识（非递归）"},
							  {"2.命令行找出可合成项并标识（递归）" },
							  {"3.命令行完成一次合成（分步骤显示）"},
			                  {"4.命令行完整版（分步骤显示）" },
							  {"5.伪图形界面显示初始数组（无分隔线）"},
			                  {"6.伪图形界面显示初始数组（有分隔线）"},
			                  {"7.伪图形界面下用箭头键选择当前色块"},
			                  {"8.伪图形界面完成一次合成（分步骤）"},
			                  {"9.伪图形界面完整版(支持鼠标)"},
			                  {"0.退出"},
							  { "\0" } };
		int x;
		select = public_menu(menu, 1);
		x = select - '0';
		if (x == 0)//0 退出程序
			break;
	    //得到的x是0-6的值，其中x==6代表伪图形界面完整版
		if (select != '9') {
			putchar(select);
			continue;
		}
		//x==9时，完整版
		cct_cls();
		get_line_column(&line, &column, &target);
		//然后要开始根据输入的行列、画图
		merge_array_setup(line,column,merge_array);
		//之后开始绘图
		full_version_gmw_merge_ten(line, column, merge_array,target);
		//然后要打印本小题结束，输入end继续的语句！
		public_cin_end_to_continue();
	}
}
