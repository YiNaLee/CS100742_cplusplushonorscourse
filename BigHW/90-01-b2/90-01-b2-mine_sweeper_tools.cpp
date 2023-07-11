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
/*��cpp�Ĺ��ܣ��ж���Ϸ�Ƿ�ɹ�*/

/***************************************
�������ƣ�judge_game()
���������nandu,mine1,mine2,mine3
���ܣ��ж���Ϸ�Ƿ�ɹ�
����ֵ�� ����1˵����Ϸ�����Լ���������2˵����Ϸ�ɹ�������0˵����Ϸʧ��
˵����
****************************************/
int judge_game(int mine1[][SCALE1], int mine2[][SCALE2], int mine3[][SCALE3], int nandu)
{
	int i, j;
	int counter = 0;
	switch (nandu)
	{
		case(1):
			for (i = 1; i < BODER1; i++) {
				for (j = 1; j < BODER1; j++) {
					if (mine1[i][j] == '*' + 1000)
						return 0;//��Ϸʧ��
					if (mine1[i][j] < REVEAL)//��������е�ֵС��һǧ��˵��������û�б���
						counter++;
				}
			}
			if (counter == MINE1_NUM)
				return 2;//��Ϸ�ɹ�
			else
				return 1;//��Ϸ����
			break;

		case(2):
			for (i = 1; i < BODER2; i++) {
				for (j = 1; j < BODER2; j++) {
					if (mine2[i][j] == '*' + 1000)
						return 0;
					if (mine2[i][j] < REVEAL)//��������е�ֵС��һǧ��˵��������û�б���
						counter++;
				}
			}
			if (counter == MINE2_NUM)
				return 2;//��Ϸ�ɹ�
			else
				return 1;//��Ϸ����
			break;

		case(3):
			for (i = 1; i < BODER2; i++) {
				for (j = 1; j < BODER3; j++) {
					if (mine3[i][j] == '*' + 1000)
						return 0;
					if (mine3[i][j] < REVEAL)//��������е�ֵС��һǧ��˵��������û�б���
						counter++;
				}
			}
			if (counter == MINE3_NUM)
				return 2;//��Ϸ�ɹ�
			else
				return 1;//��Ϸ����
			break;

	}

	return 0;
}