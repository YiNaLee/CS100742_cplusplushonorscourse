/*2052316 ��07 ��t��*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
#include"90-02-b4-led.h"
using namespace std;

#include "../include/cmd_hdc_tools.h"
#include "../include/cmd_console_tools.h"
#include"../include/menu_combine.h"
#include "../include/cmd_gmw_tools.h"
int  main()
{
	//��������Ϊ��������
	cct_setfontsize("����",16 );
	cct_setconsoleborder(123, 38, 123, 38);//���ڴ�С
	while (1) {
		cct_setcolor();
		char menu[][1024] = { 
							 {"1.ģ��LED��Ϣ��ʾ-��������-��*��ʾÿ����\0"},
							 {" -- ��ʾʱ����������Ϊ����6����ɺ󰴻س�����\0"},
			                 {"\n"},
							 {"2.ģ��LED��Ϣ��ʾ-��������-hdc_porint��ÿ����\0"},
							 {"-- ����ʱ��ÿ����ֱ��Ϊ6����ɺ󰴻س�����\0"},
							 {"-- ÿ����֮����2ms��ʱ\0"},
							 {"\n"},
			                 {"3.�������룺��Ļ��С����ɫ���ַ�ģʽ������Ĵ�С����/�����ֿ������"},
							 {"\n"},
			                 {"0.�˳�\0"},
							 { "\0" } };
		int x;
		char select;

		select = public_menu(menu, 1);
		x = select - '0';
		if (x == 0)//0 �˳�����
			break;
		/*else if (x == 1) {//������һ�����ֻ�ȫ�Ƿ���(����y��ʾ����):
			//�Ӻ��ֿ��ж�ȡĳ�����ֵĵ�����Ϣ
			cct_cls();
			cin_one_Chinese_character();
		}*/
		else if (x == 1) {
			cct_cls();
			simplified_Chinese_low_version();
		}
		else if (x == 2) {
			cct_cls();
			//test_to_draw();
			traditional_Chinese_low_version();
		}
		else if (x == 3) {
			cct_cls();
			interactive_input();
		}
		cct_cls();/*������Ļ*/
		cct_setcolor();
	}
	return 0;
}
