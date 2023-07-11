/* 信07 2052316 李祎娜 */
#pragma once

/* -----------------------------------------

	 本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ----------------------------------------- */
   /*全局只读变量或者宏定义*/
const int GAMEOVER_X = 59;
const int GAMEOVER_Y = 34;
const int GAME_note = 34;



/*与菜单选择有关的函数*/
int menu_choice();
/*输入多个参数 1/2/3/4/6/7/8/9共用此函数*/
void select(int x, int* n, char* src, char* dst, char* tmp);

/*与汉诺塔递归有关的函数*/
void hanoi(int n, char src, char tmp, char dst, int x);
void move(int number, char src, char dst, int x);

/*与元素值入栈有关的函数*/
void getin_stack(int n, char src);
void single_stack(char src, char dst);

/*与延时移动有关的函数*/
void sleepspeed(int speed);

/*打印初始状态的函数*/
void firstline(char src, int n, int x);
void primilary_condition(int x, int n, char src, char dst);
void final_deal(char dst);
/*实现4/8纵向移动的函数 其中包含了嵌套*/
void move_yuansu(int x, char src, char dst);
void perline(int number, char src, char dst);
/*横向输出的函数 3/4/8共用此函数*/
void landspace_print(int number, char src, char dst, int x);
/*打印圆柱底盘和盘子的函数*/
void chassis_print();
void print_singleplate(int n, int x, int y);
void print_nplate(int n, char src, int canshu);
void move_step(int n, char src, char dst);
void move_plate8(int n, char src, char dst);//第八步的部分操作 嵌套在move 函数中
/*使盘子移动的函数 7/8/9共用此函数*/
void choice_moveplate(int tmpx, int tmpy, char ch, int bg_color, int fg_color, int LENGTH, int canshu, int MAX_X, int MAX_Y, int MIN_X);
/*手工操作移动汉诺塔*/
void game_mode(int n, char src, char dst);
int  per_command(char qishi, char mubiao);
/*每次结束后清空静态全局变量*/
void clear_data();

