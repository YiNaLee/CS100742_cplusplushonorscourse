/* 2052316 信07 李祎娜 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include "../include/cmd_gmw_tools.h"
using namespace std;

/* --------------------------------------------------
		此处可以给出需要的静态全局变量（尽可能少，最好没有）、静态全局只读变量/宏定义（个数不限）等
   -------------------------------------------------- */


/* --------------------------------------------------
		此处可以给出需要的内部辅助工具函数
		1、函数名不限，建议为 gmw_inner_* 
		2、个数不限
		3、必须是static函数，确保只在本源文件中使用
		
   -------------------------------------------------- */
   
/************************************************************************
函数名称：gmw_inner_draw_frame_perline()
函数功能：完成画边框的分布操作
函数参数：
函数返回值：
其他说明：本函数是自增的static函数，只在本文件内部使用
***************************************************************************/
static void gmw_inner_draw_frame_perline(const CONSOLE_GRAPHICS_INFO* const pCGI,int Y,int choice)
{
	//cct_setconsoleborder(pCGI->cols, pCGI->lines);
	//画内部框架，首先规定颜色
	int X = pCGI->start_x;
	cct_gotoxy(X, Y);
	cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
	switch (choice) {
		case 1://打印第一排
			if (pCGI->draw_frame_with_col_no) {
				//如果有列标
				cct_gotoxy(X+2, Y - 1);
				int bank = (pCGI->CFI.block_width + pCGI->CFI.block_width_ext) / 2 + 1;
				int bankk = pCGI->CFI.block_width + pCGI->CFI.block_width_ext;
				cct_setcolor(pCGI->area_bgcolor, pCGI->area_fgcolor);
				cout << setw(bank)<<"0";//setw(5) 打印0
				Sleep(pCGI->delay_of_draw_frame);
				for (int num = 1; num < pCGI ->col_num; num++) {
					if (num > 99) {
						cout << setw(bankk) << "**";
					}
					else 
					    cout << setw(bankk)  << num;
					 
					Sleep(pCGI->delay_of_draw_frame);
				}
				//getchar();
			}
			cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);//恢复为游戏颜色
			cct_gotoxy(X, Y);
			cout << pCGI->CFI.top_left;//"╔"
			Sleep(pCGI->delay_of_draw_frame);
			for (int k = 0; k < pCGI->col_num - 1; k++) {
				for (int i = 0; i < (pCGI->CFI.block_width)/ 2; i++) {
					cout << pCGI->CFI.h_normal;// "═"
					Sleep(pCGI->delay_of_draw_frame);
				}
				if (pCGI->CFI.separator) {
					cout << pCGI->CFI.h_top_separator;//"╦";
					Sleep(pCGI->delay_of_draw_frame);
				}
				   
			}
			for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
				cout << pCGI->CFI.h_normal;// "═"
				Sleep(pCGI->delay_of_draw_frame);	
			}
			cout << pCGI->CFI.top_right;//"╗";
			Sleep(pCGI->delay_of_draw_frame);
			break;
		case 2://打印中间有竖线排	
			for (int k = 0; k < pCGI->col_num; k++) {
				if (pCGI->CFI.separator==0&&k==0) {
					cout << pCGI->CFI.v_normal;//"║";
					Sleep(pCGI->delay_of_draw_frame);
				}
				else if (pCGI->CFI.separator) {
					cout << pCGI->CFI.v_normal;//"║";
					Sleep(pCGI->delay_of_draw_frame);
				}
				for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
					cout << setw(2) << " ";
				}
			}
			cout << pCGI->CFI.v_normal;//"║";
			Sleep(pCGI->delay_of_draw_frame);
			break;
		case 3://打印中间有十字排
			if (pCGI->CFI.separator) {
				cout << pCGI->CFI.v_left_separator;//cout << "╠";
			}
			/*else
				cout << pCGI->CFI.v_normal;//"║";*/
			
			Sleep(pCGI->delay_of_draw_frame);
			if (pCGI->CFI.separator) {
				for (int k = 0; k < pCGI->col_num - 1; k++) {
					for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
						cout << pCGI->CFI.h_normal;// "═"
						Sleep(pCGI->delay_of_draw_frame);
					}
					cout << pCGI->CFI.mid_separator;//cout << "╬";
					Sleep(pCGI->delay_of_draw_frame);
				}
				for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
					cout << pCGI->CFI.h_normal;// "═"
					Sleep(pCGI->delay_of_draw_frame);
				}
				cout << pCGI->CFI.v_right_separator;//cout << "╣";
				Sleep(pCGI->delay_of_draw_frame);
			}
			/*else {
				int length = pCGI->CFI.block_width * pCGI->col_num + 1;
				cout << setw(length) << " ";
				cout << pCGI->CFI.v_normal;//"║";
			}*/
			break;
		case 4://打印最后一排
			cout << pCGI->CFI.lower_left;//cout << "╚";
			Sleep(pCGI->delay_of_draw_frame);
			for (int k = 0; k < pCGI->col_num - 1; k++) {
				for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
					cout << pCGI->CFI.h_normal;// "═"
					Sleep(pCGI->delay_of_draw_frame);
				}
				if (pCGI->CFI.separator) {
					cout << pCGI->CFI.h_lower_separator;//cout << "╩";
					Sleep(pCGI->delay_of_draw_frame);
				}

			}
			for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
				cout << pCGI->CFI.h_normal;// "═"
				Sleep(pCGI->delay_of_draw_frame);
			}
			cout << pCGI->CFI.lower_right;//cout << "╝";
			Sleep(pCGI->delay_of_draw_frame);
			break;


	}

}


/* ----------------------------------------------- 
		实现下面给出的函数（函数声明不准动）
   ----------------------------------------------- */
/***************************************************************************
  函数名称：
  功    能：设置游戏主框架的行列数
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const int row						：行数(错误则为0，不设上限，人为保证正确性)
			const int col						：列数(错误则为0，不设上限，人为保证正确性)
  返 回 值：
  说    明：1、指消除类游戏的矩形区域的行列值
            2、行列的变化会导致CONSOLE_GRAPHICS_INFO结构体中其它成员值的变化，要处理
***************************************************************************/
int gmw_set_rowcol(CONSOLE_GRAPHICS_INFO *const pCGI, const int row, const int col)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	pCGI->col_num = col;
	pCGI->row_num = row;
	//行列的变化会导致cmd窗口变化，lines，cols和每行每列宽度变化：bwidth和bhigh
	
	pCGI->CFI.bwidth = pCGI->CFI.block_width * pCGI->col_num + pCGI->CFI.block_width_ext * (pCGI->col_num -1)+4;
	pCGI->CFI.bhigh = pCGI->CFI.block_high * pCGI->row_num + pCGI->CFI.block_high_ext * (pCGI->row_num -1)+2;
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	pCGI->SLI.lower_start_y = pCGI->start_y + pCGI->CFI.bhigh;
	return 0; //此句可根据需要修改
}
//如果有边框的情况：x1=pCGI->start_x+(pCGI->col_num-1)*
/***************************************************************************
  函数名称：
  功    能：设置整个窗口（含游戏区、附加区在内的整个cmd窗口）的颜色
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   const int bg_color					：前景色（缺省COLOR_BLACK）
		   const int fg_color					：背景色（缺省COLOR_WHITE）
		   const bool cascade					：是否级联（缺省为true-级联）
  返 回 值：
  说    明：1、cascade = true时
				同步修改游戏主区域的颜色
				同步修改上下状态栏的正常文本的背景色和前景色，醒目文本的背景色（前景色不变）
			2、不检查颜色值错误及冲突，需要人为保证
				例：颜色非0-15
				    前景色背景色的值一致导致无法看到内容
					前景色正好是状态栏醒目前景色，导致无法看到醒目提示
					...
***************************************************************************/
int gmw_set_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int bgcolor, const int fgcolor, const bool cascade)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	pCGI->area_bgcolor = bgcolor;
	pCGI->area_fgcolor = fgcolor;
	if (cascade == true) {
		pCGI->CFI.bgcolor = bgcolor;
		pCGI->CFI.fgcolor = fgcolor;
		pCGI->SLI.lower_normal_bgcolor = bgcolor;
		pCGI->SLI.lower_normal_fgcolor = fgcolor;
		pCGI->SLI.top_normal_bgcolor = bgcolor;
		pCGI->SLI.top_normal_fgcolor = fgcolor;
		pCGI->SLI.lower_catchy_bgcolor = bgcolor;
		pCGI->SLI.top_catchy_bgcolor = bgcolor;
	}
	
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：设置窗口的字体
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   const char *fontname					：字体名称（只能是"Terminal"和"新宋体"两种，错误则返回-1，不改变字体）
		   const int fs_high					：字体高度（缺省及错误为16，不设其它限制，人为保证）
		   const int fs_width					：字体高度（缺省及错误为8，不设其它限制，人为保证）
  返 回 值：
  说    明：1、与cmd_console_tools中的setfontsize相似，目前只支持“点阵字体”和“新宋体”
            2、若设置其它字体则直接返回，保持原字体设置不变
***************************************************************************/
int gmw_set_font(CONSOLE_GRAPHICS_INFO *const pCGI, const char *fontname, const int fs_high, const int fs_width)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//strcmp返回0说明相等
	if (int(strcmp(fontname, "新宋体") )!=0 && int(strcmp(fontname, "Terminal") )!= 0) {
		return -1;
	}
	strcpy(pCGI->CFT.font_type,fontname);
	pCGI->CFT.font_size_high = fs_high;
	pCGI->CFT.font_size_width = fs_width;
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：设置延时
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   const int type						：延时的类型（目前为3种）
		   const int delay_ms					：以ms为单位的延时
			   画边框的延时：0 ~ 不设上限，人为保证正确（<0则置0）
			   画色块的延时：0 ~ 不设上限，人为保证正确（<0则置0）
			   色块移动的延时：BLOCK_MOVED_DELAY_MS ~ 不设上限，人为保证正确（ <BLOCK_MOVED_DELAY_MS 则置 BLOCK_MOVED_DELAY_MS）
  返 回 值：
  说    明：
***************************************************************************/
int gmw_set_delay(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const int delay_ms)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	switch (type) {
		case(DELAY_OF_DRAW_FRAME):
			pCGI->delay_of_draw_frame = delay_ms;
			break;
		case(DELAY_OF_DRAW_BLOCK):
			pCGI->delay_of_draw_block = delay_ms;
			break;
		case(DELAY_OF_BLOCK_MOVED):
			if ((delay_ms) < BLOCK_MOVED_DELAY_MS) {
				pCGI->delay_of_block_moved = BLOCK_MOVED_DELAY_MS;
			}
			else
				pCGI->delay_of_block_moved = delay_ms;
			break;
		default:
			break;

	}
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  输入参数：设置游戏主框架结构之外需要保留的额外区域
  功    能：CONSOLE_GRAPHICS_INFO *const pCGI	：
		   const int up_lines					：上部额外的行（缺省及错误为0，不设上限，人为保证）
		   const int down_lines				：下部额外的行（缺省及错误为0，不设上限，人为保证）
		   const int left_cols					：左边额外的列（缺省及错误为0，不设上限，人为保证）
		   const int right_cols				：右边额外的列（缺省及错误为0，不设上限，人为保证）
  返 回 值：
  说    明：额外行列的变化会导致CONSOLE_GRAPHICS_INFO结构体中其它成员值的变化，要处理
***************************************************************************/
int gmw_set_ext_rowcol(CONSOLE_GRAPHICS_INFO *const pCGI, const int up_lines, const int down_lines, const int left_cols, const int right_cols)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//首先改变额外的值
	pCGI->extern_up_lines = up_lines;
	pCGI->extern_down_lines = down_lines;
	pCGI->extern_left_cols = left_cols;
	pCGI->extern_right_cols = right_cols;
	//会改变的值由startx和starty和cmd窗口大小
	pCGI->start_x = pCGI->draw_frame_with_row_no * 2 + pCGI->extern_left_cols;
	pCGI->start_y = pCGI->top_status_line + pCGI->draw_frame_with_col_no + pCGI->extern_up_lines;
	
	//cmd窗口计算方式已经新定义
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4+pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1+pCGI->extern_right_cols;
	
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：填充 CONSOLE_FRAME_TYPE 结构中的11种线型（缺省4种）
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const int type						：1 - 全线 2 - 全单线 3 - 横双竖单 4 - 横单竖双
  返 回 值：
  说    明：
***************************************************************************/
int gmw_set_frame_default_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const int type)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	switch (type) {
		case 1://全双线
			strcpy(pCGI->CFI.top_left, "╔");
			strcpy(pCGI->CFI.lower_left, "╚");
			strcpy(pCGI->CFI.top_right, "╗");
			strcpy(pCGI->CFI.lower_right, "╝");
			strcpy(pCGI->CFI.h_normal, "═");
			strcpy(pCGI->CFI.v_normal, "║");
			strcpy(pCGI->CFI.h_top_separator, "╦");
			strcpy(pCGI->CFI.h_lower_separator, "╩");
			strcpy(pCGI->CFI.v_left_separator, "╠");
			strcpy(pCGI->CFI.v_right_separator, "╣");
			strcpy(pCGI->CFI.mid_separator, "╬");
			break;
		case(2)://全单线
			strcpy(pCGI->CFI.top_left, "┏");//
			strcpy(pCGI->CFI.lower_left, "┗");
			strcpy(pCGI->CFI.top_right, "┓");
			strcpy(pCGI->CFI.lower_right, "┛");
			strcpy(pCGI->CFI.h_normal, "━");
			strcpy(pCGI->CFI.v_normal, "┃");//┃
			strcpy(pCGI->CFI.h_top_separator, "┳");// ┳
			strcpy(pCGI->CFI.h_lower_separator, "┻");
			strcpy(pCGI->CFI.v_left_separator, "┣");
			strcpy(pCGI->CFI.v_right_separator, "┫");
			strcpy(pCGI->CFI.mid_separator, "╋");
			break;
		case(3)://横双竖单
			strcpy(pCGI->CFI.top_left, "╒");
			strcpy(pCGI->CFI.lower_left, "╘");
			strcpy(pCGI->CFI.top_right, "╕");// ╕
			strcpy(pCGI->CFI.lower_right, "╛");
			strcpy(pCGI->CFI.h_normal, "═");
			strcpy(pCGI->CFI.v_normal, "│");
			strcpy(pCGI->CFI.h_top_separator, "╤");
			strcpy(pCGI->CFI.h_lower_separator, "╧");
			strcpy(pCGI->CFI.v_left_separator, "╞");
			strcpy(pCGI->CFI.v_right_separator, "╡");
			strcpy(pCGI->CFI.mid_separator, "╪");
			break;
		case(4)://横单竖双
			strcpy(pCGI->CFI.top_left, "╓");
			strcpy(pCGI->CFI.lower_left, "╙");
			strcpy(pCGI->CFI.top_right, "╖");// ╕
			strcpy(pCGI->CFI.lower_right, "╜");
			strcpy(pCGI->CFI.h_normal, "─");//─
			strcpy(pCGI->CFI.v_normal, "║");
			strcpy(pCGI->CFI.h_top_separator, "╥");
			strcpy(pCGI->CFI.h_lower_separator, "╨");
			strcpy(pCGI->CFI.v_left_separator, "╟");//
			strcpy(pCGI->CFI.v_right_separator, "╢");
			strcpy(pCGI->CFI.mid_separator, "╫");
			break;
		default:
			break;
			

	}
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：填充 CONSOLE_FRAME_TYPE 结构中的11种线型
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const char *...						：共11种，具体见.h，此处略
  返 回 值：
  说    明：约定为一个中文制表符，可以使用其它内容，人为保证2字节
			1、超过2字节则只取前2字节
			2、如果给NULL，用两个空格替代
			3、如果给1字节，则补一个空格，如果因此而导致显示乱，不算错
***************************************************************************/
int gmw_set_frame_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const char *top_left, const char *lower_left, const char *top_right,
	const char *lower_right, const char *h_normal, const char *v_normal, const char *h_top_separator,
	const char *h_lower_separator, const char *v_left_separator, const char *v_right_separator, const char *mid_separator)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	strncpy(pCGI->CFI.top_left, top_left,2);
	strncpy(pCGI->CFI.lower_left, lower_left,2);
	strncpy(pCGI->CFI.top_right,top_right,2);
	strncpy(pCGI->CFI.lower_right,lower_right,2);
	strncpy(pCGI->CFI.h_normal,h_normal,2);
	strncpy(pCGI->CFI.v_normal,v_normal,2);
	strncpy(pCGI->CFI.h_top_separator,h_top_separator,2);
	strncpy(pCGI->CFI.h_lower_separator, h_lower_separator,2);
	strncpy(pCGI->CFI.v_left_separator, v_left_separator,2);
	strncpy(pCGI->CFI.v_right_separator, v_right_separator,2);
	strncpy(pCGI->CFI.mid_separator, mid_separator,2);
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：填充 CONSOLE_FRAME_TYPE 结构中的色块数量大小、是否需要分隔线等
  输入参数：输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const int block_width						：宽度（错误及缺省2，因为约定表格线为中文制表符，如果给出奇数，要+1）
			const int block_high						：高度（错误及缺省1）
			const bool separator						：是否需要分隔线（缺省为true，需要分隔线）
  返 回 值：
  说    明：框架大小/是否需要分隔线等的变化会导致CONSOLE_GRAPHICS_INFO结构体中其它成员值的变化，要处理
***************************************************************************/
int gmw_set_frame_style(CONSOLE_GRAPHICS_INFO *const pCGI, const int block_width, const int block_high, const bool separator)
{
	int block_widths = block_width;
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	/*还要处理输入错误？*/
	if (block_width % 2 == 1) {//奇数
		block_widths++;
	}
	
	pCGI->CFI.block_width = block_widths;
	pCGI->CFI.block_high = block_high;
	pCGI->CFI.separator = separator;
	//分隔线（分割线不是紧连着色块的分隔线）的有无、色块高和宽的大小会导致cols、lines、bwidth、bhigh的变化；
	pCGI->CFI.block_width_ext = pCGI->CFI.separator * 2;
	pCGI->CFI.block_high_ext = pCGI->CFI.separator;
	pCGI->CFI.bwidth = pCGI->CFI.block_width * pCGI->col_num + pCGI->CFI.block_width_ext * (pCGI->col_num -1)+4;
	pCGI->CFI.bhigh = pCGI->CFI.block_high * pCGI->row_num + pCGI->CFI.block_high_ext * (pCGI->row_num-1)+2;

	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	pCGI->SLI.lower_start_y = pCGI->start_y + pCGI->CFI.bhigh;
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：填充 CONSOLE_BORDER_TYPE 结构中的颜色
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const int bg_color					：背景色（缺省 -1表示用窗口背景色）
			const int fg_color					：前景色（缺省 -1表示用窗口前景色）
  返 回 值：
  说    明：不检查颜色值错误及冲突，需要人为保证
				例：颜色非0-15，前景色背景色的值一致导致无法看到内容等
***************************************************************************/
int gmw_set_frame_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int bgcolor, const int fgcolor)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//设置背景框的颜色
	pCGI->CFI.bgcolor = bgcolor;
	pCGI->CFI.fgcolor = fgcolor;
	//?
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：填充 CONSOLE_BLOCK_INFO 结构中的6种线型（缺省4种）
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const int type						：1 - 全双线 2 - 全单线 3 - 横双竖单 4 - 横单竖双
  返 回 值：
  说    明：
***************************************************************************/
int gmw_set_block_default_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const int type)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	switch(type){
		case 1://全双线
			strcpy(pCGI->CBI.top_left, "╔");
			strcpy(pCGI->CBI.lower_left,"╚");
			strcpy(pCGI->CBI.top_right, "╗");
			strcpy(pCGI->CBI.lower_right, "╝");
			strcpy(pCGI->CBI.h_normal, "═");
			strcpy(pCGI->CBI.v_normal, "║");
			break;
		case 2://全单线
			strcpy(pCGI->CBI.top_left, "┏");
			strcpy(pCGI->CBI.lower_left, "┗");
			strcpy(pCGI->CBI.top_right, "┓");
			strcpy(pCGI->CBI.lower_right, "┛");
			strcpy(pCGI->CBI.h_normal, "━");
			strcpy(pCGI->CBI.v_normal, "┃");
			break;
		case 3://横双竖单
			strcpy(pCGI->CBI.top_left, "╒");
			strcpy(pCGI->CBI.lower_left, "╘");
			strcpy(pCGI->CBI.top_right, "╕");
			strcpy(pCGI->CBI.lower_right, "╛");
			strcpy(pCGI->CBI.h_normal, "═");
			strcpy(pCGI->CBI.v_normal, "│");
			break;
		case 4://横单竖双
			strcpy(pCGI->CBI.top_left, "╓");
			strcpy(pCGI->CBI.lower_left, "╙");
			strcpy(pCGI->CBI.top_right, "╖");
			strcpy(pCGI->CBI.lower_right, "╜");
			strcpy(pCGI->CBI.h_normal, "─");
			strcpy(pCGI->CBI.v_normal, "║");
			break;
		default:
			break;
			
	}
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：填充 CONSOLE_BLOCK_INFO 结构中的6种线型
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   const char *...					：共6种，具体见.h，此处略
  返 回 值：
  说    明：约定为一个中文制表符，可以使用其它内容，人为保证2字节
			1、超过2字节则只取前2字节
			2、如果给NULL，用两个空格替代
			3、如果给1字节，则补一个空格，如果因此而导致显示乱，不算错
***************************************************************************/
int gmw_set_block_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const char *top_left, const char *lower_left, const char *top_right, const char *lower_right, const char *h_normal, const char *v_normal)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//如果给null，用2个空格表示，怎么实现？后续思考
	strncpy(pCGI->CBI.top_left, top_left,2);
	strncpy(pCGI->CBI.lower_left, lower_left,2);
	strncpy(pCGI->CBI.top_right, top_right,2);
	strncpy(pCGI->CBI.lower_right, lower_right,2);
	strncpy(pCGI->CBI.h_normal,h_normal,2);
	strncpy(pCGI->CBI.v_normal, v_normal,2);
	
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：设置每个游戏色块(彩球)是否需要小边框
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   const bool on_off					：true - 需要 flase - 不需要（缺省false）
  返 回 值：
  说    明：边框约定为中文制表符，双线
***************************************************************************/
int gmw_set_block_border_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	pCGI->CBI.block_border = on_off;
	
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：设置是否显示上下状态栏
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const int type						：状态栏类型（上/下）
			const bool on_off					：true - 需要 flase - 不需要（缺省true）
  返 回 值：
  说    明：1、状态栏的相关约定如下：
			   1.1、上状态栏只能一行，在主区域最上方框线/列标的上面，为主区域的最开始一行（主区域的左上角坐标就是上状态栏的坐标）
			   1.2、下状态栏只能一行，在主区域最下方框线的下面
			   1.3、状态栏的宽度为主区域宽度，如果信息过长则截断
		   2、行列的变化会导致CONSOLE_GRAPHICS_INFO结构体中其它成员值的变化，要处理
***************************************************************************/
int gmw_set_status_line_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const bool on_off)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	if (on_off == false) {

		//不需要状态栏 还要分类是上状态栏还是下状态栏
		switch(type) {
			case(TOP_STATUS_LINE)://不需要上状态栏
				pCGI->top_status_line = false;
				break;
			case(LOWER_STATUS_LINE)://不需要下状态栏
				pCGI->lower_status_line = false;
				break;
		}
		
	}
	//有状态栏
	else {
		switch (type) {
			case(TOP_STATUS_LINE)://需要上状态栏
				pCGI->top_status_line = true;
				break;
			case(LOWER_STATUS_LINE)://需要下状态栏
				pCGI->lower_status_line = true;
				break;
			default:
				break;
		}
	}
	/*上状态栏还会影响starty*/
	pCGI->start_y = pCGI->top_status_line + pCGI->draw_frame_with_col_no + pCGI->extern_up_lines;
	
	/*状态栏的有无会改变结构体的其他成员中的starty和lines*/
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	pCGI->SLI.lower_start_y = pCGI->start_y + pCGI->CFI.bhigh;
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：设置上下状态栏的颜色
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const int type						：状态栏类型（上/下）
			const int normal_bgcolor			：正常文本背景色（缺省 -1表示使用窗口背景色）
			const int normal_fgcolor			：正常文本前景色（缺省 -1表示使用窗口前景色）
			const int catchy_bgcolor			：醒目文本背景色（缺省 -1表示使用窗口背景色）
			const int catchy_fgcolor			：醒目文本前景色（缺省 -1表示使用亮黄色）
  输入参数：
  返 回 值：
  说    明：不检查颜色值错误及冲突，需要人为保证
				例：颜色非0-15，前景色背景色的值一致导致无法看到内容等
***************************************************************************/
int gmw_set_status_line_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const int normal_bgcolor, const int normal_fgcolor, const int catchy_bgcolor, const int catchy_fgcolor)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	switch (type) {
		case(TOP_STATUS_LINE)://上
			pCGI->SLI.top_normal_bgcolor = normal_bgcolor;
			pCGI->SLI.top_normal_fgcolor = normal_fgcolor;
			pCGI->SLI.top_catchy_bgcolor = catchy_bgcolor;
			pCGI->SLI.top_catchy_fgcolor = catchy_fgcolor;
			break;
		case(LOWER_STATUS_LINE):
			pCGI->SLI.lower_normal_bgcolor = normal_bgcolor;
			pCGI->SLI.lower_normal_fgcolor = normal_fgcolor;
			pCGI->SLI.lower_catchy_bgcolor = catchy_bgcolor;
			pCGI->SLI.lower_catchy_fgcolor = catchy_fgcolor;
			break;
		default:
			break;
	}
	
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：设置是否显示行号
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const bool on_off					：true - 显示 flase - 不显示（缺省false）
  返 回 值：
  说    明：1、行号约定为字母A开始连续排列（如果超过26，则从a开始，超过52的统一为*，实际应用不可能）
            2、是否显示行号的变化会导致CONSOLE_GRAPHICS_INFO结构体中其它成员值的变化，要处理
***************************************************************************/
int gmw_set_rowno_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	if (on_off == false) {
		//不显示行号、列号,导致startx、y、lines、cols的变化
		//仅不显示行号，导致startx和cols的变化
		pCGI->draw_frame_with_row_no = false;

	}
	else
		pCGI->draw_frame_with_row_no = true;

	pCGI->start_x = pCGI->draw_frame_with_row_no * 2 + pCGI->extern_left_cols;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：设置是否显示列标
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
			const bool on_off					：true - 显示 flase - 不显示（缺省false）
  返 回 值：
  说    明：1、列标约定为数字0开始连续排列（数字0-99，超过99统一为**，实际应用不可能）
            2、是否显示列标的变化会导致CONSOLE_GRAPHICS_INFO结构体中其它成员值的变化，要处理
***************************************************************************/
int gmw_set_colno_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//仅不显示列号，导致starty和lines的变化
	if (on_off == false) {
		//不显示列号，
		pCGI->draw_frame_with_col_no = false;
	}
	else
		pCGI->draw_frame_with_col_no = true;
	pCGI->start_y = pCGI->top_status_line + pCGI->draw_frame_with_col_no + pCGI->extern_up_lines;
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->SLI.lower_start_y = pCGI->start_y + pCGI->CFI.bhigh;
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：打印 CONSOLE_GRAPHICS_INFO 结构体中的各成员值
  输入参数：
  返 回 值：
  说    明：1、仅供调试用，打印格式自定义
            2、本函数测试用例中未调用过，可以不实现
***************************************************************************/
int gmw_print(const CONSOLE_GRAPHICS_INFO *const pCGI)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	cout << pCGI->cols << " 列" << pCGI->lines << "行" << endl;
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将 CONSOLE_GRAPHICS_INFO 结构体用缺省值进行初始化
  输入参数：CONSOLE_GRAPHICS_INFO *const pCGI：整体结构指针
		   const int row					：游戏区域色块行数（缺省10）
		   const int col					：游戏区域色块列数（缺省10）
		   const int bgcolor				：整个窗口背景色（缺省 COLOR_BLACK）
		   const int fgcolor				：整个窗口背景色（缺省 COLOR_WHITE）
  返 回 值：
  说    明：窗口背景黑/前景白，点阵16*8，上下左右无额外行列，上下状态栏均有，无行号/列标，框架线型为双线，色块宽度2/高度1/无小边框，颜色略
***************************************************************************/
int gmw_init(CONSOLE_GRAPHICS_INFO *const pCGI, const int row, const int col, const int bgcolor, const int fgcolor)
{
	/* 首先置标记 */
	pCGI->inited = CGI_INITED;
	/*在头文件中已经给出函数缺省值*/
	gmw_set_color(pCGI);
	gmw_set_ext_rowcol(pCGI);//缺省预留都是0
	gmw_set_rowcol(pCGI, row, col);
	//不显示行号，不显示列标
	gmw_set_rowno_switch(pCGI,false);
	gmw_set_colno_switch(pCGI, false);
	//画边框及色块时无延时，色块移动时延时3ms
	gmw_set_delay(pCGI, DELAY_OF_DRAW_FRAME, 0);
	gmw_set_delay(pCGI, DELAY_OF_DRAW_BLOCK, 0);
	gmw_set_delay(pCGI, DELAY_OF_BLOCK_MOVED, 3);
	/*上状态栏开，正常文本颜色同窗口，醒目文本背景同窗口，前景为亮黄
		下状态栏开，正常文本颜色同窗口，醒目文本背景同窗口，前景为亮黄*/
	gmw_set_status_line_switch(pCGI, TOP_STATUS_LINE);
	gmw_set_status_line_switch(pCGI, LOWER_STATUS_LINE); 
	gmw_set_status_line_color(pCGI, TOP_STATUS_LINE,-1,-1,-1,COLOR_HYELLOW);
	gmw_set_status_line_color(pCGI, LOWER_STATUS_LINE ,- 1, -1,-1, COLOR_HYELLOW);
	//设置框架起始位置坐标
	pCGI->start_x = pCGI->draw_frame_with_row_no * 2+pCGI->extern_left_cols;
	pCGI->start_y = pCGI->top_status_line + pCGI->draw_frame_with_col_no+ pCGI->extern_up_lines;
	pCGI->SLI.lower_start_y=pCGI->start_y + pCGI->CFI.bhigh;
	//下面初始化边框的11种分割线
	gmw_set_frame_linetype(pCGI);
	gmw_set_frame_default_linetype(pCGI, 1);
	
	//然后色块宽2高1，要分割线
	gmw_set_frame_style(pCGI);
	//暂不定义
	//不需要小边框
	gmw_set_block_border_switch(pCGI);
	gmw_set_block_default_linetype(pCGI, 1);//默认色块缺省为双线边框
	//定义字体、字号信息
	gmw_set_font(pCGI);
	
	//初始化cmd窗口下的line和column大小
	//上额外空间+上状态栏+列标显示+主区域+下状态栏）+ 4（1中文输入法提示行+3预留空行）
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	pCGI->SLI.lower_catchy_fgcolor = COLOR_HYELLOW;
	cct_setcolor();
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：画主游戏框架
  输入参数：const CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
  返 回 值：
  说    明：具体可参考demo的效果
***************************************************************************/
int gmw_draw_frame(const CONSOLE_GRAPHICS_INFO *const pCGI)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	/*画初始框架*/
	//首先将缓冲区设置为与规定大小相匹配的大小，列在前，行在后
	cct_setfontsize(pCGI->CFT.font_type, pCGI->CFT.font_size_high, pCGI->CFT.font_size_width);
	cct_setconsoleborder(pCGI->cols,pCGI->lines);
	
	
	//根据是否联及修改整个区域，上下栏状态。
	cct_setcolor(pCGI->area_bgcolor, pCGI->area_fgcolor);
	cct_cls();
	/*cct_gotoxy(0, 0);
	//首先将整个游戏区域变成规定颜色
	for (int i = 0; i <pCGI->lines; i++) {
		for (int j = 0; j <pCGI->cols; j++) {
			cout << ' ';
		}
		cout<<endl;
	}
	for (int j = 0; j < pCGI->cols; j++) {
		cout << ' ';
	}
	//画第一行；*/
	int Y = pCGI->start_y;
	int X = pCGI->start_x;
	
	gmw_inner_draw_frame_perline(pCGI, Y, 1);
	Y++;
	for (int j = 0; j < pCGI->row_num - 1; j++) {
		for (int i = 0; i < pCGI->CFI.block_high; i++) {
			//if()要判断并且打印行标
			cct_gotoxy(X, Y);
			gmw_inner_draw_frame_perline(pCGI, Y, 2);
			Y++;
		}
		if (pCGI->CFI.separator) {
			cct_gotoxy(X, Y);
			gmw_inner_draw_frame_perline(pCGI, Y, 3);
			Y++;
		}
		
		
	}
	for (int i = 0; i < pCGI->CFI.block_high; i++) {
		cct_gotoxy(X, Y);
		gmw_inner_draw_frame_perline(pCGI, Y, 2);
		Y++;
	}
	cct_gotoxy(X, Y);
	gmw_inner_draw_frame_perline(pCGI, Y, 4);
	//打印行标是需要条件的
	if (pCGI->draw_frame_with_row_no) {
		cct_setcolor(pCGI->area_bgcolor, pCGI->area_fgcolor);
		X = pCGI->start_x-2;
		Y = pCGI->start_y + (pCGI->CFI.block_high + 1) / 2;
		cct_gotoxy(X, Y);
		putchar('A');
		Sleep(pCGI->delay_of_draw_frame);
		for (int num2 = 1; num2 < pCGI->row_num; num2++) {
			Y += pCGI->CFI.block_high +pCGI->CFI.separator;
			cct_gotoxy(X, Y);
			if (num2 < 26)
				putchar('A' + num2);
			else if (num2 >= 26 && num2 < 52) {
				putchar('a' + num2 - 26);
			}
			else
				putchar('*');
			Sleep(pCGI->delay_of_draw_frame);
		}
	}
	
	
	
	

	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在状态栏上显示信息
  输入参数：const CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   const int type							：指定是上/下状态栏
		   const char *msg						：正常信息
		   const char *catchy_msg					：需要特别标注的信息（在正常信息前显示）
  返 回 值：
  说    明：1、输出宽度限定为主框架的宽度（含行号列标位置），超出则截去
            2、如果最后一个字符是某汉字的前半个，会导致后面乱码，要处理
***************************************************************************/
int gmw_status_line(const CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const char *msg, const char *catchy_msg)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//前提是该状态栏是开启的，才打印，否则直接返回
	
	switch (type) {
		case TOP_STATUS_LINE://上状态栏；
			if (pCGI->top_status_line == 0)
				return -1;//不需要
			cct_gotoxy(pCGI->start_x, pCGI->start_y-1-pCGI->draw_frame_with_col_no);
			if (catchy_msg != NULL) {
				cct_setcolor(pCGI->SLI.top_catchy_bgcolor, pCGI->SLI.top_catchy_fgcolor);
				cout << catchy_msg;
			}
			cct_setcolor(pCGI->SLI.top_normal_bgcolor, pCGI->SLI.top_normal_fgcolor);
			
			cout << msg;
			break;
		case LOWER_STATUS_LINE://下状态栏
			if (pCGI->lower_status_line == 0)
				return -1;//不需要
			cct_gotoxy(pCGI->start_x, pCGI->start_y+pCGI->CFI.bhigh);
			if (catchy_msg != NULL) {
				cct_setcolor(pCGI->SLI.lower_catchy_bgcolor, pCGI->SLI.lower_catchy_fgcolor);
				cout << catchy_msg;
			}
			cct_setcolor(pCGI->SLI.lower_normal_bgcolor, pCGI->SLI.lower_normal_fgcolor);
			cout << msg<<endl;
			break;

	}
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：显示某一个色块(内容为字符串，坐标为row/col)
  输入参数：const CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   const int row_no						：行号（从0开始，人为保证正确性，程序不检查）
		   const int col_no						：列号（从0开始，人为保证正确性，程序不检查）
		   const int bdi_value						：需要显示的值
		   const BLOCK_DISPLAY_INFO *const bdi		：存放该值对应的显示信息的结构体数组
  返 回 值：
  说    明：1、BLOCK_DISPLAY_INFO 的含义见头文件，用法参考测试样例
            2、bdi_value为 BDI_VALUE_BLANK 表示空白块，要特殊处理
***************************************************************************/
int gmw_draw_block(const CONSOLE_GRAPHICS_INFO *const pCGI, const int row_no, const int col_no, const int bdi_value, const BLOCK_DISPLAY_INFO *const bdi)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//函数执行一次，画一个色块
	//首先将光标移动到指定位置，X为画色块的起始坐标，计算公式为框架起始坐标+行数*色块带框总宽度
	int X = pCGI->start_x + 2 + col_no * (pCGI->CFI.block_width + pCGI->CFI.block_width_ext);
	int Y = pCGI->start_y + 1 +row_no* (pCGI->CFI.block_high + pCGI->CFI.block_high_ext);
	int hangle = pCGI->CFI.block_width - 4;//除去有色块自身边框后的值
	int nomber = 0;
	cct_gotoxy(X, Y);
	//这里的颜色为什么不会变？
	//首先根据传入的值，遍历结构体数组，找到相同的值，确定背景和前景色
	for (nomber = 0; bdi[nomber].value != BDI_VALUE_END; nomber++) {
		if (bdi[nomber].value == bdi_value) {
			cct_setcolor(bdi[nomber].bgcolor, bdi[nomber].fgcolor);
			break;
		}
	}//退出循环后，得到的nomber正好是结构体所对的标
	//cct_setcolor(bdi[bdi_value].bgcolor, bdi[bdi_value].fgcolor);
	//对小边框内的线进行初始化，默认为双线
	//如果色块有边框则要先打印边框
	if (bdi_value == BDI_VALUE_BLANK) {//0不显示，用空格填充即可
		for (int j = 0; j < pCGI->CFI.block_high; j++) {
			for (int i = 0; i < pCGI->CFI.block_width; i++) {
				Sleep(pCGI->delay_of_draw_block);
				cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
				cout << setw(1) << " ";
			}
			Y++;
			cct_gotoxy(X, Y);
		}
	} 
	else if (bdi_value == BDI_VALUE_END) {
		//代表结束的特殊值
		return 0;
	}
	else{//如果值不为0的话
		    //是不是要先用白色把背景色去除
		    
		if (pCGI->CBI.block_border) {//需要边框
			cout << pCGI->CBI.top_left;
			Sleep(pCGI->delay_of_draw_block);
			int w = (pCGI->CFI.block_width - 4) / 2;
			for (int i = 0; i < w; i++) {
				cout << pCGI->CBI.h_normal;
				Sleep(pCGI->delay_of_draw_block);
			}
			cout << pCGI->CBI.top_right;
			Sleep(pCGI->delay_of_draw_block);
			Y++;
			cct_gotoxy(X, Y);
			if (pCGI->CFI.block_high > 2) {
				cout << pCGI->CBI.v_normal;
				Sleep(pCGI->delay_of_draw_block);
				if (bdi[nomber].content == NULL) {//!
				//直接显示数字
					cout << setw(hangle) << bdi_value;

				}
				else {//打印图形
					cout << setw(hangle) << bdi[nomber].content;
				}
				Sleep(pCGI->delay_of_draw_block);
				cout << pCGI->CBI.v_normal;
				Sleep(pCGI->delay_of_draw_block);
				Y++;
				cct_gotoxy(X, Y);
				int v_num = pCGI->CFI.block_high - 3;
				for (int i = 0; i < v_num; i++) {
					cout << pCGI->CBI.v_normal;
					Sleep(pCGI->delay_of_draw_block);
					int bk = (pCGI->CFI.block_width - 4) / 2;
					for (int i = 0; i < bk; i++) {
						cout << setw(2) << " ";
						Sleep(pCGI->delay_of_draw_block);
					}
					cout << pCGI->CBI.v_normal;
					Y++;
					cct_gotoxy(X, Y);
				}
				//打印最后一排
				cout << pCGI->CBI.lower_left;
				Sleep(pCGI->delay_of_draw_block);
				int bk2 = (pCGI->CFI.block_width - 4) / 2;
				for (int i = 0; i < bk2; i++) {
					cout << pCGI->CBI.h_normal;
					Sleep(pCGI->delay_of_draw_block);
				}
				cout << pCGI->CBI.lower_right;
				Sleep(pCGI->delay_of_draw_block);
			}
			else {//高为2且有边框
				cout << pCGI->CBI.lower_left;
				Sleep(pCGI->delay_of_draw_block);
				int bk2= (pCGI->CFI.block_width - 4) / 2;
				for (int i = 0; i < bk2; i++) {
					cout << pCGI->CBI.h_normal;
					Sleep(pCGI->delay_of_draw_block);
				}
				cout << pCGI->CBI.lower_right;
				Sleep(pCGI->delay_of_draw_block);
			}
				
		}
		else//色块自身没有边框
		{//则直接显示色块的形状
			if (bdi_value == BDI_VALUE_BLANK) {
				//如果是内部值是0，直接用空格填充
				cout << setw(2) << " ";
			}
			else if (bdi[nomber].content == NULL) {//!
				//直接显示数字
				cout << setw(pCGI->CFI.block_width) << bdi_value;
			}
			else {//打印图形
				cout << setw(pCGI->CFI.block_width)<< bdi[nomber].content;
			}
			//然后再看周围是否还有多余的空白
			//cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
			//int noborder_leftw = pCGI->CFI.block_width - 2;
			int noborder_lefth = pCGI->CFI.block_high - 1;//剩余空间为宽度-2；高度-1；
			/*for (int i = 0; i < noborder_leftw; i++) {
				cout << setw(1) << " ";
			}*/
			for (int i = 0; i < noborder_lefth; i++) {
				Y++;
				cct_gotoxy(X, Y);
				cout<<setw( pCGI->CFI.block_width)<<" ";
			}
		}
		

	}
	//比下状态栏+2
	cct_gotoxy(pCGI->start_x, pCGI->start_y + pCGI->CFI.bhigh+1);
	cct_setcolor();
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：移动某一个色块
  输入参数：const CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   const int row_no						：行号（从0开始，人为保证正确性，程序不检查）
		   const int col_no						：列号（从0开始，人为保证正确性，程序不检查）
		   const int bdi_value						：需要显示的值
		   const int blank_bdi_value				：移动过程中用于动画效果显示时用于表示空白的值（一般为0，此处做为参数代入，是考虑到可能出现的特殊情况）
		   const BLOCK_DISPLAY_INFO *const bdi		：存放显示值/空白值对应的显示信息的结构体数组
		   const int direction						：移动方向，一共四种，具体见cmd_gmw_tools.h
		   const int distance						：移动距离（从1开始，人为保证正确性，程序不检查）
  返 回 值：
  说    明：
***************************************************************************/
int gmw_move_block(const CONSOLE_GRAPHICS_INFO *const pCGI, const int row_no, const int col_no, const int bdi_value, const int blank_bdi_value, const BLOCK_DISPLAY_INFO *const bdi, const int direction, const int distance)
{
	/*移动的四种值：DOWN_TO_UP		0
                    UP_TO_DOWN		1
                    RIGHT_TO_LEFT	2
                    LEFT_TO_RIGHT	3*/
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	int X_drawblock= pCGI->start_x + 2 + col_no * (pCGI->CFI.block_width + pCGI->CFI.block_width_ext);
	int Y_drawblock = pCGI->start_y +1 + row_no * (pCGI->CFI.block_high + pCGI->CFI.block_high_ext);
	int i=0;
	cct_setcolor(bdi[bdi_value].bgcolor, bdi[bdi_value].fgcolor);//颜色设置；
	/*首先色块移动有延时，要展示延时。*/
	switch (direction) {
		case DOWN_TO_UP://向上移动色块
			//还要分框架有无边框而分开不同讨论
			for (i = 1; i <= distance; i++) {
				gmw_draw_block(pCGI, row_no - i, col_no, bdi_value, bdi);
				//Sleep(pCGI->delay_of_block_moved);
				//然后清理下方的色块；
				cct_gotoxy(X_drawblock, Y_drawblock -(i-1) * (pCGI->CFI.block_high + pCGI->CFI.block_high_ext));
				cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
				for (int cir = 0; cir <pCGI->CFI.block_high; cir++) {
					cct_gotoxy(X_drawblock, Y_drawblock - (i - 1) * (pCGI->CFI.block_high + pCGI->CFI.block_high_ext) + cir);
					cout << setw(pCGI->CFI.block_width) << " ";
					Sleep(pCGI->delay_of_block_moved);
				}
				Sleep(pCGI->delay_of_block_moved);
			}
			break;
		case  UP_TO_DOWN://向下移动
			for (i = 1; i <=distance; i++) {
				gmw_draw_block(pCGI, row_no+i, col_no, bdi_value, bdi);
				//然后清理上方的色块；
				//Sleep(pCGI->delay_of_block_moved);
				cct_gotoxy(X_drawblock, Y_drawblock+(i-1)* (pCGI->CFI.block_high + pCGI->CFI.block_high_ext));
				cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
				for (int cir = 0; cir < pCGI->CFI.block_high; cir++) {
					cct_gotoxy(X_drawblock, Y_drawblock + (i - 1) * (pCGI->CFI.block_high + pCGI->CFI.block_high_ext) + cir);
					cout << setw(pCGI->CFI.block_width) << " ";
					Sleep(pCGI->delay_of_block_moved);
				}
				Sleep(pCGI->delay_of_block_moved);
			}
			break;
		case RIGHT_TO_LEFT://向左移动
			for (i = 1; i <=distance; i++) {
				gmw_draw_block(pCGI, row_no, col_no-i, bdi_value, bdi);
				//Sleep(pCGI->delay_of_block_moved);
				//然后清理右方的色块；
				cct_gotoxy(X_drawblock-(i-1)*(pCGI->CFI.block_width+pCGI->CFI.block_width_ext), Y_drawblock);
				cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
				for (int cir = 0; cir < pCGI->CFI.block_high; cir++) {
					cct_gotoxy(X_drawblock - (i - 1) * (pCGI->CFI.block_width + pCGI->CFI.block_width_ext), Y_drawblock+cir );
					cout << setw(pCGI->CFI.block_width) << " ";
					Sleep(pCGI->delay_of_block_moved);
				}
				Sleep(pCGI->delay_of_block_moved);
			}
			break;
		case LEFT_TO_RIGHT://右移动
			for (i = 1; i <=distance; i++) {
				gmw_draw_block(pCGI, row_no, col_no+i, bdi_value, bdi);
				//Sleep(pCGI->delay_of_block_moved);
				//然后清理左方的色块；
				cct_gotoxy(X_drawblock +(i-1)* (pCGI->CFI.block_width + pCGI->CFI.block_width_ext), Y_drawblock);
				cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
				for (int cir = 0; cir < pCGI->CFI.block_high; cir++) {
					cct_gotoxy(X_drawblock + (i - 1) * (pCGI->CFI.block_width + pCGI->CFI.block_width_ext), Y_drawblock+ cir);
					cout << setw(pCGI->CFI.block_width) << " ";
					Sleep(pCGI->delay_of_block_moved);
				}
				Sleep(pCGI->delay_of_block_moved);
			}
			break;
		default:
			break;


	}
		
	return 0; //此句可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：读键盘或鼠标
  输入参数：const CONSOLE_GRAPHICS_INFO *const pCGI	：整体结构指针
		   int &MAction							：如果返回 CCT_MOUSE_EVENT(0)，则此值有效，为 MOUSE_ONLY_MOVED/MOUSE_LEFT_BUTTON_CLICK/MOUSE_RIGHT_BUTTON_CLICK 三者之一
		                                               如果返回 CCT_KEYBOARD_EVENT(1)，则此值无效
		   int &MRow								：如果返回 CCT_MOUSE_EVENT 且 MAction = MOUSE_ONLY_MOVED/MOUSE_LEFT_BUTTON_CLICK，则此值有效，表示左键选择的游戏区域的行号（从0开始）
												  其余情况此值无效（如果访问无效值导致错误，不是本函数的错!!!）
		   int &MCol								：如果返回 CCT_MOUSE_EVENT 且 MAction = MOUSE_ONLY_MOVED/MOUSE_LEFT_BUTTON_CLICK，则此值有效，表示左键选择的游戏区域的列号（从0开始）
												  其余情况此值无效（如果访问无效值导致错误，不是本函数的错!!!）
		   int &KeyCode1							：如果返回 CCT_KEYBOARD_EVENT，则此值有效，为读到的键码（如果双键码，则为第一个）
												  其余情况此值无效（如果访问无效值导致错误，不是本函数的错!!!）
		   int &KeyCode2							：如果返回 CCT_KEYBOARD_EVENT，则此值有效，为读到的键码（如果双键码，则为第二个，如果是单键码，则为0）
												  其余情况此值无效（如果访问无效值导致错误，不是本函数的错!!!）
		   const bool update_lower_status_line		：鼠标移动时，是否要在本函数中显示"[当前光标] *行*列/位置非法"的信息（true=显示，false=不显示，缺省为true）
  返 回 值：函数返回约定
		   1、如果是鼠标移动，得到的MRow/MCol与传入的相同(鼠标指针微小的移动)，则不返回，继续读
							  得到行列非法位置，则不返回，根据 update_lower_status_line 的设置在下状态栏显示"[当前光标] 位置非法"
							  得到的MRow/MCol与传入的不同(行列至少一个变化)，根据 update_lower_status_line 的设置在下状态栏显示"[当前光标] *行*列"，再返回MOUSE_ONLY_MOVED（有些游戏返回后要处理色块的不同颜色显示）
		   2、如果是按下鼠标左键，且当前鼠标指针停留在主游戏区域的*行*列上，则返回 CCT_MOUSE_EVENT ，MAction 为 MOUSE_LEFT_BUTTON_CLICK, MRow 为行号，MCol 为列标
		                          且当前鼠标指针停留在非法区域（非游戏区域，游戏区域中的分隔线），则不返回，根据 update_lower_status_line 的设置在下状态栏显示"[当前光标] 位置非法"
		   3、如果是按下鼠标右键，则不判断鼠标指针停留区域是否合法，直接返回 CCT_MOUSE_EVENT ，MAction 为 MOUSE_LEFT_BUTTON_CLICK, MRow、MCol不可信
		   4、如果按下键盘上的某键（含双键码按键），则直接返回 CCT_KEYBOARD_EVENT，KeyCode1/KeyCode2中为对应的键码值
 说    明：通过调用 cmd_console_tools.cpp 中的 read_keyboard_and_mouse 函数实现
***************************************************************************/
int gmw_read_keyboard_and_mouse(const CONSOLE_GRAPHICS_INFO *const pCGI, int &MAction, int &MRow, int &MCol, int &KeyCode1, int &KeyCode2, const bool update_lower_status_line)
{
	/* 防止在未调用 gmw_init 前调用其它函数 */
	if (pCGI->inited != CGI_INITED)
		return -1;
	cct_enable_mouse();//允许鼠标操作
	cct_setcursor(CURSOR_INVISIBLE);//关闭光标
	int X = 0, Y = 0;//读取的鼠标的坐标
	int rett;//ret为cct鼠标函数返回值
	int loop = 1;
	int old_rrow=-1,old_rcol=-1;//记录上一次鼠标读到的行列
	char tempd[256] = " ";
	int flag = 0;
	
	while (loop) {
		old_rrow = MRow;
		old_rcol = MCol;//第一次循环开始都是-1
		//循环不退出的条件：移动的时候：得到的行列都和之前的相同 /行列位置非法，状态栏显示位置非法后继续读。
		//鼠标移动会返回的情况：得到行列至少有一个变化并且都合法，状态栏打印后返回MOVED
		//鼠标左键：合法就返回，非法不返回。非法的话状态栏打印非法
		//鼠标右键：不判断行列合法性，直接返回
		//键盘键：含双建码按键，直接返回建码
		rett = cct_read_keyboard_and_mouse(X, Y, MAction, KeyCode1, KeyCode2);
		//如果是键盘操作首先根据读取的xy值判断行列是否合法
		//按照cct给出的模板往里面套
		if (rett == CCT_MOUSE_EVENT) {
			switch (MAction) {
				
				case MOUSE_ONLY_MOVED://移动
					//要根据移动的xy计算出读取的行列；
					//需要行列的计算公式
					//根据合法位置读取光标所在的行列
						//MRow由Y坐标决定 从0--line-1
					
					if (X <= (pCGI->start_x+1) || Y <= pCGI->start_y || X >= (pCGI->start_x-1) + pCGI->CFI.bwidth - 1 || Y >= pCGI->start_y + pCGI->CFI.bhigh - 1) {
						//状态栏要显示位置非法；
						if (update_lower_status_line) {
							gmw_status_line(pCGI, LOWER_STATUS_LINE, "[当前光标] 位置非法            ");
						}
						flag = 1;
						continue;//继续读
					}//此外,如果框架有分割线，碰到分割线也算非法位置
					else if (pCGI->CFI.separator) {
						if ((X-pCGI->start_x)%(pCGI->CFI.block_width+2)==0|| (X - pCGI->start_x) % (pCGI->CFI.block_width + 2)==1) {
							if (update_lower_status_line) {
								gmw_status_line(pCGI, LOWER_STATUS_LINE, "[当前光标] 位置非法           ");
							}
							flag = 1;
							continue;//继续读
						}
						else if ((Y- pCGI->start_y) % (pCGI->CFI.block_high +1) == 0 ) {
							if (update_lower_status_line) {
								gmw_status_line(pCGI, LOWER_STATUS_LINE, "[当前光标] 位置非法           ");
							}
							flag = 1;//flag=1是位置非法标记
							continue;//继续读
						}
					}
					if (pCGI->CFI.separator) {
						MRow = (Y - pCGI->start_y) / (pCGI->CFI.block_high + pCGI->CFI.separator);
						MCol = (X - pCGI->start_x) / (pCGI->CFI.block_width + pCGI->CFI.block_width_ext);
					}
					else {
						//无分割线
						MRow = (Y - pCGI->start_y-1) / pCGI->CFI.block_high;
						MCol = (X - pCGI->start_x-2) / pCGI->CFI.block_width;
					}
					//判断是否与之前的位置相同，如果是微小移动，还要继续读，
					if (MRow == old_rrow && MCol == old_rcol&&flag==0) {
						continue;
					}
					else {//至少有一个变化
						if (update_lower_status_line) {
							sprintf(tempd, "[当前光标] %c行%d列          ", char('A' + MRow), MCol); //未考虑mrow超过26，mcol超过99的情况，如有需要，请自行处理
							gmw_status_line(pCGI, LOWER_STATUS_LINE, tempd);
						}
						return CCT_MOUSE_EVENT;
					}
				
					break;
					//
				case MOUSE_RIGHT_BUTTON_CLICK://按下右键，同左键一样要判断是否合法
				case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
					//鼠标左键：合法就返回，非法不返回,并且继续循环。非法的话状态栏打印非法
					if (X <= pCGI->start_x || Y <= pCGI->start_y || X >= pCGI->start_x + pCGI->CFI.bwidth - 1 || Y >= pCGI->start_y + pCGI->CFI.bhigh - 1) {
						//位置非法;
						continue;//继续读
					}//此外,如果框架有分割线，碰到分割线也算非法位置
					else if (pCGI->CFI.separator) {
						if ((X - pCGI->start_x) % (pCGI->CFI.block_width + 2) == 0 || (X - pCGI->start_x) % (pCGI->CFI.block_width + 2) == 1) {
							continue;//继续读
						}
						else if ((Y - pCGI->start_y) % (pCGI->CFI.block_high + 1) == 0) {
							continue;//继续读
						}
					}
					if (pCGI->CFI.separator) {
						MRow = (Y - pCGI->start_y) / (pCGI->CFI.block_high + pCGI->CFI.separator);
						MCol = (X - pCGI->start_x) / (pCGI->CFI.block_width + pCGI->CFI.block_width_ext);
					}
					else {
						//无分割线
						MRow = (Y - pCGI->start_y - 1) / pCGI->CFI.block_high;
						MCol = (X - pCGI->start_x - 2) / pCGI->CFI.block_width;
					}
					//判断是否与之前的位置相同，如果是微小移动，还要继续读，	
					return CCT_MOUSE_EVENT;
					break;
				
				
				case MOUSE_NO_ACTION://别的什么操作
					break;
				default:
					break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
		else if (rett == CCT_KEYBOARD_EVENT) {
			//如果按下键盘上的某键（含双键码按键），则直接返回 CCT_KEYBOARD_EVENT，KeyCode1 / KeyCode2中为对应的键码值
			return rett;//直接返回即可。
		
		}//end of else if(ret == CCT_KEYBOARD_EVENT）



	}
	return 0; //此句可根据需要修改
}
