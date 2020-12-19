#include "head.h"
bool flag = false; //用来记录是否已经将所有的数据读入并且数据没有被更改,防止重复读取浪费时间
int lines;         //用来记录当前的文件中的记录的行数
FILE *fp_lines;
char txt1[] = "1.txt";
struct Node nodes[N];
int main()
{
    char title[] = "\t\t\t*********欢迎进入记账簿系统！********\n\n\n";
    initWindow(title);
    fp_lines = fopen("line.txt", "r");
    if (fp_lines == NULL)
    {
        FILE *tfp;
        tfp = fopen("line.txt", "w");
        fprintf(tfp, "0");
        printf("=====================\n");
        printf("检测到您是第一次使用该程序，已为您自动生成记录文件\n");
        printf("=====================\n");
        FILE *tfp2;
        tfp2 = fopen("1.txt", "wb");
        fclose(tfp2);
        fp_lines = fopen("line.txt", "r");
        if (fp_lines == NULL)
        {
            fprintf(stderr, "打开line.txt时出现错误");
            perror("line.txt: ");
            system("pause");
            exit(EXIT_FAILURE);
        }
    }
    fscanf(fp_lines, "%d", &lines);
    while (1)
    {
        start_print(); //start_print函数用来展示启动界面
        int type;
        scanf("%d", &type);
        if (type == 0)
        {
            init();
        }
        else if (type == 1)
        {
            print_all();
        }
        else if (type == 2)
        {
            insert();
        }
        else if (type == 3)
        {
            my_sort(lines);
        }
        else if (type == 3.1)
        {
            print_sort_cost_desc(lines);
        }
        else if (type == 3.2)
        {
            print_sort_cost_asc(lines);
        }
        else if (type == 3.3)
        {
            print_sort_date_desc(lines);
        }
        else if (type == 3.4)
        {
            print_sort_date_asc(lines);
        }
        else if (type == 4)
        {
            printf("请输入一个日期，格式如20191208所示，中间没有分隔符:");
            int d;
            scanf("%d", &d);
            get_special_date(d);
        }
        else if (type == 5)
        {
            delete_print(lines);
            int templine;
            while (1)
            {
                printf("请输入您想要删除的行数:");
                scanf("%d", &templine);
                if (templine <= 0 || templine > lines)
                {
                    printf("您的输入不合法，应该输入一个1~%d之间的数，请重新输入\n", lines);
                    continue;
                }
                else
                {
                    delete_one(templine);
                    break;
                }
            }
        }
        else if (type == 6)
        {
            print_sum();
        }
        else if (type == 7)
        {
            change();
        }
        else if (type == 8)
        {
            cout << "------------------------------------" << endl;
            cout << "我们的成员有" << endl;
            cout << "************" << endl;
            cout << "************" << endl;
            cout << "************" << endl;
            cout << "------------------------------------" << endl;
            system("pause");
        }
        else if (type == 9)
        {
            fujian();
        }
        else if (type == 10)
        {
            // char farewell = "再见！欢迎再次使用本记账系统"
            char tempstring[] = "\t\t\t*********再见！欢迎再次使用本记账系统********\n\n\n";
            char *farewell = tempstring;
            while (*farewell != 0)
            {
                //输出字符指针所指向的内容
                printf("%c", *farewell);
                //将指针指向下一个字符
                farewell++;
                //休眠
            }
            break;
        }
        else
        {
            // printf("请输入正确的指令\n");
            // 这个好像在pause之后会收到回车出现问题,先注释掉
        }
    }
    return 0;
}
