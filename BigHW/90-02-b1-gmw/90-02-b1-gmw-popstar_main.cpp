/*2052316 ��07 ��t��*/
/* -----------------------------------------
	 ���ļ����ܣ�
	1����main����  ִ����������������Ĺ���
	2����ʼ����Ļ
	3�����ù����˵�������public_menu��������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����.cpp�У�
	5.ע������ʱ�����ƣ������������ʵ������������������
   ----------------------------------------- */
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
#include "90-02-b1-gmw.h"
using namespace std;
int main()
{
	
	while (1) {
		char select;
		int line, column;// �Ǹ���������д�С��8-10��
		int li = 0, co = 0;//�Ǽ��������Ҫ����������
		char temp[256] = " ";
		cct_setfontsize("������", 16);
		cct_cls();
		int star_array[STARMAX][STARMAX] = { 0 };
		char menu[][1024] = { {"����������gmw��������ɵ�������"},
							 {"G.αͼ�ν���������\0"},
							 {"Q.�˳�\0"},
							 { "\0" } };
		int x;
		select = public_menu(menu, 2);
		if (select >= 'a' && select <= 'z') {
			select -= 32;//תΪ��д
		}
		x = select - 'A';
		
	
		//�õ���x��0-6��ֵ������x==6����αͼ�ν���������
		if (select !='G') {
			putchar(select);
			continue;
		}
		cct_cls();
		
		get_line_column(&line, &column);//�Ӽ��̶��������д�С
		while (1) {
			for (int i = 0; i < line; i++) {
				for (int j = 0; j < column; j++) {
					star_array[i][j] = 0;
				}
			}
			star_array_setup(line, column, star_array);

			gmw_popstar_full_version(line, column, star_array);
			pause_enter(NULL);

		}
		
	}
}