/*2052316 ��07 ��t��*/
#define _CRT_SECURE_NO_WARNINGS
/* -----------------------------------------
	 ���ļ����ܣ�
	1��������������gmw��������ɵ��޷ָ��߰汾
	2�����ļ��еĺ���Ϊ˽�к�������main����
	3.ע������ʱ�����ƣ������������ʵ������������������
   ----------------------------------------- */
   /**************************************************************************
   �������ƣ�get_line_column
   �������� ����ָ�����
   �������� ��øı��к��е�ֵ
   ��������ֵ ��
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
		cout << "������������8-10����";
		cin >> *line;
		if (!cin.good() || *line < 8 || *line>10) {
			cct_gotoxy(0, 1);
			cout << "���벻�Ϸ�������������";
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
			cout << "������������8-10����";
			while (1) {//����������Ƿ���ȷ
				cct_gotoxy(20, 1);
				cin >> *column;
				if (!cin.good() || *column < 8 || *column>10) {
					cct_gotoxy(0, 2);
					cout << "���벻�Ϸ�������������";
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
�������ƣ�star_array_setup(...)
����������
�������ܣ��������������ֵ������ɫ������ȵ�������������
��������ֵ��
����˵����

*********************************************************************/
void star_array_setup(int line, int column, int star_array[STARMAX][STARMAX])
{
	/*��Ҫ�������1-5�ȸ��ʵ����֣�ÿ�β���ͬ*/
	srand((unsigned int)(time(0)));//���������������
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			star_array[i][j] = rand() % 5 + 1;
		}
	}

}
/********************************************************************
�������ƣ�gmw_popstar_full_version(...)
����������
�������ܣ���gmw�����������������
��������ֵ��
����˵������Ϸ��ܵ�����ֵ�ɴ������line��column�õ���

*********************************************************************/
int gmw_popstar_full_version(int line,int column,int star_array[][STARMAX] )
{
	//����һ�������������ɫ����ɫ�Ľṹ�����顣
	const BLOCK_DISPLAY_INFO bdi_popstar[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0����ʾ���ÿո���伴��
		{1,  COLOR_BLUE, COLOR_BLACK, "��"},	//1��ʾ��һ���� ����ɫ������ͬ
		{2, COLOR_RED, COLOR_BLACK, "��"},
		{3,  COLOR_PINK,COLOR_BLACK, "��"},
		{4,  COLOR_CYAN, COLOR_BLACK, "��"},
		{5,  COLOR_HRED, COLOR_BLACK, "��"},
		{10, COLOR_HWHITE, COLOR_HWHITE, "  "},
		{11,  COLOR_BLUE, COLOR_HWHITE, "��"},	//�ڲ�ֵ+10��ʾ����
		{12, COLOR_RED, COLOR_HWHITE, "��"},
		{13,  COLOR_PINK,COLOR_HWHITE, "��"},
		{14,  COLOR_CYAN, COLOR_HWHITE, "��"},
		{15,  COLOR_HRED, COLOR_HWHITE, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};//ֵΪ1-5����ͬ����ɫ 11-15������
	CONSOLE_GRAPHICS_INFO popstar_CGI; //����һ��CGI����
	char temp[256] = " ";
	//9*9��16*16��16*30 �ʵ��Ŵ���18*32
	/*��ȱʡֵ��ʼ�������ڱ�����/ǰ���ף�����16*8�����������޶������У�����״̬�����У����к�/�б꣬�������Ϊ˫�ߣ�ɫ����2/�߶�1/��С�߿���ɫ�ԣ�*/
	gmw_init(&popstar_CGI);
	//���ָ���
	gmw_set_rowcol(&popstar_CGI, line, column);
	gmw_set_frame_style(&popstar_CGI, 6, 3);//ɫ����ָ��߸�3��6
	//��Ҫ�޸ĵ�����Ϸ�������ɫ����Ϸ�����и����������
	//Ҫ��Ϊ��ʾ�б���б�
	gmw_set_rowno_switch(&popstar_CGI, true);							//��ʾ�к�
	gmw_set_colno_switch(&popstar_CGI, true);	
	//�����Ϊ���ָ��ߵİ汾
	gmw_set_block_border_switch(&popstar_CGI, true);
	//��������Ϸ����Ϊ����ɫ��ɫ����ɫ����������
	gmw_set_frame_color(&popstar_CGI, COLOR_HWHITE, COLOR_BLACK);
	//���������ʱ
	gmw_set_delay(&popstar_CGI, DELAY_OF_DRAW_FRAME, 1);
	gmw_set_status_line_switch(&popstar_CGI, TOP_STATUS_LINE, true);
	gmw_set_status_line_color(&popstar_CGI, TOP_STATUS_LINE, COLOR_BLACK, COLOR_HWHITE, COLOR_BLACK, COLOR_HYELLOW);
	gmw_draw_frame(&popstar_CGI);
	sprintf(temp, "��ǰ��Ļ����Ϊ��%d��%d��", popstar_CGI.lines, popstar_CGI.cols);
	gmw_status_line(&popstar_CGI, TOP_STATUS_LINE, temp);
	
	//ɫ�������ɫ���û�ɫ�麯��ʱ�Ÿ� 
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			gmw_draw_block(&popstar_CGI, i, j,star_array[i+1][j+1], bdi_popstar);
		}
	}
	//��ʼʹ�ü���������
	int loop = 1;
	int maction, mrow = -1, mcol = -1;
	int oldrow = -9, oldcol = -9;
	int keycode1, keycode2;
	int ret;
	int all_score = 0;//�ܵ÷�
	while (loop) {
		int per_score = 0;//���ε÷�
		int succenum = 0;//����������ɫ������
		gmw_set_status_line_color(&popstar_CGI, TOP_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
		if (judge_is_over(line, column, star_array) == 0) {
			//��Ϸ����
			int left=cal_left_num(line, column, star_array);
			int reward = 0;
			if (left < 10) {
				reward = 180 * (10 - left);
				all_score += reward;
			}
			sprintf(temp, "ʣ��%d��δ���������%d��,�ܵ÷�%d��", left, reward,all_score);
			gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE,"��Ϸ���������س���������һ��,", temp);
			break;
		}
		ret = gmw_read_keyboard_and_mouse(&popstar_CGI, maction, mrow, mcol, keycode1, keycode2);
		//������mrowΪ��ʾ�������У�ʵ�������е����ж�Ҫ����+1
		if (ret == CCT_MOUSE_EVENT) {
			if (maction == MOUSE_ONLY_MOVED) {
				
				//��ȡ����һ����λ�õķ���
				if (oldrow != -9) {
					gmw_draw_block(&popstar_CGI, oldrow, oldcol, star_array[oldrow+ 1][oldcol + 1], bdi_popstar);
				}
				//�����Ϸ�λ�ý�ɫ�鷴�ԣ�
				gmw_draw_block(&popstar_CGI, mrow, mcol, star_array[mrow + 1][mcol + 1]%100+10, bdi_popstar);
				oldrow = mrow;
				oldcol = mcol;
				
				//�ƶ���״̬����ʾ����ǰλ�ã�
			}
			else if (maction== MOUSE_LEFT_BUTTON_CLICK) {//����Ļ���Ҫ����
				{
					//�����ж�������µĵط��ܷ�����
					int accept=digui_find(mrow + 1, mcol + 1, star_array, line, column);
					//��һ�����Ҫ�����д���1000����Ա�ʾ
					for (int i = 0; i < line; i++) {
						for (int j = 0; j < column; j++) {

							if (star_array[i + 1][j + 1] > 1000) {
								gmw_draw_block(&popstar_CGI, i, j,star_array[i+1][j+1]%100+10, bdi_popstar);//���Ա�ʾ
							}
						}
					}
					gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
					gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
					if (accept == 0) {
						//��״̬����ӡ��������
						gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
						gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE,"��ͷ��/����ƶ����س���/�������ѡ��","��Χ����ֵͬ");
						continue;
					}
					oldrow = mrow;
					oldcol = mcol;//��¼��һ��������ʱѡ�е�����λ��
					ret = gmw_read_keyboard_and_mouse(&popstar_CGI, maction, mrow, mcol, keycode1, keycode2);
					if (maction == MOUSE_LEFT_BUTTON_CLICK && oldrow == mrow && oldcol == mcol) {
						//��������������������ͬһ��λ�ý��е�����
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {

								if (star_array[i+1][j+1] > 1000) {
									gmw_draw_block(&popstar_CGI, i, j, 0, bdi_popstar);//�Ѿ���ȥ���ڲ�ֵ����1000
									star_array[i + 1][j + 1] = 0;//��ȥ���ڲ�����ֵ��Ϊ0
									succenum++;
								}
							}
						}
						//һ�ε�������������������,ʹ0ȫ���������Ϸ�
						gmw_downstar(line, column, star_array, &popstar_CGI);
						/*����������ٴ�ӡһ��*/
						for (int cx = 0; cx < line; cx++) {
							for (int cy = 0; cy < column; cy++) {
								gmw_draw_block( &popstar_CGI, cx, cy, star_array[cx + 1][cy + 1], bdi_popstar);
							}
						}
						Sleep(2);
						per_score = succenum * succenum * 5;
						all_score += per_score;
						sprintf(temp, "���������÷�%d�֣��ܵ÷�%d��", per_score, all_score);
						gmw_status_line(&popstar_CGI, TOP_STATUS_LINE, temp);
						
					}
					else {
						//�Ż�����һ���������˵������ƿ���
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								if (star_array[i + 1][j + 1] > 10) {
									star_array[i + 1][j + 1] %= 10;
								}
							}
						}
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {
								gmw_draw_block(&popstar_CGI, i, j, star_array[i + 1][j + 1], bdi_popstar);//������ʾ
							}
						}
					}
				}
				
			}
		}
		else { //CCT_KEYBOARD_EVENT - ������뺬��ȥ�� cmd_console_tools.cpp
			//���̲���
			switch (keycode1) {
				case 13:	//�س���
					//���λ�úϷ����ȷ��Ե�ǰɫ��
					if(mrow>=0&&mrow<line&&mcol>=0&&mcol<column){
						//�����ж�������µĵط��ܷ�����
						int accept = digui_find(mrow + 1, mcol + 1, star_array, line, column);
						//��һ�����Ҫ�����д���1000����Ա�ʾ
						for (int i = 0; i < line; i++) {
							for (int j = 0; j < column; j++) {

								if (star_array[i + 1][j + 1] > 1000) {
									gmw_draw_block(&popstar_CGI, i, j, star_array[i + 1][j + 1] % 100 + 10, bdi_popstar);//���Ա�ʾ
								}
							}
						}
						gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
						gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
						if (accept == 0) {
							//��״̬����ӡ��������
							gmw_set_status_line_color(&popstar_CGI, LOWER_STATUS_LINE, 0, 7, 0, COLOR_HYELLOW);
							gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, "��ͷ��/����ƶ����س���/�������ѡ��", "��Χ����ֵͬ");
							continue;
						}
						else {
							//�ٴλس�����������
							oldrow = mrow;
							oldcol = mcol;//��¼��һ��������ʱѡ�е�����λ��
							ret = gmw_read_keyboard_and_mouse(&popstar_CGI, maction, mrow, mcol, keycode1, keycode2);
							if (keycode1==13 && oldrow == mrow && oldcol == mcol) {
								//��������������������ͬһ��λ�ý��е�����
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {

										if (star_array[i + 1][j + 1] > 1000) {
											gmw_draw_block(&popstar_CGI, i, j, 0, bdi_popstar);//�Ѿ���ȥ���ڲ�ֵ����1000
											star_array[i + 1][j + 1] = 0;//��ȥ���ڲ�����ֵ��Ϊ0
											succenum++;
										}
									}
								}
								//һ�ε�������������������,ʹ0ȫ���������Ϸ�
								gmw_downstar(line, column, star_array, &popstar_CGI);
								/*����������ٴ�ӡһ��*/
								for (int cx = 0; cx < line; cx++) {
									for (int cy = 0; cy < column; cy++) {
										gmw_draw_block(&popstar_CGI, cx, cy, star_array[cx + 1][cy + 1], bdi_popstar);
									}
								}
								Sleep(2);
								per_score = succenum * succenum * 5;
								all_score += per_score;
								sprintf(temp, "���������÷�%d�֣��ܵ÷�%d��", per_score, all_score);
								gmw_status_line(&popstar_CGI, TOP_STATUS_LINE, temp);
								//Ȼ��Ҫ�ڵ����λ������һ���µ�����+1�ķ��飬��������Ϊ0λ�������ֵ���
							}
							else {
								//�Ż�����һ���������˵������ƿ���
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										if (star_array[i + 1][j + 1] > 10) {
											star_array[i + 1][j + 1] %= 10;
										}
									}
								}
								for (int i = 0; i < line; i++) {
									for (int j = 0; j < column; j++) {
										gmw_draw_block(&popstar_CGI, i, j, star_array[i + 1][j + 1], bdi_popstar);//������ʾ
									}
								}
							}
						}
					
					}
					break;
				case 224://��ͷ��
					//��ͷ�ƿ���ʱ��Ҫȡ������
					if (oldrow != -9) {
						gmw_draw_block(&popstar_CGI, oldrow, oldcol, star_array[oldrow + 1][oldcol + 1], bdi_popstar);
					}
					switch (keycode2) {
						case KB_ARROW_UP://�ϼ�ͷ
							if (mrow>0)
								mrow-= 1;
							else
								mrow = line-1;
							//ͬʱ��״̬����ʼ���
							sprintf(temp, "��ǰ���̣�%d��%d��", mrow,mcol);
							gmw_status_line(&popstar_CGI,LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_DOWN://�¼�ͷ
							if (mrow < line-1)
								mrow += 1;
							else
								mrow = 0;
							sprintf(temp, "��ǰ���̣�%d��%d��", mrow, mcol);
							gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_LEFT://���ͷ
							if (mcol > 0)
								mcol-= 1;
							else
								mcol = column-1;
							sprintf(temp, "��ǰ���̣�%d��%d��", mrow, mcol);
							gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, temp);
							break;
						case KB_ARROW_RIGHT:
							if (mcol< column-1)
								mcol += 1;
							else
								mcol = 0;
							sprintf(temp, "��ǰ���̣�%d��%d��", mrow, mcol);
							gmw_status_line(&popstar_CGI, LOWER_STATUS_LINE, temp);
							break;
					}
					oldrow = mrow;
					oldcol = mcol;
					//Ȼ����Ҫ����ǰɫ�췴��
					gmw_draw_block(&popstar_CGI, mrow, mcol, star_array[mrow + 1][mcol + 1] % 100 + 10, bdi_popstar);//���Ա�ʾ
					break;
			}//end of switch*/
		}//end of else
		//���ε÷���succenum*succenum*5
		
		
	}//end of while
	return all_score;
}



/*�������ƣ�gmw_downstar
�������ܣ�ÿ�����һ�������Ч����󣬽��ڲ������������У�ʹ����������*/
void gmw_downstar(int line, int column, int star_array[][STARMAX], CONSOLE_GRAPHICS_INFO* pCGI)
{
	const BLOCK_DISPLAY_INFO bdi_popstar[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0����ʾ���ÿո���伴��
		{1,  COLOR_BLUE, COLOR_BLACK, "��"},	//1��ʾ��һ���� ����ɫ������ͬ
		{2, COLOR_RED, COLOR_BLACK, "��"},
		{3,  COLOR_PINK,COLOR_BLACK, "��"},
		{4,  COLOR_CYAN, COLOR_BLACK, "��"},
		{5,  COLOR_HRED, COLOR_BLACK, "��"},
		{10, COLOR_HWHITE, COLOR_HWHITE, "  "},
		{11,  COLOR_BLUE, COLOR_HWHITE, "��"},	//�ڲ�ֵ+10��ʾ����
		{12, COLOR_RED, COLOR_HWHITE, "��"},
		{13,  COLOR_PINK,COLOR_HWHITE, "��"},
		{14,  COLOR_CYAN, COLOR_HWHITE, "��"},
		{15,  COLOR_HRED, COLOR_HWHITE, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};//ֵΪ1-5����ͬ����ɫ 11-15������
	//�ȼ��ÿһ�У��������ϼ�顢
	for (int i = 1; i <= column; i++) {
		for (int j = line; j > 1; j--) {
			if (star_array[j][i] == 0) {//��¼��һ��Ϊ0��λ��
				int successive_num = 0;//����һ������������ͬɫ��ı���
				int l = j;//��¼��һ��Ϊ0��λ��
				for (; star_array[l][i] == 0 && l > 1; l--) {
					successive_num++;
				}
				for (; j - successive_num >= 1; j--) {
					star_array[j][i] = star_array[j - successive_num][i];
					//��Ҫ��ӡ����Ч����
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
		/*Ȼ���ټ����һ�е�Ϊ0����������ȷ��0��������*/
		for (int j = line; j > 1; j--) {
			if (star_array[j][i] == 0) {//��¼��һ��Ϊ0��λ��
				int successive_num = 0;//����һ������������ͬɫ��ı���
				int l = j;//��¼��һ��Ϊ0��λ��
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

	//Ȼ�����Ƿ���һ����Ϊ0������У���Ҫ��������һ������
	//ƽ��һ����Ҫע���Ƿ��ж���ͬʱΪ0�������
	int successive_col = 0;//��¼�����Ŀ��еĸ���
	int first_col = 0;//��¼��һ��Ϊ0���б�
	int whole = 0;//����������Ϊ���е�����
	for (int i = 1; i <= column; i++) {
		if (star_array[line][i] == 0) {
			whole++;
		}
	}
	while (1) {
		int ip;
		for (ip = 1; ip < column; ip++) {//���һ��Ϊ0����ƽ��
			if (star_array[line][ip] == 0) {
				first_col = ip;
				break;
				/*successive_col++;
				if (star_array[line][i + 1] != 0) {
					break;
				}*/
			}
		}/*���ڼ����Ƿ���ܴ��ڶ�������Ϊ0�����*/
		if (ip == column - whole + 1 || ip == column) {
			break;//˵���������һ�У�Ҳû���ҵ�����������
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
		}/*��������*/
		/*�����������������*/

	}
	//������whole�ĸ������������ұ߲�����Ϊ0��
	for (int a = 0; whole > 0; a++) {
		for (int b = 1; b <= line; b++) {
			star_array[b][column - a] = 0;
		}
		whole--;
	}
}
/****************************************************************************
�������ƣ�cal_left_num
����������
�������ܣ�����ʣ����ٸ����ǣ��������ٷ���
��������ֵ��
****************************************************************************/
int cal_left_num(int line, int column, int array[][STARMAX])
{
	int num_left = 0;
	for (int i = 1; i <= line; i++) {
		//��Ҫ����������
		for (int j = 1; j <= column; j++) {
			if (array[i][j] != 0) {
				num_left++;
			}
		}
	}
	return num_left;
	//��״̬��Ҫ��ӡʣ���������
}
void pause_enter(const char* prompt)
{
	//cout << "���س������������������...";
	if (prompt != NULL)
		cout << prompt;
	while (_getch() != '\r')
		;
	return;
}