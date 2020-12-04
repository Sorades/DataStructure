#include <iostream>
using namespace std;

template <class ElemType>
struct linkNode
{
    ElemType data;
    linkNode *next;
};

template <typename Elemtype>
linkNode<Elemtype> *initStack();
template <typename Elemtype>
void destroyStack(linkNode<Elemtype> *&stack);
template <typename Elemtype>
bool stackEmpty(linkNode<Elemtype> *stack);
template <typename Elemtype>
void push(linkNode<Elemtype> *stack, Elemtype e);
template <typename Elemtype>
bool pop(linkNode<Elemtype> *stack, Elemtype &e);
template <typename Elemtype>
bool getTop(linkNode<Elemtype> *stack, Elemtype &e);

void getIn(char *exp, char postexp[]);
double calculate(char postexp[]);

int main()
{
    char exp[] = "(56-20)/(4+2)";
    char *postexp = new char;
    getIn(exp, postexp);
    printf("中缀表达式：%s\n", exp);
    printf("后缀表达式：%s\n", postexp);
    cout << "表达式的值：" << calculate(postexp) << endl;
    return 0;
}

//初始化栈
template <typename Elemtype>
linkNode<Elemtype> *initStack()
{
    linkNode<Elemtype> *stack = new linkNode<Elemtype>;
    stack->next = NULL;
    return stack;
}

//销毁栈
template <typename Elemtype>
void destroyStack(linkNode<Elemtype> *&stack)
{
    linkNode<Elemtype> *pre = stack, *p = pre->next;
    while (p != NULL)
    {
        delete pre;
        pre = p;
        p = p->next;
    }
    delete pre;
}

//判断栈是否空
template <typename Elemtype>
bool stackEmpty(linkNode<Elemtype> *stack)
{
    return stack->next == NULL;
}

//进栈
template <typename Elemtype>
void push(linkNode<Elemtype> *stack, Elemtype e)
{
    linkNode<Elemtype> *node = new linkNode<Elemtype>;
    node->data = e;
    node->next = stack->next;
    stack->next = node;
}

//出栈
template <typename Elemtype>
bool pop(linkNode<Elemtype> *stack, Elemtype &e)
{
    if (stackEmpty(stack))
        return false;
    e = stack->next->data;
    linkNode<Elemtype> *node = stack->next;
    stack->next = node->next;
    free(node);
    return true;
}

//取栈顶
template <typename Elemtype>
bool getTop(linkNode<Elemtype> *stack, Elemtype &e)
{
    if (stackEmpty(stack))
        return false;
    e = stack->next->data;
    return true;
}

//转换为后缀表达式
void getIn(char *exp, char *postexp)
{
    char ch = *exp;
    int i = 0; //postexp的下标
    linkNode<char> *opera = initStack<char>();
    while (*exp != '\0')
    {
        switch (*exp)
        {
        case '(': //扫描到（，将其进栈
            push(opera, '(');
            exp++;
            break;
        case ')':
            pop(opera, ch);
            while(ch!='('){
                postexp[i++] = ch;
                pop(opera, ch);
            }
            exp++; //继续扫描
            break;
        case '-':
        case '+':
            while (!stackEmpty(opera))
            {
                getTop(opera, ch); //得到栈顶元素
                if (ch != '(')
                {
                    postexp[i++] = ch; //若栈顶元素非（则存入postexp
                    pop(opera, ch);    //并将其出栈
                }
                else
                    break; //栈顶为（则退出循环
            }
            push(opera, *exp); //将当前+-进栈
            exp++;
            break;
        case '*':
        case '/':
            while (!stackEmpty(opera))
            {
                getTop(opera, ch);
                if (ch == '/' || ch == '*')
                {
                    postexp[i++] = ch; //栈顶的符号优先级不低于当前符号则出栈存入postexp
                    pop(opera, ch);
                }
                else
                    break;
            }
            push(opera, *exp); //当前*/入栈
            exp++;
            break;
        default:
            while (*exp >= '0' && *exp <= '9')
            {
                postexp[i++] = *exp; //数字直接进postexp
                exp++;
            }
            postexp[i++] = '#'; //每个数字之间隔#
            break;
        }
    }
    while (!stackEmpty(opera))
    {
        pop(opera, ch); //保留符号出栈
        postexp[i++] = ch;
    }
    postexp[i] = '\0'; //给字符串赋结尾
    destroyStack(opera);
}

double calculate(char *postexp)
{
    double val, op1, op2, ed;
    linkNode<double> *opnd = initStack<double>();
    while (*postexp != '\0')
    {
        switch (*postexp)
        {
        case '+':
            pop(opnd, op1); //第一个操作数
            pop(opnd, op2); //第二个操作数
            ed = op2 + op1;
            push(opnd, ed); //结果入栈
            break;
        case '-':
            pop(opnd, op1);
            pop(opnd, op2);
            ed = op2 - op1;
            push(opnd, ed);
            break;
        case '*':
            pop(opnd, op1);
            pop(opnd, op2);
            ed = op2 * op1;
            push(opnd, ed);
            break;
        case '/':
            pop(opnd, op1);
            pop(opnd, op2);
            if (op1 != 0)
            {
                ed = op2 / op1;
                push(opnd, ed);
                break;
            }
            else
            {
                cout << "\n除数不能为零！\n";
                exit(0);
            }
        default:
            val = 0;
            while (*postexp >= '0' && *postexp <= '9')
            {
                val = val * 10 + *postexp - '0';
                postexp++;
            }
            push(opnd, val);
            break;
        }
        postexp++;
    }
    getTop(opnd, ed);
    destroyStack(opnd);
    return ed;
}
