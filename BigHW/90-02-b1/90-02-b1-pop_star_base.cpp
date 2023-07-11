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
函数功能：
函数返回值：
****************************************************************************/
/****************************************************************************
函数名称：puase_enter()
函数参数：
函数功能：输入回车键进行数组下落操作
函数返回值：
****************************************************************************/
void pause_enter(const char*prompt)
{
	//cout << "按回车键进行数组下落操作...";
	cout << prompt;
	while (_getch() != '\r')
		;
	return;
}
/****************************************************************************
函数名称：cin_end_to_continue()
函数参数：
函数功能：菜单项完成时，输入end来确定本小题的结束
函数返回值：
****************************************************************************/
void cin_end_to_continue()
{
	char shuru[20] = "0";
	
	while (1) {
		cin.ignore(65536, '\n');
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
/****************************************************************************
函数名称：char to_confirm_eliminate(int*li,int *co)
函数参数：li,co
函数功能：获取输入指令，是否消除
函数返回值：Y/N/Q
****************************************************************************/
char to_confirm_eliminate(int*li,int *co)
{
	char confirm;
	cout << "请确认是否把" << (char)(*li + 'A') << *co << "及周围的相同值消除(Y/N/Q):";
	while (1) {
		confirm= _getch();
		if (confirm == 'y' || confirm == 'Y' || confirm == 'n' || confirm == 'N' || confirm == 'q' || confirm == 'Q') {
			putchar(confirm);
			if (confirm == 'y' || confirm == 'q' || confirm == 'n') {
				confirm -= 32;//统一转成大写字母;
			}
			break;
		}


	}
	return confirm;
}


/**************************************************************************
函数名称：get_line_column
函数参数 两个指针变量
函数功能 获得改变行和列的值
函数返回值 无
*****************************************************************************/
void get_line_column(int* line, int* column)
{
	while (1) {
		cct_gotoxy(0, 0);
		cout << "请输入行数（8-10）：";
		cin >> *line;
		if (!cin.good() || *line < 8 || *line>10) {
			cct_gotoxy(0, 1);
			cout << "输入不合法，请重新输入";
			cct_gotoxy(19,0);
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
					cct_gotoxy(0,2);
					cout << "输入不合法，请重新输入";
					cct_gotoxy(20,1);
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
函数名称：star_array_setup(int*line,int*column)
函数参数：&column,&line
函数功能：根据输入的行列值生成颜色概率相等的消灭星星数组
函数返回值：
其他说明：

*********************************************************************/
void star_array_setup(int line, int column,int star_array[STAR_MAX][STAR_MAX])
{
	/*需要随机产生1-5等概率的数字，每次不相同*/
	srand((unsigned int)(time(0)));//生成随机数的种子
	for (int i = 1; i <=line; i++) {
		for (int j = 1; j <= column; j++) {
			star_array[i][j] = rand() % 5 + 1;
		}
	}

}
/****************************************************************************
函数名称：print_prililary()
函数参数：line column star_array[][]
函数功能:打印数组都合用这一个函数。
函数返回值：本次得分
****************************************************************************/

int print_primilary(int line,int column,int star_array[STAR_MAX][STAR_MAX],const char *prompt)
{
	int per_score = 0;//用于计算单次得分；
	int num = 0;//用于计算每次消除的个数
	if (prompt) {
		cout << prompt << endl;
	}
	//cout << "当前数组：\n";
	cout << "  |";
	for (int i = 0; i < column; i++) {
		cout << setw(3) << i;
	}
	cout << endl;
	cout << "--+";
	for (int i = 0; i < column; i++) {
		cout << "---";
	}
	cout << "-\n";
	/*接下来输出每行：*/
	for (int i = 0; i < line; i++) {
		putchar('A' + i);
		cout << " |";
		for (int j = 0; j < column; j++) {
			if (prompt == "当前数组（不同色标识）："||prompt=="相同值归并后的数组（不同色标识）:"
				   ||prompt== "下落后的数组:") {
				if (star_array[i + 1][j + 1] > 5||star_array[i+1][j+1]==0) {//高亮输出
					star_array[i + 1][j + 1] %= 100;
					if (prompt == "相同值归并后的数组（不同色标识）:") {
						if (star_array[i + 1][j + 1] != 0) {
							num++;
						}
						star_array[i + 1][j + 1] = 0;//归并后置为0输出，
					}
					cout << setw(2)<< " ";
					cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);//设置高亮
					cout << star_array[i + 1][j + 1];
					//输出结束后如果只是标记相同色块，则要复原到100+
					//如果是y消除按钮，则说明该色块已经被消除，仍然置为0
					if (prompt == "当前数组（不同色标识）：") {
						star_array[i + 1][j + 1] += 100;
					}
					cct_setcolor();//恢复为缺省颜色
				}
				else//普通输出
					cout << setw(3) << star_array[i + 1][j + 1];
			}
			else if (prompt == "当前数组：") {
				if (star_array[i + 1][j + 1] == 0) {
					cout << setw(2) << " ";
					cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);//设置高亮
					cout << star_array[i + 1][j + 1];
					cct_setcolor();//恢复为缺省颜色
				}
				else 
					cout << setw(3) << star_array[i + 1][j + 1];
			}
			else 
			    cout << setw(3) << star_array[i+1][j+1];
			
		}
		cout << endl;
	}
	cout << endl;
	per_score = num * num * 5;
	return per_score;//本次得分
}
/****************************************************************************
函数名称：void cin_position()
函数参数：int*li,in*co//用来返回输入的坐标位置，line ，column用来比较上限
函数功能：获取需要消除的行列的坐标位置
函数返回值：
****************************************************************************/
void cin_position(int* li, int* co, int line, int column)
{
	char Line;
	int Column;
	cout << "请以字母+数字形式【例：c2】输入矩阵坐标：";
	while (1) {//处理行输入

		cin >> Line;
		if (!cin.good()) {
			cout << "输入错误，请重新输入.";
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (Line >= 'a' && Line <= 'a' + line - 1 || Line >= 'A' && Line <= 'A' + line - 1) {
			if (Line >= 'a' && Line <= 'a' + line - 1)
				Line -= 32;/*全部转成大写*/
			break;
		}
		cin.clear();
		cin.ignore(65536, '\n');
		cout << "输入错误，请重新输入.";
	}
	while (1) {
		//处理列输入
		cin >> Column;
		if (!cin.good()) {
			cout << "输入错误，请重新输入.";
			/*若列输入出现问题，则行输入也要重新输入过*/
			cin.clear();
			cin.ignore(65536, '\n');
			/*清空缓冲区后，重新从行开始输入*/
			while (1) {//处理行输入
				cin >> Line;
				if (!cin.good()) {
					cout << "输入错误，请重新输入.";
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				if (Line >= 'a' && Line <= 'a' + line - 1 || Line >= 'A' && Line <= 'A' + line - 1) {
					if (Line >= 'a' && Line <= 'a' + line - 1)
						Line -= 32;/*全部转成大写*/
					break;
				}
				cin.clear();
				cin.ignore(65536, '\n');
				cout << "输入错误，请重新输入.";
			}
			continue;
		}
		if (Column >= 0 && Column < column) {
			break;
		}
		/*如果未退出，证明程序输入有误，还要重新输入行*/
		cout << "输入错误，请重新输入.";
	}
	*li = Line - 'A';
	*co = Column;
	cout << "输入为";
	putchar('A' + *li);
	cout << "行" << *co << "列\n";
}
/****************************************************************************
函数名称：
函数参数：donghua==0表示无动画效果，donghua==1表示有动画效果
函数功能：对数组进行重新排列，将中间为0的地方自然下落；
函数返回值：
****************************************************************************/
void dowm_array(int line, int column, int star_array[STAR_MAX][STAR_MAX],int donghua)
{
	//先检查每一列，从下往上检查、
	for (int i = 1; i <= column; i++) {
		for (int j = line; j > 1; j--) {
			if (star_array[j][i] == 0) {//记录第一个为0的位置
				int successive_num = 0;//定义一个计算连续相同色块的变量
				int l = j;//记录第一个为0的位置
				for (; star_array[l][i] == 0&&l>1; l--) {
					successive_num++;
				}
				for (; j - successive_num >= 1; j--) {
					star_array[j][i] = star_array[j - successive_num][i];
					//需要打印动画效果；
					if (donghua == 1){
						Sleep(1);//打印一下目前的数组
						draw_graph(line, column,star_array, 0);
				    }
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
				if (donghua == 1) {
					Sleep(1);//打印一下目前的数组
					draw_graph(line, column, star_array, 0);
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
		for (ip = 1; ip< column; ip++) {//最后一列为0不用平移
			if (star_array[line][ip] == 0) {
				first_col = ip;
				break;
				/*successive_col++;
				if (star_array[line][i + 1] != 0) {
					break;
				}*/
			}
		}/*用于计算是否可能存在多行连续为0的情况*/
		if (ip == column-whole+1||ip==column) {
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
		if (successive_col >= 1&&first_col<=column) {
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


	cout << endl;
}
/****************************************************************************
函数名称：cal_left_num
函数参数：
函数功能：计算剩余多少个星星，奖励多少分数
函数返回值：
****************************************************************************/
int cal_left_num(int line,int column,int array[][STAR_MAX])
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
	cct_setcolor(COLOR_HYELLOW, COLOR_RED);//设置高亮
	cout << "剩余" << num_left << "个不可消除项，本关结束！\n";
	cct_setcolor();/*考虑放到一个函数中去*/
	return num_left;
}
/****************************************************************************
函数名称：
函数参数：
函数功能：完成菜单项1的封装操作
函数返回值：
****************************************************************************/
void step1_base(int line,int column,int*li,int*co,int array[][STAR_MAX])
{
	//从键盘读取的要消除的数组下标
	print_primilary(line, column, array,"当前数组：");//打印初始状态下的数组
	cin_position(li, co, line, column);//获取要消除的位置坐标
	int accept=digui_find(*li+1, *co+1, array, line, column);//同时accept来接受返回值；
    /*返回为1说明该位置处有相同的色块，返回为0说明没有相同色块*/
	while(accept == 0) {
		cout << "输入的矩阵位置坐标处无相同值，请重新输入";
		cin_position(li, co, line, column);
		accept = digui_find(*li+1, *co+1, array, line, column);
	}
	/*当返回值不为0，说明可消灭星星。需要查找结果数组*/
	int copy_array[12][12] = {0};
	for (int i = 1; i <=line; i++) {
		for (int j = 1; j <= column; j++) {
			if (array[i][j] >100) {
				copy_array[i][j] = 1;
			}
		}
	}
	print_primilary(line, column, copy_array, "查找结果数组：");
	print_primilary(line, column, array, "当前数组（不同色标识）：");

}
/****************************************************************************
函数名称：
函数参数：
函数功能：完成菜单项2的封装操作
          命令行下一次消除
函数返回值：
****************************************************************************/
int cmd_full_eliminate(int line, int column,int*li,int *co,int array[][STAR_MAX],int canshu)
{
	int sin_score = 0;//本次得分
	step1_base(line, column, li, co, array);
	char choice=to_confirm_eliminate(li, co);
	cout << endl;
	if (choice == 'Y') {//确认要消除
		//打印相同值归并后的数组：将相同的地方置为0
		sin_score=print_primilary(line, column, array, "相同值归并后的数组（不同色标识）:");
		if (canshu == 2) {
			cout << "本次得分：" << sin_score << "分 " << "总得分：" << sin_score << "分\n";
			pause_enter("按回车键进行数组下落操作...");//按回车进行数组下落；
			dowm_array(line, column, array,0);//将数组进行移动
			print_primilary(line, column, array, "下落后的数组:");
		}
		else if (canshu == 3) {
			cout << "本次得分" << sin_score << "分";
		}
		
	}
	return sin_score;
}
/****************************************************************************
函数名称：pass_a_pass()
函数参数：
函数功能：命令行下循环执行完成一关，直到无相同数字星星可消除
函数返回值：
****************************************************************************/
void pass_a_pass(int line, int column, int* li, int* co, int array[][STAR_MAX])
{
	int full_score = 0;
	int reljudge = 1;
	while(reljudge){
		full_score+=cmd_full_eliminate(line, column, li, co, array,3);
		cout<<"总得分：" << full_score << "分\n";
		pause_enter("按回车键进行数组下落操作...");//按回车进行数组下落；
		dowm_array(line, column, array,0);//将数组进行移动
		print_primilary(line, column, array, "下落后的数组:");
		pause_enter("本次消除结束，按回车键继续一次新的消除...");
		cout << endl;
		reljudge = judge_is_over(line, column, array);//判断游戏是否结束
	}
	cal_left_num(line, column, array);

}
