/*2052316 信07 李祎娜*/
/*本文件为90-02-b1的私有文件，存放仅与消灭星星有关的私有函数*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h" 
#include "90-02-b1-pop_star.h"
#include"../include/basic_public.h"

using namespace std;
/****************************************************************************
函数名称：
函数参数：
函数功能：无分割线的情况下选择（菜单项D）
函数返回值：
****************************************************************************/


/****************************************************************************
函数名称：
函数参数：
函数功能：上下两个状态栏的内容显示函数
函数返回值：
****************************************************************************/



/****************************************************************************
函数名称：
函数参数：
函数功能：cmd窗口大小随着行列值大小而变化
函数返回值：
****************************************************************************/
void change_cmd(int line, int column,int dtrow,int dtcol,int*hang,int*lie, int  BASELINE, int BASECOLUMN)
{
	*hang = (line - MIN_SCALE) * dtrow + BASELINE;
	*lie = (column - MIN_SCALE) * dtcol + BASECOLUMN;

	cct_setconsoleborder(*lie, *hang);//根据数组大小而确定窗口大小
	//cout << "当前屏幕设置为" << *hang << "行" << *lie<< "列";

}
/****************************************************************************
函数名称：
函数参数：width此处按照题目要求要传6和3
函数功能：打印标尺 
函数返回值：
****************************************************************************/
void draw_ruler(int line,int column,int width1,int width2)
{
	cct_gotoxy(1, 1);
	for (int i = 0; i < column; i++) {
		cout << setw(width1) << i;
	}
	for (int i = 0; i < line; i++) {
		cct_gotoxy(0, 4+i*width2);
		putchar(i + 'A');
	}


}
/****************************************************************************
函数名称：
函数参数：
函数功能：画一个星星，反显==1画反显，否则普通
函数返回值：★
****************************************************************************/
void draw_a_star(int random_color,int x,int y,int fanxian)
{
	if (random_color > 100) {
		random_color %= 100;
	}
	cct_gotoxy(x, y);//左上角坐标
	if (fanxian == 1) {
		cct_setcolor(random_color, COLOR_HWHITE);
	}
	else
	    cct_setcolor(random_color, COLOR_BLACK);
	if (random_color == 0) {
		cct_setcolor(7, 7);//打印空白
	}
	cout << "╔═╗";
	cct_gotoxy(x, y + 1);
	cout << "║★║";
	cct_gotoxy(x, y + 2);
	cout << "╚═╝";

}
/****************************************************************************
函数名称：
函数参数：
函数功能：画图，打印色块；构建初始的伪图形化界面
函数返回值：★
****************************************************************************/
void draw_graph(int line, int column, int array[][STAR_MAX],int canshu)
{
	int x=0, y=0;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			if (canshu == 0) {
				y = 3 + (i - 1) * 3;
				x = 4 + (j - 1) * 6;
			}
			else {
				y = 3 + (i - 1) * 4;
				x = 4 + (j - 1) * 8;
			}
			
			draw_a_star(array[i][j], x, y,0);
		}
	}
	
}
void print_perline(int line,int column,int scale,int X,int Y,int choice,const int bcolor,const int fcolor)
{
	cct_gotoxy(X, Y);
	cct_setcolor(bcolor, fcolor);
	switch (choice) {
		case(1)://打印第一排
			cout << "╔";
			for (int k = 0; k < column-1; k++) {
				for (int i = 0; i < (scale-2)/2; i++) {
					cout << "═";
				}
				cout << "╦";
			}
			for (int i = 0; i < (scale - 2) / 2; i++) {
				cout << "═";
			}
			cout << "╗";
			break;
		case(2)://打印中间竖线排
			for (int k = 0; k < column; k++) {
				cout << "║";
				for (int i = 0; i < (scale - 2) / 2; i++) {
					cout << setw(2) << " ";
				}
			}
			cout<< "║";
			break;
		case(3)://打印中间有十字排
			cout << "╠";
			for (int k = 0; k < column - 1; k++) {
				for (int i = 0; i < (scale - 2) / 2; i++) {
					cout << "═";
				}
				cout << "╬";
			}
			for (int i = 0; i < (scale - 2) / 2; i++) {
				cout << "═";
			}
			cout << "╣";
			break;
		case(4)://打印最后一排
			cout << "╚";
			for (int k = 0; k < column - 1; k++) {
				for (int i = 0; i < (scale - 2) / 2; i++) {
					cout << "═";
				}
				cout << "╩";
			}
			for (int i = 0; i < (scale - 2) / 2; i++) {
				cout << "═";
			}
			cout << "╝";
			break;

	}

}
/*画中间有横线的边框*/
/****************************************************************************
函数名称:draw_complex_frame
函数参数：XY，代表边框的起始位置
         row和column代表数组的大小
		  scale代表画的小边框的边长大小
函数功能：画一个中间有横线的边框
函数返回值：
****************************************************************************/

void draw_complex_frame(int row, int column, int X, int Y, int scale)
{
	cct_gotoxy(X, Y);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	print_perline(row, column, scale, X, Y, 1, COLOR_HWHITE, COLOR_BLACK);
	Y++;
	for (int j = 0; j < row - 1; j++) {
		for (int i = 0; i < (scale - 2) / 2; i++) {
			cct_gotoxy(X, Y);
			print_perline(row, column, scale, X, Y, 2, COLOR_HWHITE, COLOR_BLACK);
			Y++;
		}
		cct_gotoxy(X, Y);
		print_perline(row, column, scale, X, Y, 3, COLOR_HWHITE, COLOR_BLACK);
		Y++;
	}
	for (int i = 0; i < (scale - 2) / 2; i++) {
		cct_gotoxy(X, Y);
		print_perline(row, column, scale, X, Y, 2, COLOR_HWHITE, COLOR_BLACK);
		Y++;
	}
	cct_gotoxy(X, Y);
	print_perline(row, column, scale, X, Y, 4, COLOR_HWHITE, COLOR_BLACK);
	

}
/****************************************************************************
函数名称：graph_choice_noline()
函数参数：
函数功能：d选项的封装操作
函数返回值：
****************************************************************************/
void graph_choice_noline(int line,int column,int array[][STAR_MAX],int choose_line,int choose_column)
{
	int hang = 0, lie = 0;//表示屏幕行列大小
	int test_line=-1, test_column=-1;
	change_cmd(line, column, DTROW, DTCOL,&hang,&lie,BASE_LINE, BASE_COLUMN);
	status_bar_up(hang, lie, 0, 0);
	draw_ruler(line, column, DTCOL, DTROW);
	draw_frame(3 * column, 3 * line, 2, 2);
	draw_graph(line, column, array,0);
	mouse_and_keyboard(&test_line, &test_column, line,column,array,0,4,3,3,6,0,0);
	/*恢复初始屏幕大小*/
	cct_setcolor();
	
}
/****************************************************************************
函数名称：
函数参数：
函数功能：e选项的封装操作,和d的唯一不同是有中间的框
函数返回值：
****************************************************************************/
void graph_choice_line(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column)
{
	int hang = 0, lie = 0;//表示屏幕行列大小
	int test_line = -1, test_column =-1;
	/*字体变小*/
	change_cmd(line, column, DT2ROW, DT2COL, &hang, &lie, BASE2_LINE, BASE2_COLUMN);
	status_bar_up(hang, lie, 0, 0);
	draw_ruler(line, column, DT2COL, DT2ROW);
	draw_complex_frame(line, column, 2, 2, 8);
	draw_graph(line, column, array,1 );
	mouse_and_keyboard(&test_line, &test_column, line, column, array, 1,4,3,4,8,0,0);
	cct_setcolor();

}
/****************************************************************************
函数名称：graph_a_pop
函数参数：
函数功能：伪图形界面下完成一次消除 对应菜单项F
函数返回值：
****************************************************************************/
void graph_a_pop(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column)
{
	int hang = 0, lie = 0;//表示屏幕行列大小
	int test_line = -1, test_column = -1;
	int keycoded = 0;
	change_cmd(line, column, DTROW, DTCOL, &hang, &lie, BASE_LINE, BASE_COLUMN);
	status_bar_up(hang, lie, 0, 0);
	draw_ruler(line, column, DTCOL, DTROW);
	draw_frame(3 * column, 3 * line, 2, 2);
	draw_graph(line, column, array, 0);
	if (mouse_and_keyboard(&test_line, &test_column, line, column, array, 0, 4, 3, 3, 6, 1,1) == 1) {
		//返回1，说明有地方要被消除；
		print_blank(line,column, array, test_line, test_column);
		click_and_enter(&keycoded, 0);

	}
	
	int score=graph_down_array(line, column, array);
	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "本次得分:" << score <<"  "<< "总得分:" << score;
	
	/*本次合成结束，单击左键或者c再一次合成*/
	cct_gotoxy(0, 3 + 3 * line + 1);
	cout << "本次合成结束，按C/单击左键继续新一次的合成\n";
	click_and_enter(&keycoded, 2);
	/*再要读键盘和鼠标的左键与回车操作*/
}
/****************************************************************************
函数名称：final_pop_star()
函数参数：
函数功能：消灭星星游戏最终版，对应菜单项G
函数返回值：
****************************************************************************/
void final_pop_star(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column)
{
	int full_score = 0;
	int hang = 0, lie = 0;//表示屏幕行列大小
	int test_line = -1, test_column = -1;
	int keycoded = 0;
	change_cmd(line, column, DTROW, DTCOL, &hang, &lie, BASE_LINE, BASE_COLUMN);
	status_bar_up(hang, lie, 0, 0);
	draw_ruler(line, column, DTCOL, DTROW);
	draw_frame(3 * column, 3 * line, 2, 2);
	draw_graph(line, column, array, 0);
	while (1) {
		//继续下一关后数组要重新随机生成
		star_array_setup(line, column, array);
		draw_graph(line, column, array, 0);
		while (judge_is_over(line, column, array)) {
			//返回1，说明有地方要被消除；并且游戏未结束
			mouse_and_keyboard(&test_line, &test_column, line, column, array, 0, 4, 3, 3, 6, 1, 1);
			print_blank(line, column, array, test_line, test_column);//打印空白
			int perscore = graph_down_array(line, column, array);//一次合成结束
			full_score += perscore;
			cct_setcolor();
			cct_gotoxy(0, 0);
			cout << "本次得分：" << perscore <<"分，"<< "总分：" << full_score<<"分        ";
			cout << endl;//还要输出当前的分数信息
		}
		int lef = cul_lef(line, column, array);
		int reward_mark = 0;
		if (lef < 10) {
			reward_mark = (10 - lef) * 180;
		}
		full_score += reward_mark;
		cct_gotoxy(0, 0);
		cout << "奖励得分：" << reward_mark << "分,总分" << full_score<<"分            ";
		while (_getch() != '\r')
			continue;
	}
	
}
/****************************************************************************
函数名称：
函数参数：
函数功能：计算剩余的个数，并且决定是否加分
函数返回值：
****************************************************************************/
int cul_lef(int line, int column, int array[][STAR_MAX] )
{
	int num = 0;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			if (array[i][j] != 0) {
				num ++ ;
			}
		}
	}
	cct_gotoxy(0, 3 + 3 * line + 1);
	cct_setcolor(COLOR_HWHITE, COLOR_YELLOW);
	cout << "剩余" << num << "个星星，无可消除项，本关结束！回车继续下一关";
	cct_setcolor();
	return num;
}
/****************************************************************************
函数名称：
函数参数：
函数功能：/*只读取单击和回车操作
函数返回值：
****************************************************************************/

void click_and_enter(int*keycode1_,int canshu)
{
	int biaoji = 1;
	while (biaoji) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		int XX, YY, maction_,keycode2_;
		int ret = cct_read_keyboard_and_mouse(XX, YY, maction_, *keycode1_, keycode2_);

		if (ret == CCT_MOUSE_EVENT) {
			switch (maction_) {
				case MOUSE_LEFT_BUTTON_CLICK:
					biaoji = 0;//按下左键
					break;
				default:
					break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
		else if (ret == CCT_KEYBOARD_EVENT) {

			switch (*keycode1_) {
				case 13:	//回车键
					if(canshu==0)
					    biaoji = 0;
					break;
				case 99://c的asc码
				case 67:
					if (canshu == 2) {
						biaoji = 0;
					}
					break;
				default:
					break;
			}
		}//end of else if(ret == CCT_KEYBOARD_EVENT）
	} //end of while(1)
}


/****************************************************************************
函数名称：mouce_and_keyboard()
函数参数：canshu==0中间无横线，参数是1，中间有横线
函数功能:光标和键盘的一些操作。
其中judge_is_eliminated设置为0代表DE选项的不用判断是否可以消除
                       设置为1代表FG选项的单击和回车需要判断能否消除
					   special_deal对于DE选项而言都是0，对于F选项才是1
****************************************************************************/
int mouse_and_keyboard(int* test_line, int* test_column,int line, int column,int array[STAR_MAX][STAR_MAX],int canshu,int startx,int starty,
	int disli,int discol,int judge_is_eliminated,int special_deal)
{
	int X = 0, Y = 0;//读取的鼠标的坐标
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int fanxian = 0;
	int pre_row=0, pre_col = 0;
	cct_enable_mouse();//允许鼠标操作
	while (loop) {
		cct_setcursor(CURSOR_INVISIBLE);//关闭光标
		if (special_deal) {
			draw_graph(line, column, array, 0);
			if(*test_line>=1)
			    draw_a_star(array[*test_line][*test_column], startx + discol * (*test_column - 1), starty + disli * (*test_line - 1), 1);
			
		}
			
		cct_enable_mouse();//允许鼠标操作
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		/*X.Y可以获取当前鼠标的坐标*/
		if (ret == CCT_MOUSE_EVENT) {//鼠标事件，需要判断位置是否合法并转到某行打印
			switch (maction) {
				case MOUSE_ONLY_MOVED://移动，要判断位置 如果是合法位置需要反显并打印位置，位置非法则提示
					pre_row = *test_line;
					pre_col = *test_column;
					if (canshu == 0) {//中间无横线
						fanxian = legal_XY(X, Y, line, column, starty, startx, disli, discol, test_line, test_column,0,array);
					}
					else {
						fanxian = legal_XY(X, Y, line, column, starty, startx, disli, discol, test_line, test_column,1,array);
					}
					
					if (fanxian == 1) {//鼠标经过合法位置，需要反显
						if (pre_row != -1) {
							if (!(pre_row == *test_line&&pre_col == *test_column)) {
								//证明上一次的位置和这次不同，需要先取消老反显
								draw_a_star(array[pre_row][pre_col], startx + discol * (pre_col - 1), starty + disli* (pre_row - 1), 0);
							}
						}
						draw_a_star(array[*test_line][*test_column], startx + discol * (*test_column - 1), starty + disli * (*test_line - 1), 1);
					}/*如果鼠标移开，要取消反显*/
					/*如果移开了，位置非法，也需要取消反显*/
					else {
						if (pre_row != -1) {
							draw_a_star(array[pre_row][pre_col], startx + discol * (pre_col - 1), starty + disli * (pre_row - 1), 0);
						}
					}
				
					break;
				case MOUSE_LEFT_BUTTON_CLICK://单击左键表示选择
					if (fanxian == 1&& judge_is_eliminated==0) {
						cct_setcolor();
						cct_gotoxy(0, starty + disli * line + 1);
						cout << "选中了";
						putchar('A' + *test_line - 1);
						cout << "行" << *test_column - 1 << "列           \n";
						loop = 0;
					}
					else if(judge_is_eliminated == 1){//需要判断选中的这行这列是否可以消除
						if (digui_find(*test_line, *test_column, array, line, column) == 0) {
							cct_setcolor(0,COLOR_HYELLOW);
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "周围无相同值,";
							cct_setcolor();
							cout << "箭头键/鼠标移动，回车键/单击左键选择";
							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);//再读一遍鼠标操作，但是无反应；
							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);//再读一遍鼠标操作，但是无反应
							cct_gotoxy(0, starty + disli * line + 1);
							cout << setw(50) << " ";
							
						}
						else if (digui_find(*test_line, *test_column, array, line, column)) {
							cct_gotoxy(0, starty + disli * line + 1);
							cct_setcolor();
							cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";
							highlight_all_linked_stars(line, column, array);//反显所有可以被消除的；
							int flag = 1;
							while (flag) {
								ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
								ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
								pre_row = *test_line;
								pre_col = *test_column;
								switch (maction) {//再判断一次是否选择
									case MOUSE_LEFT_BUTTON_CLICK://单击左键表示选择)
										return 1;
										break;
									case MOUSE_ONLY_MOVED:
										fanxian = legal_XY(X, Y, line, column, starty, startx, disli, discol, test_line, test_column, 0,array);

										break;
									default:
										break;
								}
								switch (keycode1) {
									case 13:
										return 1;
										break;
									case 224://读取箭头键
										flag = 0;
										break;
								
									default:
										break;

								}
								if (!(*test_line == pre_row && *test_column == pre_col))
									break;//鼠标移出当前范围则取消

							}
							
							
						}
					}
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:
					break;

				case MOUSE_NO_ACTION:
				default:
					break;
			}
		}
		/*还要支持键盘操作*/
		else if (ret == CCT_KEYBOARD_EVENT ) {
			cct_disable_mouse();	//禁用鼠标
			/*键盘第一次操作的时候，默认在左上角*/
			if (pre_row == 0) {
				*test_line = 1;
				*test_column = 1;
				draw_a_star(array[1][1], startx, starty, 1);//反显第一个色块
			}
			switch (keycode1) {
				case 13:	//回车键 
					if (judge_is_eliminated == 0)
					{
						loop = 0;
						cct_setcolor();
						cct_gotoxy(0, starty + disli * line + 1);
						cout << "选中了";
						putchar('A' + *test_line - 1);
						cout << "行" << *test_column - 1 << "列           \n";
						return 1;
					}
					else if (judge_is_eliminated == 1) {//输入回车键需要再一次
						if (digui_find(*test_line, *test_column, array, line, column) == 0) {
							cct_setcolor(0, COLOR_HYELLOW);
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "周围无相同值,";
							cct_setcolor();
							cout << "箭头键/鼠标移动，回车键/单击左键选择";
						}
						else if (digui_find(*test_line, *test_column, array, line, column)) {
							cct_gotoxy(0, starty + disli * line + 1);
							cct_setcolor();
							cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";
							highlight_all_linked_stars(line, column, array);//反显所有可以被消除的；
							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
							//ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
							switch (maction) {//再判断一次是否选择了
								case MOUSE_LEFT_BUTTON_CLICK://单击左键表示选择)
									return 1;
									break;
								default:
									break;
							}
							switch (keycode1) {
								case 13:
									return 1;
									break;
								default:
									break;

							}

						}
					}
				case 224://箭头键
					if (*test_line!= -1) {//取消之前的反显
						draw_a_star(array[*test_line][*test_column], startx + discol * (*test_column - 1), starty + disli * (*test_line - 1), 0);
					}
					switch (keycode2) {
						case KB_ARROW_UP://上箭头
							if (*test_line > 1)
								*test_line -= 1;
							else
								*test_line = line;
							cct_setcolor();
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "【当前键盘】";
							putchar('A' + *test_line - 1);
							cout << "行" << *test_column - 1 << "列" << setw(50) << " ";
							break;
						case KB_ARROW_DOWN://下箭头
							if (*test_line < line)
								*test_line += 1;
							else
								*test_line = 1;
							cct_setcolor();
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "【当前键盘】";
							putchar('A' + *test_line - 1);
							cout << "行" << *test_column - 1 << "列"<<setw(50)<<" ";
							break;
						case KB_ARROW_LEFT://左箭头
							if (*test_column > 1)
								*test_column -= 1;
							else
								*test_column = column;
							cct_setcolor();
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "【当前键盘】";
							putchar('A' + *test_line - 1);
							cout << "行" << *test_column - 1 << "列"<<setw(50)<<" ";
							break;
						case KB_ARROW_RIGHT:
							if (*test_column < column)
								*test_column += 1;
							else
								*test_column = 1;
							cct_setcolor();
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "【当前键盘】";
							putchar('A' + *test_line - 1);
							cout << "行" << *test_column - 1 << "列" << setw(50) << " ";
							break;
					}
					draw_a_star(array[*test_line][*test_column], startx + discol * (*test_column - 1), starty + disli * (*test_line - 1), 1);
					break;
			}
		}
	}
	return 0;
}
/****************************************************************************
函数名称：
函数参数：
函数功能：第一次单击的时候反显所有可以被消除的色块
函数返回值：
****************************************************************************/
void highlight_all_linked_stars(int line,int column,int array[][STAR_MAX])
{
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			if (array[i][j] > 100) {
				draw_a_star(array[i][j], 4 + 6 * (j - 1), 3 + 3 * (i - 1), 1);
			}
		}
	}
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			if (array[i][j] > 100) {
				array[i][j] %= 100;
			}
		}
	}
	
	
}

/****************************************************************************
函数名称：
函数参数：
函数功能：将菜单项F 中的第一步点击的色块处变成白色
函数返回值：
****************************************************************************/
void print_blank(int line, int column, int array[][STAR_MAX],int choice_line,int choice_column)
{
	digui_find(choice_line, choice_column, array, line, column);
	for (int i = 1; i <=line; i++){
		for (int j = 1; j <= column; j++) {
			if (array[i][j] > 100) {
				//打印成白色
				cct_setcolor(7, 7);
				int y = 3 + (i - 1) * 3;
				int x = 4 + (j - 1) * 6;
				cct_gotoxy(x, y);//左上角坐标
				cout << "      ";
				cct_gotoxy(x, y + 1);
				cout << "      ";
				cct_gotoxy(x, y + 2);
				cout << "      ";
				cct_setcolor();
			}
		}
		cct_gotoxy(0, 3 + 3 * line + 1);
		cout << "合成完成，回车键/单击左键下落"<<setw(50)<<" ";
	}

}
/****************************************************************************
函数名称：
函数参数：
函数功能：对数组实现下落功能的同时每次返回值为本次点击新增得分
函数返回值：
****************************************************************************/
int  graph_down_array(int line, int column, int array[][STAR_MAX])
{
	int num = 0;
	Sleep(50);//下落的动画效果
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			if (array[i][j] > 100) {
				array[i][j] = 0;
				num++;
			}
		}
	}
	dowm_array(line, column, array,1);//将数组内部重新排序，使0自然下落；
	//再打印一遍数组；//再打印一遍空白；
	draw_graph(line, column, array, 0);
	return num * num * 5;//打印数组的同时返回每次所得分数
}


