/* 2052316 ��07 ��t�� */
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
		�˴����Ը�����Ҫ�ľ�̬ȫ�ֱ������������٣����û�У�����̬ȫ��ֻ������/�궨�壨�������ޣ���
   -------------------------------------------------- */


/* --------------------------------------------------
		�˴����Ը�����Ҫ���ڲ��������ߺ���
		1�����������ޣ�����Ϊ gmw_inner_* 
		2����������
		3��������static������ȷ��ֻ�ڱ�Դ�ļ���ʹ��
		
   -------------------------------------------------- */
   
/************************************************************************
�������ƣ�gmw_inner_draw_frame_perline()
�������ܣ���ɻ��߿�ķֲ�����
����������
��������ֵ��
����˵������������������static������ֻ�ڱ��ļ��ڲ�ʹ��
***************************************************************************/
static void gmw_inner_draw_frame_perline(const CONSOLE_GRAPHICS_INFO* const pCGI,int Y,int choice)
{
	//cct_setconsoleborder(pCGI->cols, pCGI->lines);
	//���ڲ���ܣ����ȹ涨��ɫ
	int X = pCGI->start_x;
	cct_gotoxy(X, Y);
	cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
	switch (choice) {
		case 1://��ӡ��һ��
			if (pCGI->draw_frame_with_col_no) {
				//������б�
				cct_gotoxy(X+2, Y - 1);
				int bank = (pCGI->CFI.block_width + pCGI->CFI.block_width_ext) / 2 + 1;
				int bankk = pCGI->CFI.block_width + pCGI->CFI.block_width_ext;
				cct_setcolor(pCGI->area_bgcolor, pCGI->area_fgcolor);
				cout << setw(bank)<<"0";//setw(5) ��ӡ0
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
			cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);//�ָ�Ϊ��Ϸ��ɫ
			cct_gotoxy(X, Y);
			cout << pCGI->CFI.top_left;//"�X"
			Sleep(pCGI->delay_of_draw_frame);
			for (int k = 0; k < pCGI->col_num - 1; k++) {
				for (int i = 0; i < (pCGI->CFI.block_width)/ 2; i++) {
					cout << pCGI->CFI.h_normal;// "�T"
					Sleep(pCGI->delay_of_draw_frame);
				}
				if (pCGI->CFI.separator) {
					cout << pCGI->CFI.h_top_separator;//"�j";
					Sleep(pCGI->delay_of_draw_frame);
				}
				   
			}
			for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
				cout << pCGI->CFI.h_normal;// "�T"
				Sleep(pCGI->delay_of_draw_frame);	
			}
			cout << pCGI->CFI.top_right;//"�[";
			Sleep(pCGI->delay_of_draw_frame);
			break;
		case 2://��ӡ�м���������	
			for (int k = 0; k < pCGI->col_num; k++) {
				if (pCGI->CFI.separator==0&&k==0) {
					cout << pCGI->CFI.v_normal;//"�U";
					Sleep(pCGI->delay_of_draw_frame);
				}
				else if (pCGI->CFI.separator) {
					cout << pCGI->CFI.v_normal;//"�U";
					Sleep(pCGI->delay_of_draw_frame);
				}
				for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
					cout << setw(2) << " ";
				}
			}
			cout << pCGI->CFI.v_normal;//"�U";
			Sleep(pCGI->delay_of_draw_frame);
			break;
		case 3://��ӡ�м���ʮ����
			if (pCGI->CFI.separator) {
				cout << pCGI->CFI.v_left_separator;//cout << "�d";
			}
			/*else
				cout << pCGI->CFI.v_normal;//"�U";*/
			
			Sleep(pCGI->delay_of_draw_frame);
			if (pCGI->CFI.separator) {
				for (int k = 0; k < pCGI->col_num - 1; k++) {
					for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
						cout << pCGI->CFI.h_normal;// "�T"
						Sleep(pCGI->delay_of_draw_frame);
					}
					cout << pCGI->CFI.mid_separator;//cout << "�p";
					Sleep(pCGI->delay_of_draw_frame);
				}
				for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
					cout << pCGI->CFI.h_normal;// "�T"
					Sleep(pCGI->delay_of_draw_frame);
				}
				cout << pCGI->CFI.v_right_separator;//cout << "�g";
				Sleep(pCGI->delay_of_draw_frame);
			}
			/*else {
				int length = pCGI->CFI.block_width * pCGI->col_num + 1;
				cout << setw(length) << " ";
				cout << pCGI->CFI.v_normal;//"�U";
			}*/
			break;
		case 4://��ӡ���һ��
			cout << pCGI->CFI.lower_left;//cout << "�^";
			Sleep(pCGI->delay_of_draw_frame);
			for (int k = 0; k < pCGI->col_num - 1; k++) {
				for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
					cout << pCGI->CFI.h_normal;// "�T"
					Sleep(pCGI->delay_of_draw_frame);
				}
				if (pCGI->CFI.separator) {
					cout << pCGI->CFI.h_lower_separator;//cout << "�m";
					Sleep(pCGI->delay_of_draw_frame);
				}

			}
			for (int i = 0; i < (pCGI->CFI.block_width) / 2; i++) {
				cout << pCGI->CFI.h_normal;// "�T"
				Sleep(pCGI->delay_of_draw_frame);
			}
			cout << pCGI->CFI.lower_right;//cout << "�a";
			Sleep(pCGI->delay_of_draw_frame);
			break;


	}

}


/* ----------------------------------------------- 
		ʵ����������ĺ���������������׼����
   ----------------------------------------------- */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�������Ϸ����ܵ�������
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const int row						������(������Ϊ0���������ޣ���Ϊ��֤��ȷ��)
			const int col						������(������Ϊ0���������ޣ���Ϊ��֤��ȷ��)
  �� �� ֵ��
  ˵    ����1��ָ��������Ϸ�ľ������������ֵ
            2�����еı仯�ᵼ��CONSOLE_GRAPHICS_INFO�ṹ����������Աֵ�ı仯��Ҫ����
***************************************************************************/
int gmw_set_rowcol(CONSOLE_GRAPHICS_INFO *const pCGI, const int row, const int col)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	pCGI->col_num = col;
	pCGI->row_num = row;
	//���еı仯�ᵼ��cmd���ڱ仯��lines��cols��ÿ��ÿ�п�ȱ仯��bwidth��bhigh
	
	pCGI->CFI.bwidth = pCGI->CFI.block_width * pCGI->col_num + pCGI->CFI.block_width_ext * (pCGI->col_num -1)+4;
	pCGI->CFI.bhigh = pCGI->CFI.block_high * pCGI->row_num + pCGI->CFI.block_high_ext * (pCGI->row_num -1)+2;
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	pCGI->SLI.lower_start_y = pCGI->start_y + pCGI->CFI.bhigh;
	return 0; //�˾�ɸ�����Ҫ�޸�
}
//����б߿�������x1=pCGI->start_x+(pCGI->col_num-1)*
/***************************************************************************
  �������ƣ�
  ��    �ܣ������������ڣ�����Ϸ�������������ڵ�����cmd���ڣ�����ɫ
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   const int bg_color					��ǰ��ɫ��ȱʡCOLOR_BLACK��
		   const int fg_color					������ɫ��ȱʡCOLOR_WHITE��
		   const bool cascade					���Ƿ�����ȱʡΪtrue-������
  �� �� ֵ��
  ˵    ����1��cascade = trueʱ
				ͬ���޸���Ϸ���������ɫ
				ͬ���޸�����״̬���������ı��ı���ɫ��ǰ��ɫ����Ŀ�ı��ı���ɫ��ǰ��ɫ���䣩
			2���������ɫֵ���󼰳�ͻ����Ҫ��Ϊ��֤
				������ɫ��0-15
				    ǰ��ɫ����ɫ��ֵһ�µ����޷���������
					ǰ��ɫ������״̬����Ŀǰ��ɫ�������޷�������Ŀ��ʾ
					...
***************************************************************************/
int gmw_set_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int bgcolor, const int fgcolor, const bool cascade)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
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
	
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ô��ڵ�����
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   const char *fontname					���������ƣ�ֻ����"Terminal"��"������"���֣������򷵻�-1�����ı����壩
		   const int fs_high					������߶ȣ�ȱʡ������Ϊ16�������������ƣ���Ϊ��֤��
		   const int fs_width					������߶ȣ�ȱʡ������Ϊ8�������������ƣ���Ϊ��֤��
  �� �� ֵ��
  ˵    ����1����cmd_console_tools�е�setfontsize���ƣ�Ŀǰֻ֧�֡��������塱�͡������塱
            2������������������ֱ�ӷ��أ�����ԭ�������ò���
***************************************************************************/
int gmw_set_font(CONSOLE_GRAPHICS_INFO *const pCGI, const char *fontname, const int fs_high, const int fs_width)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//strcmp����0˵�����
	if (int(strcmp(fontname, "������") )!=0 && int(strcmp(fontname, "Terminal") )!= 0) {
		return -1;
	}
	strcpy(pCGI->CFT.font_type,fontname);
	pCGI->CFT.font_size_high = fs_high;
	pCGI->CFT.font_size_width = fs_width;
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʱ
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   const int type						����ʱ�����ͣ�ĿǰΪ3�֣�
		   const int delay_ms					����msΪ��λ����ʱ
			   ���߿����ʱ��0 ~ �������ޣ���Ϊ��֤��ȷ��<0����0��
			   ��ɫ�����ʱ��0 ~ �������ޣ���Ϊ��֤��ȷ��<0����0��
			   ɫ���ƶ�����ʱ��BLOCK_MOVED_DELAY_MS ~ �������ޣ���Ϊ��֤��ȷ�� <BLOCK_MOVED_DELAY_MS ���� BLOCK_MOVED_DELAY_MS��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int gmw_set_delay(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const int delay_ms)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
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
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ���������������Ϸ����ܽṹ֮����Ҫ�����Ķ�������
  ��    �ܣ�CONSOLE_GRAPHICS_INFO *const pCGI	��
		   const int up_lines					���ϲ�������У�ȱʡ������Ϊ0���������ޣ���Ϊ��֤��
		   const int down_lines				���²�������У�ȱʡ������Ϊ0���������ޣ���Ϊ��֤��
		   const int left_cols					����߶�����У�ȱʡ������Ϊ0���������ޣ���Ϊ��֤��
		   const int right_cols				���ұ߶�����У�ȱʡ������Ϊ0���������ޣ���Ϊ��֤��
  �� �� ֵ��
  ˵    �����������еı仯�ᵼ��CONSOLE_GRAPHICS_INFO�ṹ����������Աֵ�ı仯��Ҫ����
***************************************************************************/
int gmw_set_ext_rowcol(CONSOLE_GRAPHICS_INFO *const pCGI, const int up_lines, const int down_lines, const int left_cols, const int right_cols)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//���ȸı�����ֵ
	pCGI->extern_up_lines = up_lines;
	pCGI->extern_down_lines = down_lines;
	pCGI->extern_left_cols = left_cols;
	pCGI->extern_right_cols = right_cols;
	//��ı��ֵ��startx��starty��cmd���ڴ�С
	pCGI->start_x = pCGI->draw_frame_with_row_no * 2 + pCGI->extern_left_cols;
	pCGI->start_y = pCGI->top_status_line + pCGI->draw_frame_with_col_no + pCGI->extern_up_lines;
	
	//cmd���ڼ��㷽ʽ�Ѿ��¶���
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4+pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1+pCGI->extern_right_cols;
	
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���� CONSOLE_FRAME_TYPE �ṹ�е�11�����ͣ�ȱʡ4�֣�
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const int type						��1 - ȫ�� 2 - ȫ���� 3 - ��˫���� 4 - �ᵥ��˫
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int gmw_set_frame_default_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const int type)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	switch (type) {
		case 1://ȫ˫��
			strcpy(pCGI->CFI.top_left, "�X");
			strcpy(pCGI->CFI.lower_left, "�^");
			strcpy(pCGI->CFI.top_right, "�[");
			strcpy(pCGI->CFI.lower_right, "�a");
			strcpy(pCGI->CFI.h_normal, "�T");
			strcpy(pCGI->CFI.v_normal, "�U");
			strcpy(pCGI->CFI.h_top_separator, "�j");
			strcpy(pCGI->CFI.h_lower_separator, "�m");
			strcpy(pCGI->CFI.v_left_separator, "�d");
			strcpy(pCGI->CFI.v_right_separator, "�g");
			strcpy(pCGI->CFI.mid_separator, "�p");
			break;
		case(2)://ȫ����
			strcpy(pCGI->CFI.top_left, "��");//
			strcpy(pCGI->CFI.lower_left, "��");
			strcpy(pCGI->CFI.top_right, "��");
			strcpy(pCGI->CFI.lower_right, "��");
			strcpy(pCGI->CFI.h_normal, "��");
			strcpy(pCGI->CFI.v_normal, "��");//��
			strcpy(pCGI->CFI.h_top_separator, "��");// ��
			strcpy(pCGI->CFI.h_lower_separator, "��");
			strcpy(pCGI->CFI.v_left_separator, "��");
			strcpy(pCGI->CFI.v_right_separator, "��");
			strcpy(pCGI->CFI.mid_separator, "��");
			break;
		case(3)://��˫����
			strcpy(pCGI->CFI.top_left, "�V");
			strcpy(pCGI->CFI.lower_left, "�\");
			strcpy(pCGI->CFI.top_right, "�Y");// �Y
			strcpy(pCGI->CFI.lower_right, "�_");
			strcpy(pCGI->CFI.h_normal, "�T");
			strcpy(pCGI->CFI.v_normal, "��");
			strcpy(pCGI->CFI.h_top_separator, "�h");
			strcpy(pCGI->CFI.h_lower_separator, "�k");
			strcpy(pCGI->CFI.v_left_separator, "�b");
			strcpy(pCGI->CFI.v_right_separator, "�e");
			strcpy(pCGI->CFI.mid_separator, "�n");
			break;
		case(4)://�ᵥ��˫
			strcpy(pCGI->CFI.top_left, "�W");
			strcpy(pCGI->CFI.lower_left, "�]");
			strcpy(pCGI->CFI.top_right, "�Z");// �Y
			strcpy(pCGI->CFI.lower_right, "�`");
			strcpy(pCGI->CFI.h_normal, "��");//��
			strcpy(pCGI->CFI.v_normal, "�U");
			strcpy(pCGI->CFI.h_top_separator, "�i");
			strcpy(pCGI->CFI.h_lower_separator, "�l");
			strcpy(pCGI->CFI.v_left_separator, "�c");//
			strcpy(pCGI->CFI.v_right_separator, "�f");
			strcpy(pCGI->CFI.mid_separator, "�o");
			break;
		default:
			break;
			

	}
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���� CONSOLE_FRAME_TYPE �ṹ�е�11������
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const char *...						����11�֣������.h���˴���
  �� �� ֵ��
  ˵    ����Լ��Ϊһ�������Ʊ��������ʹ���������ݣ���Ϊ��֤2�ֽ�
			1������2�ֽ���ֻȡǰ2�ֽ�
			2�������NULL���������ո����
			3�������1�ֽڣ���һ���ո������˶�������ʾ�ң������
***************************************************************************/
int gmw_set_frame_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const char *top_left, const char *lower_left, const char *top_right,
	const char *lower_right, const char *h_normal, const char *v_normal, const char *h_top_separator,
	const char *h_lower_separator, const char *v_left_separator, const char *v_right_separator, const char *mid_separator)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
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
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���� CONSOLE_FRAME_TYPE �ṹ�е�ɫ��������С���Ƿ���Ҫ�ָ��ߵ�
  ������������������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const int block_width						����ȣ�����ȱʡ2����ΪԼ�������Ϊ�����Ʊ�����������������Ҫ+1��
			const int block_high						���߶ȣ�����ȱʡ1��
			const bool separator						���Ƿ���Ҫ�ָ��ߣ�ȱʡΪtrue����Ҫ�ָ��ߣ�
  �� �� ֵ��
  ˵    ������ܴ�С/�Ƿ���Ҫ�ָ��ߵȵı仯�ᵼ��CONSOLE_GRAPHICS_INFO�ṹ����������Աֵ�ı仯��Ҫ����
***************************************************************************/
int gmw_set_frame_style(CONSOLE_GRAPHICS_INFO *const pCGI, const int block_width, const int block_high, const bool separator)
{
	int block_widths = block_width;
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	/*��Ҫ�����������*/
	if (block_width % 2 == 1) {//����
		block_widths++;
	}
	
	pCGI->CFI.block_width = block_widths;
	pCGI->CFI.block_high = block_high;
	pCGI->CFI.separator = separator;
	//�ָ��ߣ��ָ��߲��ǽ�����ɫ��ķָ��ߣ������ޡ�ɫ��ߺͿ�Ĵ�С�ᵼ��cols��lines��bwidth��bhigh�ı仯��
	pCGI->CFI.block_width_ext = pCGI->CFI.separator * 2;
	pCGI->CFI.block_high_ext = pCGI->CFI.separator;
	pCGI->CFI.bwidth = pCGI->CFI.block_width * pCGI->col_num + pCGI->CFI.block_width_ext * (pCGI->col_num -1)+4;
	pCGI->CFI.bhigh = pCGI->CFI.block_high * pCGI->row_num + pCGI->CFI.block_high_ext * (pCGI->row_num-1)+2;

	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	pCGI->SLI.lower_start_y = pCGI->start_y + pCGI->CFI.bhigh;
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���� CONSOLE_BORDER_TYPE �ṹ�е���ɫ
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const int bg_color					������ɫ��ȱʡ -1��ʾ�ô��ڱ���ɫ��
			const int fg_color					��ǰ��ɫ��ȱʡ -1��ʾ�ô���ǰ��ɫ��
  �� �� ֵ��
  ˵    �����������ɫֵ���󼰳�ͻ����Ҫ��Ϊ��֤
				������ɫ��0-15��ǰ��ɫ����ɫ��ֵһ�µ����޷��������ݵ�
***************************************************************************/
int gmw_set_frame_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int bgcolor, const int fgcolor)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//���ñ��������ɫ
	pCGI->CFI.bgcolor = bgcolor;
	pCGI->CFI.fgcolor = fgcolor;
	//?
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���� CONSOLE_BLOCK_INFO �ṹ�е�6�����ͣ�ȱʡ4�֣�
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const int type						��1 - ȫ˫�� 2 - ȫ���� 3 - ��˫���� 4 - �ᵥ��˫
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int gmw_set_block_default_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const int type)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	switch(type){
		case 1://ȫ˫��
			strcpy(pCGI->CBI.top_left, "�X");
			strcpy(pCGI->CBI.lower_left,"�^");
			strcpy(pCGI->CBI.top_right, "�[");
			strcpy(pCGI->CBI.lower_right, "�a");
			strcpy(pCGI->CBI.h_normal, "�T");
			strcpy(pCGI->CBI.v_normal, "�U");
			break;
		case 2://ȫ����
			strcpy(pCGI->CBI.top_left, "��");
			strcpy(pCGI->CBI.lower_left, "��");
			strcpy(pCGI->CBI.top_right, "��");
			strcpy(pCGI->CBI.lower_right, "��");
			strcpy(pCGI->CBI.h_normal, "��");
			strcpy(pCGI->CBI.v_normal, "��");
			break;
		case 3://��˫����
			strcpy(pCGI->CBI.top_left, "�V");
			strcpy(pCGI->CBI.lower_left, "�\");
			strcpy(pCGI->CBI.top_right, "�Y");
			strcpy(pCGI->CBI.lower_right, "�_");
			strcpy(pCGI->CBI.h_normal, "�T");
			strcpy(pCGI->CBI.v_normal, "��");
			break;
		case 4://�ᵥ��˫
			strcpy(pCGI->CBI.top_left, "�W");
			strcpy(pCGI->CBI.lower_left, "�]");
			strcpy(pCGI->CBI.top_right, "�Z");
			strcpy(pCGI->CBI.lower_right, "�`");
			strcpy(pCGI->CBI.h_normal, "��");
			strcpy(pCGI->CBI.v_normal, "�U");
			break;
		default:
			break;
			
	}
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���� CONSOLE_BLOCK_INFO �ṹ�е�6������
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   const char *...					����6�֣������.h���˴���
  �� �� ֵ��
  ˵    ����Լ��Ϊһ�������Ʊ��������ʹ���������ݣ���Ϊ��֤2�ֽ�
			1������2�ֽ���ֻȡǰ2�ֽ�
			2�������NULL���������ո����
			3�������1�ֽڣ���һ���ո������˶�������ʾ�ң������
***************************************************************************/
int gmw_set_block_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const char *top_left, const char *lower_left, const char *top_right, const char *lower_right, const char *h_normal, const char *v_normal)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//�����null����2���ո��ʾ����ôʵ�֣�����˼��
	strncpy(pCGI->CBI.top_left, top_left,2);
	strncpy(pCGI->CBI.lower_left, lower_left,2);
	strncpy(pCGI->CBI.top_right, top_right,2);
	strncpy(pCGI->CBI.lower_right, lower_right,2);
	strncpy(pCGI->CBI.h_normal,h_normal,2);
	strncpy(pCGI->CBI.v_normal, v_normal,2);
	
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ÿ����Ϸɫ��(����)�Ƿ���ҪС�߿�
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   const bool on_off					��true - ��Ҫ flase - ����Ҫ��ȱʡfalse��
  �� �� ֵ��
  ˵    �����߿�Լ��Ϊ�����Ʊ����˫��
***************************************************************************/
int gmw_set_block_border_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	pCGI->CBI.block_border = on_off;
	
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������Ƿ���ʾ����״̬��
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const int type						��״̬�����ͣ���/�£�
			const bool on_off					��true - ��Ҫ flase - ����Ҫ��ȱʡtrue��
  �� �� ֵ��
  ˵    ����1��״̬�������Լ�����£�
			   1.1����״̬��ֻ��һ�У������������Ϸ�����/�б�����棬Ϊ��������ʼһ�У�����������Ͻ����������״̬�������꣩
			   1.2����״̬��ֻ��һ�У������������·����ߵ�����
			   1.3��״̬���Ŀ��Ϊ�������ȣ������Ϣ������ض�
		   2�����еı仯�ᵼ��CONSOLE_GRAPHICS_INFO�ṹ����������Աֵ�ı仯��Ҫ����
***************************************************************************/
int gmw_set_status_line_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const bool on_off)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	if (on_off == false) {

		//����Ҫ״̬�� ��Ҫ��������״̬��������״̬��
		switch(type) {
			case(TOP_STATUS_LINE)://����Ҫ��״̬��
				pCGI->top_status_line = false;
				break;
			case(LOWER_STATUS_LINE)://����Ҫ��״̬��
				pCGI->lower_status_line = false;
				break;
		}
		
	}
	//��״̬��
	else {
		switch (type) {
			case(TOP_STATUS_LINE)://��Ҫ��״̬��
				pCGI->top_status_line = true;
				break;
			case(LOWER_STATUS_LINE)://��Ҫ��״̬��
				pCGI->lower_status_line = true;
				break;
			default:
				break;
		}
	}
	/*��״̬������Ӱ��starty*/
	pCGI->start_y = pCGI->top_status_line + pCGI->draw_frame_with_col_no + pCGI->extern_up_lines;
	
	/*״̬�������޻�ı�ṹ���������Ա�е�starty��lines*/
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	pCGI->SLI.lower_start_y = pCGI->start_y + pCGI->CFI.bhigh;
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���������״̬������ɫ
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const int type						��״̬�����ͣ���/�£�
			const int normal_bgcolor			�������ı�����ɫ��ȱʡ -1��ʾʹ�ô��ڱ���ɫ��
			const int normal_fgcolor			�������ı�ǰ��ɫ��ȱʡ -1��ʾʹ�ô���ǰ��ɫ��
			const int catchy_bgcolor			����Ŀ�ı�����ɫ��ȱʡ -1��ʾʹ�ô��ڱ���ɫ��
			const int catchy_fgcolor			����Ŀ�ı�ǰ��ɫ��ȱʡ -1��ʾʹ������ɫ��
  ���������
  �� �� ֵ��
  ˵    �����������ɫֵ���󼰳�ͻ����Ҫ��Ϊ��֤
				������ɫ��0-15��ǰ��ɫ����ɫ��ֵһ�µ����޷��������ݵ�
***************************************************************************/
int gmw_set_status_line_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const int normal_bgcolor, const int normal_fgcolor, const int catchy_bgcolor, const int catchy_fgcolor)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	switch (type) {
		case(TOP_STATUS_LINE)://��
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
	
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������Ƿ���ʾ�к�
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const bool on_off					��true - ��ʾ flase - ����ʾ��ȱʡfalse��
  �� �� ֵ��
  ˵    ����1���к�Լ��Ϊ��ĸA��ʼ�������У��������26�����a��ʼ������52��ͳһΪ*��ʵ��Ӧ�ò����ܣ�
            2���Ƿ���ʾ�кŵı仯�ᵼ��CONSOLE_GRAPHICS_INFO�ṹ����������Աֵ�ı仯��Ҫ����
***************************************************************************/
int gmw_set_rowno_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	if (on_off == false) {
		//����ʾ�кš��к�,����startx��y��lines��cols�ı仯
		//������ʾ�кţ�����startx��cols�ı仯
		pCGI->draw_frame_with_row_no = false;

	}
	else
		pCGI->draw_frame_with_row_no = true;

	pCGI->start_x = pCGI->draw_frame_with_row_no * 2 + pCGI->extern_left_cols;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������Ƿ���ʾ�б�
  ���������CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
			const bool on_off					��true - ��ʾ flase - ����ʾ��ȱʡfalse��
  �� �� ֵ��
  ˵    ����1���б�Լ��Ϊ����0��ʼ�������У�����0-99������99ͳһΪ**��ʵ��Ӧ�ò����ܣ�
            2���Ƿ���ʾ�б�ı仯�ᵼ��CONSOLE_GRAPHICS_INFO�ṹ����������Աֵ�ı仯��Ҫ����
***************************************************************************/
int gmw_set_colno_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//������ʾ�кţ�����starty��lines�ı仯
	if (on_off == false) {
		//����ʾ�кţ�
		pCGI->draw_frame_with_col_no = false;
	}
	else
		pCGI->draw_frame_with_col_no = true;
	pCGI->start_y = pCGI->top_status_line + pCGI->draw_frame_with_col_no + pCGI->extern_up_lines;
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->SLI.lower_start_y = pCGI->start_y + pCGI->CFI.bhigh;
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ CONSOLE_GRAPHICS_INFO �ṹ���еĸ���Աֵ
  ���������
  �� �� ֵ��
  ˵    ����1�����������ã���ӡ��ʽ�Զ���
            2������������������δ���ù������Բ�ʵ��
***************************************************************************/
int gmw_print(const CONSOLE_GRAPHICS_INFO *const pCGI)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	cout << pCGI->cols << " ��" << pCGI->lines << "��" << endl;
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��� CONSOLE_GRAPHICS_INFO �ṹ����ȱʡֵ���г�ʼ��
  ���������CONSOLE_GRAPHICS_INFO *const pCGI������ṹָ��
		   const int row					����Ϸ����ɫ��������ȱʡ10��
		   const int col					����Ϸ����ɫ��������ȱʡ10��
		   const int bgcolor				���������ڱ���ɫ��ȱʡ COLOR_BLACK��
		   const int fgcolor				���������ڱ���ɫ��ȱʡ COLOR_WHITE��
  �� �� ֵ��
  ˵    �������ڱ�����/ǰ���ף�����16*8�����������޶������У�����״̬�����У����к�/�б꣬�������Ϊ˫�ߣ�ɫ����2/�߶�1/��С�߿���ɫ��
***************************************************************************/
int gmw_init(CONSOLE_GRAPHICS_INFO *const pCGI, const int row, const int col, const int bgcolor, const int fgcolor)
{
	/* �����ñ�� */
	pCGI->inited = CGI_INITED;
	/*��ͷ�ļ����Ѿ���������ȱʡֵ*/
	gmw_set_color(pCGI);
	gmw_set_ext_rowcol(pCGI);//ȱʡԤ������0
	gmw_set_rowcol(pCGI, row, col);
	//����ʾ�кţ�����ʾ�б�
	gmw_set_rowno_switch(pCGI,false);
	gmw_set_colno_switch(pCGI, false);
	//���߿�ɫ��ʱ����ʱ��ɫ���ƶ�ʱ��ʱ3ms
	gmw_set_delay(pCGI, DELAY_OF_DRAW_FRAME, 0);
	gmw_set_delay(pCGI, DELAY_OF_DRAW_BLOCK, 0);
	gmw_set_delay(pCGI, DELAY_OF_BLOCK_MOVED, 3);
	/*��״̬�����������ı���ɫͬ���ڣ���Ŀ�ı�����ͬ���ڣ�ǰ��Ϊ����
		��״̬�����������ı���ɫͬ���ڣ���Ŀ�ı�����ͬ���ڣ�ǰ��Ϊ����*/
	gmw_set_status_line_switch(pCGI, TOP_STATUS_LINE);
	gmw_set_status_line_switch(pCGI, LOWER_STATUS_LINE); 
	gmw_set_status_line_color(pCGI, TOP_STATUS_LINE,-1,-1,-1,COLOR_HYELLOW);
	gmw_set_status_line_color(pCGI, LOWER_STATUS_LINE ,- 1, -1,-1, COLOR_HYELLOW);
	//���ÿ����ʼλ������
	pCGI->start_x = pCGI->draw_frame_with_row_no * 2+pCGI->extern_left_cols;
	pCGI->start_y = pCGI->top_status_line + pCGI->draw_frame_with_col_no+ pCGI->extern_up_lines;
	pCGI->SLI.lower_start_y=pCGI->start_y + pCGI->CFI.bhigh;
	//�����ʼ���߿��11�ַָ���
	gmw_set_frame_linetype(pCGI);
	gmw_set_frame_default_linetype(pCGI, 1);
	
	//Ȼ��ɫ���2��1��Ҫ�ָ���
	gmw_set_frame_style(pCGI);
	//�ݲ�����
	//����ҪС�߿�
	gmw_set_block_border_switch(pCGI);
	gmw_set_block_default_linetype(pCGI, 1);//Ĭ��ɫ��ȱʡΪ˫�߱߿�
	//�������塢�ֺ���Ϣ
	gmw_set_font(pCGI);
	
	//��ʼ��cmd�����µ�line��column��С
	//�϶���ռ�+��״̬��+�б���ʾ+������+��״̬����+ 4��1�������뷨��ʾ��+3Ԥ�����У�
	pCGI->lines = pCGI->start_y + pCGI->CFI.bhigh + pCGI->lower_status_line + 4 + pCGI->extern_down_lines;
	pCGI->cols = pCGI->start_x + pCGI->CFI.bwidth + 1 + pCGI->extern_right_cols;
	pCGI->SLI.lower_catchy_fgcolor = COLOR_HYELLOW;
	cct_setcolor();
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������Ϸ���
  ���������const CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
  �� �� ֵ��
  ˵    ��������ɲο�demo��Ч��
***************************************************************************/
int gmw_draw_frame(const CONSOLE_GRAPHICS_INFO *const pCGI)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	/*����ʼ���*/
	//���Ƚ�����������Ϊ��涨��С��ƥ��Ĵ�С������ǰ�����ں�
	cct_setfontsize(pCGI->CFT.font_type, pCGI->CFT.font_size_high, pCGI->CFT.font_size_width);
	cct_setconsoleborder(pCGI->cols,pCGI->lines);
	
	
	//�����Ƿ������޸���������������״̬��
	cct_setcolor(pCGI->area_bgcolor, pCGI->area_fgcolor);
	cct_cls();
	/*cct_gotoxy(0, 0);
	//���Ƚ�������Ϸ�����ɹ涨��ɫ
	for (int i = 0; i <pCGI->lines; i++) {
		for (int j = 0; j <pCGI->cols; j++) {
			cout << ' ';
		}
		cout<<endl;
	}
	for (int j = 0; j < pCGI->cols; j++) {
		cout << ' ';
	}
	//����һ�У�*/
	int Y = pCGI->start_y;
	int X = pCGI->start_x;
	
	gmw_inner_draw_frame_perline(pCGI, Y, 1);
	Y++;
	for (int j = 0; j < pCGI->row_num - 1; j++) {
		for (int i = 0; i < pCGI->CFI.block_high; i++) {
			//if()Ҫ�жϲ��Ҵ�ӡ�б�
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
	//��ӡ�б�����Ҫ������
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
	
	
	
	

	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���״̬������ʾ��Ϣ
  ���������const CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   const int type							��ָ������/��״̬��
		   const char *msg						��������Ϣ
		   const char *catchy_msg					����Ҫ�ر��ע����Ϣ����������Ϣǰ��ʾ��
  �� �� ֵ��
  ˵    ����1���������޶�Ϊ����ܵĿ�ȣ����к��б�λ�ã����������ȥ
            2��������һ���ַ���ĳ���ֵ�ǰ������ᵼ�º������룬Ҫ����
***************************************************************************/
int gmw_status_line(const CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const char *msg, const char *catchy_msg)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//ǰ���Ǹ�״̬���ǿ����ģ��Ŵ�ӡ������ֱ�ӷ���
	
	switch (type) {
		case TOP_STATUS_LINE://��״̬����
			if (pCGI->top_status_line == 0)
				return -1;//����Ҫ
			cct_gotoxy(pCGI->start_x, pCGI->start_y-1-pCGI->draw_frame_with_col_no);
			if (catchy_msg != NULL) {
				cct_setcolor(pCGI->SLI.top_catchy_bgcolor, pCGI->SLI.top_catchy_fgcolor);
				cout << catchy_msg;
			}
			cct_setcolor(pCGI->SLI.top_normal_bgcolor, pCGI->SLI.top_normal_fgcolor);
			
			cout << msg;
			break;
		case LOWER_STATUS_LINE://��״̬��
			if (pCGI->lower_status_line == 0)
				return -1;//����Ҫ
			cct_gotoxy(pCGI->start_x, pCGI->start_y+pCGI->CFI.bhigh);
			if (catchy_msg != NULL) {
				cct_setcolor(pCGI->SLI.lower_catchy_bgcolor, pCGI->SLI.lower_catchy_fgcolor);
				cout << catchy_msg;
			}
			cct_setcolor(pCGI->SLI.lower_normal_bgcolor, pCGI->SLI.lower_normal_fgcolor);
			cout << msg<<endl;
			break;

	}
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾĳһ��ɫ��(����Ϊ�ַ���������Ϊrow/col)
  ���������const CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   const int row_no						���кţ���0��ʼ����Ϊ��֤��ȷ�ԣ����򲻼�飩
		   const int col_no						���кţ���0��ʼ����Ϊ��֤��ȷ�ԣ����򲻼�飩
		   const int bdi_value						����Ҫ��ʾ��ֵ
		   const BLOCK_DISPLAY_INFO *const bdi		����Ÿ�ֵ��Ӧ����ʾ��Ϣ�Ľṹ������
  �� �� ֵ��
  ˵    ����1��BLOCK_DISPLAY_INFO �ĺ����ͷ�ļ����÷��ο���������
            2��bdi_valueΪ BDI_VALUE_BLANK ��ʾ�հ׿飬Ҫ���⴦��
***************************************************************************/
int gmw_draw_block(const CONSOLE_GRAPHICS_INFO *const pCGI, const int row_no, const int col_no, const int bdi_value, const BLOCK_DISPLAY_INFO *const bdi)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	//����ִ��һ�Σ���һ��ɫ��
	//���Ƚ�����ƶ���ָ��λ�ã�XΪ��ɫ�����ʼ���꣬���㹫ʽΪ�����ʼ����+����*ɫ������ܿ��
	int X = pCGI->start_x + 2 + col_no * (pCGI->CFI.block_width + pCGI->CFI.block_width_ext);
	int Y = pCGI->start_y + 1 +row_no* (pCGI->CFI.block_high + pCGI->CFI.block_high_ext);
	int hangle = pCGI->CFI.block_width - 4;//��ȥ��ɫ������߿���ֵ
	int nomber = 0;
	cct_gotoxy(X, Y);
	//�������ɫΪʲô����䣿
	//���ȸ��ݴ����ֵ�������ṹ�����飬�ҵ���ͬ��ֵ��ȷ��������ǰ��ɫ
	for (nomber = 0; bdi[nomber].value != BDI_VALUE_END; nomber++) {
		if (bdi[nomber].value == bdi_value) {
			cct_setcolor(bdi[nomber].bgcolor, bdi[nomber].fgcolor);
			break;
		}
	}//�˳�ѭ���󣬵õ���nomber�����ǽṹ�����Եı�
	//cct_setcolor(bdi[bdi_value].bgcolor, bdi[bdi_value].fgcolor);
	//��С�߿��ڵ��߽��г�ʼ����Ĭ��Ϊ˫��
	//���ɫ���б߿���Ҫ�ȴ�ӡ�߿�
	if (bdi_value == BDI_VALUE_BLANK) {//0����ʾ���ÿո���伴��
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
		//�������������ֵ
		return 0;
	}
	else{//���ֵ��Ϊ0�Ļ�
		    //�ǲ���Ҫ���ð�ɫ�ѱ���ɫȥ��
		    
		if (pCGI->CBI.block_border) {//��Ҫ�߿�
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
				//ֱ����ʾ����
					cout << setw(hangle) << bdi_value;

				}
				else {//��ӡͼ��
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
				//��ӡ���һ��
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
			else {//��Ϊ2���б߿�
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
		else//ɫ������û�б߿�
		{//��ֱ����ʾɫ�����״
			if (bdi_value == BDI_VALUE_BLANK) {
				//������ڲ�ֵ��0��ֱ���ÿո����
				cout << setw(2) << " ";
			}
			else if (bdi[nomber].content == NULL) {//!
				//ֱ����ʾ����
				cout << setw(pCGI->CFI.block_width) << bdi_value;
			}
			else {//��ӡͼ��
				cout << setw(pCGI->CFI.block_width)<< bdi[nomber].content;
			}
			//Ȼ���ٿ���Χ�Ƿ��ж���Ŀհ�
			//cct_setcolor(pCGI->CFI.bgcolor, pCGI->CFI.fgcolor);
			//int noborder_leftw = pCGI->CFI.block_width - 2;
			int noborder_lefth = pCGI->CFI.block_high - 1;//ʣ��ռ�Ϊ���-2���߶�-1��
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
	//����״̬��+2
	cct_gotoxy(pCGI->start_x, pCGI->start_y + pCGI->CFI.bhigh+1);
	cct_setcolor();
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ƶ�ĳһ��ɫ��
  ���������const CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   const int row_no						���кţ���0��ʼ����Ϊ��֤��ȷ�ԣ����򲻼�飩
		   const int col_no						���кţ���0��ʼ����Ϊ��֤��ȷ�ԣ����򲻼�飩
		   const int bdi_value						����Ҫ��ʾ��ֵ
		   const int blank_bdi_value				���ƶ����������ڶ���Ч����ʾʱ���ڱ�ʾ�հ׵�ֵ��һ��Ϊ0���˴���Ϊ�������룬�ǿ��ǵ����ܳ��ֵ����������
		   const BLOCK_DISPLAY_INFO *const bdi		�������ʾֵ/�հ�ֵ��Ӧ����ʾ��Ϣ�Ľṹ������
		   const int direction						���ƶ�����һ�����֣������cmd_gmw_tools.h
		   const int distance						���ƶ����루��1��ʼ����Ϊ��֤��ȷ�ԣ����򲻼�飩
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int gmw_move_block(const CONSOLE_GRAPHICS_INFO *const pCGI, const int row_no, const int col_no, const int bdi_value, const int blank_bdi_value, const BLOCK_DISPLAY_INFO *const bdi, const int direction, const int distance)
{
	/*�ƶ�������ֵ��DOWN_TO_UP		0
                    UP_TO_DOWN		1
                    RIGHT_TO_LEFT	2
                    LEFT_TO_RIGHT	3*/
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	int X_drawblock= pCGI->start_x + 2 + col_no * (pCGI->CFI.block_width + pCGI->CFI.block_width_ext);
	int Y_drawblock = pCGI->start_y +1 + row_no * (pCGI->CFI.block_high + pCGI->CFI.block_high_ext);
	int i=0;
	cct_setcolor(bdi[bdi_value].bgcolor, bdi[bdi_value].fgcolor);//��ɫ���ã�
	/*����ɫ���ƶ�����ʱ��Ҫչʾ��ʱ��*/
	switch (direction) {
		case DOWN_TO_UP://�����ƶ�ɫ��
			//��Ҫ�ֿ�����ޱ߿���ֿ���ͬ����
			for (i = 1; i <= distance; i++) {
				gmw_draw_block(pCGI, row_no - i, col_no, bdi_value, bdi);
				//Sleep(pCGI->delay_of_block_moved);
				//Ȼ�������·���ɫ�飻
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
		case  UP_TO_DOWN://�����ƶ�
			for (i = 1; i <=distance; i++) {
				gmw_draw_block(pCGI, row_no+i, col_no, bdi_value, bdi);
				//Ȼ�������Ϸ���ɫ�飻
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
		case RIGHT_TO_LEFT://�����ƶ�
			for (i = 1; i <=distance; i++) {
				gmw_draw_block(pCGI, row_no, col_no-i, bdi_value, bdi);
				//Sleep(pCGI->delay_of_block_moved);
				//Ȼ�������ҷ���ɫ�飻
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
		case LEFT_TO_RIGHT://���ƶ�
			for (i = 1; i <=distance; i++) {
				gmw_draw_block(pCGI, row_no, col_no+i, bdi_value, bdi);
				//Sleep(pCGI->delay_of_block_moved);
				//Ȼ�������󷽵�ɫ�飻
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
		
	return 0; //�˾�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������̻����
  ���������const CONSOLE_GRAPHICS_INFO *const pCGI	������ṹָ��
		   int &MAction							��������� CCT_MOUSE_EVENT(0)�����ֵ��Ч��Ϊ MOUSE_ONLY_MOVED/MOUSE_LEFT_BUTTON_CLICK/MOUSE_RIGHT_BUTTON_CLICK ����֮һ
		                                               ������� CCT_KEYBOARD_EVENT(1)�����ֵ��Ч
		   int &MRow								��������� CCT_MOUSE_EVENT �� MAction = MOUSE_ONLY_MOVED/MOUSE_LEFT_BUTTON_CLICK�����ֵ��Ч����ʾ���ѡ�����Ϸ������кţ���0��ʼ��
												  ���������ֵ��Ч�����������Чֵ���´��󣬲��Ǳ������Ĵ�!!!��
		   int &MCol								��������� CCT_MOUSE_EVENT �� MAction = MOUSE_ONLY_MOVED/MOUSE_LEFT_BUTTON_CLICK�����ֵ��Ч����ʾ���ѡ�����Ϸ������кţ���0��ʼ��
												  ���������ֵ��Ч�����������Чֵ���´��󣬲��Ǳ������Ĵ�!!!��
		   int &KeyCode1							��������� CCT_KEYBOARD_EVENT�����ֵ��Ч��Ϊ�����ļ��루���˫���룬��Ϊ��һ����
												  ���������ֵ��Ч�����������Чֵ���´��󣬲��Ǳ������Ĵ�!!!��
		   int &KeyCode2							��������� CCT_KEYBOARD_EVENT�����ֵ��Ч��Ϊ�����ļ��루���˫���룬��Ϊ�ڶ���������ǵ����룬��Ϊ0��
												  ���������ֵ��Ч�����������Чֵ���´��󣬲��Ǳ������Ĵ�!!!��
		   const bool update_lower_status_line		������ƶ�ʱ���Ƿ�Ҫ�ڱ���������ʾ"[��ǰ���] *��*��/λ�÷Ƿ�"����Ϣ��true=��ʾ��false=����ʾ��ȱʡΪtrue��
  �� �� ֵ����������Լ��
		   1�����������ƶ����õ���MRow/MCol�봫�����ͬ(���ָ��΢С���ƶ�)���򲻷��أ�������
							  �õ����зǷ�λ�ã��򲻷��أ����� update_lower_status_line ����������״̬����ʾ"[��ǰ���] λ�÷Ƿ�"
							  �õ���MRow/MCol�봫��Ĳ�ͬ(��������һ���仯)������ update_lower_status_line ����������״̬����ʾ"[��ǰ���] *��*��"���ٷ���MOUSE_ONLY_MOVED����Щ��Ϸ���غ�Ҫ����ɫ��Ĳ�ͬ��ɫ��ʾ��
		   2������ǰ������������ҵ�ǰ���ָ��ͣ��������Ϸ�����*��*���ϣ��򷵻� CCT_MOUSE_EVENT ��MAction Ϊ MOUSE_LEFT_BUTTON_CLICK, MRow Ϊ�кţ�MCol Ϊ�б�
		                          �ҵ�ǰ���ָ��ͣ���ڷǷ����򣨷���Ϸ������Ϸ�����еķָ��ߣ����򲻷��أ����� update_lower_status_line ����������״̬����ʾ"[��ǰ���] λ�÷Ƿ�"
		   3������ǰ�������Ҽ������ж����ָ��ͣ�������Ƿ�Ϸ���ֱ�ӷ��� CCT_MOUSE_EVENT ��MAction Ϊ MOUSE_LEFT_BUTTON_CLICK, MRow��MCol������
		   4��������¼����ϵ�ĳ������˫���밴��������ֱ�ӷ��� CCT_KEYBOARD_EVENT��KeyCode1/KeyCode2��Ϊ��Ӧ�ļ���ֵ
 ˵    ����ͨ������ cmd_console_tools.cpp �е� read_keyboard_and_mouse ����ʵ��
***************************************************************************/
int gmw_read_keyboard_and_mouse(const CONSOLE_GRAPHICS_INFO *const pCGI, int &MAction, int &MRow, int &MCol, int &KeyCode1, int &KeyCode2, const bool update_lower_status_line)
{
	/* ��ֹ��δ���� gmw_init ǰ������������ */
	if (pCGI->inited != CGI_INITED)
		return -1;
	cct_enable_mouse();//����������
	cct_setcursor(CURSOR_INVISIBLE);//�رչ��
	int X = 0, Y = 0;//��ȡ����������
	int rett;//retΪcct��꺯������ֵ
	int loop = 1;
	int old_rrow=-1,old_rcol=-1;//��¼��һ��������������
	char tempd[256] = " ";
	int flag = 0;
	
	while (loop) {
		old_rrow = MRow;
		old_rcol = MCol;//��һ��ѭ����ʼ����-1
		//ѭ�����˳����������ƶ���ʱ�򣺵õ������ж���֮ǰ����ͬ /����λ�÷Ƿ���״̬����ʾλ�÷Ƿ����������
		//����ƶ��᷵�ص�������õ�����������һ���仯���Ҷ��Ϸ���״̬����ӡ�󷵻�MOVED
		//���������Ϸ��ͷ��أ��Ƿ������ء��Ƿ��Ļ�״̬����ӡ�Ƿ�
		//����Ҽ������ж����кϷ��ԣ�ֱ�ӷ���
		//���̼�����˫���밴����ֱ�ӷ��ؽ���
		rett = cct_read_keyboard_and_mouse(X, Y, MAction, KeyCode1, KeyCode2);
		//����Ǽ��̲������ȸ��ݶ�ȡ��xyֵ�ж������Ƿ�Ϸ�
		//����cct������ģ����������
		if (rett == CCT_MOUSE_EVENT) {
			switch (MAction) {
				
				case MOUSE_ONLY_MOVED://�ƶ�
					//Ҫ�����ƶ���xy�������ȡ�����У�
					//��Ҫ���еļ��㹫ʽ
					//���ݺϷ�λ�ö�ȡ������ڵ�����
						//MRow��Y������� ��0--line-1
					
					if (X <= (pCGI->start_x+1) || Y <= pCGI->start_y || X >= (pCGI->start_x-1) + pCGI->CFI.bwidth - 1 || Y >= pCGI->start_y + pCGI->CFI.bhigh - 1) {
						//״̬��Ҫ��ʾλ�÷Ƿ���
						if (update_lower_status_line) {
							gmw_status_line(pCGI, LOWER_STATUS_LINE, "[��ǰ���] λ�÷Ƿ�            ");
						}
						flag = 1;
						continue;//������
					}//����,�������зָ��ߣ������ָ���Ҳ��Ƿ�λ��
					else if (pCGI->CFI.separator) {
						if ((X-pCGI->start_x)%(pCGI->CFI.block_width+2)==0|| (X - pCGI->start_x) % (pCGI->CFI.block_width + 2)==1) {
							if (update_lower_status_line) {
								gmw_status_line(pCGI, LOWER_STATUS_LINE, "[��ǰ���] λ�÷Ƿ�           ");
							}
							flag = 1;
							continue;//������
						}
						else if ((Y- pCGI->start_y) % (pCGI->CFI.block_high +1) == 0 ) {
							if (update_lower_status_line) {
								gmw_status_line(pCGI, LOWER_STATUS_LINE, "[��ǰ���] λ�÷Ƿ�           ");
							}
							flag = 1;//flag=1��λ�÷Ƿ����
							continue;//������
						}
					}
					if (pCGI->CFI.separator) {
						MRow = (Y - pCGI->start_y) / (pCGI->CFI.block_high + pCGI->CFI.separator);
						MCol = (X - pCGI->start_x) / (pCGI->CFI.block_width + pCGI->CFI.block_width_ext);
					}
					else {
						//�޷ָ���
						MRow = (Y - pCGI->start_y-1) / pCGI->CFI.block_high;
						MCol = (X - pCGI->start_x-2) / pCGI->CFI.block_width;
					}
					//�ж��Ƿ���֮ǰ��λ����ͬ�������΢С�ƶ�����Ҫ��������
					if (MRow == old_rrow && MCol == old_rcol&&flag==0) {
						continue;
					}
					else {//������һ���仯
						if (update_lower_status_line) {
							sprintf(tempd, "[��ǰ���] %c��%d��          ", char('A' + MRow), MCol); //δ����mrow����26��mcol����99�������������Ҫ�������д���
							gmw_status_line(pCGI, LOWER_STATUS_LINE, tempd);
						}
						return CCT_MOUSE_EVENT;
					}
				
					break;
					//
				case MOUSE_RIGHT_BUTTON_CLICK://�����Ҽ���ͬ���һ��Ҫ�ж��Ƿ�Ϸ�
				case MOUSE_LEFT_BUTTON_CLICK:			//�������
					//���������Ϸ��ͷ��أ��Ƿ�������,���Ҽ���ѭ�����Ƿ��Ļ�״̬����ӡ�Ƿ�
					if (X <= pCGI->start_x || Y <= pCGI->start_y || X >= pCGI->start_x + pCGI->CFI.bwidth - 1 || Y >= pCGI->start_y + pCGI->CFI.bhigh - 1) {
						//λ�÷Ƿ�;
						continue;//������
					}//����,�������зָ��ߣ������ָ���Ҳ��Ƿ�λ��
					else if (pCGI->CFI.separator) {
						if ((X - pCGI->start_x) % (pCGI->CFI.block_width + 2) == 0 || (X - pCGI->start_x) % (pCGI->CFI.block_width + 2) == 1) {
							continue;//������
						}
						else if ((Y - pCGI->start_y) % (pCGI->CFI.block_high + 1) == 0) {
							continue;//������
						}
					}
					if (pCGI->CFI.separator) {
						MRow = (Y - pCGI->start_y) / (pCGI->CFI.block_high + pCGI->CFI.separator);
						MCol = (X - pCGI->start_x) / (pCGI->CFI.block_width + pCGI->CFI.block_width_ext);
					}
					else {
						//�޷ָ���
						MRow = (Y - pCGI->start_y - 1) / pCGI->CFI.block_high;
						MCol = (X - pCGI->start_x - 2) / pCGI->CFI.block_width;
					}
					//�ж��Ƿ���֮ǰ��λ����ͬ�������΢С�ƶ�����Ҫ��������	
					return CCT_MOUSE_EVENT;
					break;
				
				
				case MOUSE_NO_ACTION://���ʲô����
					break;
				default:
					break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
		else if (rett == CCT_KEYBOARD_EVENT) {
			//������¼����ϵ�ĳ������˫���밴��������ֱ�ӷ��� CCT_KEYBOARD_EVENT��KeyCode1 / KeyCode2��Ϊ��Ӧ�ļ���ֵ
			return rett;//ֱ�ӷ��ؼ��ɡ�
		
		}//end of else if(ret == CCT_KEYBOARD_EVENT��



	}
	return 0; //�˾�ɸ�����Ҫ�޸�
}
