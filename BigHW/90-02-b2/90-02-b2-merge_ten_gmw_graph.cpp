/*2052316 ��07 ��t��*/
#define _CRT_SECURE_NO_WARNINGS
/* -----------------------------------------
	 ���ļ����ܣ�
	1��������������gmw��������ɵ��޷ָ��߰汾
	2�����ļ��еĺ���Ϊ˽�к�������main����
	3.ע������ʱ�����ƣ������������ʵ������������������
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
	 �������ƣ�get_line_column
	 �������� ����ָ�����
	 �������� ��øı��к��е�ֵ
	 ��������ֵ ��
	 *****************************************************************************/
void get_line_column(int* line, int* column,int*target)
{
	while (1) {
		cct_gotoxy(0, 0);
		cout << "������������5-8����";
		cin >> *line;
		if (!cin.good() || *line < 5 || *line>8) {
			cct_gotoxy(0, 1);
			cout << "���벻�Ϸ�������������";
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
			cout << "������������5-10����";
			while (1) {//����������Ƿ���ȷ
				cct_gotoxy(20, 1);
				cin >> *column;
				if (!cin.good() || *column < 5 || *column>10) {
					cct_gotoxy(0, 2);
					cout << "���벻�Ϸ�������������";
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
			cout << "������ϳ�Ŀ�꣨5-20����";
			while (1) {
				cct_gotoxy(24, 2);
				cin >> *target;
				if (!cin.good() || *target < 5 || *target>20) {
					cct_gotoxy(0, 3);
					cout << "���벻�Ϸ�������������";
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
�������ƣ�star_array_setup(...)
����������
�������ܣ��������������ֵ������ɫ������ȵĺϳ�10�����ڲ�ֵ�ĳ�ʼ��
��������ֵ����ʼ��ֻ��1-3�������ڲ�ֵ
����˵����

*********************************************************************/
void merge_array_setup(int line, int column, int star_array[][MERGE_MAX_SCALE])
{
	/*��ʼ��Ҫ�������1-3�ȸ��ʵ����֣�ÿ�β���ͬ*/
	srand((unsigned int)(time(0)));//���������������
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			star_array[i][j] = rand() % 3 + 1;
		}
	}

}
/********************************************************************
�������ƣ�full_version_gmw_merge_ten()
����������
�������ܣ����Ƴ�ʼ�ϳ�ʮ��ͼ��
��������ֵ��
����˵��������gmw��������

*********************************************************************/
void full_version_gmw_merge_ten(int line,int column,int array[][MERGE_MAX_SCALE],int target)
{
	//����һ�������������ɫ����ɫ�Ľṹ�����顣
	const BLOCK_DISPLAY_INFO bdi_merge_ten[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0����ʾ���ÿո���伴��
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
		{101,  COLOR_BLUE,COLOR_HWHITE, "1"},//�ڲ�ֵ+100��ʾ����
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
		 {113,  COLOR_BLUE, COLOR_HWHITE, "13"},	//1��ʾ��һ���� ����ɫ������ͬ
		{114, COLOR_GREEN, COLOR_HWHITE, "14"},
		{115,  COLOR_CYAN,COLOR_HWHITE, "15"},
		{116,  COLOR_RED, COLOR_HWHITE, "16"},
		{117,  COLOR_PINK, COLOR_HWHITE, "17"},
		 {118,  COLOR_YELLOW, COLOR_HWHITE, "18"},
		 {119,  COLOR_HBLUE, COLOR_HWHITE, "19"},
		{120, COLOR_RED, COLOR_HWHITE, "20"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};//ֵΪ1-5����ͬ����ɫ 11-15������
	CONSOLE_GRAPHICS_INFO merge_CGI; //����һ��CGI����
	char temp[256] = " ";
	gmw_init(&merge_CGI);
	//��ȫ��������˵��ߣ�ɫ���С�߿�Ҳ����˵��ߣ�
	gmw_set_frame_default_linetype(&merge_CGI, 2);
	gmw_set_block_default_linetype(&merge_CGI, 2);
	gmw_set_rowcol(&merge_CGI, line, column);
	gmw_set_frame_style(&merge_CGI, 6, 3);//ɫ����ָ��߸�3��6
	//��Ҫ�޸ĵ�����Ϸ�������ɫ����Ϸ�����и����������
	//Ҫ��Ϊ��ʾ�б���б�
	gmw_set_rowno_switch(&merge_CGI, true);							//��ʾ�к�
	gmw_set_colno_switch(&merge_CGI, true);
	//�����Ϊ���ָ��ߵİ汾
	gmw_set_block_border_switch(&merge_CGI, true);
	//��������Ϸ����Ϊ����ɫ��ɫ����ɫ����������
	gmw_set_frame_color(&merge_CGI, COLOR_HWHITE, COLOR_BLACK);
	//���������ʱ
	gmw_set_delay(&merge_CGI, DELAY_OF_DRAW_FRAME, 1);
	gmw_set_status_line_switch(&merge_CGI, TOP_STATUS_LINE, true);
	gmw_set_status_line_color(&merge_CGI, TOP_STATUS_LINE, COLOR_BLACK, COLOR_HWHITE, COLOR_BLACK, COLOR_HYELLOW);
	gmw_draw_frame(&merge_CGI);
	sprintf(temp, "��ǰ��Ļ����Ϊ��%d��%d��", merge_CGI.lines, merge_CGI.cols);
	gmw_status_line(&merge_CGI, TOP_STATUS_LINE, temp);
	//ɫ�������ɫ���û�ɫ�麯��ʱ�Ÿ� 
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1], bdi_merge_ten);
		}
	}
	//��ʼʹ�������̲���
	//��ʼʹ�ü���������
	int loop = 1;
	int maction, mrow = -1, mcol = -1;
	int oldrow = -9, oldcol = -9;
	int regline = 0, regcol = 0;
	int keycode1, keycode2;
	int ret;
	int all_score = 0;//�ܵ÷�
	int record_inner = 0;
	int tempmax = 0;
	
	while (loop) {
		gmw_set_status_line_color(&merge_CGI, TOP_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		//�����ж���Ϸ�Ƿ�����ˣ������������״̬�����������Ϣ��
		if (judge_is_over(line, column, array) == 0) {
			
			gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "��Q�˳�                              ","�޿ɺϲ�����,��Ϸ����!");
			while (1) {
				int x = getchar();
				if (x == 'Q' || x == 'q')
					break;
			}
			break;
		}
		int per_score = 0;//���ε÷�
		int succenum = 0;//����������ɫ������
		gmw_set_status_line_color(&merge_CGI, TOP_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		//��Ϸ�ǲ�������ģ�Ҫÿ������֮�����²����µ��������һ��Ŀ���ȷ���Ƿ������һ�κϳ�
		ret = gmw_read_keyboard_and_mouse(&merge_CGI, maction, mrow, mcol, keycode1, keycode2);
		//������mrowΪ��ʾ�������У�ʵ�������е����ж�Ҫ����+1
		if (ret == CCT_MOUSE_EVENT) {
			if (maction == MOUSE_ONLY_MOVED) {

				//��ȡ����һ����λ�õķ���
				if (oldrow != -9) {
					gmw_draw_block(&merge_CGI, oldrow, oldcol,array[oldrow + 1][oldcol + 1], bdi_merge_ten);
				}
				//�����Ϸ�λ�ý�ɫ�鷴�ԣ�
				gmw_draw_block(&merge_CGI, mrow, mcol, array[mrow + 1][mcol + 1] % 50 + 100, bdi_merge_ten);
				oldrow = mrow;
				oldcol = mcol;

				//�ƶ���״̬����ʾ����ǰλ�ã�
			}
			else if (maction == MOUSE_LEFT_BUTTON_CLICK) {//����Ļ���Ҫ����
				{
					//�����ж�������µĵط��ܷ�����
					int accept = digui_find(mrow + 1, mcol + 1, array, line, column);
					//��һ�����Ҫ�����д���1000����Ա�ʾ
					for (int i = 0; i < line; i++) {
						for (int j = 0; j < column; j++) {

							if (array[i + 1][j + 1] > 1000) {
								gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] % 100 + 100, bdi_merge_ten);//���Ա�ʾ
							}
						}
					}
					gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
					gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
					if (accept == 0) {
						//��״̬����ӡ��������
						gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
						gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "��ͷ��/����ƶ����س���/�������ѡ��", "��Χ����ֵͬ");
						continue;
					}
					oldrow = mrow;
					oldcol = mcol;//��¼��һ��������ʱѡ�е�����λ��
					ret = gmw_read_keyboard_and_mouse(&merge_CGI, maction, mrow, mcol, keycode1, keycode2);
					if (maction == MOUSE_LEFT_BUTTON_CLICK && oldrow == mrow && oldcol == mcol) {
						//��������������������ͬһ��λ�ý��е�����
						array[mrow+1][mcol+1]=array[mrow+1][mcol+1]%100+1;//�Ȱ�ԭ��λ�ñ��+1
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								//����ȥ������֮��������
								if (array[i + 1][j + 1] > 1000) {
									gmw_draw_block(&merge_CGI, i, j, 0, bdi_merge_ten);//�Ѿ���ȥ���ڲ�ֵ����1000
									record_inner = array[i + 1][j + 1] % 100;
									array[i + 1][j + 1] = 0;//��ȥ���ڲ�����ֵ��Ϊ0
									regline = mrow + 1;//��ǵ����λ��
									regcol = mcol + 1;
									succenum++;
								}
							}
						}
						gmw_draw_block(&merge_CGI, mrow, mcol, array[mrow+1][mcol+1], bdi_merge_ten);
						Sleep(300);//������ʱ���㿴��
						//һ�ε�������������������,ʹ0ȫ���������Ϸ�
						gmw_public_downstar(line, column, array);
						/*����������ٴ�ӡһ��*/
						for (int cx = 0; cx < line; cx++) {
							for (int cy = 0; cy < column; cy++) {
								gmw_draw_block(&merge_CGI, cx, cy,array[cx + 1][cy + 1], bdi_merge_ten);
							}
						}
						per_score = succenum*record_inner*3;
						all_score += per_score;
						sprintf(temp, "���ε÷֣�%d ���ܷ�%d ,�ϳ�Ŀ��:%d        ", per_score, all_score, target);
						gmw_status_line(&merge_CGI, TOP_STATUS_LINE, temp);
						//Ȼ������regline ��regcol��λ��������һ��record_inner +1��ɫ��
						srand((unsigned int)(time(0)));//���������������,���ɵ�����������Ա�����ԭ�е�ֵ��
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
								gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] % 100, bdi_merge_ten);//����ʾһ��
							}
						}
					}
					else {
						//������һ�ε������ƿ���
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								if (array[i + 1][j + 1] > 100) {
									array[i + 1][j + 1] %= 20;
								}
							}
						}
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] , bdi_merge_ten);//������ʾ
							}
						}
					}
				}

			}
		}
		else { //CCT_KEYBOARD_EVENT - ������뺬��ȥ�� cmd_console_tools.cpp
			//���̲���
			//��ʼ���ü��̲���
			if (oldrow == -9) {
				mrow = 1;
				mcol = 1;
				oldrow = 1;
				oldcol = 1;
			}
			switch (keycode1) {
				case 13:	//�س���
					//���λ�úϷ����ȷ��Ե�ǰɫ��
					if (mrow >= 0 && mrow < line && mcol >= 0 && mcol < column) {
						//�����ж�������µĵط��ܷ�����
						int accept = digui_find(mrow + 1, mcol + 1, array, line, column);
						//��һ�����Ҫ�����д���1000����Ա�ʾ
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {

								if (array[i + 1][j + 1] > 1000) {
									gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] % 100 + 100, bdi_merge_ten);//���Ա�ʾ
								}
							}
						}
						gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
						gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
						if (accept == 0) {
							//��״̬����ӡ��������
							gmw_set_status_line_color(&merge_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, "��ͷ��/����ƶ����س���/�������ѡ��", "��Χ����ֵͬ");
							continue;
						}
						else {
							//�ٴλس�����������
							oldrow = mrow;
							oldcol = mcol;//��¼��һ��������ʱѡ�е�����λ��
							ret = gmw_read_keyboard_and_mouse(&merge_CGI, maction, mrow, mcol, keycode1, keycode2);
							if (keycode1 == 13 && oldrow == mrow && oldcol == mcol) {
								//��������������������ͬһ��λ�ý��е�����
								array[mrow + 1][mcol + 1] = array[mrow + 1][mcol + 1] % 100 + 1;//�Ȱ�ԭ��λ�ñ��+1
								gmw_draw_block(&merge_CGI, mrow, mcol, array[mrow + 1][mcol + 1], bdi_merge_ten);
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {

										if (array[i + 1][j + 1] > 1000) {
											gmw_draw_block(&merge_CGI, i, j, 0, bdi_merge_ten);//�Ѿ���ȥ���ڲ�ֵ����1000
											record_inner = array[i + 1][j + 1] % 100;
											regline = mrow + 1;//��ǵ����λ��
											regcol = mcol+ 1;
											array[i + 1][j + 1] = 0;//��ȥ���ڲ�����ֵ��Ϊ0
											succenum++;
										}
									}
								}
								Sleep(300);//������ʱ���㿴��
								//һ�ε�������������������,ʹ0ȫ���������Ϸ�
								gmw_public_downstar(line, column, array);
								/*����������ٴ�ӡһ��*/
								for (int cx = 0; cx < line; cx++) {
									for (int cy = 0; cy < column; cy++) {
										gmw_draw_block(&merge_CGI, cx, cy, array[cx + 1][cy + 1], bdi_merge_ten);
									}
								}
								Sleep(2);
								per_score = succenum * record_inner * 3;
								all_score += per_score;
								sprintf(temp, "���ε÷֣�%d ���ܷ�%d ,�ϳ�Ŀ��:%d          ", per_score, all_score,target);
								gmw_status_line(&merge_CGI, TOP_STATUS_LINE, temp);
								//Ȼ������regline ��regcol��λ��������һ��record_inner +1��ɫ��
								srand((unsigned int)(time(0)));//���������������,���ɵ�����������Ա�����ԭ�е�ֵ��
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
										gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1] % 100, bdi_merge_ten);//����ʾһ��
									}
								}
							}
							else {
								//�س�һ�ε������ƿ���
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										if (array[i + 1][j + 1] > 100) {
											array[i + 1][j + 1] %= 20;//�ָ�ԭ״
										}
									}
								}
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										gmw_draw_block(&merge_CGI, i, j, array[i + 1][j + 1], bdi_merge_ten);//������ʾ
									}
								}
							}
						}

					}
				case 224://��ͷ��
					//��ͷ�ƿ���ʱ��Ҫȡ������
					if (oldrow != -9) {
						gmw_draw_block(&merge_CGI, oldrow, oldcol, array[oldrow + 1][oldcol + 1], bdi_merge_ten);
					}
					switch (keycode2) {
						case KB_ARROW_UP://�ϼ�ͷ
							if (mrow > 0)
								mrow -= 1;
							else
								mrow = line - 1;
							//ͬʱ��״̬����ʼ���
							sprintf(temp, "��ǰ���̣�%d��%d��", mrow, mcol);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_DOWN://�¼�ͷ
							if (mrow < line - 1)
								mrow += 1;
							else
								mrow = 0;
							sprintf(temp, "��ǰ���̣�%d��%d��", mrow, mcol);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_LEFT://���ͷ
							if (mcol > 0)
								mcol -= 1;
							else
								mcol = column - 1;
							sprintf(temp, "��ǰ���̣�%d��%d��", mrow, mcol);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_RIGHT:
							if (mcol < column - 1)
								mcol += 1;
							else
								mcol = 0;
							sprintf(temp, "��ǰ���̣�%d��%d��", mrow, mcol);
							gmw_status_line(&merge_CGI, LOWER_STATUS_LINE, temp);
							break;
					}
					oldrow = mrow;
					oldcol = mcol;
					//Ȼ����Ҫ����ǰɫ�췴��
					gmw_draw_block(&merge_CGI, mrow, mcol, array[mrow + 1][mcol + 1] % 100 + 100, bdi_merge_ten);//���Ա�ʾ
					break;
			}//end of switch*/
		}//end of else
		//�������鿴���Ƿ�ϳ���Ŀ�ꣻ
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				if (array[i + 1][j + 1] ==target) {
					
					sprintf(temp, "�Ѿ��ϳɵ�%d", target);
					gmw_status_line(&merge_CGI, LOWER_STATUS_LINE,"���س���/����������������Ŀ�����", temp);
					target++;//Ŀ���һ,�Ѿ��ϳ��˵�ǰ��Ŀ�ꣻ
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