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
void init(); //������ʼ���ĺ���
void print_all();
void insert();
void my_sort(int n);
bool file_sort(Node a, Node b);
void get_data(int n);               //��������������ļ��е���������ȫ�������ṹ������,n�ǵ�ǰ���ļ��м�¼������
void print_sort_cost_desc(int n);   //�����Խ��������ǰ�����м�¼
bool cost_desc_cmp(Node a, Node b); //���������ǰ���м�¼��cmp����
void print_sort_cost_asc(int n);    //��Ǯ������������ǰ���м�¼�е�����
bool cost_asc_cmp(Node a, Node b);  //���������ǰ���м�¼��cmp����
void print_sort_date_desc(int n);   //�����ڽ��������ǰ���м�¼�е�����
bool date_desc_cmp(Node a, Node b); //���ڽ��������ǰ���м�¼��cmp����
void print_sort_date_asc(int n);    //���������������ǰ���м�¼�е�����
bool date_asc_cmp(Node a, Node b);  //�������������ǰ���м�¼��cmp����
void delete_one(int n);             //����ɾ�����е�һ����¼
void delete_print(int n);           //������ɾ������������а����е��������
FILE *open_rplus(char *filename);   //������r+ģʽ���ļ�
void get_special_date(int n);       //��������ĳһ�ض�������������Ѽ�¼
bool sort_asc(Node a, Node b);
void print_sum(); //����չʾ��ǰ���ܽ��
void change();    //�����ı��¼�е�Ԫ��


#endif
