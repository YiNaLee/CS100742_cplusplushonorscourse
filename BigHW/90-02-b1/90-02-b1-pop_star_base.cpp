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
�������ܣ�
��������ֵ��
****************************************************************************/
/****************************************************************************
�������ƣ�puase_enter()
����������
�������ܣ�����س������������������
��������ֵ��
****************************************************************************/
void pause_enter(const char*prompt)
{
	//cout << "���س������������������...";
	cout << prompt;
	while (_getch() != '\r')
		;
	return;
}
/****************************************************************************
�������ƣ�cin_end_to_continue()
����������
�������ܣ��˵������ʱ������end��ȷ����С��Ľ���
��������ֵ��
****************************************************************************/
void cin_end_to_continue()
{
	char shuru[20] = "0";
	
	while (1) {
		cin.ignore(65536, '\n');
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
/****************************************************************************
�������ƣ�char to_confirm_eliminate(int*li,int *co)
����������li,co
�������ܣ���ȡ����ָ��Ƿ�����
��������ֵ��Y/N/Q
****************************************************************************/
char to_confirm_eliminate(int*li,int *co)
{
	char confirm;
	cout << "��ȷ���Ƿ��" << (char)(*li + 'A') << *co << "����Χ����ֵͬ����(Y/N/Q):";
	while (1) {
		confirm= _getch();
		if (confirm == 'y' || confirm == 'Y' || confirm == 'n' || confirm == 'N' || confirm == 'q' || confirm == 'Q') {
			putchar(confirm);
			if (confirm == 'y' || confirm == 'q' || confirm == 'n') {
				confirm -= 32;//ͳһת�ɴ�д��ĸ;
			}
			break;
		}


	}
	return confirm;
}


/**************************************************************************
�������ƣ�get_line_column
�������� ����ָ�����
�������� ��øı��к��е�ֵ
��������ֵ ��
*****************************************************************************/
void get_line_column(int* line, int* column)
{
	while (1) {
		cct_gotoxy(0, 0);
		cout << "������������8-10����";
		cin >> *line;
		if (!cin.good() || *line < 8 || *line>10) {
			cct_gotoxy(0, 1);
			cout << "���벻�Ϸ�������������";
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
			cout << "������������8-10����";
			while (1) {//����������Ƿ���ȷ
				cct_gotoxy(20, 1);
				cin >> *column;
				if (!cin.good() || *column < 8 || *column>10) {
					cct_gotoxy(0,2);
					cout << "���벻�Ϸ�������������";
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
�������ƣ�star_array_setup(int*line,int*column)
����������&column,&line
�������ܣ��������������ֵ������ɫ������ȵ�������������
��������ֵ��
����˵����

*********************************************************************/
void star_array_setup(int line, int column,int star_array[STAR_MAX][STAR_MAX])
{
	/*��Ҫ�������1-5�ȸ��ʵ����֣�ÿ�β���ͬ*/
	srand((unsigned int)(time(0)));//���������������
	for (int i = 1; i <=line; i++) {
		for (int j = 1; j <= column; j++) {
			star_array[i][j] = rand() % 5 + 1;
		}
	}

}
/****************************************************************************
�������ƣ�print_prililary()
����������line column star_array[][]
��������:��ӡ���鶼������һ��������
��������ֵ�����ε÷�
****************************************************************************/

int print_primilary(int line,int column,int star_array[STAR_MAX][STAR_MAX],const char *prompt)
{
	int per_score = 0;//���ڼ��㵥�ε÷֣�
	int num = 0;//���ڼ���ÿ�������ĸ���
	if (prompt) {
		cout << prompt << endl;
	}
	//cout << "��ǰ���飺\n";
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
	/*���������ÿ�У�*/
	for (int i = 0; i < line; i++) {
		putchar('A' + i);
		cout << " |";
		for (int j = 0; j < column; j++) {
			if (prompt == "��ǰ���飨��ͬɫ��ʶ����"||prompt=="��ֵͬ�鲢������飨��ͬɫ��ʶ��:"
				   ||prompt== "����������:") {
				if (star_array[i + 1][j + 1] > 5||star_array[i+1][j+1]==0) {//�������
					star_array[i + 1][j + 1] %= 100;
					if (prompt == "��ֵͬ�鲢������飨��ͬɫ��ʶ��:") {
						if (star_array[i + 1][j + 1] != 0) {
							num++;
						}
						star_array[i + 1][j + 1] = 0;//�鲢����Ϊ0�����
					}
					cout << setw(2)<< " ";
					cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);//���ø���
					cout << star_array[i + 1][j + 1];
					//������������ֻ�Ǳ����ͬɫ�飬��Ҫ��ԭ��100+
					//�����y������ť����˵����ɫ���Ѿ�����������Ȼ��Ϊ0
					if (prompt == "��ǰ���飨��ͬɫ��ʶ����") {
						star_array[i + 1][j + 1] += 100;
					}
					cct_setcolor();//�ָ�Ϊȱʡ��ɫ
				}
				else//��ͨ���
					cout << setw(3) << star_array[i + 1][j + 1];
			}
			else if (prompt == "��ǰ���飺") {
				if (star_array[i + 1][j + 1] == 0) {
					cout << setw(2) << " ";
					cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);//���ø���
					cout << star_array[i + 1][j + 1];
					cct_setcolor();//�ָ�Ϊȱʡ��ɫ
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
	return per_score;//���ε÷�
}
/****************************************************************************
�������ƣ�void cin_position()
����������int*li,in*co//�����������������λ�ã�line ��column�����Ƚ�����
�������ܣ���ȡ��Ҫ���������е�����λ��
��������ֵ��
****************************************************************************/
void cin_position(int* li, int* co, int line, int column)
{
	char Line;
	int Column;
	cout << "������ĸ+������ʽ������c2������������꣺";
	while (1) {//����������

		cin >> Line;
		if (!cin.good()) {
			cout << "�����������������.";
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (Line >= 'a' && Line <= 'a' + line - 1 || Line >= 'A' && Line <= 'A' + line - 1) {
			if (Line >= 'a' && Line <= 'a' + line - 1)
				Line -= 32;/*ȫ��ת�ɴ�д*/
			break;
		}
		cin.clear();
		cin.ignore(65536, '\n');
		cout << "�����������������.";
	}
	while (1) {
		//����������
		cin >> Column;
		if (!cin.good()) {
			cout << "�����������������.";
			/*��������������⣬��������ҲҪ���������*/
			cin.clear();
			cin.ignore(65536, '\n');
			/*��ջ����������´��п�ʼ����*/
			while (1) {//����������
				cin >> Line;
				if (!cin.good()) {
					cout << "�����������������.";
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				if (Line >= 'a' && Line <= 'a' + line - 1 || Line >= 'A' && Line <= 'A' + line - 1) {
					if (Line >= 'a' && Line <= 'a' + line - 1)
						Line -= 32;/*ȫ��ת�ɴ�д*/
					break;
				}
				cin.clear();
				cin.ignore(65536, '\n');
				cout << "�����������������.";
			}
			continue;
		}
		if (Column >= 0 && Column < column) {
			break;
		}
		/*���δ�˳���֤�������������󣬻�Ҫ����������*/
		cout << "�����������������.";
	}
	*li = Line - 'A';
	*co = Column;
	cout << "����Ϊ";
	putchar('A' + *li);
	cout << "��" << *co << "��\n";
}
/****************************************************************************
�������ƣ�
����������donghua==0��ʾ�޶���Ч����donghua==1��ʾ�ж���Ч��
�������ܣ�����������������У����м�Ϊ0�ĵط���Ȼ���䣻
��������ֵ��
****************************************************************************/
void dowm_array(int line, int column, int star_array[STAR_MAX][STAR_MAX],int donghua)
{
	//�ȼ��ÿһ�У��������ϼ�顢
	for (int i = 1; i <= column; i++) {
		for (int j = line; j > 1; j--) {
			if (star_array[j][i] == 0) {//��¼��һ��Ϊ0��λ��
				int successive_num = 0;//����һ������������ͬɫ��ı���
				int l = j;//��¼��һ��Ϊ0��λ��
				for (; star_array[l][i] == 0&&l>1; l--) {
					successive_num++;
				}
				for (; j - successive_num >= 1; j--) {
					star_array[j][i] = star_array[j - successive_num][i];
					//��Ҫ��ӡ����Ч����
					if (donghua == 1){
						Sleep(1);//��ӡһ��Ŀǰ������
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
				if (donghua == 1) {
					Sleep(1);//��ӡһ��Ŀǰ������
					draw_graph(line, column, star_array, 0);
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
		for (ip = 1; ip< column; ip++) {//���һ��Ϊ0����ƽ��
			if (star_array[line][ip] == 0) {
				first_col = ip;
				break;
				/*successive_col++;
				if (star_array[line][i + 1] != 0) {
					break;
				}*/
			}
		}/*���ڼ����Ƿ���ܴ��ڶ�������Ϊ0�����*/
		if (ip == column-whole+1||ip==column) {
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
		if (successive_col >= 1&&first_col<=column) {
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


	cout << endl;
}
/****************************************************************************
�������ƣ�cal_left_num
����������
�������ܣ�����ʣ����ٸ����ǣ��������ٷ���
��������ֵ��
****************************************************************************/
int cal_left_num(int line,int column,int array[][STAR_MAX])
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
	cct_setcolor(COLOR_HYELLOW, COLOR_RED);//���ø���
	cout << "ʣ��" << num_left << "��������������ؽ�����\n";
	cct_setcolor();/*���Ƿŵ�һ��������ȥ*/
	return num_left;
}
/****************************************************************************
�������ƣ�
����������
�������ܣ���ɲ˵���1�ķ�װ����
��������ֵ��
****************************************************************************/
void step1_base(int line,int column,int*li,int*co,int array[][STAR_MAX])
{
	//�Ӽ��̶�ȡ��Ҫ�����������±�
	print_primilary(line, column, array,"��ǰ���飺");//��ӡ��ʼ״̬�µ�����
	cin_position(li, co, line, column);//��ȡҪ������λ������
	int accept=digui_find(*li+1, *co+1, array, line, column);//ͬʱaccept�����ܷ���ֵ��
    /*����Ϊ1˵����λ�ô�����ͬ��ɫ�飬����Ϊ0˵��û����ͬɫ��*/
	while(accept == 0) {
		cout << "����ľ���λ�����괦����ֵͬ������������";
		cin_position(li, co, line, column);
		accept = digui_find(*li+1, *co+1, array, line, column);
	}
	/*������ֵ��Ϊ0��˵�����������ǡ���Ҫ���ҽ������*/
	int copy_array[12][12] = {0};
	for (int i = 1; i <=line; i++) {
		for (int j = 1; j <= column; j++) {
			if (array[i][j] >100) {
				copy_array[i][j] = 1;
			}
		}
	}
	print_primilary(line, column, copy_array, "���ҽ�����飺");
	print_primilary(line, column, array, "��ǰ���飨��ͬɫ��ʶ����");

}
/****************************************************************************
�������ƣ�
����������
�������ܣ���ɲ˵���2�ķ�װ����
          ��������һ������
��������ֵ��
****************************************************************************/
int cmd_full_eliminate(int line, int column,int*li,int *co,int array[][STAR_MAX],int canshu)
{
	int sin_score = 0;//���ε÷�
	step1_base(line, column, li, co, array);
	char choice=to_confirm_eliminate(li, co);
	cout << endl;
	if (choice == 'Y') {//ȷ��Ҫ����
		//��ӡ��ֵͬ�鲢������飺����ͬ�ĵط���Ϊ0
		sin_score=print_primilary(line, column, array, "��ֵͬ�鲢������飨��ͬɫ��ʶ��:");
		if (canshu == 2) {
			cout << "���ε÷֣�" << sin_score << "�� " << "�ܵ÷֣�" << sin_score << "��\n";
			pause_enter("���س������������������...");//���س������������䣻
			dowm_array(line, column, array,0);//����������ƶ�
			print_primilary(line, column, array, "����������:");
		}
		else if (canshu == 3) {
			cout << "���ε÷�" << sin_score << "��";
		}
		
	}
	return sin_score;
}
/****************************************************************************
�������ƣ�pass_a_pass()
����������
�������ܣ���������ѭ��ִ�����һ�أ�ֱ������ͬ�������ǿ�����
��������ֵ��
****************************************************************************/
void pass_a_pass(int line, int column, int* li, int* co, int array[][STAR_MAX])
{
	int full_score = 0;
	int reljudge = 1;
	while(reljudge){
		full_score+=cmd_full_eliminate(line, column, li, co, array,3);
		cout<<"�ܵ÷֣�" << full_score << "��\n";
		pause_enter("���س������������������...");//���س������������䣻
		dowm_array(line, column, array,0);//����������ƶ�
		print_primilary(line, column, array, "����������:");
		pause_enter("�����������������س�������һ���µ�����...");
		cout << endl;
		reljudge = judge_is_over(line, column, array);//�ж���Ϸ�Ƿ����
	}
	cal_left_num(line, column, array);

}
