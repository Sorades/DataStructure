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

//历遍栈中元素，判断当前位置是否满足条件
bool posJudge(StackType *stack, Data elem);
//求解n皇后
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
//判断坐标是否符合
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
//求解n皇后
void func()
{
    StackType *stack = initStack();
    bool find = false;//find值表明当前行是否找到可选坐标
    int num = 0;
    cout << "n皇后问题求解(n<20)...\nn:";
    cin >> n;
    Data elem, flag;//elem存当前皇后坐标，flag存上一个皇后的坐标用于回退
    flag.x = flag.y = 1;
    for (int i = 1; i <= n && i > 0; i++)//最后i<0时退出循环
    {
        elem.x = i;
        for (int j = flag.y; j <= n; j++)
        {
            elem.y = j;
            if (posJudge(stack, elem))
            {
                push(stack, elem);//将满足的坐标进栈
                flag = elem;
                find = true;//找到
                break;
            }
        }
        if (find)//找到时，num+1，将列数调回1
        {
            num++;
            find = false;
            if (num == n)//num=n时，找到其中一种解法
            {
                count++;
                cout << "第" << count << "个解：";
                num -= 2;
                output(stack);
                cout << endl;
                i -= 2;
                pop(stack, flag);
                pop(stack, flag);//退回上一行的坐标
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
