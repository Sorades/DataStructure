#include <iostream>
using namespace std;
struct ElemType
{
    int n;
    char x, y, z;
    bool flag;
};

struct linkNode
{
    ElemType data;
    linkNode *next;
};

linkNode *initStack();
void destroyStack(linkNode *&stack);
bool stackEmpty(linkNode *stack);
void push(linkNode *&stack, ElemType e);
bool pop(linkNode *&stack, ElemType &e);
bool getTop(linkNode *stack, ElemType &e);


//��ʼ��ջ
linkNode *initStack()
{
    linkNode *stack = new linkNode;
    stack->next = NULL;
    return stack;
}
//����ջ
void destroyStack(linkNode *&stack)
{
    linkNode *ptr = stack, *p = stack->next;
    while (p != NULL)
    {
        free(ptr);
        ptr = p;
        p = p->next;
    }
    free(ptr);
}
//�ж�ջ�Ƿ��
bool stackEmpty(linkNode *stack)
{
    return stack->next == NULL;
}
//��ջ
void push(linkNode *&stack, ElemType e)
{
    linkNode *node = new linkNode;
    node->data = e;
    node->next = stack->next;
    stack->next = node;
}
//��ջ
bool pop(linkNode *&stack, ElemType &e)
{
    if (stackEmpty(stack))
        return false;
    linkNode *node = stack->next;
    e = node->data;
    stack->next = node->next;
    free(node);
    return true;
}
//ȡջ��
bool getTop(linkNode *stack, ElemType &e)
{
    if (stackEmpty(stack))
        return false;
    e = stack->next->data;
    return true;
}
