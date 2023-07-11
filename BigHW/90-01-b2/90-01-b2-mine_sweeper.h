/*2052316 ��07 ��t��*/
#pragma once
/* -----------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ mine_sweeper_main.cpp/mine_sweeper_base.cpp/mine_sweeper_graph.cpp
				mine_sweeper_menu.cpp/mine_sweeper_tools.cpp���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ----------------------------------------- */
#include <time.h>
#include "../include/cmd_console_tools.h"
   /*���������洢���׵������С�ĳ���*/
const int SCALE1 = 11;
const int SCALE2 = 18;
const int SCALE3 = 32;
/*�׵���������������*/
const int MINE1_NUM = 10;
const int MINE2_NUM = 40;
const int MINE3_NUM = 99;
/*ɨ�׹�ģ*/
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
const int bg_color = COLOR_HYELLOW;//����Ϊ����ɫ
const int fg_color = COLOR_BLACK;   //ǰ��Ϊ��ɫ
const int MARK = 42;
const int SIGN = 999;
const int UNSIGN = 888;
const int ZERO = 0;
const int HUNDRED = 100;
/*���س�����ͣ����*/
void pause_enter();
/*��˵�ѡ���йصĺ���*/
int  menu_choice();
int  difficulty_choice();
/*���Ѷ�ѡ���йصĺ���*/
void inner_show_arrary(int menu_choice, int difficulty_choice);
/*������ʾ*/
void prompt_word(int x);


/*���ӡɨ�������йصĺ���*/
/*��һ���˵�ѡ���õ��ĺ���*/
void cnt_array1(int mine1[][SCALE1], int i, int j);
void cnt_array2(int mine2[][SCALE2], int i, int j);
void cnt_array3(int mine3[][SCALE3], int i, int j);
void create_array(int difficulty_choice, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[SCALE2][SCALE3]);
void print_array1(int difficulty_choice, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
/*��˵���2�йصĺ���*/
void first_open_array(int nandu, int x);
int prompt_command(int nandu, int* num1, int* num2, int x, int* mark);
void makeup_mine(int num1, int num2, int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
void print_hidden(int nandu, int canshu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int* mark);
void reveal(int* number);
void digui_first(int nandu, int num1, int num2, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
void eight_direction(int nandu, int num1, int num2, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
/*��˵���3�йصĺ���*/
void print_perstep(int nandu, int x);

/*��˵���4�йصĺ���*/
void remark(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int num1, int num2, int* mark);
/*�ж���Ϸ�Ƿ�ɹ�*/
int judge_game(int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int nandu);

/*αͼ�λ������´���ĺ���*/
/*�˵���5/6/7/8/9�õ��ĺ���*/
void print_graph(int x, int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);
void printline_choice(int choice, int geshu, int x);
void graph_showarray(int menu_choice, int difficulty_choice);//���ĺ���
/*�˵���6/7/8/9�õ��ĺ���*/
int judeg_XY(int x, int y, int nandu, int* line, int* column);
int test_mouse(int nandu, int x, int* line, int* column, int* right_click);
/*�˵���7/8/9�õ��ĺ���*/
void graph_firstopen(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]);

/*�˵���8/9���õ��ĺ�����ѭ��ֱ����Ϸ����*/
void graph_gamemode(int nandu, int x, int mine1[][SCALE1],
	int mine2[][SCALE2], int mine3[][SCALE3], int* line, int* column, float begin_time);
void prompt_word(int x);
/*����Ҽ���ǻ�ȡ����� 8/9�õ�*/
void mark_sign(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int num1, int num2, int* counter);
/*�˵���9�õ��ĺ�������ӡʱ�������*/
void primary_mine(int* counter, int x);
void cur_time_number(int mine_counter, int choice, float begin_time);

