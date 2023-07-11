/*2052316 信07 李祎娜*/
#include <iostream>
#include <cmath>
#include <Windows.h>
#include "../include/cmd_hdc_tools.h"
using namespace std;
#define Pi 3.14159265
void hdc_draw_Mathematical_curve_2052316()
{
	hdc_cls();
	cout << "这是一系列等轴双曲线\n";
	//r=100xita;
	int cols, lines, bufferc, bufferl;//读取当前窗口大小
	cct_getconsoleborder(cols, lines, bufferc, bufferl);
	int max_x = cols;
	int max_y = lines;
	int basex = 350;
	int basey = 400;
	for (double x = 0; x <= double(max_x )* 50; x++) {
		for (double y = 0; y <= double(max_y) * 50; y++) {
			//双曲线 x*x/（2*2）-（y*y）/（2*2）=1
			double compare1 = double((x - basex)) * (x - basex) * 1.0 / (150.0 * 150) - double((y - basey))* (y - basey) * 1.0 / (150.0* 150);
			double compare2= double((x - basex)) * (x - basex) * 1.0 / (70.0* 70) - double((y - basey)) * (y - basey) * 1.0 / (70.0 * 70);
			double compare3 = double((x - basex)) * (x - basex) * 1.0 / double((110.0 * 110)) -double((y - basey)) * (y - basey) * 1.0 / (110.0 * 110);
			double compare4 = double((x - basex)) * (x - basex) * 1.0 / double((190.0 * 190)) - double((y - basey)) * (y - basey) * 1.0 / (190.0 * 190);
			if (abs(compare1 - 1) <= 1e-1) {
				hdc_point(int(x),int(y), 5, RGB(140,241,238));//no3
			}
			if (abs(compare2 - 1) <= 1e-1) {
				hdc_point(int(x),int( y), 1, RGB(213,36,42));
			}
			if (abs(compare3- 1) <= 1e-1) {
				hdc_point(int(x),int( y), 1, RGB(172,213,36));
			}
			if (abs(compare4 - 1) <= 1e-1) {
				hdc_point(int(x),int(y), 1, RGB(140,174,241));
			}
		}
		
	}
}