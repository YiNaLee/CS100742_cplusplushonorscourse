/* ��07 2052316 ��t�� */

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

/*�������Ĺ��ܣ����һЩɨ�׺��������Ƕ���Ҫ�õ��Ĺ��ú���*/
/****************************************************************************
�������ƣ�
����������
�������ܣ�
��������ֵ��
****************************************************************************/



/****************************************************************************
�������ƣ�
����������
�������ܣ�
��������ֵ��
****************************************************************************/
/*�������ƣ�reveal()
�������ܣ�����Ҫ��һ�����򿪵������1000
�𵽱�Ǵ򿪵�����
*/
void reveal(int* number)
{
	*number =1000+(*number);
}







/****************************************************************************
�������ƣ�digui_find()
����������num1,num2Ϊ���̶�����Ҫ������λ�ã�line��columnΪ����������
�������ܣ��õݹ�ķ�ʽ�ҵ���Χ�ĸ�������ͬ�����ֲ��������
         ע����������ָ��λ�����꼰��Χ��ͬ��ĺ���������ͬ�汾���������ǿɹ��á�
��������ֵ

****************************************************************************/
int digui_find(int num1, int num2, int array[][12], int line, int column)
{
	if (array[num1][num2] == 0) {
		return 0;//����0��������ȥ
	}
	int same_color = array[num1][num2]%100;
	
	if (num1 >= 1 && num1 <= line && num2 >= 1 && num2 <= column) {
		/*if (array[num1 + 1][num2] == same_color || array[num1 - 1][num2] == same_color ||
			array[num1][num2 + 1] == same_color || array[num1][num2 - 1] == same_color) {
			//�ж�����ͬɫ�����������ֵ��ͬ�����෴
			reveal(&array[num1][num2]);//֤�����Ա���������ǣ�
			search_around(num1, num2, array, line, column);//�ݹ�Ѱ����Ҫ������������
			
			
		}*/
		if (array[num1 + 1][num2] == same_color) {
			reveal(&array[num1][num2]);//֤�����Ա���������ǣ�
			reveal(&array[num1 + 1][num2]);
			digui_find(num1 + 1, num2, array, line, column);
		}
		if (array[num1 - 1][num2] == same_color) {
			reveal(&array[num1][num2]);//֤�����Ա���������ǣ�
			reveal(&array[num1-1][num2]);
			digui_find(num1 -1, num2, array, line, column);
		}
		if (array[num1][num2-1] == same_color) {
			reveal(&array[num1][num2]);//֤�����Ա���������ǣ�
			reveal(&array[num1][num2-1]);
			digui_find(num1, num2-1, array, line, column);
		}
		if (array[num1][num2+1] == same_color) {
			reveal(&array[num1][num2]);//֤�����Ա���������ǣ�
			reveal(&array[num1][num2+1]);
			digui_find(num1, num2+1, array, line, column);
		}
	}
	
	if (array[num1][num2] < 100) {//֤�����λ�õ����ܶ�û����ɫ��ͬ�ķ���
		return 0;

	}
	return 1;//����1��˵������ط�����ȥ
	
	
}
/****************************************************************************
�������ƣ�judge_is_over(int line ,int column,int array[12][12])
����������
�������ܣ�
��������ֵ������0˵����Ϸ���������ط�0˵����Ϸδ������
****************************************************************************/
int judge_is_over(int line ,int column,int array[12][12])
{
	int judge = 0;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			judge += digui_find(i, j, array, line, column);
		}
	}
	/*����digui_find�������������˼Ӳ�����Ҫ��ԭ*/
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= column; j++) {
			array[i][j] %= 100;
		}
	}
	return judge;//���ط�0˵����Ϸδ����������0˵����Ϸ����

}
/*״̬����ӡ����*/
void status_bar_up(int sizerow, int sizecol, const int X, const int Y)
{
	cct_gotoxy(X, Y);
	cout << "��ǰ��Ļ����Ϊ" << sizerow << "��" << sizecol << "��\n";
}

/*�������ָ�����*/
void save_oldbuffer_size(int* cur_cols, int* cur_lines, int* cur_buffer_cols, int* cur_buffer_lines)
{

	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);//ȡ���л������Ĵ�С
	/* ������ֵ�����ڻָ� */
	*cur_cols = cols;
	*cur_lines = lines;
	*cur_buffer_cols = buffer_cols;
	*cur_buffer_lines = buffer_lines;
}
/****************************************************************************
�������ƣ�draw_frame
����������
�������ܣ����߿�
��������ֵ��
****************************************************************************/
void draw_frame(int length, int height,int X, int Y)
{
	cct_gotoxy(X, Y);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	/*��ӡ��һ��*/
	cout << "�X";//һ������ռ2�ֽ�
	for (int i = 0; i < length; i++) {
		cout << "�T";
	}
	cout << "�[";
	/*��ӡ�м���*/
	for (int j = 0; j < height; j++) {
		Y++;
		cct_gotoxy(X, Y);
		cout << "�U";
		for (int i = 0; i < length; i++) {
			cout << setw(2) << " ";
		}
		cout << "�U" << endl;
		Sleep(50);//����Ч��
		
	}
	/*��ӡ�����*/
	cct_gotoxy(X, Y + 1);
	cout << "�^";//һ������ռ2�ֽ�
	for (int i = 0; i < length; i++) {
		cout << "�T";
	}
	cout << "�a";

}

/****************************************************************************
�������ƣ�legal_XY()
���������������discolΪ6/8��dislineΪ3/4��startxΪ4��startyΪ3
��������:�ж����λ���Ƿ�Ϸ���
��������ֵ��0���Ϸ���1�Ϸ�
****************************************************************************/
int legal_XY(int X, int Y, int line, int column, int starty, int startx, int disline, int discol,
	int* choose_line, int* choose_col,int differ,int array[][12])
{
	cct_setcolor();
	cct_gotoxy(0, starty + disline * line + 1);
	cout << "����ǰ��꡿";
	if (Y<starty || Y>(starty + line * disline-1) || X<startx || X>startx + column * discol-1) {
		cout << "λ�÷Ƿ�" << setw(50) << " ";
		return 0;
	}
	else {
		if (differ == 0) {//���м�߽�Ĳ���Ϊ0
			/*����Ϸ�汾�л�Ҫ�ж����λ���ǲ���0������Ѿ�����������0��Ҳ��Ƿ�λ�á�*/
			*choose_col = (X - startx) / discol + 1;//��ʾ������ʵ�������е���/�У���12*12��
			*choose_line = (Y - starty) / disline + 1;
			if (array[*choose_line][*choose_col]!=0) {
				putchar('A' + *choose_line - 1);
				cout << "��" << *choose_col - 1 << "��     " << setw(50) << " ";
				return 1;//��ʾλ�úϷ�
			}
			else {
				cout << "λ�÷Ƿ�" << setw(50) << " ";
				return 0;
			}
		}
		else {
			if ((X - 3) % 8 == 0 || (X - 3) % 8 == 1 || (Y - 2) % 4 == 0) {
				cout << "λ�÷Ƿ�"<< setw(50) << " ";
				return 0;
			}
			else {
				*choose_col = (X - startx) / discol + 1;//��ʾ������ʵ�������е���/�У���12*12��
				*choose_line = (Y - starty) / disline + 1;
				putchar('A' + *choose_line - 1);
				cout << "��" << *choose_col - 1 << "��     " << setw(50) << " ";;
				return 1;//��ʾλ�úϷ�

			}

		}
	}
	return 0;

}
/*�������ƣ�gmw_downstar
�������ܣ�ÿ�����һ�������Ч����󣬽��ڲ������������У�ʹ����������*/
void gmw_public_downstar(int line, int column, int star_array[][12])
{
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
void public_pause_enter(const char* prompt)
{
	//cout << "���س������������������...";
	if (prompt != NULL)
		cout << prompt;
	while (_getch() != '\r')
		;
	return;
}
/****************************************************************************
�������ƣ�public_cin_end_to_continue()
����������
�������ܣ��˵������ʱ������end��ȷ����С��Ľ���
��������ֵ��
****************************************************************************/
void public_cin_end_to_continue()
{
	char shuru[20] = "0";

	while (1) {
		if (!cin) {//���״̬���ԣ�Ҫ����
			cin.clear();
			cin.ignore(65536, '\n');
		}
		
		cout << "��С�����������End����...";
		cin.getline(shuru, 19);
		if ((shuru[0] == 'e' || shuru[0] == 'E') && (shuru[1] == 'n' || shuru[1] == 'N') && (shuru[2] == 'd' || shuru[2] == 'D')) {
			break;
		}
		for (int i = 0; i < 20; i++) {
			shuru[i] = '0';
		}
		cin.ignore(65536, '\n');
		cout << "�����������������\n";
	}
}