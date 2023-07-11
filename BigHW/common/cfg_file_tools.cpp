/*2052316 信07 李祎娜*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <io.h>
#include "../include/cfg_file_tools.h"
using namespace std;

/* ---------------------------------------------------------------
	 允许加入其它需要static函数（内部工具用）
   ---------------------------------------------------------------- */
/*函数功能：把配置文件中的所有信息读入到内存中 修改内存后再重新写入文件*/
static void get_all_lines()
{//由于要实现修改的功能，要用到链表的知识；


}
/***************************************************************************
  函数名称：无参构造函数
  功    能：//无参构造，置filename为""即可
  输入参数：
  返 回 值：
  说    明：如有必要，按需加入其它内容
***************************************************************************/
CFT::CFT()
{
	filename = "";
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：如有必要，按需加入其它内容
***************************************************************************/
CFT::~CFT()
{
	if (fp.is_open())
		fp.close();
}

/***************************************************************************
  函数名称：
  功    能：//两参构造，功能同open
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
CFT::CFT(const char* cfgname, int opt)
{
	//cout << "进入两参构造函数\n";
	filename = cfgname;
	if (opt == OPEN_OPT_RDONLY) {//只读方式
		fp.open(filename, ios::binary | ios::out);
		if (!fp.is_open()) {
			cout << "以只读方式打开的文件" << filename << "不存在\n";
		}
	}
	else if (opt == OPEN_OPT_RDWR) {
		fp.open(filename, ios::binary | ios::in | ios::out);//文件不存在时要自动创造文件；
		if (!fp.is_open()) {//打开失败则创建
			fp.open(filename, ios::binary | ios::out);
		}
		cout << "读写文件"<<filename<<"打开成功\n";
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：CFT(const char* cfgname, int opt = OPEN_OPT_RDONLY);	
  //两参构造，功能同open
  说    明：
***************************************************************************/
void CFT::open(const char* cfgname, int& judge,int opt)
{
	filename = cfgname;
	//cout << "进入open函数\n";
	if (opt == OPEN_OPT_RDONLY) {//只读方式
		fp.open(filename, ios::binary | ios::out);
		if (!fp.is_open()) {
			cout << "以只读方式打开的文件" << filename << "不存在\n";
			judge = -1;
			//return -1;
		}
	}
	else if (opt == OPEN_OPT_RDWR) {
		fp.open(filename, ios::binary|ios::in|ios::out);//文件不存在时要自动创造文件；
		if (!fp.is_open()) {//打开失败则创建
			fp.open(filename, ios::binary | ios::out);
		}
		cout << "读写文件" << filename << "打开成功\n";
	}
	

	//return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：关闭文件
***************************************************************************/
void CFT::close()
{
	if (fp.is_open())//保证显示调用后析构不错
		fp.close();
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：newsize代表字节数
  说    明：C++17中有filesystem::resize_file直接可以修改文件大小，之前的版本无
                   因此本函数扔沿用C的旧方法
	    已实现，不要动
***************************************************************************/
int CFT::file_resize(int newsize)
{
	/* 如果大小是负数则直接返回-1 */
	if (newsize < 0)
		return -1;

	if (!fp.good())
		fp.clear();

	/* 取fp当前指针位置 */
	int now_pos = int(fp.tellg());

	/* 首先：C++方式关闭 */
	this->close();

	/* 其次：C方式打开并改变文件大小 */
	FILE* fp_cstyle;
	fp_cstyle = fopen(filename.c_str(), "rb+"); //rw方式打开
	if (fp_cstyle) {
		_chsize(_fileno(fp_cstyle), newsize);
		fclose(fp_cstyle);
	}
	else
		cout << "open [" << filename << "] for resize failed" << endl;

	/* 再次：C++方式重新打开 */
	fp.open(filename, ios::in | ios::out | ios::binary);
	if (fp.is_open()==0) {
		cout << "reopen [" << filename << "] after resize failed" << endl;
		return -1;
	}

	/* 文件指针移动到原位置 */
	fp.seekg(now_pos < newsize ? now_pos:newsize, ios::beg);

	return 0;
}

/* ---------------------------------------------------------------
	 允许AAT中自定义成员函数的实现（protected）
   ---------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：加入的组放在文件最后，如果该组已经存在，则不加入
  输入参数：//先不考虑已经存在的情况，直接在文件最后写入
  返 回 值：
  说    明：成功返回1 失败返回0（已存在返回0）
 ***************************************************************************/
int CFT::group_add(const char* group_name)
{
	//char mark_group[1024] = '[' + group_name + ']';
	char mark_group[1024] = "[";
	strcat(mark_group, group_name);
	strcat(mark_group, "]\n\n");//再人为补两个回车
	//cout << "strlen(mark_group=)" << strlen(mark_group) << endl;
	//cout << mark_group << endl;
	fp.write(mark_group, strlen(mark_group));
	//退出，证明需要加入；
	//fp.seekg(ios::end, 0);
	//fp.write(mark_group, strlen(mark_group));//
	cout << "调试信息，已成功加入[" << group_name << "]\n";
	return 1; //成功加入一组
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：返回成功删除的个数，如果不存在返回0；存在多组则全部删除

  说    明：还没处理好，现在还没做到要处理错误的程度；
***************************************************************************/
int CFT::group_del(const char* group_name)
{
	char mark_group[1024] = "[";
	int position1 = 0;
	int position2 = 0;
	int delposition = 0;
	int enddel = 0;
	strcpy(&mark_group[1], group_name);
	strcat(mark_group, "]");
	//文件指针移到开头进行读取
	char  perline[1024] = "";
	fp.seekp(ios::beg, 0);//读的文件指针回到开头
	fp.getline(perline, 1024);//先特判第一行
	if (mark_group == perline) {
		;
	}
	while (!fp.eof()) {
		fp.getline(perline, 1024);
		if (mark_group == perline) {//删除该组到下一组之间的全部信息
			delposition = position1;//位置1
			while (!fp.eof()) {
				fp.getline(perline, 1024);
				if (perline[0] = '[' && perline[strlen(perline) - 1] == ']') {
					enddel = position2;//位置2
					break;
				}
				position2 = (int)fp.tellg();//tellp和tellg同步的；
				//如何删除？
			}

			//int now_pos = int(fp.tellg());
		}
		position1= (int)fp.tellg();//读取上一行时的位置 但是如果第一行的文件
	}
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：增加项目 组名的下一行处 只增加一次，成功返回一
***************************************************************************/
int CFT::item_add(const char* group_name, const char* item_name, const int item_value)
{
	cout << item_name<<strlen(item_name) << endl;
	fp.write(item_name, strlen(item_name));//到底为什么不能写入啊？
	char* p = new(nothrow)char[strlen(group_name) + 3];
	if (p == NULL) {
		cout << "动态内存申请失败\n";
		exit(-1);
	}
	p[0] = '[';
	strcpy(&p[1], group_name);
	p[strlen(group_name) + 1] = ']';
	char perline[1024]="";
	while (fp.getline(perline, 1024)) {
		cout << perline << endl;
		if (strncmp(perline, p, strlen(group_name) + 2) == 0) {
			//找到了位置；写入一次即可退出
			//fp.get();//读掉回车；
			cout << item_name << " " << strlen(item_name);
			fp.write(item_name, strlen(item_name));//写入该文件 读写同步
			//fp << item_name;//写入文件？
			return 1;
		}
	}//暂时没有考虑已经存在的情况
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_add(const char* group_name, const char* item_name, const double item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_add(const char* group_name, const char* item_name, const char *item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_add(const char* group_name, const char* item_name, const string &item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_add(const char* group_name, const char* item_name, const char item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_add(const char* group_name, const char* item_name)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_del(const char* group_name, const char* item_name)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_update(const char* group_name, const char* item_name, const int item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_update(const char* group_name, const char* item_name, const double item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_update(const char* group_name, const char* item_name, const char* item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_update(const char* group_name, const char* item_name, const string &item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_update(const char* group_name, const char* item_name, const char item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_update(const char* group_name, const char* item_name)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_get_value(const char* group_name, const char* item_name, int &item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_get_value(const char* group_name, const char* item_name, double& item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_get_value(const char* group_name, const char* item_name, char *item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_get_value(const char* group_name, const char* item_name, string &item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_get_value(const char* group_name, const char* item_name, char& item_value)
{
	return 0; //此句根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CFT::item_get_value(const char* group_name, const char* item_name)
{
	return 0; //此句根据需要修改
}

