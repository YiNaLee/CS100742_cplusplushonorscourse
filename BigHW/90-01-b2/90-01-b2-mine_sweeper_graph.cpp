/* 信07 2052316 李祎娜 */
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
/*本文件功能：伪图形界面相关函数的实现*/
/*对应菜单项5-9*/




/******************************************************************************************************
函数名称：printline_chioce
说明：
0.choice选择要画的线
1.表示画竖线和灰色部分
2.表示打印从第二个横线开始的中间部分
3.打印第一行的横线
4.打印最后一行的横线
5.geshu选择要重复打印的次数*/
/*画伪图形界面   此函数只负责画框架和填充黄色或白色（初始的第一步还未打开的显示），不负责填入数字*/
/*输入不同的参数可以画不同的线*/
void printline_choice(int choice, int geshu, int x)
{
	int i, j;
	//难度1 2 3
	//对应9*9 16*16 16*30
	switch (choice)
	{
		case(1)://代表画两条竖线和灰白部分

			for (j = 0; j < 2; j++) {
				for (i = 0; i < geshu - 1; i++) {//打印个geshu-1遍
					cct_setcolor(COLOR_WHITE, COLOR_BLACK);
					cout << "║";
					if (x == 5 || x == 6)
						cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);//设为亮白色 打印空格
					else {//否则初始尾打开默认为黄色
						cct_setcolor(COLOR_YELLOW, COLOR_YELLOW);
					}
					cout << setw(4) << " ";
				}
				cct_setcolor(COLOR_WHITE, COLOR_BLACK);
				cout << "║";//最后一个边框位置无黄色填充
				cct_setcolor();//缺省打印一个空格
				cout << endl;
				cout << " ";
			}
			cct_setcolor();//恢复缺省
			break;
		case(2)://打印从第二个横线开始的中间部分
			cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			cout << "╠";
			for (i = 0; i < geshu; i++) {
				cout << "══╬";
			}
			cout << "══╣";
			cout << endl;
			cct_setcolor();//恢复缺省
			break;
		case(3)://打印第一个行的横线
			cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			cout << "╔";
			for (i = 0; i < geshu; i++) {
				cout << "══╦";

			}
			cout << "══╗";
			cout << endl;
			cct_setcolor();//恢复缺省
			break;
		case(4):///打印最后一行的横线
			cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			cout << "╚";
			for (i = 0; i < geshu; i++) {
				cout << "══╩";
			}
			cout << "══╝\n";
			cct_setcolor();//恢复缺省
			break;
	}
	return;
}

/************************************************
函数名称：graph_firstopen()
函数功能：在6的基础上第一次用鼠标打开扫雷数组
但是应当注意应该确定点下的点自身非雷
返回值：无
特殊说明：7/8/9共用此函数
地址传递 line和column通过地址来传递
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
						cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine1[i][j]);//打印数组
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
						cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine2[i][j]);//打印数组
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
						cct_setcolor(COLOR_HWHITE, COLOR_BLUE + mine3[i][j]);//打印数组
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
函数名称：print_graph
输入参数：int x,int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3]
函数功能：打印初始的框架：5/6的有数字填入，7/8/9的只打印黄色的遮盖的数组
函数特殊说明：无
*******************************************************/
void print_graph(int x, int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	int i, j;
	int first_X = 1, first_Y = 2;
	switch (nandu)
	{

		case(1)://9*9
			/*先打印数字和字母*/
			cct_setconsoleborder(59, 35);//9*9雷阵设置行为59,35
			cct_gotoxy(5, 1);
			for (i = 0; i < 9; i++) {
				cout << i << setw(5) << " ";
			}
			/*然后再打印黑色的框 背景为白色 前景为黑色*/
			cct_gotoxy(first_X, first_Y);
			/*先打印第一行*/
			printline_choice(3, 8, x);
			/*然后打印竖线和中间行*/
			for (i = 0; i < 8; i++) {
				putchar('A' + i);
				printline_choice(1, 10, x);
				printline_choice(2, 8, x);
			}
			/*然后打印最后一行*/
			putchar('A' + i);
			printline_choice(1, 10, x);
			printline_choice(4, 8, x);
			/*打印9*9的表格完成，接下来要填入非零的数字和雷*/
			if (x == 5 || x == 6) {
				for (i = 1; i < 10; i++) {//i代表行，j代表列
					for (j = 1; j < 10; j++) {
						if (mine1[i][j] > 0 && mine1[i][j] < 10) {
							/*数字要显示*/
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
			/*先打印第一行*/
			printline_choice(3, 15, x);
			/*然后打印竖线和中间行*/
			for (i = 0; i < 15; i++) {
				putchar('A' + i);
				printline_choice(1, 17, x);
				printline_choice(2, 15, x);
			}
			/*然后打印最后一行*/
			putchar('A' + i);
			printline_choice(1, 17, x);
			printline_choice(4, 15, x);
			/*打印16*16的表格完成，接下来要填入非零的数字和雷*/
			if (x == 5 || x == 6) {
				for (i = 1; i < 17; i++) {//i代表行，j代表列
					for (j = 1; j < 17; j++) {
						if (mine2[i][j] > 0 && mine2[i][j] < 10) {
							/*数字要显示*/
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
			/*先打印第一行*/
			printline_choice(3, 29, x);
			/*然后打印竖线和中间行*/
			for (i = 0; i < 15; i++) {
				putchar('A' + i);
				printline_choice(1, 31, x);
				printline_choice(2, 29, x);
			}
			/*然后打印最后一行*/
			putchar('A' + i);
			printline_choice(1, 31, x);
			printline_choice(4, 29, x);
			/*打印16*30的表格完成，接下来要填入非零的数字和雷*/
			if (x == 5 || x == 6) {
				for (i = 1; i < 17; i++) {//i代表行，j代表列
					for (j = 1; j < 31; j++) {
						if (mine3[i][j] > 0 && mine3[i][j] < 10) {
							/*数字要显示*/
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
/*函数名称：test_mouse()
输入参数
函数功能：在5的界面上检测鼠标的位置，按下左键结束
函数返回值：返回0说明仅进行鼠标操作，无键盘操作，返回1说明按下esc键 返回2说明按下空格键
//在菜单项9中，
特殊说明： */
int test_mouse(int nandu, int x, int* line, int* column, int* right_click)
{

	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int legal = 0;
	*right_click = 0;//清空
	cct_enable_mouse();
	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		/*X.Y可以获取当前鼠标的坐标*/
		if (ret == CCT_MOUSE_EVENT) {//鼠标事件，需要判断位置是否合法并转到某行打印
			switch (maction) {
				case MOUSE_ONLY_MOVED://移动，要判断位置
					if (nandu == 1)
						cct_gotoxy(0, 30);
					else
						cct_gotoxy(0, 51);
					cout << "【当前光标】";
					legal = judeg_XY(X, Y, nandu, line, column);//成功返回1
					break;
				case MOUSE_LEFT_BUTTON_CLICK://单击左键表示退出
					if (legal == 1 || x == 6) {
						loop = 0;

					}

					break;
				case MOUSE_RIGHT_BUTTON_CLICK://按下右键表示标记为雷或者取消标记为雷
					if (legal == 1 && (x == 8 || x == 9)) {
						*right_click = 1;//按下右键
						loop = 0;
					}
					break;

				case MOUSE_NO_ACTION:
				default:
					break;
			}
		}
		//菜单项8需要读键盘上的esc键
		else if (ret == CCT_KEYBOARD_EVENT && (x == 8 || x == 9)) {
			switch (keycode1) {
				case 27:	//ESC键 
					loop = 0;
					return 1;
				case 32:    //空格键
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
函数功能：判断位置是否合法
若位置非法 返回值为0
若位置合法，返回值为1
*********************************************/

int judeg_XY(int x, int y, int nandu, int* line, int* column)//把获得的光标位置穿进去即可
{
	switch (nandu)
	{
		case(1):
			if ((y >= 3 && y <= 28) && (y % 3 == 0 || y % 3 == 1)) {
				if (x >= 3 && x <= 54 && (x % 6 != 1 && x % 6 != 2)) {
					putchar(y / 3 + 'A' - 1);
					cout << " 行";
					putchar((x - 3) / 6 + '0');
					cout << " 列";
				}
				else {
					cout << "位置非法";
					return 0;
				}
			}
			else {
				cout << "位置非法";
				return 0;
			}
			break;
		case(2):
			if ((y >= 3 && y <= 49) && (y % 3 == 0 || y % 3 == 1)) {
				if (x >= 3 && x <= 96 && (x % 6 != 1 && x % 6 != 2)) {
					putchar(y / 3 + 'A' - 1);
					cout << " 行";
					cout << (x - 3) / 6;
					cout << " 列";
				}
				else {
					cout << "位置非法";
					return 0;
				}
			}
			else {
				cout << "位置非法";
				return 0;
			}
			break;
		case(3):
			if ((y >= 3 && y <= 49) && (y % 3 == 0 || y % 3 == 1)) {
				if (x >= 3 && x <= 180 && (x % 6 != 1 && x % 6 != 2)) {
					putchar(y / 3 + 'A' - 1);
					cout << " 行";
					cout << (x - 3) / 6;
					cout << " 列";
				}
				else {
					cout << "位置非法";
					return 0;
				}
			}
			else {
				cout << "位置非法";
				return 0;
			}
			break;

	}
	*line = y / 3;
	*column = (x - 3) / 6 + 1;
	return 1;//成功返回 位置合法为1
}

void prompt_word(int x)
{
	if (x == 8) {
		cct_setcolor();
		cct_gotoxy(0, 0);
		cout << "按ESC退出";
	}
	else if (x == 9) {
		cct_setcolor();
		cct_gotoxy(0, 0);
		cout << "按ESC退出,空格显示时间";
	}
}

/***************************************************
函数名称：mark_sign()
输入参数
函数功能：标记或取消标记为雷
函数返回值
说明：
 *********************************************** */
void mark_sign(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int num1, int num2, int* counter)
{

	switch (nandu)
	{
		case(1):
			if (mine1[num1][num2] >= REVEAL)
				return;
			else if (mine1[num1][num2] >= ZERO && mine1[num1][num2] <= MARK) {
				mine1[num1][num2] += HUNDRED;//加100,标记该位置为雷
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
				mine1[num1][num2] -= HUNDRED;//取消标记
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
				mine2[num1][num2] += HUNDRED;//加100,标记该位置为雷
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
				mine2[num1][num2] -= HUNDRED;//取消标记
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
				mine3[num1][num2] += HUNDRED;//加100,标记该位置为雷
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
				mine3[num1][num2] -= HUNDRED;//取消标记
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

/*函数名称：graph_gamemode(）
输入参数 int nandu ,int x,int mine1[][],mine2[][],mine3[][]
函数功能：游戏模式每次打开相应的数组
函数返回值
说明：8/9共用此函数
test_mouse 函数若返回1 说明按下esc键，程序结束：
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
		if (exit == 1) {//按下esc键
			return;
		}
		else if (exit == 2 && x == 9) {//返回时间
			cur_time_number(counter, 1, begin_time);
		}
		else if (right_click == 0) {//按下左键
			digui_first(nandu, *line, *column, mine1, mine2, mine3);
			graph_firstopen(nandu, mine1, mine2, mine3);
		}
		else {//按下右键
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
				cout << "共用时" << float(clock() / 1000.0) - begin_time << "秒,";
			}
			cout << "你输了, 游戏结束           \n";
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

				cout << "共用时" << float(clock() / 1000.0) - begin_time << "秒,";
			}
			cout << "恭喜胜利，游戏结束！\n";
			break;
		}
		else//返回值是1，游戏继续
			;

	}
	return;
}
/******************************************************
函数名称：cur_time_number
函数功能：返回当前的时间或者雷数并打印
函数说明：choice=1说明取时间 choice=2说明显示雷数
函数返回值：
******************************************************/
void cur_time_number(int mine_counter, int choice, float begin_time)
{
	cct_gotoxy(0, 0);
	cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
	if (choice == 1) {
		cout << "当前时间" << float(clock() / 1000.0) - begin_time << "秒,";
	}
	else if (choice == 2) {
		cout << "剩余雷数" << mine_counter << "，";
	}
	cct_setcolor();
	cout << "ESC退出，空格显示时间";
}

/*函数名称：graph_showarray()
输入参数 menu_choice\difficulty_choice
函数功能：显示初始化伪图形界面
函数返回值：无
特殊说明：此函数是菜单项5-9的核心函数 所有操作都在这个主函数里完成
调用数组生成函数create_array
调用回车继续函数pause_enter();*/
void graph_showarray(int menu_choice, int difficulty_choice)
{
	//设置字体大小小一点
	cct_setfontsize("新宋体", 16);
	int cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines;//现有的缓冲区行列值
	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);//取现有缓冲区的大小
	/* 保留现值，用于恢复 */
	cur_cols = cols;
	cur_lines = lines;
	cur_buffer_cols = buffer_cols;
	cur_buffer_lines = buffer_lines;
	int mark = 0;
	cct_cls();//先清屏
	int mine1[SCALE1][SCALE1] = { 0 };//9*9的扫雷 10颗雷
	int mine2[SCALE2][SCALE2] = { 0 };//16*16     40颗雷
	int mine3[SCALE2][SCALE3] = { 0 };//16*30     99颗雷
	int line = 0, column = 0;//返回鼠标点下的值
	float begin_time = 0;
	if (menu_choice == 9) {//初始时间
		begin_time = float(clock() / 1000.0);
	}
	if (menu_choice == 5 || menu_choice == 6) {
		create_array(difficulty_choice, mine1, mine2, mine3);/*形成三个数组*/
	}
	print_graph(menu_choice, difficulty_choice, mine1, mine2, mine3);//形成初始大框架
	prompt_word(menu_choice);
	if (menu_choice == 6) {
		//检测鼠标的位置
		test_mouse(difficulty_choice, menu_choice, &line, &column, &mark);

	}
	else if (menu_choice == 7 || menu_choice == 8 || menu_choice == 9) {//7和8/9的第一步合并
		int exit = test_mouse(difficulty_choice, menu_choice, &line, &column, &mark);
		if (exit == 1) {//如果是8 并且执行esc语句
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
			cct_setconsoleborder(cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines);//恢复为初始
			cct_setfontsize("新宋体", 24);
			return;
		}
		while (exit == 2 && menu_choice == 9) {//空格键
			cct_gotoxy(0, 0);
			cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
			cout << "当前时间" << float(clock() / 1000.0) - begin_time << "秒,";
			cct_setcolor();
			cout << "ESC退出，空格显示时间";
			exit = test_mouse(difficulty_choice, menu_choice, &line, &column, &mark);

		}
		//如果8未输入退出，则先执行同7第一步操作
		makeup_mine(line, column, difficulty_choice, mine1, mine2, mine3);//根据第一次输入的坐标来制造数组
		digui_first(difficulty_choice, line, column, mine1, mine2, mine3);
		graph_firstopen(difficulty_choice, mine1, mine2, mine3);
	}

	if (menu_choice == 7 && difficulty_choice == 1)
		cct_gotoxy(0, 31);
	else if (menu_choice == 7)
		cct_gotoxy(0, 52);
	else if (menu_choice == 8 || menu_choice == 9) {
		graph_gamemode(difficulty_choice, menu_choice, mine1, mine2, mine3, &line, &column, begin_time);//循环执行游戏直到成功

	}
	pause_enter();
	cct_setconsoleborder(cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines);//恢复为初始
	cct_setfontsize("新宋体", 24);
	return;
}
