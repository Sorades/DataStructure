#include <iostream>
using namespace std;

struct SqString
{
    char data;
    SqString *next;
};
SqString *strAssign(char cstr[]);
void destroyStr(SqString *&str);
void strCopy(SqString *&str, SqString *matrix);
bool isEqual(SqString *str1, SqString *str2);
int strLength(SqString *str);
SqString *connect(SqString *str1, SqString *str2);
SqString *subStr(SqString *str, int front, int num);
SqString *insStr(SqString *str1, int index, SqString *str2);
SqString *delStr(SqString *str, int front, int num);
SqString *repStr(SqString *str1, int front, int num, SqString *str2);
void dispStr(SqString *str);

SqString *strAssign(char cstr[])
{
    SqString *head, *node, *end;
    head = new SqString;
    end = head;
    for (int i = 0; cstr[i] != '\0'; i++)
    {
        node = new SqString;
        node->data = cstr[i];
        end->next = node;
        end = node;
    }
    end->next = NULL;
}
void destroyStr(SqString *&str)
{
    SqString *pre = str, *p = pre->next;
    while (p != NULL)
    {
        delete pre;
        pre = p;
        p = pre->next;
    }
    delete pre;
}
void strCopy(SqString *&str, SqString *matrix)
{
    SqString *ptr = matrix->next, *node, *end;
    str = new SqString;
    end = str;
    while (ptr != NULL)
    {
        node = new SqString;
        node->data = ptr->data;
        end->next = node;
        end = node;
        ptr = ptr->next;
    }
    end->next = NULL;
}
bool isEqual(SqString *str1, SqString *str2)
{
    SqString *ptr1 = str1->next, *ptr2 = str2->next;
    while (ptr1 != NULL && ptr2 != NULL && ptr1->data == ptr2->data)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr1 == NULL && ptr2 == NULL)
        return true;
    else
        return false;
}
int strLength(SqString *str)
{
    int len = 0;
    SqString *ptr = str->next;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    return len;
}
SqString *connect(SqString *str1, SqString *str2)
{
    SqString *str, *node, *end, *ptr = str1->next;
    str = new SqString;
    end = str;
    while (ptr != NULL)
    {
        node = new SqString;
        node->data = ptr->data;
        end->next = node;
        end = node;
        ptr = ptr->next;
    }
    ptr = str2->next;
    while (ptr != NULL)
    {
        node = new SqString;
        node->data = ptr->data;
        end->next = node;
        end = node;
        ptr = ptr->next;
    }
    node->next = NULL;
}
SqString *subStr(SqString *str, int front, int num)
{
    SqString *head, *node, *end, *ptr = str->next;
    head = new SqString;
    head->next = NULL;
    end = head;
    if (front <= 0 || front > strLength(str) || num < 0 || front + num - 1 > strLength(str))
        return str;
    for (int i = 0; i < front; i++)
        ptr = ptr->next;
    for (int i = 0; i < num; i++)
    {
        node = new SqString;
        node->data = ptr->data;
        end->next = node;
        end = node;
        ptr = ptr->next;
    }
    end->next = NULL;
    return head;
}
SqString *insStr(SqString *str1, int index, SqString *str2)
{
    SqString *str, *node, *end, *ptr1, *ptr2;
    str = new SqString;
    str->next = NULL;
    if (index <= 0 || index > strLength(str1) + 1)
        return str;
    for (int i = 1; i < index; i++)
    {
        node = new SqString;
        node->data = ptr1->data;
        end->next = node;
        end = node;
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        node = new SqString;
        node->data = ptr2->data;
        end->next = node;
        end = node;
        ptr2 = ptr2->next;
    }
    while (ptr1 != NULL)
    {
        node = new SqString;
        node->data = ptr1->data;
        end->next = node;
        end = node;
        ptr1 = ptr1->next;
    }
    end->next = NULL;
}
SqString *delStr(SqString *str, int front, int num)
{
    SqString *head, *node, *ptr = str->next, *temp;
    head = new SqString;
    head->next = NULL;
    if (front <= 0 || num > strLength(str) || num < 0 || front + num - 1 > strLength(str))
        return head;
    //定位到front前一位
    for (int i = 2; i < front; i++)
        ptr = ptr->next;
    temp = ptr; //暂时存储front前一位
    head->next = ptr->next;
    for (int i = 0; i < num; i++)
        ptr = ptr->next;
    temp->next = ptr->next;
    ptr->next = NULL;
    return head;
}
SqString *repStr(SqString *str1, int front, int num, SqString *str2)
{
    SqString *head, *node, *end, *temp1, *temp2, *ptr1 = str1->next, *ptr2 = str2->next;
    head = new SqString;
    end = head;
    head->next = NULL;
    if (front <= 0 || front > strLength(str1) || num < 0 || num != strLength(str2) || front + num - 1 > strLength(str1))
        return head;
    for (int i = 2; i < front; i++)
        ptr1 = ptr1->next;
    head->next = ptr1->next; //存入head
    temp1 = ptr1;            //记录front前一位
    for (int i = 0; i <= num; i++)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    temp2 = ptr1->next; //记录字串后的地址
    temp1->next = str2->next;
    ptr2->next = temp2;
    ptr1->next = NULL;
    return head;
}
void dispStr(SqString *str)
{
    SqString *ptr = str->next;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr->next = ptr;
    }
}