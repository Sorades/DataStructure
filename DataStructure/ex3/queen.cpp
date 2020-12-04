#include <iostream>
using namespace std;
typedef int elemType;

struct Data
{
    elemType x;
    elemType y;
};

struct StackType
{
    Data data;
    StackType *next;
};

int n, count = 0;

StackType *initStack();
void destroyStack(StackType *&stack);
bool isEmpty(StackType *stack);
void push(StackType *&stack, Data elem);
bool pop(StackType *&stack, Data &elem);
Data getTop(StackType *stack);
void output(StackType *stack);

//����ջ��Ԫ�أ��жϵ�ǰλ���Ƿ���������
bool posJudge(StackType *stack, Data elem);
//���n�ʺ�
void func();

int main()
{
    func();
    return 0;
}

StackType *initStack()
{
    StackType *stack = new StackType;
    stack->next = NULL;
    return stack;
}
void destroyStack(StackType *&stack)
{
    StackType *pre = stack, *p = pre->next;
    while (p != NULL)
    {
        delete pre;
        pre = p;
        p = p->next;
    }
    delete pre;
}
bool isEmpty(StackType *stack)
{
    return stack->next == NULL;
}
void push(StackType *&stack, Data elem)
{
    StackType *node = new StackType;
    node->data.x = elem.x;
    node->data.y = elem.y;
    node->next = stack->next;
    stack->next = node;
}
bool pop(StackType *&stack, Data &elem)
{
    if (isEmpty(stack))
        return false;
    StackType *node = stack->next;
    elem.x = node->data.x;
    elem.y = node->data.y;
    stack->next = node->next;
    delete node;
    return true;
}
Data getTop(StackType *stack)
{
    if (isEmpty(stack))
        exit(1);
    Data elem;
    elem.x = stack->next->data.x;
    elem.y = stack->next->data.y;
    return elem;
}
void output(StackType *stack)
{
    StackType *node = stack;
    while (node->next != NULL)
    {
        node = node->next;
        cout << "(" << node->data.x << "," << node->data.y << ")\t";
    }
}
//�ж������Ƿ����
bool posJudge(StackType *stack, Data elem)
{
    StackType *node = stack;
    while (node->next != NULL)
    {
        node = node->next;
        if (elem.x == node->data.x || elem.y == node->data.y || (elem.x + elem.y) == (node->data.x + node->data.y) || (elem.x - elem.y) == (node->data.x - node->data.y))
            return false;
    }
    return true;
}
//���n�ʺ�
void func()
{
    StackType *stack = initStack();
    bool find = false;//findֵ������ǰ���Ƿ��ҵ���ѡ����
    int num = 0;
    cout << "n�ʺ��������(n<20)...\nn:";
    cin >> n;
    Data elem, flag;//elem�浱ǰ�ʺ����꣬flag����һ���ʺ���������ڻ���
    flag.x = flag.y = 1;
    for (int i = 1; i <= n && i > 0; i++)//���i<0ʱ�˳�ѭ��
    {
        elem.x = i;
        for (int j = flag.y; j <= n; j++)
        {
            elem.y = j;
            if (posJudge(stack, elem))
            {
                push(stack, elem);//������������ջ
                flag = elem;
                find = true;//�ҵ�
                break;
            }
        }
        if (find)//�ҵ�ʱ��num+1������������1
        {
            num++;
            find = false;
            if (num == n)//num=nʱ���ҵ�����һ�ֽⷨ
            {
                count++;
                cout << "��" << count << "���⣺";
                num -= 2;
                output(stack);
                cout << endl;
                i -= 2;
                pop(stack, flag);
                pop(stack, flag);//�˻���һ�е�����
                flag.y++;
                continue;
            }
            flag.y = 1;
        }
        else
        {
            i -= 2;
            pop(stack, flag);
            num--;
            flag.y++;
        }
    }
}
