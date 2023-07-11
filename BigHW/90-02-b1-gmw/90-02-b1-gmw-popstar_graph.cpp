/*2052316 信07 李祎娜*/
#define _CRT_SECURE_NO_WARNINGS
/* -----------------------------------------
	 本文件功能：
	1、放消灭星星用gmw函数集完成的无分割线版本
	2、此文件中的函数为私有函数，供main调用
	3.注：由于时间限制，本程序仅真正实现了消灭星星完整版
   ----------------------------------------- */
   /**************************************************************************
   函数名称：get_line_column
   函数参数 两个指针变量
   函数功能 获得改变行和列的值
   函数返回值 无
   *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h" 
#include"../include/cmd_gmw_tools.h"
#include "90-02-b1-gmw.h"
#include"../include/basic_public.h"

using namespace std;
void get_line_column(int* line, int* column)
{
	while (1) {
		cct_gotoxy(0, 0);
		cout << "请输入行数（8-10）：";
		cin >> *line;
		if (!cin.good() || *line < 8 || *line>10) {
			cct_gotoxy(0, 1);
			cout << "输入不合法，请重新输入";
			cct_gotoxy(19, 0);
			cout << "                                                       ";
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (*line >= 8 && *line <= 10) {
			cct_gotoxy(0, 1);
			cout << "                                   ";
			cct_gotoxy(0, 1);
			cout << "请输入列数（8-10）：";
			while (1) {//检测列输入是否正确
				cct_gotoxy(20, 1);
				cin >> *column;
				if (!cin.good() || *column < 8 || *column>10) {
					cct_gotoxy(0, 2);
					cout << "输入不合法，请重新输入";
					cct_gotoxy(20, 1);
					cout << "                                                ";
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				else if (*column >= 8 && *column <= 10)
					break;
			}
			break;
		}
	}
}
/********************************************************************
函数名称：star_array_setup(...)
函数参数：
函数功能：根据输入的行列值生成颜色概率相等的消灭星星数组
函数返回值：
其他说明：

*********************************************************************/
void star_array_setup(int line, int column, int star_array[STARMAX][STARMAX])
{
	/*需要随机产生1-5等概率的数字，每次不相同*/
	srand((unsigned int)(time(0)));//生成随机数的种子
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			star_array[i][j] = rand() % 5 + 1;
		}
	}

}
/********************************************************************
函数名称：gmw_popstar_full_version(...)
函数参数：
函数功能：用gmw函数集完成消灭星星
函数返回值：
其他说明：游戏框架的行列值由传入参数line和column得到，

*********************************************************************/
int gmw_popstar_full_version(int line,int column,int star_array[][STARMAX] )
{
	//定义一个存放消灭星星色块颜色的结构体数组。
	const BLOCK_DISPLAY_INFO bdi_popstar[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0不显示，用空格填充即可
		{1,  COLOR_BLUE, COLOR_BLACK, "★"},	//1表示有一个雷 背景色与框架相同
		{2, COLOR_RED, COLOR_BLACK, "★"},
		{3,  COLOR_PINK,COLOR_BLACK, "★"},
		{4,  COLOR_CYAN, COLOR_BLACK, "★"},
		{5,  COLOR_HRED, COLOR_BLACK, "★"},
		{10, COLOR_HWHITE, COLOR_HWHITE, "  "},
		{11,  COLOR_BLUE, COLOR_HWHITE, "★"},	//内部值+10表示反显
		{12, COLOR_RED, COLOR_HWHITE, "★"},
		{13,  COLOR_PINK,COLOR_HWHITE, "★"},
		{14,  COLOR_CYAN, COLOR_HWHITE, "★"},
		{15,  COLOR_HRED, COLOR_HWHITE, "★"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};//值为1-5代表不同的颜色 11-15代表反显
	CONSOLE_GRAPHICS_INFO popstar_CGI; //声明一个CGI变量
	char temp[256] = " ";
	//9*9和16*16和16*30 适当放大，用18*32
	/*用缺省值初始化（窗口背景黑/前景白，点阵16*8，上下左右无额外行列，上下状态栏均有，无行号/列标，框架线型为双线，色块宽度2/高度1/无小边框，颜色略）*/
	gmw_init(&popstar_CGI);
	//带分割线
	gmw_set_rowcol(&popstar_CGI, line, column);
	gmw_set_frame_style(&popstar_CGI, 6, 3);//色块带分隔线高3宽6
	//还要修改的是游戏区域的颜色、游戏的行列根据输入而定
	//要改为显示行标和列标
	gmw_set_rowno_switch(&popstar_CGI, true);							//显示行号
	gmw_set_colno_switch(&popstar_CGI, true);	
	//主框架为带分割线的版本
	gmw_set_block_border_switch(&popstar_CGI, true);
	//设置有游戏区域为亮白色，色块颜色，不联及；
	gmw_set_frame_color(&popstar_CGI, COLOR_HWHITE, COLOR_BLACK);
	//画框架有延时
	gmw_set_delay(&popstar_CGI, DELAY_OF_DRAW_FRAME, 1);
	gmw_set_status_line_switch(&popstar_CGI, TOP_STATUS_LINE, true);
	gmw_set_status_line_color(&popstar_CGI, TOP_STATUS_LINE, COLOR_BLACK, COLOR_HWHITE, COLOR_BLACK, COLOR_HYELLOW);
	gmw_draw_frame(&popstar_CGI);
	sprintf(temp, "当前屏幕设置为：%d行%d列", popstar_CGI.lines, popstar_CGI.cols);
	gmw_status_line(&popstar_CGI, TOP_STATUS_LINE, temp);
	
	//色块具体颜色调用画色块函数时才改 
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			gmw_draw_block(&popstar_CGI, i, j,star_array[i+1][j+1], bdi_popstar);
		}
	}
	//开始使用键盘鼠标操作
	int loop = 1;
	int maction, mrow = -1, mcol = -1;
	int oldrow = -9, oldcol = -9;
	int keycode1, keycode2;
	int ret;
	int all_score = 0;//总得分
	while (loop) {
		int per_score = 0;//本次得分
		int succenum = 0;//本次消除的色块数量
		gmw_set_status_line_color(&popstar_CGI, TOP_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		if (judge_is_over(line, column, star_array) == 0) {
			//游戏结束
			int left=cal_left_num(line, column, star_array);
			int reward = 0;
			if (left < 10) {
				reward = 180 * (10 - left);
				all_score += reward;
			}
			sprintf(temp, "剩余%d个未消除项，奖励%d分,总得分%d分", left, reward,all_score);
			gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE,"游戏结束，按回车键继续下一关,", temp);
			break;
		}
		ret = gmw_read_keyboard_and_mouse(&popstar_CGI, maction, mrow, mcol, keycode1, keycode2);
		//读到的mrow为显示出的行列，实际数组中的行列都要在再+1
		if (ret == CCT_MOUSE_EVENT) {
			if (maction == MOUSE_ONLY_MOVED) {
				
				//先取消上一个老位置的反显
				if (oldrow != -9) {
					gmw_draw_block(&popstar_CGI, oldrow, oldcol, star_array[oldrow+ 1][oldcol + 1], bdi_popstar);
				}
				//经过合法位置将色块反显；
				gmw_draw_block(&popstar_CGI, mrow, mcol, star_array[mrow + 1][mcol + 1]%100+10, bdi_popstar);
				oldrow = mrow;
				oldcol = mcol;
				
				//移动，状态栏显示；当前位置；
			}
			else if (maction== MOUSE_LEFT_BUTTON_CLICK) {//左键的话需要两次
				{
					//首先判断左键按下的地方能否被消除
					int accept=digui_find(mrow + 1, mcol + 1, star_array, line, column);
					//第一次左键要把所有大于1000的项反显表示
					for (int i = 0; i < line; i++) {
						for (int j = 0; j < column; j++) {

							if (star_array[i + 1][j + 1] > 1000) {
								gmw_draw_block(&popstar_CGI, i, j,star_array[i+1][j+1]%100+10, bdi_popstar);//反显表示
							}
						}
					}
					gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
					gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, "箭头键/鼠标移动取消当前选择，回车键/左键单击合成");
					if (accept == 0) {
						//下状态栏打印不可消除
						gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
						gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE,"箭头键/鼠标移动，回车键/左键单击选择","周围无相同值");
						continue;
					}
					oldrow = mrow;
					oldcol = mcol;//记录第一次鼠标左键时选中的行列位置
					ret = gmw_read_keyboard_and_mouse(&popstar_CGI, maction, mrow, mcol, keycode1, keycode2);
					if (maction == MOUSE_LEFT_BUTTON_CLICK && oldrow == mrow && oldcol == mcol) {
						//连续两次鼠标左键并且在同一个位置进行单击；
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {

								if (star_array[i+1][j+1] > 1000) {
									gmw_draw_block(&popstar_CGI, i, j, 0, bdi_popstar);//已经消去的内部值大于1000
									star_array[i + 1][j + 1] = 0;//消去后将内部数组值置为0
									succenum++;
								}
							}
						}
						//一次单击后进行数组下落操作,使0全部落在最上方
						gmw_downstar(line, column, star_array, &popstar_CGI);
						/*数组下落后，再打印一次*/
						for (int cx = 0; cx < line; cx++) {
							for (int cy = 0; cy < column; cy++) {
								gmw_draw_block( &popstar_CGI, cx, cy, star_array[cx + 1][cy + 1], bdi_popstar);
							}
						}
						Sleep(2);
						per_score = succenum * succenum * 5;
						all_score += per_score;
						sprintf(temp, "本次消除得分%d分，总得分%d分", per_score, all_score);
						gmw_status_line(&popstar_CGI, TOP_STATUS_LINE, temp);
						
					}
					else {
						//优化，第一次如果点击了但是又移开了
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								if (star_array[i + 1][j + 1] > 10) {
									star_array[i + 1][j + 1] %= 10;
								}
							}
						}
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								gmw_draw_block(&popstar_CGI, i, j, star_array[i + 1][j + 1], bdi_popstar);//正常显示
							}
						}
					}
				}
				
			}
		}
		else { //CCT_KEYBOARD_EVENT - 具体键码含义去读 cmd_console_tools.cpp
			//键盘操作
			switch (keycode1) {
				case 13:	//回车键
					//如果位置合法，先反显当前色块
					if(mrow>=0&&mrow<line&&mcol>=0&&mcol<column){
						//首先判断左键按下的地方能否被消除
						int accept = digui_find(mrow + 1, mcol + 1, star_array, line, column);
						//第一次左键要把所有大于1000的项反显表示
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {

								if (star_array[i + 1][j + 1] > 1000) {
									gmw_draw_block(&popstar_CGI, i, j, star_array[i + 1][j + 1] % 100 + 10, bdi_popstar);//反显表示
								}
							}
						}
						gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
						gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, "箭头键/鼠标移动取消当前选择，回车键/左键单击合成");
						if (accept == 0) {
							//下状态栏打印不可消除
							gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
							gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, "箭头键/鼠标移动，回车键/左键单击选择", "周围无相同值");
							continue;
						}
						else {
							//再次回车键进行消除
							oldrow = mrow;
							oldcol = mcol;//记录第一次鼠标左键时选中的行列位置
							ret = gmw_read_keyboard_and_mouse(&popstar_CGI, maction, mrow, mcol, keycode1, keycode2);
							if (keycode1==13 && oldrow == mrow && oldcol == mcol) {
								//连续两次鼠标左键并且在同一个位置进行单击；
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {

										if (star_array[i + 1][j + 1] > 1000) {
											gmw_draw_block(&popstar_CGI, i, j, 0, bdi_popstar);//已经消去的内部值大于1000
											star_array[i + 1][j + 1] = 0;//消去后将内部数组值置为0
											succenum++;
										}
									}
								}
								//一次单击后进行数组下落操作,使0全部落在最上方
								gmw_downstar(line, column, star_array, &popstar_CGI);
								/*数组下落后，再打印一次*/
								for (int cx = 0; cx < line; cx++) {
									for (int cy = 0; cy < column; cy++) {
										gmw_draw_block(&popstar_CGI, cx, cy, star_array[cx + 1][cy + 1], bdi_popstar);
									}
								}
								Sleep(2);
								per_score = succenum * succenum * 5;
								all_score += per_score;
								sprintf(temp, "本次消除得分%d分，总得分%d分", per_score, all_score);
								gmw_status_line(&popstar_CGI, TOP_STATUS_LINE, temp);
								//然后要在点击的位置生成一个新的数字+1的方块，并且其他为0位置用随机值填充
							}
							else {
								//优化，第一次如果点击了但是又移开了
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										if (star_array[i + 1][j + 1] > 10) {
											star_array[i + 1][j + 1] %= 10;
										}
									}
								}
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										gmw_draw_block(&popstar_CGI, i, j, star_array[i + 1][j + 1], bdi_popstar);//正常显示
									}
								}
							}
						}
					
					}
					break;
				case 224://箭头键
					//箭头移开的时候要取消反显
					if (oldrow != -9) {
						gmw_draw_block(&popstar_CGI, oldrow, oldcol, star_array[oldrow + 1][oldcol + 1], bdi_popstar);
					}
					switch (keycode2) {
						case KB_ARROW_UP://上箭头
							if (mrow>0)
								mrow-= 1;
							else
								mrow = line-1;
							//同时下状态栏开始输出
							sprintf(temp, "当前键盘：%d行%d列", mrow,mcol);
							gmw_status_line(&popstar_CGI,LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_DOWN://下箭头
							if (mrow < line-1)
								mrow += 1;
							else
								mrow = 0;
							sprintf(temp, "当前键盘：%d行%d列", mrow, mcol);
							gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_LEFT://左箭头
							if (mcol > 0)
								mcol-= 1;
							else
								mcol = column-1;
							sprintf(temp, "当前键盘：%d行%d列", mrow, mcol);
							gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_RIGHT:
							if (mcol< column-1)
								mcol += 1;
							else
								mcol = 0;
							sprintf(temp, "当前键盘：%d行%d列", mrow, mcol);
							gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, temp);
							break;
					}
					oldrow = mrow;
					oldcol = mcol;
					//然后需要将当前色快反显
					gmw_draw_block(&popstar_CGI, mrow, mcol, star_array[mrow + 1][mcol + 1] % 100 + 10, bdi_popstar);//反显表示
					break;
			}//end of switch*/
		}//end of else
		//本次得分是succenum*succenum*5
		
		
	}//end of while
	return all_score;
}



/*函数名称：gmw_downstar
函数功能：每次完成一次鼠标有效点击后，将内部数组重新排列，使浮在最上面*/
void gmw_downstar(int line, int column, int star_array[][STARMAX], CONSOLE_GRAPHICS_INFO* pCGI)
{
	const BLOCK_DISPLAY_INFO bdi_popstar[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0不显示，用空格填充即可
		{1,  COLOR_BLUE, COLOR_BLACK, "★"},	//1表示有一个雷 背景色与框架相同
		{2, COLOR_RED, COLOR_BLACK, "★"},
		{3,  COLOR_PINK,COLOR_BLACK, "★"},
		{4,  COLOR_CYAN, COLOR_BLACK, "★"},
		{5,  COLOR_HRED, COLOR_BLACK, "★"},
		{10, COLOR_HWHITE, COLOR_HWHITE, "  "},
		{11,  COLOR_BLUE, COLOR_HWHITE, "★"},	//内部值+10表示反显
		{12, COLOR_RED, COLOR_HWHITE, "★"},
		{13,  COLOR_PINK,COLOR_HWHITE, "★"},
		{14,  COLOR_CYAN, COLOR_HWHITE, "★"},
		{15,  COLOR_HRED, COLOR_HWHITE, "★"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};//值为1-5代表不同的颜色 11-15代表反显
	//先检查每一列，从下往上检查、
	for (int i = 1; i <= column; i++) {
		for (int j = line; j > 1; j--) {
			if (star_array[j][i] == 0) {//记录第一个为0的位置
				int successive_num = 0;//定义一个计算连续相同色块的变量
				int l = j;//记录第一个为0的位置
				for (; star_array[l][i] == 0 && l > 1; l--) {
					successive_num++;
				}
				for (; j - successive_num >= 1; j--) {
					star_array[j][i] = star_array[j - successive_num][i];
					//需要打印动画效果；
					/*Sleep(1);
					for (int cx = 0; cx < line; cx++) {
						for (int cy = 0; cy < column; cy++) {
							gmw_draw_block(pCGI, cx, cy, star_array[cx+1][cy+1], bdi_popstar);
						}
					}*/
					
					star_array[j - successive_num][i] = 0;
				}
				if (j == successive_num) {
					for (; j >= 1; j--) {
						star_array[j][i] = 0;
					}
				}
			}
		}
		/*然后再检查这一列的为0个数，必须确保0都在上面*/
		for (int j = line; j > 1; j--) {
			if (star_array[j][i] == 0) {//记录第一个为0的位置
				int successive_num = 0;//定义一个计算连续相同色块的变量
				int l = j;//记录第一个为0的位置
				for (; star_array[l][i] == 0 && l > 1; l--) {
					successive_num++;
				}
				for (; j - successive_num >= 1; j--) {
					star_array[j][i] = star_array[j - successive_num][i];
					star_array[j - successive_num][i] = 0;
				}
				if (j == successive_num) {
					for (; j >= 1; j--) {
						star_array[j][i] = 0;
					}
				}
				Sleep(1);
				for (int cx = 0; cx < line; cx++) {
					for (int cy = 0; cy < column; cy++) {
						gmw_draw_block(pCGI, cx, cy, star_array[cx + 1][cy + 1], bdi_popstar);
					}
				}
			}
		}
	}

	//然后检查是否有一整列为0，如果有，需要将它的右一列左移
	//平移一整列要注意是否有多列同时为0的情况。
	int successive_col = 0;//记录连续的空列的个数
	int first_col = 0;//记录第一列为0的列标
	int whole = 0;//整个数组中为空列的列数
	for (int i = 1; i <= column; i++) {
		if (star_array[line][i] == 0) {
			whole++;
		}
	}
	while (1) {
		int ip;
		for (ip = 1; ip < column; ip++) {//最后一列为0不用平移
			if (star_array[line][ip] == 0) {
				first_col = ip;
				break;
				/*successive_col++;
				if (star_array[line][i + 1] != 0) {
					break;
				}*/
			}
		}/*用于计算是否可能存在多行连续为0的情况*/
		if (ip == column - whole + 1 || ip == column) {
			break;//说明到了最后一行，也没有找到，遍历结束
		}
		if (first_col <= column) {
			for (int i = first_col; i < column; i++) {
				if (star_array[line][i] == 0) {
					successive_col++;
					if (star_array[line][i + 1] != 0) {
						break;
					}
				}
			}
		}
		if (successive_col >= 1 && first_col <= column) {
			int move = column - (first_col + successive_col) + 1;
			for (int a = 0; a < move; a++) {
				for (int b = 1; b <= line; b++) {
					star_array[b][first_col + a] = star_array[b][first_col + successive_col + a];
				}
			}
		}/*连续多行*/
		/*如果不存在连续多行*/

	}
	//最后根据whole的个数而将数组右边部分置为0；
	for (int a = 0; whole > 0; a++) {
		for (int b = 1; b <= line; b++) {
			star_array[b][column - a] = 0;
		}
		whole--;
	}
}
/****************************************************************************
函数名称：cal_left_num
函数参数：
函数功能：计算剩余多少个星星，奖励多少分数
函数返回值：
****************************************************************************/
int cal_left_num(int line, int column, int array[][STARMAX])
{
	int num_left = 0;
	for (int i = 1; i <= line; i++) {
		//还要给出奖励分
		for (int j = 1; j <= column; j++) {
			if (array[i][j] != 0) {
				num_left++;
			}
		}
	}
	return num_left;
	//下状态栏要打印剩余多少星星
}
void pause_enter(const char* prompt)
{
	//cout << "按回车键进行数组下落操作...";
	if (prompt != NULL)
		cout << prompt;
	while (_getch() != '\r')
		;
	return;
}