/*2052316 信07 李祎娜*/
//本cpp功能：辅助函数，菜单函数调用、返回选择值、
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
using namespace std;

#include "../include/cmd_hdc_tools.h"
#include "../include/cmd_console_tools.h"
#include"../include/menu_combine.h"
#include "../include/cmd_gmw_tools.h"
#include "../include/basic_public.h"

/************************************************************************************
函数名称：cin_one_Chinese_character()
函数参数：
函数功能：输入一个汉字或全角符号(输入y表示结束),要处理各种输入错误
对应菜单项1功能
************************************************************************************/
void cin_one_Chinese_character()
{
	FILE* fphzk16 = NULL;//hzk16库的文件指针
	FILE* fphzk16f = NULL;//hzk16f库的文件指针
	unsigned char storage[32];//用来存输入的字符数组
	unsigned char buffer[32];//读取字库中
	char type = 'n';//缺省是简体字
	unsigned char key[8] = {
	   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};//方便查找，
	int i, j,k;//循环次数
	int flag;//记录要画的点
	int offset = 0;//在汉字库中的偏移值
	while (1) {
		cout << "请输入一个汉字或全角符号(输入y表示结束):";
		cin >> storage;//输入之后只取第一个汉字，而且要判断输入的第一个汉字是不是汉字
		cin.ignore(65536, '\n');
		if (storage[0] == 'Y' || storage[0] == 'y') {
			//输入end继续
			public_cin_end_to_continue();
			return;
		}
		cout << "是否需要显示繁体(Y/n)";
		cin >> type;
		cin.ignore(65536, '\n');//清空缓冲区
		//用最高位判断输入是否是汉字 
		if (storage[0] / int(pow(2, 7)) == 0) {
			cout << "不是合法的GB2312汉字(高位非法)\n";
			public_pause_enter("请按任意键继续. . .");
			cct_cls();
			continue;
		}
		//否则就是合法的汉字
		if (type == 'y' || type == 'Y') {//繁体处理规则
			fphzk16f = fopen("HZK16F", "rb");
			if (fphzk16f == NULL) {
				cout << "无法打开字库文件HZK16F\n";
				public_pause_enter("请按任意键继续. . .");
				return;
			}
			cout << "输入的汉字是                   ：" << storage[0] << storage[1] << endl;

		}
		else {//简体处理规则：
			fphzk16 = fopen("HZK16", "rb");
			if (fphzk16 == NULL) {
				cout << "无法打开字库文件HZK16\n";
				public_pause_enter("请按任意键继续. . .");
				return;
			}

			cout << "输入的汉字是                   ：" << storage[0] << storage[1] << endl;
			
		}
		
		cout << "汉字的区位码                   ：" << int(storage[0] - 0xa0) << int(storage[1] - 0xa0) << endl;
		cout << "前半个汉字的内部码             ：" << hex << int(storage[0]) << endl;
		cout << "后半个汉字的内部码             ：" << hex << int(storage[1]) << endl;

		offset = (94 * (unsigned int)(storage[0] - 0xa0 - 1) + (storage[1] - 0xa0 - 1)) * 32;
		cout << "在16点阵汉字库中的偏移值是     ：" << dec << offset << endl;
		cout << "字库中读到的16*16点阵的值是    ：\n";
		//一共有32个字节，四个一小组，八个换行
		if (type == 'y' || type == 'Y') {
			//繁体规则
			if (fphzk16f == 0) {
				return;
			}
			else {
				fseek(fphzk16f, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk16f);//读取一共32个点阵信息
				fclose(fphzk16f);
			}
			
		}
		else {
			if (fphzk16 == 0) {
				return;
			}
			else {
				fseek(fphzk16, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk16);//读取一共32个点阵信息
				fclose(fphzk16);
			}
		
		}
		
		for (j = 0; j < 4; j++) {
			for (i = j * 8; i < j * 8 + 4; i++) {
				printf("%.2X ", buffer[i]);
				//cout << hex << int(buffer[i]) << " ";
			}
			cout << "-";
			for (i = j * 8 + 4; i < j * 8 + 8; i++) {
				printf("%.2X ", buffer[i]);
			}
			cout << endl;
		}
		cout << endl;
		cout << "  0 1 2 3 4 5 6 7 8 9 A B C D E F\n";
		//然后跳到下面画点阵图；

		for (k = 0; k < 16; k++) {
			if (k < 10) {
				cout << k << " ";
			}
			else {
				putchar('A' + k - 10);
				cout << " ";
			}
			for (j = 0; j < 2; j++) {
				for (i = 0; i < 8; i++) {
					flag = buffer[k * 2 + j] & key[i];
					cct_setcolor(7, 0);
					printf("%s ", flag ? "*" : " ");
			//		cct_setcolor();
				}
			}
			printf("\n");
		}
		//cct_setcolor();
		public_pause_enter("请按任意键继续. . .");

		cct_cls();
	}

}
/************************************************************************************
函数名称：void interactive_input()
函数参数：
函数功能：交互输入，对各种输入错误自行处理成合理模式
对应菜单项4功能
************************************************************************************/
void interactive_input()
{
	int set_cols, set_lines;//屏幕大小
	int color_fg, color_bg;//文字想要显示的颜色 （不是led的颜色）
	int font_size;//cmd下字体大小（不是led字体大小）
	int hdc_radius;//每个字体的直径（普通是6）
	int RGB1, RGB2, RGB3;//led下的三色
	int wordtype;//选择繁体还是简体
	unsigned char words[1024] = "\0" ;//不要超过512个字
	cout << "请输入屏幕大小：【如：123 38】表示宽123高38，中间以空格分隔:\n";
	cout << "如果输入范围过大、过小、输入错误将默认以【123 38】窗口大小显示,请输入：";
	cin >> set_cols >> set_lines;
	if (!cin) {
		cin.clear();
		cin.ignore(65536, '\n');
		set_cols = 123;
		set_lines = 38;
		//cct_setconsoleborder(123, 38, 123, 38);//设置窗口
	}
	else if (set_cols < 120 || set_cols>240||set_lines<30||set_lines>50) {
		//cct_setconsoleborder(123, 38, 123, 38);//设置窗口
		set_cols = 123;
		set_lines = 38;
	}
	else {
		;//cct_setconsoleborder(set_cols,set_lines,set_cols,set_lines);//设置窗口
	}
	cout << "输入屏幕和文字想要显示的颜色：如【0,7】表示背景黑色，文字白色\n";
	cout << "若输入错误或者范围不合理将默认【0,7】处理：";
	cin >> color_bg >> color_fg;
	if (!cin) {
		color_bg = 0;
		color_fg = 7;
		cin.clear();
		cin.ignore(65536, '\n');
	}
	else if (color_bg < 0 || color_bg>15 || color_fg < 0 || color_fg>15) {
		color_bg = 0;
		color_fg = 7;
	}
	cout << "请输入字符模式下字体大小，范围【8-24】，否则置默认值16：";
	cin >> font_size;
	if (!cin) {
	    font_size = 16;
		cin.clear();
		cin.ignore(65536, '\n');
	}
	else if (font_size < 8 || font_size>24) {
		font_size = 16;
	}
	cout << "输入hcd方式下每个点的直径：范围【3-10】，否则置默认值6：";
	cin >> hdc_radius;
	if (!cin) {
		hdc_radius = 6;
		cin.clear();
		cin.ignore(65536, '\n');
	}
	else if (hdc_radius < 3 || hdc_radius>10) {
		hdc_radius = 6;
	}
	cout << "这里输入你想输出的文字：（不超过512个字）";
	cin >> words;
	cout << "选择LED中文字的颜色：如【255 255 0】表示黄色,颜色不适合可能导致黑色看不出\n";
	cout << "如果输入错误，默认黄色：";
	cin >> RGB1 >> RGB2 >> RGB3;
	if (!cin) {
		cin.clear();
		cin.ignore(65536, '\n');
		RGB1 = 255;
		RGB2 = 255;
		RGB3 = 0;
	}
	else if (RGB1 < 0 || RGB1>255 || RGB2 < 0 || RGB2>255 || RGB3 < 0 || RGB3>255) {
		RGB1 = 255;
		RGB2 = 255;
		RGB3 = 0;
	}
	cout << "繁体还是简体：【0.繁体，1.简体】：(输入错误默认繁体)";
	cin >> wordtype;
	if (!cin) {
		cin.clear();
		cin.ignore(65536, '\n');
		wordtype = 0;
	}
	else if (wordtype != 0 &&wordtype != 1) {
		wordtype = 0;
	}
	//选择多种展示的模式，1表示从下到上，2表示从右到左，3表示从内到外
	cout << "选择led特效为何种模式：[1]从下到上逆序 [2]从外到内 [3]从内到外\n";
	cout << "请选择\n";
	int mode;
	while (1) {
		mode = getchar();
		if (mode >= '1' && mode <= '3') {
			break;
		}
	}
	int delay_;
	cout << "输入延时时间(ms),不合理将置为20ms\n";
	cin >> delay_;
	if (!cin) {
		cin.clear();
		cin.ignore(65536, '\n');
		delay_ = 20;
	}
	if (delay_ < 0 || delay_>100) {
		delay_ = 20;
	}
	cin.ignore(65536, '\n');
	hdc_set_delay(0);//画点设置为0，不然太慢
	//下面对输入进行实现
	//为了展示动画；
	
	cct_setfontsize("点阵", font_size);
	cct_setconsoleborder(set_cols,set_lines,set_cols,set_lines);//设置窗口
	cct_setcolor(color_bg, color_fg);
	
	//在交互式下计算一行可以打出多少字；
	int perline_word = set_cols / hdc_radius/2;
	//words
	unsigned char buffer[32] = { 0 };//存放点阵信息
	int k, j, i, cnt;
	unsigned char key[8] = {
	   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};//方便查找，
	int flag;//记录要画的点
	FILE* fphzk16f;//繁体库
	FILE* fphzk16;//简体库
	//计算一下输入的文本一共有多少字
	int word_num=0;
	for (int i = 0; words[i] != '\0'; i++) {
		word_num++;
	}
	word_num /= 2;//word_num表示了一共有多少字
	
	//0表示简体，1表示繁体
	hdc_cls();//先清屏，否则无法画
	switch (mode) {
	case '1'://从下到上的模式；
		for (cnt = (word_num - 1) * 2; cnt >= 0; cnt -= 2) {
			int offset = (94 * (unsigned int)(words[cnt] - 0xa0 - 1) \
				+ (words[cnt + 1] - 0xa0 - 1)) * 32;
			if (wordtype == 0) {//繁体字库
				fphzk16f = fopen("HZK16F", "rb");
				if (fphzk16f == NULL) {
					cout << "无法打开字库文件HZK16F\n";
					public_pause_enter("请按任意键继续. . .");
					return;
				}
				if (fphzk16f == 0) {
					return;
				}
				else {
					fseek(fphzk16f, offset, SEEK_SET);
					fread(buffer, 1, 32, fphzk16f);//读取一共32个点阵信息
					fclose(fphzk16f);
				}
			}
			else {//简体字库
				fphzk16 = fopen("HZK16", "rb");
				if (fphzk16 == NULL) {
					cout << "无法打开字库文件HZK16\n";
					public_pause_enter("请按任意键继续. . .");
					return;
				}
				if (fphzk16 == 0) {
					return;
				}
				else {
					fseek(fphzk16, offset, SEEK_SET);
					fread(buffer, 1, 32, fphzk16);//读取一共32个点阵信息
					fclose(fphzk16);
				}
			}
			//开始画图
			for (k = 0; k < 16; k++) {
				for (j = 0; j < 2; j++) {
					for (i = 0; i < 8; i++) {
						flag = buffer[k * 2 + j] & key[i];
						if (flag) {
							if (j == 0) {
								hdc_point(((cnt % (perline_word * 2) / 2) * 16 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//画点，要确定该点的坐标
							}
							else {//j==1
								hdc_point(((cnt % (perline_word * 2) / 2) * 16 + 8 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//画点，要确定该点的坐标
							}
						}
						else {
							;
						}

					}
				}
			}
			Sleep(delay_);//睡眠时间
			//还要将buffer清空
			for (int a = 0; a < 32; a++) {
				buffer[a] = 0;
			}
		}

		break;
	case '2'://从外到内
		for (cnt = 0; cnt<word_num; cnt += 2) {
			int temp = cnt;
			for (int circle = 0; circle < 2; circle++) {
				int offset = (94 * (unsigned int)(words[cnt] - 0xa0 - 1) \
					+ (words[cnt + 1] - 0xa0 - 1)) * 32;
				if (wordtype == 0) {//繁体字库
					fphzk16f = fopen("HZK16F", "rb");
					if (fphzk16f == NULL) {
						cout << "无法打开字库文件HZK16F\n";
						public_pause_enter("请按任意键继续. . .");
						return;
					}
					if (fphzk16f == 0) {
						return;
					}
					else {
						fseek(fphzk16f, offset, SEEK_SET);
						fread(buffer, 1, 32, fphzk16f);//读取一共32个点阵信息
						fclose(fphzk16f);
					}
				}
				else {//简体字库
					fphzk16 = fopen("HZK16", "rb");
					if (fphzk16 == NULL) {
						cout << "无法打开字库文件HZK16\n";
						public_pause_enter("请按任意键继续. . .");
						return;
					}
					if (fphzk16 == 0) {
						return;
					}
					else {
						fseek(fphzk16, offset, SEEK_SET);
						fread(buffer, 1, 32, fphzk16);//读取一共32个点阵信息
						fclose(fphzk16);
					}
				}
				//开始画图
				for (k = 0; k < 16; k++) {
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							if (flag) {
								if (j == 0) {
									hdc_point(((cnt % (perline_word * 2) / 2) * 16 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//画点，要确定该点的坐标
								}
								else {//j==1
									hdc_point(((cnt % (perline_word * 2) / 2) * 16 + 8 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//画点，要确定该点的坐标
								}
							}
							else {
								;
							}

						}
					}
				}

				Sleep(delay_);//睡眠时间
				//还要将buffer清空
				for (int a = 0; a < 32; a++) {
					buffer[a] = 0;
				}
				cnt = word_num * 2 - 2 - cnt;//第二次循环时cnt的值会不同

			}
			cnt = temp;
			//Sleep(delay_);//睡眠时间
			//还要将buffer清空
			for (int a = 0; a < 32; a++) {
				buffer[a] = 0;
			}
		}
		break;
	case '3'://从内到外
		int cmop = 0;
		if (word_num % 2 == 0) {
			cmop = word_num - 2;
		}
		else {
			cmop = word_num - 1;
		}
		for (cnt =cmop; cnt >=0; cnt -= 2) {
			int temp = cnt;
			for (int circle = 0; circle < 2; circle++) {
				int offset = (94 * (unsigned int)(words[cnt] - 0xa0 - 1) \
					+ (words[cnt + 1] - 0xa0 - 1)) * 32;
				if (wordtype == 0) {//繁体字库
					fphzk16f = fopen("HZK16F", "rb");
					if (fphzk16f == NULL) {
						cout << "无法打开字库文件HZK16F\n";
						public_pause_enter("请按任意键继续. . .");
						return;
					}
					if (fphzk16f == 0) {
						return;
					}
					else {
						fseek(fphzk16f, offset, SEEK_SET);
						fread(buffer, 1, 32, fphzk16f);//读取一共32个点阵信息
						fclose(fphzk16f);
					}
				}
				else {//简体字库
					fphzk16 = fopen("HZK16", "rb");
					if (fphzk16 == NULL) {
						cout << "无法打开字库文件HZK16\n";
						public_pause_enter("请按任意键继续. . .");
						return;
					}
					if (fphzk16 == 0) {
						return;
					}
					else {
						fseek(fphzk16, offset, SEEK_SET);
						fread(buffer, 1, 32, fphzk16);//读取一共32个点阵信息
						fclose(fphzk16);
					}
				}
				//开始画图
				for (k = 0; k < 16; k++) {
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							if (flag) {
								if (j == 0) {
									hdc_point(((cnt % (perline_word * 2) / 2) * 16 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//画点，要确定该点的坐标
								}
								else {//j==1
									hdc_point(((cnt % (perline_word * 2) / 2) * 16 + 8 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//画点，要确定该点的坐标
								}
							}
							else {
								;
							}

						}
					}
				}

				Sleep(delay_);//睡眠时间
				//还要将buffer清空
				for (int a = 0; a < 32; a++) {
					buffer[a] = 0;
				}
				cnt = word_num * 2 -2- cnt;//第二次循环时cnt的值会不同

			}
			cnt = temp;
			//Sleep(delay_);//睡眠时间
			//还要将buffer清空
			for (int a = 0; a < 32; a++) {
				buffer[a] = 0;
			}
		}
		break;
	}
		
	
	
	public_pause_enter("按回车键继续");
	//cct_setcolor();
	
	cct_setfontsize("新宋体", 16);
	cct_setconsoleborder(123, 38);//设置窗口
	public_cin_end_to_continue();
	cct_cls();
}