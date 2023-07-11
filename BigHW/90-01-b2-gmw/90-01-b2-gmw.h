/*2052316 信07 李祎娜*/
#pragma once
/* -----------------------------------------

	 本文件功能：
	
	1、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	2、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ----------------------------------------- */
#define MINE_ARRAYLINE    18
#define MINE_ARRAYCOL     32
#define BODER1            10
#define BODER2            17
#define BODER3            31
#define REVEAL            1000
#define MINEMIN           10
#define MINEMED           40
#define MINEMAX           99
#define LINECOLMIN         9
#define LINECOLMED        16
#define COLMAX            30

//扫雷规模选择函数
int difficulty_choice();
//回车键暂停函数；
void pause_enter();
//画边框的函数；
void graph_gmw_mine_sweeper(int nandu);
//递归寻找函数
void digui_sweeper(int nandu, int num1, int num2, int minesweeper[][MINE_ARRAYCOL]);
//根据第一次输入来制造数组的函数
void makeup_mine(int num1, int num2, int nandu, int mine_array[][MINE_ARRAYCOL]);
//判断游戏是否继续的函数
int judge_game_isover(int nandu, int mine_sweeper[][MINE_ARRAYCOL], int* left_mine);
int graph_continue_mine_sweeper(CONSOLE_GRAPHICS_INFO* minesweeperCGI, int nandu, float* curtime, float begintime, int mine[][MINE_ARRAYCOL]);
