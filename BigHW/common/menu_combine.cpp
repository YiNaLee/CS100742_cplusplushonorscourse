/* ��07 2052316 ��t�� */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
/*��cpp�Ĺ��ܣ��˵������Ĺ���*/

using namespace std;
/************************************************************************************
�������ƣ�public_menu(char (*lp)[1024]
�����������ַ���ָ�� sort������������һ������
�������ܣ��������ҵ�Ĳ˵���ô˺�����ֻҪ����˵���Ķ�ά�ַ����鼴��
��������ֵ:һ�������char���ַ�
�������ʣ���������
************************************************************************************/
char public_menu(char (*lp)[1024],int sort)
{
	char(*lpp)[1024] = lp;
	char* pp = *lp;
	char select=0;
	int num = 0,tmp=0;//����������ĺ��ߵĳ��ȣ�
	for (; *pp!='\0'; lpp++) {
		pp = *lpp;
		for (; *pp != '\0'; pp++) {
			num++;
		}
		pp = *lpp;//�ٻص�����
		if (num > tmp) {
			tmp = num;
		}
		num = 0;
	}
	lpp = lp;
	pp = *lp;//ָ�븴λ
	for (int i = 0; i < tmp; i++) {
		cout << '-';
	}
	cout << endl;/*��ӡ��һ�ŵĺ���*/

	for (; *pp != '\0'; lpp++) {
		pp = *lpp;//��һ��
		for (; *pp != '\0'; pp++) {
			cout << *pp;
		}
		pp = *lpp;//�ٻص�����
		if(*pp!='\0')
		    cout << endl;
		
	}
	for (int i = 0; i <tmp; i++) {
		cout << '-';
	}
	cout << endl;
	cout << "[��ѡ��]";
	while (sort==1)
	{
		select = _getch();
		if (select >= '0' && select <= '9') {
			putchar(select);
			break;
		}		
	}
	while (sort == 2) {
		select = _getch();
		if (select >= 'A' && select <= 'G' || select >= 'a' && select <= 'g' || select == 'Q' || select == 'q') {
			putchar(select);
			break;
		}		
	}
	if (sort == 1 || sort == 2) {
		return select;
	}
	else
		return '0';
	
	

}



























