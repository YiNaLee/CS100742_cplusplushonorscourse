/*2052316 信07 李祎娜*/
#pragma once
/* -----------------------------------------
	 本文件功能：
	1、无分割线版本消灭星星的私有头文件
   ----------------------------------------- */
#define STARMAX    12
#define STAR       10




//获得行列大小，根据行列大小随机生成数组
void get_line_column(int* line, int* column);
void star_array_setup(int line, int column, int star_array[STARMAX][STARMAX]);
//游戏画框架和色块，调用gmw工具的函数
int gmw_popstar_full_version(int line, int column, int star_array[][STARMAX]);
//数组下落函数
void gmw_downstar(int line, int column, int star_array[][STARMAX], CONSOLE_GRAPHICS_INFO* pCGI);
//奖励计算函数
int cal_left_num(int line, int column, int array[][STARMAX]);
void pause_enter(const char* prompt);
