/*2052316 ��07 ��t��*/
#pragma once
/* -----------------------------------------
	 ���ļ����ܣ�
	1���޷ָ��߰汾�������ǵ�˽��ͷ�ļ�
   ----------------------------------------- */
#define STARMAX    12
#define STAR       10




//������д�С���������д�С�����������
void get_line_column(int* line, int* column);
void star_array_setup(int line, int column, int star_array[STARMAX][STARMAX]);
//��Ϸ����ܺ�ɫ�飬����gmw���ߵĺ���
int gmw_popstar_full_version(int line, int column, int star_array[][STARMAX]);
//�������亯��
void gmw_downstar(int line, int column, int star_array[][STARMAX], CONSOLE_GRAPHICS_INFO* pCGI);
//�������㺯��
int cal_left_num(int line, int column, int array[][STARMAX]);
void pause_enter(const char* prompt);
