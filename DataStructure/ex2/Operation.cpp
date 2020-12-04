#include <iostream>
using namespace std;
typedef char ElemType;
struct linkNode
{
    ElemType data;
    linkNode *next;
};

void initStack(linkNode *&stack);
void destroyStack(linkNode *&stack);
bool stackEmpty(linkNode *stack);
void push(linkNode *&stack, ElemType e);
bool pop(linkNode *&stack, ElemType &e);
bool getTop(linkNode *stack, ElemType &e);

void getIn(char *exp, char postexp[]);
double calculate(char postexp[]);

int main()
{

    return 0;
}

//��ʼ��ջ
void initStack(linkNode *&stack)
{
    stack = new linkNode;
    stack->next = NULL;
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

//ת��Ϊ��׺���ʽ
void getIn(char *exp, char postexp[])
{
    char ch = *exp;
    int i = 0;
    linkNode *opera;
    initStack(opera);
    while (exp != '\0')
    {
        switch (*exp)
        {
            //������������ջ
        case '(':
            push(opera, '('); //����ջ
            exp++;
            break;
            //��������ջ�У�ǰ��Ԫ�س�ջ���Ž�postexp
        case ')':
            do
            {
                pop(opera, ch);
                postexp[i++] = ch;
            } while (ch != '(');
            exp++;
            break;
        case '-':
        case '+':
            //+-����ջ��Ԫ�س�ջ��ֱ����������ջ��
            while (!stackEmpty(opera))
            {
                getTop(opera, ch);
                if (ch != '(')
                {
                    postexp[i++] = ch;
                    pop(opera, ch);
                }
                else
                    break;
            }
            //����ǰ+-��ջ
            push(opera, *exp);
            exp++;
            break;
        case '/':
        case '*':
            //��ջ��Ϊ/*��ջ��Ԫ�س�ջ����postexp
            while (!stackEmpty(opera))
            {
                getTop(opera, ch);
                if (ch == '/' || ch == '*')
                {
                    postexp[i++] = ch;
                    pop(opera, ch);
                }
                else
                    break;
                //����ǰ*/��ջ
                push(opera, *exp);
                exp++;
                break;
            }
        default:
            //��������
            while (*exp >= '0' && *exp <= '9')
            {
                postexp[i++] = *exp;
                exp++;
            }
            postexp[i++] = '#';//ÿ�����ּ��#
            while (!stackEmpty(opera))
            {
                pop(opera, ch);
                postexp[i++] = ch;
            }
            postexp[i] = '\0';
            destroyStack(opera);

            break;
        }
    }
}

//��׺���ʽ����
double calculate(char postexp[]){
    linkNode *opnd;

}