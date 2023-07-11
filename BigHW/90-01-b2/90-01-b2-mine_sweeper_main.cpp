/* 信07 2052316 李祎娜 */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b2-mine_sweeper.h"
#include "../include/menu_combine.h"
using namespace std;
/* -----------------------------------------
	 本文件功能：
	1、放main函数  执行扫雷的功能
	2、初始化屏幕
	3、调用公共菜单函数（public_menu）并返回选项
	4、根据选项调用菜单各项对应的执行函数（.cpp中）
   ----------------------------------------- */
int main()
{
	/* 执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		cct_setfontsize("新宋体", 24);
		char menu[][1024] = { {"1.选择难度并显示内部数组\0"} ,
							 {"2.输入初始位置并显示被打开的初始区域\0"},
							 {"3.内部数组基础版\0"},
							 {"4.内部数组完整版（标记、运行时间）\0"},
							 {"5.画出伪图形化框架并显示内部数据\0"},
							 {"6.检测鼠标位置和合法性（左键单击退出）\0"},
							 {"7.鼠标选择初始位置并显示被打开的初始区域\0"},
							 {"8.伪图形界面基础版\0"},
							 {"9.伪图形界面完整版\0"},
							 {"0.退出游戏\0"},
			                 { "\0" }};
		int x;
		char select;
		
		select = public_menu(menu, 1);
		x = select - '0';
		if (x == 0)//0 退出程序
			break;
		else if (x == 1) {//第一个菜单项 显示内部数组
			int nandu = difficulty_choice();
			inner_show_arrary(x, nandu);
		}
		else if (x == 2) {//显示被打开的初始区域
			int nandu = difficulty_choice();
			first_open_array(nandu, x);
		}
		else if (x == 3) {//内部数组基础版
			int nandu = difficulty_choice();
			print_perstep(nandu, x);
		}
		else if (x == 4) {//内部数组完整版
			int nandu = difficulty_choice();
			print_perstep(nandu, x);
		}
		else if (x == 5) {
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		else if (x == 6) {/*在5的基础上检测光标的合法性*/
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		else if (x == 7) {//在6的基础上先将数组全部遮蔽，然后初始第一步点开
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		else if (x == 8) {//在7的基础上完成游戏版本，按esc可以退出
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		else if (x == 9) {
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		cct_cls();/*清理屏幕*/
	}
	return 0;
}
