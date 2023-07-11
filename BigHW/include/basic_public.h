/*2052316 信07 李祎娜*/
#pragma once
/*递归寻找，标记内部数组的函数*/
void reveal(int* number);
int digui_find(int num1, int num2, int array[][12], int line, int column);
/*判断游戏是否结束的函数*/
int judge_is_over(int line, int column, int array[12][12]);
/*状态栏打印函数*/
void status_bar_up(int sizerow, int sizecol, const int X, const int Y);
//void status_bar_down(int currow, int curcol, int positiony);
/*设置缓冲区函数*/
void save_oldbuffer_size(int* cur_cols, int* cur_lines, int* cur_buffer_cols, int* cur_buffer_lines);
/*画边框函数*/
void draw_a_star(int random_color, int x, int y, int fanxian);
void draw_frame(int length, int height, int X, int Y);
/*判断鼠标位置是否合法*/
int legal_XY(int X, int Y, int line, int column, int starty, int startx, int disline, int discol,
	int* choose_line, int* choose_col,int differ,int array[][12]);
//数组下落函数
void gmw_public_downstar(int line, int column, int star_array[][12]);
//回车键继续游戏函数
void public_pause_enter(const char* prompt= NULL);
//输入end继续函数
void public_cin_end_to_continue();