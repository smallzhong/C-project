#include "head.h"
bool flag = false; //������¼�Ƿ��Ѿ������е����ݶ��벢������û�б�����,��ֹ�ظ���ȡ�˷�ʱ��
int lines;         //������¼��ǰ���ļ��еļ�¼������
FILE *fp_lines;
char txt1[] = "1.txt";
struct Node nodes[N];
int main()
{
    char title[] = "\t\t\t*********��ӭ������˲�ϵͳ��********\n\n\n";
    initWindow(title);
    fp_lines = fopen("line.txt", "r");
    if (fp_lines == NULL)
    {
        FILE *tfp;
        tfp = fopen("line.txt", "w");
        fprintf(tfp, "0");
        printf("=====================\n");
        printf("��⵽���ǵ�һ��ʹ�øó�����Ϊ���Զ����ɼ�¼�ļ�\n");
        printf("=====================\n");
        FILE *tfp2;
        tfp2 = fopen("1.txt", "wb");
        fclose(tfp2);
        fp_lines = fopen("line.txt", "r");
        if (fp_lines == NULL)
        {
            fprintf(stderr, "��line.txtʱ���ִ���");
            perror("line.txt: ");
            system("pause");
            exit(EXIT_FAILURE);
        }
    }
    fscanf(fp_lines, "%d", &lines);
    while (1)
    {
        start_print(); //start_print��������չʾ��������
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
            printf("������һ�����ڣ���ʽ��20191208��ʾ���м�û�зָ���:");
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
                printf("����������Ҫɾ��������:");
                scanf("%d", &templine);
                if (templine <= 0 || templine > lines)
                {
                    printf("�������벻�Ϸ���Ӧ������һ��1~%d֮�����������������\n", lines);
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
            cout << "���ǵĳ�Ա��" << endl;
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
            // char farewell = "�ټ�����ӭ�ٴ�ʹ�ñ�����ϵͳ"
            char tempstring[] = "\t\t\t*********�ټ�����ӭ�ٴ�ʹ�ñ�����ϵͳ********\n\n\n";
            char *farewell = tempstring;
            while (*farewell != 0)
            {
                //����ַ�ָ����ָ�������
                printf("%c", *farewell);
                //��ָ��ָ����һ���ַ�
                farewell++;
                //����
            }
            break;
        }
        else
        {
            // printf("��������ȷ��ָ��\n");
            // ���������pause֮����յ��س���������,��ע�͵�
        }
    }
    return 0;
}
