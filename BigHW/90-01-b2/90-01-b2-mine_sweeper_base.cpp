/* ��07 2052316 ��t�� */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b2-mine_sweeper.h"
using namespace std;
/*���ļ����ܣ��ڲ��������غ�����ʵ��*/
/**********************************************
�������ƣ�
���������
�������ܣ�
����ֵ��
˵����
***********************************************/


/******************************************
�������ƣ�difficulty_choice
�������ܣ������ѶȲ�����ѡ��
��������ֵ���Ѷ�ѡ��1-3
******************************************/
int difficulty_choice()
{
	/*����*/
	cct_cls();
	int choice;
	cout << "��ѡ���Ѷȣ�\n";
	cout << "  1.����(9*9   - 10����)\n";
	cout << "  2.�м�(16*16 - 40����)\n";
	cout << "  3.�߼�(16*30 - 99����)\n";
	cout << "������[1..3]:\n";
	while (1)
	{
		choice = _getch();
		if (choice >= '1' && choice <= '3')
			break;
	}
	return choice - '0';
}

/**********************************************
�������ƣ�pause_enter()
���������
�������ܣ����ô˺�����ʵ�ְ��س��������Ĺ���
����ֵ��
˵����
***********************************************/
void pause_enter()
{
	cout << endl;
	cout << "���س�������...";
	while (1)
	{
		int enter = _getch();
		if (enter == '\r')
			break;
	}

}


/**********************************************
�������ƣ�cnt_array()
���������int mine[][];
�������ܣ�ͳ�Ʒ��׵���Χ���׵ĸ���
����ֵ����
˵����Ƕ��create_array��
***********************************************/
void cnt_array1(int mine1[][SCALE1], int i, int j)
{//���������ʵ������һ��ָ�룬��˶���mine2.mine3��Ȼ����ʹ�ô˱���

	if (mine1[i][j] != '*')//��Χ8��
	{
		if (mine1[i - 1][j] == '*')
			mine1[i][j]++;

		if (mine1[i + 1][j] == '*')
			mine1[i][j]++;

		if (mine1[i][j - 1] == '*')
			mine1[i][j]++;

		if (mine1[i][j + 1] == '*')
			mine1[i][j]++;

		if (mine1[i - 1][j - 1] == '*')
			mine1[i][j]++;

		if (mine1[i - 1][j + 1] == '*')
			mine1[i][j]++;

		if (mine1[i + 1][j - 1] == '*')
			mine1[i][j]++;

		if (mine1[i + 1][j + 1] == '*')
			mine1[i][j]++;
	}
}

void cnt_array2(int mine2[][SCALE2], int i, int j)
{
	if (mine2[i][j] != '*')//��Χ8��
	{
		if (mine2[i - 1][j] == '*')
			mine2[i][j]++;

		if (mine2[i + 1][j] == '*')
			mine2[i][j]++;

		if (mine2[i][j - 1] == '*')
			mine2[i][j]++;

		if (mine2[i][j + 1] == '*')
			mine2[i][j]++;

		if (mine2[i - 1][j - 1] == '*')
			mine2[i][j]++;

		if (mine2[i - 1][j + 1] == '*')
			mine2[i][j]++;

		if (mine2[i + 1][j - 1] == '*')
			mine2[i][j]++;

		if (mine2[i + 1][j + 1] == '*')
			mine2[i][j]++;
	}
}
void cnt_array3(int mine3[][SCALE3], int i, int j)
{
	if (mine3[i][j] != '*')//��Χ8��
	{
		if (mine3[i - 1][j] == '*')
			mine3[i][j]++;

		if (mine3[i + 1][j] == '*')
			mine3[i][j]++;

		if (mine3[i][j - 1] == '*')
			mine3[i][j]++;

		if (mine3[i][j + 1] == '*')
			mine3[i][j]++;

		if (mine3[i - 1][j - 1] == '*')
			mine3[i][j]++;

		if (mine3[i - 1][j + 1] == '*')
			mine3[i][j]++;

		if (mine3[i + 1][j - 1] == '*')
			mine3[i][j]++;

		if (mine3[i + 1][j + 1] == '*')
			mine3[i][j]++;
	}
}

/***************************************************************
�������ƣ�create_array
������difficulty_chioce
�������ܣ�����ɨ������ 9*9 ��16*16��16*30
��������ֵ�� ��
********************************************************************/
void create_array(int difficulty_choice, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[SCALE2][SCALE3])
{

	int i, j;
	srand((unsigned int)(time(0)));//���������������
	if (difficulty_choice == 1) {//9*9
		/*��ȷ���׵�λ��*/
		for (i = 0; i < MINE1_NUM; i++)
		{
			while (1)
			{
				int X, Y;
				X = rand() % (SCALE1 - 2) + 1;
				Y = rand() % (SCALE1 - 2) + 1;
				if (mine1[X][Y] == 0)//�����и���
				{
					mine1[X][Y] = '*';//������������е�10����
					break;
				}
				else
					continue;
			}

		}
		/*Ȼ�������Χ�׵ĸ���*/
		for (i = 1; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
			{
				cnt_array1(mine1, i, j);
			}
		}
	}
	else if (difficulty_choice == 2) {//16*16
		for (i = 0; i < MINE2_NUM; i++)
		{
			while (1)
			{
				int X, Y;
				X = rand() % (SCALE2 - 2) + 1;
				Y = rand() % (SCALE2 - 2) + 1;
				if (mine2[X][Y] == 0)//�����и���
				{
					mine2[X][Y] = '*';//������������е�10����
					break;
				}
				else
					continue;
			}

		}
		/*Ȼ�������Χ�׵ĸ���*/
		for (i = 1; i < 17; i++)
		{
			for (j = 1; j < 17; j++)
			{
				cnt_array2(mine2, i, j);

			}
		}
	}
	else {//16*30
		for (i = 0; i < MINE3_NUM; i++)
		{
			while (1)
			{
				int X, Y;
				X = rand() % (SCALE2 - 2) + 1;
				Y = rand() % (SCALE3 - 2) + 1;
				if (mine3[X][Y] == 0)//�����и���
				{
					mine3[X][Y] = '*';//������������е�10����
					break;
				}
				else
					continue;
			}
		}
		/*Ȼ���ټ�����Χ���׵ĸ���*/
		for (i = 1; i < 17; i++)
		{
			for (j = 1; j < 31; j++)
			{
				cnt_array3(mine3, i, j);

			}
		}

	}
}
/************************************************************
�������ƣ�print_array
����������difficulty_choice,mine1[][],mine2[][],mine3[][]
�������ܣ���ӡ��һ��������
����ֵ����
*************************************************************/
void print_array1(int difficulty_choice, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	int i, j;
	cout << "�ڲ�����\n";
	switch (difficulty_choice)
	{
		case(1)://��ӡ9*9�ĵ�������
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			cout << "\n--+";
			for (i = 0; i < 20; i++) {
				cout << "-";
			}
			cout << endl;

			for (i = 1; i < SCALE1 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE1 - 1; j++)
				{
					if (mine1[i][j] == 42)
						cout << "* ";
					else
						cout << mine1[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case(2):
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			for (i = 0; i < 7; i++) {
				putchar('a' + i);
				putchar(' ');
			}
			cout << "\n--+";
			for (i = 0; i < 35; i++) {
				cout << "-";
			}
			cout << endl;
			/*����������ڲ�����*/
			for (i = 1; i < SCALE2 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE2 - 1; j++)
				{
					if (mine2[i][j] == 42)
						cout << "* ";
					else
						cout << mine2[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case(3):
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			for (i = 0; i < 21; i++) {
				putchar('a' + i);
				putchar(' ');
			}
			cout << endl;
			/*����������ڲ�����*/
			for (i = 1; i < SCALE2 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE3 - 1; j++)
				{
					if (mine3[i][j] == 42)
						cout << "* ";
					else
						cout << mine3[i][j] << " ";
				}
				cout << endl;
			}
			break;
	}

}
void inner_show_arrary(int menu_choice, int difficulty_choice)
{
	cct_cls();//������
	int mine1[SCALE1][SCALE1] = { 0 };//9*9��ɨ�� 10����
	int mine2[SCALE2][SCALE2] = { 0 };//16*16     40����
	int mine3[SCALE2][SCALE3] = { 0 };//16*30     99����
	//int i=1,j=1;

	if (menu_choice == 1) {
		create_array(difficulty_choice, mine1, mine2, mine3);/*�γ���������*/
		print_array1(difficulty_choice, mine1, mine2, mine3);
	}
	cout << endl;
	cout << "���س�������...";
	while (1)
	{
		int enter = _getch();
		if (enter == '\r')
			break;
	}

}

/**********************************************
�������ƣ�prompt_command()
���������nandu &num1 &num2
�������ܣ��Ӽ��̶����һ��Ҫ�򿪵�λ������
����ֵ������2����������&��ȡʱ��
		����0��������q���˳�
		����1��������㿪������
		������1��mark=999������Ϊ��
		������1��mark=888����ȡ���ñ��

˵�������ô˺������Եõ���һ��Ҫ�򿪵�λ�õ�����
***********************************************/
int prompt_command(int nandu, int* num1, int* num2, int x, int* mark)
{
	*mark = 0;//��ʼÿ��markΪ0��
	if (x == 4) {
		cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)\n";
		cout << setw(14) << " " << "��- ��Ǹ�����Ϊ��(����!E3)\n";
		cout << setw(14) << " " << "# - ȡ�����      (����#E3)\n";

	}
	cout << "�������λ�õ���������(���к��У��ϸ����ִ�Сд����G1/Af,��Q/q�˳�) : ";
	while (1) {
		*num1 = _getch();
		if (*num1 == '!' && x == 4) {
			putchar(*num1);//��ʾ!��
			*num1 = _getch();
			*mark = 999;//���Ϊ�ף���markΪ999
		}
		else if (*num1 == '#' && x == 4) {
			putchar(*num1);//��ʾ#��
			*num1 = _getch();
			*mark = 888;//ȡ����Ǹõ�Ϊ��

		}
		else if (*num1 == '&' && x == 4) {//ȡʱ��
			float time = float(clock() / 1000.0);
			cout << "\n������ʱ�䣺" << time << "��\n";
			return 2;
		}
		else if (*num1 == 'Q' || *num1 == 'q') {
			putchar(*num1);
			return 0;
		}

		switch (nandu)
		{
			case(1):
				if (*num1 >= 'A' && *num1 <= 'I')
				{
					putchar(*num1);
					*num1 = *num1 - 'A' + 1;
					while (1) {
						*num2 = _getch();
						if (*num2 >= '1' && *num2 <= '9') {
							putchar(*num2);
							*num2 = *num2 - '0';
							return 1;
						}

					}
				}
				break;
			case(2):
				if (*num1 >= 'A' && *num1 <= 'P') {
					putchar(*num1);
					*num1 = *num1 - 'A' + 1;
					while (1) {
						*num2 = _getch();
						if (*num2 >= '1' && *num2 <= '9' || *num2 >= 'a' && *num2 <= 'g') {
							putchar(*num2);
							if (*num2 >= 'a' && *num2 <= 'g')
								*num2 = *num2 - 'a' + 10;
							else {
								*num2 = *num2 - '0';
							}
							return 1;
						}
					}
				}
				break;
			case(3):
				if (*num1 >= 'A' && *num1 <= 'P') {
					putchar(*num1);
					*num1 = *num1 - 'A' + 1;
					while (1) {
						*num2 = _getch();
						if (*num2 >= '1' && *num2 <= '9' || *num2 >= 'a' && *num2 <= 'u') {
							putchar(*num2);
							if (*num2 >= 'a' && *num2 <= 'u')
								*num2 = *num2 - 'a' + 10;
							else
								*num2 = *num2 - '0';
							return 1;
						}
					}
				}
				break;
		}

	}


}
/**********************************************
�������ƣ�makeup_mine()
���������num1������ num2������
�������ܣ��ڵõ���һ�������λ�������Ų���
����ֵ��
˵��������Ҫ��������ף���Χ�˸�λ��ȫ������
��Ӧ�ڶ����˵�ѡ��
***********************************************/
void makeup_mine(int num1, int num2, int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{

	int i, j;
	srand((unsigned int)(time(0)));
	/*�������ָ����Ŀ���ף���Ҫ����е��������Χ8���ط���������*/
	switch (nandu)
	{
		case(1):
			for (i = 0; i < MINE1_NUM; i++)
			{
				while (1)
				{
					int X, Y;
					X = rand() % MAX_X1 + 1;
					Y = rand() % MAX_Y1 + 1;
					if (abs(X - num1) <= 1 && abs(Y - num2) <= 1) {//ѡ��λ�õ���Χ�˸�λ�ñ��벻����
						continue;
					}
					if (mine1[X][Y] == 0)//�����и���
					{
						mine1[X][Y] = '*';//������������е���
						break;
					}
					else
						continue;
				}

			}
			/*Ȼ����ͳ�Ʒ���λ����Χ������*/
			for (i = 1; i < 10; i++)
			{
				for (j = 1; j < 10; j++)
				{
					cnt_array1(mine1, i, j);
				}
			}
			break;

		case(2):
			for (i = 0; i < MINE2_NUM; i++)
			{
				while (1)
				{
					int X, Y;
					X = rand() % MAX_X2 + 1;
					Y = rand() % MAX_Y2 + 1;
					if (abs(X - num1) <= 1 && abs(Y - num2) <= 1) {//ѡ��λ�õ���Χ�˸�λ�ñ��벻����
						continue;
					}
					if (mine2[X][Y] == 0)//�����и���
					{
						mine2[X][Y] = '*';//������������е���
						break;
					}
					else
						continue;
				}

			}
			/*Ȼ����ͳ����Χ*/
			/*Ȼ�������Χ�׵ĸ���*/
			for (i = 1; i < 17; i++)
			{
				for (j = 1; j < 17; j++)
				{
					cnt_array2(mine2, i, j);

				}
			}
			break;
		case(3):
			for (i = 0; i < MINE3_NUM; i++)
			{
				while (1)
				{
					int X, Y;
					X = rand() % MAX_X3 + 1;
					Y = rand() % MAX_Y3 + 1;
					if (abs(X - num1) <= 1 && abs(Y - num2) <= 1) {//ѡ��λ�õ���Χ�˸�λ�ñ��벻����
						continue;
					}
					if (mine3[X][Y] == 0)//�����и���
					{
						mine3[X][Y] = '*';//������������е���
						break;
					}
					else
						continue;
				}

			}
			/*Ȼ����ͳ����Χ����λ��*/
			for (i = 1; i < 17; i++)
			{
				for (j = 1; j < 31; j++)
				{
					cnt_array3(mine3, i, j);

				}
			}
			break;

	}

}



/**********************************************
�������ƣ�print_hidden()
���������nandu (1-3)
�������ܣ���ʾ��ͬ��С�ĳ�ʼ���� ȫ����x��ʾ��ʾ�ڱ�
����ֵ����
˵����
***********************************************/
void print_hidden(int nandu, int canshu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int* mark)
{
	/*mark 999 ������Ϊ�� *mark 888����ȡ�����Ϊ��*/
	int i, j;
	if (canshu == 1) {
		cct_cls();//������
		cout << "�ڲ�����:\n";
	}
	else
		cout << "\n�㿪�������Ϊ:\n";
	switch (nandu)
	{
		case(1)://��ӡ9*9�ĵ�������
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			cout << "\n--+";
			for (i = 0; i < 20; i++) {
				cout << "-";
			}
			cout << endl;
			/*��������ӡx*/
			for (i = 1; i < SCALE1 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE1 - 1; j++)
				{

					if (canshu == 1)
						cout << "X ";
					else {//�ж������ڵ�ֵ��������ڵ���1000�����ȥ1000����򿪣�
						if (mine1[i][j] >= REVEAL) {
							mine1[i][j] -= REVEAL;
							//���Ҹı���ɫ
							if (mine1[i][j] == '*') {
								cout << '*';
								mine1[i][j] += REVEAL;//�ٽ�����򿪵��׸�ֵΪ1042 ˵����Ϸ����
							}
							else if (mine1[i][j] == 0)//�����0��λ�ã��ı���ɫ��
							{
								cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
								cout << mine1[i][j];
								mine1[i][j] += REVEAL;
							}
							else if (mine1[i][j] != '*') {//�������0����Ҳ���ף��ı���ɫ����
								cct_setcolor(COLOR_HYELLOW, COLOR_GREEN);
								cout << mine1[i][j];
								mine1[i][j] += REVEAL;//�򿪺������ֵ����һǧ�����������Ѿ�����

							}
							cct_setcolor();//�ָ�Ϊȱʡ
							cout << " ";

						}/*���������Ҫ�򿪵�������Ե�*/
						else if ((mine1[i][j] >= 100) && canshu == 4) {//���һ���������� ��100���Ϊ��
							cct_setcolor(COLOR_RED, COLOR_WHITE);//����ɫ�죬ǰ��ɫ��
							cout << 'X';
							cct_setcolor();
							cout << " ";
						}
						else {
							cout << "X ";
						}
					}
				}
				cout << endl;
			}
			break;

		case(2):
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			for (i = 0; i < 7; i++) {
				putchar('a' + i);
				putchar(' ');
			}
			cout << "\n--+";
			for (i = 0; i < 35; i++) {
				cout << "-";
			}
			cout << endl;
			/*�����x*/
			for (i = 1; i < SCALE2 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE2 - 1; j++)
				{
					//cout << "X ";
					if (canshu == 1) {
						cout << "X ";
					}
					else {//�ж������ڵ�ֵ��������ڵ���1000�����ȥ1000����򿪣�
						if (mine2[i][j] >= REVEAL) {
							mine2[i][j] -= REVEAL;
							//���Ҹı���ɫ
							if (mine2[i][j] == '*') {
								cout << '*';
								mine2[i][j] += REVEAL;//�ٽ�����򿪵��׸�ֵΪ1042 ˵����Ϸ����
							}
							else if (mine2[i][j] == 0)//�����0��λ�ã��ı���ɫ��
							{
								cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
								cout << mine2[i][j];
								mine2[i][j] += REVEAL;
							}
							else if (mine2[i][j] != '*') {//�������0����Ҳ���ף��ı���ɫ����
								cct_setcolor(COLOR_HYELLOW, COLOR_GREEN);
								cout << mine2[i][j];
								mine2[i][j] += REVEAL;//�򿪺������ֵ����һǧ�����������Ѿ�����

							}
							cct_setcolor();//�ָ�Ϊȱʡ
							cout << " ";
						}//���������Ҫ�򿪵�������Ե�
						else if ((mine2[i][j] >= 100) && canshu == 4) {//���һ���������� ��100���Ϊ��
							cct_setcolor(COLOR_RED, COLOR_WHITE);//����ɫ�죬ǰ��ɫ��
							cout << 'X';
							cct_setcolor();
							cout << " ";
						}
						else {
							cout << "X ";
						}
					}
				}
				cout << endl;
			}
			break;

		case(3):
			cout << "  |";
			for (i = 1; i < 10; i++) {
				cout << i << " ";
			}
			for (i = 0; i < 21; i++) {
				putchar('a' + i);
				putchar(' ');
			}
			cout << endl;
			/*����������ڲ�����*/
			for (i = 1; i < SCALE2 - 1; i++)
			{
				putchar('A' + i - 1);
				cout << " |";
				for (j = 1; j < SCALE3 - 1; j++)
				{
					if (canshu == 1) {
						cout << "X ";
					}
					else {//�ж������ڵ�ֵ��������ڵ���1000�����ȥ1000����򿪣�
						if (mine3[i][j] >= REVEAL) {
							mine3[i][j] -= REVEAL;
							//���Ҹı���ɫ
							if (mine3[i][j] == '*') {
								cout << '*';
								mine3[i][j] += REVEAL;//�ٽ�����򿪵��׸�ֵΪ1042 ˵����Ϸ����
							}
							else if (mine3[i][j] == 0)//�����0��λ�ã��ı���ɫ��
							{
								cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
								cout << mine3[i][j];
								mine3[i][j] += REVEAL;
							}
							else if (mine3[i][j] != '*') {//�������0����Ҳ���ף��ı���ɫ����
								cct_setcolor(COLOR_HYELLOW, COLOR_GREEN);
								cout << mine3[i][j];
								mine3[i][j] += REVEAL;//�򿪺������ֵ����һǧ�����������Ѿ�����

							}
							cct_setcolor();//�ָ�Ϊȱʡ
							cout << " ";

						}//���������Ҫ�򿪵�������Ե�
						else if ((mine3[i][j] >= 100) && canshu == 4) {//���һ���������� ��100���Ϊ��
							cct_setcolor(COLOR_RED, COLOR_WHITE);//����ɫ�죬ǰ��ɫ��
							cout << 'X';
							cct_setcolor();
							cout << " ";
						}
						else {
							cout << "X ";
						}
					}
				}
				cout << endl;
			}
			break;

	}
	cout << endl;
}


/*�������ƣ�remark()
��������������Ϊ�� �Ѹô��滻Ϊ999
		���ȡ����ǣ��Ѹô����888
�𵽱������
*/
void remark(int nandu, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int num1, int num2, int* mark)
{
	switch (nandu)
	{
		case(1):
			if (mine1[num1][num2] > REVEAL) {//˵����λ���Ѿ����򿪣����ܽ��б�ǲ���
				return;
			}
			else if (*mark == SIGN) {//���Ϊ��
				if (mine1[num1][num2] >= ZERO && mine1[num1][num2] <= MARK)//����Ѿ������򲻿��ٱ��
					mine1[num1][num2] += HUNDRED;//��100,��Ǹ�λ��
			}
			else if (*mark == UNSIGN) {//ȡ�����
				if (mine1[num1][num2] >= HUNDRED && mine1[num1][num2] <= HUNDRED + MARK)//����Ѿ��������ò�����ֻ�Ա���ǵ�ȡ�����
					mine1[num1][num2] -= HUNDRED;//ȡ�����
			}
			break;
		case(2):
			if (mine2[num1][num2] > REVEAL) {//˵����λ���Ѿ����򿪣����ܽ��б�ǲ���
				return;
			}
			else if (*mark == SIGN) {
				if (mine2[num1][num2] >= ZERO && mine2[num1][num2] <= MARK)//����Ѿ������򲻿��ٱ��
					mine2[num1][num2] += HUNDRED;//��100,��Ǹ�λ��
			}
			else if (*mark == UNSIGN) {
				if (mine2[num1][num2] >= HUNDRED && mine2[num1][num2] <= HUNDRED + MARK)//����Ѿ��������ò�����ֻ�Ա���ǵ�ȡ�����
					mine2[num1][num2] -= HUNDRED;//ȡ�����
			}
			break;
		case(3):
			if (mine3[num1][num2] > REVEAL) {//˵����λ���Ѿ����򿪣����ܽ��б�ǲ���
				return;
			}
			else if (*mark == SIGN) {
				if (mine3[num1][num2] >= ZERO && mine3[num1][num2] <= MARK)//����Ѿ������򲻿��ٱ��
					mine3[num1][num2] += HUNDRED;//��100,��Ǹ�λ��
			}
			else if (*mark == UNSIGN) {
				if (mine3[num1][num2] >= HUNDRED && mine3[num1][num2] <= HUNDRED + MARK)//����Ѿ��������ò�����ֻ�Ա���ǵ�ȡ�����
					mine3[num1][num2] -= HUNDRED;//ȡ�����
			}
			break;


	}
	return;

}


/***************************************
�������ƣ�eight_direction
���������
���ܣ����ظ����õĴ��� Ƕ����digui_fist�����й�
˵������С���ھ�������һ����ʼ����ķ���Ҫ����һ������ʵ��
****************************************/
void eight_direction(int nandu, int num1, int num2, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	digui_first(nandu, num1 - 1, num2, mine1, mine2, mine3);//�ݹ���� һ��ҪѰ�Ұ˸�λ��
	digui_first(nandu, num1, num2 - 1, mine1, mine2, mine3);
	digui_first(nandu, num1 + 1, num2, mine1, mine2, mine3);
	digui_first(nandu, num1, num2 + 1, mine1, mine2, mine3);
	digui_first(nandu, num1 + 1, num2 + 1, mine1, mine2, mine3);
	digui_first(nandu, num1 - 1, num2 + 1, mine1, mine2, mine3);
	digui_first(nandu, num1 - 1, num2 - 1, mine1, mine2, mine3);
	digui_first(nandu, num1 + 1, num2 - 1, mine1, mine2, mine3);
}

/***************************************
�������ƣ�digui_fist
���������
���ܣ���ʾ��һ���ĳ�ʼ����
//�õݹ�Ѱ�ҳ�ʼ�����򣬲��ҰѸ������ֵ��1000
˵������С���ھ�������һ����ʼ����ķ���Ҫ����һ������ʵ��
****************************************/
void digui_first(int nandu, int num1, int num2, int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3])
{
	switch (nandu)
	{
		case(1):
			if (num1 == 0 || num1 == BODER1 || num2 == 0 || num2 == BODER1)//����߽緶Χ��ֹͣ��ɢ
				return;
			if (mine1[num1][num2] == 0) {
				reveal(&mine1[num1][num2]);//�����Ϊ0��λ�ô�
				eight_direction(nandu, num1, num2, mine1, mine2, mine3);//��ҪѰ�Ұ˸�λ��
			}
			else if (mine1[num1][num2] > 0 && mine1[num1][num2] <= MINE1_NUM) {
				//����Ƿ�0���ǵ��׵�λ�� ����¶��λ�ú�����ֹͣ
				reveal(&mine1[num1][num2]);
				return;
			}
			else if (mine1[num1][num2] == '*') {
				//����򿪵�λ�����ף���ӡ���׺���Ϸ����
				reveal(&mine1[num1][num2]);
				return;
			}
			break;
		case(2):
			if (num1 == 0 || num1 == BODER2 || num2 == 0 || num2 == BODER2)//����߽緶Χ��ֹͣ��ɢ
				return;
			if (mine2[num1][num2] == 0) {
				reveal(&mine2[num1][num2]);//�����Ϊ0��λ�ô�
				eight_direction(nandu, num1, num2, mine1, mine2, mine3);//��ҪѰ�Ұ˸�λ��
			}
			else if (mine2[num1][num2] > 0 && mine2[num1][num2] <= MINE1_NUM) {
				//����Ƿ�0���ǵ��׵�λ�� ����¶��λ�ú�����ֹͣ
				reveal(&mine2[num1][num2]);
				return;
			}
			else if (mine2[num1][num2] == '*') {
				//����򿪵�λ�����ף���ӡ���׺���Ϸ����
				reveal(&mine2[num1][num2]);
				return;
			}
			break;
		case(3)://16*30������ ����num1�ı߽���BODER2
			if (num1 == 0 || num1 == BODER2 || num2 == 0 || num2 == BODER3)//����߽緶Χ��ֹͣ��ɢ
				return;
			if (mine3[num1][num2] == 0) {
				reveal(&mine3[num1][num2]);//�����Ϊ0��λ�ô�
				eight_direction(nandu, num1, num2, mine1, mine2, mine3);//��ҪѰ�Ұ˸�λ��
			}
			else if (mine3[num1][num2] > 0 && mine3[num1][num2] <= MINE1_NUM) {
				//����Ƿ�0���ǵ��׵�λ�� ����¶��λ�ú�����ֹͣ
				reveal(&mine3[num1][num2]);
				return;
			}
			else if (mine3[num1][num2] == '*') {
				//����򿪵�λ�����ף���ӡ���׺���Ϸ����
				reveal(&mine3[num1][num2]);
				return;
			}
			break;

	}

}

/***************************************
�������ƣ�first_open_arrray()
���������nandu
���ܣ���ʾ��һ���ĳ�ʼ����
����ֵ��
˵����
****************************************/
void first_open_array(int nandu, int x)
{
	int mark = 0;
	/*�ȶ�������ɨ������ */
	int mine1[SCALE1][SCALE1] = { 0 };//9*9��ɨ�� 10����
	int mine2[SCALE2][SCALE2] = { 0 };//16*16     40����
	int mine3[SCALE2][SCALE3] = { 0 };//16*30     99����
	int num1 = 0, num2 = 0;
	print_hidden(nandu, 1, mine1, mine2, mine3, &mark);//��ʾ��ʼ���ڸǲ���
	int quit = prompt_command(nandu, &num1, &num2, x, &mark);//����num1��num2���˳���ָ��
	if (quit == 1) {
		makeup_mine(num1, num2, nandu, mine1, mine2, mine3);//��������ĵ�һ��λ�õ�����������
		digui_first(nandu, num1, num2, mine1, mine2, mine3);//��ǵ�һ��Ҫ���򿪵�����
		print_hidden(nandu, 2, mine1, mine2, mine3, &mark);//��һ�δ�
	}
	if (x == 2)
		pause_enter();


}
/***************************************
�������ƣ�print_perstep()
���������nandu
���ܣ��ڲ����������
����ֵ��
˵�����ڵڶ����Ļ����ϼ���������������ֱ����Ϸ����
��Ӧ�������˵�ѡ��
****************************************/
void print_perstep(int nandu, int x)
{/*�ȶ�������ɨ������ */
	int mine1[SCALE1][SCALE1] = { 0 };//9*9��ɨ�� 10����
	int mine2[SCALE2][SCALE2] = { 0 };//16*16     40����
	int mine3[SCALE2][SCALE3] = { 0 };//16*30     99����
	int num1 = 0, num2 = 0;
	int mark = 0;
	print_hidden(nandu, 1, mine1, mine2, mine3, &mark);//��ʾ��ʼ���ڸǲ���
	/*�����ǵ�һ������*/
	int quit = prompt_command(nandu, &num1, &num2, x, &mark);//����num1��num2���˳���ָ��
	while (quit == 2) {//���������ȡʱ��Ļ�
		quit = prompt_command(nandu, &num1, &num2, x, &mark);
	}
	if (quit == 1) {
		if (mark == 0) {//��һ�β���Ĭ�ϵ㿪һ����
			makeup_mine(num1, num2, nandu, mine1, mine2, mine3);//��������ĵ�һ��λ�õ�����������
			digui_first(nandu, num1, num2, mine1, mine2, mine3);//��ǵ�һ��Ҫ���򿪵�����
			print_hidden(nandu, x, mine1, mine2, mine3, &mark);//��һ�δ�
		}
		while (x == 4 && mark == 999 || mark == 888) {//���Ϊ�� ����ȡ�����Ϊ�� ����һ������ͱ����һ����
			remark(nandu, mine1, mine2, mine3, num1, num2, &mark);
			print_hidden(nandu, x, mine1, mine2, mine3, &mark);//��ʾ����
			quit = prompt_command(nandu, &num1, &num2, x, &mark);//��������
		}


	}
	else {//quit=0ʱ��ֱ���˳�
		pause_enter();
		return;
	}
	/*�����濪ʼִ��ѭ����ÿ�δ�һ�Σ�֪����Ϸ����Ϊֹ*/
	while (1) {
		num1 = 0, num2 = 0;//ÿ�����¿�ʼǰ��num1,2����
		quit = prompt_command(nandu, &num1, &num2, x, &mark);//����num1��num2���˳���ָ��
		while (quit == 2) {//ȡʱ��
			quit = prompt_command(nandu, &num1, &num2, x, &mark);
		}
		if (quit == 0)
			break;
		else if (quit == 1 && mark == 0) {
			digui_first(nandu, num1, num2, mine1, mine2, mine3);//��ǵ�һ��Ҫ���򿪵�����
			print_hidden(nandu, x, mine1, mine2, mine3, &mark);
		}
		else if (quit == 1 && x == 4) {
			remark(nandu, mine1, mine2, mine3, num1, num2, &mark);//���Ϊ��
			print_hidden(nandu, x, mine1, mine2, mine3, &mark);
		}

		int panduan = judge_game(mine1, mine2, mine3, nandu);
		if (panduan == 0) {
			cout << "������,��Ϸ����\n";
			break;
		}
		else if (panduan == 2) {
			cout << "��ϲʤ������Ϸ������\n";
			break;
		}
		else//����ֵ��1����Ϸ����
			;
	}
	pause_enter();

}
