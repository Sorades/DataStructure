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


//³õÊ¼»¯Õ»
linkNode *initStack()
{
    linkNode *stack = new linkNode;
    stack->next = NULL;
    return stack;
}
//Ïú»ÙÕ»
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
//ÅĞ¶ÏÕ»ÊÇ·ñ¿Õ
bool stackEmpty(linkNode *stack)
{
    return stack->next == NULL;
}
//½øÕ»
void push(linkNode *&stack, ElemType e)
{
    linkNode *node = new linkNode;
    node->data = e;
    node->next = stack->next;
    stack->next = node;
}
//³öÕ»
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
//È¡Õ»¶¥
bool getTop(linkNode *stack, ElemType &e)
{
    if (stackEmpty(stack))
        return false;
    e = stack->next->data;
    return true;
}
