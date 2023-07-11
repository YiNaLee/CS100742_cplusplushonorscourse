/*2052316 ��07 ��t��*/
//��cpp���ܣ������������˵��������á�����ѡ��ֵ��
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
�������ƣ�cin_one_Chinese_character()
����������
�������ܣ�����һ�����ֻ�ȫ�Ƿ���(����y��ʾ����),Ҫ��������������
��Ӧ�˵���1����
************************************************************************************/
void cin_one_Chinese_character()
{
	FILE* fphzk16 = NULL;//hzk16����ļ�ָ��
	FILE* fphzk16f = NULL;//hzk16f����ļ�ָ��
	unsigned char storage[32];//������������ַ�����
	unsigned char buffer[32];//��ȡ�ֿ���
	char type = 'n';//ȱʡ�Ǽ�����
	unsigned char key[8] = {
	   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};//������ң�
	int i, j,k;//ѭ������
	int flag;//��¼Ҫ���ĵ�
	int offset = 0;//�ں��ֿ��е�ƫ��ֵ
	while (1) {
		cout << "������һ�����ֻ�ȫ�Ƿ���(����y��ʾ����):";
		cin >> storage;//����֮��ֻȡ��һ�����֣�����Ҫ�ж�����ĵ�һ�������ǲ��Ǻ���
		cin.ignore(65536, '\n');
		if (storage[0] == 'Y' || storage[0] == 'y') {
			//����end����
			public_cin_end_to_continue();
			return;
		}
		cout << "�Ƿ���Ҫ��ʾ����(Y/n)";
		cin >> type;
		cin.ignore(65536, '\n');//��ջ�����
		//�����λ�ж������Ƿ��Ǻ��� 
		if (storage[0] / int(pow(2, 7)) == 0) {
			cout << "���ǺϷ���GB2312����(��λ�Ƿ�)\n";
			public_pause_enter("�밴���������. . .");
			cct_cls();
			continue;
		}
		//������ǺϷ��ĺ���
		if (type == 'y' || type == 'Y') {//���崦�����
			fphzk16f = fopen("HZK16F", "rb");
			if (fphzk16f == NULL) {
				cout << "�޷����ֿ��ļ�HZK16F\n";
				public_pause_enter("�밴���������. . .");
				return;
			}
			cout << "����ĺ�����                   ��" << storage[0] << storage[1] << endl;

		}
		else {//���崦�����
			fphzk16 = fopen("HZK16", "rb");
			if (fphzk16 == NULL) {
				cout << "�޷����ֿ��ļ�HZK16\n";
				public_pause_enter("�밴���������. . .");
				return;
			}

			cout << "����ĺ�����                   ��" << storage[0] << storage[1] << endl;
			
		}
		
		cout << "���ֵ���λ��                   ��" << int(storage[0] - 0xa0) << int(storage[1] - 0xa0) << endl;
		cout << "ǰ������ֵ��ڲ���             ��" << hex << int(storage[0]) << endl;
		cout << "�������ֵ��ڲ���             ��" << hex << int(storage[1]) << endl;

		offset = (94 * (unsigned int)(storage[0] - 0xa0 - 1) + (storage[1] - 0xa0 - 1)) * 32;
		cout << "��16�����ֿ��е�ƫ��ֵ��     ��" << dec << offset << endl;
		cout << "�ֿ��ж�����16*16�����ֵ��    ��\n";
		//һ����32���ֽڣ��ĸ�һС�飬�˸�����
		if (type == 'y' || type == 'Y') {
			//�������
			if (fphzk16f == 0) {
				return;
			}
			else {
				fseek(fphzk16f, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk16f);//��ȡһ��32��������Ϣ
				fclose(fphzk16f);
			}
			
		}
		else {
			if (fphzk16 == 0) {
				return;
			}
			else {
				fseek(fphzk16, offset, SEEK_SET);
				fread(buffer, 1, 32, fphzk16);//��ȡһ��32��������Ϣ
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
		//Ȼ���������滭����ͼ��

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
		public_pause_enter("�밴���������. . .");

		cct_cls();
	}

}
/************************************************************************************
�������ƣ�void interactive_input()
����������
�������ܣ��������룬�Ը�������������д���ɺ���ģʽ
��Ӧ�˵���4����
************************************************************************************/
void interactive_input()
{
	int set_cols, set_lines;//��Ļ��С
	int color_fg, color_bg;//������Ҫ��ʾ����ɫ ������led����ɫ��
	int font_size;//cmd�������С������led�����С��
	int hdc_radius;//ÿ�������ֱ������ͨ��6��
	int RGB1, RGB2, RGB3;//led�µ���ɫ
	int wordtype;//ѡ���廹�Ǽ���
	unsigned char words[1024] = "\0" ;//��Ҫ����512����
	cout << "��������Ļ��С�����磺123 38����ʾ��123��38���м��Կո�ָ�:\n";
	cout << "������뷶Χ���󡢹�С���������Ĭ���ԡ�123 38�����ڴ�С��ʾ,�����룺";
	cin >> set_cols >> set_lines;
	if (!cin) {
		cin.clear();
		cin.ignore(65536, '\n');
		set_cols = 123;
		set_lines = 38;
		//cct_setconsoleborder(123, 38, 123, 38);//���ô���
	}
	else if (set_cols < 120 || set_cols>240||set_lines<30||set_lines>50) {
		//cct_setconsoleborder(123, 38, 123, 38);//���ô���
		set_cols = 123;
		set_lines = 38;
	}
	else {
		;//cct_setconsoleborder(set_cols,set_lines,set_cols,set_lines);//���ô���
	}
	cout << "������Ļ��������Ҫ��ʾ����ɫ���硾0,7����ʾ������ɫ�����ְ�ɫ\n";
	cout << "�����������߷�Χ������Ĭ�ϡ�0,7������";
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
	cout << "�������ַ�ģʽ�������С����Χ��8-24����������Ĭ��ֵ16��";
	cin >> font_size;
	if (!cin) {
	    font_size = 16;
		cin.clear();
		cin.ignore(65536, '\n');
	}
	else if (font_size < 8 || font_size>24) {
		font_size = 16;
	}
	cout << "����hcd��ʽ��ÿ�����ֱ������Χ��3-10����������Ĭ��ֵ6��";
	cin >> hdc_radius;
	if (!cin) {
		hdc_radius = 6;
		cin.clear();
		cin.ignore(65536, '\n');
	}
	else if (hdc_radius < 3 || hdc_radius>10) {
		hdc_radius = 6;
	}
	cout << "��������������������֣���������512���֣�";
	cin >> words;
	cout << "ѡ��LED�����ֵ���ɫ���硾255 255 0����ʾ��ɫ,��ɫ���ʺϿ��ܵ��º�ɫ������\n";
	cout << "����������Ĭ�ϻ�ɫ��";
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
	cout << "���廹�Ǽ��壺��0.���壬1.���塿��(�������Ĭ�Ϸ���)";
	cin >> wordtype;
	if (!cin) {
		cin.clear();
		cin.ignore(65536, '\n');
		wordtype = 0;
	}
	else if (wordtype != 0 &&wordtype != 1) {
		wordtype = 0;
	}
	//ѡ�����չʾ��ģʽ��1��ʾ���µ��ϣ�2��ʾ���ҵ���3��ʾ���ڵ���
	cout << "ѡ��led��ЧΪ����ģʽ��[1]���µ������� [2]���⵽�� [3]���ڵ���\n";
	cout << "��ѡ��\n";
	int mode;
	while (1) {
		mode = getchar();
		if (mode >= '1' && mode <= '3') {
			break;
		}
	}
	int delay_;
	cout << "������ʱʱ��(ms),��������Ϊ20ms\n";
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
	hdc_set_delay(0);//��������Ϊ0����Ȼ̫��
	//������������ʵ��
	//Ϊ��չʾ������
	
	cct_setfontsize("����", font_size);
	cct_setconsoleborder(set_cols,set_lines,set_cols,set_lines);//���ô���
	cct_setcolor(color_bg, color_fg);
	
	//�ڽ���ʽ�¼���һ�п��Դ�������֣�
	int perline_word = set_cols / hdc_radius/2;
	//words
	unsigned char buffer[32] = { 0 };//��ŵ�����Ϣ
	int k, j, i, cnt;
	unsigned char key[8] = {
	   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};//������ң�
	int flag;//��¼Ҫ���ĵ�
	FILE* fphzk16f;//�����
	FILE* fphzk16;//�����
	//����һ��������ı�һ���ж�����
	int word_num=0;
	for (int i = 0; words[i] != '\0'; i++) {
		word_num++;
	}
	word_num /= 2;//word_num��ʾ��һ���ж�����
	
	//0��ʾ���壬1��ʾ����
	hdc_cls();//�������������޷���
	switch (mode) {
	case '1'://���µ��ϵ�ģʽ��
		for (cnt = (word_num - 1) * 2; cnt >= 0; cnt -= 2) {
			int offset = (94 * (unsigned int)(words[cnt] - 0xa0 - 1) \
				+ (words[cnt + 1] - 0xa0 - 1)) * 32;
			if (wordtype == 0) {//�����ֿ�
				fphzk16f = fopen("HZK16F", "rb");
				if (fphzk16f == NULL) {
					cout << "�޷����ֿ��ļ�HZK16F\n";
					public_pause_enter("�밴���������. . .");
					return;
				}
				if (fphzk16f == 0) {
					return;
				}
				else {
					fseek(fphzk16f, offset, SEEK_SET);
					fread(buffer, 1, 32, fphzk16f);//��ȡһ��32��������Ϣ
					fclose(fphzk16f);
				}
			}
			else {//�����ֿ�
				fphzk16 = fopen("HZK16", "rb");
				if (fphzk16 == NULL) {
					cout << "�޷����ֿ��ļ�HZK16\n";
					public_pause_enter("�밴���������. . .");
					return;
				}
				if (fphzk16 == 0) {
					return;
				}
				else {
					fseek(fphzk16, offset, SEEK_SET);
					fread(buffer, 1, 32, fphzk16);//��ȡһ��32��������Ϣ
					fclose(fphzk16);
				}
			}
			//��ʼ��ͼ
			for (k = 0; k < 16; k++) {
				for (j = 0; j < 2; j++) {
					for (i = 0; i < 8; i++) {
						flag = buffer[k * 2 + j] & key[i];
						if (flag) {
							if (j == 0) {
								hdc_point(((cnt % (perline_word * 2) / 2) * 16 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//���㣬Ҫȷ���õ������
							}
							else {//j==1
								hdc_point(((cnt % (perline_word * 2) / 2) * 16 + 8 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//���㣬Ҫȷ���õ������
							}
						}
						else {
							;
						}

					}
				}
			}
			Sleep(delay_);//˯��ʱ��
			//��Ҫ��buffer���
			for (int a = 0; a < 32; a++) {
				buffer[a] = 0;
			}
		}

		break;
	case '2'://���⵽��
		for (cnt = 0; cnt<word_num; cnt += 2) {
			int temp = cnt;
			for (int circle = 0; circle < 2; circle++) {
				int offset = (94 * (unsigned int)(words[cnt] - 0xa0 - 1) \
					+ (words[cnt + 1] - 0xa0 - 1)) * 32;
				if (wordtype == 0) {//�����ֿ�
					fphzk16f = fopen("HZK16F", "rb");
					if (fphzk16f == NULL) {
						cout << "�޷����ֿ��ļ�HZK16F\n";
						public_pause_enter("�밴���������. . .");
						return;
					}
					if (fphzk16f == 0) {
						return;
					}
					else {
						fseek(fphzk16f, offset, SEEK_SET);
						fread(buffer, 1, 32, fphzk16f);//��ȡһ��32��������Ϣ
						fclose(fphzk16f);
					}
				}
				else {//�����ֿ�
					fphzk16 = fopen("HZK16", "rb");
					if (fphzk16 == NULL) {
						cout << "�޷����ֿ��ļ�HZK16\n";
						public_pause_enter("�밴���������. . .");
						return;
					}
					if (fphzk16 == 0) {
						return;
					}
					else {
						fseek(fphzk16, offset, SEEK_SET);
						fread(buffer, 1, 32, fphzk16);//��ȡһ��32��������Ϣ
						fclose(fphzk16);
					}
				}
				//��ʼ��ͼ
				for (k = 0; k < 16; k++) {
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							if (flag) {
								if (j == 0) {
									hdc_point(((cnt % (perline_word * 2) / 2) * 16 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//���㣬Ҫȷ���õ������
								}
								else {//j==1
									hdc_point(((cnt % (perline_word * 2) / 2) * 16 + 8 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//���㣬Ҫȷ���õ������
								}
							}
							else {
								;
							}

						}
					}
				}

				Sleep(delay_);//˯��ʱ��
				//��Ҫ��buffer���
				for (int a = 0; a < 32; a++) {
					buffer[a] = 0;
				}
				cnt = word_num * 2 - 2 - cnt;//�ڶ���ѭ��ʱcnt��ֵ�᲻ͬ

			}
			cnt = temp;
			//Sleep(delay_);//˯��ʱ��
			//��Ҫ��buffer���
			for (int a = 0; a < 32; a++) {
				buffer[a] = 0;
			}
		}
		break;
	case '3'://���ڵ���
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
				if (wordtype == 0) {//�����ֿ�
					fphzk16f = fopen("HZK16F", "rb");
					if (fphzk16f == NULL) {
						cout << "�޷����ֿ��ļ�HZK16F\n";
						public_pause_enter("�밴���������. . .");
						return;
					}
					if (fphzk16f == 0) {
						return;
					}
					else {
						fseek(fphzk16f, offset, SEEK_SET);
						fread(buffer, 1, 32, fphzk16f);//��ȡһ��32��������Ϣ
						fclose(fphzk16f);
					}
				}
				else {//�����ֿ�
					fphzk16 = fopen("HZK16", "rb");
					if (fphzk16 == NULL) {
						cout << "�޷����ֿ��ļ�HZK16\n";
						public_pause_enter("�밴���������. . .");
						return;
					}
					if (fphzk16 == 0) {
						return;
					}
					else {
						fseek(fphzk16, offset, SEEK_SET);
						fread(buffer, 1, 32, fphzk16);//��ȡһ��32��������Ϣ
						fclose(fphzk16);
					}
				}
				//��ʼ��ͼ
				for (k = 0; k < 16; k++) {
					for (j = 0; j < 2; j++) {
						for (i = 0; i < 8; i++) {
							flag = buffer[k * 2 + j] & key[i];
							if (flag) {
								if (j == 0) {
									hdc_point(((cnt % (perline_word * 2) / 2) * 16 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//���㣬Ҫȷ���õ������
								}
								else {//j==1
									hdc_point(((cnt % (perline_word * 2) / 2) * 16 + 8 + i) * hdc_radius, ((cnt / (perline_word * 2)) * 16 + k + 1) * hdc_radius, hdc_radius, RGB(RGB1, RGB2, RGB3));//���㣬Ҫȷ���õ������
								}
							}
							else {
								;
							}

						}
					}
				}

				Sleep(delay_);//˯��ʱ��
				//��Ҫ��buffer���
				for (int a = 0; a < 32; a++) {
					buffer[a] = 0;
				}
				cnt = word_num * 2 -2- cnt;//�ڶ���ѭ��ʱcnt��ֵ�᲻ͬ

			}
			cnt = temp;
			//Sleep(delay_);//˯��ʱ��
			//��Ҫ��buffer���
			for (int a = 0; a < 32; a++) {
				buffer[a] = 0;
			}
		}
		break;
	}
		
	
	
	public_pause_enter("���س�������");
	//cct_setcolor();
	
	cct_setfontsize("������", 16);
	cct_setconsoleborder(123, 38);//���ô���
	public_cin_end_to_continue();
	cct_cls();
}