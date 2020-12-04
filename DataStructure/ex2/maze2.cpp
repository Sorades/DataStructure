#include <iostream>
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
    int x, y;
    int dir;
};
struct stType
{
    Dot data;
    stType *next;
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
        cout << "该迷宫无解\n";
    return 0;
}

stType *initStack()
{
    stType *head, *end;
    head = new stType;
    end = head;
    return head;
}
void destroyStack(stType *&stack)
{
    stType *pre = stack, *p = stack->next;
    while (pre->next != NULL)
    {
        delete pre;
        pre = p;
        p = p->next;
    }
    delete pre;
}
bool stackEmpty(stType *stack)
{
    return stack->next == NULL;
}
void push(stType *stack, Dot temp)
{
    stType *node = new stType;
    node->data.x = temp.x;
    node->data.y = temp.y;
    node->data.dir = temp.dir;
    node->next = stack->next;
    stack->next = node;
}
bool pop(stType *stack, Dot &temp)
{
    if (stackEmpty(stack))
        return false;
    stType *node = stack;
    temp.x = stack->next->data.x;
    temp.y = stack->next->data.y;
    temp.dir = stack->next->data.dir;
    stack->next = node->next;
    delete node;
    return true;
}
bool getTop(stType *stack, Dot &temp)
{
    if (stackEmpty(stack))
        return false;
    temp.x = stack->next->data.x;
    temp.y = stack->next->data.y;
    temp.dir = stack->next->data.dir;
    return true;
}
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
            cout << "迷宫路径如下：";
            int count = 0;
            while (!stackEmpty(stack))
            {
                pop(stack, block);
                path[count++] = block;
            }
            while (count >= 1)
            {
                count--;
                cout << "(" << path[count].x << "," << path[count].y << ")" << endl;
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
            stack->next->data.dir = dir;
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