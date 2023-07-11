/* 信07 2052316 李祎娜 */


/* -----------------------------------------

     本文件功能：
    1、放被 hanoi_main.cpp/hanoi_menu.cpp 中的各函数调用的菜单各项对应的执行函数

     本文件要求：
    1、不允许定义外部全局变量（const及#define不在限制范围内）
    2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
    3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    4、按需加入系统头文件、自定义头文件、命名空间等

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

static int cnt = 0;//全局简单变量 记录步数
static int stacka[10] = { 0 };//三个全局一维数组，记录圆柱上现有的圆盘编号
static int stackb[10] = { 0 };
static int stackc[10] = { 0 };
static int top1 = 0;//三个全局简单变量，记录圆柱上现有的圆盘的数量
static int top2 = 0;
static int top3 = 0;
static int speed = 0;//静态全局变量移动延时*/
/***************************************************************************
     函数名称:
     功    能：
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/

void select(int x, int* n, char* src, char* dst, char* tmp)//一个函数完成所有参数的输入操作
{
    cout << endl;
    cout << endl;
    while (1)  //判断层数n是否输入正确且在1-10层
    {
        cout << "请输入汉诺塔的层数(1-10):\n";
        cin >> *n;
        if (!cin)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        else if (*n < 1 || *n>10)
        {
            cin.ignore(1024, '\n');  //做到每次都要清空缓冲区
            continue;
        }
        else if (*n >= 1 && *n <= 10)
        {
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)//输入起始柱
    {
        cout << "请输入起始柱(A-C)：\n";
        cin >> *src;
        if (!cin)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        else if (*src != 'a' && *src != 'b' && *src != 'c' && *src != 'A' && *src != 'B' && *src != 'C')
        {
            cin.ignore(1024, '\n');  //做到每次都要清空缓冲区
            continue;
        }

        else
        {
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)//目标柱
    {
        cout << "请输入目标柱(A-C)：\n";
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
            cin.ignore(1024, '\n');  //做到每次都要清空缓冲区
            continue;
        }
        /*else if(src=='a'||src=='b'||src=='c'||src=='A'||src=='B'||src=='C')*/
        else if (*dst == *src)  //如果起始柱和目标柱相同 
        {
            cout << "目标柱(A)不能与起始柱(A)相同\n";
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (*dst >= 97 && *dst <= 99)
                *dst = *dst - 32;//转大写
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
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)\n";
            /*处理移动速度*/
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
/*作用：将静态全局变量清零，以防下次出错*/
void clear_data()
{
    int i;
    cnt = 0;//全局简单变量 记录步数
    for (i = 0; i < 10; i++)
    {
        stacka[i] = 0;
        stackb[i] = 0;
        stackc[i] = 0;
    }
    top1 = 0;//三个全局简单变量，记录圆柱上现有的圆盘的数量
    top2 = 0;
    top3 = 0;
    speed = 0;//静态全局变量移动延时*/
}
/***************************************************************************
     函数名称:getin_stack()
     功    能：完成初始输入数据的入栈操作
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/
void getin_stack(int n, char src)
{
    /*初始元素入栈：*/
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
     函数名称:single_stack()
     功    能：每一次的元素入栈出栈操作
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/
void single_stack(char src, char dst)
{
    if (src == 'A' && dst == 'C')   //1
    {
        stackc[top3++] = stacka[--top1];
        stacka[top1] = 0;//清空栈
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
     函数名称:sleepspeed
     功    能：延时移动
     输入参数：speed
     返 回 值：
     说    明：
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
        case(1)://延时最长
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
     函数名称:firstline
     功    能：打印4的第一行 （初始状态
     输入参数：src，n
     返 回 值：
     说    明：
   ***************************************************************************/
void firstline(char src, int n, int x)//打印初始状态的
{

    int i;
    cout << "初始:  ";
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
        cout << setw(20) << " ";//打印a的空格
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
     函数名称:primilary_condition
     功    能：显示选项4的初始状态
     输入参数：n src
     返 回 值：无
     说    明：
   ***************************************************************************/

void primilary_condition(int x, int n, char src, char dst)
{
    int i;
    int X, Y;
    if (x != 9)
        cout << "从 " << src << " 移动到 " << dst << ",共 " << n << " 层，延时设置为 " << speed;
    if (x == 4)
        cct_gotoxy(0, 17);
    else//x=8
        cct_gotoxy(0, 32);
    firstline(src, n, x);//显示横向的初始
    /*显示初始三个栈的情况*/
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
     函数名称:
     功    能：状态4的最后的处理
     输入参数：
     返 回 值：
     说    明：
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
    /*光标回到最下面 程序结束*/
    cct_gotoxy(0, 20);
}
/***************************************************************************
     函数名称:
     功    能：动态元素的变化
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/
void move_yuansu(int x, char src, char dst)
{


    int X, Y;
    if (x == 4)
        Y = 11;//栈A最下面一个元素的坐标
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
     函数名称:
     功    能：横向打印时单句 的输出
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/
void perline(int number, char src, char dst)
{
    int i;
    cout << "第" << setw(4) << setiosflags(ios::right) <<
        cnt << " 步" << "(" << setw(2) << number << "#: " << src << "-->" << dst << ")" << "  A:";
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


/*横向输出3/4/8共用一个函数：*/
/***************************************************************************
     函数名称：landspace_print
     功    能：3/4/8横向打印
     输入参数：number src dst
     返 回 值：无
     说    明：嵌套了single_stack()函数和
   ***************************************************************************/
void landspace_print(int number, char src, char dst, int x)
{

    single_stack(src, dst);//元素值的更新，出入栈
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
     函数名称:chioce_moveplate 7/8/9 共用此函数
     功    能：选择移动方式 使盘子移动
     输入参数：n src dst
     返 回 值：
     说    明：
   ***************************************************************************/
void choice_moveplate(int tmpx, int tmpy, char ch, int bg_color, int fg_color, int LENGTH, int canshu, int MAX_X, int MAX_Y, int MIN_X)//n代表要移动的盘子 此处第七题
{

    int n = (LENGTH - 1) / 2;
    switch (canshu)
    {
        case(1)://向上移动
            for (; tmpy > 0; tmpy--)
            {
                cct_showch(tmpx, tmpy, ch, bg_color, fg_color, LENGTH);//打印一遍第一个盘子 
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
                if (tmpy > 2) {//用黄色填充圆柱 用黑色填充原来的颜色
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, (LENGTH - 1) / 2);
                    cct_showch(tmpx + n, tmpy, ch, COLOR_HYELLOW, COLOR_HYELLOW, 1);//黄色柱子
                    cct_showch(tmpx + n + 1, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, (LENGTH - 1) / 2);
                    /*清除显示最后一次保留*/
                }
                else if (tmpy == 2) {
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);//可以消除剩下的一个空格，也可以恢复原状
                }
            } /* 恢复为初始颜色 */
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);
            break;
        case(2)://向移动
            for (; tmpy < MAX_Y; tmpy++)
            {
                cct_showch(tmpx, tmpy, ch, bg_color, fg_color, LENGTH);//打印一遍第一个盘子
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
                    cct_showch(tmpx + n, tmpy, ch, COLOR_HYELLOW, COLOR_HYELLOW, 1);//黄色柱子
                    cct_showch(tmpx + n + 1, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, (LENGTH - 1) / 2);
                }
            } /* 恢复为初始颜色 */
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);

            break;
        case(3)://向右移动
            for (; tmpx < MAX_X; tmpx++)
            {
                cct_showch(tmpx, tmpy, ch, bg_color, fg_color, LENGTH);//打印一遍第一个盘子
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
                    /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
                }
            }
            /* 恢复为初始颜色 */
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);

            break;
        case(4)://向左移动
            for (; tmpx > MIN_X; tmpx--)
            {
                cct_showch(tmpx, tmpy, ch, bg_color, fg_color, LENGTH);//打印一遍第一个盘子
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
                    /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                    cct_showch(tmpx, tmpy, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
                }
            }
            /* 恢复为初始颜色 */
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);

            break;


    }


}

/***************************************************************************
     函数名称：move_step
     功    能：实现第一个盘子的移动//对应第7个菜单选项
     输入参数：n src dst
     返 回 值：
     说    明：
   ***************************************************************************/
void move_step(int n, char src, char dst)
{
    int x, y, tmpx, tmpy;
    const char ch = '*';
    print_nplate(n, src, 0);//第六步的预备工作
    int bg_color, fg_color;
    int LENGTH = 3;

    switch (src)
    {
        case('A')://起始柱是A
        {
            x = 1, y = 15;

            tmpx = x + 10;
            tmpy = y - n;
            bg_color = 1;//背景色是固定的
            fg_color = 1;
            choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);

            switch (dst)
            {
                case('B'):
                {
                    if (n % 2 == 0) {/*则移动到c柱*/
                        const int MAX_X = 76;
                        tmpx = 11, tmpy = 1;//A的头顶坐标
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);
                        /*然后再下移到C柱*/
                        const int MAX_Y = 15;
                        tmpx = 75; tmpy = 1;
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);

                    }
                    /*盘字个数为奇数，移动到目标柱B*/
                    else {
                        const int MAX_X = 44;
                        tmpx = 11, tmpy = 1;//A的头顶坐标
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);
                        /*然后再下移到B柱*/
                        const int MAX_Y = 15;
                        tmpx = 43; tmpy = 1;
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);

                    }
                    break;//如果起始柱是A,目标柱是B已经讨论完成
                }
                case('C')://起始柱是A 目标柱是C
                    if (n % 2 == 0)//则先到B柱
                    {
                        const int MAX_X = 44;
                        tmpx = 11, tmpy = 1;//A的头顶坐标
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);
                        /*然后再下移到B柱*/
                        const int MAX_Y = 15;
                        tmpx = 43; tmpy = 1;
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);
                    }
                    else {//移动到c柱
                        const int MAX_X = 76;
                        tmpx = 11, tmpy = 1;//A的头顶坐标
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);
                        /*然后再下移到C柱*/
                        const int MAX_Y = 15;
                        tmpx = 75; tmpy = 1;
                        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);

                    }
            }
            break;
        }
        /*第二类 初始柱是B */
        case('B'):
        {
            x = 33, y = 15;
            tmpx = x + 10;
            tmpy = y - n;
            bg_color = 1;
            fg_color = 1;
            LENGTH = 3;
            /*第一步把b上移*/
            choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);
            if (dst == 'A' && n % 2 != 0 || dst == 'C' && n % 2 == 0) {/*则从B移动到A*/
                tmpx = 43, tmpy = 1;
                const int MIN_X = 12;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//左移动
                tmpx = 11, tmpy = 1;
                const int MAX_Y = 15;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移
            }
            else {//从B移动到C
                tmpx = 43, tmpy = 1;
                const int MAX_X = 76;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);//右移动
                tmpx = 75, tmpy = 1;
                const int MAX_Y = 15;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移
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
            choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//C柱上移
            if (dst == 'A' && n % 2 != 0 || dst == 'B' && n % 2 == 0) {//则从C移动到A
                tmpx = 75, tmpy = 1;
                const int MIN_X = 12;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//左移动
                tmpx = 11, tmpy = 1;
                const int MAX_Y = 15;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移
            }
            else {//从c移动到b
                tmpx = 75, tmpy = 1;
                const int MIN_X = 44;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//左移动
                tmpx = 43, tmpy = 1;
                const int MAX_Y = 15;
                choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移
            }
            break;
        }
    }


}
/*盘子自动移动 ，嵌套调用盘子移动函数 chioce_moveplate*/
void move_plate8(int n, char src, char dst)
{
    int bg_color = n;
    int fg_color = n;
    const char ch = '*';
    //single_stack(src, dst);//实现值的出入栈的操作横向打印已有进栈操作 无需重复两遍

    int X = 11;
    int Y = 14;//栈A最下面一个元素的坐标
    int MAX_X = 0, MAX_Y = 0, MIN_X = 0;
    int LENGTH = 2 * n + 1;
    if (src == 'A' && dst == 'B') {/*1*/
        int tmpy = Y - top1;
        int tmpx = 12 - (LENGTH - 1) / 2;
        // cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//上移
        tmpy = 1;
        MAX_X = 44 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);//右移动
        tmpx = 44 - (LENGTH - 1) / 2;
        MAX_Y = Y - top2 + 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移动 
    }
    else if (src == 'A' && dst == 'C') {/*2*/
        int tmpx = 12 - (LENGTH - 1) / 2;
        int tmpy = Y - top1;
        // cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//上移
        tmpy = 1;
        MAX_X = 76 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);//右移动
        tmpx = 76 - (LENGTH - 1) / 2;
        MAX_Y = Y - top3 + 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移动 
    }
    else if (src == 'B' && dst == 'A') {/*3*/
        X = 44;
        int tmpy = Y - top2;
        int tmpx = X - (LENGTH - 1) / 2;
        // cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//上移
        tmpy = 1;
        MIN_X = 12 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//左移动
        MAX_Y = Y - top1 + 2;
        tmpx = 12 - (LENGTH - 1) / 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移动 
    }
    else if (src == 'B' && dst == 'C') {/*4*/
        X = 44;
        int tmpy = Y - top2;
        int tmpx = X - (LENGTH - 1) / 2;
        // cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//上移
        tmpy = 1;
        MAX_X = 76 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 3, MAX_X, 0, 0);//右移动
        MAX_Y = Y - top3 + 2;
        tmpx = 76 - (LENGTH - 1) / 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移动 
    }
    else if (src == 'C' && dst == 'A') {/*5*/
        X = 76;
        int tmpy = Y - top3;
        int tmpx = X - (LENGTH - 1) / 2;
        //cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//上移
        tmpy = 1;
        MIN_X = 12 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//左移动
        MAX_Y = Y - top1 + 2;
        tmpx = 12 - (LENGTH - 1) / 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移动 

    }
    else if (src == 'C' && dst == 'B') {
        X = 76;
        int tmpy = Y - top3;
        int tmpx = X - (LENGTH - 1) / 2;
        //cct_gotoxy(tmpx, tmpy);
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 1, 0, 0, 0);//上移
        tmpy = 1;
        MIN_X = 44 - (LENGTH - 1) / 2 + 1;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 4, 0, 0, MIN_X);//左移动
        MAX_Y = Y - top2 + 2;
        tmpx = 44 - (LENGTH - 1) / 2;
        choice_moveplate(tmpx, tmpy, ch, bg_color, fg_color, LENGTH, 2, 0, MAX_Y, 0);//下移动 
    }
    // sleepspeed(speed);
}

/***************************************************************************
     函数名称：move
     功    能：实现每一步具体的操作
     输入参数：
     返 回 值：
     说    明：
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
            cout << "第" << setw(4) << setiosflags(ios::right) <<
                cnt << " 步" << "(" << setw(2) << number << "#: " << src << "-->" << dst << ")" << endl;
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
            landspace_print(number, src, dst, x);//无暂停
            move_yuansu(x, src, dst);//无回车
            move_plate8(number, src, dst);//无回车
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
     函数名称：hanoi
     功    能：实现递归功能
     输入参数：n src tmp dst
     返 回 值：
     说    明：
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
      函数名称：chassis_print()
      功    能：打印三个底盘和柱子 5/6/7/8/9共用此函数
      输入参数：无
      返 回 值：
      说    明：
    ***************************************************************************/
void chassis_print()
{
    const int LENGTH = 23;//底盘的长度为23
    const char ch = '*';
    const int bg_color = COLOR_HYELLOW;//背景为亮黄色
    const int fg_color = COLOR_HYELLOW;//前景为亮黄色
    const int Y = 15;
    int x = 1;
    cct_showch(x, Y, ch, bg_color, fg_color, LENGTH);
    /*在(1,15)位置连续打印23个字符*/
    x = 33;
    cct_showch(x, Y, ch, bg_color, fg_color, LENGTH);
    x = 65;
    cct_showch(x, Y, ch, bg_color, fg_color, LENGTH);
    /*然后从下往上打印三根柱子*/
    int y = 14;
    x = 12;
    for (y = 14; y > 2; y--)
    {
        cct_showch(x, y, ch, bg_color, fg_color, 1);
        cct_showch(x + 32, y, ch, bg_color, fg_color, 1);
        cct_showch(x + 64, y, ch, bg_color, fg_color, 1);
        Sleep(100);//此语句控制延迟效果
    }
    /* 恢复为初始颜色 */
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);


}
/***************************************************************************
      函数名称：print_singleplate
      功    能：打印盘子
      输入参数：无
      返 回 值：
      说    明：
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
        cct_showch(tmp, y, ch, bg_color, fg_color, 2 * n + 1 - i * 2);//用n的值做背景色和前景色
        Sleep(50);
    }
    /* 恢复为初始颜色 */
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/***************************************************************************
      函数名称：print_nplate()
      功    能：打印n个盘子 预备 即第六步的操作
      输入参数：src,n
      返 回 值：
      说    明：
    ***************************************************************************/
void print_nplate(int n, char src, int canshu)
{
    int x, y;
    chassis_print();//先打印三个底盘


    switch (src)
    {
        case('A')://起始柱是A
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
函数名称：per_command()
功    能：处理输入错误 游戏选项
输入参数：
返 回 值：
说    明：
***************************************************************************/
int  per_command(char qishi, char mubiao)
{
    char src;

    while (1) {
        /*恢复光标*/
        cct_setcursor(CURSOR_VISIBLE_NORMAL);
        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);//光标回到初始的地方
        cin >> src;
        if (src == 'Q' || src == 'q') {
            return 0;
        }
        else {
            char dst;
            cin >> dst;
            if (src > 96)/*转大写*/
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
                        cout << "源柱为空！";
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
                                cout << "起始柱和目标柱不能相同！";
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
                                        cout << "大盘压小盘，非法移动！";
                                        Sleep(500);
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << setw(30) << "        ";
                                        cct_gotoxy(GAMEOVER_X, GAMEOVER_Y);
                                        cout << setw(30) << " ";
                                        continue;
                                    }
                                }
                                break;
                            case('C')://为什么这里不报错？
                                if (top3 != 0) {
                                    if (stackc[top3 - 1] < stacka[top1 - 1]) {
                                        cct_gotoxy(0, GAME_note + 1);
                                        cout << "大盘压小盘，非法移动！";
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
                        cout << "源柱为空！";
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
                                        cout << "大盘压小盘，非法移动！";
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
                                cout << "起始柱和目标柱不能相同！";
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
                                        cout << "大盘压小盘，非法移动！";
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
                        cout << "源柱为空！";
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
                                        cout << "大盘压小盘，非法移动！";
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
                                        cout << "大盘压小盘，非法移动！";
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
                                cout << "起始柱和目标柱不能相同！";
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
            /*这里已经得到正确输入*/
        /*再要得到移动的盘子的编号*/
            int number = 0;//代表盘子编号
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
            cct_setcursor(CURSOR_INVISIBLE);//关闭光标
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
      函数名称：game_mode(char src)
      功    能：菜单项第九个选项
      输入参数：n,src,dst
      返 回 值：
      说    明：
    ***************************************************************************/
void game_mode(int n, char src, char dst)/*游戏模式*/
{
    cct_gotoxy(0, 0);
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
    primilary_condition(9, n, src, dst);//初始横向状态 初始状态
    print_nplate(n, src, 0);//打印底盘和盘子 即菜单项6的操作
   //getin_stack(n, src);//将初始元素入栈 main函数里面已经执行过这句话了


    cct_gotoxy(0, GAME_note);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);//恢复光标
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";

    int ret = per_command(src, dst);
    if (ret == 0)
    {
        cct_gotoxy(0, GAME_note + 1);
        cout << "游戏终止！！！";
    }
    else if (ret == 1)
    {
        cct_gotoxy(0, GAME_note + 1);
        cout << "恭喜你已经成功破解汉诺塔游戏，游戏结束!!!!!";
    }
}