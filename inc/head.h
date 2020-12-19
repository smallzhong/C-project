#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <ctype.h>
using namespace std;

const int N = 1010;
const double esp = 0.001;
const int BUFSIZE = 4096;

struct Node
{
    int date;
    double cost;
    char usage[110];
};

void initWindow(char *title);
void start_print();
void fujian();
void cul();
void init(); //用来初始化的函数
void print_all();
void insert();
void my_sort(int n);
bool file_sort(Node a, Node b);
void get_data(int n);               //这个函数用来将文件中的所有数据全部读到结构体里面,n是当前的文件中记录的行数
void print_sort_cost_desc(int n);   //用来以金额降序输出当前的所有记录
bool cost_desc_cmp(Node a, Node b); //降序输出当前所有记录的cmp函数
void print_sort_cost_asc(int n);    //以钱金额升序输出当前所有记录中的数据
bool cost_asc_cmp(Node a, Node b);  //升序输出当前所有记录的cmp函数
void print_sort_date_desc(int n);   //以日期降序输出当前所有记录中的数据
bool date_desc_cmp(Node a, Node b); //日期降序输出当前所有记录的cmp函数
void print_sort_date_asc(int n);    //以日期升序输出当前所有记录中的数据
bool date_asc_cmp(Node a, Node b);  //日期升序输出当前所有记录的cmp函数
void delete_one(int n);             //用来删除其中的一条记录
void delete_print(int n);           //用来在删除函数里面进行把所有的内容输出
FILE *open_rplus(char *filename);   //用来以r+模式打开文件
void get_special_date(int n);       //用来查找某一特定的天的所有消费记录
bool sort_asc(Node a, Node b);
void print_sum(); //用来展示当前的总金额
void change();    //用来改变记录中的元素


#endif
