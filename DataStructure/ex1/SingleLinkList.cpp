#include <iostream>
using namespace std;

//单链表L
struct Link
{
    int num;
    char lower;
    char upper;
    Link *next;
};
Link *L;

//三种链表的模板
template <class ElemName>
struct List
{
    ElemName elem;
    List *next;
};
//创建有n个节点的链表
Link *creat(int n);

/*将L中的数据写入*/
//int
List<int> *copyInt(int n);
//小写字母
List<char> *copyLow(int n);
//大写字母
List<char> *copyUp(int n);

void outPut(Link *list);
template <typename T>
void outPut(List<T> *list);
Link *outPut(Link *list, int n);

int main()
{
    int length = 0;
    cout << "请输入单链表L初始节点数：";
    cin >> length;
    L = creat(length);
    outPut(L);
    List<int> *listInt = copyInt(length);
    cout << "得到的L1中的数字：\n";
    outPut<int>(listInt);
    List<char> *listLow = copyLow(length);
    cout << "得到的L2中的小写字母：\n";
    outPut<char>(listLow);
    List<char> *listUp = copyUp(length);
    cout << "得到的L3中的大写字母：\n";
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
        cout << "现在开始录入第" << i + 1 << "个节点的信息...\n数字：";
        while (!(cin >> node->num))
        {
            cin.clear();
            cin.sync();
            cout << "输入错误！请输入数字：";
        }
        cout << "小写字母：";

        cin >> node->lower;
        while (!(node->lower >= 'a' && node->lower <= 'z'))
        {
            cout << "输入错误！请输入小写字母：";
            cin >> node->lower;
        }
        cout << "大写字母：";
        cin >> node->upper;
        while (!(node->upper >= 'A' && node->upper <= 'Z'))
        {
            cout << "输入错误！请输入大写字母：";
            cin >> node->upper;
        }
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
//输出全部L
void outPut(Link *list)
{
    Link *h = list;
    int i = 1;
    cout << "现在输出单链表中的信息...\n";
    while (h->next != NULL)
    {
        h = h->next;
        cout << "第" << i << "个节点：" << h->num << "\t" << h->lower << "\t" << h->upper << endl;
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

//输出特定节点
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