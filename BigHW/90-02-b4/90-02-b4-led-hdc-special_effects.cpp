/*2052316 ��07 ��t��*/
//��cpp���ܣ�����hdc��ͼ�������led��ʾ��Ч��
/*��Ӧ�˵���2.3����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
#include "../include/cmd_console_tools.h"
#include "../include/cmd_hdc_tools.h"
#include"../include/menu_combine.h"
#include "../include/cmd_gmw_tools.h"
#include "../include/basic_public.h"

using namespace std;
/************************************************************************************
�������ƣ�simplified_Chinese_low_version()
����������
�������ܣ�ʵ��demo�Ĳ˵���2.ģ��LED��Ϣ��ʾ-��������-��*��ʾÿ����
  -- ��ʾʱ����������Ϊ����6����ɺ󰴻س�����
��Ӧ�˵���2����
************************************************************************************/
void simplified_Chinese_low_version()
{
	FILE* fphzk16;
	cct_setfontsize("������", 6);
	cct_setconsoleborder(320, 98, 320,98);//���ô���
	
	unsigned char storage[] = "�ڡ��ס��ʡ�������ר����֣�¶��Ŀ�У�������̸����������ù���Ա���ڵص�λ����ְ�����Դˣ�������֣�¶��ʾ����������һֱ��\0";//�������ı�
	unsigned char buffer[32] = {0};//��ŵ�����Ϣ
	int k,j,i,cnt;
	unsigned char key[8] = {
	   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};//������ң�
	
	int flag;//��¼Ҫ���ĵ�
	for ( cnt = 0; cnt<120; cnt+=2) {
		int offset = (94 * (unsigned int)(storage[cnt] - 0xa0 - 1) \
			+ (storage[cnt+1] - 0xa0 - 1)) * 32;
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
		//����Ҫ��ʼ��ͼ
		cct_setcolor(0,10);//��ɫ
		cct_gotoxy((cnt % 20) * 16, (cnt / 20) * 16);
		for (k = 0; k < 16; k++) {
			for (j = 0; j < 2; j++) {
				for (i = 0; i < 8; i++) {
					flag = buffer[k * 2 + j] & key[i];
					
					printf("%s ", flag ? "*" : " ");
				}
			}
			cct_gotoxy((cnt % 20) * 16, (cnt / 20) * 16 + k + 1);
		}
		//��Ҫ��buffer���
		for (int a = 0; a < 32; a++) {
			buffer[a] = 0;
		}
	}
	public_pause_enter();
	cct_setfontsize("������",16);
	cct_setconsoleborder(120, 30);
	public_cin_end_to_continue();
	cct_cls();
	cct_setcolor();
	return;
}
/************************************************************************************
�������ƣ�traditional_Chinese_low_version()
����������
�������ܣ�ʵ��demo�Ĳ˵�3.3.ģ��LED��Ϣ��ʾ-��������-hdc_porint��ÿ����
  -- ����ʱ��ÿ����ֱ��Ϊ6����ɺ󰴻س�����
  -- ÿ����֮����2ms��ʱ
************************************************************************************/
void traditional_Chinese_low_version()
{
	//Ҫ�õ�hdc�ĺ����������л������ʱΪ2ms
	FILE* fphzk16f;
	cct_setfontsize("������", 16);
	cct_setconsoleborder(123,38,123,38);//���ô���
	unsigned char storage[] = "�ڡ��ס��ʡ�������ר����֣�¶��Ŀ�У�������̸����������ù���Ա���ڵص�λ����ְ�����Դˣ�������֣�¶��ʾ����������һֱ��\0";//�������ı�
	unsigned char buffer[32] = { 0 };//��ŵ�����Ϣ
	int k, j, i, cnt;
	unsigned char key[8] = {
	   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};//������ң�

	int flag;//��¼Ҫ���ĵ�
	hdc_cls();//�������������޷���
	//ÿ����֮�����������ʱ
	for (cnt = 0; cnt < 120; cnt += 2) {
		int offset = (94 * (unsigned int)(storage[cnt] - 0xa0 - 1) \
			+ (storage[cnt + 1] - 0xa0 - 1)) * 32;
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
		//����Ҫ��ʼ��ͼ
		//�˴��Ļ�ͼҪ����hdc���߼�
		
		//cct_gotoxy((cnt % 20) * 16, (cnt / 20) * 16);
		for (k = 0; k < 16; k++) {
			for (j = 0; j < 2; j++) {
				for (i = 0; i < 8; i++) {
					flag = buffer[k * 2 + j] & key[i];
					if (flag) {
						if (j==0) {
							//hdc_circle(100, 100, 10, true, RGB(255, 255, 0));
							hdc_point(((cnt%20/2) * 16 + i)*6, ((cnt / 20) * 16 + k + 1) *6, 6, RGB(255, 255, 0));//���㣬Ҫȷ���õ������
						}
						else {//j==1
							hdc_point(((cnt%20/2) * 16 + 8+i)*6, ((cnt / 20) * 16 + k + 1) *6,6, RGB(255, 255, 0));//���㣬Ҫȷ���õ������
						}
						//cout << " ";
					}
					else {
						//printf("%s ", flag ? "*" : " ");
						;
					}
					
				}
			}
			//cct_gotoxy((cnt % 20) * 16, (cnt / 20) * 16 + k + 1);
		}
		//��Ҫ��buffer���
		for (int a = 0; a < 32; a++) {
			buffer[a] = 0;
		}
	}
	public_pause_enter();
	cct_cls();
	cct_setfontsize("������", 16);
	cct_setconsoleborder(100, 100);//���ô���
	public_cin_end_to_continue();
	cct_setcolor();
	return;
}
