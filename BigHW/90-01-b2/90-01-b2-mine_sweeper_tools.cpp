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
/*本cpp的功能：判断游戏是否成功*/

/***************************************
函数名称：judge_game()
输入参数：nandu,mine1,mine2,mine3
功能：判断游戏是否成功
返回值； 返回1说明游戏还可以继续，返回2说明游戏成功，返回0说明游戏失败
说明：
****************************************/
int judge_game(int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int nandu)
{
	int i, j;
	int counter = 0;
	switch (nandu)
	{
		case(1):
			for (i = 1; i < BODER1; i++) {
				for (j = 1; j < BODER1; j++) {
					if (mine1[i][j] == '*' + 1000)
						return 0;//游戏失败
					if (mine1[i][j] < REVEAL)//如果数组中的值小于一千，说明该数组没有被打开
						counter++;
				}
			}
			if (counter == MINE1_NUM)
				return 2;//游戏成功
			else
				return 1;//游戏继续
			break;

		case(2):
			for (i = 1; i < BODER2; i++) {
				for (j = 1; j < BODER2; j++) {
					if (mine2[i][j] == '*' + 1000)
						return 0;
					if (mine2[i][j] < REVEAL)//如果数组中的值小于一千，说明该数组没有被打开
						counter++;
				}
			}
			if (counter == MINE2_NUM)
				return 2;//游戏成功
			else
				return 1;//游戏继续
			break;

		case(3):
			for (i = 1; i < BODER2; i++) {
				for (j = 1; j < BODER3; j++) {
					if (mine3[i][j] == '*' + 1000)
						return 0;
					if (mine3[i][j] < REVEAL)//如果数组中的值小于一千，说明该数组没有被打开
						counter++;
				}
			}
			if (counter == MINE3_NUM)
				return 2;//游戏成功
			else
				return 1;//游戏继续
			break;

	}

	return 0;
}