/*2052316 ��07 ��t��*/
#pragma once
/* -----------------------------------------

	 ���ļ����ܣ�
	
	1��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	2�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ----------------------------------------- */
#define MINE_ARRAYLINE    18
#define MINE_ARRAYCOL     32
#define BODER1            10
#define BODER2            17
#define BODER3            31
#define REVEAL            1000
#define MINEMIN           10
#define MINEMED           40
#define MINEMAX           99
#define LINECOLMIN         9
#define LINECOLMED        16
#define COLMAX            30

//ɨ�׹�ģѡ����
int difficulty_choice();
//�س�����ͣ������
void pause_enter();
//���߿�ĺ�����
void graph_gmw_mine_sweeper(int nandu);
//�ݹ�Ѱ�Һ���
void digui_sweeper(int nandu, int num1, int num2, int minesweeper[][MINE_ARRAYCOL]);
//���ݵ�һ����������������ĺ���
void makeup_mine(int num1, int num2, int nandu, int mine_array[][MINE_ARRAYCOL]);
//�ж���Ϸ�Ƿ�����ĺ���
int judge_game_isover(int nandu, int mine_sweeper[][MINE_ARRAYCOL], int* left_mine);
int graph_continue_mine_sweeper(CONSOLE_GRAPHICS_INFO* minesweeperCGI, int nandu, float* curtime, float begintime, int mine[][MINE_ARRAYCOL]);
