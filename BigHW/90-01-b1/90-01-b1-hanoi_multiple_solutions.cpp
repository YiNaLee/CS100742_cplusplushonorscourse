/* ��07 2052316 ��t�� */


/* -----------------------------------------

     ���ļ����ܣ�
    1���ű� hanoi_main.cpp/hanoi_menu.cpp �еĸ��������õĲ˵������Ӧ��ִ�к���

     ���ļ�Ҫ��
    1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
    2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
    3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
    4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------- */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b1-hanoi.h"
using namespace std;

static int cnt = 0;//ȫ�ּ򵥱��� ��¼����
static int stacka[10] = { 0 };//����ȫ��һά���飬��¼Բ�������е�Բ�̱��
static int stackb[10] = { 0 };
static int stackc[10] = { 0 };
static int top1 = 0;//����ȫ�ּ򵥱�������¼Բ�������е�Բ�̵�����
static int top2 = 0;
static int top3 = 0;
static int speed = 0;//��̬ȫ�ֱ����ƶ���ʱ*/
/***************************************************************************
     ��������:
     ��    �ܣ�
     ���������
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/

void select(int x, int* n, char* src, char* dst, char* tmp)//һ������������в������������
{
    cout << endl;
    cout << endl;
    while (1)  //�жϲ���n�Ƿ�������ȷ����1-10��
    {
        cout << "�����뺺ŵ���Ĳ���(1-10):\n";
        cin >> *n;
        if (!cin)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        else if (*n < 1 || *n>10)
        {
            cin.ignore(1024, '\n');  //����ÿ�ζ�Ҫ��ջ�����
            continue;
        }
        else if (*n >= 1 && *n <= 10)
        {
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)//������ʼ��
    {
        cout << "��������ʼ��(A-C)��\n";
        cin >> *src;
        if (!cin)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        else if (*src != 'a' && *src != 'b' && *src != 'c' && *src != 'A' && *src != 'B' && *src != 'C')
        {
            cin.ignore(1024, '\n');  //����ÿ�ζ�Ҫ��ջ�����
            continue;
        }

        else
        {
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)//Ŀ����
    {
        cout << "������Ŀ����(A-C)��\n";
        cin >> *dst;
        if (!cin)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        /*A */
        else if (*dst != 'a' && *dst != 'b' && *dst != 'c' && *dst != 'A' && *dst != 'B' && *dst != 'C')
        {
            cin.ignore(1024, '\n');  //����ÿ�ζ�Ҫ��ջ�����
            continue;
        }
        /*else if(src=='a'||src=='b'||src=='c'||src=='A'||src=='B'||src=='C')*/
        else if (*dst == *src)  //�����ʼ����Ŀ������ͬ 
        {
            cout << "Ŀ����(A)��������ʼ��(A)��ͬ\n";
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (*dst >= 97 && *dst <= 99)
                *dst = *dst - 32;//ת��д
            if (*src >= 97 && *src <= 99)
                *src = *src - 32;
            *tmp = 65 + 66 + 67 - *src - *dst;
            cin.ignore(1024, '\n');
            break;
        }

    }
    if (x == 4 || x == 8)
    {
        while (1)
        {
            cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)\n";
            /*�����ƶ��ٶ�*/
            cin >> speed;

            if (!cin)
            {
                cin.clear();
                cin.ignore(65536, '\n');
                continue;
            }
            if (speed >= 0 && speed <= 5)
                break;
        }
    }
    return;


}
/*���ã�����̬ȫ�ֱ������㣬�Է��´γ���*/
void clear_data()
{
    int i;
    cnt = 0;//ȫ�ּ򵥱��� ��¼����
    for (i = 0; i < 10; i++)
    {
        stacka[i] = 0;
        stackb[i] = 0;
        stackc[i] = 0;
    }
    top1 = 0;//����ȫ�ּ򵥱�������¼Բ�������е�Բ�̵�����
    top2 = 0;
    top3 = 0;
    speed = 0;//��̬ȫ�ֱ����ƶ���ʱ*/
}
/***************************************************************************
     ��������:getin_stack()
     ��    �ܣ���ɳ�ʼ�������ݵ���ջ����
     ���������
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void getin_stack(int n, char src)
{
    /*��ʼԪ����ջ��*/
    int i;
    for (i = n; i > 0; i--)
    {
        if (src == 'A')
        {

            stacka[top1++] = i;
        }
        else if (src == 'B')
        {

            stackb[top2++] = i;
        }
        else
        {

            stackc[top3++] = i;
        }
    }
}
/***************************************************************************
     ��������:single_stack()
     ��    �ܣ�ÿһ�ε�Ԫ����ջ��ջ����
     ���������
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void single_stack(char src, char dst)
{
    if (src == 'A' && dst == 'C')   //1
    {
        stackc[top3++] = stacka[--top1];
        stacka[top1] = 0;//���ջ
    }
    else if (src == 'A' && dst == 'B')   //2
    {
        stackb[top2++] = stacka[--top1];
        stacka[top1] = 0;
    }
    else if (src == 'B' && dst == 'A')   //3
    {
        stacka[top1++] = stackb[--top2];
        stackb[top2] = 0;
    }
    else if (src == 'B' && dst == 'C')   //4
    {
        stackc[top3++] = stackb[--top2];
        stackb[top2] = 0;
    }
    else if (src == 'C' && dst == 'A')   //5
    {
        stacka[top1++] = stackc[--top3];
        stackc[top3] = 0;
    }
    else if (src == 'C' && dst == 'B')   //6
    {
        stackb[top2++] = stackc[--top3];
        stackc[top3] = 0;
    }
}
/***************************************************************************
     ��������:sleepspeed
     ��    �ܣ���ʱ�ƶ�
     ���������speed
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void sleepspeed(int speed)
{
    switch (speed)
    {
        case(0):
        {
            while (getchar() != '\n')
            {
                ;
            }
            break;
        }
        case(1)://��ʱ�
        {
            Sleep(500);
            break;
        }
        case(2):
        {
            Sleep(200);
            break;
        }
        case(3):
        {
            Sleep(100);
            break;
        }
        case(4):
        {
            Sleep(50);
            break;
        }
        case(5):
        {
            Sleep(1);
            break;
        }

    }
}

/***************************************************************************
     ��������:firstline
     ��    �ܣ���ӡ4�ĵ�һ�� ����ʼ״̬
     ���������src��n
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void firstline(char src, int n, int x)//��ӡ��ʼ״̬��
{

    int i;
    cout << "��ʼ:  ";
    cout << "A:";
    if (src == 'A')
    {
        for (i = n; i > 0; i--)
        {
            cout << " " << i;
        }
        for (i = 0; i < 20 - 2 * n; i++)
            cout << " ";//mark1
        cout << "B:" << setw(20) << " ";
        cout << "C:" << setw(20) << " " << endl;
    }
    else if (src == 'B')
    {
        cout << setw(20) << " ";//��ӡa�Ŀո�
        cout << "B:";
        for (i = n; i > 0; i--)
        {
            cout << " " << i;
        }
        for (i = 0; i < 20 - 2 * n; i++)
            cout << " ";
        cout << "C:" << setw(20) << " " << endl;
    }
    else
    {
        cout << setw(20) << " ";
        cout << "B:";
        cout << setw(20) << " ";
        cout << "C:";
        for (i = n; i > 0; i--)
        {
            cout << " " << i;
        }
        for (i = 0; i < 20 - 2 * n; i++)
            cout << " ";
        cout << endl;
    }
    if (x != 9)
        sleepspeed(speed);

}
/***************************************************************************
     ��������:primilary_condition
     ��    �ܣ���ʾѡ��4�ĳ�ʼ״̬
     ���������n src
     �� �� ֵ����
     ˵    ����
   ***************************************************************************/

void primilary_condition(int x, int n, char src, char dst)
{
    int i;
    int X, Y;
    if (x != 9)
        cout << "�� " << src << " �ƶ��� " << dst << ",�� " << n << " �㣬��ʱ����Ϊ " << speed;
    if (x == 4)
        cct_gotoxy(0, 17);
    else//x=8
        cct_gotoxy(0, 32);
    firstline(src, n, x);//��ʾ����ĳ�ʼ
    /*��ʾ��ʼ����ջ�����*/
    if (x == 4)
        cct_gotoxy(9, 12);
    else
        cct_gotoxy(9, 27);
    cout << "=========================";
    if (x == 4)
        cct_gotoxy(11, 13);
    else
        cct_gotoxy(11, 28);
    cout << "A         B         C";
    if (src == 'A')
    {
        if (x == 4)
            cct_gotoxy(11, 11);
        else
            cct_gotoxy(11, 26);
        if (x == 4)
            X = 11, Y = 11;
        else
            X = 11, Y = 26;
        for (i = 0; i < top1; i++)
        {
            cct_gotoxy(X, Y);
            cout << stacka[i];
            Y--;
        }
    }
    if (src == 'B')
    {
        if (x == 4)
            cct_gotoxy(21, 11);
        else
            cct_gotoxy(21, 26);
        if (x == 4)
            X = 21, Y = 11;
        else
            X = 21, Y = 26;
        for (i = 0; i < top2; i++)
        {
            cct_gotoxy(X, Y);
            cout << stackb[i];
            Y--;
        }
    }
    if (src == 'C')
    {
        if (x == 4)
            cct_gotoxy(31, 11);
        else
            cct_gotoxy(31, 26);
        if (x == 4)
            X = 31, Y = 11;
        else
            X = 31, Y = 26;
        for (i = 0; i < top3; i++)
        {
            cct_gotoxy(X, Y);
            cout << stackc[i];
            Y--;
        }

    }
    if (x == 4)
        sleepspeed(speed);
}
/***************************************************************************
     ��������:
     ��    �ܣ�״̬4�����Ĵ���
     ���������
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void final_deal(char dst)
{
    const int X = 11, Y = 11;
    if (dst == 'A')
    {
        cct_gotoxy(X + 10, Y);
        cout << "  ";
        cct_gotoxy(X + 20, Y);
        cout << "  ";
    }
    else if (dst == 'B')
    {
        cct_gotoxy(X, Y);
        cout << "  ";
        cct_gotoxy(X + 20, Y);
        cout << "  ";
    }
    else if (dst == 'C')
    {
        cct_gotoxy(X, Y);
        cout << "  ";
        cct_gotoxy(X + 10, Y);
        cout << "  ";
    }
    /*���ص������� �������*/
    cct_gotoxy(0, 20);
}
/***************************************************************************
     ��������:
     ��    �ܣ���̬Ԫ�صı仯
     ���������
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void move_yuansu(int x, char src, char dst)
{


    int X, Y;
    if (x == 4)
        Y = 11;//ջA������һ��Ԫ�ص�����
    else
        Y = 26;

    if (src == 'A' && dst == 'C')   //1
    {

        X = 11;
        cct_gotoxy(X, Y - top1);
        cout << "  ";
        X = 31;
        cct_gotoxy(X, Y - top3 + 1);
        if (top3 > 0)
        {
            cout << stackc[top3 - 1];
        }

    }
    else if (src == 'A' && dst == 'B')   //2
    {
        /*stackb[top2++] = stacka[--top1];*/
        X = 11;
        cct_gotoxy(X, Y - top1);

        cout << "  ";
        X = 21;
        cct_gotoxy(X, Y - top2 + 1);
        if (top2 > 0)
        {
            cout << stackb[top2 - 1];
        }
    }
    else if (src == 'B' && dst == 'A')   //3
    {
        X = 21;
        cct_gotoxy(X, Y - top2);
        cout << "  ";
        X = 11;
        cct_gotoxy(X, Y - top1 + 1);
        if (top1 > 0)
        {
            cout << stacka[top1 - 1];
        }
        /*stacka[top1++] = stackb[--top2];*/

    }
    else if (src == 'B' && dst == 'C')   //4
    {
        /*stackc[top3++] = stackb[--top2];*/
        X = 21;
        cct_gotoxy(X, Y - top2);
        cout << "  ";
        X = 31;
        cct_gotoxy(X, Y - top3 + 1);
        /*cout << stackc[top3 - 1];*/
        if (top3 > 0)
        {
            cout << stackc[top3 - 1];
        }

    }
    else if (src == 'C' && dst == 'A')   //5
    {
        /*stacka[top1++] = stackc[--top3];*/
        X = 31;
        cct_gotoxy(X, Y - top3);
        cout << "  ";
        X = 11;
        cct_gotoxy(X, Y - top1 + 1);
        if (top1 > 0)
        {
            cout << stacka[top1 - 1];
        }
    }
    else if (src == 'C' && dst == 'B')   //6
    {
        /*stackb[top2++] = stackc[--top3];*/
        X = 31;
        cct_gotoxy(X, Y - top3);
        cout << "  ";
        X = 21;
        cct_gotoxy(X, Y - top2 + 1);
        if (top2 > 0)
        {
            cout << stackb[top2 - 1];
        }
    }

}
/***************************************************************************
     ��������:
     ��    �ܣ������ӡʱ���� �����
     ���������
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void perline(int number, char src, char dst)
{
    int i;
    cout << "��" << setw(4) << setiosflags(ios::right) <<
        cnt << " ��" << "(" << setw(2) << number << "#: " << src << "-->" << dst << ")" << "  A:";
    /*if (top1 != 9)
    {
        stacka[top1 + 1] = 0;
    }*/
    for (i = 0; i < top1; i++)
    {
        if (stacka[i] != 0)
            cout << " " << stacka[i];
        else
            cout << "  ";

    }
    for (i = 0; i < 20 - 2 * top1; i++)
    {
        cout << " ";
    }
    cout << "B:";
    if (top2 != 9)
    {
        stackb[top2 + 1] = 0;
    }
    for (i = 0; i < top2; i++)
    {
        if (stackb[i] != 0)
            cout << " " << stackb[i];
        else
            cout << "  ";
    }
    for (i = 0; i < 20 - 2 * top2; i++)
    {
        cout << " ";
    }
    cout << "C:";
    if (top3 != 9)
    {
        stackc[top3 + 1] = 0;
    }
    for (i = 0; i < top3; i++)
    {
        if (stackc[i] != 0)
            cout << " " << stackc[i];
        else
            cout << "  ";
    }
    for (i = 0; i < 20 - 2 * top3; i++)
    {
        cout << " ";
    }
    cout << endl;
}


/*�������3/4/8����һ��������*/
/***************************************************************************
     �������ƣ�landspace_print
     ��    �ܣ�3/4/8�����ӡ
     ���������number src dst
     �� �� ֵ����
     ˵    ����Ƕ����single_stack()������
   ***************************************************************************/
void landspace_print(int number, char src, char dst, int x)
{

    single_stack(src, dst);//Ԫ��ֵ�ĸ��£�����ջ
    switch (x)
    {
        case(3):
            perline(number, src, dst);
            break;
        case(4):
            cct_gotoxy(0, 17);
            perline(number, src, dst);
            break;
        case(8):
            cct_gotoxy(0, 32);
            perline(number, src, dst);
            break;
        case(9):
            cct_gotoxy(0, 32);
            perline(number, src, dst);
            break;
        default:
            break;
    }

}


/***************************************************************************
     ��������:chioce_moveplate 7/8/9 ���ô˺���
     ��    �ܣ�ѡ���ƶ���ʽ ʹ�����ƶ�
     ���������n src dst
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void choice_moveplate(int tmpx, int tmpy, char ch, int bg_color, int fg_color, int LENGTH, int canshu, int MAX_X, int MAX_Y, int MIN_X)//n����Ҫ�ƶ������� �˴�������
{

    int n = (LENGTH - 1) / 2;
    switch (canshu)
    {
        case(1)://�����ƶ�
            for (; tmpy > 0; tmpy--)
            {
                cct_showch(tmpx, tmpy, ch, bg_color, fg_color, LENGTH);//��ӡһ���һ������ 
                if (speed == 5)
                    Sleep(1);
                else if (speed == 4)
                    Sleep(10);
                else if (speed == 3)

                    Sleep(20);
                else if (speed == 2)
                    Sleep(30);
                else if (speed == 1)
                    Sleep(40);
                else
                    Sleep(50);
                if (tmpy > 2) {//�û�ɫ���Բ�� �ú�ɫ���ԭ������ɫ
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, (LENGTH - 1) / 2);
                    cct_showch(tmpx + n, tmpy, ch, COLOR_HYELLOW, COLOR_HYELLOW, 1);//��ɫ����
                    cct_showch(tmpx + n + 1, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, (LENGTH - 1) / 2);
                    /*�����ʾ���һ�α���*/
                }
                else if (tmpy == 2) {
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);//��������ʣ�µ�һ���ո�Ҳ���Իָ�ԭ״
                }
            } /* �ָ�Ϊ��ʼ��ɫ */
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);
            break;
        case(2)://���ƶ�
            for (; tmpy < MAX_Y; tmpy++)
            {
                cct_showch(tmpx, tmpy, ch, bg_color, fg_color, LENGTH);//��ӡһ���һ������
                if (speed == 5)
                    Sleep(1);
                else if (speed == 4)
                    Sleep(10);
                else if (speed == 3)

                    Sleep(20);
                else if (speed == 2)
                    Sleep(30);
                else if (speed == 1)
                    Sleep(40);
                else
                    Sleep(50);
                if (tmpy < 3) {
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
                }
                else if (tmpy < MAX_Y - 1) {
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, (LENGTH - 1) / 2);
                    cct_showch(tmpx + n, tmpy, ch, COLOR_HYELLOW, COLOR_HYELLOW, 1);//��ɫ����
                    cct_showch(tmpx + n + 1, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, (LENGTH - 1) / 2);
                }
            } /* �ָ�Ϊ��ʼ��ɫ */
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);

            break;
        case(3)://�����ƶ�
            for (; tmpx < MAX_X; tmpx++)
            {
                cct_showch(tmpx, tmpy, ch, bg_color, fg_color, LENGTH);//��ӡһ���һ������
                if (speed == 5)
                    Sleep(1);
                else if (speed == 4)
                    Sleep(10);
                else if (speed == 3)

                    Sleep(20);
                else if (speed == 2)
                    Sleep(30);
                else if (speed == 1)
                    Sleep(40);
                else
                    Sleep(50);
                if (tmpx < MAX_X - 1) {
                    /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
                }
            }
            /* �ָ�Ϊ��ʼ��ɫ */
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);

            break;
        case(4)://�����ƶ�
            for (; tmpx > MIN_X; tmpx--)
            {
                cct_showch(tmpx, tmpy, ch, bg_color, fg_color, LENGTH);//��ӡһ���һ������
                if (speed == 5)
                    Sleep(1);
                else if (speed == 4)
                    Sleep(10);
                else if (speed == 3)

                    Sleep(20);
                else if (speed == 2)
                    Sleep(30);
                else if (speed == 1)
                    Sleep(40);
                else
                    Sleep(50);
                if (tmpx > MIN_X - 1) {
                    /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
                }
            }
            /* �ָ�Ϊ��ʼ��ɫ */
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);

            break;


    }


}

/***************************************************************************
     �������ƣ�move_step
     ��    �ܣ�ʵ�ֵ�һ�����ӵ��ƶ�//��Ӧ��7���˵�ѡ��
     ���������n src dst
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void move_step(int n, char src, char dst)
{
    int x, y, tmpx, tmpy;
    const char ch = '*';
    print_nplate(n, src, 0);//��������Ԥ������
    int bg_color, fg_color;
    int LENGTH = 3;

    switch (src)
    {
        case('A')://��ʼ����A
        {
            x = 1, y = 15;

            tmpx = x + 10;
            tmpy = y - n;
            bg_color = 1;//����ɫ�ǹ̶���
            fg_color = 1;
            choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);

            switch (dst)
            {
                case('B'):
                {
                    if (n % 2 == 0) {/*���ƶ���c��*/
                        const int MAX_X = 76;
                        tmpx = 11, tmpy = 1;//A��ͷ������
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);
                        /*Ȼ�������Ƶ�C��*/
                        const int MAX_Y = 15;
                        tmpx = 75; tmpy = 1;
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);

                    }
                    /*���ָ���Ϊ�������ƶ���Ŀ����B*/
                    else {
                        const int MAX_X = 44;
                        tmpx = 11, tmpy = 1;//A��ͷ������
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);
                        /*Ȼ�������Ƶ�B��*/
                        const int MAX_Y = 15;
                        tmpx = 43; tmpy = 1;
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);

                    }
                    break;//�����ʼ����A,Ŀ������B�Ѿ��������
                }
                case('C')://��ʼ����A Ŀ������C
                    if (n % 2 == 0)//���ȵ�B��
                    {
                        const int MAX_X = 44;
                        tmpx = 11, tmpy = 1;//A��ͷ������
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);
                        /*Ȼ�������Ƶ�B��*/
                        const int MAX_Y = 15;
                        tmpx = 43; tmpy = 1;
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);
                    }
                    else {//�ƶ���c��
                        const int MAX_X = 76;
                        tmpx = 11, tmpy = 1;//A��ͷ������
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);
                        /*Ȼ�������Ƶ�C��*/
                        const int MAX_Y = 15;
                        tmpx = 75; tmpy = 1;
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);

                    }
            }
            break;
        }
        /*�ڶ��� ��ʼ����B */
        case('B'):
        {
            x = 33, y = 15;
            tmpx = x + 10;
            tmpy = y - n;
            bg_color = 1;
            fg_color = 1;
            LENGTH = 3;
            /*��һ����b����*/
            choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);
            if (dst == 'A' && n % 2 != 0 || dst == 'C' && n % 2 == 0) {/*���B�ƶ���A*/
                tmpx = 43, tmpy = 1;
                const int MIN_X = 12;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//���ƶ�
                tmpx = 11, tmpy = 1;
                const int MAX_Y = 15;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//����
            }
            else {//��B�ƶ���C
                tmpx = 43, tmpy = 1;
                const int MAX_X = 76;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);//���ƶ�
                tmpx = 75, tmpy = 1;
                const int MAX_Y = 15;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//����
            }
            break;
        }
        case('C'):
        {
            x = 65, y = 15;
            tmpx = x + 10;
            tmpy = y - n;
            bg_color = 1;
            fg_color = 1;
            LENGTH = 3;
            choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//C������
            if (dst == 'A' && n % 2 != 0 || dst == 'B' && n % 2 == 0) {//���C�ƶ���A
                tmpx = 75, tmpy = 1;
                const int MIN_X = 12;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//���ƶ�
                tmpx = 11, tmpy = 1;
                const int MAX_Y = 15;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//����
            }
            else {//��c�ƶ���b
                tmpx = 75, tmpy = 1;
                const int MIN_X = 44;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//���ƶ�
                tmpx = 43, tmpy = 1;
                const int MAX_Y = 15;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//����
            }
            break;
        }
    }


}
/*�����Զ��ƶ� ��Ƕ�׵��������ƶ����� chioce_moveplate*/
void move_plate8(int n, char src, char dst)
{
    int bg_color = n;
    int fg_color = n;
    const char ch = '*';
    //single_stack(src, dst);//ʵ��ֵ�ĳ���ջ�Ĳ��������ӡ���н�ջ���� �����ظ�����

    int X = 11;
    int Y = 14;//ջA������һ��Ԫ�ص�����
    int MAX_X = 0, MAX_Y = 0, MIN_X = 0;
    int LENGTH = 2 * n + 1;
    if (src == 'A' && dst == 'B') {/*1*/
        int tmpy = Y - top1;
        int tmpx = 12 - (LENGTH - 1) / 2;
        // cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//����
        tmpy = 1;
        MAX_X = 44 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);//���ƶ�
        tmpx = 44 - (LENGTH - 1) / 2;
        MAX_Y = Y - top2 + 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//���ƶ� 
    }
    else if (src == 'A' && dst == 'C') {/*2*/
        int tmpx = 12 - (LENGTH - 1) / 2;
        int tmpy = Y - top1;
        // cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//����
        tmpy = 1;
        MAX_X = 76 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);//���ƶ�
        tmpx = 76 - (LENGTH - 1) / 2;
        MAX_Y = Y - top3 + 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//���ƶ� 
    }
    else if (src == 'B' && dst == 'A') {/*3*/
        X = 44;
        int tmpy = Y - top2;
        int tmpx = X - (LENGTH - 1) / 2;
        // cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//����
        tmpy = 1;
        MIN_X = 12 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//���ƶ�
        MAX_Y = Y - top1 + 2;
        tmpx = 12 - (LENGTH - 1) / 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//���ƶ� 
    }
    else if (src == 'B' && dst == 'C') {/*4*/
        X = 44;
        int tmpy = Y - top2;
        int tmpx = X - (LENGTH - 1) / 2;
        // cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//����
        tmpy = 1;
        MAX_X = 76 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);//���ƶ�
        MAX_Y = Y - top3 + 2;
        tmpx = 76 - (LENGTH - 1) / 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//���ƶ� 
    }
    else if (src == 'C' && dst == 'A') {/*5*/
        X = 76;
        int tmpy = Y - top3;
        int tmpx = X - (LENGTH - 1) / 2;
        //cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//����
        tmpy = 1;
        MIN_X = 12 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//���ƶ�
        MAX_Y = Y - top1 + 2;
        tmpx = 12 - (LENGTH - 1) / 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//���ƶ� 

    }
    else if (src == 'C' && dst == 'B') {
        X = 76;
        int tmpy = Y - top3;
        int tmpx = X - (LENGTH - 1) / 2;
        //cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//����
        tmpy = 1;
        MIN_X = 44 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//���ƶ�
        MAX_Y = Y - top2 + 2;
        tmpx = 44 - (LENGTH - 1) / 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//���ƶ� 
    }
    // sleepspeed(speed);
}

/***************************************************************************
     �������ƣ�move
     ��    �ܣ�ʵ��ÿһ������Ĳ���
     ���������
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void move(int number, char src, char dst, int x)
{
    cnt++;

    switch (x)
    {
        case(1):
            cout << setw(2) << number << "# " << src << "---->" << dst << endl;
            break;
        case(2):
            cout << "��" << setw(4) << setiosflags(ios::right) <<
                cnt << " ��" << "(" << setw(2) << number << "#: " << src << "-->" << dst << ")" << endl;
            break;
        case(3):
            landspace_print(number, src, dst, x);
            break;
        case(4):
            landspace_print(number, src, dst, x);
            move_yuansu(x, src, dst);
            sleepspeed(speed);
            break;
        case(8):
            landspace_print(number, src, dst, x);//����ͣ
            move_yuansu(x, src, dst);//�޻س�
            move_plate8(number, src, dst);//�޻س�
            sleepspeed(speed);
            break;
        case(9):
            landspace_print(number, src, dst, x);
            move_yuansu(x, src, dst);
            move_plate8(number, src, dst);
            break;


    }
}

/***************************************************************************
     �������ƣ�hanoi
     ��    �ܣ�ʵ�ֵݹ鹦��
     ���������n src tmp dst
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int x)
{
    if (n == 1)
    {
        move(n, src, dst, x);
    }
    else
    {
        hanoi(n - 1, src, dst, tmp, x);
        move(n, src, dst, x);
        hanoi(n - 1, tmp, src, dst, x);
    }
}
/***************************************************************************
      �������ƣ�chassis_print()
      ��    �ܣ���ӡ�������̺����� 5/6/7/8/9���ô˺���
      �����������
      �� �� ֵ��
      ˵    ����
    ***************************************************************************/
void chassis_print()
{
    const int LENGTH = 23;//���̵ĳ���Ϊ23
    const char ch = '*';
    const int bg_color = COLOR_HYELLOW;//����Ϊ����ɫ
    const int fg_color = COLOR_HYELLOW;//ǰ��Ϊ����ɫ
    const int Y = 15;
    int x = 1;
    cct_showch(x, Y, ch, bg_color, fg_color, LENGTH);
    /*��(1,15)λ��������ӡ23���ַ�*/
    x = 33;
    cct_showch(x, Y, ch, bg_color, fg_color, LENGTH);
    x = 65;
    cct_showch(x, Y, ch, bg_color, fg_color, LENGTH);
    /*Ȼ��������ϴ�ӡ��������*/
    int y = 14;
    x = 12;
    for (y = 14; y > 2; y--)
    {
        cct_showch(x, y, ch, bg_color, fg_color, 1);
        cct_showch(x + 32, y, ch, bg_color, fg_color, 1);
        cct_showch(x + 64, y, ch, bg_color, fg_color, 1);
        Sleep(100);//���������ӳ�Ч��
    }
    /* �ָ�Ϊ��ʼ��ɫ */
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);


}
/***************************************************************************
      �������ƣ�print_singleplate
      ��    �ܣ���ӡ����
      �����������
      �� �� ֵ��
      ˵    ����
    ***************************************************************************/
void print_singleplate(int n, int x, int y)
{
    int i, tmp;
    const char ch = '*';
    int bg_color, fg_color;

    for (i = 0; i < n; i++)
    {
        tmp = x + 11 - n + i;
        y--;
        bg_color = n - i;
        fg_color = n - i;
        cct_showch(tmp, y, ch, bg_color, fg_color, 2 * n + 1 - i * 2);//��n��ֵ������ɫ��ǰ��ɫ
        Sleep(50);
    }
    /* �ָ�Ϊ��ʼ��ɫ */
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/***************************************************************************
      �������ƣ�print_nplate()
      ��    �ܣ���ӡn������ Ԥ�� ���������Ĳ���
      ���������src,n
      �� �� ֵ��
      ˵    ����
    ***************************************************************************/
void print_nplate(int n, char src, int canshu)
{
    int x, y;
    chassis_print();//�ȴ�ӡ��������


    switch (src)
    {
        case('A')://��ʼ����A
        {
            x = 1, y = 15;
            print_singleplate(n, x, y);
            break;
        }
        case('B'):
        {
            x = 33, y = 15;
            print_singleplate(n, x, y);
            break;
        }
        case('C'):
        {
            x = 65, y = 15;
            print_singleplate(n, x, y);
            break;
        }
    }
    if (canshu == 8) {
        sleepspeed(speed);
    }

}
/***************************************************************************
�������ƣ�per_command()
��    �ܣ������������ ��Ϸѡ��
���������
�� �� ֵ��
˵    ����
***************************************************************************/
int  per_command(char qishi, char mubiao)
{
    char src;

    while (1) {
        /*�ָ����*/
        cct_setcursor(CURSOR_VISIBLE_NORMAL);
        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);//���ص���ʼ�ĵط�
        cin >> src;
        if (src == 'Q' || src == 'q') {
            return 0;
        }
        else {
            char dst;
            cin >> dst;
            if (src > 96)/*ת��д*/
                src -= 32;
            if (dst > 96)
                dst -= 32;
            if (src < 'A' || src>'C') {
                cct_gotoxy(0, GAME_note + 1);
                cout << "        ";
                cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                cout << setw(20) << " ";
                continue;
            }
            if (dst < 'A' || dst>'C') {
                cct_gotoxy(0, GAME_note + 1);
                cout << "        ";
                cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                cout << setw(20) << " ";
                continue;
            }

            switch (src)
            {
                case('A'):
                    if (stacka[0] == 0) {
                        cct_gotoxy(0, GAME_note + 1);
                        cout << "Դ��Ϊ�գ�";
                        Sleep(50);
                        cct_gotoxy(0, GAME_note + 1);
                        cout << setw(30) << "        ";
                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                        cout << setw(30) << " ";
                        continue;
                    }
                    else {
                        switch (dst)
                        {
                            case('A'):
                                cct_gotoxy(0, GAME_note + 1);
                                cout << "��ʼ����Ŀ����������ͬ��";
                                Sleep(500);
                                cct_gotoxy(0, GAME_note + 1);
                                cout << setw(30) << "        ";
                                cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                cout << setw(30) << " ";
                                continue;
                                break;
                            case('B'):
                                if (top2 != 0) {
                                    if (stackb[top2 - 1] < stacka[top1 - 1]) {
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << "����ѹС�̣��Ƿ��ƶ���";
                                        Sleep(500);
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << setw(30) << "        ";
                                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                        cout << setw(30) << " ";
                                        continue;
                                    }
                                }
                                break;
                            case('C')://Ϊʲô���ﲻ����
                                if (top3 != 0) {
                                    if (stackc[top3 - 1] < stacka[top1 - 1]) {
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << "����ѹС�̣��Ƿ��ƶ���";
                                        Sleep(500);
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << setw(30) << "        ";
                                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                        cout << setw(30) << " ";
                                        continue;
                                    }

                                }
                                break;
                        }
                    }
                    break;
                case('B'):
                    if (stackb[0] == 0) {
                        cct_gotoxy(0, GAME_note + 1);
                        cout << "Դ��Ϊ�գ�";
                        Sleep(500);
                        cct_gotoxy(0, GAME_note + 1);
                        cout << setw(30) << "        ";
                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                        cout << setw(20) << " ";
                        continue;
                    }
                    else {
                        switch (dst)
                        {
                            case('A'):
                                if (top1 != 0) {
                                    if (stacka[top1 - 1] < stackb[top2 - 1]) {
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << "����ѹС�̣��Ƿ��ƶ���";
                                        Sleep(50);
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << setw(30) << "        ";
                                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                        cout << setw(30) << " ";
                                        continue;
                                    }
                                }
                                break;
                            case('B'):
                                cct_gotoxy(0, GAME_note + 1);
                                cout << "��ʼ����Ŀ����������ͬ��";
                                Sleep(500);
                                cct_gotoxy(0, GAME_note + 1);
                                cout << setw(30) << "        ";
                                cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                cout << setw(30) << " ";
                                continue;
                                break;
                            case('C'):
                                if (top3 != 0) {
                                    if (stackc[top3 - 1] < stackb[top2 - 1]) {
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << "����ѹС�̣��Ƿ��ƶ���";
                                        Sleep(500);
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << setw(30) << "        ";
                                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                        cout << setw(30) << " ";
                                        continue;
                                    }
                                }
                                break;
                        }
                    }
                    break;
                case('C'):
                {
                    if (stackc[0] == 0) {
                        cct_gotoxy(0, GAME_note + 1);
                        cout << "Դ��Ϊ�գ�";
                        Sleep(500);
                        cct_gotoxy(0, GAME_note + 1);
                        cout << setw(30) << "           ";
                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                        cout << setw(30) << " ";
                        continue;
                    }
                    else {
                        switch (dst)
                        {
                            case('A'):
                                if (top1 != 0) {
                                    if (stacka[top1 - 1] < stackc[top3 - 1]) {
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << "����ѹС�̣��Ƿ��ƶ���";
                                        Sleep(500);
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << setw(30) << "        ";
                                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                        cout << setw(30) << " ";
                                        continue;
                                    }
                                }
                                break;
                            case('B'):
                                if (top2 != 0) {
                                    if (stackb[top2 - 1] < stackc[top3 - 1]) {
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << "����ѹС�̣��Ƿ��ƶ���";
                                        Sleep(500);
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << setw(30) << "        ";
                                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                        cout << setw(30) << " ";
                                        continue;
                                    }
                                }
                                break;
                            case('C'):
                                cct_gotoxy(0, GAME_note + 1);
                                cout << "��ʼ����Ŀ����������ͬ��";
                                Sleep(500);
                                cct_gotoxy(0, GAME_note + 1);
                                cout << setw(30) << "        ";
                                cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                cout << setw(30) << " ";
                                continue;
                                break;

                        }

                    }
                    break;
                }
            }
            /*�����Ѿ��õ���ȷ����*/
        /*��Ҫ�õ��ƶ������ӵı��*/
            int number = 0;//�������ӱ��
            int i = 0;
            switch (src)
            {
                case('A'):
                    for (i = 9; i >= 0; i--) {
                        if (stacka[i] != 0) {
                            number = stacka[i];
                            break;
                        }
                    }
                    break;
                case('B'):
                    for (i = 9; i >= 0; i--) {
                        if (stackb[i] != 0)
                        {
                            number = stackb[i];
                            break;
                        }
                    }
                    break;
                case('C'):
                    for (i = 9; i >= 0; i--) {
                        if (stackc[i] != 0)
                        {
                            number = stackc[i];
                            break;
                        }
                    }
                    break;

            }
            cct_setcursor(CURSOR_INVISIBLE);//�رչ��
            move(number, src, dst, 9);
            cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
            cout << setw(30) << " ";
            switch (qishi)
            {
                case('A'):
                    if (top1 == 0) {
                        if (mubiao == 'B' && top3 == 0)
                            return 1;
                        else if (mubiao == 'C' && top2 == 0)
                            return 1;
                    }
                    break;
                case('B'):
                    if (top2 == 0) {
                        if (mubiao == 'A' && top2 == 0)
                            return 1;
                        else if (mubiao == 'C' && top1 == 0)
                            return 1;
                    }
                    break;
                case('C'):
                    if (top3 == 0) {
                        if (mubiao == 'B' && top1 == 0)
                            return 1;
                        else if (mubiao == 'A' && top2 == 0)
                            return 1;
                    }
                    break;
            }
        }

    }
}



/***************************************************************************
      �������ƣ�game_mode(char src)
      ��    �ܣ��˵���ھŸ�ѡ��
      ���������n,src,dst
      �� �� ֵ��
      ˵    ����
    ***************************************************************************/
void game_mode(int n, char src, char dst)/*��Ϸģʽ*/
{
    cct_gotoxy(0, 0);
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
    primilary_condition(9, n, src, dst);//��ʼ����״̬ ��ʼ״̬
    print_nplate(n, src, 0);//��ӡ���̺����� ���˵���6�Ĳ���
   //getin_stack(n, src);//����ʼԪ����ջ main���������Ѿ�ִ�й���仰��


    cct_gotoxy(0, GAME_note);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);//�ָ����
    cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";

    int ret = per_command(src, dst);
    if (ret == 0)
    {
        cct_gotoxy(0, GAME_note + 1);
        cout << "��Ϸ��ֹ������";
    }
    else if (ret == 1)
    {
        cct_gotoxy(0, GAME_note + 1);
        cout << "��ϲ���Ѿ��ɹ��ƽ⺺ŵ����Ϸ����Ϸ����!!!!!";
    }
}