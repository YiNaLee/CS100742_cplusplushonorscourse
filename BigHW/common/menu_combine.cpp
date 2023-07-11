/* 信07 2052316 李祎娜 */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
/*本cpp的功能：菜单函数的共用*/

using namespace std;
/************************************************************************************
函数名称：public_menu(char (*lp)[1024]
函数参数：字符行指针 sort用来区分是哪一种输入
函数功能：多个大作业的菜单项共用此函数，只要传入菜单项的二维字符数组即可
函数返回值:一个输入的char型字符
函数性质：公共函数
************************************************************************************/
char public_menu(char (*lp)[1024],int sort)
{
	char(*lpp)[1024] = lp;
	char* pp = *lp;
	char select=0;
	int num = 0,tmp=0;//用来计算最长的横线的长度；
	for (; *pp!='\0'; lpp++) {
		pp = *lpp;
		for (; *pp != '\0'; pp++) {
			num++;
		}
		pp = *lpp;//再回到行首
		if (num > tmp) {
			tmp = num;
		}
		num = 0;
	}
	lpp = lp;
	pp = *lp;//指针复位
	for (int i = 0; i < tmp; i++) {
		cout << '-';
	}
	cout << endl;/*打印第一排的横线*/

	for (; *pp != '\0'; lpp++) {
		pp = *lpp;//下一行
		for (; *pp != '\0'; pp++) {
			cout << *pp;
		}
		pp = *lpp;//再回到行首
		if(*pp!='\0')
		    cout << endl;
		
	}
	for (int i = 0; i <tmp; i++) {
		cout << '-';
	}
	cout << endl;
	cout << "[请选择：]";
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



























