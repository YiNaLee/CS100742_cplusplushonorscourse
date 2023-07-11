/*2052316 信07 李祎娜*/
#define _CRT_SECURE_NO_WARNINGS
/* -----------------------------------------
	 本文件功能：
	1、放消灭星星用gmw函数集完成的无分割线版本
	2、此文件中的函数为私有函数，供main调用
	3.注：由于时间限制，本程序仅真正实现了消灭星星完整版
   ----------------------------------------- */
  

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h" 
#include"../include/cmd_gmw_tools.h"
#include "90-02-b2-merge_ten.h"
#include"../include/basic_public.h"
   /**************************************************************************
	 函数名称：get_line_column
	 函数参数 两个指针变量
	 函数功能 获得改变行和列的值
	 函数返回值 无
	 *****************************************************************************/
void get_line_column(int* line, int* column,int*target)
{
	while (1) {
		cct_gotoxy(0, 0);
		cout << "请输入行数（5-8）：";
		cin >> *line;
		if (!cin.good() || *line < 5 || *line>8) {
			cct_gotoxy(0, 1);
			cout << "输入不合法，请重新输入";
			cct_gotoxy(19, 0);
			cout << "                                                       ";
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (*line >= 5 && *line <= 8) {
			cct_gotoxy(0, 1);
			cout << "                                   ";
			cct_gotoxy(0, 1);
			cout << "请输入列数（5-10）：";
			while (1) {//检测列输入是否正确
				cct_gotoxy(20, 1);
				cin >> *column;
				if (!cin.good() || *column < 5 || *column>10) {
					cct_gotoxy(0, 2);
					cout << "输入不合法，请重新输入";
					cct_gotoxy(20, 1);
					cout << "                                                ";
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				else if (*column >= 5 && *column <= 10)
					break;
			}
			

			cct_gotoxy(0, 2);
			cout << setw(30) << " ";
			cct_gotoxy(0, 2);
			cout << "请输入合成目标（5-20）：";
			while (1) {
				cct_gotoxy(24, 2);
				cin >> *target;
				if (!cin.good() || *target < 5 || *target>20) {
					cct_gotoxy(0, 3);
					cout << "输入不合法，请重新输入";
					cct_gotoxy(24, 2);
					cout << "                                                ";
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				else if (*target >= 5 && *target <= 20)
					break;
			}
			break;
		}
	}
}
/********************************************************************
函数名称：star_array_setup(...)
函数参数：
函数功能：根据输入的行列值生成颜色概率相等的合成10数组内部值的初始化
函数返回值：初始化只有1-3这三个内部值
其他说明：

*********************************************************************/
void merge_array_setup(int line, int column, int star_array[][MERGE_MAX_SCALE])
{
	/*初始需要随机产生1-3等概率的数字，每次不相同*/
	srand((unsigned int)(time(0)));//生成随机数的种子
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			star_array[i][j] = rand() % 3 + 1;
		}
	}

}
/********************************************************************
函数名称：full_version_gmw_merge_ten()
函数参数：
函数功能：绘制初始合成十的图形
函数返回值：
其他说明：调用gmw函数集，

*********************************************************************/
void full_version_gmw_merge_ten(int line,int column,int array[][MERGE_MAX_SCALE],int target)
{
	//定义一个存放消灭星星色块颜色的结构体数组。
	const BLOCK_DISPLAY_INFO bdi_merge_ten[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0不显示，用空格填充即可
		{1,  COLOR_BLUE, COLOR_BLACK, "1"},	
		{2, COLOR_GREEN, COLOR_BLACK, "2"},
		{3,  COLOR_CYAN,COLOR_BLACK, "3"},
		{4,  COLOR_RED, COLOR_BLACK, "4"},
		{5,  COLOR_PINK, COLOR_BLACK, "5"},
		 {6,  COLOR_YELLOW, COLOR_BLACK, "6"},
		 {7,  COLOR_HBLUE, COLOR_BLACK, "7"},
		 {8,  COLOR_HGREEN, COLOR_BLACK, "8"},
		 {9,  COLOR_HCYAN, COLOR_BLACK, "9"},
		 {10,  COLOR_HRED, COLOR_BLACK, "10"},
		 {11,  COLOR_HPINK, COLOR_BLACK, "11"},
		 {12,  COLOR_HYELLOW, COLOR_BLACK, "12"},
		 {13,  COLOR_BLUE, COLOR_BLACK, "13"},	
		{14, COLOR_GREEN, COLOR_BLACK, "14"},
		{15,  COLOR_CYAN,COLOR_BLACK, "15"},
		{16,  COLOR_RED, COLOR_BLACK, "16"},
		{17,  COLOR_PINK, COLOR_BLACK, "17"},
		 {18,  COLOR_YELLOW, COLOR_BLACK, "18"},
		 {19,  COLOR_HBLUE, COLOR_BLACK, "19"},
		{20, COLOR_RED, COLOR_HWHITE, "20"},
		{101,  COLOR_BLUE,COLOR_HWHITE, "1"},//内部值+100表示反显
		{102, COLOR_GREEN, COLOR_HWHITE, "2"},
		{103,  COLOR_CYAN,COLOR_HWHITE, "3"},
		{104,  COLOR_RED, COLOR_HWHITE, "4"},
		{105,  COLOR_PINK, COLOR_HWHITE, "5"},
		 {106,  COLOR_YELLOW, COLOR_HWHITE, "6"},
		 {107,  COLOR_HBLUE, COLOR_HWHITE, "7"},
		 {108,  COLOR_HGREEN, COLOR_HWHITE, "8"},
		 {109,  COLOR_HCYAN, COLOR_HWHITE, "9"},
		 {110,  COLOR_HRED, COLOR_HWHITE, "10"},
		 {111,  COLOR_HPINK, COLOR_HWHITE, "11"},
		 {112,  COLOR_HYELLOW, COLOR_HWHITE, "12"},
		 {113,  COLOR_BLUE, COLOR_HWHITE, "13"},	//1表示有一个雷 背景色与框架相同
		{114, COLOR_GREEN, COLOR_HWHITE, "14"},
		{115,  COLOR_CYAN,COLOR_HWHITE, "15"},
		{116,  COLOR_RED, COLOR_HWHITE, "16"},
		{117,  COLOR_PINK, COLOR_HWHITE, "17"},
		 {118,  COLOR_YELLOW, COLOR_HWHITE, "18"},
		 {119,  COLOR_HBLUE, COLOR_HWHITE, "19"},
		{120, COLOR_RED, COLOR_HWHITE, "20"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};//值为1-5代表不同的颜色 11-15代表反显
	CONSOLE_GRAPHICS_INFO merge_CGI; //声明一个CGI变量
	char temp[256] = " ";
	gmw_init(&merge_CGI);
	//框全部都变成了单线；色块的小边框也变成了单线；
	gmw_set_frame_default_linetype(&merge_CGI, 2);
	gmw_set_block_default_linetype(&merge_CGI, 2);
	gmw_set_rowcol(&merge_CGI, line, column);
	gmw_set_frame_style(&merge_CGI, 6, 3);//色块带分隔线高3宽6
	//还要修改的是游戏区域的颜色、游戏的行列根据输入而定
	//要改为显示行标和列标
	gmw_set_rowno_switch(&merge_CGI, true);							//显示行号
	gmw_set_colno_switch(&merge_CGI, true);
	//主框架为带分割线的版本
	gmw_set_block_border_switch(&merge_CGI, true);
	//设置有游戏区域为亮白色，色块颜色，不联及；
	gmw_set_frame_color(&merge_CGI, COLOR_HWHITE, COLOR_BLACK);
	//画框架有延时
	gmw_set_delay(&merge_CGI, DELAY_OF_DRAW_FRAME, 1);
	gmw_set_status_line_switch(&merge_CGI, TOP_STATUS_LINE, true);
	gmw_set_status_line_color(&merge_CGI, TOP_STATUS_LINE, COLOR_BLACK, COLOR_HWHITE, COLOR_BLACK, COLOR_HYELLOW);
	gmw_draw_frame(&merge_CGI);
	sprintf(temp, "当前屏幕设置为：%d行%d列", merge_CGI.lines, merge_CGI.cols);
	gmw_status_line(&merge_CGI, TOP_STATUS_LINE, temp);
	//色块具体颜色调用画色块函数时才改 
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1], bdi_merge_ten);
		}
	}
	//开始使用鼠标键盘操作
	//开始使用键盘鼠标操作
	int loop = 1;
	int maction, mrow = -1, mcol = -1;
	int oldrow = -9, oldcol = -9;
	int regline = 0, regcol = 0;
	int keycode1, keycode2;
	int ret;
	int all_score = 0;//总得分
	int record_inner = 0;
	int tempmax = 0;
	
	while (loop) {
		gmw_set_status_line_color(&merge_CGI, TOP_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		//首先判断游戏是否结束了，如果结束，下状态栏输出结束信息；
		if (judge_is_over(line, column, array) == 0) {
			
			gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "按Q退出                              ","无可合并的项,游戏结束!");
			while (1) {
				int x = getchar();
				if (x == 'Q' || x == 'q')
					break;
			}
			break;
		}
		int per_score = 0;//本次得分
		int succenum = 0;//本次消除的色块数量
		gmw_set_status_line_color(&merge_CGI, TOP_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		//游戏是不会结束的，要每次消除之后重新补充新的数，完成一个目标后确定是否进行下一次合成
		ret = gmw_read_keyboard_and_mouse(&merge_CGI, maction, mrow, mcol, keycode1, keycode2);
		//读到的mrow为显示出的行列，实际数组中的行列都要在再+1
		if (ret == CCT_MOUSE_EVENT) {
			if (maction == MOUSE_ONLY_MOVED) {

				//先取消上一个老位置的反显
				if (oldrow != -9) {
					gmw_draw_block(&merge_CGI, oldrow, oldcol,array[oldrow + 1][oldcol + 1], bdi_merge_ten);
				}
				//经过合法位置将色块反显；
				gmw_draw_block(&merge_CGI, mrow, mcol, array[mrow + 1][mcol + 1] % 50 + 100, bdi_merge_ten);
				oldrow = mrow;
				oldcol = mcol;

				//移动，状态栏显示；当前位置；
			}
			else if (maction == MOUSE_LEFT_BUTTON_CLICK) {//左键的话需要两次
				{
					//首先判断左键按下的地方能否被消除
					int accept = digui_find(mrow + 1, mcol + 1, array, line, column);
					//第一次左键要把所有大于1000的项反显表示
					for (int i = 0; i < line; i++) {
						for (int j = 0; j < column; j++) {

							if (array[i + 1][j + 1] > 1000) {
								gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] % 100 + 100, bdi_merge_ten);//反显表示
							}
						}
					}
					gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
					gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "箭头键/鼠标移动取消当前选择，回车键/左键单击合成");
					if (accept == 0) {
						//下状态栏打印不可消除
						gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
						gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "箭头键/鼠标移动，回车键/左键单击选择", "周围无相同值");
						continue;
					}
					oldrow = mrow;
					oldcol = mcol;//记录第一次鼠标左键时选中的行列位置
					ret = gmw_read_keyboard_and_mouse(&merge_CGI, maction, mrow, mcol, keycode1, keycode2);
					if (maction == MOUSE_LEFT_BUTTON_CLICK && oldrow == mrow && oldcol == mcol) {
						//连续两次鼠标左键并且在同一个位置进行单击；
						array[mrow+1][mcol+1]=array[mrow+1][mcol+1]%100+1;//先把原来位置变成+1
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								//先消去，下落之后再填满
								if (array[i + 1][j + 1] > 1000) {
									gmw_draw_block(&merge_CGI, i, j, 0, bdi_merge_ten);//已经消去的内部值大于1000
									record_inner = array[i + 1][j + 1] % 100;
									array[i + 1][j + 1] = 0;//消去后将内部数组值置为0
									regline = mrow + 1;//标记点击的位子
									regcol = mcol + 1;
									succenum++;
								}
							}
						}
						gmw_draw_block(&merge_CGI, mrow, mcol, array[mrow+1][mcol+1], bdi_merge_ten);
						Sleep(300);//动画延时方便看出
						//一次单击后进行数组下落操作,使0全部落在最上方
						gmw_public_downstar(line, column, array);
						/*数组下落后，再打印一次*/
						for (int cx = 0; cx < line; cx++) {
							for (int cy = 0; cy < column; cy++) {
								gmw_draw_block(&merge_CGI, cx, cy,array[cx + 1][cy + 1], bdi_merge_ten);
							}
						}
						per_score = succenum*record_inner*3;
						all_score += per_score;
						sprintf(temp, "本次得分：%d ，总分%d ,合成目标:%d        ", per_score, all_score, target);
						gmw_status_line(&merge_CGI, TOP_STATUS_LINE, temp);
						//然后再在regline 和regcol的位置上生成一个record_inner +1的色块
						srand((unsigned int)(time(0)));//生成随机数的种子,生成的随机数不可以比现在原有的值大
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								if (array[i + 1][j + 1]>tempmax) {
									tempmax=array[i+1][j+1];
								}
							}
						}
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								if (array[i + 1][j + 1] == 0) {
									array[i + 1][j + 1] = rand() % (tempmax-1) + 1;
								}
							}
						}
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] % 100, bdi_merge_ten);//再显示一遍
							}
						}
					}
					else {
						//鼠标左击一次但是又移开了
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								if (array[i + 1][j + 1] > 100) {
									array[i + 1][j + 1] %= 20;
								}
							}
						}
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] , bdi_merge_ten);//正常显示
							}
						}
					}
				}

			}
		}
		else { //CCT_KEYBOARD_EVENT - 具体键码含义去读 cmd_console_tools.cpp
			//键盘操作
			//初始就用键盘操作
			if (oldrow == -9) {
				mrow = 1;
				mcol = 1;
				oldrow = 1;
				oldcol = 1;
			}
			switch (keycode1) {
				case 13:	//回车键
					//如果位置合法，先反显当前色块
					if (mrow >= 0 && mrow < line && mcol >= 0 && mcol < column) {
						//首先判断左键按下的地方能否被消除
						int accept = digui_find(mrow + 1, mcol + 1, array, line, column);
						//第一次左键要把所有大于1000的项反显表示
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {

								if (array[i + 1][j + 1] > 1000) {
									gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] % 100 + 100, bdi_merge_ten);//反显表示
								}
							}
						}
						gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
						gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "箭头键/鼠标移动取消当前选择，回车键/左键单击合成");
						if (accept == 0) {
							//下状态栏打印不可消除
							gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "箭头键/鼠标移动，回车键/左键单击选择", "周围无相同值");
							continue;
						}
						else {
							//再次回车键进行消除
							oldrow = mrow;
							oldcol = mcol;//记录第一次鼠标左键时选中的行列位置
							ret = gmw_read_keyboard_and_mouse(&merge_CGI, maction, mrow, mcol, keycode1, keycode2);
							if (keycode1 == 13 && oldrow == mrow && oldcol == mcol) {
								//连续两次鼠标左键并且在同一个位置进行单击；
								array[mrow + 1][mcol + 1] = array[mrow + 1][mcol + 1] % 100 + 1;//先把原来位置变成+1
								gmw_draw_block(&merge_CGI, mrow, mcol, array[mrow + 1][mcol + 1], bdi_merge_ten);
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {

										if (array[i + 1][j + 1] > 1000) {
											gmw_draw_block(&merge_CGI, i, j, 0, bdi_merge_ten);//已经消去的内部值大于1000
											record_inner = array[i + 1][j + 1] % 100;
											regline = mrow + 1;//标记点击的位子
											regcol = mcol+ 1;
											array[i + 1][j + 1] = 0;//消去后将内部数组值置为0
											succenum++;
										}
									}
								}
								Sleep(300);//动画延时方便看出
								//一次单击后进行数组下落操作,使0全部落在最上方
								gmw_public_downstar(line, column, array);
								/*数组下落后，再打印一次*/
								for (int cx = 0; cx < line; cx++) {
									for (int cy = 0; cy < column; cy++) {
										gmw_draw_block(&merge_CGI, cx, cy, array[cx + 1][cy + 1], bdi_merge_ten);
									}
								}
								Sleep(2);
								per_score = succenum * record_inner * 3;
								all_score += per_score;
								sprintf(temp, "本次得分：%d ，总分%d ,合成目标:%d          ", per_score, all_score,target);
								gmw_status_line(&merge_CGI, TOP_STATUS_LINE, temp);
								//然后再在regline 和regcol的位置上生成一个record_inner +1的色块
								srand((unsigned int)(time(0)));//生成随机数的种子,生成的随机数不可以比现在原有的值大
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										if (array[i + 1][j + 1] > tempmax) {
											tempmax = array[i + 1][j + 1];
										}
									}
								}
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										if (array[i + 1][j + 1] == 0) {
											array[i + 1][j + 1] = rand() % (tempmax - 1) + 1;
										}
									}
								}
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] % 100, bdi_merge_ten);//再显示一遍
									}
								}
							}
							else {
								//回车一次但是又移开了
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										if (array[i + 1][j + 1] > 100) {
											array[i + 1][j + 1] %= 20;//恢复原状
										}
									}
								}
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1], bdi_merge_ten);//正常显示
									}
								}
							}
						}

					}
				case 224://箭头键
					//箭头移开的时候要取消反显
					if (oldrow != -9) {
						gmw_draw_block(&merge_CGI, oldrow, oldcol, array[oldrow + 1][oldcol + 1], bdi_merge_ten);
					}
					switch (keycode2) {
						case KB_ARROW_UP://上箭头
							if (mrow > 0)
								mrow -= 1;
							else
								mrow = line - 1;
							//同时下状态栏开始输出
							sprintf(temp, "当前键盘：%d行%d列", mrow, mcol);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_DOWN://下箭头
							if (mrow < line - 1)
								mrow += 1;
							else
								mrow = 0;
							sprintf(temp, "当前键盘：%d行%d列", mrow, mcol);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_LEFT://左箭头
							if (mcol > 0)
								mcol -= 1;
							else
								mcol = column - 1;
							sprintf(temp, "当前键盘：%d行%d列", mrow, mcol);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_RIGHT:
							if (mcol < column - 1)
								mcol += 1;
							else
								mcol = 0;
							sprintf(temp, "当前键盘：%d行%d列", mrow, mcol);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, temp);
							break;
					}
					oldrow = mrow;
					oldcol = mcol;
					//然后需要将当前色快反显
					gmw_draw_block(&merge_CGI, mrow, mcol, array[mrow + 1][mcol + 1] % 100 + 100, bdi_merge_ten);//反显表示
					break;
			}//end of switch*/
		}//end of else
		//遍历数组看看是否合成了目标；
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				if (array[i + 1][j + 1] ==target) {
					
					sprintf(temp, "已经合成到%d", target);
					gmw_status_line(&merge_CGI, LOWER_STATUS_LINE,"按回车键/单击左键继续向更高目标进发", temp);
					target++;//目标加一,已经合成了当前的目标；
					while (1) {
						int X,Y;
						ret = cct_read_keyboard_and_mouse(X,Y,maction,keycode1,keycode2);
						if (maction == MOUSE_LEFT_BUTTON_CLICK || keycode1 == 13) {
							break;
						}
					}

				}
			}
		}
	
	}//end of while
	
	
}