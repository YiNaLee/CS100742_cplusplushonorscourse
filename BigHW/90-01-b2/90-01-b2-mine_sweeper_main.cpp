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
#include "../include/menu_combine.h"
using namespace std;
/* -----------------------------------------
	 ���ļ����ܣ�
	1����main����  ִ��ɨ�׵Ĺ���
	2����ʼ����Ļ
	3�����ù����˵�������public_menu��������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����.cpp�У�
   ----------------------------------------- */
int main()
{
	/* ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		cct_setfontsize("������", 24);
		char menu[][1024] = { {"1.ѡ���ѶȲ���ʾ�ڲ�����\0"} ,
							 {"2.�����ʼλ�ò���ʾ���򿪵ĳ�ʼ����\0"},
							 {"3.�ڲ����������\0"},
							 {"4.�ڲ����������棨��ǡ�����ʱ�䣩\0"},
							 {"5.����αͼ�λ���ܲ���ʾ�ڲ�����\0"},
							 {"6.������λ�úͺϷ��ԣ���������˳���\0"},
							 {"7.���ѡ���ʼλ�ò���ʾ���򿪵ĳ�ʼ����\0"},
							 {"8.αͼ�ν��������\0"},
							 {"9.αͼ�ν���������\0"},
							 {"0.�˳���Ϸ\0"},
			                 { "\0" }};
		int x;
		char select;
		
		select = public_menu(menu, 1);
		x = select - '0';
		if (x == 0)//0 �˳�����
			break;
		else if (x == 1) {//��һ���˵��� ��ʾ�ڲ�����
			int nandu = difficulty_choice();
			inner_show_arrary(x, nandu);
		}
		else if (x == 2) {//��ʾ���򿪵ĳ�ʼ����
			int nandu = difficulty_choice();
			first_open_array(nandu, x);
		}
		else if (x == 3) {//�ڲ����������
			int nandu = difficulty_choice();
			print_perstep(nandu, x);
		}
		else if (x == 4) {//�ڲ�����������
			int nandu = difficulty_choice();
			print_perstep(nandu, x);
		}
		else if (x == 5) {
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		else if (x == 6) {/*��5�Ļ����ϼ����ĺϷ���*/
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		else if (x == 7) {//��6�Ļ������Ƚ�����ȫ���ڱΣ�Ȼ���ʼ��һ���㿪
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		else if (x == 8) {//��7�Ļ����������Ϸ�汾����esc�����˳�
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		else if (x == 9) {
			int nandu = difficulty_choice();
			graph_showarray(x, nandu);
		}
		cct_cls();/*������Ļ*/
	}
	return 0;
}
