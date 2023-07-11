/* ��07 2052316 ��t�� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b1-hanoi.h"
#include"../include/menu_combine.h"

using namespace std;

/* -----------------------------------------

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ����const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ�
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1)
	{
		int x, n;
		char src, dst, tmp;
		char menu[][1024] = { {"1.������\0"} ,
							 {"2.������(������¼)\0"},
							 {"3.�ڲ�������ʾ(����)\0"},
							 {"4.�ڲ�������ʾ(����+����)\0"},
							 {"5.ͼ�ν�-Ԥ��-������Բ��\0"},
							 {"6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������\0"},
							 {"7.ͼ�ν�-Ԥ��-��һ���ƶ�\0"},
							 {"8.ͼ�ν�-�Զ��ƶ��汾\0"},
							 {"9.ͼ�ν�-��Ϸ��\0"},
							 {"0.�˳���Ϸ\0"},
							 { "\0" } };
		char sel;
		sel = public_menu(menu, 1);
		x = sel - '0';
		if (x == 0)
			break;
		else if (x != 5)//1/2/3/4/8/9ѡ��Ҫչʾ����
		{
			select(x, &n, &src, &dst, &tmp);//�����Ҫ�Ĳ�������
			getin_stack(n, src);/*��ʼԪ����ջ��*/
			/*4/5/6/7/8/9��Ҫ����*/
			if (x > 3 && x < 10)
				cct_cls();
			if (x == 4)
			{
				cct_setcursor(CURSOR_INVISIBLE);//�رչ��
				primilary_condition(x, n, src, dst);//��ʾ��ʼ״̬
			}
			else if (x == 8)
			{
				cct_setcursor(CURSOR_INVISIBLE);//�رչ��
				cct_gotoxy(0, 0);
				//cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed;
				primilary_condition(x, n, src, dst);//��ʾ��ʼ״̬
				print_nplate(n, src, 8);//�����˴�ӡ�����������Ӻʹ�ӡ��ʼԲ�̵Ĳ���
			/*!��һ��ҪС��*/	//sleepspeed(speed);
				//����ݹ�֮ǰ�ȴ�ӡ����	
			}
			else if (x == 9) {
				cct_setcursor(CURSOR_INVISIBLE);//�رչ��
				game_mode(n, src, dst);
				cct_gotoxy(0, GAME_note + 4);
			}
			/*��������Ҫ����hanoi���� �Ѳ�������hanio������5����Ҫ���ݲ�����6����Ҫʹ�õݹ�*/
			if (x != 6 && x != 9)//6/9���õݹ麯��
				hanoi(n, src, tmp, dst, x);
			else if (x == 6)//x����6ʱ ���ý��еݹ�
			{
				cct_gotoxy(0, 0);
				cct_setcursor(CURSOR_INVISIBLE);//�رչ��
				cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
				print_nplate(n, src, 0);
				cct_gotoxy(0, 38);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);
			}
			if (x == 4)
			{
				final_deal(dst);//��ʾ����״̬
			}
			else if (x == 7)
			{
				cct_gotoxy(0, 0);
				cct_setcursor(CURSOR_INVISIBLE);//�رչ��
				cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
				move_step(n, src, dst);
				cct_gotoxy(0, 38);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);
			}
			else if (x == 8) {
				cct_gotoxy(0, 38);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//�ָ����
			}
			clear_data();//�����̬�ֲ�����
			cct_setcursor(CURSOR_VISIBLE_NORMAL);//�ָ����
			cout << "\n���س�������";
			while (_getch() != '\r')
				;
			cct_cls();
		}
		else //�����if (x == 5)//��Բ��
		{
			cct_setcursor(CURSOR_INVISIBLE);//�رչ��
			cct_cls();
			chassis_print();
			cct_gotoxy(0, 38);
			cout << "���س�������";
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			while (_getch() != '\r')
				;
			cct_cls();
		}
	}
	return 0;
}