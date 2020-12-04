#include <iostream>
using namespace std;
typedef int ElemType;
struct stack
{
    ElemType *data;
    int maxRoom;
    int top;
};
bool initStack(stack *&s, int maxRoom);
void destroyStack(stack *&s);
bool isStackEmpty(stack *s);
bool isStackFull(stack *s);
bool push(stack *&s, ElemType e);
bool pop(stack *&s, ElemType &e);
bool getTop(stack *s, ElemType &e);

int main()
{

    return 0;
}
//³õÊ¼»¯Õ»
bool initStack(stack *&s, int maxRoom)
{
    if (s)
        return false;
    if ((s = new stack) == NULL)
        return false;
    s->maxRoom = maxRoom;
    s->top = -1;
    return true;
}
//Ïú»ÙÕ»
void destroyStack(stack *&s)
{
    if (s)
    {
        free(s);
    }
}
//ÅÐ¶ÏÕ»ÊÇ·ñ¿Õ
bool isStackEmpty(stack *s)
{
    return s->top == -1;
}
//ÅÐ¶ÏÕ»ÊÇ·ñÂú
bool isStackFull(stack *s)
{
    return s->maxRoom == s->top;
}
//³öÕ»
bool pop(stack *&s, ElemType &e)
{
    if (isStackEmpty(s))
        return false;
    e = s->data[s->top--];
    return true;
}
//½øÕ»
bool push(stack *&s, ElemType e)
{
    s->data[++s->top] = e;
    return true;
}
//È¡Õ»¶¥ÔªËØ
bool getTop(stack *s,ElemType&e){
    if(isStackEmpty(s))
        return false;
    e = s->data[s->top];
    return true;
}