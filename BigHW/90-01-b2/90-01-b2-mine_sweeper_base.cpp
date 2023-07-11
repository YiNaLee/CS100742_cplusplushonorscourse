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
/*本文件功能：内部数组版相关函数的实现*/
/**********************************************
函数名称：
输入参数：
函数功能：
返回值：
说明：
***********************************************/


/******************************************
函数名称：difficulty_choice
函数功能：输入难度参数的选择
函数返回值：难度选项1-3
******************************************/
int difficulty_choice()
{
	/*清屏*/
	cct_cls();
	int choice;
	cout << "请选择难度：\n";
	cout << "  1.初级(9*9   - 10颗雷)\n";
	cout << "  2.中级(16*16 - 40颗雷)\n";
	cout << "  3.高级(16*30 - 99颗雷)\n";
	cout << "请输入[1..3]:\n";
	while (1)
	{
		choice = _getch();
		if (choice >= '1' && choice <= '3')
			break;
	}
	return choice - '0';
}

/**********************************************
函数名称：pause_enter()
输入参数：
函数功能：调用此函数，实现按回车键继续的功能
返回值：
说明：
***********************************************/
void pause_enter()
{
	cout << endl;
	cout << "按回车键继续...";
	while (1)
	{
		int enter = _getch();
		if (enter == '\r')
			break;
	}

}


/**********************************************
函数名称：cnt_array()
输入参数：int mine[][];
函数功能：统计非雷点周围的雷的个数
返回值：无
说明：嵌在create_array中
***********************************************/
void cnt_array1(int mine1[][SCALE1], int i, int j)
{//传入的数组实际上是一个指针，因此对于mine2.mine3仍然可以使用此变量

	if (mine1[i][j] != '*')//周围8个
	{
		if (mine1[i - 1][j] == '*')
			mine1[i][j]++;

		if (mine1[i + 1][j] == '*')
			mine1[i][j]++;

		if (mine1[i][j - 1] == '*')
			mine1[i][j]++;

		if (mine1[i][j + 1] == '*')
			mine1[i][j]++;

		if (mine1[i - 1][j - 1] == '*')
			mine1[i][j]++;

		if (mine1[i - 1][j + 1] == '*')
			mine1[i][j]++;

		if (mine1[i + 1][j - 1] == '*')
			mine1[i][j]++;

		if (mine1[i + 1][j + 1] == '*')
			mine1[i][j]++;
	}
}

void cnt_array2(int mine2[][SCALE2], int i, int j)
{
	if (mine2[i][j] != '*')//周围8个
	{
		if (mine2[i - 1][j] == '*')
			mine2[i][j]++;

		if (mine2[i + 1][j] == '*')
			mine2[i][j]++;

		if (mine2[i][j - 1] == '*')
			mine2[i][j]++;

		if (mine2[i][j + 1] == '*')
			mine2[i][j]++;

		if (mine2[i - 1][j - 1] == '*')
			mine2[i][j]++;

		if (mine2[i - 1][j + 1] == '*')
			mine2[i][j]++;

		if (mine2[i + 1][j - 1] == '*')
			mine2[i][j]++;

		if (mine2[i + 1][j + 1] == '*')
			mine2[i][j]++;
	}
}
void cnt_array3(int mine3[][SCALE3], int i, int j)
{
	if (mine3[i][j] != '*')//周围8个
	{
		if (mine3[i - 1][j] == '*')
			mine3[i][j]++;

		if (mine3[i + 1][j] == '*')
			mine3[i][j]++;

		if (mine3[i][j - 1] == '*')
			mine3[i][j]++;

		if (mine3[i][j + 1] == '*')
			mine3[i][j]++;

		if (mine3[i - 1][j - 1] == '*')
			mine3[i][j]++;

		if (mine3[i - 1][j + 1] == '*')
			mine3[i][j]++;

		if (mine3[i + 1][j - 1] == '*')
			mine3[i][j]++;

		if (mine3[i + 1][j + 1] == '*')
			mine3[i][j]++;
	}
}

/***************************************************************
函数名称：create_array
参数：difficulty_chioce
函数功能：生成扫雷数组 9*9 或16*16或16*30
函数返回值： 无
********************************************************************/
void create_array(int difficulty_choice, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[SCALE2][SCALE3])
{

	int i, j;
	srand((unsigned int)(time(0)));//生成随机数的种子
	if (difficulty_choice == 1) {//9*9
		/*先确定雷的位置*/
		for (i = 0; i < MINE1_NUM; i++)
		{
			while (1)
			{
				int X, Y;
				X = rand() % (SCALE1 - 2) + 1;
				Y = rand() % (SCALE1 - 2) + 1;
				if (mine1[X][Y] == 0)//不能有覆盖
				{
					mine1[X][Y] = '*';//随机生成数组中的10个雷
					break;
				}
				else
					continue;
			}

		}
		/*然后计算周围雷的个数*/
		for (i = 1; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
			{
				cnt_array1(mine1, i, j);
			}
		}
	}
	else if (difficulty_choice == 2) {//16*16
		for (i = 0; i < MINE2_NUM; i++)
		{
			while (1)
			{
				int X, Y;
				X = rand() % (SCALE2 - 2) + 1;
				Y = rand() % (SCALE2 - 2) + 1;
				if (mine2[X][Y] == 0)//不能有覆盖
				{
					mine2[X][Y] = '*';//随机生成数组中的10个雷
					break;
				}
				else
					continue;
			}

		}
		/*然后计算周围雷的个数*/
		for (i = 1; i < 17; i++)
		{
			for (j = 1; j < 17; j++)
			{
				cnt_array2(mine2, i, j);

			}
		}
	}
	else {//16*30
		for (i = 0; i < MINE3_NUM; i++)
		{
			while (1)
			{
				int X, Y;
				X = rand() % (SCALE2 - 2) + 1;
				Y = rand() % (SCALE3 - 2) + 1;
				if (mine3[X][Y] == 0)//不能有覆盖
				{
					mine3[X][Y] = '*';//随机生成数组中的10个雷
					break;
				}
				else
					continue;
			}
		}
		/*然后再计算周围的雷的个数*/
		for (i = 1; i < 17; i++)
		{
			for (j = 1; j < 31; j++)
			{
				cnt_array3(mine3, i, j);

			}
		}

	}
}
/************************************************************
函数名称：print_array
函数参数：difficulty_choice,mine1[][],mine2[][],mine3[][]
函数功能：打印第一步的数组
返回值：无
*************************************************************/
void print_array1(int difficulty_choice, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	int i, j;
	cout << "内部数组\n";
	switch (difficulty_choice)
	{
		case(1)://打印9*9的地雷数组
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			cout << "\n--+";
			for (i = 0; i < 20; i++) {
				cout << "-";
			}
			cout << endl;

			for (i = 1; i < SCALE1 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE1 - 1; j++)
				{
					if (mine1[i][j] == 42)
						cout << "* ";
					else
						cout << mine1[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case(2):
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			for (i = 0; i < 7; i++) {
				putchar('a' + i);
				putchar(' ');
			}
			cout << "\n--+";
			for (i = 0; i < 35; i++) {
				cout << "-";
			}
			cout << endl;
			/*接下来输出内部的雷*/
			for (i = 1; i < SCALE2 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE2 - 1; j++)
				{
					if (mine2[i][j] == 42)
						cout << "* ";
					else
						cout << mine2[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case(3):
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			for (i = 0; i < 21; i++) {
				putchar('a' + i);
				putchar(' ');
			}
			cout << endl;
			/*接下来输出内部的雷*/
			for (i = 1; i < SCALE2 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE3 - 1; j++)
				{
					if (mine3[i][j] == 42)
						cout << "* ";
					else
						cout << mine3[i][j] << " ";
				}
				cout << endl;
			}
			break;
	}

}
void inner_show_arrary(int menu_choice, int difficulty_choice)
{
	cct_cls();//先清屏
	int mine1[SCALE1][SCALE1] = { 0 };//9*9的扫雷 10颗雷
	int mine2[SCALE2][SCALE2] = { 0 };//16*16     40颗雷
	int mine3[SCALE2][SCALE3] = { 0 };//16*30     99颗雷
	//int i=1,j=1;

	if (menu_choice == 1) {
		create_array(difficulty_choice, mine1, mine2, mine3);/*形成三个数组*/
		print_array1(difficulty_choice, mine1, mine2, mine3);
	}
	cout << endl;
	cout << "按回车键继续...";
	while (1)
	{
		int enter = _getch();
		if (enter == '\r')
			break;
	}

}

/**********************************************
函数名称：prompt_command()
输入参数：nandu &num1 &num2
函数功能：从键盘读入第一个要打开的位置坐标
返回值：返回2代表输入了&，取时间
		返回0代表输入q，退出
		返回1代表输入点开的数组
		若返回1且mark=999代表标记为雷
		若返回1且mark=888代表取消该标记

说明：调用此函数可以得到第一个要打开的位置的坐标
***********************************************/
int prompt_command(int nandu, int* num1, int* num2, int x, int* mark)
{
	*mark = 0;//初始每次mark为0，
	if (x == 4) {
		cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)\n";
		cout << setw(14) << " " << "！- 标记该坐标为雷(例：!E3)\n";
		cout << setw(14) << " " << "# - 取消标记      (例：#E3)\n";

	}
	cout << "输入非零位置的行列坐标(先行后列，严格区分大小写，例G1/Af,按Q/q退出) : ";
	while (1) {
		*num1 = _getch();
		if (*num1 == '!' && x == 4) {
			putchar(*num1);//显示!号
			*num1 = _getch();
			*mark = 999;//标记为雷，则mark为999
		}
		else if (*num1 == '#' && x == 4) {
			putchar(*num1);//显示#号
			*num1 = _getch();
			*mark = 888;//取消标记该点为雷

		}
		else if (*num1 == '&' && x == 4) {//取时间
			float time = float(clock() / 1000.0);
			cout << "\n已运行时间：" << time << "秒\n";
			return 2;
		}
		else if (*num1 == 'Q' || *num1 == 'q') {
			putchar(*num1);
			return 0;
		}

		switch (nandu)
		{
			case(1):
				if (*num1 >= 'A' && *num1 <= 'I')
				{
					putchar(*num1);
					*num1 = *num1 - 'A' + 1;
					while (1) {
						*num2 = _getch();
						if (*num2 >= '1' && *num2 <= '9') {
							putchar(*num2);
							*num2 = *num2 - '0';
							return 1;
						}

					}
				}
				break;
			case(2):
				if (*num1 >= 'A' && *num1 <= 'P') {
					putchar(*num1);
					*num1 = *num1 - 'A' + 1;
					while (1) {
						*num2 = _getch();
						if (*num2 >= '1' && *num2 <= '9' || *num2 >= 'a' && *num2 <= 'g') {
							putchar(*num2);
							if (*num2 >= 'a' && *num2 <= 'g')
								*num2 = *num2 - 'a' + 10;
							else {
								*num2 = *num2 - '0';
							}
							return 1;
						}
					}
				}
				break;
			case(3):
				if (*num1 >= 'A' && *num1 <= 'P') {
					putchar(*num1);
					*num1 = *num1 - 'A' + 1;
					while (1) {
						*num2 = _getch();
						if (*num2 >= '1' && *num2 <= '9' || *num2 >= 'a' && *num2 <= 'u') {
							putchar(*num2);
							if (*num2 >= 'a' && *num2 <= 'u')
								*num2 = *num2 - 'a' + 10;
							else
								*num2 = *num2 - '0';
							return 1;
						}
					}
				}
				break;
		}

	}


}
/**********************************************
函数名称：makeup_mine()
输入参数：num1代表行 num2代表列
函数功能：在得到第一次输入的位置坐标后才布雷
返回值：
说明：布局要求：自身非雷，周围八个位置全部非雷
对应第二个菜单选项
***********************************************/
void makeup_mine(int num1, int num2, int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{

	int i, j;
	srand((unsigned int)(time(0)));
	/*随机生成指定数目的雷，但要求点中的区域的周围8个地方都不是雷*/
	switch (nandu)
	{
		case(1):
			for (i = 0; i < MINE1_NUM; i++)
			{
				while (1)
				{
					int X, Y;
					X = rand() % MAX_X1 + 1;
					Y = rand() % MAX_Y1 + 1;
					if (abs(X - num1) <= 1 && abs(Y - num2) <= 1) {//选定位置的周围八个位置必须不是雷
						continue;
					}
					if (mine1[X][Y] == 0)//不能有覆盖
					{
						mine1[X][Y] = '*';//随机生成数组中的雷
						break;
					}
					else
						continue;
				}

			}
			/*然后再统计非雷位置周围的雷数*/
			for (i = 1; i < 10; i++)
			{
				for (j = 1; j < 10; j++)
				{
					cnt_array1(mine1, i, j);
				}
			}
			break;

		case(2):
			for (i = 0; i < MINE2_NUM; i++)
			{
				while (1)
				{
					int X, Y;
					X = rand() % MAX_X2 + 1;
					Y = rand() % MAX_Y2 + 1;
					if (abs(X - num1) <= 1 && abs(Y - num2) <= 1) {//选定位置的周围八个位置必须不是雷
						continue;
					}
					if (mine2[X][Y] == 0)//不能有覆盖
					{
						mine2[X][Y] = '*';//随机生成数组中的雷
						break;
					}
					else
						continue;
				}

			}
			/*然后再统计周围*/
			/*然后计算周围雷的个数*/
			for (i = 1; i < 17; i++)
			{
				for (j = 1; j < 17; j++)
				{
					cnt_array2(mine2, i, j);

				}
			}
			break;
		case(3):
			for (i = 0; i < MINE3_NUM; i++)
			{
				while (1)
				{
					int X, Y;
					X = rand() % MAX_X3 + 1;
					Y = rand() % MAX_Y3 + 1;
					if (abs(X - num1) <= 1 && abs(Y - num2) <= 1) {//选定位置的周围八个位置必须不是雷
						continue;
					}
					if (mine3[X][Y] == 0)//不能有覆盖
					{
						mine3[X][Y] = '*';//随机生成数组中的雷
						break;
					}
					else
						continue;
				}

			}
			/*然后再统计周围非雷位置*/
			for (i = 1; i < 17; i++)
			{
				for (j = 1; j < 31; j++)
				{
					cnt_array3(mine3, i, j);

				}
			}
			break;

	}

}



/**********************************************
函数名称：print_hidden()
输入参数：nandu (1-3)
函数功能：显示不同大小的初始数组 全部以x表示表示遮蔽
返回值：无
说明：
***********************************************/
void print_hidden(int nandu, int canshu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int* mark)
{
	/*mark 999 代表标记为雷 *mark 888代表取消标记为雷*/
	int i, j;
	if (canshu == 1) {
		cct_cls();//先清屏
		cout << "内部数组:\n";
	}
	else
		cout << "\n点开后的数组为:\n";
	switch (nandu)
	{
		case(1)://打印9*9的地雷数组
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			cout << "\n--+";
			for (i = 0; i < 20; i++) {
				cout << "-";
			}
			cout << endl;
			/*接下来打印x*/
			for (i = 1; i < SCALE1 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE1 - 1; j++)
				{

					if (canshu == 1)
						cout << "X ";
					else {//判断数组内的值，如果大于等于1000，则减去1000，后打开！
						if (mine1[i][j] >= REVEAL) {
							mine1[i][j] -= REVEAL;
							//并且改变颜色
							if (mine1[i][j] == '*') {
								cout << '*';
								mine1[i][j] += REVEAL;//再将这个打开的雷赋值为1042 说明游戏结束
							}
							else if (mine1[i][j] == 0)//如果是0的位置，改变颜色打开
							{
								cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
								cout << mine1[i][j];
								mine1[i][j] += REVEAL;
							}
							else if (mine1[i][j] != '*') {//如果不是0但是也非雷，改变颜色，打开
								cct_setcolor(COLOR_HYELLOW, COLOR_GREEN);
								cout << mine1[i][j];
								mine1[i][j] += REVEAL;//打开后数组的值增加一千来标记这个点已经被打开

							}
							cct_setcolor();//恢复为缺省
							cout << " ";

						}/*上面是针对要打开的数组而言的*/
						else if ((mine1[i][j] >= 100) && canshu == 4) {//添加一个辅助功能 加100标记为雷
							cct_setcolor(COLOR_RED, COLOR_WHITE);//背景色红，前景色白
							cout << 'X';
							cct_setcolor();
							cout << " ";
						}
						else {
							cout << "X ";
						}
					}
				}
				cout << endl;
			}
			break;

		case(2):
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			for (i = 0; i < 7; i++) {
				putchar('a' + i);
				putchar(' ');
			}
			cout << "\n--+";
			for (i = 0; i < 35; i++) {
				cout << "-";
			}
			cout << endl;
			/*再输出x*/
			for (i = 1; i < SCALE2 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE2 - 1; j++)
				{
					//cout << "X ";
					if (canshu == 1) {
						cout << "X ";
					}
					else {//判断数组内的值，如果大于等于1000，则减去1000，后打开！
						if (mine2[i][j] >= REVEAL) {
							mine2[i][j] -= REVEAL;
							//并且改变颜色
							if (mine2[i][j] == '*') {
								cout << '*';
								mine2[i][j] += REVEAL;//再将这个打开的雷赋值为1042 说明游戏结束
							}
							else if (mine2[i][j] == 0)//如果是0的位置，改变颜色打开
							{
								cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
								cout << mine2[i][j];
								mine2[i][j] += REVEAL;
							}
							else if (mine2[i][j] != '*') {//如果不是0但是也非雷，改变颜色，打开
								cct_setcolor(COLOR_HYELLOW, COLOR_GREEN);
								cout << mine2[i][j];
								mine2[i][j] += REVEAL;//打开后数组的值增加一千来标记这个点已经被打开

							}
							cct_setcolor();//恢复为缺省
							cout << " ";
						}//上面是针对要打开的数组而言的
						else if ((mine2[i][j] >= 100) && canshu == 4) {//添加一个辅助功能 加100标记为雷
							cct_setcolor(COLOR_RED, COLOR_WHITE);//背景色红，前景色白
							cout << 'X';
							cct_setcolor();
							cout << " ";
						}
						else {
							cout << "X ";
						}
					}
				}
				cout << endl;
			}
			break;

		case(3):
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			for (i = 0; i < 21; i++) {
				putchar('a' + i);
				putchar(' ');
			}
			cout << endl;
			/*接下来输出内部的雷*/
			for (i = 1; i < SCALE2 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE3 - 1; j++)
				{
					if (canshu == 1) {
						cout << "X ";
					}
					else {//判断数组内的值，如果大于等于1000，则减去1000，后打开！
						if (mine3[i][j] >= REVEAL) {
							mine3[i][j] -= REVEAL;
							//并且改变颜色
							if (mine3[i][j] == '*') {
								cout << '*';
								mine3[i][j] += REVEAL;//再将这个打开的雷赋值为1042 说明游戏结束
							}
							else if (mine3[i][j] == 0)//如果是0的位置，改变颜色打开
							{
								cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
								cout << mine3[i][j];
								mine3[i][j] += REVEAL;
							}
							else if (mine3[i][j] != '*') {//如果不是0但是也非雷，改变颜色，打开
								cct_setcolor(COLOR_HYELLOW, COLOR_GREEN);
								cout << mine3[i][j];
								mine3[i][j] += REVEAL;//打开后数组的值增加一千来标记这个点已经被打开

							}
							cct_setcolor();//恢复为缺省
							cout << " ";

						}//上面是针对要打开的数组而言的
						else if ((mine3[i][j] >= 100) && canshu == 4) {//添加一个辅助功能 加100标记为雷
							cct_setcolor(COLOR_RED, COLOR_WHITE);//背景色红，前景色白
							cout << 'X';
							cct_setcolor();
							cout << " ";
						}
						else {
							cout << "X ";
						}
					}
				}
				cout << endl;
			}
			break;

	}
	cout << endl;
}


/*函数名称：remark()
函数功能如果标记为雷 把该处替换为999
		如果取消标记，把该处变成888
起到标记作用
*/
void remark(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int num1, int num2, int* mark)
{
	switch (nandu)
	{
		case(1):
			if (mine1[num1][num2] > REVEAL) {//说明该位置已经被打开，则不能进行标记操作
				return;
			}
			else if (*mark == SIGN) {//标记为雷
				if (mine1[num1][num2] >= ZERO && mine1[num1][num2] <= MARK)//如果已经被打开则不可再标记
					mine1[num1][num2] += HUNDRED;//加100,标记该位置
			}
			else if (*mark == UNSIGN) {//取消标记
				if (mine1[num1][num2] >= HUNDRED && mine1[num1][num2] <= HUNDRED + MARK)//如果已经被打开则不用操作，只对被标记的取消标记
					mine1[num1][num2] -= HUNDRED;//取消标记
			}
			break;
		case(2):
			if (mine2[num1][num2] > REVEAL) {//说明该位置已经被打开，则不能进行标记操作
				return;
			}
			else if (*mark == SIGN) {
				if (mine2[num1][num2] >= ZERO && mine2[num1][num2] <= MARK)//如果已经被打开则不可再标记
					mine2[num1][num2] += HUNDRED;//加100,标记该位置
			}
			else if (*mark == UNSIGN) {
				if (mine2[num1][num2] >= HUNDRED && mine2[num1][num2] <= HUNDRED + MARK)//如果已经被打开则不用操作，只对被标记的取消标记
					mine2[num1][num2] -= HUNDRED;//取消标记
			}
			break;
		case(3):
			if (mine3[num1][num2] > REVEAL) {//说明该位置已经被打开，则不能进行标记操作
				return;
			}
			else if (*mark == SIGN) {
				if (mine3[num1][num2] >= ZERO && mine3[num1][num2] <= MARK)//如果已经被打开则不可再标记
					mine3[num1][num2] += HUNDRED;//加100,标记该位置
			}
			else if (*mark == UNSIGN) {
				if (mine3[num1][num2] >= HUNDRED && mine3[num1][num2] <= HUNDRED + MARK)//如果已经被打开则不用操作，只对被标记的取消标记
					mine3[num1][num2] -= HUNDRED;//取消标记
			}
			break;


	}
	return;

}


/***************************************
函数名称：eight_direction
输入参数：
功能：可重复利用的代码 嵌套在digui_fist函数中国
说明：本小题在矩阵中找一个初始区域的方法要求用一个函数实现
****************************************/
void eight_direction(int nandu, int num1, int num2, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	digui_first(nandu, num1 - 1, num2, mine1, mine2, mine3);//递归继续 一共要寻找八个位置
	digui_first(nandu, num1, num2 - 1, mine1, mine2, mine3);
	digui_first(nandu, num1 + 1, num2, mine1, mine2, mine3);
	digui_first(nandu, num1, num2 + 1, mine1, mine2, mine3);
	digui_first(nandu, num1 + 1, num2 + 1, mine1, mine2, mine3);
	digui_first(nandu, num1 - 1, num2 + 1, mine1, mine2, mine3);
	digui_first(nandu, num1 - 1, num2 - 1, mine1, mine2, mine3);
	digui_first(nandu, num1 + 1, num2 - 1, mine1, mine2, mine3);
}

/***************************************
函数名称：digui_fist
输入参数：
功能：显示第一步的初始数组
//用递归寻找初始的区域，并且把该区域的值加1000
说明：本小题在矩阵中找一个初始区域的方法要求用一个函数实现
****************************************/
void digui_first(int nandu, int num1, int num2, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	switch (nandu)
	{
		case(1):
			if (num1 == 0 || num1 == BODER1 || num2 == 0 || num2 == BODER1)//到达边界范围，停止扩散
				return;
			if (mine1[num1][num2] == 0) {
				reveal(&mine1[num1][num2]);//将这个为0的位置打开
				eight_direction(nandu, num1, num2, mine1, mine2, mine3);//共要寻找八个位置
			}
			else if (mine1[num1][num2] > 0 && mine1[num1][num2] <= MINE1_NUM) {
				//如果是非0但非地雷的位置 ，揭露该位置后立刻停止
				reveal(&mine1[num1][num2]);
				return;
			}
			else if (mine1[num1][num2] == '*') {
				//如果打开的位置是雷，打印出雷后游戏结束
				reveal(&mine1[num1][num2]);
				return;
			}
			break;
		case(2):
			if (num1 == 0 || num1 == BODER2 || num2 == 0 || num2 == BODER2)//到达边界范围，停止扩散
				return;
			if (mine2[num1][num2] == 0) {
				reveal(&mine2[num1][num2]);//将这个为0的位置打开
				eight_direction(nandu, num1, num2, mine1, mine2, mine3);//共要寻找八个位置
			}
			else if (mine2[num1][num2] > 0 && mine2[num1][num2] <= MINE1_NUM) {
				//如果是非0但非地雷的位置 ，揭露该位置后立刻停止
				reveal(&mine2[num1][num2]);
				return;
			}
			else if (mine2[num1][num2] == '*') {
				//如果打开的位置是雷，打印出雷后游戏结束
				reveal(&mine2[num1][num2]);
				return;
			}
			break;
		case(3)://16*30的数组 所以num1的边界是BODER2
			if (num1 == 0 || num1 == BODER2 || num2 == 0 || num2 == BODER3)//到达边界范围，停止扩散
				return;
			if (mine3[num1][num2] == 0) {
				reveal(&mine3[num1][num2]);//将这个为0的位置打开
				eight_direction(nandu, num1, num2, mine1, mine2, mine3);//共要寻找八个位置
			}
			else if (mine3[num1][num2] > 0 && mine3[num1][num2] <= MINE1_NUM) {
				//如果是非0但非地雷的位置 ，揭露该位置后立刻停止
				reveal(&mine3[num1][num2]);
				return;
			}
			else if (mine3[num1][num2] == '*') {
				//如果打开的位置是雷，打印出雷后游戏结束
				reveal(&mine3[num1][num2]);
				return;
			}
			break;

	}

}

/***************************************
函数名称：first_open_arrray()
输入参数：nandu
功能：显示第一步的初始数组
返回值；
说明：
****************************************/
void first_open_array(int nandu, int x)
{
	int mark = 0;
	/*先定义三个扫雷数组 */
	int mine1[SCALE1][SCALE1] = { 0 };//9*9的扫雷 10颗雷
	int mine2[SCALE2][SCALE2] = { 0 };//16*16     40颗雷
	int mine3[SCALE2][SCALE3] = { 0 };//16*30     99颗雷
	int num1 = 0, num2 = 0;
	print_hidden(nandu, 1, mine1, mine2, mine3, &mark);//显示初始的遮盖部分
	int quit = prompt_command(nandu, &num1, &num2, x, &mark);//输入num1和num2或退出的指令
	if (quit == 1) {
		makeup_mine(num1, num2, nandu, mine1, mine2, mine3);//根据输入的第一个位置的坐标来布雷
		digui_first(nandu, num1, num2, mine1, mine2, mine3);//标记第一步要被打开的区域
		print_hidden(nandu, 2, mine1, mine2, mine3, &mark);//第一次打开
	}
	if (x == 2)
		pause_enter();


}
/***************************************
函数名称：print_perstep()
输入参数：nandu
功能：内部数组基础版
返回值；
说明：在第二步的基础上继续输入行列坐标直到游戏结束
对应第三个菜单选项
****************************************/
void print_perstep(int nandu, int x)
{/*先定义三个扫雷数组 */
	int mine1[SCALE1][SCALE1] = { 0 };//9*9的扫雷 10颗雷
	int mine2[SCALE2][SCALE2] = { 0 };//16*16     40颗雷
	int mine3[SCALE2][SCALE3] = { 0 };//16*30     99颗雷
	int num1 = 0, num2 = 0;
	int mark = 0;
	print_hidden(nandu, 1, mine1, mine2, mine3, &mark);//显示初始的遮盖部分
	/*下面是第一次输入*/
	int quit = prompt_command(nandu, &num1, &num2, x, &mark);//输入num1和num2或退出的指令
	while (quit == 2) {//如果输入是取时间的话
		quit = prompt_command(nandu, &num1, &num2, x, &mark);
	}
	if (quit == 1) {
		if (mark == 0) {//第一次操作默认点开一个数
			makeup_mine(num1, num2, nandu, mine1, mine2, mine3);//根据输入的第一个位置的坐标来布雷
			digui_first(nandu, num1, num2, mine1, mine2, mine3);//标记第一步要被打开的区域
			print_hidden(nandu, x, mine1, mine2, mine3, &mark);//第一次打开
		}
		while (x == 4 && mark == 999 || mark == 888) {//标记为雷 或者取消标记为雷 即第一次输入就标记了一个雷
			remark(nandu, mine1, mine2, mine3, num1, num2, &mark);
			print_hidden(nandu, x, mine1, mine2, mine3, &mark);//显示该雷
			quit = prompt_command(nandu, &num1, &num2, x, &mark);//继续操作
		}


	}
	else {//quit=0时，直接退出
		pause_enter();
		return;
	}
	/*从下面开始执行循环，每次打开一次，知道游戏结束为止*/
	while (1) {
		num1 = 0, num2 = 0;//每次重新开始前将num1,2清零
		quit = prompt_command(nandu, &num1, &num2, x, &mark);//输入num1和num2或退出的指令
		while (quit == 2) {//取时间
			quit = prompt_command(nandu, &num1, &num2, x, &mark);
		}
		if (quit == 0)
			break;
		else if (quit == 1 && mark == 0) {
			digui_first(nandu, num1, num2, mine1, mine2, mine3);//标记第一步要被打开的区域
			print_hidden(nandu, x, mine1, mine2, mine3, &mark);
		}
		else if (quit == 1 && x == 4) {
			remark(nandu, mine1, mine2, mine3, num1, num2, &mark);//标记为雷
			print_hidden(nandu, x, mine1, mine2, mine3, &mark);
		}

		int panduan = judge_game(mine1, mine2, mine3, nandu);
		if (panduan == 0) {
			cout << "你输了,游戏结束\n";
			break;
		}
		else if (panduan == 2) {
			cout << "恭喜胜利，游戏结束！\n";
			break;
		}
		else//返回值是1，游戏继续
			;
	}
	pause_enter();

}
