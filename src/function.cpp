#include "head.h"
extern bool flag;
extern int lines;
extern FILE *fp_lines;
extern char txt1[];
extern struct Node nodes[N];
void initWindow(char *title)
{
    //设置窗口大小
    // system("mode con:cols=100 lines=1000");
    // system("mode con:cols=100");
    //设置窗口字体的颜色
    system("color 7D");
    //循环输出标题（条件：）
    while (*title != 0)
    {
        //输出字符指针所指向的内容
        printf("%c", *title);
        //将指针指向下一个字符
        title++;
        //休眠
        Sleep(50);
    }
}

void start_print()
{
    printf("\t\t\t\t----------功能列表-------\n");
    printf("\t\t\t\t------1------展示记录\n");
    printf("\t\t\t\t------2------添加记录\n");
    printf("\t\t\t\t------3------进行排序\n");
    printf("\t\t\t\t-----------------------------------\n");
    printf("\t\t\t\t------4------查找消费记录\n");
    printf("\t\t\t\t------5------展示所有的消费记录并进行删除操作\n");
    printf("\t\t\t\t------6-----统计当前的总金额\n");
    printf("\t\t\t\t------7-----更改记录中的内容\n");
    printf("\t\t\t\t------8-----关于我们\n");
    printf("\t\t\t\t------9-----附件\n");
    printf("\t\t\t\t------10-----退出当前程序\n");
    printf("\t\t\t\t-----------------------------------------------\n");
}

void delete_print(int n)
{
    FILE *fp;
    // fp = open_rplus("1.txt");
    fp = fopen("1.txt", "r");
    if (fp == NULL)
    {
        perror("出错啦: ");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_SET);
    if (flag == false)
    {
        get_data(n);
        flag = true;
    }
    // printf("%10s %10s %10s\n", "日期", "金额", "用途");
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("id:%d %10d %10.2lf %10s\n", i, nodes[i].date, nodes[i].cost, nodes[i].usage);
    // }
    char buf[BUFSIZE];
    int i = 1;
    // while (1)
    // {
    //     fgets(buf, 10000, fp);
    //     if (feof(fp))
    //         break;
    //     printf("id = %d:%s", i++, buf);
    // }
    while (fgets(buf, 10000, fp) != NULL)
    {
        if (i > lines)
        {
            break; //如果当前读取的行数大于总的行数，说明读取到了空行，跳出循环
        }
        printf("id = %d:%s", i, buf);
        i++;
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
}

bool cost_desc_cmp(Node a, Node b)
{
    if (fabs(a.cost - b.cost) > esp) //如果a.cost不等于b.cost
    {
        return a.cost > b.cost;
    }
    return a.date < b.date; //如果等于，就以日期从大到小输出
}

bool date_desc_cmp(Node a, Node b)
{
    if (a.date != b.date)
    {
        return a.date > b.date;
    }
    return a.cost > b.cost;
}

bool date_asc_cmp(Node a, Node b)
{
    if (a.date != b.date)
    {
        return a.date < b.date;
    }
    return a.cost > b.cost;
}

bool cost_asc_cmp(Node a, Node b)
{
    if (fabs(a.cost - b.cost) > esp) //如果a.cost不等于b.cost
    {
        return a.cost < b.cost;
    }
    return a.date < b.date; //如果等于，就以日期从大到小输出
}

void print_sort_cost_desc(int n)
{
    FILE *fp;
    fp = open_rplus(txt1);
    if (flag == false) //如果当前的数据并没有被读进到结构体里面
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, cost_desc_cmp);
    printf("---------------start-------------------------\n");
    printf("%10s %10s %10s\n", "日期", "金额", "用途");
    for (int i = 1; i <= n; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----共有%d条记录-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    system("pause");
}

void print_sort_date_desc(int n)
{
    FILE *fp;
    fp = open_rplus(txt1);
    if (flag == false) //如果当前的数据并没有被读进到结构体里面
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, date_desc_cmp);
    printf("-------------------start---------------------------\n");
    printf("%10s %10s %10s\n", "日期", "金额", "用途");
    for (int i = 1; i <= n; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----共有%d条记录-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    system("pause");
}

void print_sort_date_asc(int n)
{
    FILE *fp;
    fp = open_rplus(txt1);
    if (flag == false) //如果当前的数据并没有被读进到结构体里面
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, date_asc_cmp);
    printf("-------------------start---------------------------\n");
    printf("%10s %10s %10s\n", "日期", "金额", "用途");
    for (int i = 1; i <= n; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----共有%d条记录-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    system("pause");
}

void print_sort_cost_asc(int n)
{
    FILE *fp;
    fp = open_rplus(txt1);
    if (flag == false) //如果当前的数据并没有被读进到结构体里面
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, cost_asc_cmp);
    printf("-------------------start---------------------------\n");
    printf("%10s %10s %10s\n", "日期", "金额", "用途");
    for (int i = 1; i <= n; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----共有%d条记录-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    system("pause");
}

void get_data(int n)
{
    FILE *fp;
    fp = open_rplus(txt1);
    rewind(fp);
    for (int i = 1; i <= n; i++)
    {
        int date;
        double cost;
        char usage[110];
        fscanf(fp, "%d %lf %s", &date, &cost, usage);
        nodes[i].date = date;
        nodes[i].cost = cost;
        strcpy(nodes[i].usage, usage);
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
}

void print_all()
{
    // FILE *fp;
    // // fp = open_rplus("1.txt");
    // fp = fopen("1.txt", "r");
    // if (fp == NULL)
    // {
    //     perror("出错啦：");
    //     system("pause");
    //     exit(EXIT_FAILURE);
    // }
    // rewind(fp);
    // printf("\n-----------start--------\n");
    // char buf[BUFSIZE];
    // int i = 1; //用来记录当前的行数。如果多于总行数就跳出循环，防止输出空行
    // while (fgets(buf, sizeof(buf), fp) != NULL)
    // {
    //     if (i > lines)
    //     {
    //         break; //跳出循环
    //     }
    //     printf("%s", buf);
    //     i++;
    // }
    // printf("-----共有%d条记录-----\n-----------end--------\n\n", lines);
    // if (fclose(fp) != 0)
    // {
    //     fprintf(stderr, "关闭文件的时候出现错误！\n");
    //     exit(EXIT_FAILURE);
    // }
    FILE *fp;
    fp = open_rplus(txt1);
    if (flag == false) //如果当前的数据并没有被读进到结构体里面
    {
        get_data(lines);
        flag = true;
    }
    printf("-------------------start---------------------------\n");
    printf("%10s %10s %10s\n", "日期", "金额", "用途");
    for (int i = 1; i <= lines; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----共有%d条记录-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
    system("pause");
}

void insert()
{
    FILE *fp;
    fp = open_rplus(txt1);
    {
        lines++;
        rewind(fp_lines);
        fprintf(fp_lines, "%d", lines);
    }                        //首先将line.txt更新
    fseek(fp, 0L, SEEK_END); //将文件指针指到文件的结尾
    int year, mon, day;
    printf("请输入当前的日期，格式为 20XX.XX.XX\n");
    scanf("%d.%d.%d", &year, &mon, &day);
    int date = year * 10000 + mon * 100 + day;
    // cout<<date;
    printf("请输入您想记录的金额\n");
    double cost;
    scanf("%lf", &cost);
    char usage[110];
    printf("请输入用途\n");
    scanf("%s", usage);
    // printf("%10s %10s %10s\n", "日期", "金额", "用途");
    // fprintf(fp, "%10d %10.2lf %10s\n", date, cost, usage);
    fprintf(fp, "%d %.2lf %s\n", date, cost, usage);
    flag = false;
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    system("pause");
}

void my_sort(int n) //传入文件指针和当前文件里面的记录的总条数
{
    int type;
    FILE *fp;
    fp = open_rplus(txt1);
    printf("-------------以下是排序功能-----------\n");
    while (1)
    {
        printf("---1------按每次消费的金额降序输出当前的消费记录\n");
        printf("---2------按每次消费的金额升序输出当前的消费记录\n");
        printf("---3------按日期降序输出当前的消费记录\n");
        printf("---4------按日期升序输出当前的消费记录\n");
        printf("---0------返回上一级\n");
        scanf("%d", &type);
        if (type == 1)
        {
            print_sort_cost_desc(lines);
            break;
        }
        else if (type == 2)
        {
            print_sort_cost_asc(lines);
            break;
        }
        else if (type == 3)
        {
            print_sort_date_desc(lines);
            break;
        }
        else if (type == 4)
        {
            print_sort_date_asc(lines);
            break;
        }
        else if (type == 0)
            return;
        else
        {
            printf("输入不合法！请重新输入。\n");
            continue;
        }
    }
    if (flag == false) //如果当前的数据并没有被读进到结构体里面
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, file_sort); //进行对当前文件里面的东西的排序
    rewind(fp);
    // printf("%10s %10s %10s\n", "日期", "金额", "用途");
    for (int i = 1; i <= n; i++)
    {
        fprintf(fp, "%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
        // fprintf(stdout, "%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "关闭文件的时候出现错误！\n");
        exit(EXIT_FAILURE);
    }
}

void delete_one(int n)
{
    FILE *fp;
    // fp = open_rplus("1.txt");
    fp = fopen("1.txt", "r");
    if (fp == NULL)
    {
        perror("出错啦：");
        system("pause");
        exit(EXIT_FAILURE);
    }
    FILE *fpt;
    char buf[BUFSIZE];
    fpt = fopen("temp.txt", "w");
    if (fpt == NULL)
    {
        perror("出错啦：");
        system("pause");
        exit(EXIT_FAILURE);
    }
    // while (1)
    // {
    //     i++;
    //     if (i == n)
    //     {
    //         fgets(buf, sizeof(buf), fp); //除了需要删除的那一行，其他的全部放到temp.txt里面去
    //         // if (feof(fp) || buf[0] == '\n') //如果当前到达了文件的末尾或者读了一个换行符进来（也说明这是文件的末尾),break
    //         //     break;
    //         if (fgets(buf, 100, fp) == NULL)
    //             break;
    //         if (buf[0] == '\n')
    //             break;
    //         printf("i == n buf = %s", buf);
    //     }
    //     else
    //     {
    //         if (fgets(buf, 100, fp) == NULL)
    //             break;
    //         if (buf[0] == '\n')
    //             break;
    //         // if (feof(fp) || buf[0] == '\n') //如果当前到达了文件的末尾或者读了一个换行符进来（也说明这是文件的末尾),break
    //         // break;
    //         printf("%s", buf);
    //         fputs(buf, fpt);
    //     }
    // }
    int i = 1; //用来记录当前读的是第几行
    while (fgets(buf, 1000, fp) != NULL)
    {
        // if (i > lines)
        // {
        //     break;//如果当前行数的id大于总的行数，
        // }
        if (i == n)
        {
            i++;
            continue;
        }
        else
        {
            i++;
            fputs(buf, fpt);
        }
    }
    fclose(fp);
    fclose(fpt); //全部关闭
    // system("erase 1.txt"); //将源文件删除
    // remove("1.txt");
    const char A[10] = "1.txt";

    if (remove(A))
    {
        printf("删除失败\n");
        perror("remove");
        system("pause");
        exit(EXIT_FAILURE);
    }
    if (rename("temp.txt", "1.txt"))
    {
        perror("重命名时出现错误: ");
        system("pause");
        exit(EXIT_FAILURE);
    }
    //至此1.txt文件里面的内容全部修改完毕
    //开始修改line.txt里面的内容
    lines--; //先减少一行
    FILE *lfp;
    lfp = fopen("line.txt", "w");
    if (lfp == NULL)
    {
        printf("can't open line.txt\n");
        perror("错误信息: ");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%d", lines);
    if (fclose(lfp) != 0) //用来关闭lfp
    {
        perror("关闭line.txt时发生错误");
        system("pause");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    flag = false;
    system("pause");
}

void print_sum()
{
    if (flag == false)
    {
        get_data(lines);
        flag = true;
    }
    double sum = 0;
    for (int i = 1; i <= lines; i++)
    {
        sum += nodes[i].cost;
    }
    printf("当前所有记录的总钱数是：%.2lf\n", sum);
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    system("pause");
}

void change()
{
    // delete_print(lines);
    get_data(lines);
    flag = false;
    FILE *fp;
    fp = open_rplus(txt1);
    char buf[BUFSIZE];
    int i = 1;
    while (fgets(buf, 10000, fp) != NULL)
    {
        if (i > lines)
        {
            break; //如果当前读取的行数大于总的行数，说明读取到了空行，跳出循环
        }
        printf("id = %d:%s", i, buf);
        i++;
    }
    // for (int i = 1; i <= lines; i++)
    // {
    //     printf("%d %.2lf %s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    // }
    printf("如果您想修改某条记录的日期，请输入1，想修改金额请输入2，想修改记录的用途请输入3\n");
    int type;
    scanf("%d", &type);
    while (!(type == 1 || type == 2 || type == 3))
    {
        printf("输入不合法，请重新输入:");
        scanf("%d", &type);
    }
    int line_to_alter;
    printf("请输入您想要修改的记录的id\n");
    scanf("%d", &line_to_alter);
    while (line_to_alter < 1 || line_to_alter > lines)
    {
        printf("输入不合法，请重新输入:");
        scanf("%d", &line_to_alter);
    }
    if (type == 1)
    {
        printf("请输入想修改成的日期:");
        int date;
        scanf("%d", &date);
        nodes[line_to_alter].date = date;
    }
    else if (type == 2)
    {
        printf("请输入想修改成的金额：");
        double money;
        scanf("%lf", &money);
        nodes[line_to_alter].cost = money;
    }
    else if (type == 3)
    {
        char temp[BUFSIZE];
        printf("请输入想要修改成的用途:");
        scanf("%s", temp);
        strcpy(nodes[line_to_alter].usage, temp);
    }
    printf("=============修改后的记录============\n");
    printf("%10s %10s %10s\n", "日期", "金额", "用途");
    for (int i = 1; i <= lines; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("===================================\n");
    FILE *fp2;
    fp2 = fopen("temp.txt", "w");
    if (fp2 == NULL)
    {
        perror("出错啦：");
        system("pause");
        exit(EXIT_FAILURE);
    }
    printf("%10s %10s %10s\n", "日期", "金额", "用途");
    for (int i = 1; i <= lines; i++)
    {
        fprintf(fp2, "%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    if (fclose(fp) == EOF)
    {
        perror("can't close fp:");
        system("pause");
        exit(EXIT_FAILURE);
    }
    if (fclose(fp2) == EOF)
    {
        perror("can't close fp2");
        system("pause");
        exit(EXIT_FAILURE);
    }
    if (remove("1.txt") != 0)
    {
        printf("can't remove 1.txt!\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    if (rename("temp.txt", "1.txt") != 0)
    {
        printf("can't rename it!\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    system("pause");
}

void get_special_date(int n)
{
    if (flag == false) //如果当前的数据并没有被读进到结构体里面
    {
        get_data(lines);
    }
    flag = false; //因为要将结构体里面的东西进行排序，所以下一次读取数据的时候要重新读取
    sort(nodes + 1, nodes + 1 + lines, sort_asc);
    bool tflag = false; //用来记录需要查找的日期到底有没有记录
    int ct = 0;         //用来记录一共查找到了几条记录
    for (int i = 1; i <= lines; i++)
    {
        if (nodes[i].date > n)
            break; //如果当前遍历到的已经大于需要查找的日期，跳出循环
        if (nodes[i].date == n)
        {
            ct++;
            if (tflag == false)
            {
                printf("-------查找到的记录如下----------\n");
                printf("%10s %10s %10s\n", "日期", "金额", "用途");
            }
            tflag = true;
            printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
        }
    }
    if (tflag == false) //如果没有找到
    {
        printf("对不起,未查到您输入日期当日的消费记录。\n");
    }
    else
    {
        printf("-------以上共查找到了%d条记录-------\n", ct);
    }
    // printf("-----0------返回上一级\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    system("pause");
}

FILE *open_rplus(char *filename)
{
    FILE *fp;
    if ((fp = fopen(filename, "r+")) == NULL)
    {
        fprintf(stderr, "打开%s文件的时候出现错误，有可能是因为该文件不存在，如果不存在请先创建文件\n", filename);
        perror(filename);
        system("pause");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void init()
{
    FILE *fp1;
    fp1 = fopen("1.txt", "wb");
    if (fp1 == NULL)
    {
        perror("出错啦：");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fclose(fp1);
    FILE *fp2;
    fp2 = fopen("line.txt", "w");
    if (fp2 == NULL)
    {
        perror("出错啦：");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fprintf(fp2, "0");
    fclose(fp2); //创立两个文件并向记录行数的文件里面记录行数为0
    lines = 0;
    return;
}

void fujian()
{
    printf("\t\t\t\t----------功能列表-------\n");
    int type;
    while (1)
    {
        printf("\t\t\t\t------1------------计算器\n");
        scanf("%d", &type);
        if (type == 1)
        {
            cul();
            break;
        }
        else
        {
            printf("输入不合法，请重新输入。\n");
            continue;
        }
    }
}

void cul()
{
    // 分别存放第一个操作数和第二个操作数以及结果的变量
    double x1, x2, result;

    // 存放运算符的变量
    char m;
    int ttt = 1;
    while (ttt)
    {
        printf("请输入第一个数：\n");
        // 下面这得注意，接收double型的数据得用lf%，接收float用f%
        scanf("%lf", &x1);

        printf("请输入运算操作（+ - * /）：\n");
        cin >> m;
        printf("\n");

        printf("请输入第二个数：\n");
        scanf("%lf", &x2);

        switch (m)
        {
        case '+':
            printf("加法\n");
            result = x1 + x2;
            printf("%lf + %lf = %lf\n", x1, x2, result);
            break;

        case '-':
            printf("减法\n");
            result = x1 - x2;
            printf("%lf - %lf = %lf\n", x1, x2, result);
            break;

        case '*':
            printf("乘法\n");
            result = x1 * x2;
            printf("%lf * %lf = %lf\n", x1, x2, result);
            break;

        case '/':
            printf("除法\n");
            if (x2 == 0)
            {
                printf("除数不能为0.\n");
            }
            else
            {
                result = x1 / x2;
                printf("%lf / %lf = %lf\n", x1, x2, result);
            }
            break;

        default:
            break;
        }
        printf("是否继续？输入0退出\n");
        scanf("%d", &ttt);
        // cout << "是否继续" << e
        // cin >> ttt;
    }
}

bool file_sort(Node a, Node b)
{
    return a.date < b.date;
}

bool sort_asc(Node a, Node b)
{
    if (a.date != b.date)
    {
        return a.date < b.date;
    }
    return a.cost < b.cost;
}
