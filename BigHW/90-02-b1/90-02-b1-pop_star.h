/*2052316 信07 李祎娜*/
#pragma once
/*本文件为消灭星星程序内部的私有头文件*/
const int STAR = 10;
const int STAR_MAX = 12;
const int BASE_LINE= 32;//伪图形界面下的cmd窗口的最小行
const int BASE_COLUMN = 55;//最小列
const int BASE2_LINE = 39;
const int BASE2_COLUMN = 69;
const int MIN_SCALE= 8;
const int MAX_SCALE = 10;
const int DTROW = 3;
const int DTCOL = 6;
const int DT2ROW = 4;
const int DT2COL = 8;
/*获取输入的函数*/
void get_line_column(int* line, int* column);
void cin_position(int* li, int* co, int line, int column);
void cin_end_to_continue();
char to_confirm_eliminate(int* li, int* co);
void pause_enter(const char*prompt);
/*建立数组的函数*/
void star_array_setup(int line, int column, int star_array[STAR_MAX][STAR_MAX]);
/*将数组进行移动的函数*/
void dowm_array(int line, int column, int star_array[STAR_MAX][STAR_MAX],int donghua);
/*实现所有打印数组的复用的函数*/
int print_primilary(int line, int column, int star_array[STAR_MAX][STAR_MAX],const char*prompt);
/*计算剩余多少星星的函数*/
int cal_left_num(int line, int column, int array[][STAR_MAX]);
/*封装各个base步骤的函数*/
void step1_base(int line, int column, int* li, int* co, int array[][STAR_MAX]);
int cmd_full_eliminate(int line, int column, int* li, int* co, int array[][STAR_MAX],int canshu);
void pass_a_pass(int line, int column, int* li, int* co, int array[][STAR_MAX]);

/*伪图形界面下的函数*/
/*标尺打印函数*/
void draw_ruler(int line, int column, int width1, int width2);
/*根据数组大小而改变窗口大小*/
void change_cmd(int line, int column, const int dtrow, const int dtcol,int *hang,int *lie,const int  BASELINE, const int BASECOLUMN);
void graph_choice_noline(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column);
/*画图 函数*/
void draw_graph(int line, int column, int array[][STAR_MAX],int canshu);
void draw_a_star(int random_color, int x, int y,int fanxian);
void draw_complex_frame(int row, int column, int X, int Y, int scale);
void print_perline(int line, int column, int scale, int X, int Y, int choice, const int bcolor, const int fcolor);
void graph_choice_line(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column);
void graph_a_pop(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column);
void highlight_all_linked_stars(int line, int column, int array[][STAR_MAX]);
void print_blank(int line, int column, int array[][STAR_MAX], int choice_line, int choice_column);
int graph_down_array(int line, int column, int array[][STAR_MAX]);
void final_pop_star(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column);
int cul_lef(int line, int column, int array[][STAR_MAX]);
/*鼠标键盘函数*/
int mouse_and_keyboard(int* test_line, int* test_column, int line, int column, int array[STAR_MAX][STAR_MAX], int canshu, int startx, int starty,
	int disli, int discol,int judge_is_eliminated,int special_deal);
void click_and_enter(int*keycode1_,int canshu);

