#include "stack.h"
#include <iostream>
using namespace std;
void hanoi(int n, char x, char y, char z);

int main()
{
    int n;
    cout << "汉诺塔--栈解\n请输入盘子个数：";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
void hanoi(int n, char x, char y, char z)
{
    linkNode *stack = initStack();
    ElemType elem, elem1, elem2, elem3;
    int count = 0;
    if (n <= 0)
        return;
    elem.n = n, elem.x = x, elem.y = y, elem.z = z, elem.flag = false;
    push(stack, elem);
    while (!stackEmpty(stack))
    {
        pop(stack, elem);
        if (elem.flag == false)
        {
            elem1.n = elem.n - 1, elem1.x = elem.y, elem1.y = elem.x, elem1.z = elem.z;
            if (elem1.n == 1)
                elem1.flag = true;
            else
                elem1.flag = false;
            push(stack, elem1);
            elem2.n = elem.n, elem2.x = elem.x, elem2.y = elem.y, elem2.z = elem.z;
            elem2.flag = true;
            push(stack, elem2);
            elem3.n = elem.n - 1, elem3.x = elem.x, elem3.y = elem.z, elem3.z = elem.y;
            if (elem3.n == 1)
                elem3.flag = true;
            else
                elem3.flag = false;
            push(stack, elem3);
        }
        else
        {
            cout << "第" << elem.n << "个盘：" << elem.x << " → " << elem.z << endl;
            count++;
        }
    }
    cout << "总共" << count << "步\n";
}
