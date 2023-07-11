/* 2052316 信07 李祎娜 */
#include <iostream>
#include "../include/cmd_console_tools.h" 
#include "../include/menu_combine.h"
#include "90-02-b1-pop_star.h"
#include <conio.h>
using namespace std;
/*本文件的功能：存放main函数，调用各个函数，完成游戏的最终功能*/
int main()
{
	/* 执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	//cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		char select;
		int line, column;// 是该数组的行列大小【8-10】
		int li = 0, co = 0;//是键盘输入的要消除的行列
		int star_array[12][12] = { 0 };//将数组适当放大，预留四周的空间
		cct_setfontsize("新宋体", 16);
		cct_cls();
		
		char menu[][1024] = { {"A.命令行找出可消除项并标识\0"} ,
							 {"B.命令行完成一次消除（分步骤显示）\0"},
							 {"C.命令行完成一关（分步骤显示）\0"},
							 {"D.伪图形界面下用鼠标选择一个色块（无分隔线）\0"},
							 {"E.伪图形界面下用鼠标选择一个色块（有分隔线）\0"},
							 {"F.伪图形界面下完成一次消除（分步骤）\0"},
							 {"G.伪图形界面完整版\0"},
							 {"Q.退出\0"},
							 { "\0" } };
		int x;
		select = public_menu(menu, 2);
		if (select >='a' && select <= 'z') {
			select -= 32;//转为大写
		}
		x = select - 'A';
		if (select == 'Q') {
			cin_end_to_continue();
			continue;
		}
		cct_cls();
		
		get_line_column(&line, &column);//从键盘读数组行列大小
		star_array_setup(line, column, star_array);//建立数组
		if (x == 0) {
			step1_base(line, column,&li,&co, star_array);
		}
		else if (x == 1) {
			cmd_full_eliminate(line, column, &li, &co,star_array,2);
		}
		else if (x == 2) {
			pass_a_pass(line, column, &li, &co, star_array);
		}
		else if (x == 3) {
			graph_choice_noline(line, column, star_array, 1, 1);
		}
		else if (x == 4) {
			graph_choice_line(line, column, star_array, 1, 1);
		}
		else if (x == 5) {
			//伪图形界面下完成一步骤!加油啦
			graph_a_pop(line,column, star_array, 1, 1);
		}
		
		else if (x == 6) {//伪图形界面完整版
			final_pop_star(line, column, star_array, 1, 1);
		}
		
		cin_end_to_continue();
		
		

		//cct_setconsoleborder(cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines);//恢复为初始
	}
    return 0;
}
