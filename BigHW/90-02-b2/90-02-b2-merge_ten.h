/*2052316 ��07 ��t��*/
#pragma once
/* -----------------------------------------
	 ���ļ����ܣ�
	1���ϳ�ʮ��˽��ͷ�ļ�
   ----------------------------------------- */
#define MERGE_MAX_LINE     10
#define MERGE_MAX_SCALE   12
#define MERGE_L            8
#define MERGE_C            10
//��úϳ�ʮ�����кͺϳ�Ŀ��ĺ���
//���ɳ�ʼ���ڲ�����ֵ�ĺ���
void merge_array_setup(int line, int column, int star_array[][MERGE_MAX_SCALE]);
void get_line_column(int* line, int* column, int* target);
void full_version_gmw_merge_ten(int line, int column, int array[][MERGE_MAX_SCALE],int target);