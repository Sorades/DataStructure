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

//初始化栈
void initStack(linkNode *&stack)
{
    stack = new linkNode;
    stack->next = NULL;
}
//销毁栈
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
//判断栈是否空
bool stackEmpty(linkNode *stack)
{
    return stack->next == NULL;
}
//进栈
void push(linkNode *&stack, ElemType e)
{
    linkNode *node = new linkNode;
    node->data = e;
    node->next = stack->next;
    stack->next = node;
}
//出栈
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
//取栈顶
bool getTop(linkNode *stack, ElemType &e)
{
    if (stackEmpty(stack))
        return false;
    e = stack->next->data;
    return true;
}

//转换为后缀表达式
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
            //遇（，将（进栈
        case '(':
            push(opera, '('); //（进栈
            exp++;
            break;
            //遇），将栈中（前的元素出栈，放进postexp
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
            //+-，将栈顶元素出栈，直到遇（，或栈空
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
            //将当前+-进栈
            push(opera, *exp);
            exp++;
            break;
        case '/':
        case '*':
            //若栈顶为/*则将栈顶元素出栈存入postexp
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
                //将当前*/入栈
                push(opera, *exp);
                exp++;
                break;
            }
        default:
            //处理数字
            while (*exp >= '0' && *exp <= '9')
            {
                postexp[i++] = *exp;
                exp++;
            }
            postexp[i++] = '#';//每个数字间隔#
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

//后缀表达式计算
double calculate(char postexp[]){
    linkNode *opnd;

}