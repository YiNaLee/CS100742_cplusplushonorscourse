/* 信07 2052316 李祎娜 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include"../include/cmd_console_tools.h"
#include"../include/cmd_gmw_tools.h"
#include "90-01-b2-gmw.h"
#include"../include/basic_public.h"
using namespace std;
/*本文件功能：伪图形界面相关函数的实现*/
/*只对应扫雷完整版*/
/*说明：为了方便看清楚，虽然画框架无边框，但是将自身的小色块加了边框*/

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
函数名称：make_up_mine()
输入参数：num1表示第一次点开的行/num2表示第一次点开的列，难度表示选择的1/2/3 分别对应9*9  16*16和16*30
函数功能：调用此函数，随机生成扫雷的雷的位置
返回值：完成本函数后，扫雷内部数组的初始值已经建立
说明：
***********************************************/
void makeup_mine(int num1, int num2, int nandu, int mine_array[][MINE_ARRAYCOL])
{
	int i,j,MINE_NUM=0,MAX_X=0,MAX_Y=0;
	switch (nandu) {
		case 1:
			MINE_NUM = 10;//雷数为10
			MAX_X = 9;//规模为9*9
			MAX_Y = 9;//实际数组中为了方便计算，用的是11*11
			break;
		case 2:
			MINE_NUM = 40;
			MAX_X = 16;//规模为16*16
			MAX_Y = 16;//实际数组用到的是18*18
			break;
		case 3:
			MINE_NUM = 99;
			MAX_X = 16;//规模为16*16
			MAX_Y = 30;//实际数组用到的是18*30
			break;
	}

	for (i = 0; i < MINE_NUM; i++)
	{
		while (1)
		{
			int X, Y;
			X = rand() % MAX_X + 1;
			Y = rand() % MAX_Y + 1;
			if (abs(X - num1) <= 1 && abs(Y - num2) <= 1) {//选定位置的周围八个位置必须不是雷
				continue;
			}
			if (mine_array[X][Y] == 0)//不能有覆盖
			{
				mine_array[X][Y] = '*';//随机生成数组中的雷
				break;
			}
			else
				continue;
		}

	}
	/*然后为非雷位置周围赋值*/
	for (i = 1; i <=MAX_X; i++)
	{
		for (j = 1; j <=MAX_Y; j++)
		{
			if (mine_array[i][j] != '*')//周围8个
			{
				if (mine_array[i - 1][j] == '*')
					mine_array[i][j]++;

				if (mine_array[i + 1][j] == '*')
					mine_array[i][j]++;

				if (mine_array[i][j - 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i][j + 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i - 1][j - 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i - 1][j + 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i + 1][j - 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i + 1][j + 1] == '*')
					mine_array[i][j]++;
			}
		}
	}
	
}
void digui_sweeper(int nandu, int num1, int num2, int minesweeper[][MINE_ARRAYCOL])
{
	int borderline=0, bordercol=0;
	switch (nandu) {
		case 1:
			borderline = BODER1;
			bordercol = BODER1;
			break;
		case 2:
			borderline = BODER2;
			bordercol = BODER2;
			break;
		case 3:
			borderline = BODER2;
			bordercol = BODER3;
			break;
	}
	if (num1 == 0 || num1 == borderline || num2 == 0 || num2 ==bordercol)//到达边界范围，停止扩散
		return;
	if (minesweeper[num1][num2] == 0) {
		reveal(&minesweeper[num1][num2]);//将这个为0的位置打开
		digui_sweeper(nandu, num1 - 1, num2, minesweeper);//递归继续 一共要寻找八个位置
		digui_sweeper(nandu, num1, num2 - 1, minesweeper);
		digui_sweeper(nandu, num1 + 1, num2, minesweeper);
		digui_sweeper(nandu, num1, num2 + 1, minesweeper);
		digui_sweeper(nandu, num1 + 1, num2 + 1, minesweeper);
		digui_sweeper(nandu, num1 - 1, num2 + 1, minesweeper);
		digui_sweeper(nandu, num1 - 1, num2 - 1, minesweeper);
		digui_sweeper(nandu, num1 + 1, num2 - 1, minesweeper);
	}
	
	else if (minesweeper[num1][num2] > 0 && minesweeper[num1][num2] <= 10) {
		//如果是非0但非地雷的位置 ，揭露该位置后立刻停止
		reveal(&minesweeper[num1][num2]);
		return;
	}
	else if (minesweeper[num1][num2] == '*') {
		//如果打开的位置是雷，打印出雷后游戏结束
		reveal(&minesweeper[num1][num2]);
		return;
	}
}
/**********************************************
函数名称：graph_gmw_mine_sweeper()
输入参数：int x,int nandu
函数功能：对应菜单项9，调用gmw中的函数
返回值：
说明：
***********************************************/
void graph_gmw_mine_sweeper(int nandu)
{
	int line=0, col=0;
	CONSOLE_GRAPHICS_INFO MineSweeper_CGI; //声明一个CGI变量
	//9*9和16*16和16*30 适当放大，用18*32
	/*用缺省值初始化（窗口背景黑/前景白，点阵16*8，上下左右无额外行列，上下状态栏均有，无行号/列标，框架线型为双线，色块宽度2/高度1/无小边框，颜色略）*/
	gmw_init(&MineSweeper_CGI);
	//不带分割线
	gmw_set_frame_style(&MineSweeper_CGI, 6, 3, false);//色块不带分隔线高二宽4
	//还要修改的是游戏区域的颜色、游戏的行列根据输入而定
	//要改为显示行标和列标
	gmw_set_rowno_switch(&MineSweeper_CGI, true);							//显示行号
	gmw_set_colno_switch(&MineSweeper_CGI, true);							//显示列标
	//设置有游戏区域为亮白色，色块颜色为黄色，不联及；
	gmw_set_frame_color(&MineSweeper_CGI, COLOR_HWHITE, COLOR_BLACK);
	//色块具体颜色调用画色块函数时才改 
	const BLOCK_DISPLAY_INFO bdi_sweeper[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0不显示，用空格填充即可
		{1,  COLOR_HWHITE, COLOR_HCYAN, "1"},	//1表示有一个雷 背景色与框架相同
		{2, COLOR_HWHITE, COLOR_HBLUE, "2"},
		{3,  COLOR_HWHITE, COLOR_HRED, "3"},
		{4,  COLOR_HWHITE, COLOR_HRED, "4"},
		{5,  COLOR_HWHITE, COLOR_HBLACK, "5"},
		{6,  COLOR_HWHITE, COLOR_BLUE, "6"},
		{7,  COLOR_HWHITE, COLOR_RED, "7"},
		{8, COLOR_HWHITE, COLOR_RED, "8"},
		{10,COLOR_YELLOW + 1,-1,"  "},//数字10代表该位置没有被打开
		{-100,COLOR_RED + 1,-1,"#"},//-100表示标记该位置为雷
		{42,COLOR_HWHITE,COLOR_BLACK,"*"},//42表示该位置是雷
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	//色块颜色没打开默认是黄色，打开后是白色（框架背景色
	//
	switch (nandu) {
		case 1://9*9
			gmw_set_rowcol(&MineSweeper_CGI, LINECOLMIN, LINECOLMIN);
			line = LINECOLMIN;
			col = LINECOLMIN;
			break;
		case 2:
			gmw_set_rowcol(&MineSweeper_CGI, LINECOLMED, LINECOLMED);
			line = LINECOLMED;
			col = LINECOLMED;
			break;
		case 3:
			gmw_set_rowcol(&MineSweeper_CGI, LINECOLMED, COLMAX);
			line = LINECOLMED;
			col = COLMAX;
			break;
	}
	//色块默认改为需要小边框；
	gmw_set_block_border_switch(&MineSweeper_CGI, true);
	gmw_draw_frame(&MineSweeper_CGI);
	int mine_array[MINE_ARRAYLINE][MINE_ARRAYCOL] = { 0 };
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			//如果值小于10，则没有被打开
			gmw_draw_block(&MineSweeper_CGI, i, j, 10, bdi_sweeper);//初始化都是黄色；
		}
	}
	gmw_set_status_line_color(&MineSweeper_CGI, TOP_STATUS_LINE, COLOR_BLACK, COLOR_HWHITE, COLOR_BLACK, COLOR_HYELLOW);
	gmw_set_status_line_color(&MineSweeper_CGI, LOWER_STATUS_LINE, COLOR_BLACK, COLOR_HWHITE,COLOR_BLACK, COLOR_HYELLOW);
	//然后再利用鼠标操作，根据第一次点击的位置，并返回，布雷；
	gmw_status_line(&MineSweeper_CGI, TOP_STATUS_LINE, "右键标记或取消标记为雷","按ESC退出，空格显示时间");
	int loop = 1;
	int maction,mrow = -1, mcol = -1;
	int keycode1, keycode2;
	int ret;
	char temp[256] = " ";
	float begin_time = float(clock() / 1000.0);
	//游戏开始时，即有初始时间
	float cultime = 0;
	while (loop) {
		//old_mrow = mrow;
		//old_mcol = mcol;
		ret = gmw_read_keyboard_and_mouse(&MineSweeper_CGI, maction, mrow, mcol, keycode1, keycode2);
		//读到的mrow为显示出的行列，实际数组中的行列都要在再+1
		if (ret == CCT_MOUSE_EVENT) {
			if (maction == MOUSE_ONLY_MOVED) {
				//移动，状态栏显示；当前位置；
			}
			else {//第一次读到有效的左键和右键都开始布雷
				//退出循环，第一次独到的位置是mrow和mcol
				loop = 0;
			}
		}
		else { //CCT_KEYBOARD_EVENT - 具体键码含义去读 cmd_console_tools.cpp
			switch (keycode1) {
				case 32://空格显示时间
					//cout << "当前时间" << float(clock() / 1000.0) - begin_time << "秒,";用sprintf写
					cultime= float(clock() / 1000.0 - begin_time);
					sprintf(temp, "当前时间%lf秒，ESC退出，空格显示时间",cultime);
					gmw_status_line(&MineSweeper_CGI, TOP_STATUS_LINE, temp);//待完善
					
					break;
				case 27: 
					loop = 0;
					break;
				default:
					break;
			}//end of switch
		}//end of else
	}//end of while
	int num1 = mrow + 1;
	int num2 = mcol + 1;
	makeup_mine(num1, num2, nandu, mine_array);//布雷；
	//第一次点开后要用递归方法,寻找周边全为0的数组并打开,打开的标记就是将数组内部的值增加1000；
	digui_sweeper(nandu,num1, num2, mine_array);
	//再打印一次，
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			//如果值小于10，则仍然以黄色
			if (mine_array[i+1][j+1]>=0&&mine_array[i+1][j+1]<=10||mine_array[i+1][j+1]=='*'){
				gmw_draw_block(&MineSweeper_CGI, i, j, 10, bdi_sweeper);//小于1000，没有被打开，是黄色；
			}
			else {
				gmw_draw_block(&MineSweeper_CGI, i, j, mine_array[i+1][j+1]%100, bdi_sweeper);//
			}
		}
	}
	int fanhuizhi = graph_continue_mine_sweeper(&MineSweeper_CGI, nandu, &cultime, begin_time, mine_array);
	
	cct_gotoxy(MineSweeper_CGI.start_x, MineSweeper_CGI.start_y + MineSweeper_CGI .CFI.bhigh+1);
	pause_enter();
	
	
}
/**********************************************
函数名称：graph_continue_mine_sweeper()
输入参数：int x,int nandu
函数功能：循环执行直到遇到雷或游戏结束。
返回值：
说明：
***********************************************/
int graph_continue_mine_sweeper(CONSOLE_GRAPHICS_INFO* minesweeperCGI,int nandu,float*curtime,float begintime,int mine[][MINE_ARRAYCOL])
{//将结构体变量做参数传递进来，
	int line = 0;
	int col= 0;
	const BLOCK_DISPLAY_INFO bdi_sweeper[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0不显示，用空格填充即可
		{1,  COLOR_HWHITE, COLOR_HCYAN, "1"},	//1表示有一个雷 背景色与框架相同
		{2, COLOR_HWHITE, COLOR_HBLUE, "2"},
		{3,  COLOR_HWHITE, COLOR_HRED, "3"},
		{4,  COLOR_HWHITE, COLOR_HRED, "4"},
		{5,  COLOR_HWHITE, COLOR_HBLACK, "5"},
		{6,  COLOR_HWHITE, COLOR_BLUE, "6"},
		{7,  COLOR_HWHITE, COLOR_RED, "7"},
		{8, COLOR_HWHITE, COLOR_RED, "8"},
		{10,COLOR_YELLOW + 1,-1,"  "},//数字10代表该位置没有被打开
		{-100,COLOR_RED + 1,-1,"#"},//-100表示标记该位置为雷
		{42,COLOR_HWHITE,COLOR_BLACK,"*"},//42表示该位置是雷
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	int left_mine = 0;//剩余雷数
	int all_mine = 0;
	switch (nandu) {
		case 1://9*9
			
			line = LINECOLMIN;
			col = LINECOLMIN;
			all_mine = 10;
			break;
		case 2:
			line = LINECOLMED;
			col = LINECOLMED;
			all_mine = 40;
			break;
		case 3:
			line = LINECOLMED;
			col = COLMAX;
			all_mine = 99;
			break;
			
	}
	while (1) {
		int loop = 1;
		int maction, old_mrow, old_mcol, mrow = -1, mcol = -1;
		int keycode1, keycode2;
		int ret;
		char temp[256] = " ";
		while (loop) {
			old_mrow = mrow;
			old_mcol = mcol;
			ret = gmw_read_keyboard_and_mouse(minesweeperCGI, maction, mrow, mcol, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				if (maction == MOUSE_ONLY_MOVED) {
					//移动，状态栏显示；当前位置；
				}
				else {
					loop = 0;
				}
			}
			else { //CCT_KEYBOARD_EVENT - 具体键码含义去读 cmd_console_tools.cpp
				switch (keycode1) {
					case 32://空格显示时间
						//cout << "当前时间" << float(clock() / 1000.0) - begin_time << "秒,";用sprintf写
						*curtime = float(clock() / 1000.0 - begintime);
						sprintf(temp, "当前时间%lf秒，ESC退出，空格显示时间", *curtime);
						gmw_status_line(minesweeperCGI, TOP_STATUS_LINE, temp);//待完善

						break;
					case 27:
						loop = 0;
						return -99;//标记按下esc键的特殊值
						break;
					default:
						break;
				}//end of switch
			}//end of else
		}//end of while
		int num1 = mrow + 1;
		int num2 = mcol + 1;
		if (maction == MOUSE_LEFT_BUTTON_CLICK) {
			//左键的话；
			digui_sweeper(nandu, num1, num2, mine);
		}
		if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
			//右键；
			if (mine[num1][num2] < REVEAL && mine[num1][num2] >= 0) {
				//没有被打开过，可以标记为雷
				mine[num1][num2] -= 99999;
			}
			else if (mine[num1][num2] < 0) {
				//取消标记为雷。
				mine[num1][num2] += 99999;
			}
		}
		//再打印一次，
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				if (mine[i+1][j+1] < 1000&&mine[i+1][j+1]>=0) {//没有被打开
					gmw_draw_block(minesweeperCGI, i, j, 10, bdi_sweeper);//初始化都是黄色；
				}
				else {	
					if (mine[i+1][j+1]<0) {
						//将内部值-99999以作为被标记的标志，如果被标记了，则不能打开。
						gmw_draw_block(minesweeperCGI, i, j, -100, bdi_sweeper);//-100表示标记该处为雷
					}
					else {//被打开，则正常输出（包含输出雷的情况）
						gmw_draw_block(minesweeperCGI, i, j, mine[i+1][j+1] % 100, bdi_sweeper);//
					}
					
				}
			}
		}
		//然后再判断游戏是否结束，并且计算剩余雷的数，打印在上状态栏上。
		int gameover = judge_game_isover(nandu, mine,&left_mine);
		sprintf(temp, "剩余雷数%d个，按ESC键退出，空格显示时间                   ", all_mine-left_mine);
		gmw_status_line(minesweeperCGI, TOP_STATUS_LINE, temp);
		if (gameover == 0) {
			//游戏结束，下状态栏打印，退出循环。
			gmw_status_line(minesweeperCGI, LOWER_STATUS_LINE, "按回车键继续","游戏结束，你输了,");
			return 0;
		}
		if (gameover == 1) {
			//游戏继续；
			continue;
		}
		if (gameover == 2) {
			float alltime=float(clock() / 1000.0 - begintime);
			sprintf(temp, "一共用时%lf秒.", alltime);
			gmw_status_line(minesweeperCGI, LOWER_STATUS_LINE, temp,"恭喜你，你赢啦!");
			return 2;
		}
	}
}

/***************************************
函数名称：judge_game()
输入参数：nandu,mine_array
功能：判断游戏是否成功
返回值； 返回1说明游戏还可以继续，返回2说明游戏成功，返回0说明游戏失败
说明：
****************************************/
int judge_game_isover(int nandu,int mine_sweeper[][MINE_ARRAYCOL],int*pop_mine)
{
	int i, j;
	int counter = 0;//用于计算有几个雷
	int borderline = 0;//行数
	int bordercol = 0;//列数
	int mine_num = 0;//雷数
	*pop_mine = 0;
	switch (nandu)
	{
		case 1:
			borderline = BODER1;
			bordercol = BODER1;
			mine_num = MINEMIN;
			break;
		case 2:
			borderline = BODER2;
			bordercol = BODER2;
			mine_num = MINEMED;
			break;
		case 3:
			borderline = BODER2;
			bordercol = BODER3;
			mine_num = MINEMAX;
			break;
	}
	for (i = 1; i < borderline; i++) {
		for (j = 1; j < bordercol; j++) {
			if (mine_sweeper[i][j] <0) {
				(*pop_mine)++;
			}
		}
	}
	for (i = 1; i < borderline; i++) {
		for (j = 1; j < bordercol; j++) {
			/*if (mine_sweeper[i][j] < 0) {
				mine_sweeper[i][j] += 99999;//重新还原。
			}*/
			if (mine_sweeper[i][j] == '*' + REVEAL)
				return 0;//游戏失败,证明为雷的数组已经被打开
			if (mine_sweeper[i][j] < REVEAL)//如果数组中的值小于一千，说明该数组没有被打开
				counter++;

		}
	}
	if (counter == mine_num)
		return 2;//游戏成功
	else
		return 1;//游戏继续

	
}
