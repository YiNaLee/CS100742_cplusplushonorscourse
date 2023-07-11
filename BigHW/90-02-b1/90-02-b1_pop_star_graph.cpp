/*2052316 ��07 ��t��*/
/*���ļ�Ϊ90-02-b1��˽���ļ�����Ž������������йص�˽�к���*/
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
�������ƣ�
����������
�������ܣ��޷ָ��ߵ������ѡ�񣨲˵���D��
��������ֵ��
****************************************************************************/


/****************************************************************************
�������ƣ�
����������
�������ܣ���������״̬����������ʾ����
��������ֵ��
****************************************************************************/



/****************************************************************************
�������ƣ�
����������
�������ܣ�cmd���ڴ�С��������ֵ��С���仯
��������ֵ��
****************************************************************************/
void change_cmd(int line, int column,int dtrow,int dtcol,int*hang,int*lie, int  BASELINE, int BASECOLUMN)
{
	*hang = (line - MIN_SCALE) * dtrow + BASELINE;
	*lie = (column - MIN_SCALE) * dtcol + BASECOLUMN;

	cct_setconsoleborder(*lie, *hang);//���������С��ȷ�����ڴ�С
	//cout << "��ǰ��Ļ����Ϊ" << *hang << "��" << *lie<< "��";

}
/****************************************************************************
�������ƣ�
����������width�˴�������ĿҪ��Ҫ��6��3
�������ܣ���ӡ��� 
��������ֵ��
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
�������ƣ�
����������
�������ܣ���һ�����ǣ�����==1�����ԣ�������ͨ
��������ֵ����
****************************************************************************/
void draw_a_star(int random_color,int x,int y,int fanxian)
{
	if (random_color > 100) {
		random_color %= 100;
	}
	cct_gotoxy(x, y);//���Ͻ�����
	if (fanxian == 1) {
		cct_setcolor(random_color, COLOR_HWHITE);
	}
	else
	    cct_setcolor(random_color, COLOR_BLACK);
	if (random_color == 0) {
		cct_setcolor(7, 7);//��ӡ�հ�
	}
	cout << "�X�T�[";
	cct_gotoxy(x, y + 1);
	cout << "�U��U";
	cct_gotoxy(x, y + 2);
	cout << "�^�T�a";

}
/****************************************************************************
�������ƣ�
����������
�������ܣ���ͼ����ӡɫ�飻������ʼ��αͼ�λ�����
��������ֵ����
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
		case(1)://��ӡ��һ��
			cout << "�X";
			for (int k = 0; k < column-1; k++) {
				for (int i = 0; i < (scale-2)/2; i++) {
					cout << "�T";
				}
				cout << "�j";
			}
			for (int i = 0; i < (scale - 2) / 2; i++) {
				cout << "�T";
			}
			cout << "�[";
			break;
		case(2)://��ӡ�м�������
			for (int k = 0; k < column; k++) {
				cout << "�U";
				for (int i = 0; i < (scale - 2) / 2; i++) {
					cout << setw(2) << " ";
				}
			}
			cout<< "�U";
			break;
		case(3)://��ӡ�м���ʮ����
			cout << "�d";
			for (int k = 0; k < column - 1; k++) {
				for (int i = 0; i < (scale - 2) / 2; i++) {
					cout << "�T";
				}
				cout << "�p";
			}
			for (int i = 0; i < (scale - 2) / 2; i++) {
				cout << "�T";
			}
			cout << "�g";
			break;
		case(4)://��ӡ���һ��
			cout << "�^";
			for (int k = 0; k < column - 1; k++) {
				for (int i = 0; i < (scale - 2) / 2; i++) {
					cout << "�T";
				}
				cout << "�m";
			}
			for (int i = 0; i < (scale - 2) / 2; i++) {
				cout << "�T";
			}
			cout << "�a";
			break;

	}

}
/*���м��к��ߵı߿�*/
/****************************************************************************
��������:draw_complex_frame
����������XY������߿����ʼλ��
         row��column��������Ĵ�С
		  scale������С�߿�ı߳���С
�������ܣ���һ���м��к��ߵı߿�
��������ֵ��
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
�������ƣ�graph_choice_noline()
����������
�������ܣ�dѡ��ķ�װ����
��������ֵ��
****************************************************************************/
void graph_choice_noline(int line,int column,int array[][STAR_MAX],int choose_line,int choose_column)
{
	int hang = 0, lie = 0;//��ʾ��Ļ���д�С
	int test_line=-1, test_column=-1;
	change_cmd(line, column, DTROW, DTCOL,&hang,&lie,BASE_LINE, BASE_COLUMN);
	status_bar_up(hang, lie, 0, 0);
	draw_ruler(line, column, DTCOL, DTROW);
	draw_frame(3 * column, 3 * line, 2, 2);
	draw_graph(line, column, array,0);
	mouse_and_keyboard(&test_line, &test_column, line,column,array,0,4,3,3,6,0,0);
	/*�ָ���ʼ��Ļ��С*/
	cct_setcolor();
	
}
/****************************************************************************
�������ƣ�
����������
�������ܣ�eѡ��ķ�װ����,��d��Ψһ��ͬ�����м�Ŀ�
��������ֵ��
****************************************************************************/
void graph_choice_line(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column)
{
	int hang = 0, lie = 0;//��ʾ��Ļ���д�С
	int test_line = -1, test_column =-1;
	/*�����С*/
	change_cmd(line, column, DT2ROW, DT2COL, &hang, &lie, BASE2_LINE, BASE2_COLUMN);
	status_bar_up(hang, lie, 0, 0);
	draw_ruler(line, column, DT2COL, DT2ROW);
	draw_complex_frame(line, column, 2, 2, 8);
	draw_graph(line, column, array,1 );
	mouse_and_keyboard(&test_line, &test_column, line, column, array, 1,4,3,4,8,0,0);
	cct_setcolor();

}
/****************************************************************************
�������ƣ�graph_a_pop
����������
�������ܣ�αͼ�ν��������һ������ ��Ӧ�˵���F
��������ֵ��
****************************************************************************/
void graph_a_pop(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column)
{
	int hang = 0, lie = 0;//��ʾ��Ļ���д�С
	int test_line = -1, test_column = -1;
	int keycoded = 0;
	change_cmd(line, column, DTROW, DTCOL, &hang, &lie, BASE_LINE, BASE_COLUMN);
	status_bar_up(hang, lie, 0, 0);
	draw_ruler(line, column, DTCOL, DTROW);
	draw_frame(3 * column, 3 * line, 2, 2);
	draw_graph(line, column, array, 0);
	if (mouse_and_keyboard(&test_line, &test_column, line, column, array, 0, 4, 3, 3, 6, 1,1) == 1) {
		//����1��˵���еط�Ҫ��������
		print_blank(line,column, array, test_line, test_column);
		click_and_enter(&keycoded, 0);

	}
	
	int score=graph_down_array(line, column, array);
	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "���ε÷�:" << score <<"  "<< "�ܵ÷�:" << score;
	
	/*���κϳɽ����������������c��һ�κϳ�*/
	cct_gotoxy(0, 3 + 3 * line + 1);
	cout << "���κϳɽ�������C/�������������һ�εĺϳ�\n";
	click_and_enter(&keycoded, 2);
	/*��Ҫ�����̺����������س�����*/
}
/****************************************************************************
�������ƣ�final_pop_star()
����������
�������ܣ�����������Ϸ���հ棬��Ӧ�˵���G
��������ֵ��
****************************************************************************/
void final_pop_star(int line, int column, int array[][STAR_MAX], int choose_line, int choose_column)
{
	int full_score = 0;
	int hang = 0, lie = 0;//��ʾ��Ļ���д�С
	int test_line = -1, test_column = -1;
	int keycoded = 0;
	change_cmd(line, column, DTROW, DTCOL, &hang, &lie, BASE_LINE, BASE_COLUMN);
	status_bar_up(hang, lie, 0, 0);
	draw_ruler(line, column, DTCOL, DTROW);
	draw_frame(3 * column, 3 * line, 2, 2);
	draw_graph(line, column, array, 0);
	while (1) {
		//������һ�غ�����Ҫ�����������
		star_array_setup(line, column, array);
		draw_graph(line, column, array, 0);
		while (judge_is_over(line, column, array)) {
			//����1��˵���еط�Ҫ��������������Ϸδ����
			mouse_and_keyboard(&test_line, &test_column, line, column, array, 0, 4, 3, 3, 6, 1, 1);
			print_blank(line, column, array, test_line, test_column);//��ӡ�հ�
			int perscore = graph_down_array(line, column, array);//һ�κϳɽ���
			full_score += perscore;
			cct_setcolor();
			cct_gotoxy(0, 0);
			cout << "���ε÷֣�" << perscore <<"�֣�"<< "�ܷ֣�" << full_score<<"��        ";
			cout << endl;//��Ҫ�����ǰ�ķ�����Ϣ
		}
		int lef = cul_lef(line, column, array);
		int reward_mark = 0;
		if (lef < 10) {
			reward_mark = (10 - lef) * 180;
		}
		full_score += reward_mark;
		cct_gotoxy(0, 0);
		cout << "�����÷֣�" << reward_mark << "��,�ܷ�" << full_score<<"��            ";
		while (_getch() != '\r')
			continue;
	}
	
}
/****************************************************************************
�������ƣ�
����������
�������ܣ�����ʣ��ĸ��������Ҿ����Ƿ�ӷ�
��������ֵ��
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
	cout << "ʣ��" << num << "�����ǣ��޿���������ؽ������س�������һ��";
	cct_setcolor();
	return num;
}
/****************************************************************************
�������ƣ�
����������
�������ܣ�/*ֻ��ȡ�����ͻس�����
��������ֵ��
****************************************************************************/

void click_and_enter(int*keycode1_,int canshu)
{
	int biaoji = 1;
	while (biaoji) {
		/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		int XX, YY, maction_,keycode2_;
		int ret = cct_read_keyboard_and_mouse(XX, YY, maction_, *keycode1_, keycode2_);

		if (ret == CCT_MOUSE_EVENT) {
			switch (maction_) {
				case MOUSE_LEFT_BUTTON_CLICK:
					biaoji = 0;//�������
					break;
				default:
					break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
		else if (ret == CCT_KEYBOARD_EVENT) {

			switch (*keycode1_) {
				case 13:	//�س���
					if(canshu==0)
					    biaoji = 0;
					break;
				case 99://c��asc��
				case 67:
					if (canshu == 2) {
						biaoji = 0;
					}
					break;
				default:
					break;
			}
		}//end of else if(ret == CCT_KEYBOARD_EVENT��
	} //end of while(1)
}


/****************************************************************************
�������ƣ�mouce_and_keyboard()
����������canshu==0�м��޺��ߣ�������1���м��к���
��������:���ͼ��̵�һЩ������
����judge_is_eliminated����Ϊ0����DEѡ��Ĳ����ж��Ƿ��������
                       ����Ϊ1����FGѡ��ĵ����ͻس���Ҫ�ж��ܷ�����
					   special_deal����DEѡ����Զ���0������Fѡ�����1
****************************************************************************/
int mouse_and_keyboard(int* test_line, int* test_column,int line, int column,int array[STAR_MAX][STAR_MAX],int canshu,int startx,int starty,
	int disli,int discol,int judge_is_eliminated,int special_deal)
{
	int X = 0, Y = 0;//��ȡ����������
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int fanxian = 0;
	int pre_row=0, pre_col = 0;
	cct_enable_mouse();//����������
	while (loop) {
		cct_setcursor(CURSOR_INVISIBLE);//�رչ��
		if (special_deal) {
			draw_graph(line, column, array, 0);
			if(*test_line>=1)
			    draw_a_star(array[*test_line][*test_column], startx + discol * (*test_column - 1), starty + disli * (*test_line - 1), 1);
			
		}
			
		cct_enable_mouse();//����������
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		/*X.Y���Ի�ȡ��ǰ��������*/
		if (ret == CCT_MOUSE_EVENT) {//����¼�����Ҫ�ж�λ���Ƿ�Ϸ���ת��ĳ�д�ӡ
			switch (maction) {
				case MOUSE_ONLY_MOVED://�ƶ���Ҫ�ж�λ�� ����ǺϷ�λ����Ҫ���Բ���ӡλ�ã�λ�÷Ƿ�����ʾ
					pre_row = *test_line;
					pre_col = *test_column;
					if (canshu == 0) {//�м��޺���
						fanxian = legal_XY(X, Y, line, column, starty, startx, disli, discol, test_line, test_column,0,array);
					}
					else {
						fanxian = legal_XY(X, Y, line, column, starty, startx, disli, discol, test_line, test_column,1,array);
					}
					
					if (fanxian == 1) {//��꾭���Ϸ�λ�ã���Ҫ����
						if (pre_row != -1) {
							if (!(pre_row == *test_line&&pre_col == *test_column)) {
								//֤����һ�ε�λ�ú���β�ͬ����Ҫ��ȡ���Ϸ���
								draw_a_star(array[pre_row][pre_col], startx + discol * (pre_col - 1), starty + disli* (pre_row - 1), 0);
							}
						}
						draw_a_star(array[*test_line][*test_column], startx + discol * (*test_column - 1), starty + disli * (*test_line - 1), 1);
					}/*�������ƿ���Ҫȡ������*/
					/*����ƿ��ˣ�λ�÷Ƿ���Ҳ��Ҫȡ������*/
					else {
						if (pre_row != -1) {
							draw_a_star(array[pre_row][pre_col], startx + discol * (pre_col - 1), starty + disli * (pre_row - 1), 0);
						}
					}
				
					break;
				case MOUSE_LEFT_BUTTON_CLICK://���������ʾѡ��
					if (fanxian == 1&& judge_is_eliminated==0) {
						cct_setcolor();
						cct_gotoxy(0, starty + disli * line + 1);
						cout << "ѡ����";
						putchar('A' + *test_line - 1);
						cout << "��" << *test_column - 1 << "��           \n";
						loop = 0;
					}
					else if(judge_is_eliminated == 1){//��Ҫ�ж�ѡ�е����������Ƿ��������
						if (digui_find(*test_line, *test_column, array, line, column) == 0) {
							cct_setcolor(0,COLOR_HYELLOW);
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "��Χ����ֵͬ,";
							cct_setcolor();
							cout << "��ͷ��/����ƶ����س���/�������ѡ��";
							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);//�ٶ�һ���������������޷�Ӧ��
							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);//�ٶ�һ���������������޷�Ӧ
							cct_gotoxy(0, starty + disli * line + 1);
							cout << setw(50) << " ";
							
						}
						else if (digui_find(*test_line, *test_column, array, line, column)) {
							cct_gotoxy(0, starty + disli * line + 1);
							cct_setcolor();
							cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�";
							highlight_all_linked_stars(line, column, array);//�������п��Ա������ģ�
							int flag = 1;
							while (flag) {
								ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
								ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
								pre_row = *test_line;
								pre_col = *test_column;
								switch (maction) {//���ж�һ���Ƿ�ѡ��
									case MOUSE_LEFT_BUTTON_CLICK://���������ʾѡ��)
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
									case 224://��ȡ��ͷ��
										flag = 0;
										break;
								
									default:
										break;

								}
								if (!(*test_line == pre_row && *test_column == pre_col))
									break;//����Ƴ���ǰ��Χ��ȡ��

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
		/*��Ҫ֧�ּ��̲���*/
		else if (ret == CCT_KEYBOARD_EVENT ) {
			cct_disable_mouse();	//�������
			/*���̵�һ�β�����ʱ��Ĭ�������Ͻ�*/
			if (pre_row == 0) {
				*test_line = 1;
				*test_column = 1;
				draw_a_star(array[1][1], startx, starty, 1);//���Ե�һ��ɫ��
			}
			switch (keycode1) {
				case 13:	//�س��� 
					if (judge_is_eliminated == 0)
					{
						loop = 0;
						cct_setcolor();
						cct_gotoxy(0, starty + disli * line + 1);
						cout << "ѡ����";
						putchar('A' + *test_line - 1);
						cout << "��" << *test_column - 1 << "��           \n";
						return 1;
					}
					else if (judge_is_eliminated == 1) {//����س�����Ҫ��һ��
						if (digui_find(*test_line, *test_column, array, line, column) == 0) {
							cct_setcolor(0, COLOR_HYELLOW);
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "��Χ����ֵͬ,";
							cct_setcolor();
							cout << "��ͷ��/����ƶ����س���/�������ѡ��";
						}
						else if (digui_find(*test_line, *test_column, array, line, column)) {
							cct_gotoxy(0, starty + disli * line + 1);
							cct_setcolor();
							cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�";
							highlight_all_linked_stars(line, column, array);//�������п��Ա������ģ�
							ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
							//ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
							switch (maction) {//���ж�һ���Ƿ�ѡ����
								case MOUSE_LEFT_BUTTON_CLICK://���������ʾѡ��)
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
				case 224://��ͷ��
					if (*test_line!= -1) {//ȡ��֮ǰ�ķ���
						draw_a_star(array[*test_line][*test_column], startx + discol * (*test_column - 1), starty + disli * (*test_line - 1), 0);
					}
					switch (keycode2) {
						case KB_ARROW_UP://�ϼ�ͷ
							if (*test_line > 1)
								*test_line -= 1;
							else
								*test_line = line;
							cct_setcolor();
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "����ǰ���̡�";
							putchar('A' + *test_line - 1);
							cout << "��" << *test_column - 1 << "��" << setw(50) << " ";
							break;
						case KB_ARROW_DOWN://�¼�ͷ
							if (*test_line < line)
								*test_line += 1;
							else
								*test_line = 1;
							cct_setcolor();
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "����ǰ���̡�";
							putchar('A' + *test_line - 1);
							cout << "��" << *test_column - 1 << "��"<<setw(50)<<" ";
							break;
						case KB_ARROW_LEFT://���ͷ
							if (*test_column > 1)
								*test_column -= 1;
							else
								*test_column = column;
							cct_setcolor();
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "����ǰ���̡�";
							putchar('A' + *test_line - 1);
							cout << "��" << *test_column - 1 << "��"<<setw(50)<<" ";
							break;
						case KB_ARROW_RIGHT:
							if (*test_column < column)
								*test_column += 1;
							else
								*test_column = 1;
							cct_setcolor();
							cct_gotoxy(0, starty + disli * line + 1);
							cout << "����ǰ���̡�";
							putchar('A' + *test_line - 1);
							cout << "��" << *test_column - 1 << "��" << setw(50) << " ";
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
�������ƣ�
����������
�������ܣ���һ�ε�����ʱ�������п��Ա�������ɫ��
��������ֵ��
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
�������ƣ�
����������
�������ܣ����˵���F �еĵ�һ�������ɫ�鴦��ɰ�ɫ
��������ֵ��
****************************************************************************/
void print_blank(int line, int column, int array[][STAR_MAX],int choice_line,int choice_column)
{
	digui_find(choice_line, choice_column, array, line, column);
	for (int i = 1; i <=line; i++){
		for (int j = 1; j <= column; j++) {
			if (array[i][j] > 100) {
				//��ӡ�ɰ�ɫ
				cct_setcolor(7, 7);
				int y = 3 + (i - 1) * 3;
				int x = 4 + (j - 1) * 6;
				cct_gotoxy(x, y);//���Ͻ�����
				cout << "      ";
				cct_gotoxy(x, y + 1);
				cout << "      ";
				cct_gotoxy(x, y + 2);
				cout << "      ";
				cct_setcolor();
			}
		}
		cct_gotoxy(0, 3 + 3 * line + 1);
		cout << "�ϳ���ɣ��س���/�����������"<<setw(50)<<" ";
	}

}
/****************************************************************************
�������ƣ�
����������
�������ܣ�������ʵ�����书�ܵ�ͬʱÿ�η���ֵΪ���ε�������÷�
��������ֵ��
****************************************************************************/
int  graph_down_array(int line, int column, int array[][STAR_MAX])
{
	int num = 0;
	Sleep(50);//����Ķ���Ч��
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			if (array[i][j] > 100) {
				array[i][j] = 0;
				num++;
			}
		}
	}
	dowm_array(line, column, array,1);//�������ڲ���������ʹ0��Ȼ���䣻
	//�ٴ�ӡһ�����飻//�ٴ�ӡһ��հף�
	draw_graph(line, column, array, 0);
	return num * num * 5;//��ӡ�����ͬʱ����ÿ�����÷���
}


