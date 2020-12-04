#include <iostream>
#define maxSize 3
using namespace std;
typedef int ElemType;
struct LinearList
{
    ElemType data[maxSize];
    int length;
};

void creatList(LinearList *&L, ElemType a[], int n);
void initList(LinearList *&L);
void destroyList(LinearList *&L);
int linearLength(LinearList *L);
void dispList(LinearList *L);
bool getElem(LinearList *L, int i, ElemType &e);
bool listInsert(LinearList *&L, int i, ElemType e);
int locateElem(LinearList *L, ElemType e);
bool listDelete(LinearList *&L, int i, ElemType &e);

int main()
{

    return 0;
}
//创建线性表
void creatList(LinearList *&L, ElemType a[], int n)
{
    int i = 0, k = 0;
    LinearList *L = new LinearList;
    for (int i = 0, k = 0; i < n; i++, k++)
        L->data[k] = a[i];
    L->length = k;
}
//初始化线性表
void initList(LinearList *&L)
{
    LinearList *L = new LinearList;
    L->length = 0;
}
//销毁线性表
void destroyList(LinearList *&L)
{
    free(L);
}
//返回线性表的长度
int linearLength(LinearList *L)
{
    return (L->length);
}
//输出线性表元素
void dispList(LinearList *L)
{
    for (int i = 0; i < L->length; i++)
        cout << L->data[i];
    cout << endl;
}
//返回某位置的元素
bool getElem(LinearList *L, int i, ElemType &e)
{
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i - 1];
    return true;
}
//在某位置插入元素
bool listInsert(LinearList *&L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1 || L->length == maxSize)
        return false;
    i--;
    for (j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
    return true;
}
//定位某元素
int locateElem(LinearList *L, ElemType e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;
    if (i >= L->length)
        return 0;
    else
    {
        return i + 1;
    }
}
//删除一个元素
bool listDelete(LinearList *&L, int i, ElemType &e)
{
    int j;
    if (i < 1 || i > L->length)
        return false;
    i--;
    e = L->data[i];
    for (int i = 0; i < L->length; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return true;
}