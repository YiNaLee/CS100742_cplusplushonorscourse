/* 信07 2052316 李祎娜 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b1-hanoi.h"
#include"../include/menu_combine.h"

using namespace std;

/* -----------------------------------------

	 本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

	 本文件要求：
	1、不允许定义全局变量（含外部全局和静态全集，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1)
	{
		int x, n;
		char src, dst, tmp;
		char menu[][1024] = { {"1.基本解\0"} ,
							 {"2.基本解(步数记录)\0"},
							 {"3.内部数组显示(横向)\0"},
							 {"4.内部数组显示(纵向+横向)\0"},
							 {"5.图形解-预备-画三个圆柱\0"},
							 {"6.图形解-预备-在起始柱上画n个盘子\0"},
							 {"7.图形解-预备-第一次移动\0"},
							 {"8.图形解-自动移动版本\0"},
							 {"9.图形解-游戏版\0"},
							 {"0.退出游戏\0"},
							 { "\0" } };
		char sel;
		sel = public_menu(menu, 1);
		x = sel - '0';
		if (x == 0)
			break;
		else if (x != 5)//1/2/3/4/8/9选项要展示过程
		{
			select(x, &n, &src, &dst, &tmp);//完成需要的参数输入
			getin_stack(n, src);/*初始元素入栈：*/
			/*4/5/6/7/8/9都要清屏*/
			if (x > 3 && x < 10)
				cct_cls();
			if (x == 4)
			{
				cct_setcursor(CURSOR_INVISIBLE);//关闭光标
				primilary_condition(x, n, src, dst);//显示初始状态
			}
			else if (x == 8)
			{
				cct_setcursor(CURSOR_INVISIBLE);//关闭光标
				cct_gotoxy(0, 0);
				//cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed;
				primilary_condition(x, n, src, dst);//显示初始状态
				print_nplate(n, src, 8);//包含了打印三个底盘柱子和打印初始圆盘的操作
			/*!这一步要小心*/	//sleepspeed(speed);
				//进入递归之前先打印底盘	
			}
			else if (x == 9) {
				cct_setcursor(CURSOR_INVISIBLE);//关闭光标
				game_mode(n, src, dst);
				cct_gotoxy(0, GAME_note + 4);
			}
			/*接下来需要调用hanoi函数 把参数传给hanio，除了5不需要传递参数、6不需要使用递归*/
			if (x != 6 && x != 9)//6/9不用递归函数
				hanoi(n, src, tmp, dst, x);
			else if (x == 6)//x等于6时 不用进行递归
			{
				cct_gotoxy(0, 0);
				cct_setcursor(CURSOR_INVISIBLE);//关闭光标
				cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
				print_nplate(n, src, 0);
				cct_gotoxy(0, 38);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);
			}
			if (x == 4)
			{
				final_deal(dst);//显示最终状态
			}
			else if (x == 7)
			{
				cct_gotoxy(0, 0);
				cct_setcursor(CURSOR_INVISIBLE);//关闭光标
				cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
				move_step(n, src, dst);
				cct_gotoxy(0, 38);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);
			}
			else if (x == 8) {
				cct_gotoxy(0, 38);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//恢复光标
			}
			clear_data();//清除静态局部变量
			cct_setcursor(CURSOR_VISIBLE_NORMAL);//恢复光标
			cout << "\n按回车键继续";
			while (_getch() != '\r')
				;
			cct_cls();
		}
		else //情况是if (x == 5)//画圆柱
		{
			cct_setcursor(CURSOR_INVISIBLE);//关闭光标
			cct_cls();
			chassis_print();
			cct_gotoxy(0, 38);
			cout << "按回车键继续";
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			while (_getch() != '\r')
				;
			cct_cls();
		}
	}
	return 0;
}