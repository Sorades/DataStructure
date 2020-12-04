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
    printf("��׺���ʽ��%s\n", exp);
    printf("��׺���ʽ��%s\n", postexp);
    cout << "���ʽ��ֵ��" << calculate(postexp) << endl;
    return 0;
}

//��ʼ��ջ
template <typename Elemtype>
linkNode<Elemtype> *initStack()
{
    linkNode<Elemtype> *stack = new linkNode<Elemtype>;
    stack->next = NULL;
    return stack;
}

//����ջ
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

//�ж�ջ�Ƿ��
template <typename Elemtype>
bool stackEmpty(linkNode<Elemtype> *stack)
{
    return stack->next == NULL;
}

//��ջ
template <typename Elemtype>
void push(linkNode<Elemtype> *stack, Elemtype e)
{
    linkNode<Elemtype> *node = new linkNode<Elemtype>;
    node->data = e;
    node->next = stack->next;
    stack->next = node;
}

//��ջ
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

//ȡջ��
template <typename Elemtype>
bool getTop(linkNode<Elemtype> *stack, Elemtype &e)
{
    if (stackEmpty(stack))
        return false;
    e = stack->next->data;
    return true;
}

//ת��Ϊ��׺���ʽ
void getIn(char *exp, char *postexp)
{
    char ch = *exp;
    int i = 0; //postexp���±�
    linkNode<char> *opera = initStack<char>();
    while (*exp != '\0')
    {
        switch (*exp)
        {
        case '(': //ɨ�赽���������ջ
            push(opera, '(');
            exp++;
            break;
        case ')':
            pop(opera, ch);
            while(ch!='('){
                postexp[i++] = ch;
                pop(opera, ch);
            }
            exp++; //����ɨ��
            break;
        case '-':
        case '+':
            while (!stackEmpty(opera))
            {
                getTop(opera, ch); //�õ�ջ��Ԫ��
                if (ch != '(')
                {
                    postexp[i++] = ch; //��ջ��Ԫ�طǣ������postexp
                    pop(opera, ch);    //�������ջ
                }
                else
                    break; //ջ��Ϊ�����˳�ѭ��
            }
            push(opera, *exp); //����ǰ+-��ջ
            exp++;
            break;
        case '*':
        case '/':
            while (!stackEmpty(opera))
            {
                getTop(opera, ch);
                if (ch == '/' || ch == '*')
                {
                    postexp[i++] = ch; //ջ���ķ������ȼ������ڵ�ǰ�������ջ����postexp
                    pop(opera, ch);
                }
                else
                    break;
            }
            push(opera, *exp); //��ǰ*/��ջ
            exp++;
            break;
        default:
            while (*exp >= '0' && *exp <= '9')
            {
                postexp[i++] = *exp; //����ֱ�ӽ�postexp
                exp++;
            }
            postexp[i++] = '#'; //ÿ������֮���#
            break;
        }
    }
    while (!stackEmpty(opera))
    {
        pop(opera, ch); //�������ų�ջ
        postexp[i++] = ch;
    }
    postexp[i] = '\0'; //���ַ�������β
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
            pop(opnd, op1); //��һ��������
            pop(opnd, op2); //�ڶ���������
            ed = op2 + op1;
            push(opnd, ed); //�����ջ
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
                cout << "\n��������Ϊ�㣡\n";
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
