/*2052316 ��07 ��t��*/
/* -----------------------------------------
	 ���ļ����ܣ�
	1����main����  ִ�кϳ�ʮ������Ĺ���
	2����ʼ����Ļ
	3�����ù����˵�������public_menu��������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����.cpp�У�
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
#include"../include/basic_public.h"
#include "90-02-b2-merge_ten.h"
using namespace std;
int main()
{

	while (1) {
		char select;
		int line=0, column=0,target=0;// �Ǹ���������д�С�ͺϳ�Ŀ��
		int li = 0, co = 0;//�Ǽ��������Ҫ����������
		char temp[256] = " ";
		cct_setfontsize("������", 16);
		cct_cls();
		int merge_array[MERGE_MAX_SCALE][MERGE_MAX_SCALE] = { 0 };//������һ��12*12���ʵ��Ŵ�����飬
		//���������ǵ������С��ͬ;
		char menu[][1024] = { {"1.�������ҳ��ɺϳ����ʶ���ǵݹ飩"},
							  {"2.�������ҳ��ɺϳ����ʶ���ݹ飩" },
							  {"3.���������һ�κϳɣ��ֲ�����ʾ��"},
			                  {"4.�����������棨�ֲ�����ʾ��" },
							  {"5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�"},
			                  {"6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�"},
			                  {"7.αͼ�ν������ü�ͷ��ѡ��ǰɫ��"},
			                  {"8.αͼ�ν������һ�κϳɣ��ֲ��裩"},
			                  {"9.αͼ�ν���������(֧�����)"},
			                  {"0.�˳�"},
							  { "\0" } };
		int x;
		select = public_menu(menu, 1);
		x = select - '0';
		if (x == 0)//0 �˳�����
			break;
	    //�õ���x��0-6��ֵ������x==6����αͼ�ν���������
		if (select != '9') {
			putchar(select);
			continue;
		}
		//x==9ʱ��������
		cct_cls();
		get_line_column(&line, &column, &target);
		//Ȼ��Ҫ��ʼ������������С���ͼ
		merge_array_setup(line,column,merge_array);
		//֮��ʼ��ͼ
		full_version_gmw_merge_ten(line, column, merge_array,target);
		//Ȼ��Ҫ��ӡ��С�����������end��������䣡
		public_cin_end_to_continue();
	}
}
