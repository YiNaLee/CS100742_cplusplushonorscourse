/*2052316 ��07 ��t��*/
/*ע������ʱ�����ƣ������������ʵ����ɨ��ͼ�λ�������*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include"../include/menu_combine.h"
#include "../include/cmd_gmw_tools.h"
#include "90-01-b2-gmw.h"
/* -----------------------------------------
	 ���ļ����ܣ�
	1����main����  ִ��ɨ�׵Ĺ���
	2����ʼ����Ļ
	3�����ù����˵�������public_menu��������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����.cpp�У�
	5.ע������ʱ�����ƣ������������ʵ����ɨ��ͼ�λ�������
   ----------------------------------------- */
using namespace std;
int main()
{
	//cct_setconsoleborder(100, 40);
	cct_setfontsize("������", 24);
	while (1) {
		cct_setfontsize("������", 24);
		char menu[][1024] = { {"ɨ����gmw������ʵ�ֵ������棺" },
							 {"9.αͼ�ν���������\0"},
							 {"0.�˳���Ϸ\0"},
							 { "\0" } };
		int x;
		char select;

		select = public_menu(menu, 1);
		x = select - '0';
		if (x == 0)//0 �˳�����
			break;
		if (x == 9) {
			int nandu = difficulty_choice();
			graph_gmw_mine_sweeper(nandu);
		}
		cct_cls();/*������Ļ*/
	}
	return 0;
}