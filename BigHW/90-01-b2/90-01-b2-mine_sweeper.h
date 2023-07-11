/*2052316 信07 李祎娜*/
#pragma once
/* -----------------------------------------

	 本文件功能：
	1、为了保证 mine_sweeper_main.cpp/mine_sweeper_base.cpp/mine_sweeper_graph.cpp
				mine_sweeper_menu.cpp/mine_sweeper_tools.cpp能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ----------------------------------------- */
#include <time.h>
#include "../include/cmd_console_tools.h"
   /*定义三个存储地雷的数组大小的常量*/
const int SCALE1 = 11;
const int SCALE2 = 18;
const int SCALE3 = 32;
/*雷的总数的三个常量*/
const int MINE1_NUM = 10;
const int MINE2_NUM = 40;
const int MINE3_NUM = 99;
/*扫雷规模*/
const int MAX_X1 = 9;
const int MAX_Y1 = 9;
const int MAX_X2 = 16;
const int MAX_Y2 = 16;
const int MAX_X3 = 16;
const int MAX_Y3 = 30;

const int BODER1 = 10;
const int BODER2 = 17;
const int BODER3 = 31;


const int REVEAL = 1000;
const int bg_color = COLOR_HYELLOW;//背景为亮黄色
const int fg_color = COLOR_BLACK;   //前景为黑色
const int MARK = 42;
const int SIGN = 999;
const int UNSIGN = 888;
const int ZERO = 0;
const int HUNDRED = 100;
/*按回车键暂停函数*/
void pause_enter();
/*与菜单选择有关的函数*/
int  menu_choice();
int  difficulty_choice();
/*与难度选择有关的函数*/
void inner_show_arrary(int menu_choice, int difficulty_choice);
/*文字提示*/
void prompt_word(int x);


/*与打印扫雷数组有关的函数*/
/*第一个菜单选项用到的函数*/
void cnt_array1(int mine1[][SCALE1], int i, int j);
void cnt_array2(int mine2[][SCALE2], int i, int j);
void cnt_array3(int mine3[][SCALE3], int i, int j);
void create_array(int difficulty_choice, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[SCALE2][SCALE3]);
void print_array1(int difficulty_choice, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
/*与菜单项2有关的函数*/
void first_open_array(int nandu, int x);
int prompt_command(int nandu, int* num1, int* num2, int x, int* mark);
void makeup_mine(int num1, int num2, int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
void print_hidden(int nandu, int canshu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int* mark);
void reveal(int* number);
void digui_first(int nandu, int num1, int num2, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
void eight_direction(int nandu, int num1, int num2, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
/*与菜单项3有关的函数*/
void print_perstep(int nandu, int x);

/*与菜单项4有关的函数*/
void remark(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int num1, int num2, int* mark);
/*判断游戏是否成功*/
int judge_game(int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int nandu);

/*伪图形化界面下处理的函数*/
/*菜单项5/6/7/8/9用到的函数*/
void print_graph(int x, int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
void printline_choice(int choice, int geshu, int x);
void graph_showarray(int menu_choice, int difficulty_choice);//核心函数
/*菜单项6/7/8/9用到的函数*/
int judeg_XY(int x, int y, int nandu, int* line, int* column);
int test_mouse(int nandu, int x, int* line, int* column, int* right_click);
/*菜单项7/8/9用到的函数*/
void graph_firstopen(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);

/*菜单项8/9共用到的函数，循环直到游戏结束*/
void graph_gamemode(int nandu, int x, int mine1[][SCALE1],
	int mine2[][SCALE2], int mine3[][SCALE3], int* line, int* column, float begin_time);
void prompt_word(int x);
/*鼠标右键标记或取消标记 8/9用到*/
void mark_sign(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int num1, int num2, int* counter);
/*菜单项9用到的函数：打印时间和雷数*/
void primary_mine(int* counter, int x);
void cur_time_number(int mine_counter, int choice, float begin_time);

