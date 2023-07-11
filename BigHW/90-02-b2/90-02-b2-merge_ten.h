/*2052316 信07 李祎娜*/
#pragma once
/* -----------------------------------------
	 本文件功能：
	1、合成十的私有头文件
   ----------------------------------------- */
#define MERGE_MAX_LINE     10
#define MERGE_MAX_SCALE   12
#define MERGE_L            8
#define MERGE_C            10
//获得合成十的行列和合成目标的函数
//生成初始化内部数组值的函数
void merge_array_setup(int line, int column, int star_array[][MERGE_MAX_SCALE]);
void get_line_column(int* line, int* column, int* target);
void full_version_gmw_merge_ten(int line, int column, int array[][MERGE_MAX_SCALE],int target);