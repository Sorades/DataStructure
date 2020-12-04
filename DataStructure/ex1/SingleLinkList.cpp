#include <iostream>
using namespace std;

//������L
struct Link
{
    int num;
    char lower;
    char upper;
    Link *next;
};
Link *L;

//���������ģ��
template <class ElemName>
struct List
{
    ElemName elem;
    List *next;
};
//������n���ڵ������
Link *creat(int n);

/*��L�е�����д��*/
//int
List<int> *copyInt(int n);
//Сд��ĸ
List<char> *copyLow(int n);
//��д��ĸ
List<char> *copyUp(int n);

void outPut(Link *list);
template <typename T>
void outPut(List<T> *list);
Link *outPut(Link *list, int n);

int main()
{
    int length = 0;
    cout << "�����뵥����L��ʼ�ڵ�����";
    cin >> length;
    L = creat(length);
    outPut(L);
    List<int> *listInt = copyInt(length);
    cout << "�õ���L1�е����֣�\n";
    outPut<int>(listInt);
    List<char> *listLow = copyLow(length);
    cout << "�õ���L2�е�Сд��ĸ��\n";
    outPut<char>(listLow);
    List<char> *listUp = copyUp(length);
    cout << "�õ���L3�еĴ�д��ĸ��\n";
    outPut<char>(listUp);
    return 0;
}

Link *creat(int n)
{
    Link *head, *node, *end;
    head = new Link;
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = new Link;
        cout << "���ڿ�ʼ¼���" << i + 1 << "���ڵ����Ϣ...\n���֣�";
        while (!(cin >> node->num))
        {
            cin.clear();
            cin.sync();
            cout << "����������������֣�";
        }
        cout << "Сд��ĸ��";

        cin >> node->lower;
        while (!(node->lower >= 'a' && node->lower <= 'z'))
        {
            cout << "�������������Сд��ĸ��";
            cin >> node->lower;
        }
        cout << "��д��ĸ��";
        cin >> node->upper;
        while (!(node->upper >= 'A' && node->upper <= 'Z'))
        {
            cout << "��������������д��ĸ��";
            cin >> node->upper;
        }
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
//���ȫ��L
void outPut(Link *list)
{
    Link *h = list;
    int i = 1;
    cout << "��������������е���Ϣ...\n";
    while (h->next != NULL)
    {
        h = h->next;
        cout << "��" << i << "���ڵ㣺" << h->num << "\t" << h->lower << "\t" << h->upper << endl;
    }
}
template <typename T>
void outPut(List<T> *h)
{
    while (h->next != NULL)
    {
        h = h->next;
        cout << h->elem << "\t";
    }
    cout << endl;
}

//����ض��ڵ�
Link *outPut(Link *list, int n)
{
    Link *t = list;
    int i = 0;
    while (i < n && t != NULL)
    {
        t = t->next;
        i++;
    }
    if (t != NULL)
        return t;
}

List<int> *copyInt(int n)
{
    List<int> *head, *node, *end;
    head = new List<int>;
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = new List<int>;
        node->elem = outPut(L, i + 1)->num;
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
List<char> *copyLow(int n)
{
    List<char> *head, *node, *end;
    head = new List<char>;
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = new List<char>;
        node->elem = outPut(L, i + 1)->lower;
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
List<char> *copyUp(int n)
{
    List<char> *head, *node, *end;
    head = new List<char>;
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = new List<char>;
        node->elem = outPut(L, i + 1)->upper;
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}