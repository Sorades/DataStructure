#include <iostream>
#define maxCol 10
using namespace std;
typedef int ElemType;
struct listHead
{
    int raw, col;
    struct listNode *next;
};
struct listNode
{
    ElemType data[maxCol];
    listNode *next;
};

void creatTable(listHead *&h);
void destroyTable(listHead *&h);
void dispTable(listHead *h);
void linkTable(listHead *&h, listHead *h1, listHead *h2);

int main()
{
    listHead *h1, *h2, *h;
    cout << "��1��\n";
    creatTable(h1);
    cout << "��2��\n";
    creatTable(h2);
    linkTable(h, h1, h2);
    cout << "������Ӻ�ı�\n";
    dispTable(h);
    destroyTable(h);
    destroyTable(h1);
    destroyTable(h2);
    return 0;
}
//�������Ա�
void creatTable(listHead *&h)
{
    listHead *head = new listHead;
    head->next = NULL;
    listNode *node, *end;
    cout << "������Ҫ���������Ա��������";
    cin >> head->raw;
    cout << "������";
    cin >> head->col;
    cout << "���·��������Ա�����ݣ�\n";
    for (int i = 0; i < head->raw; i++)
    {
        cout << "��" << i + 1 << "�У�";
        node = new listNode;
        for (int j = 0; j < head->col; j++)
            cin >> node->data[j];
        if (head->next == NULL)
            head->next = node;
        else
            end->next = node;
        end = node;
    }
    end->next = NULL;
    h = head;
}
//�������Ա�
void destroyTable(listHead *&h)
{
    listNode *ptr = h->next, *p = ptr->next;
    while (p != NULL)
    {
        free(ptr);
        ptr = p;
        p = p->next;
    }
    free(ptr);
    free(h);
}
//������Ա�
void dispTable(listHead *h)
{
    listNode *p = h->next;
    while (p != NULL)
    {
        for (int i = 0; i < h->col; i++)
            cout << p->data[i] << "\t";
        cout << endl;
        p = p->next;
    }
}
//����Ȼ�������Ա�
void linkTable(listHead *&h, listHead *h1, listHead *h2)
{
    listNode *listPtr1, *listPtr2, *node, *end;
    listPtr1 = h1->next;
    cout << "�����ֶ��ǣ�\n��һ������ţ�";
    int i, j;
    cin >> i;
    cout << "�ڶ�������ţ�";
    cin >> j;
    listHead *head = new listHead;
    head->raw = 0;
    head->col = h1->col + h2->col;
    head->next = NULL;
    while (listPtr1 != NULL)
    {
        listPtr2 = h2->next;
        while (listPtr2 != NULL)
        {
            if (listPtr1->data[i - 1] == listPtr2->data[j - 1])
            {
                node = new listNode;
                for (int k = 0; k < h1->col; k++)
                    node->data[k] = listPtr1->data[k];
                for (int k = 0; k < h2->col; k++)
                    node->data[h1->col + k] = listPtr2->data[k];
                if (head->next == NULL)
                    head->next = node;
                else
                    end->next = node;
                end = node;
                head->raw++;
            }
            listPtr2 = listPtr2->next;
        }
        listPtr1 = listPtr1->next;
    }
    end->next = NULL;
    h = head;
}