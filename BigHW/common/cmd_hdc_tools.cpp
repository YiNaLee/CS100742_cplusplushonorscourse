/* 2052316 信07 李祎娜 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "../include/cmd_hdc_tools.h"
using namespace std;

#if !HDC_SERIES_BY_TEACHER	//未定义的情况下才打开条件编译
//自己写的函数在这条件下运行
/* 允许添加需要的头文件 */

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow(); //VS中此处会有波浪线，不影响正常使用

/* 已定义的静态全局变量 */
static HWND hWnd = GetConsoleWindow();
static HDC hdc = NULL;
static const double PI = 3.14159;
static int _BgColor_, _FgColor_, _Width_, _High;
static int _Delay_ms=0;//默认如果不设置，值为0

/* 允许适度使用静态全局变量，但仅限static，即外部不可见 */

/* 此处允许添加自定义函数，但仅限static，即外部不可见 */
/***************************************************************************
  函数名称：cul_area()
  功    能：计算三角形面积
  输入参数：三个点的坐标，用向量叉乘计算
  返 回 值：
  说    明：
***************************************************************************/
static double cul_area(const int Ax,const int Ay,const int Bx,const int By,const int Cx,const int Cy)
{
	//double result = abs(((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3))/2.0);
	double s = abs((double(Ax) * By + Bx * Cy + Cx * Ay - Ay * Bx - By * Cx - Cy * Ax) / 2.0);
	//cout << "s="<< s << endl;
	return s;
}
/*计算面积的重载，用于计算矩形中的三角形面积*/
static int judge_is_in_triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, const int x, const int y)
{
	double sum_area = cul_area(x1, y1, x2, y2, x3, y3);
	double area01 = cul_area(x1, y1, x2, y2, x, y);
	double area02 = cul_area(x1, y1, x3, y3, x, y);
	double area03 = cul_area(x2, y2, x3, y3, x, y);
	if (abs(sum_area-(area01+area02+area03))<=1e-1) {
		//认为在内部
		return 1;
	}
	else
		return 0;
}
static int judge_is_in_rectangle(const int x1,const int y1,const int x2,const int y2,
	const int x3,const int y3,const int x4,const int y4,const int x,const int y,const int width,const int high)
{
	double all_area = width * high;//矩形总面积是长乘宽
	double area01 = abs(cul_area(x1, y1, x2, y2, x, y));
	double area02 = abs(cul_area(x2, y2, x3, y3, x, y));
	double area03 =abs( cul_area(x3, y3, x4, y4, x, y));
	double area04 = abs(cul_area(x4, y4, x1, y1, x, y));
	if (abs(all_area - (area01 + area02 + area03+area04)) <= 1e-1) {
		//认为在内部
		return 1;
	}
	else
		return 0;
}
/*如果在扇形内部则返回1，否则返回0*/
/*static int judge_is_insector(int x,int y,int radius, const int point_x, const int point_y,int borderx,int bordery,int inclination)
{
	if ((x - point_x) * (x - point_x) + (y - point_y) * (y - point_y) > radius * radius) {
		return 0;//不在内部
	}
	//然后计算该点与一条边线的夹角
	//三点连为一个三角形，计算三角形的夹角即可
	double a = sqrt((x - point_x) * (x - point_x) + (y - point_y) * (y - point_y));
	double b= sqrt((x - borderx) * (x - borderx) + (y - bordery) * (y - bordery));
	double c = sqrt((borderx - point_x) * (borderx - point_x) + (bordery - point_y) * (bordery - point_y));
	//计算夹角cosB和inclination比较
	//这里还是待修正！
}*/


/* 下面给出了几个基本函数的完整实现，不要改动 */
/***************************************************************************
  函数名称：
  功    能：初始化
  输入参数：const int bgcolor：背景色
            const int fgcolor：前景色
			const int width  ：屏幕宽度（点阵）
			const int high   ：屏幕高度（点阵）
  返 回 值：
  说    明：
***************************************************************************/
void hdc_init(const int bgcolor, const int fgcolor, const int width, const int high)
{
	/* 先释放，防止不release而再次init（hdc_release可重入） */
	hdc_release();

	/* 窗口init后，用一个静态全局量记录，后续hdc_cls()会用到 */
	_BgColor_ = bgcolor;
	_FgColor_ = fgcolor;
	_Width_ = width;
	_High = high;

	hdc = GetDC(hWnd);

	cct_setcursor(CURSOR_INVISIBLE);
	cct_setcolor(bgcolor, fgcolor);
	cct_setfontsize("点阵字体", 16);
	cct_setconsoleborder(width / 8 + !!(width % 8), high / 16 + !!(high % 16)); //将点阵的宽度及高度转换为特定字体的行列数，!!的含义：如果不是8/16的倍数，行列多+1
	cct_cls();
}

/***************************************************************************
  函数名称：
  功    能：释放画图资源
  输入参数：
  返 回 值：
  说    明：可重入
***************************************************************************/
void hdc_release()
{
	if (hdc) {
		ReleaseDC(hWnd, hdc);
		hdc = NULL;
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hdc_set_delay(int ms)
{
	if (ms > 0)
		_Delay_ms = ms;
	else
		_Delay_ms = 0;
}

/***************************************************************************
  函数名称：
  功    能：设置画笔颜色，传入RGB值
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hdc_set_pencolor(const int RGB_value)
{
	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, RGB_value);
}

/***************************************************************************
  函数名称：
  功    能：设置画笔颜色，传入RGB三色，值0-255
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hdc_set_pencolor(const unsigned char red, const unsigned char green, const unsigned char blue)
{
	hdc_set_pencolor(RGB(red, green, blue));
}

/***************************************************************************
  函数名称：
  功    能：清除屏幕上现有的图形
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hdc_cls()
{
    /* 发现一定要换一种颜色初始化才能清除像素点，找到更简便方法的同学可以通知我 */
	hdc_init(_BgColor_, (_FgColor_  + 1) % 16, _Width_, _High);

	hdc_init(_BgColor_, _FgColor_, _Width_, _High);

	/* 部分机器上运行demo时，会出现hdc_cls()后第一根线有缺线的情况，加延时即可
	   如果部分机器运行还有问题，调高此延时值 */
	Sleep(30);
}

/***************************************************************************
  函数名称：
  功    能：在(x,y)位置处用指定颜色画出一个像素点
  输入参数：const int x：x坐标，左上角为(0,0)
            const int y：y坐标，左上角为(0,0)
  返 回 值：
  说    明：颜色直接用当前设定，可以在调用处指定
***************************************************************************/
static inline void hdc_base_point(const int x, const int y)
{
	MoveToEx(hdc, x - 1, y - 1, NULL);
	LineTo(hdc, x, y);
	if (_Delay_ms > 0)
		Sleep(_Delay_ms);
}

/***************************************************************************
  函数名称：
  功    能：在(x1,y1)-(x2,y2)之间画出一个像素点的连线
  输入参数：const int x1：起点x坐标，左上角为(0,0)
			const int y1：起点y坐标，左上角为(0,0)
			const int x2：终点y坐标，左上角为(0,0)
			const int y2：终点y坐标，左上角为(0,0)
  返 回 值：
  说    明：颜色直接用当前设定
***************************************************************************/
static inline void hdc_base_line(const int x1, const int y1, const int x2, const int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	if (_Delay_ms > 0)
		Sleep(_Delay_ms);
}

/***************************************************************************
  函数名称：
  功    能：在(x,y)位置处用指定颜色画一个指定粗细的点(用画实心圆来模拟)
  输入参数：const int x			：x坐标，左上角为(0,0)
            const int y			：y坐标，左上角为(0,0)
			const int thickness	：点的粗细，下限位1，上限不限(如过大会导致不完全填充)（有缺省值）
			const int RGB_value	：点的颜色（有缺省值）
  返 回 值：
  说    明：改进运行效率
***************************************************************************/
void hdc_point(const int x, const int y, const int thickness, const int RGB_value)
{
	int tn = thickness;
	if (tn < 1)
		tn = 1;		//处理下限
	/* 不卡点直径的上限，但是单上限超过一定大小是，画出的圆部分位置未实心 */

	const int tn_end = (tn <= 1) ? 1 : tn/2;

	int angle, level;
	int old_x1 = INT_MAX, old_y1 = INT_MAX, x1, y1;
	int count = 0;

	if (RGB_value != INVALID_RGB)
		hdc_set_pencolor(RGB_value);

	/* 用画圆的方式模拟粗点 */
	for (level = 1; level <= tn_end; level++) {
		for (angle = 0; angle <= 360; angle ++) {
			/* 注意，系统的坐标轴，0°在圆的最下方 */
			x1 = x + (int)(level * sin(angle * PI / 180));
			y1 = y - (int)(level * cos(angle * PI / 180));

			/* 当半径很小时，角度变化不会引起int型的x1/y1变化，因此加判断语句，避免重复画同一像素点 */
			if (x1 != old_x1 || y1 != old_y1) {
				old_x1 = x1;
				old_y1 = y1;
				hdc_base_point(x1, y1);
				++count;
			}
		}
	}
#if 0
	/* 放开此注释，可以看到一个粗点用了几个像素点组成 */
	cct_gotoxy(0, 41);
	printf("count=%d           ", count);
	getchar();
#endif
}

/* -------------------------------------------------------------------------
	给出下列函数的实现，函数名及参数表不准改动
	1、不需要调用系统的其他有关图形操作的函数
	2、下列函数的实现都基于hdc_base_point/hdc_base_line函数的组合
	3、想一想，是不是所有函数都需要给出独立的实现过程？应该先实现哪些函数？
	4、填充是实现中最复杂的部分
	5、系统的角度与函数参数中的角度含义相差180°
   ------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：画线段
  输入参数：const int x1		：起点的x
            const int y1		：起点的y
			const int x2		：终点的x
			const int y2		：终点的y
			const int thickness	：线段的粗细（有缺省值）
			const int RGB_value	：线段的颜色（有缺省值）
  返 回 值：
  说    明：本函数可以用基于hdc_point的组合（速度慢）
                  也可以用hdc_base_point/hdc_base_line的组合（速度快）
***************************************************************************/
void hdc_line(const int x1, const int y1, const int x2, const int y2, const int thickness, const int RGB_value)
{
	if (RGB_value != 2147483647)
		hdc_set_pencolor(RGB_value);
	/*if (x2 != x1) {
		//斜率存在；
		double k = 1.0 * (y2 - y1) / (x2 - x1);
		if (abs(k) <= 0.5) {
			//斜率小于0.5
			for (int i = 0; i < thickness; i++) {
				hdc_base_line(x1, y1 + i, x2, y2 + i);
			}
		}
		else {
			for (int i = 0; i < thickness; i++) {
				hdc_base_line(x1 + i, y1, x2 + i, y2);
			}
		}
	}*/
	//先设置画笔的颜色
	
	//画线段，就用bsae_line不停的填充即可，如果线段粗细大于1；则跳到（x+i，y）处多画几次；
	if (y2!=y1) {
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1 + i, y1, x2 + i, y2);
		}
		//既不平行于x轴也不平行于y轴
	}
	else {//y1==y2
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1, y1+i, x2, y2+i);
		}
	}
	
}

/***************************************************************************
  函数名称：
  功    能：给出三点的坐标，画一个三角形
  输入参数：const int x1		：第1个点的x
            const int y1		：第1个点的y
			const int x2		：第2个点的x
			const int y2		：第2个点的y
			const int x3		：第3个点的x
			const int y3		：第3个点的y
			bool filled			：是否需要填充（有缺省值）
			const int thickness	：边的粗细（有缺省值）
			const int RGB_value	：颜色（有缺省值）
  返 回 值：
  说    明：不判断三点是否共线，如果共线，划出一条直线即可
***************************************************************************/
void hdc_triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, bool filled, const int thickness, const int RGB_value)
{
	if (RGB_value != INVALID_RGB)
		hdc_set_pencolor(RGB_value);
	//本函数功能：调用hdc_line（）画三条线
	//先画边框；
	//x1,y1-->x2,y2
	if (y2 != y1) {
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1 + i, y1, x2 + i, y2);
		}
		//既不平行于x轴也不平行于y轴
	}
	else {//y1==y2
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1, y1 + i, x2, y2 + i);
		}
	}
	//x1,y1-->x3,y3
	if (y3 != y1) {
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1 + i, y1, x3 + i, y3);
		}
		//既不平行于x轴也不平行于y轴
	}
	else {//y1==y2
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1, y1 + i, x3, y3 + i);
		}
	}
	//x2,y2-->x3,y3
	if (y3 != y2) {
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x2 + i, y2, x3 + i, y3);
		}
		//既不平行于x轴也不平行于y轴
	}
	else {//y1==y2
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x2, y2 + i, x3, y3 + i);
		}
	}
	/*hdc_line(x1, y1, x3, y3, thickness, 255);
	hdc_line(x2, y2, x3, y3, thickness, 255);*/
	//填充
	if (filled == true) {
		int cols, lines, bufferc, bufferl;//读取当前窗口大小
		cct_getconsoleborder(cols, lines, bufferc, bufferl);

		//数学方法判断点是否在图形内部:若p在内部，则Sabp+Sacp+Sbcp=Sabc;
		int max_x = cols;
		int max_y = lines;
		for (int x = 0; x <=max_x*50; x++) {
			for (int y = 0; y <= max_y*50; y++) {
				if (judge_is_in_triangle(x1, y1, x2, y2, x3, y3, x, y) == 1) {
					hdc_point(x, y);

				}
			}
		}
		

	}
	


}

/***************************************************************************
  函数名称：
  功    能：给出左上角坐标及宽度、高度，画出一个长方形
  输入参数：const int left_up_x			：左上角x
            const int left_up_y			：左上角y
			const int width				：宽度
			const int high				：高度
			const int rotation_angles	：以左上角为支点，与x轴的旋转倾角（向下转为正）
			bool filled					：是否需要填充（有缺省值）
			const int thickness			：边的粗细（有缺省值）
			const int RGB_value			：颜色（有缺省值）
  返 回 值：
  说    明：
***************************************************************************/
void hdc_rectangle(const int left_up_x, const int left_up_y, const int width, const int high, const int rotation_angles, const bool filled, const int thickness, const int RGB_value)
{
	//绘制长方形，首先要把角度摆正
	/*设平面上一点（x1,y1），绕另一点（x0,y0）逆时针旋转A角度后的点为（x2,y2）,则：
    x2 = (x1-x0)*cosA - (y1-y0)*sinA + x0
    y2 = (x1-x0)*sinA + (y1-y0)*cosA + y0*/
	//角度为0度时，四个点的坐标分别是（x0，y0）（x1,y1）(x2,y2)(x3,y3)
	int x0 = left_up_x;
	int y0 = left_up_y;
	int x1 = left_up_x + width;
	int y1 = left_up_y;//初始位置0度角 
	int x2 = x1;
	int y2 = y1 + high;
	int x3 = left_up_x;
	int y3 = y2;
	int right_up_x =int( (x1 - x0) * cos(rotation_angles / 180.0 * PI) - (y1 - y0) * sin(rotation_angles / 180.0 * PI) + x0);
	int right_up_y =int((x1-x0)* sin(rotation_angles / 180.0 * PI)+(y1-y0)*cos(rotation_angles / 180.0 * PI)+y0);
	//逆时针方向开始画线第一条线
	Sleep(100);
	hdc_line(left_up_x, left_up_y, right_up_x, right_up_y, thickness, RGB_value);
	Sleep(100);
	int right_down_x=int((x2-x0)* cos(rotation_angles / 180.0 * PI)-(y2-y0)* sin(rotation_angles / 180.0 * PI)+x0);
	int right_down_y = int((x2 - x0) * sin(rotation_angles / 180.0 * PI) + (y2 - y0) * cos(rotation_angles / 180.0 * PI) + y0);
	hdc_line(right_up_x, right_up_y, right_down_x,right_down_y, thickness, RGB_value);//第二条线
	int left_down_x=int((x3-x0) * cos(rotation_angles / 180.0 * PI)-(y3-y0) * sin(rotation_angles / 180.0* PI) + x0);
	int left_down_y=int((x3 - x0)* sin(rotation_angles / 180.0 * PI)+(y3 - y0) * cos(rotation_angles / 180.0* PI )+ y0);
	Sleep(100);
	hdc_line(right_down_x, right_down_y, left_down_x, left_down_y, thickness, RGB_value);//第三条线
	Sleep(100);
	hdc_line(left_down_x, left_down_y, left_up_x, left_up_y, thickness, RGB_value);//第四条线
	if (filled == true) {//相当于填充2个三角形之和
		int cols, lines, bufferc, bufferl;//读取当前窗口大小
		cct_getconsoleborder(cols, lines, bufferc, bufferl);
		int max_x = cols;
		int max_y = lines;
		for (int x = 0; x <= max_x * 50; x++) {
			for (int y = 0; y <= max_y * 50; y++) {
				if (judge_is_in_triangle(left_up_x, left_up_y, right_up_x, right_up_y, right_down_x, right_down_y, x, y) == 1) {
					hdc_point(x, y);

				}
				if (judge_is_in_triangle(left_up_x, left_up_y, left_down_x, left_down_y, right_down_x, right_down_y, x, y) == 1) {
					hdc_point(x, y);

				}

			}
		}


	}
																						 
/*设平面上一点（x1,y1），绕另一点（x0,y0）逆时针旋转A角度后的点为（x2,y2）,则：
	x2 = (x1-x0)*cosA - (y1-y0)*sinA + x0
	y2 = (x1-x0)*sinA + (y1-y0)*cosA + y0*/
}

/***********************************************************************     ****
  函数名称：
  功    能：给出左上角坐标及边长，画出一个正方形
  输入参数：const int left_up_x			：左上角x
			const int left_up_y			：左上角y
			const int length			：边长
			const int rotation_angles	：以左上角为支点，与x轴的旋转倾角（向下转为正）（有缺省值）
			const bool filled			：是否需要填充（有缺省值）
			const int thickness			：边的粗细（有缺省值）
			const int RGB_value			：颜色（有缺省值）
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hdc_square(const int left_up_x, const int left_up_y, const int length, const int rotation_angles, const bool filled, const int thickness, const int RGB_value)
{
	//画正方形的本质就是画一个特殊的长方形
	int width = length;
	int high = length;
	hdc_rectangle(left_up_x, left_up_y, length, length, rotation_angles, filled, thickness, RGB_value);
}

/***************************************************************************
  函数名称：
  功    能：按照给出的参数画一段圆弧
  输入参数：const int point_x		：圆心的x
            const int point_y		：圆心的y
			const int radius		：半径
			const int angle_begin	：起始角度（以圆的最上方为0°，顺时针为正，注意：与系统坐标差了180°!!!）（有缺省值）
			const int angle_end		：结束角度（同上）（有缺省值）
			const int thickness		：粗细（有缺省值）
			const int RGB_value		：颜色（有缺省值）
  返 回 值：
  说    明：
***************************************************************************/
void hdc_arc(const int point_x, const int point_y, const int radius, const int angle_begin, const int angle_end, const int thickness, const int RGB_value)
{
	//圆的最上方为0度，值顺时针递增
	int angle;
	int x1, y1;//要绘制的点的坐标
	int begin = angle_begin;
	int end = angle_end;
	int level;
	int mount = 0;
	if (thickness < 8) {
		mount = 8;
	}
	else {
		mount = thickness;
	}
	if (end - begin > 360 || end < begin) {
		while (begin > 180) {
			begin -= 360;
		}
		while (begin <= -180) {
			begin += 360;
		}//这两个语句，将范围控制在-179-180之间（闭区间）
		while (end < begin) {
			//这个语句防止末角度小于初角度
			end += 360;
		}
		//特判一下，如果begin==end，则直接输出整个圆
	}
	if (begin == end) {
		//画整个圆
		for (level = 1; level <= thickness; level++) {
			for (angle = begin; angle <= begin + 360; angle++) {
				x1 = point_x + (int)(radius * sin(angle * PI / 180));
				y1 = point_y - (int)(radius * cos(angle * PI / 180));
				hdc_point(x1, y1, mount, RGB_value);
				/*hdc_point(x1+1, y1+1, thickness, RGB_value);
				hdc_point(x1 - 1, y1-1, thickness, RGB_value);
				hdc_point(x1 +1, y1 - 1, thickness, RGB_value);
				hdc_point(x1, y1 - 1, thickness, RGB_value);
				hdc_point(x1 + 1, y1, thickness, RGB_value);
				hdc_point(x1 -1, y1, thickness, RGB_value);
				hdc_point(x1-1,y1+1, thickness, RGB_value);
				hdc_point(x1, y1 + 1, thickness, RGB_value);//多画几次*/
			}

		}
	}
	else {
		for (level = 1; level <= thickness; level++) {
			for (angle = begin; angle <= end; angle++) {
				/* 注意，系统的坐标轴，0°在圆的最下方 */
				x1 = point_x + (int)(radius * sin(angle * PI / 180));
				y1 = point_y - (int)(radius * cos(angle * PI / 180));
				/*hdc_point(x1, y1, thickness, RGB_value);
				hdc_point(x1 - 1, y1, thickness, RGB_value);
				hdc_point(x1 - 1, y1, thickness, RGB_value);
				hdc_point(x1, y1 - 1, thickness, RGB_value);
				hdc_point(x1 + 1, y1, thickness, RGB_value);
				hdc_point(x1, y1 + 1, thickness, RGB_value);//多画几次*/
				hdc_point(x1, y1, mount, RGB_value);
				/*hdc_point(x1 + 1, y1 + 1, thickness, RGB_value);
				hdc_point(x1 - 1, y1 - 1, thickness, RGB_value);
				hdc_point(x1 + 1, y1 - 1, thickness, RGB_value);
				hdc_point(x1, y1 - 1, thickness, RGB_value);
				hdc_point(x1 + 1, y1, thickness, RGB_value);
				hdc_point(x1 - 1, y1, thickness, RGB_value);
				hdc_point(x1 - 1, y1 + 1, thickness, RGB_value);
				hdc_point(x1, y1 + 1, thickness, RGB_value);//多画几次*/
			}

		}
	}
}

/***************************************************************************
  函数名称：
  功    能：按照给出的参数画一个扇形
  输入参数：const int point_x		：圆心的x
			const int point_y		：圆心的y
			const int radius		：半径
			const int angle_begin	：起始角度（以圆的最上方为0°，顺时针为正，注意：与系统坐标差了180°!!!）（有缺省值）
			const int angle_end		：结束角度（同上）（有缺省值）
			const bool filled		：是否需要填充（有缺省值）
			const int thickness		：粗细（有缺省值）
			const int RGB_value		：颜色（有缺省值）
  输入参数：
  返 回 值：
  说    明：当起始/结束角度差值为360的倍数时，不画两条边
***************************************************************************/
void hdc_sector(const int point_x, const int point_y, const int radius, const int angle_begin, const int angle_end, const bool filled, const int thickness, const int RGB_value)
{
	int change_radius = radius;
	//扇形也是建立在画弧的基础上的，而且要填充，（根据到圆心的距离以及角度来判断是否在扇形区域内）
	//先画出弧然后连接始末两点
	hdc_arc(point_x, point_y, radius, angle_begin, angle_end, thickness, RGB_value);
	int x1 = point_x + (int)(radius * sin(angle_begin * PI / 180));
	int y1 = point_y - (int)(radius * cos(angle_begin * PI / 180));
	int x2 = point_x + (int)(radius * sin(angle_end * PI / 180));
	int y2 = point_y - (int)(radius * cos(angle_end * PI / 180));
	hdc_line(x1, y1, point_x, point_y, thickness, RGB_value);
	hdc_line(x2, y2, point_x, point_y, thickness, RGB_value);
	if (filled) {
		//填充的延时设置为0；
		hdc_set_delay(0);
		//需要填充判断标准是距离小于半径且在两个连线范围内
		while (change_radius > 0) {
			hdc_arc(point_x, point_y, change_radius, angle_begin, angle_end, 8, RGB_value);
			change_radius-=5;
		}//D盘

	}
}
/***************************************************************************
  函数名称：
  功    能：按照给出的参数画一个圆
  输入参数：const int point_x		：圆心的x
			const int point_y		：圆心的y
			const int radius		：半径
			const bool filled		：是否需要填充（有缺省值）
			const int thickness		：粗细（有缺省值）
			const int RGB_value		：颜色（有缺省值）
  返 回 值：
  说    明：
***************************************************************************/
void hdc_circle(const int point_x, const int point_y, const int radius, const bool filled, const int thickness, const int RGB_value)
{
	hdc_arc(point_x, point_y,radius, 0,360, thickness, RGB_value);
	if (filled) {//类比矩形填充
		int cols, lines, bufferc, bufferl;//读取当前窗口大小
		cct_getconsoleborder(cols, lines, bufferc, bufferl);
		int max_x = cols;
		int max_y = lines;
		for (int x = 0; x <= max_x * 50; x++) {
			for (int y = 0; y <= max_y * 50; y++) {
				if ((x - point_x) * (x - point_x) + (y - point_y) * (y - point_y) <= radius * radius) {
				//证明在圆的内部
					hdc_point(x, y, thickness, RGB_value);
				}

			}
		}

		
	}
	
}

/***************************************************************************
  函数名称：
  功    能：按照给出的参数画一个椭圆
  输入参数：const int point_x			：圆心的x
			const int point_y			：圆心的y
			const int radius_a			：平行于X轴的半径
			const int radius_b			：平行于Y轴的半径
			const int rotation_angles	：以圆心为支点，与x轴的旋转倾角（向下转为正）（有缺省值）
			const bool filled			：是否需要填充（有缺省值）
			const int thickness			：粗细（有缺省值）
			const int RGB_value			：颜色（有缺省值）
  返 回 值：
  说    明：
***************************************************************************/
void hdc_ellipse(const int point_x, const int point_y, const int radius_a, const int radius_b, const int rotation_angles, const bool filled, const int thickness, const int RGB_value)
{
	//在屏幕中用x2/a2+y2/b2=1的办法判定椭圆的位置；
	//值是顺时针递增；
	int cols, lines, bufferc, bufferl;//读取当前窗口大小
	cct_getconsoleborder(cols, lines, bufferc, bufferl);
	int max_x = cols;
	int max_y = lines;
	double angles = rotation_angles / 180.0 * PI;
	for (int x = 0; x <= max_x * 50; x++) {
		for (int y = 0; y <= max_y * 50; y++) {
		
			//将x用x2代换掉
			//x=x2cos(angle)-y2sin(angle)
			//y=x2sin()+y2cos()
			double compare = ((x-point_x)* cos(angles)+(y-point_y) * sin(angles)) *
				((x - point_x) * cos(angles)+(y-point_y) * sin(angles)) * 1.0 / (radius_a * radius_a) +
				((x - point_x) * sin(-angles) +(y-point_y) * cos(angles)) * ((x - point_x) * sin(-angles) +(y-point_y) * cos(angles)) * 1.0 / (radius_b * radius_b);
			if ( abs(compare-1)<1e-2) {
				//证明在椭圆上
				hdc_point(x, y, thickness, RGB_value);
			}
			if (filled) {
				//需要填充
				if (compare <= 1) {
					hdc_point(x, y, thickness, RGB_value);
				}
			}
		
		}
	}

}

#endif !HDC_SERIES_BY_TEACHER
