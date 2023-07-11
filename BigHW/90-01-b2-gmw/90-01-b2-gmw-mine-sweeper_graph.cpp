/* ��07 2052316 ��t�� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include"../include/cmd_console_tools.h"
#include"../include/cmd_gmw_tools.h"
#include "90-01-b2-gmw.h"
#include"../include/basic_public.h"
using namespace std;
/*���ļ����ܣ�αͼ�ν�����غ�����ʵ��*/
/*ֻ��Ӧɨ��������*/
/*˵����Ϊ�˷��㿴�������Ȼ������ޱ߿򣬵��ǽ������Сɫ����˱߿�*/

/**********************************************
�������ƣ�
���������
�������ܣ�
����ֵ��
˵����
***********************************************/




/******************************************
�������ƣ�difficulty_choice
�������ܣ������ѶȲ�����ѡ��
��������ֵ���Ѷ�ѡ��1-3
******************************************/
int difficulty_choice()
{
	/*����*/
	cct_cls();
	int choice;
	cout << "��ѡ���Ѷȣ�\n";
	cout << "  1.����(9*9   - 10����)\n";
	cout << "  2.�м�(16*16 - 40����)\n";
	cout << "  3.�߼�(16*30 - 99����)\n";
	cout << "������[1..3]:\n";
	while (1)
	{
		choice = _getch();
		if (choice >= '1' && choice <= '3')
			break;
	}
	return choice - '0';
}

/**********************************************
�������ƣ�pause_enter()
���������
�������ܣ����ô˺�����ʵ�ְ��س��������Ĺ���
����ֵ��
˵����
***********************************************/
void pause_enter()
{
	cout << endl;
	cout << "���س�������...";
	while (1)
	{
		int enter = _getch();
		if (enter == '\r')
			break;
	}

}
/**********************************************
�������ƣ�make_up_mine()
���������num1��ʾ��һ�ε㿪����/num2��ʾ��һ�ε㿪���У��Ѷȱ�ʾѡ���1/2/3 �ֱ��Ӧ9*9  16*16��16*30
�������ܣ����ô˺������������ɨ�׵��׵�λ��
����ֵ����ɱ�������ɨ���ڲ�����ĳ�ʼֵ�Ѿ�����
˵����
***********************************************/
void makeup_mine(int num1, int num2, int nandu, int mine_array[][MINE_ARRAYCOL])
{
	int i,j,MINE_NUM=0,MAX_X=0,MAX_Y=0;
	switch (nandu) {
		case 1:
			MINE_NUM = 10;//����Ϊ10
			MAX_X = 9;//��ģΪ9*9
			MAX_Y = 9;//ʵ��������Ϊ�˷�����㣬�õ���11*11
			break;
		case 2:
			MINE_NUM = 40;
			MAX_X = 16;//��ģΪ16*16
			MAX_Y = 16;//ʵ�������õ�����18*18
			break;
		case 3:
			MINE_NUM = 99;
			MAX_X = 16;//��ģΪ16*16
			MAX_Y = 30;//ʵ�������õ�����18*30
			break;
	}

	for (i = 0; i < MINE_NUM; i++)
	{
		while (1)
		{
			int X, Y;
			X = rand() % MAX_X + 1;
			Y = rand() % MAX_Y + 1;
			if (abs(X - num1) <= 1 && abs(Y - num2) <= 1) {//ѡ��λ�õ���Χ�˸�λ�ñ��벻����
				continue;
			}
			if (mine_array[X][Y] == 0)//�����и���
			{
				mine_array[X][Y] = '*';//������������е���
				break;
			}
			else
				continue;
		}

	}
	/*Ȼ��Ϊ����λ����Χ��ֵ*/
	for (i = 1; i <=MAX_X; i++)
	{
		for (j = 1; j <=MAX_Y; j++)
		{
			if (mine_array[i][j] != '*')//��Χ8��
			{
				if (mine_array[i - 1][j] == '*')
					mine_array[i][j]++;

				if (mine_array[i + 1][j] == '*')
					mine_array[i][j]++;

				if (mine_array[i][j - 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i][j + 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i - 1][j - 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i - 1][j + 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i + 1][j - 1] == '*')
					mine_array[i][j]++;

				if (mine_array[i + 1][j + 1] == '*')
					mine_array[i][j]++;
			}
		}
	}
	
}
void digui_sweeper(int nandu, int num1, int num2, int minesweeper[][MINE_ARRAYCOL])
{
	int borderline=0, bordercol=0;
	switch (nandu) {
		case 1:
			borderline = BODER1;
			bordercol = BODER1;
			break;
		case 2:
			borderline = BODER2;
			bordercol = BODER2;
			break;
		case 3:
			borderline = BODER2;
			bordercol = BODER3;
			break;
	}
	if (num1 == 0 || num1 == borderline || num2 == 0 || num2 ==bordercol)//����߽緶Χ��ֹͣ��ɢ
		return;
	if (minesweeper[num1][num2] == 0) {
		reveal(&minesweeper[num1][num2]);//�����Ϊ0��λ�ô�
		digui_sweeper(nandu, num1 - 1, num2, minesweeper);//�ݹ���� һ��ҪѰ�Ұ˸�λ��
		digui_sweeper(nandu, num1, num2 - 1, minesweeper);
		digui_sweeper(nandu, num1 + 1, num2, minesweeper);
		digui_sweeper(nandu, num1, num2 + 1, minesweeper);
		digui_sweeper(nandu, num1 + 1, num2 + 1, minesweeper);
		digui_sweeper(nandu, num1 - 1, num2 + 1, minesweeper);
		digui_sweeper(nandu, num1 - 1, num2 - 1, minesweeper);
		digui_sweeper(nandu, num1 + 1, num2 - 1, minesweeper);
	}
	
	else if (minesweeper[num1][num2] > 0 && minesweeper[num1][num2] <= 10) {
		//����Ƿ�0���ǵ��׵�λ�� ����¶��λ�ú�����ֹͣ
		reveal(&minesweeper[num1][num2]);
		return;
	}
	else if (minesweeper[num1][num2] == '*') {
		//����򿪵�λ�����ף���ӡ���׺���Ϸ����
		reveal(&minesweeper[num1][num2]);
		return;
	}
}
/**********************************************
�������ƣ�graph_gmw_mine_sweeper()
���������int x,int nandu
�������ܣ���Ӧ�˵���9������gmw�еĺ���
����ֵ��
˵����
***********************************************/
void graph_gmw_mine_sweeper(int nandu)
{
	int line=0, col=0;
	CONSOLE_GRAPHICS_INFO MineSweeper_CGI; //����һ��CGI����
	//9*9��16*16��16*30 �ʵ��Ŵ���18*32
	/*��ȱʡֵ��ʼ�������ڱ�����/ǰ���ף�����16*8�����������޶������У�����״̬�����У����к�/�б꣬�������Ϊ˫�ߣ�ɫ����2/�߶�1/��С�߿���ɫ�ԣ�*/
	gmw_init(&MineSweeper_CGI);
	//�����ָ���
	gmw_set_frame_style(&MineSweeper_CGI, 6, 3, false);//ɫ�鲻���ָ��߸߶���4
	//��Ҫ�޸ĵ�����Ϸ�������ɫ����Ϸ�����и����������
	//Ҫ��Ϊ��ʾ�б���б�
	gmw_set_rowno_switch(&MineSweeper_CGI, true);							//��ʾ�к�
	gmw_set_colno_switch(&MineSweeper_CGI, true);							//��ʾ�б�
	//��������Ϸ����Ϊ����ɫ��ɫ����ɫΪ��ɫ����������
	gmw_set_frame_color(&MineSweeper_CGI, COLOR_HWHITE, COLOR_BLACK);
	//ɫ�������ɫ���û�ɫ�麯��ʱ�Ÿ� 
	const BLOCK_DISPLAY_INFO bdi_sweeper[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0����ʾ���ÿո���伴��
		{1,  COLOR_HWHITE, COLOR_HCYAN, "1"},	//1��ʾ��һ���� ����ɫ������ͬ
		{2, COLOR_HWHITE, COLOR_HBLUE, "2"},
		{3,  COLOR_HWHITE, COLOR_HRED, "3"},
		{4,  COLOR_HWHITE, COLOR_HRED, "4"},
		{5,  COLOR_HWHITE, COLOR_HBLACK, "5"},
		{6,  COLOR_HWHITE, COLOR_BLUE, "6"},
		{7,  COLOR_HWHITE, COLOR_RED, "7"},
		{8, COLOR_HWHITE, COLOR_RED, "8"},
		{10,COLOR_YELLOW + 1,-1,"  "},//����10�����λ��û�б���
		{-100,COLOR_RED + 1,-1,"#"},//-100��ʾ��Ǹ�λ��Ϊ��
		{42,COLOR_HWHITE,COLOR_BLACK,"*"},//42��ʾ��λ������
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	//ɫ����ɫû��Ĭ���ǻ�ɫ���򿪺��ǰ�ɫ����ܱ���ɫ
	//
	switch (nandu) {
		case 1://9*9
			gmw_set_rowcol(&MineSweeper_CGI, LINECOLMIN, LINECOLMIN);
			line = LINECOLMIN;
			col = LINECOLMIN;
			break;
		case 2:
			gmw_set_rowcol(&MineSweeper_CGI, LINECOLMED, LINECOLMED);
			line = LINECOLMED;
			col = LINECOLMED;
			break;
		case 3:
			gmw_set_rowcol(&MineSweeper_CGI, LINECOLMED, COLMAX);
			line = LINECOLMED;
			col = COLMAX;
			break;
	}
	//ɫ��Ĭ�ϸ�Ϊ��ҪС�߿�
	gmw_set_block_border_switch(&MineSweeper_CGI, true);
	gmw_draw_frame(&MineSweeper_CGI);
	int mine_array[MINE_ARRAYLINE][MINE_ARRAYCOL] = { 0 };
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			//���ֵС��10����û�б���
			gmw_draw_block(&MineSweeper_CGI, i, j, 10, bdi_sweeper);//��ʼ�����ǻ�ɫ��
		}
	}
	gmw_set_status_line_color(&MineSweeper_CGI, TOP_STATUS_LINE, COLOR_BLACK, COLOR_HWHITE, COLOR_BLACK, COLOR_HYELLOW);
	gmw_set_status_line_color(&MineSweeper_CGI, LOWER_STATUS_LINE, COLOR_BLACK, COLOR_HWHITE,COLOR_BLACK, COLOR_HYELLOW);
	//Ȼ�������������������ݵ�һ�ε����λ�ã������أ����ף�
	gmw_status_line(&MineSweeper_CGI, TOP_STATUS_LINE, "�Ҽ���ǻ�ȡ�����Ϊ��","��ESC�˳����ո���ʾʱ��");
	int loop = 1;
	int maction,mrow = -1, mcol = -1;
	int keycode1, keycode2;
	int ret;
	char temp[256] = " ";
	float begin_time = float(clock() / 1000.0);
	//��Ϸ��ʼʱ�����г�ʼʱ��
	float cultime = 0;
	while (loop) {
		//old_mrow = mrow;
		//old_mcol = mcol;
		ret = gmw_read_keyboard_and_mouse(&MineSweeper_CGI, maction, mrow, mcol, keycode1, keycode2);
		//������mrowΪ��ʾ�������У�ʵ�������е����ж�Ҫ����+1
		if (ret == CCT_MOUSE_EVENT) {
			if (maction == MOUSE_ONLY_MOVED) {
				//�ƶ���״̬����ʾ����ǰλ�ã�
			}
			else {//��һ�ζ�����Ч��������Ҽ�����ʼ����
				//�˳�ѭ������һ�ζ�����λ����mrow��mcol
				loop = 0;
			}
		}
		else { //CCT_KEYBOARD_EVENT - ������뺬��ȥ�� cmd_console_tools.cpp
			switch (keycode1) {
				case 32://�ո���ʾʱ��
					//cout << "��ǰʱ��" << float(clock() / 1000.0) - begin_time << "��,";��sprintfд
					cultime= float(clock() / 1000.0 - begin_time);
					sprintf(temp, "��ǰʱ��%lf�룬ESC�˳����ո���ʾʱ��",cultime);
					gmw_status_line(&MineSweeper_CGI, TOP_STATUS_LINE, temp);//������
					
					break;
				case 27: 
					loop = 0;
					break;
				default:
					break;
			}//end of switch
		}//end of else
	}//end of while
	int num1 = mrow + 1;
	int num2 = mcol + 1;
	makeup_mine(num1, num2, nandu, mine_array);//���ף�
	//��һ�ε㿪��Ҫ�õݹ鷽��,Ѱ���ܱ�ȫΪ0�����鲢��,�򿪵ı�Ǿ��ǽ������ڲ���ֵ����1000��
	digui_sweeper(nandu,num1, num2, mine_array);
	//�ٴ�ӡһ�Σ�
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			//���ֵС��10������Ȼ�Ի�ɫ
			if (mine_array[i+1][j+1]>=0&&mine_array[i+1][j+1]<=10||mine_array[i+1][j+1]=='*'){
				gmw_draw_block(&MineSweeper_CGI, i, j, 10, bdi_sweeper);//С��1000��û�б��򿪣��ǻ�ɫ��
			}
			else {
				gmw_draw_block(&MineSweeper_CGI, i, j, mine_array[i+1][j+1]%100, bdi_sweeper);//
			}
		}
	}
	int fanhuizhi = graph_continue_mine_sweeper(&MineSweeper_CGI, nandu, &cultime, begin_time, mine_array);
	
	cct_gotoxy(MineSweeper_CGI.start_x, MineSweeper_CGI.start_y + MineSweeper_CGI .CFI.bhigh+1);
	pause_enter();
	
	
}
/**********************************************
�������ƣ�graph_continue_mine_sweeper()
���������int x,int nandu
�������ܣ�ѭ��ִ��ֱ�������׻���Ϸ������
����ֵ��
˵����
***********************************************/
int graph_continue_mine_sweeper(CONSOLE_GRAPHICS_INFO* minesweeperCGI,int nandu,float*curtime,float begintime,int mine[][MINE_ARRAYCOL])
{//���ṹ��������������ݽ�����
	int line = 0;
	int col= 0;
	const BLOCK_DISPLAY_INFO bdi_sweeper[] = {
		{BDI_VALUE_BLANK, COLOR_HWHITE, COLOR_GREEN, "  "},  //0����ʾ���ÿո���伴��
		{1,  COLOR_HWHITE, COLOR_HCYAN, "1"},	//1��ʾ��һ���� ����ɫ������ͬ
		{2, COLOR_HWHITE, COLOR_HBLUE, "2"},
		{3,  COLOR_HWHITE, COLOR_HRED, "3"},
		{4,  COLOR_HWHITE, COLOR_HRED, "4"},
		{5,  COLOR_HWHITE, COLOR_HBLACK, "5"},
		{6,  COLOR_HWHITE, COLOR_BLUE, "6"},
		{7,  COLOR_HWHITE, COLOR_RED, "7"},
		{8, COLOR_HWHITE, COLOR_RED, "8"},
		{10,COLOR_YELLOW + 1,-1,"  "},//����10�����λ��û�б���
		{-100,COLOR_RED + 1,-1,"#"},//-100��ʾ��Ǹ�λ��Ϊ��
		{42,COLOR_HWHITE,COLOR_BLACK,"*"},//42��ʾ��λ������
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	int left_mine = 0;//ʣ������
	int all_mine = 0;
	switch (nandu) {
		case 1://9*9
			
			line = LINECOLMIN;
			col = LINECOLMIN;
			all_mine = 10;
			break;
		case 2:
			line = LINECOLMED;
			col = LINECOLMED;
			all_mine = 40;
			break;
		case 3:
			line = LINECOLMED;
			col = COLMAX;
			all_mine = 99;
			break;
			
	}
	while (1) {
		int loop = 1;
		int maction, old_mrow, old_mcol, mrow = -1, mcol = -1;
		int keycode1, keycode2;
		int ret;
		char temp[256] = " ";
		while (loop) {
			old_mrow = mrow;
			old_mcol = mcol;
			ret = gmw_read_keyboard_and_mouse(minesweeperCGI, maction, mrow, mcol, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				if (maction == MOUSE_ONLY_MOVED) {
					//�ƶ���״̬����ʾ����ǰλ�ã�
				}
				else {
					loop = 0;
				}
			}
			else { //CCT_KEYBOARD_EVENT - ������뺬��ȥ�� cmd_console_tools.cpp
				switch (keycode1) {
					case 32://�ո���ʾʱ��
						//cout << "��ǰʱ��" << float(clock() / 1000.0) - begin_time << "��,";��sprintfд
						*curtime = float(clock() / 1000.0 - begintime);
						sprintf(temp, "��ǰʱ��%lf�룬ESC�˳����ո���ʾʱ��", *curtime);
						gmw_status_line(minesweeperCGI, TOP_STATUS_LINE, temp);//������

						break;
					case 27:
						loop = 0;
						return -99;//��ǰ���esc��������ֵ
						break;
					default:
						break;
				}//end of switch
			}//end of else
		}//end of while
		int num1 = mrow + 1;
		int num2 = mcol + 1;
		if (maction == MOUSE_LEFT_BUTTON_CLICK) {
			//����Ļ���
			digui_sweeper(nandu, num1, num2, mine);
		}
		if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
			//�Ҽ���
			if (mine[num1][num2] < REVEAL && mine[num1][num2] >= 0) {
				//û�б��򿪹������Ա��Ϊ��
				mine[num1][num2] -= 99999;
			}
			else if (mine[num1][num2] < 0) {
				//ȡ�����Ϊ�ס�
				mine[num1][num2] += 99999;
			}
		}
		//�ٴ�ӡһ�Σ�
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				if (mine[i+1][j+1] < 1000&&mine[i+1][j+1]>=0) {//û�б���
					gmw_draw_block(minesweeperCGI, i, j, 10, bdi_sweeper);//��ʼ�����ǻ�ɫ��
				}
				else {	
					if (mine[i+1][j+1]<0) {
						//���ڲ�ֵ-99999����Ϊ����ǵı�־�����������ˣ����ܴ򿪡�
						gmw_draw_block(minesweeperCGI, i, j, -100, bdi_sweeper);//-100��ʾ��Ǹô�Ϊ��
					}
					else {//���򿪣��������������������׵������
						gmw_draw_block(minesweeperCGI, i, j, mine[i+1][j+1] % 100, bdi_sweeper);//
					}
					
				}
			}
		}
		//Ȼ�����ж���Ϸ�Ƿ���������Ҽ���ʣ���׵�������ӡ����״̬���ϡ�
		int gameover = judge_game_isover(nandu, mine,&left_mine);
		sprintf(temp, "ʣ������%d������ESC���˳����ո���ʾʱ��                   ", all_mine-left_mine);
		gmw_status_line(minesweeperCGI, TOP_STATUS_LINE, temp);
		if (gameover == 0) {
			//��Ϸ��������״̬����ӡ���˳�ѭ����
			gmw_status_line(minesweeperCGI, LOWER_STATUS_LINE, "���س�������","��Ϸ������������,");
			return 0;
		}
		if (gameover == 1) {
			//��Ϸ������
			continue;
		}
		if (gameover == 2) {
			float alltime=float(clock() / 1000.0 - begintime);
			sprintf(temp, "һ����ʱ%lf��.", alltime);
			gmw_status_line(minesweeperCGI, LOWER_STATUS_LINE, temp,"��ϲ�㣬��Ӯ��!");
			return 2;
		}
	}
}

/***************************************
�������ƣ�judge_game()
���������nandu,mine_array
���ܣ��ж���Ϸ�Ƿ�ɹ�
����ֵ�� ����1˵����Ϸ�����Լ���������2˵����Ϸ�ɹ�������0˵����Ϸʧ��
˵����
****************************************/
int judge_game_isover(int nandu,int mine_sweeper[][MINE_ARRAYCOL],int*pop_mine)
{
	int i, j;
	int counter = 0;//���ڼ����м�����
	int borderline = 0;//����
	int bordercol = 0;//����
	int mine_num = 0;//����
	*pop_mine = 0;
	switch (nandu)
	{
		case 1:
			borderline = BODER1;
			bordercol = BODER1;
			mine_num = MINEMIN;
			break;
		case 2:
			borderline = BODER2;
			bordercol = BODER2;
			mine_num = MINEMED;
			break;
		case 3:
			borderline = BODER2;
			bordercol = BODER3;
			mine_num = MINEMAX;
			break;
	}
	for (i = 1; i < borderline; i++) {
		for (j = 1; j < bordercol; j++) {
			if (mine_sweeper[i][j] <0) {
				(*pop_mine)++;
			}
		}
	}
	for (i = 1; i < borderline; i++) {
		for (j = 1; j < bordercol; j++) {
			/*if (mine_sweeper[i][j] < 0) {
				mine_sweeper[i][j] += 99999;//���»�ԭ��
			}*/
			if (mine_sweeper[i][j] == '*' + REVEAL)
				return 0;//��Ϸʧ��,֤��Ϊ�׵������Ѿ�����
			if (mine_sweeper[i][j] < REVEAL)//��������е�ֵС��һǧ��˵��������û�б���
				counter++;

		}
	}
	if (counter == mine_num)
		return 2;//��Ϸ�ɹ�
	else
		return 1;//��Ϸ����

	
}
