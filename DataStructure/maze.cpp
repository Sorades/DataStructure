#include <iostream>
#define maxSize 199
using namespace std;
const int Row = 8, Col = 8;
int maze[Row + 2][Col + 2] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

struct Dot
{
    int x;
    int y;
    /*���壬dir��ʾ��һ���ķ���
    *�ϣ�0���ң�1���£�2����3
    */
    int dir;
};
struct stType
{
    Dot data[maxSize];
    int top;
};

stType *initStack();
void destroyStack(stType *&stack);
bool stackEmpty(stType *stack);
void push(stType *stack, Dot temp);
bool pop(stType *stack, Dot &temp);
bool getTop(stType *stack, Dot &temp);

bool path(int startX, int startY, int endX, int endY);

int main()
{
    if (!path(1, 1, Row, Col))
        cout << "���Թ������޽�";
    return 0;
}

//��ʼ��ջ
stType *initStack()
{
    stType *head = new stType;
    //head->data = new Dot;
    head->top = -1;
    return head;
}
//����ջ
void destroyStack(stType *&stack)
{
    if (!stackEmpty(stack))
        delete stack;
}
//�ж�ջ�Ƿ��
bool stackEmpty(stType *stack)
{
    return stack->top == -1;
}
//��ջ
void push(stType *stack, Dot temp)
{
    stack->top++;
    stack->data[stack->top].x = temp.x;
    stack->data[stack->top].y = temp.y;
    stack->data[stack->top].dir = temp.dir;
}
//��ջ
bool pop(stType *stack, Dot &temp)
{
    if (stackEmpty(stack))
        return false;
    temp.x = stack->data[stack->top].x;
    temp.y = stack->data[stack->top].y;
    temp.dir = stack->data[stack->top].dir;
    stack->top--;
    return true;
}
//ȡջ��
bool getTop(stType *stack, Dot &temp)
{
    if (stackEmpty(stack))
        return false;
    temp.x = stack->data[stack->top].x;
    temp.y = stack->data[stack->top].y;
    temp.dir = stack->data[stack->top].dir;
    return true;
}

//��start X��start Y��endX��endY
bool path(int startX, int startY, int endX, int endY)
{
    Dot *path = new Dot;
    Dot block;
    stType *stack = initStack();
    int x, y, dir;
    int x0, y0;
    bool next;
    block.x = startX;
    block.y = startY;
    block.dir = -1;
    push(stack, block);
    maze[startX][startY] = -1;
    while (!stackEmpty(stack))
    {
        getTop(stack, block);
        x = block.x;
        y = block.y;
        dir = block.dir;
        if (x == endX && y == endY)
        {
            cout << "�Թ�·�����£�\n";
            int count = 0;
            while (!stackEmpty(stack))
            {
                pop(stack, block);
                path[count].x = block.x;
                path[count].y = block.y;
                path[count].dir = block.dir;
                count++;
            }
            while (count >= 1)
            {
                count--;
                cout << "\t(" << path[count].x << "," << path[count].y << ")" << endl;
            }
            destroyStack(stack);
            return true;
        }
        next = false;
        while (dir < 4 && !next)
        {
            dir++;
            switch (dir)
            {
            case 0:
                x0 = x - 1;
                y0 = y;
                break;
            case 1:
                x0 = x;
                y0 = y + 1;
                break;
            case 2:
                x0 = x + 1;
                y0 = y;
                break;
            case 3:
                x0 = x;
                y0 = y - 1;
                break;
            }
            if (maze[x0][y0] == 0)
                next = true;
        }
        if (next)
        {
            stack->data[stack->top].dir = dir;
            block.x = x0;
            block.y = y0;
            block.dir = -1;
            push(stack, block);
            maze[x0][y0] = -1;
        }
        else
        {
            pop(stack, block);
            maze[block.x][block.y] = 0;
        }
    }
    destroyStack(stack);
    return false;
}
