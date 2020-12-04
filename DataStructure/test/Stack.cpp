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
//��ʼ��ջ
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
//����ջ
void destroyStack(stack *&s)
{
    if (s)
    {
        free(s);
    }
}
//�ж�ջ�Ƿ��
bool isStackEmpty(stack *s)
{
    return s->top == -1;
}
//�ж�ջ�Ƿ���
bool isStackFull(stack *s)
{
    return s->maxRoom == s->top;
}
//��ջ
bool pop(stack *&s, ElemType &e)
{
    if (isStackEmpty(s))
        return false;
    e = s->data[s->top--];
    return true;
}
//��ջ
bool push(stack *&s, ElemType e)
{
    s->data[++s->top] = e;
    return true;
}
//ȡջ��Ԫ��
bool getTop(stack *s,ElemType&e){
    if(isStackEmpty(s))
        return false;
    e = s->data[s->top];
    return true;
}