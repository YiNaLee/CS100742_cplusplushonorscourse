/* 2052316 ��07 ��t�� */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "../include/cmd_hdc_tools.h"
using namespace std;

#if !HDC_SERIES_BY_TEACHER	//δ���������²Ŵ���������
//�Լ�д�ĺ�����������������
/* ���������Ҫ��ͷ�ļ� */

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow(); //VS�д˴����в����ߣ���Ӱ������ʹ��

/* �Ѷ���ľ�̬ȫ�ֱ��� */
static HWND hWnd = GetConsoleWindow();
static HDC hdc = NULL;
static const double PI = 3.14159;
static int _BgColor_, _FgColor_, _Width_, _High;
static int _Delay_ms=0;//Ĭ����������ã�ֵΪ0

/* �����ʶ�ʹ�þ�̬ȫ�ֱ�����������static�����ⲿ���ɼ� */

/* �˴���������Զ��庯����������static�����ⲿ���ɼ� */
/***************************************************************************
  �������ƣ�cul_area()
  ��    �ܣ��������������
  �������������������꣬��������˼���
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static double cul_area(const int Ax,const int Ay,const int Bx,const int By,const int Cx,const int Cy)
{
	//double result = abs(((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3))/2.0);
	double s = abs((double(Ax) * By + Bx * Cy + Cx * Ay - Ay * Bx - By * Cx - Cy * Ax) / 2.0);
	//cout << "s="<< s << endl;
	return s;
}
/*������������أ����ڼ�������е����������*/
static int judge_is_in_triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, const int x, const int y)
{
	double sum_area = cul_area(x1, y1, x2, y2, x3, y3);
	double area01 = cul_area(x1, y1, x2, y2, x, y);
	double area02 = cul_area(x1, y1, x3, y3, x, y);
	double area03 = cul_area(x2, y2, x3, y3, x, y);
	if (abs(sum_area-(area01+area02+area03))<=1e-1) {
		//��Ϊ���ڲ�
		return 1;
	}
	else
		return 0;
}
static int judge_is_in_rectangle(const int x1,const int y1,const int x2,const int y2,
	const int x3,const int y3,const int x4,const int y4,const int x,const int y,const int width,const int high)
{
	double all_area = width * high;//����������ǳ��˿�
	double area01 = abs(cul_area(x1, y1, x2, y2, x, y));
	double area02 = abs(cul_area(x2, y2, x3, y3, x, y));
	double area03 =abs( cul_area(x3, y3, x4, y4, x, y));
	double area04 = abs(cul_area(x4, y4, x1, y1, x, y));
	if (abs(all_area - (area01 + area02 + area03+area04)) <= 1e-1) {
		//��Ϊ���ڲ�
		return 1;
	}
	else
		return 0;
}
/*����������ڲ��򷵻�1�����򷵻�0*/
/*static int judge_is_insector(int x,int y,int radius, const int point_x, const int point_y,int borderx,int bordery,int inclination)
{
	if ((x - point_x) * (x - point_x) + (y - point_y) * (y - point_y) > radius * radius) {
		return 0;//�����ڲ�
	}
	//Ȼ�����õ���һ�����ߵļн�
	//������Ϊһ�������Σ����������εļнǼ���
	double a = sqrt((x - point_x) * (x - point_x) + (y - point_y) * (y - point_y));
	double b= sqrt((x - borderx) * (x - borderx) + (y - bordery) * (y - bordery));
	double c = sqrt((borderx - point_x) * (borderx - point_x) + (bordery - point_y) * (bordery - point_y));
	//����н�cosB��inclination�Ƚ�
	//���ﻹ�Ǵ�������
}*/


/* ��������˼�����������������ʵ�֣���Ҫ�Ķ� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʼ��
  ���������const int bgcolor������ɫ
            const int fgcolor��ǰ��ɫ
			const int width  ����Ļ��ȣ�����
			const int high   ����Ļ�߶ȣ�����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_init(const int bgcolor, const int fgcolor, const int width, const int high)
{
	/* ���ͷţ���ֹ��release���ٴ�init��hdc_release�����룩 */
	hdc_release();

	/* ����init����һ����̬ȫ������¼������hdc_cls()���õ� */
	_BgColor_ = bgcolor;
	_FgColor_ = fgcolor;
	_Width_ = width;
	_High = high;

	hdc = GetDC(hWnd);

	cct_setcursor(CURSOR_INVISIBLE);
	cct_setcolor(bgcolor, fgcolor);
	cct_setfontsize("��������", 16);
	cct_setconsoleborder(width / 8 + !!(width % 8), high / 16 + !!(high % 16)); //������Ŀ�ȼ��߶�ת��Ϊ�ض��������������!!�ĺ��壺�������8/16�ı��������ж�+1
	cct_cls();
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ͷŻ�ͼ��Դ
  ���������
  �� �� ֵ��
  ˵    ����������
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_set_delay(int ms)
{
	if (ms > 0)
		_Delay_ms = ms;
	else
		_Delay_ms = 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����û�����ɫ������RGBֵ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_set_pencolor(const int RGB_value)
{
	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, RGB_value);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����û�����ɫ������RGB��ɫ��ֵ0-255
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_set_pencolor(const unsigned char red, const unsigned char green, const unsigned char blue)
{
	hdc_set_pencolor(RGB(red, green, blue));
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������Ļ�����е�ͼ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_cls()
{
    /* ����һ��Ҫ��һ����ɫ��ʼ������������ص㣬�ҵ�����㷽����ͬѧ����֪ͨ�� */
	hdc_init(_BgColor_, (_FgColor_  + 1) % 16, _Width_, _High);

	hdc_init(_BgColor_, _FgColor_, _Width_, _High);

	/* ���ֻ���������demoʱ�������hdc_cls()���һ������ȱ�ߵ����������ʱ����
	   ������ֻ������л������⣬���ߴ���ʱֵ */
	Sleep(30);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���(x,y)λ�ô���ָ����ɫ����һ�����ص�
  ���������const int x��x���꣬���Ͻ�Ϊ(0,0)
            const int y��y���꣬���Ͻ�Ϊ(0,0)
  �� �� ֵ��
  ˵    ������ɫֱ���õ�ǰ�趨�������ڵ��ô�ָ��
***************************************************************************/
static inline void hdc_base_point(const int x, const int y)
{
	MoveToEx(hdc, x - 1, y - 1, NULL);
	LineTo(hdc, x, y);
	if (_Delay_ms > 0)
		Sleep(_Delay_ms);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���(x1,y1)-(x2,y2)֮�仭��һ�����ص������
  ���������const int x1�����x���꣬���Ͻ�Ϊ(0,0)
			const int y1�����y���꣬���Ͻ�Ϊ(0,0)
			const int x2���յ�y���꣬���Ͻ�Ϊ(0,0)
			const int y2���յ�y���꣬���Ͻ�Ϊ(0,0)
  �� �� ֵ��
  ˵    ������ɫֱ���õ�ǰ�趨
***************************************************************************/
static inline void hdc_base_line(const int x1, const int y1, const int x2, const int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	if (_Delay_ms > 0)
		Sleep(_Delay_ms);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���(x,y)λ�ô���ָ����ɫ��һ��ָ����ϸ�ĵ�(�û�ʵ��Բ��ģ��)
  ���������const int x			��x���꣬���Ͻ�Ϊ(0,0)
            const int y			��y���꣬���Ͻ�Ϊ(0,0)
			const int thickness	����Ĵ�ϸ������λ1�����޲���(�����ᵼ�²���ȫ���)����ȱʡֵ��
			const int RGB_value	�������ɫ����ȱʡֵ��
  �� �� ֵ��
  ˵    �����Ľ�����Ч��
***************************************************************************/
void hdc_point(const int x, const int y, const int thickness, const int RGB_value)
{
	int tn = thickness;
	if (tn < 1)
		tn = 1;		//��������
	/* ������ֱ�������ޣ����ǵ����޳���һ����С�ǣ�������Բ����λ��δʵ�� */

	const int tn_end = (tn <= 1) ? 1 : tn/2;

	int angle, level;
	int old_x1 = INT_MAX, old_y1 = INT_MAX, x1, y1;
	int count = 0;

	if (RGB_value != INVALID_RGB)
		hdc_set_pencolor(RGB_value);

	/* �û�Բ�ķ�ʽģ��ֵ� */
	for (level = 1; level <= tn_end; level++) {
		for (angle = 0; angle <= 360; angle ++) {
			/* ע�⣬ϵͳ�������ᣬ0����Բ�����·� */
			x1 = x + (int)(level * sin(angle * PI / 180));
			y1 = y - (int)(level * cos(angle * PI / 180));

			/* ���뾶��Сʱ���Ƕȱ仯��������int�͵�x1/y1�仯����˼��ж���䣬�����ظ���ͬһ���ص� */
			if (x1 != old_x1 || y1 != old_y1) {
				old_x1 = x1;
				old_y1 = y1;
				hdc_base_point(x1, y1);
				++count;
			}
		}
	}
#if 0
	/* �ſ���ע�ͣ����Կ���һ���ֵ����˼������ص���� */
	cct_gotoxy(0, 41);
	printf("count=%d           ", count);
	getchar();
#endif
}

/* -------------------------------------------------------------------------
	�������к�����ʵ�֣���������������׼�Ķ�
	1������Ҫ����ϵͳ�������й�ͼ�β����ĺ���
	2�����к�����ʵ�ֶ�����hdc_base_point/hdc_base_line���������
	3����һ�룬�ǲ������к�������Ҫ����������ʵ�ֹ��̣�Ӧ����ʵ����Щ������
	4�������ʵ������ӵĲ���
	5��ϵͳ�ĽǶ��뺯�������еĽǶȺ������180��
   ------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ����߶�
  ���������const int x1		������x
            const int y1		������y
			const int x2		���յ��x
			const int y2		���յ��y
			const int thickness	���߶εĴ�ϸ����ȱʡֵ��
			const int RGB_value	���߶ε���ɫ����ȱʡֵ��
  �� �� ֵ��
  ˵    ���������������û���hdc_point����ϣ��ٶ�����
                  Ҳ������hdc_base_point/hdc_base_line����ϣ��ٶȿ죩
***************************************************************************/
void hdc_line(const int x1, const int y1, const int x2, const int y2, const int thickness, const int RGB_value)
{
	if (RGB_value != 2147483647)
		hdc_set_pencolor(RGB_value);
	/*if (x2 != x1) {
		//б�ʴ��ڣ�
		double k = 1.0 * (y2 - y1) / (x2 - x1);
		if (abs(k) <= 0.5) {
			//б��С��0.5
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
	//�����û��ʵ���ɫ
	
	//���߶Σ�����bsae_line��ͣ����伴�ɣ�����߶δ�ϸ����1����������x+i��y�����໭���Σ�
	if (y2!=y1) {
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1 + i, y1, x2 + i, y2);
		}
		//�Ȳ�ƽ����x��Ҳ��ƽ����y��
	}
	else {//y1==y2
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1, y1+i, x2, y2+i);
		}
	}
	
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������������꣬��һ��������
  ���������const int x1		����1�����x
            const int y1		����1�����y
			const int x2		����2�����x
			const int y2		����2�����y
			const int x3		����3�����x
			const int y3		����3�����y
			bool filled			���Ƿ���Ҫ��䣨��ȱʡֵ��
			const int thickness	���ߵĴ�ϸ����ȱʡֵ��
			const int RGB_value	����ɫ����ȱʡֵ��
  �� �� ֵ��
  ˵    �������ж������Ƿ��ߣ�������ߣ�����һ��ֱ�߼���
***************************************************************************/
void hdc_triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, bool filled, const int thickness, const int RGB_value)
{
	if (RGB_value != INVALID_RGB)
		hdc_set_pencolor(RGB_value);
	//���������ܣ�����hdc_line������������
	//�Ȼ��߿�
	//x1,y1-->x2,y2
	if (y2 != y1) {
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x1 + i, y1, x2 + i, y2);
		}
		//�Ȳ�ƽ����x��Ҳ��ƽ����y��
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
		//�Ȳ�ƽ����x��Ҳ��ƽ����y��
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
		//�Ȳ�ƽ����x��Ҳ��ƽ����y��
	}
	else {//y1==y2
		for (int i = 0; i < thickness; i++) {
			hdc_base_line(x2, y2 + i, x3, y3 + i);
		}
	}
	/*hdc_line(x1, y1, x3, y3, thickness, 255);
	hdc_line(x2, y2, x3, y3, thickness, 255);*/
	//���
	if (filled == true) {
		int cols, lines, bufferc, bufferl;//��ȡ��ǰ���ڴ�С
		cct_getconsoleborder(cols, lines, bufferc, bufferl);

		//��ѧ�����жϵ��Ƿ���ͼ���ڲ�:��p���ڲ�����Sabp+Sacp+Sbcp=Sabc;
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
  �������ƣ�
  ��    �ܣ��������Ͻ����꼰��ȡ��߶ȣ�����һ��������
  ���������const int left_up_x			�����Ͻ�x
            const int left_up_y			�����Ͻ�y
			const int width				�����
			const int high				���߶�
			const int rotation_angles	�������Ͻ�Ϊ֧�㣬��x�����ת��ǣ�����תΪ����
			bool filled					���Ƿ���Ҫ��䣨��ȱʡֵ��
			const int thickness			���ߵĴ�ϸ����ȱʡֵ��
			const int RGB_value			����ɫ����ȱʡֵ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_rectangle(const int left_up_x, const int left_up_y, const int width, const int high, const int rotation_angles, const bool filled, const int thickness, const int RGB_value)
{
	//���Ƴ����Σ�����Ҫ�ѽǶȰ���
	/*��ƽ����һ�㣨x1,y1��������һ�㣨x0,y0����ʱ����תA�ǶȺ�ĵ�Ϊ��x2,y2��,��
    x2 = (x1-x0)*cosA - (y1-y0)*sinA + x0
    y2 = (x1-x0)*sinA + (y1-y0)*cosA + y0*/
	//�Ƕ�Ϊ0��ʱ���ĸ��������ֱ��ǣ�x0��y0����x1,y1��(x2,y2)(x3,y3)
	int x0 = left_up_x;
	int y0 = left_up_y;
	int x1 = left_up_x + width;
	int y1 = left_up_y;//��ʼλ��0�Ƚ� 
	int x2 = x1;
	int y2 = y1 + high;
	int x3 = left_up_x;
	int y3 = y2;
	int right_up_x =int( (x1 - x0) * cos(rotation_angles / 180.0 * PI) - (y1 - y0) * sin(rotation_angles / 180.0 * PI) + x0);
	int right_up_y =int((x1-x0)* sin(rotation_angles / 180.0 * PI)+(y1-y0)*cos(rotation_angles / 180.0 * PI)+y0);
	//��ʱ�뷽��ʼ���ߵ�һ����
	Sleep(100);
	hdc_line(left_up_x, left_up_y, right_up_x, right_up_y, thickness, RGB_value);
	Sleep(100);
	int right_down_x=int((x2-x0)* cos(rotation_angles / 180.0 * PI)-(y2-y0)* sin(rotation_angles / 180.0 * PI)+x0);
	int right_down_y = int((x2 - x0) * sin(rotation_angles / 180.0 * PI) + (y2 - y0) * cos(rotation_angles / 180.0 * PI) + y0);
	hdc_line(right_up_x, right_up_y, right_down_x,right_down_y, thickness, RGB_value);//�ڶ�����
	int left_down_x=int((x3-x0) * cos(rotation_angles / 180.0 * PI)-(y3-y0) * sin(rotation_angles / 180.0* PI) + x0);
	int left_down_y=int((x3 - x0)* sin(rotation_angles / 180.0 * PI)+(y3 - y0) * cos(rotation_angles / 180.0* PI )+ y0);
	Sleep(100);
	hdc_line(right_down_x, right_down_y, left_down_x, left_down_y, thickness, RGB_value);//��������
	Sleep(100);
	hdc_line(left_down_x, left_down_y, left_up_x, left_up_y, thickness, RGB_value);//��������
	if (filled == true) {//�൱�����2��������֮��
		int cols, lines, bufferc, bufferl;//��ȡ��ǰ���ڴ�С
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
																						 
/*��ƽ����һ�㣨x1,y1��������һ�㣨x0,y0����ʱ����תA�ǶȺ�ĵ�Ϊ��x2,y2��,��
	x2 = (x1-x0)*cosA - (y1-y0)*sinA + x0
	y2 = (x1-x0)*sinA + (y1-y0)*cosA + y0*/
}

/***********************************************************************     ****
  �������ƣ�
  ��    �ܣ��������Ͻ����꼰�߳�������һ��������
  ���������const int left_up_x			�����Ͻ�x
			const int left_up_y			�����Ͻ�y
			const int length			���߳�
			const int rotation_angles	�������Ͻ�Ϊ֧�㣬��x�����ת��ǣ�����תΪ��������ȱʡֵ��
			const bool filled			���Ƿ���Ҫ��䣨��ȱʡֵ��
			const int thickness			���ߵĴ�ϸ����ȱʡֵ��
			const int RGB_value			����ɫ����ȱʡֵ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_square(const int left_up_x, const int left_up_y, const int length, const int rotation_angles, const bool filled, const int thickness, const int RGB_value)
{
	//�������εı��ʾ��ǻ�һ������ĳ�����
	int width = length;
	int high = length;
	hdc_rectangle(left_up_x, left_up_y, length, length, rotation_angles, filled, thickness, RGB_value);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ո����Ĳ�����һ��Բ��
  ���������const int point_x		��Բ�ĵ�x
            const int point_y		��Բ�ĵ�y
			const int radius		���뾶
			const int angle_begin	����ʼ�Ƕȣ���Բ�����Ϸ�Ϊ0�㣬˳ʱ��Ϊ����ע�⣺��ϵͳ�������180��!!!������ȱʡֵ��
			const int angle_end		�������Ƕȣ�ͬ�ϣ�����ȱʡֵ��
			const int thickness		����ϸ����ȱʡֵ��
			const int RGB_value		����ɫ����ȱʡֵ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_arc(const int point_x, const int point_y, const int radius, const int angle_begin, const int angle_end, const int thickness, const int RGB_value)
{
	//Բ�����Ϸ�Ϊ0�ȣ�ֵ˳ʱ�����
	int angle;
	int x1, y1;//Ҫ���Ƶĵ������
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
		}//��������䣬����Χ������-179-180֮�䣨�����䣩
		while (end < begin) {
			//�������ֹĩ�Ƕ�С�ڳ��Ƕ�
			end += 360;
		}
		//����һ�£����begin==end����ֱ���������Բ
	}
	if (begin == end) {
		//������Բ
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
				hdc_point(x1, y1 + 1, thickness, RGB_value);//�໭����*/
			}

		}
	}
	else {
		for (level = 1; level <= thickness; level++) {
			for (angle = begin; angle <= end; angle++) {
				/* ע�⣬ϵͳ�������ᣬ0����Բ�����·� */
				x1 = point_x + (int)(radius * sin(angle * PI / 180));
				y1 = point_y - (int)(radius * cos(angle * PI / 180));
				/*hdc_point(x1, y1, thickness, RGB_value);
				hdc_point(x1 - 1, y1, thickness, RGB_value);
				hdc_point(x1 - 1, y1, thickness, RGB_value);
				hdc_point(x1, y1 - 1, thickness, RGB_value);
				hdc_point(x1 + 1, y1, thickness, RGB_value);
				hdc_point(x1, y1 + 1, thickness, RGB_value);//�໭����*/
				hdc_point(x1, y1, mount, RGB_value);
				/*hdc_point(x1 + 1, y1 + 1, thickness, RGB_value);
				hdc_point(x1 - 1, y1 - 1, thickness, RGB_value);
				hdc_point(x1 + 1, y1 - 1, thickness, RGB_value);
				hdc_point(x1, y1 - 1, thickness, RGB_value);
				hdc_point(x1 + 1, y1, thickness, RGB_value);
				hdc_point(x1 - 1, y1, thickness, RGB_value);
				hdc_point(x1 - 1, y1 + 1, thickness, RGB_value);
				hdc_point(x1, y1 + 1, thickness, RGB_value);//�໭����*/
			}

		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ո����Ĳ�����һ������
  ���������const int point_x		��Բ�ĵ�x
			const int point_y		��Բ�ĵ�y
			const int radius		���뾶
			const int angle_begin	����ʼ�Ƕȣ���Բ�����Ϸ�Ϊ0�㣬˳ʱ��Ϊ����ע�⣺��ϵͳ�������180��!!!������ȱʡֵ��
			const int angle_end		�������Ƕȣ�ͬ�ϣ�����ȱʡֵ��
			const bool filled		���Ƿ���Ҫ��䣨��ȱʡֵ��
			const int thickness		����ϸ����ȱʡֵ��
			const int RGB_value		����ɫ����ȱʡֵ��
  ���������
  �� �� ֵ��
  ˵    ��������ʼ/�����ǶȲ�ֵΪ360�ı���ʱ������������
***************************************************************************/
void hdc_sector(const int point_x, const int point_y, const int radius, const int angle_begin, const int angle_end, const bool filled, const int thickness, const int RGB_value)
{
	int change_radius = radius;
	//����Ҳ�ǽ����ڻ����Ļ����ϵģ�����Ҫ��䣬�����ݵ�Բ�ĵľ����Լ��Ƕ����ж��Ƿ������������ڣ�
	//�Ȼ�����Ȼ������ʼĩ����
	hdc_arc(point_x, point_y, radius, angle_begin, angle_end, thickness, RGB_value);
	int x1 = point_x + (int)(radius * sin(angle_begin * PI / 180));
	int y1 = point_y - (int)(radius * cos(angle_begin * PI / 180));
	int x2 = point_x + (int)(radius * sin(angle_end * PI / 180));
	int y2 = point_y - (int)(radius * cos(angle_end * PI / 180));
	hdc_line(x1, y1, point_x, point_y, thickness, RGB_value);
	hdc_line(x2, y2, point_x, point_y, thickness, RGB_value);
	if (filled) {
		//������ʱ����Ϊ0��
		hdc_set_delay(0);
		//��Ҫ����жϱ�׼�Ǿ���С�ڰ뾶�����������߷�Χ��
		while (change_radius > 0) {
			hdc_arc(point_x, point_y, change_radius, angle_begin, angle_end, 8, RGB_value);
			change_radius-=5;
		}//D��

	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ո����Ĳ�����һ��Բ
  ���������const int point_x		��Բ�ĵ�x
			const int point_y		��Բ�ĵ�y
			const int radius		���뾶
			const bool filled		���Ƿ���Ҫ��䣨��ȱʡֵ��
			const int thickness		����ϸ����ȱʡֵ��
			const int RGB_value		����ɫ����ȱʡֵ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_circle(const int point_x, const int point_y, const int radius, const bool filled, const int thickness, const int RGB_value)
{
	hdc_arc(point_x, point_y,radius, 0,360, thickness, RGB_value);
	if (filled) {//��Ⱦ������
		int cols, lines, bufferc, bufferl;//��ȡ��ǰ���ڴ�С
		cct_getconsoleborder(cols, lines, bufferc, bufferl);
		int max_x = cols;
		int max_y = lines;
		for (int x = 0; x <= max_x * 50; x++) {
			for (int y = 0; y <= max_y * 50; y++) {
				if ((x - point_x) * (x - point_x) + (y - point_y) * (y - point_y) <= radius * radius) {
				//֤����Բ���ڲ�
					hdc_point(x, y, thickness, RGB_value);
				}

			}
		}

		
	}
	
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ո����Ĳ�����һ����Բ
  ���������const int point_x			��Բ�ĵ�x
			const int point_y			��Բ�ĵ�y
			const int radius_a			��ƽ����X��İ뾶
			const int radius_b			��ƽ����Y��İ뾶
			const int rotation_angles	����Բ��Ϊ֧�㣬��x�����ת��ǣ�����תΪ��������ȱʡֵ��
			const bool filled			���Ƿ���Ҫ��䣨��ȱʡֵ��
			const int thickness			����ϸ����ȱʡֵ��
			const int RGB_value			����ɫ����ȱʡֵ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void hdc_ellipse(const int point_x, const int point_y, const int radius_a, const int radius_b, const int rotation_angles, const bool filled, const int thickness, const int RGB_value)
{
	//����Ļ����x2/a2+y2/b2=1�İ취�ж���Բ��λ�ã�
	//ֵ��˳ʱ�������
	int cols, lines, bufferc, bufferl;//��ȡ��ǰ���ڴ�С
	cct_getconsoleborder(cols, lines, bufferc, bufferl);
	int max_x = cols;
	int max_y = lines;
	double angles = rotation_angles / 180.0 * PI;
	for (int x = 0; x <= max_x * 50; x++) {
		for (int y = 0; y <= max_y * 50; y++) {
		
			//��x��x2������
			//x=x2cos(angle)-y2sin(angle)
			//y=x2sin()+y2cos()
			double compare = ((x-point_x)* cos(angles)+(y-point_y) * sin(angles)) *
				((x - point_x) * cos(angles)+(y-point_y) * sin(angles)) * 1.0 / (radius_a * radius_a) +
				((x - point_x) * sin(-angles) +(y-point_y) * cos(angles)) * ((x - point_x) * sin(-angles) +(y-point_y) * cos(angles)) * 1.0 / (radius_b * radius_b);
			if ( abs(compare-1)<1e-2) {
				//֤������Բ��
				hdc_point(x, y, thickness, RGB_value);
			}
			if (filled) {
				//��Ҫ���
				if (compare <= 1) {
					hdc_point(x, y, thickness, RGB_value);
				}
			}
		
		}
	}

}

#endif !HDC_SERIES_BY_TEACHER
