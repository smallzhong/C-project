#include "head.h"
extern bool flag;
extern int lines;
extern FILE *fp_lines;
extern char txt1[];
extern struct Node nodes[N];
void initWindow(char *title)
{
    //���ô��ڴ�С
    // system("mode con:cols=100 lines=1000");
    // system("mode con:cols=100");
    //���ô����������ɫ
    system("color 7D");
    //ѭ��������⣨��������
    while (*title != 0)
    {
        //����ַ�ָ����ָ�������
        printf("%c", *title);
        //��ָ��ָ����һ���ַ�
        title++;
        //����
        Sleep(50);
    }
}

void start_print()
{
    printf("\t\t\t\t----------�����б�-------\n");
    printf("\t\t\t\t------1------չʾ��¼\n");
    printf("\t\t\t\t------2------��Ӽ�¼\n");
    printf("\t\t\t\t------3------��������\n");
    printf("\t\t\t\t-----------------------------------\n");
    printf("\t\t\t\t------4------�������Ѽ�¼\n");
    printf("\t\t\t\t------5------չʾ���е����Ѽ�¼������ɾ������\n");
    printf("\t\t\t\t------6-----ͳ�Ƶ�ǰ���ܽ��\n");
    printf("\t\t\t\t------7-----���ļ�¼�е�����\n");
    printf("\t\t\t\t------8-----��������\n");
    printf("\t\t\t\t------9-----����\n");
    printf("\t\t\t\t------10-----�˳���ǰ����\n");
    printf("\t\t\t\t-----------------------------------------------\n");
}

void delete_print(int n)
{
    FILE *fp;
    // fp = open_rplus("1.txt");
    fp = fopen("1.txt", "r");
    if (fp == NULL)
    {
        perror("������: ");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_SET);
    if (flag == false)
    {
        get_data(n);
        flag = true;
    }
    // printf("%10s %10s %10s\n", "����", "���", "��;");
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
            break; //�����ǰ��ȡ�����������ܵ�������˵����ȡ���˿��У�����ѭ��
        }
        printf("id = %d:%s", i, buf);
        i++;
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------������һ��\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
}

bool cost_desc_cmp(Node a, Node b)
{
    if (fabs(a.cost - b.cost) > esp) //���a.cost������b.cost
    {
        return a.cost > b.cost;
    }
    return a.date < b.date; //������ڣ��������ڴӴ�С���
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
    if (fabs(a.cost - b.cost) > esp) //���a.cost������b.cost
    {
        return a.cost < b.cost;
    }
    return a.date < b.date; //������ڣ��������ڴӴ�С���
}

void print_sort_cost_desc(int n)
{
    FILE *fp;
    fp = open_rplus(txt1);
    if (flag == false) //�����ǰ�����ݲ�û�б��������ṹ������
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, cost_desc_cmp);
    printf("---------------start-------------------------\n");
    printf("%10s %10s %10s\n", "����", "���", "��;");
    for (int i = 1; i <= n; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----����%d����¼-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------������һ��\n");
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
    if (flag == false) //�����ǰ�����ݲ�û�б��������ṹ������
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, date_desc_cmp);
    printf("-------------------start---------------------------\n");
    printf("%10s %10s %10s\n", "����", "���", "��;");
    for (int i = 1; i <= n; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----����%d����¼-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------������һ��\n");
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
    if (flag == false) //�����ǰ�����ݲ�û�б��������ṹ������
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, date_asc_cmp);
    printf("-------------------start---------------------------\n");
    printf("%10s %10s %10s\n", "����", "���", "��;");
    for (int i = 1; i <= n; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----����%d����¼-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------������һ��\n");
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
    if (flag == false) //�����ǰ�����ݲ�û�б��������ṹ������
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, cost_asc_cmp);
    printf("-------------------start---------------------------\n");
    printf("%10s %10s %10s\n", "����", "���", "��;");
    for (int i = 1; i <= n; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----����%d����¼-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------������һ��\n");
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
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
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
    //     perror("��������");
    //     system("pause");
    //     exit(EXIT_FAILURE);
    // }
    // rewind(fp);
    // printf("\n-----------start--------\n");
    // char buf[BUFSIZE];
    // int i = 1; //������¼��ǰ���������������������������ѭ������ֹ�������
    // while (fgets(buf, sizeof(buf), fp) != NULL)
    // {
    //     if (i > lines)
    //     {
    //         break; //����ѭ��
    //     }
    //     printf("%s", buf);
    //     i++;
    // }
    // printf("-----����%d����¼-----\n-----------end--------\n\n", lines);
    // if (fclose(fp) != 0)
    // {
    //     fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
    //     exit(EXIT_FAILURE);
    // }
    FILE *fp;
    fp = open_rplus(txt1);
    if (flag == false) //�����ǰ�����ݲ�û�б��������ṹ������
    {
        get_data(lines);
        flag = true;
    }
    printf("-------------------start---------------------------\n");
    printf("%10s %10s %10s\n", "����", "���", "��;");
    for (int i = 1; i <= lines; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("-----����%d����¼-----\n-------------------end---------------------------\n\n", lines);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
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
    }                        //���Ƚ�line.txt����
    fseek(fp, 0L, SEEK_END); //���ļ�ָ��ָ���ļ��Ľ�β
    int year, mon, day;
    printf("�����뵱ǰ�����ڣ���ʽΪ 20XX.XX.XX\n");
    scanf("%d.%d.%d", &year, &mon, &day);
    int date = year * 10000 + mon * 100 + day;
    // cout<<date;
    printf("�����������¼�Ľ��\n");
    double cost;
    scanf("%lf", &cost);
    char usage[110];
    printf("��������;\n");
    scanf("%s", usage);
    // printf("%10s %10s %10s\n", "����", "���", "��;");
    // fprintf(fp, "%10d %10.2lf %10s\n", date, cost, usage);
    fprintf(fp, "%d %.2lf %s\n", date, cost, usage);
    flag = false;
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------������һ��\n");
    // int type;
    // scanf("%d", &type);
    // if (type == 0)
    //     return;
    system("pause");
}

void my_sort(int n) //�����ļ�ָ��͵�ǰ�ļ�����ļ�¼��������
{
    int type;
    FILE *fp;
    fp = open_rplus(txt1);
    printf("-------------������������-----------\n");
    while (1)
    {
        printf("---1------��ÿ�����ѵĽ��������ǰ�����Ѽ�¼\n");
        printf("---2------��ÿ�����ѵĽ�����������ǰ�����Ѽ�¼\n");
        printf("---3------�����ڽ��������ǰ�����Ѽ�¼\n");
        printf("---4------���������������ǰ�����Ѽ�¼\n");
        printf("---0------������һ��\n");
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
            printf("���벻�Ϸ������������롣\n");
            continue;
        }
    }
    if (flag == false) //�����ǰ�����ݲ�û�б��������ṹ������
    {
        get_data(n);
        flag = true;
    }
    sort(nodes + 1, nodes + 1 + n, file_sort); //���жԵ�ǰ�ļ�����Ķ���������
    rewind(fp);
    // printf("%10s %10s %10s\n", "����", "���", "��;");
    for (int i = 1; i <= n; i++)
    {
        fprintf(fp, "%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
        // fprintf(stdout, "%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "�ر��ļ���ʱ����ִ���\n");
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
        perror("��������");
        system("pause");
        exit(EXIT_FAILURE);
    }
    FILE *fpt;
    char buf[BUFSIZE];
    fpt = fopen("temp.txt", "w");
    if (fpt == NULL)
    {
        perror("��������");
        system("pause");
        exit(EXIT_FAILURE);
    }
    // while (1)
    // {
    //     i++;
    //     if (i == n)
    //     {
    //         fgets(buf, sizeof(buf), fp); //������Ҫɾ������һ�У�������ȫ���ŵ�temp.txt����ȥ
    //         // if (feof(fp) || buf[0] == '\n') //�����ǰ�������ļ���ĩβ���߶���һ�����з�������Ҳ˵�������ļ���ĩβ),break
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
    //         // if (feof(fp) || buf[0] == '\n') //�����ǰ�������ļ���ĩβ���߶���һ�����з�������Ҳ˵�������ļ���ĩβ),break
    //         // break;
    //         printf("%s", buf);
    //         fputs(buf, fpt);
    //     }
    // }
    int i = 1; //������¼��ǰ�����ǵڼ���
    while (fgets(buf, 1000, fp) != NULL)
    {
        // if (i > lines)
        // {
        //     break;//�����ǰ������id�����ܵ�������
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
    fclose(fpt); //ȫ���ر�
    // system("erase 1.txt"); //��Դ�ļ�ɾ��
    // remove("1.txt");
    const char A[10] = "1.txt";

    if (remove(A))
    {
        printf("ɾ��ʧ��\n");
        perror("remove");
        system("pause");
        exit(EXIT_FAILURE);
    }
    if (rename("temp.txt", "1.txt"))
    {
        perror("������ʱ���ִ���: ");
        system("pause");
        exit(EXIT_FAILURE);
    }
    //����1.txt�ļ����������ȫ���޸����
    //��ʼ�޸�line.txt���������
    lines--; //�ȼ���һ��
    FILE *lfp;
    lfp = fopen("line.txt", "w");
    if (lfp == NULL)
    {
        printf("can't open line.txt\n");
        perror("������Ϣ: ");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%d", lines);
    if (fclose(lfp) != 0) //�����ر�lfp
    {
        perror("�ر�line.txtʱ��������");
        system("pause");
        exit(EXIT_FAILURE);
    }
    // printf("-----0------������һ��\n");
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
    printf("��ǰ���м�¼����Ǯ���ǣ�%.2lf\n", sum);
    // printf("-----0------������һ��\n");
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
            break; //�����ǰ��ȡ�����������ܵ�������˵����ȡ���˿��У�����ѭ��
        }
        printf("id = %d:%s", i, buf);
        i++;
    }
    // for (int i = 1; i <= lines; i++)
    // {
    //     printf("%d %.2lf %s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    // }
    printf("��������޸�ĳ����¼�����ڣ�������1�����޸Ľ��������2�����޸ļ�¼����;������3\n");
    int type;
    scanf("%d", &type);
    while (!(type == 1 || type == 2 || type == 3))
    {
        printf("���벻�Ϸ�������������:");
        scanf("%d", &type);
    }
    int line_to_alter;
    printf("����������Ҫ�޸ĵļ�¼��id\n");
    scanf("%d", &line_to_alter);
    while (line_to_alter < 1 || line_to_alter > lines)
    {
        printf("���벻�Ϸ�������������:");
        scanf("%d", &line_to_alter);
    }
    if (type == 1)
    {
        printf("���������޸ĳɵ�����:");
        int date;
        scanf("%d", &date);
        nodes[line_to_alter].date = date;
    }
    else if (type == 2)
    {
        printf("���������޸ĳɵĽ�");
        double money;
        scanf("%lf", &money);
        nodes[line_to_alter].cost = money;
    }
    else if (type == 3)
    {
        char temp[BUFSIZE];
        printf("��������Ҫ�޸ĳɵ���;:");
        scanf("%s", temp);
        strcpy(nodes[line_to_alter].usage, temp);
    }
    printf("=============�޸ĺ�ļ�¼============\n");
    printf("%10s %10s %10s\n", "����", "���", "��;");
    for (int i = 1; i <= lines; i++)
    {
        printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
    }
    printf("===================================\n");
    FILE *fp2;
    fp2 = fopen("temp.txt", "w");
    if (fp2 == NULL)
    {
        perror("��������");
        system("pause");
        exit(EXIT_FAILURE);
    }
    printf("%10s %10s %10s\n", "����", "���", "��;");
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
    if (flag == false) //�����ǰ�����ݲ�û�б��������ṹ������
    {
        get_data(lines);
    }
    flag = false; //��ΪҪ���ṹ������Ķ�����������������һ�ζ�ȡ���ݵ�ʱ��Ҫ���¶�ȡ
    sort(nodes + 1, nodes + 1 + lines, sort_asc);
    bool tflag = false; //������¼��Ҫ���ҵ����ڵ�����û�м�¼
    int ct = 0;         //������¼һ�����ҵ��˼�����¼
    for (int i = 1; i <= lines; i++)
    {
        if (nodes[i].date > n)
            break; //�����ǰ���������Ѿ�������Ҫ���ҵ����ڣ�����ѭ��
        if (nodes[i].date == n)
        {
            ct++;
            if (tflag == false)
            {
                printf("-------���ҵ��ļ�¼����----------\n");
                printf("%10s %10s %10s\n", "����", "���", "��;");
            }
            tflag = true;
            printf("%10d %10.2lf %10s\n", nodes[i].date, nodes[i].cost, nodes[i].usage);
        }
    }
    if (tflag == false) //���û���ҵ�
    {
        printf("�Բ���,δ�鵽���������ڵ��յ����Ѽ�¼��\n");
    }
    else
    {
        printf("-------���Ϲ����ҵ���%d����¼-------\n", ct);
    }
    // printf("-----0------������һ��\n");
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
        fprintf(stderr, "��%s�ļ���ʱ����ִ����п�������Ϊ���ļ������ڣ�������������ȴ����ļ�\n", filename);
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
        perror("��������");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fclose(fp1);
    FILE *fp2;
    fp2 = fopen("line.txt", "w");
    if (fp2 == NULL)
    {
        perror("��������");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fprintf(fp2, "0");
    fclose(fp2); //���������ļ������¼�������ļ������¼����Ϊ0
    lines = 0;
    return;
}

void fujian()
{
    printf("\t\t\t\t----------�����б�-------\n");
    int type;
    while (1)
    {
        printf("\t\t\t\t------1------------������\n");
        scanf("%d", &type);
        if (type == 1)
        {
            cul();
            break;
        }
        else
        {
            printf("���벻�Ϸ������������롣\n");
            continue;
        }
    }
}

void cul()
{
    // �ֱ��ŵ�һ���������͵ڶ����������Լ�����ı���
    double x1, x2, result;

    // ���������ı���
    char m;
    int ttt = 1;
    while (ttt)
    {
        printf("�������һ������\n");
        // �������ע�⣬����double�͵����ݵ���lf%������float��f%
        scanf("%lf", &x1);

        printf("���������������+ - * /����\n");
        cin >> m;
        printf("\n");

        printf("������ڶ�������\n");
        scanf("%lf", &x2);

        switch (m)
        {
        case '+':
            printf("�ӷ�\n");
            result = x1 + x2;
            printf("%lf + %lf = %lf\n", x1, x2, result);
            break;

        case '-':
            printf("����\n");
            result = x1 - x2;
            printf("%lf - %lf = %lf\n", x1, x2, result);
            break;

        case '*':
            printf("�˷�\n");
            result = x1 * x2;
            printf("%lf * %lf = %lf\n", x1, x2, result);
            break;

        case '/':
            printf("����\n");
            if (x2 == 0)
            {
                printf("��������Ϊ0.\n");
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
        printf("�Ƿ����������0�˳�\n");
        scanf("%d", &ttt);
        // cout << "�Ƿ����" << e
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
