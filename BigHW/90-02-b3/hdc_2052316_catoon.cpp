/*2052316 信07 李祎娜*/
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
#define CURTAIN RGB(224,54,57)
#define COLOR_HEAD RGB(246,186,162)
#define COLOR_HAIR RGB(1,1,1)
#define COLOR_BLING RGB(254,254,254)
#define COLOR_MOUTH RGB(114,59,62)
#define COLOR_SHY   RGB(230,149,128)
#include "../include/cmd_hdc_tools.h"
//画头部
static void draw_head(const int basex,const int basey)
{
	hdc_sector(basex - 100, basey - 140,200,-40,100,true,5, COLOR_HAIR);//头顶的发
	
	hdc_ellipse(basex-130,basey-100, 180,120,0, true, 3, COLOR_HEAD);//主头部	
	hdc_ellipse(basex - 130+180, basey - 100-10, 80, 50, 120, true, 3, COLOR_HEAD);//耳朵
	hdc_ellipse(basex - 130, basey -220, 100, 80, 0, true, 3, COLOR_HEAD);//上
	hdc_ellipse(basex-20 , basey - 180, 100, 80, 90, true, 3, COLOR_HEAD);//边缘
	//hdc_ellipse(basex+30, basey - 180, 50, 40, 60, true, 3, COLOR_HEAD);
	/*for (int i = 0; i < 200; i++) {
		hdc_arc(basex - 20 - i, basey - 200, 100, 0, 30, 10, COLOR_HAIR);//头发
	}*/
}
//画两根有趣的眉毛
static void draw_eyebrow(const int basex, const int basey)
{
	hdc_arc(basex - 190, basey - 180, 100, -30, 50, 30, COLOR_HAIR);
	hdc_arc(basex-20,basey-180,110,-30,50,30, COLOR_HAIR);
	hdc_arc(basex-190,basey-160,70,-45,45,2,COLOR_HAIR);
	hdc_arc(basex - 30, basey - 160, 70, -50, 45, 2, COLOR_HAIR);


}
//画眼睛
static void draw_eye(const int basex, const int basey)
{
	hdc_circle(basex - 190, basey - 150, 35, true, 3, COLOR_HAIR);
	//hdc_ellipse(basex-190, basey - 150, 40,25, 110, true, 3, COLOR_HAIR);//左眼
	hdc_circle(basex - 190, basey - 130, 5, true, 3, COLOR_BLING);
	hdc_circle(basex - 185, basey - 120, 3, true, 3, COLOR_BLING);
	hdc_ellipse(basex - 195, basey - 150, 15,10,-45, true, 3, COLOR_BLING);
	hdc_circle(basex - 30, basey - 155, 35, true, 3, COLOR_HAIR);
	//hdc_ellipse(basex - 30, basey - 165, 40, 25, 110, true, 3, COLOR_HAIR);//右眼
	hdc_ellipse(basex - 30, basey - 150,15, 10,-45, true, 3, COLOR_BLING);
	hdc_circle(basex - 25, basey - 130, 5, true, 3, COLOR_BLING);
	hdc_circle(basex - 20, basey - 120, 3, true, 3, COLOR_BLING);

}

static void draw_mouth(const int basex, const int basey)
{
	//basey-25处添加表情
	//hdc_line(basex - 300, basey - 50, basex - 270, basey - 55, 3, CURTAIN);

	hdc_ellipse(basex - 130, basey - 60, 60, 40, 110, true, 3, COLOR_MOUTH);
}
/*static void draw_body(const int basex, const int basey)
{
	hdc_line(basex - 240, basey -10, basex - 320, basey + 120,5, COLOR_HAIR);
	//接口处换用圆弧润色一下
	hdc_arc(basex - 320 + 10, basey + 120, 10, -100, -80, 5, COLOR_HAIR);
	hdc_line(basex - 320, basey + 120, basex - 280, basey + 250, 5, COLOR_HAIR);
	hdc_line(basex-280,basey+250,basex-230,basey+220,5, COLOR_HAIR);
	hdc_line(basex -230, basey + 220, basex - 220, basey + 125, 5, COLOR_HAIR);
	//借助一段-60--30的圆弧
	hdc_arc(basex - 210 + 9, basey + 125 + 5, 10, -60, -30, 5, COLOR_HAIR);
}*/
void hdc_draw_catoon_2052316(const int base_x, const int base_y)
{
	//绘制蜡笔小新头像
	hdc_cls();
	cout << "蜡笔小新--野原新之助";
	//幕布完成之后要把幕布改为true
	hdc_rectangle(base_x - 360, base_y - 360, 650, 500, 0, true, 4, CURTAIN);
	//hdc_rectangle(base_x -360, base_y - 360, 650, 650, 0, false, 4, CURTAIN);
	draw_head(base_x, base_y);
	draw_eyebrow(base_x, base_y);
	draw_eye(base_x, base_y);
	draw_mouth(base_x, base_y);
	//draw_body(base_x, base_y);
}