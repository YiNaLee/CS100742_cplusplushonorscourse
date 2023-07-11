/* ��07 2052316 ��t�� */
#pragma once

/* -----------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ----------------------------------------- */
   /*ȫ��ֻ���������ߺ궨��*/
const int GAMEOVER_X = 59;
const int GAMEOVER_Y = 34;
const int GAME_note = 34;



/*��˵�ѡ���йصĺ���*/
int menu_choice();
/*���������� 1/2/3/4/6/7/8/9���ô˺���*/
void select(int x, int* n, char* src, char* dst, char* tmp);

/*�뺺ŵ���ݹ��йصĺ���*/
void hanoi(int n, char src, char tmp, char dst, int x);
void move(int number, char src, char dst, int x);

/*��Ԫ��ֵ��ջ�йصĺ���*/
void getin_stack(int n, char src);
void single_stack(char src, char dst);

/*����ʱ�ƶ��йصĺ���*/
void sleepspeed(int speed);

/*��ӡ��ʼ״̬�ĺ���*/
void firstline(char src, int n, int x);
void primilary_condition(int x, int n, char src, char dst);
void final_deal(char dst);
/*ʵ��4/8�����ƶ��ĺ��� ���а�����Ƕ��*/
void move_yuansu(int x, char src, char dst);
void perline(int number, char src, char dst);
/*��������ĺ��� 3/4/8���ô˺���*/
void landspace_print(int number, char src, char dst, int x);
/*��ӡԲ�����̺����ӵĺ���*/
void chassis_print();
void print_singleplate(int n, int x, int y);
void print_nplate(int n, char src, int canshu);
void move_step(int n, char src, char dst);
void move_plate8(int n, char src, char dst);//�ڰ˲��Ĳ��ֲ��� Ƕ����move ������
/*ʹ�����ƶ��ĺ��� 7/8/9���ô˺���*/
void choice_moveplate(int tmpx, int tmpy, char ch, int bg_color, int fg_color, int LENGTH, int canshu, int MAX_X, int MAX_Y, int MIN_X);
/*�ֹ������ƶ���ŵ��*/
void game_mode(int n, char src, char dst);
int  per_command(char qishi, char mubiao);
/*ÿ�ν�������վ�̬ȫ�ֱ���*/
void clear_data();

