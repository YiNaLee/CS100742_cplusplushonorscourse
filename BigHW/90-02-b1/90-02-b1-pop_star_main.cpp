/* 2052316 ��07 ��t�� */
#include <iostream>
#include "../include/cmd_console_tools.h" 
#include "../include/menu_combine.h"
#include "90-02-b1-pop_star.h"
#include <conio.h>
using namespace std;
/*���ļ��Ĺ��ܣ����main���������ø��������������Ϸ�����չ���*/
int main()
{
	/* ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	//cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		char select;
		int line, column;// �Ǹ���������д�С��8-10��
		int li = 0, co = 0;//�Ǽ��������Ҫ����������
		int star_array[12][12] = { 0 };//�������ʵ��Ŵ�Ԥ�����ܵĿռ�
		cct_setfontsize("������", 16);
		cct_cls();
		
		char menu[][1024] = { {"A.�������ҳ����������ʶ\0"} ,
							 {"B.���������һ���������ֲ�����ʾ��\0"},
							 {"C.���������һ�أ��ֲ�����ʾ��\0"},
							 {"D.αͼ�ν����������ѡ��һ��ɫ�飨�޷ָ��ߣ�\0"},
							 {"E.αͼ�ν����������ѡ��һ��ɫ�飨�зָ��ߣ�\0"},
							 {"F.αͼ�ν��������һ���������ֲ��裩\0"},
							 {"G.αͼ�ν���������\0"},
							 {"Q.�˳�\0"},
							 { "\0" } };
		int x;
		select = public_menu(menu, 2);
		if (select >='a' && select <= 'z') {
			select -= 32;//תΪ��д
		}
		x = select - 'A';
		if (select == 'Q') {
			cin_end_to_continue();
			continue;
		}
		cct_cls();
		
		get_line_column(&line, &column);//�Ӽ��̶��������д�С
		star_array_setup(line, column, star_array);//��������
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
			//αͼ�ν��������һ����!������
			graph_a_pop(line,column, star_array, 1, 1);
		}
		
		else if (x == 6) {//αͼ�ν���������
			final_pop_star(line, column, star_array, 1, 1);
		}
		
		cin_end_to_continue();
		
		

		//cct_setconsoleborder(cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines);//�ָ�Ϊ��ʼ
	}
    return 0;
}
