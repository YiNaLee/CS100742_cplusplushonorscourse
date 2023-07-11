/* ��07 2052316 ��t�� */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b2-mine_sweeper.h"
using namespace std;
/*���ļ����ܣ�αͼ�ν�����غ�����ʵ��*/
/*��Ӧ�˵���5-9*/




/******************************************************************************************************
�������ƣ�printline_chioce
˵����
0.choiceѡ��Ҫ������
1.��ʾ�����ߺͻ�ɫ����
2.��ʾ��ӡ�ӵڶ������߿�ʼ���м䲿��
3.��ӡ��һ�еĺ���
4.��ӡ���һ�еĺ���
5.geshuѡ��Ҫ�ظ���ӡ�Ĵ���*/
/*��αͼ�ν���   �˺���ֻ���𻭿�ܺ�����ɫ���ɫ����ʼ�ĵ�һ����δ�򿪵���ʾ������������������*/
/*���벻ͬ�Ĳ������Ի���ͬ����*/
void printline_choice(int choice, int geshu, int x)
{
	int i, j;
	//�Ѷ�1 2 3
	//��Ӧ9*9 16*16 16*30
	switch (choice)
	{
		case(1)://�����������ߺͻҰײ���

			for (j = 0; j < 2; j++) {
				for (i = 0; i < geshu - 1; i++) {//��ӡ��geshu-1��
					cct_setcolor(COLOR_WHITE, COLOR_BLACK);
					cout << "�U";
					if (x == 5 || x == 6)
						cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);//��Ϊ����ɫ ��ӡ�ո�
					else {//�����ʼβ��Ĭ��Ϊ��ɫ
						cct_setcolor(COLOR_YELLOW, COLOR_YELLOW);
					}
					cout << setw(4) << " ";
				}
				cct_setcolor(COLOR_WHITE, COLOR_BLACK);
				cout << "�U";//���һ���߿�λ���޻�ɫ���
				cct_setcolor();//ȱʡ��ӡһ���ո�
				cout << endl;
				cout << " ";
			}
			cct_setcolor();//�ָ�ȱʡ
			break;
		case(2)://��ӡ�ӵڶ������߿�ʼ���м䲿��
			cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			cout << "�d";
			for (i = 0; i < geshu; i++) {
				cout << "�T�T�p";
			}
			cout << "�T�T�g";
			cout << endl;
			cct_setcolor();//�ָ�ȱʡ
			break;
		case(3)://��ӡ��һ���еĺ���
			cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			cout << "�X";
			for (i = 0; i < geshu; i++) {
				cout << "�T�T�j";

			}
			cout << "�T�T�[";
			cout << endl;
			cct_setcolor();//�ָ�ȱʡ
			break;
		case(4):///��ӡ���һ�еĺ���
			cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			cout << "�^";
			for (i = 0; i < geshu; i++) {
				cout << "�T�T�m";
			}
			cout << "�T�T�a\n";
			cct_setcolor();//�ָ�ȱʡ
			break;
	}
	return;
}

/************************************************
�������ƣ�graph_firstopen()
�������ܣ���6�Ļ����ϵ�һ��������ɨ������
����Ӧ��ע��Ӧ��ȷ�����µĵ��������
����ֵ����
����˵����7/8/9���ô˺���
��ַ���� line��columnͨ����ַ������
*************************************************************/
void graph_firstopen(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	int i, j;
	switch (nandu)
	{
		case(1):
			for (i = 1; i < BODER1; i++) {
				for (j = 1; j < BODER1; j++) {
					if (mine1[i][j] >= REVEAL) {
						mine1[i][j] -= REVEAL;
						cct_gotoxy(5 + 6 * (j - 1) - 2, 4 + 3 * (i - 1));
						cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine1[i][j]);//��ӡ����
						if (mine1[i][j] == 0)
							cout << setw(4) << " ";
						else if (mine1[i][j] == 42) {
							cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
							cout << setw(4) << "*";
						}
						else
							cout << setw(4) << mine1[i][j];
						cct_gotoxy(5 + 6 * (j - 1) - 2, 4 + 3 * (i - 1) - 1);
						cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
						cout << setw(4) << " ";
						cct_setcolor();
						mine1[i][j] += REVEAL;
					}
				}
			}
			break;
		case(2):
			for (i = 1; i < BODER2; i++) {
				for (j = 1; j < BODER2; j++) {
					if (mine2[i][j] >= REVEAL) {
						mine2[i][j] -= REVEAL;
						cct_gotoxy(5 + 6 * (j - 1) - 2, 4 + 3 * (i - 1));
						cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine2[i][j]);//��ӡ����
						if (mine2[i][j] == 0)
							cout << setw(4) << " ";
						else if (mine2[i][j] == 42) {
							cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
							cout << setw(4) << "*";
						}
						else
							cout << setw(4) << mine2[i][j];
						cct_gotoxy(5 + 6 * (j - 1) - 2, 4 + 3 * (i - 1) - 1);
						cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
						cout << setw(4) << " ";
						cct_setcolor();
						mine2[i][j] += REVEAL;
					}
				}
			}
			break;
		case(3):
			for (i = 1; i < BODER2; i++) {
				for (j = 1; j < BODER3; j++) {
					if (mine3[i][j] >= REVEAL) {
						mine3[i][j] -= REVEAL;
						cct_gotoxy(5 + 6 * (j - 1) - 2, 4 + 3 * (i - 1));
						cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine3[i][j]);//��ӡ����
						if (mine3[i][j] == 0)
							cout << setw(4) << " ";
						else if (mine3[i][j] == 42) {
							cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
							cout << setw(4) << "*";
						}
						else
							cout << setw(4) << mine3[i][j];
						cct_gotoxy(5 + 6 * (j - 1) - 2, 4 + 3 * (i - 1) - 1);
						cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
						cout << setw(4) << " ";
						cct_setcolor();
						mine3[i][j] += REVEAL;
					}
				}
			}
			break;


	}
}
/******************************************************
�������ƣ�print_graph
���������int x,int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]
�������ܣ���ӡ��ʼ�Ŀ�ܣ�5/6�����������룬7/8/9��ֻ��ӡ��ɫ���ڸǵ�����
��������˵������
*******************************************************/
void print_graph(int x, int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	int i, j;
	int first_X = 1, first_Y = 2;
	switch (nandu)
	{

		case(1)://9*9
			/*�ȴ�ӡ���ֺ���ĸ*/
			cct_setconsoleborder(59, 35);//9*9����������Ϊ59,35
			cct_gotoxy(5, 1);
			for (i = 0; i < 9; i++) {
				cout << i << setw(5) << " ";
			}
			/*Ȼ���ٴ�ӡ��ɫ�Ŀ� ����Ϊ��ɫ ǰ��Ϊ��ɫ*/
			cct_gotoxy(first_X, first_Y);
			/*�ȴ�ӡ��һ��*/
			printline_choice(3, 8, x);
			/*Ȼ���ӡ���ߺ��м���*/
			for (i = 0; i < 8; i++) {
				putchar('A' + i);
				printline_choice(1, 10, x);
				printline_choice(2, 8, x);
			}
			/*Ȼ���ӡ���һ��*/
			putchar('A' + i);
			printline_choice(1, 10, x);
			printline_choice(4, 8, x);
			/*��ӡ9*9�ı����ɣ�������Ҫ�����������ֺ���*/
			if (x == 5 || x == 6) {
				for (i = 1; i < 10; i++) {//i�����У�j������
					for (j = 1; j < 10; j++) {
						if (mine1[i][j] > 0 && mine1[i][j] < 10) {
							/*����Ҫ��ʾ*/
							cct_gotoxy(5 + 6 * (j - 1), 4 + 3 * (i - 1));
							cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine1[i][j]);
							cout << mine1[i][j];
							cct_setcolor();
						}
						else if (mine1[i][j] == '*') {
							cct_gotoxy(5 + 6 * (j - 1), 4 + 3 * (i - 1));
							cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
							cout << '*';
							cct_setcolor();
						}
					}
				}
			}
			cct_gotoxy(0, 32);
			break;
		case(2):
			cct_setconsoleborder(101, 56);
			cct_gotoxy(5, 1);
			for (i = 0; i < 16; i++) {
				cout << setiosflags(ios::left) << setw(6) << i;
			}
			cct_gotoxy(first_X, first_Y);
			/*�ȴ�ӡ��һ��*/
			printline_choice(3, 15, x);
			/*Ȼ���ӡ���ߺ��м���*/
			for (i = 0; i < 15; i++) {
				putchar('A' + i);
				printline_choice(1, 17, x);
				printline_choice(2, 15, x);
			}
			/*Ȼ���ӡ���һ��*/
			putchar('A' + i);
			printline_choice(1, 17, x);
			printline_choice(4, 15, x);
			/*��ӡ16*16�ı����ɣ�������Ҫ�����������ֺ���*/
			if (x == 5 || x == 6) {
				for (i = 1; i < 17; i++) {//i�����У�j������
					for (j = 1; j < 17; j++) {
						if (mine2[i][j] > 0 && mine2[i][j] < 10) {
							/*����Ҫ��ʾ*/
							cct_gotoxy(5 + 6 * (j - 1), 4 + 3 * (i - 1));
							cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine2[i][j]);
							cout << mine2[i][j];
							cct_setcolor();
						}
						else if (mine2[i][j] == '*') {
							cct_gotoxy(5 + 6 * (j - 1), 4 + 3 * (i - 1));
							cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
							cout << '*';
							cct_setcolor();
						}
					}
				}
			}
			cct_gotoxy(0, 50);
			break;
		case(3):
			cct_setconsoleborder(185, 56);
			cct_gotoxy(5, 1);
			for (i = 0; i < 30; i++) {
				cout << setiosflags(ios::left) << setw(6) << i;
			}
			cct_gotoxy(first_X, first_Y);
			/*�ȴ�ӡ��һ��*/
			printline_choice(3, 29, x);
			/*Ȼ���ӡ���ߺ��м���*/
			for (i = 0; i < 15; i++) {
				putchar('A' + i);
				printline_choice(1, 31, x);
				printline_choice(2, 29, x);
			}
			/*Ȼ���ӡ���һ��*/
			putchar('A' + i);
			printline_choice(1, 31, x);
			printline_choice(4, 29, x);
			/*��ӡ16*30�ı����ɣ�������Ҫ�����������ֺ���*/
			if (x == 5 || x == 6) {
				for (i = 1; i < 17; i++) {//i�����У�j������
					for (j = 1; j < 31; j++) {
						if (mine3[i][j] > 0 && mine3[i][j] < 10) {
							/*����Ҫ��ʾ*/
							cct_gotoxy(5 + 6 * (j - 1), 4 + 3 * (i - 1));
							cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine3[i][j]);
							cout << mine3[i][j];
							cct_setcolor();
						}
						else if (mine3[i][j] == '*') {
							cct_gotoxy(5 + 6 * (j - 1), 4 + 3 * (i - 1));
							cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
							cout << '*';
							cct_setcolor();
						}
					}
				}
			}
			cct_gotoxy(0, 50);
			break;
	}

	return;
}
/*�������ƣ�test_mouse()
�������
�������ܣ���5�Ľ����ϼ������λ�ã������������
��������ֵ������0˵�����������������޼��̲���������1˵������esc�� ����2˵�����¿ո��
//�ڲ˵���9�У�
����˵���� */
int test_mouse(int nandu, int x, int* line, int* column, int* right_click)
{

	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int legal = 0;
	*right_click = 0;//���
	cct_enable_mouse();
	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		/*X.Y���Ի�ȡ��ǰ��������*/
		if (ret == CCT_MOUSE_EVENT) {//����¼�����Ҫ�ж�λ���Ƿ�Ϸ���ת��ĳ�д�ӡ
			switch (maction) {
				case MOUSE_ONLY_MOVED://�ƶ���Ҫ�ж�λ��
					if (nandu == 1)
						cct_gotoxy(0, 30);
					else
						cct_gotoxy(0, 51);
					cout << "����ǰ��꡿";
					legal = judeg_XY(X, Y, nandu, line, column);//�ɹ�����1
					break;
				case MOUSE_LEFT_BUTTON_CLICK://���������ʾ�˳�
					if (legal == 1 || x == 6) {
						loop = 0;

					}

					break;
				case MOUSE_RIGHT_BUTTON_CLICK://�����Ҽ���ʾ���Ϊ�׻���ȡ�����Ϊ��
					if (legal == 1 && (x == 8 || x == 9)) {
						*right_click = 1;//�����Ҽ�
						loop = 0;
					}
					break;

				case MOUSE_NO_ACTION:
				default:
					break;
			}
		}
		//�˵���8��Ҫ�������ϵ�esc��
		else if (ret == CCT_KEYBOARD_EVENT && (x == 8 || x == 9)) {
			switch (keycode1) {
				case 27:	//ESC�� 
					loop = 0;
					return 1;
				case 32:    //�ո��
					if (x == 9) {
						loop = 0;
						return 2;
					}
					break;
			}
		}

	}
	return 0;
}


/********************************************
int judeg_XY
�������ܣ��ж�λ���Ƿ�Ϸ�
��λ�÷Ƿ� ����ֵΪ0
��λ�úϷ�������ֵΪ1
*********************************************/

int judeg_XY(int x, int y, int nandu, int* line, int* column)//�ѻ�õĹ��λ�ô���ȥ����
{
	switch (nandu)
	{
		case(1):
			if ((y >= 3 && y <= 28) && (y % 3 == 0 || y % 3 == 1)) {
				if (x >= 3 && x <= 54 && (x % 6 != 1 && x % 6 != 2)) {
					putchar(y / 3 + 'A' - 1);
					cout << " ��";
					putchar((x - 3) / 6 + '0');
					cout << " ��";
				}
				else {
					cout << "λ�÷Ƿ�";
					return 0;
				}
			}
			else {
				cout << "λ�÷Ƿ�";
				return 0;
			}
			break;
		case(2):
			if ((y >= 3 && y <= 49) && (y % 3 == 0 || y % 3 == 1)) {
				if (x >= 3 && x <= 96 && (x % 6 != 1 && x % 6 != 2)) {
					putchar(y / 3 + 'A' - 1);
					cout << " ��";
					cout << (x - 3) / 6;
					cout << " ��";
				}
				else {
					cout << "λ�÷Ƿ�";
					return 0;
				}
			}
			else {
				cout << "λ�÷Ƿ�";
				return 0;
			}
			break;
		case(3):
			if ((y >= 3 && y <= 49) && (y % 3 == 0 || y % 3 == 1)) {
				if (x >= 3 && x <= 180 && (x % 6 != 1 && x % 6 != 2)) {
					putchar(y / 3 + 'A' - 1);
					cout << " ��";
					cout << (x - 3) / 6;
					cout << " ��";
				}
				else {
					cout << "λ�÷Ƿ�";
					return 0;
				}
			}
			else {
				cout << "λ�÷Ƿ�";
				return 0;
			}
			break;

	}
	*line = y / 3;
	*column = (x - 3) / 6 + 1;
	return 1;//�ɹ����� λ�úϷ�Ϊ1
}

void prompt_word(int x)
{
	if (x == 8) {
		cct_setcolor();
		cct_gotoxy(0, 0);
		cout << "��ESC�˳�";
	}
	else if (x == 9) {
		cct_setcolor();
		cct_gotoxy(0, 0);
		cout << "��ESC�˳�,�ո���ʾʱ��";
	}
}

/***************************************************
�������ƣ�mark_sign()
�������
�������ܣ���ǻ�ȡ�����Ϊ��
��������ֵ
˵����
 *********************************************** */
void mark_sign(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int num1, int num2, int* counter)
{

	switch (nandu)
	{
		case(1):
			if (mine1[num1][num2] >= REVEAL)
				return;
			else if (mine1[num1][num2] >= ZERO && mine1[num1][num2] <= MARK) {
				mine1[num1][num2] += HUNDRED;//��100,��Ǹ�λ��Ϊ��
				if (*counter > 0) {
					(*counter)--;
				}
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1));
				cct_setcolor(COLOR_RED, COLOR_WHITE);
				cout << setw(4) << "#";
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1) - 1);
				cct_setcolor(COLOR_RED, COLOR_RED);
				cout << setw(4) << " ";
				cct_setcolor();
			}
			else if (mine1[num1][num2] >= HUNDRED && mine1[num1][num2] <= HUNDRED + MARK) {
				mine1[num1][num2] -= HUNDRED;//ȡ�����
				if (*counter < 10) {
					(*counter)++;
				}
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1));
				cct_setcolor(COLOR_YELLOW, COLOR_YELLOW);
				cout << setw(4) << " ";
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1) - 1);
				cct_setcolor(COLOR_YELLOW, COLOR_YELLOW);
				cout << setw(4) << " ";
				cct_setcolor();
			}
			break;
		case(2):
			if (mine2[num1][num2] >= REVEAL)
				return;
			else if (mine2[num1][num2] >= ZERO && mine2[num1][num2] <= MARK) {
				mine2[num1][num2] += HUNDRED;//��100,��Ǹ�λ��Ϊ��
				if (*counter > 0) {
					(*counter)--;
				}
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1));
				cct_setcolor(COLOR_RED, COLOR_WHITE);
				cout << setw(4) << "#";
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1) - 1);
				cct_setcolor(COLOR_RED, COLOR_RED);
				cout << setw(4) << " ";
				cct_setcolor();
			}
			else if (mine2[num1][num2] >= HUNDRED && mine2[num1][num2] <= HUNDRED + MARK) {
				mine2[num1][num2] -= HUNDRED;//ȡ�����
				if (*counter < 40) {
					(*counter)++;
				}
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1));
				cct_setcolor(COLOR_YELLOW, COLOR_YELLOW);
				cout << setw(4) << " ";
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1) - 1);
				cct_setcolor(COLOR_YELLOW, COLOR_YELLOW);
				cout << setw(4) << " ";
				cct_setcolor();
			}
			break;
		case(3):
			if (mine3[num1][num2] >= REVEAL)
				return;
			else if (mine3[num1][num2] >= ZERO && mine3[num1][num2] <= MARK) {
				mine3[num1][num2] += HUNDRED;//��100,��Ǹ�λ��Ϊ��
				if (*counter > 0) {
					(*counter)--;
				}
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1));
				cct_setcolor(COLOR_RED, COLOR_WHITE);
				cout << setw(4) << "#";
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1) - 1);
				cct_setcolor(COLOR_RED, COLOR_RED);
				cout << setw(4) << " ";
				cct_setcolor();
			}
			else if (mine3[num1][num2] >= HUNDRED && mine3[num1][num2] <= HUNDRED + MARK) {
				mine3[num1][num2] -= HUNDRED;//ȡ�����
				if (*counter < 99) {
					(*counter)++;
				}
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1));
				cct_setcolor(COLOR_YELLOW, COLOR_YELLOW);
				cout << setw(4) << " ";
				cct_gotoxy(5 + 6 * (num2 - 1) - 2, 4 + 3 * (num1 - 1) - 1);
				cct_setcolor(COLOR_YELLOW, COLOR_YELLOW);
				cout << setw(4) << " ";
				cct_setcolor();
			}
			break;
	}

}
void primary_mine(int* counter, int nandu)
{
	switch (nandu)
	{
		case(1):
			*counter = 10;
			break;
		case(2):
			*counter = 40;
			break;
		case(3):
			*counter = 99;
			break;
	}
}

/*�������ƣ�graph_gamemode(��
������� int nandu ,int x,int mine1[][],mine2[][],mine3[][]
�������ܣ���Ϸģʽÿ�δ���Ӧ������
��������ֵ
˵����8/9���ô˺���
test_mouse ����������1 ˵������esc�������������
  */
void graph_gamemode(int nandu, int x, int mine1[][SCALE1],
	int mine2[][SCALE2], int mine3[][SCALE3], int* line, int* column, float begin_time)
{
	int exit = 0;
	int right_click = 0;
	int counter = 0;
	primary_mine(&counter, nandu);
	while (1) {
		int exit = test_mouse(nandu, x, line, column, &right_click);
		if (exit == 1) {//����esc��
			return;
		}
		else if (exit == 2 && x == 9) {//����ʱ��
			cur_time_number(counter, 1, begin_time);
		}
		else if (right_click == 0) {//�������
			digui_first(nandu, *line, *column, mine1, mine2, mine3);
			graph_firstopen(nandu, mine1, mine2, mine3);
		}
		else {//�����Ҽ�
			mark_sign(nandu, mine1, mine2, mine3, *line, *column, &counter);
			if (x == 9) {
				cur_time_number(counter, 2, begin_time);
			}
		}
		int panduan = judge_game(mine1, mine2, mine3, nandu);
		if (panduan == 0) {
			switch (nandu)
			{
				case(1):
					cct_gotoxy(0, 30);
					break;
				case(2):
				case(3):
					cct_gotoxy(0, 51);
					break;
			}
			if (x == 9) {
				cout << "����ʱ" << float(clock() / 1000.0) - begin_time << "��,";
			}
			cout << "������, ��Ϸ����           \n";
			break;
		}
		else if (panduan == 2) {
			switch (nandu)
			{
				case(1):
					cct_gotoxy(0, 30);
					break;
				case(2):
				case(3):
					cct_gotoxy(0, 51);
					break;
			}
			if (x == 9) {

				cout << "����ʱ" << float(clock() / 1000.0) - begin_time << "��,";
			}
			cout << "��ϲʤ������Ϸ������\n";
			break;
		}
		else//����ֵ��1����Ϸ����
			;

	}
	return;
}
/******************************************************
�������ƣ�cur_time_number
�������ܣ����ص�ǰ��ʱ�������������ӡ
����˵����choice=1˵��ȡʱ�� choice=2˵����ʾ����
��������ֵ��
******************************************************/
void cur_time_number(int mine_counter, int choice, float begin_time)
{
	cct_gotoxy(0, 0);
	cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
	if (choice == 1) {
		cout << "��ǰʱ��" << float(clock() / 1000.0) - begin_time << "��,";
	}
	else if (choice == 2) {
		cout << "ʣ������" << mine_counter << "��";
	}
	cct_setcolor();
	cout << "ESC�˳����ո���ʾʱ��";
}

/*�������ƣ�graph_showarray()
������� menu_choice\difficulty_choice
�������ܣ���ʾ��ʼ��αͼ�ν���
��������ֵ����
����˵�����˺����ǲ˵���5-9�ĺ��ĺ��� ���в���������������������
�����������ɺ���create_array
���ûس���������pause_enter();*/
void graph_showarray(int menu_choice, int difficulty_choice)
{
	//���������ССһ��
	cct_setfontsize("������", 16);
	int cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines;//���еĻ���������ֵ
	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);//ȡ���л������Ĵ�С
	/* ������ֵ�����ڻָ� */
	cur_cols = cols;
	cur_lines = lines;
	cur_buffer_cols = buffer_cols;
	cur_buffer_lines = buffer_lines;
	int mark = 0;
	cct_cls();//������
	int mine1[SCALE1][SCALE1] = { 0 };//9*9��ɨ�� 10����
	int mine2[SCALE2][SCALE2] = { 0 };//16*16     40����
	int mine3[SCALE2][SCALE3] = { 0 };//16*30     99����
	int line = 0, column = 0;//���������µ�ֵ
	float begin_time = 0;
	if (menu_choice == 9) {//��ʼʱ��
		begin_time = float(clock() / 1000.0);
	}
	if (menu_choice == 5 || menu_choice == 6) {
		create_array(difficulty_choice, mine1, mine2, mine3);/*�γ���������*/
	}
	print_graph(menu_choice, difficulty_choice, mine1, mine2, mine3);//�γɳ�ʼ����
	prompt_word(menu_choice);
	if (menu_choice == 6) {
		//�������λ��
		test_mouse(difficulty_choice, menu_choice, &line, &column, &mark);

	}
	else if (menu_choice == 7 || menu_choice == 8 || menu_choice == 9) {//7��8/9�ĵ�һ���ϲ�
		int exit = test_mouse(difficulty_choice, menu_choice, &line, &column, &mark);
		if (exit == 1) {//�����8 ����ִ��esc���
			switch (difficulty_choice)
			{
				case(1):
					cct_gotoxy(0, 31);
					break;
				case(2):
				case(3):
					cct_gotoxy(0, 52);
					break;
			}
			pause_enter();
			cct_setconsoleborder(cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines);//�ָ�Ϊ��ʼ
			cct_setfontsize("������", 24);
			return;
		}
		while (exit == 2 && menu_choice == 9) {//�ո��
			cct_gotoxy(0, 0);
			cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
			cout << "��ǰʱ��" << float(clock() / 1000.0) - begin_time << "��,";
			cct_setcolor();
			cout << "ESC�˳����ո���ʾʱ��";
			exit = test_mouse(difficulty_choice, menu_choice, &line, &column, &mark);

		}
		//���8δ�����˳�������ִ��ͬ7��һ������
		makeup_mine(line, column, difficulty_choice, mine1, mine2, mine3);//���ݵ�һ���������������������
		digui_first(difficulty_choice, line, column, mine1, mine2, mine3);
		graph_firstopen(difficulty_choice, mine1, mine2, mine3);
	}

	if (menu_choice == 7 && difficulty_choice == 1)
		cct_gotoxy(0, 31);
	else if (menu_choice == 7)
		cct_gotoxy(0, 52);
	else if (menu_choice == 8 || menu_choice == 9) {
		graph_gamemode(difficulty_choice, menu_choice, mine1, mine2, mine3, &line, &column, begin_time);//ѭ��ִ����Ϸֱ���ɹ�

	}
	pause_enter();
	cct_setconsoleborder(cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines);//�ָ�Ϊ��ʼ
	cct_setfontsize("������", 24);
	return;
}
