/*2052316 ��07 ��t��*/
#pragma once
/*�ݹ�Ѱ�ң�����ڲ�����ĺ���*/
void reveal(int* number);
int digui_find(int num1, int num2, int array[][12], int line, int column);
/*�ж���Ϸ�Ƿ�����ĺ���*/
int judge_is_over(int line, int column, int array[12][12]);
/*״̬����ӡ����*/
void status_bar_up(int sizerow, int sizecol, const int X, const int Y);
//void status_bar_down(int currow, int curcol, int positiony);
/*���û���������*/
void save_oldbuffer_size(int* cur_cols, int* cur_lines, int* cur_buffer_cols, int* cur_buffer_lines);
/*���߿���*/
void draw_a_star(int random_color, int x, int y, int fanxian);
void draw_frame(int length, int height, int X, int Y);
/*�ж����λ���Ƿ�Ϸ�*/
int legal_XY(int X, int Y, int line, int column, int starty, int startx, int disline, int discol,
	int* choose_line, int* choose_col,int differ,int array[][12]);
//�������亯��
void gmw_public_downstar(int line, int column, int star_array[][12]);
//�س���������Ϸ����
void public_pause_enter(const char* prompt= NULL);
//����end��������
void public_cin_end_to_continue();