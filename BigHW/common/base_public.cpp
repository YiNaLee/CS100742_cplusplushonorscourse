/* 信07 2052316 李祎娜 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include"../include/basic_public.h"

using namespace std;

/*本函数的功能：存放一些扫雷和消灭星星都需要用到的共用函数*/
/****************************************************************************
函数名称：
函数参数：
函数功能：
函数返回值：
****************************************************************************/



/****************************************************************************
函数名称：
函数参数：
函数功能：
函数返回值：
****************************************************************************/
/*函数名称：reveal()
函数功能：对需要第一步被打开的数组加1000
起到标记打开的作用
*/
void reveal(int* number)
{
	*number =1000+(*number);
}







/****************************************************************************
函数名称：digui_find()
函数参数：num1,num2为键盘读到的要消除的位置，line和column为最大的行列数
函数功能：用递归的方式找到周围四个方向相同的数字并标记他们
         注：本个查找指定位置坐标及周围相同项的函数两个不同版本的消灭星星可共用。
函数返回值

****************************************************************************/
int digui_find(int num1, int num2, int array[][12], int line, int column)
{
	if (array[num1][num2] == 0) {
		return 0;//返回0，不可消去
	}
	int same_color = array[num1][num2]%100;
	
	if (num1 >= 1 && num1 <= line && num2 >= 1 && num2 <= column) {
		/*if (array[num1 + 1][num2] == same_color || array[num1 - 1][num2] == same_color ||
			array[num1][num2 + 1] == same_color || array[num1][num2 - 1] == same_color) {
			//判断有相同色块的条件是数值相同或者相反
			reveal(&array[num1][num2]);//证明可以被消除，标记；
			search_around(num1, num2, array, line, column);//递归寻找需要被消除的星星
			
			
		}*/
		if (array[num1 + 1][num2] == same_color) {
			reveal(&array[num1][num2]);//证明可以被消除，标记；
			reveal(&array[num1 + 1][num2]);
			digui_find(num1 + 1, num2, array, line, column);
		}
		if (array[num1 - 1][num2] == same_color) {
			reveal(&array[num1][num2]);//证明可以被消除，标记；
			reveal(&array[num1-1][num2]);
			digui_find(num1 -1, num2, array, line, column);
		}
		if (array[num1][num2-1] == same_color) {
			reveal(&array[num1][num2]);//证明可以被消除，标记；
			reveal(&array[num1][num2-1]);
			digui_find(num1, num2-1, array, line, column);
		}
		if (array[num1][num2+1] == same_color) {
			reveal(&array[num1][num2]);//证明可以被消除，标记；
			reveal(&array[num1][num2+1]);
			digui_find(num1, num2+1, array, line, column);
		}
	}
	
	if (array[num1][num2] < 100) {//证明这个位置的四周都没有颜色相同的方块
		return 0;

	}
	return 1;//返回1，说明这个地方可消去
	
	
}
/****************************************************************************
函数名称：judge_is_over(int line ,int column,int array[12][12])
函数参数：
函数功能：
函数返回值：返回0说明游戏结束，返回非0说明游戏未结束。
****************************************************************************/
int judge_is_over(int line ,int column,int array[12][12])
{
	int judge = 0;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			judge += digui_find(i, j, array, line, column);
		}
	}
	/*由于digui_find函数对数组做了加操作，要复原*/
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			array[i][j] %= 100;
		}
	}
	return judge;//返回非0说明游戏未结束，返回0说明游戏结束

}
/*状态栏打印函数*/
void status_bar_up(int sizerow, int sizecol, const int X, const int Y)
{
	cct_gotoxy(X, Y);
	cout << "当前屏幕设置为" << sizerow << "行" << sizecol << "列\n";
}

/*缓冲区恢复函数*/
void save_oldbuffer_size(int* cur_cols, int* cur_lines, int* cur_buffer_cols, int* cur_buffer_lines)
{

	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);//取现有缓冲区的大小
	/* 保留现值，用于恢复 */
	*cur_cols = cols;
	*cur_lines = lines;
	*cur_buffer_cols = buffer_cols;
	*cur_buffer_lines = buffer_lines;
}
/****************************************************************************
函数名称：draw_frame
函数参数：
函数功能：画边框
函数返回值：
****************************************************************************/
void draw_frame(int length, int height,int X, int Y)
{
	cct_gotoxy(X, Y);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	/*打印第一排*/
	cout << "╔";//一个符号占2字节
	for (int i = 0; i < length; i++) {
		cout << "═";
	}
	cout << "╗";
	/*打印中间排*/
	for (int j = 0; j < height; j++) {
		Y++;
		cct_gotoxy(X, Y);
		cout << "║";
		for (int i = 0; i < length; i++) {
			cout << setw(2) << " ";
		}
		cout << "║" << endl;
		Sleep(50);//动画效果
		
	}
	/*打印最后排*/
	cct_gotoxy(X, Y + 1);
	cout << "╚";//一个符号占2字节
	for (int i = 0; i < length; i++) {
		cout << "═";
	}
	cout << "╝";

}

/****************************************************************************
函数名称：legal_XY()
函数参数：这里的discol为6/8，disline为3/4；startx为4；starty为3
函数功能:判断鼠标位置是否合法。
函数返回值：0不合法，1合法
****************************************************************************/
int legal_XY(int X, int Y, int line, int column, int starty, int startx, int disline, int discol,
	int* choose_line, int* choose_col,int differ,int array[][12])
{
	cct_setcolor();
	cct_gotoxy(0, starty + disline * line + 1);
	cout << "【当前鼠标】";
	if (Y<starty || Y>(starty + line * disline-1) || X<startx || X>startx + column * discol-1) {
		cout << "位置非法" << setw(50) << " ";
		return 0;
	}
	else {
		if (differ == 0) {//无中间边界的参数为0
			/*在游戏版本中还要判断这个位置是不是0，如果已经被消除，是0，也算非法位置。*/
			*choose_col = (X - startx) / discol + 1;//表示的是真实在数组中的行/列（以12*12）
			*choose_line = (Y - starty) / disline + 1;
			if (array[*choose_line][*choose_col]!=0) {
				putchar('A' + *choose_line - 1);
				cout << "行" << *choose_col - 1 << "列     " << setw(50) << " ";
				return 1;//表示位置合法
			}
			else {
				cout << "位置非法" << setw(50) << " ";
				return 0;
			}
		}
		else {
			if ((X - 3) % 8 == 0 || (X - 3) % 8 == 1 || (Y - 2) % 4 == 0) {
				cout << "位置非法"<< setw(50) << " ";
				return 0;
			}
			else {
				*choose_col = (X - startx) / discol + 1;//表示的是真实在数组中的行/列（以12*12）
				*choose_line = (Y - starty) / disline + 1;
				putchar('A' + *choose_line - 1);
				cout << "行" << *choose_col - 1 << "列     " << setw(50) << " ";;
				return 1;//表示位置合法

			}

		}
	}
	return 0;

}
/*函数名称：gmw_downstar
函数功能：每次完成一次鼠标有效点击后，将内部数组重新排列，使浮在最上面*/
void gmw_public_downstar(int line, int column, int star_array[][12])
{
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
void public_pause_enter(const char* prompt)
{
	//cout << "按回车键进行数组下落操作...";
	if (prompt != NULL)
		cout << prompt;
	while (_getch() != '\r')
		;
	return;
}
/****************************************************************************
函数名称：public_cin_end_to_continue()
函数参数：
函数功能：菜单项完成时，输入end来确定本小题的结束
函数返回值：
****************************************************************************/
void public_cin_end_to_continue()
{
	char shuru[20] = "0";

	while (1) {
		if (!cin) {//如果状态不对，要处理
			cin.clear();
			cin.ignore(65536, '\n');
		}
		
		cout << "本小题结束，输入End继续...";
		cin.getline(shuru, 19);
		if ((shuru[0] == 'e' || shuru[0] == 'E') && (shuru[1] == 'n' || shuru[1] == 'N') && (shuru[2] == 'd' || shuru[2] == 'D')) {
			break;
		}
		for (int i = 0; i < 20; i++) {
			shuru[i] = '0';
		}
		cin.ignore(65536, '\n');
		cout << "输入错误，请重新输入\n";
	}
}