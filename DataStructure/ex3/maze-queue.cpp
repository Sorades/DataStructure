#include <iostream>
#define maxSize 999
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

struct Box
{
    int x, y;
    int pre;
};

typedef Box ElemType;

struct QuType
{
    ElemType data[maxSize];
    int front, rear;
};

void initQueue(QuType *&queue);
void destroyQueue(QuType *&queue);
bool isEmpty(QuType *queue);
bool enQueue(QuType *&queue, ElemType elem);
bool deQueue(QuType *&queue, ElemType &elem);

bool mazepath(int startX, int startY, int endX, int endY);
void printPath(QuType *queue, int front);

int main()
{
    if (!mazepath(1, 1, Row, Col))
        cout << "该迷宫没有解\n";
    return 0;
}

void initQueue(QuType *&queue)
{
    queue = new QuType;
    queue->front = queue->rear = -1;
}
void destroyQueue(QuType *&queue)
{
    delete queue;
}
bool isEmpty(QuType *queue)
{
    return (queue->front == queue->rear);
}
bool enQueue(QuType *&queue, ElemType elem)
{
    if (queue->rear == maxSize - 1)
        return false;
    queue->rear++;
    queue->data[queue->rear] = elem;
    return true;
}
bool deQueue(QuType *&queue, ElemType &elem)
{
    if (isEmpty(queue))
        return false;
    queue->front++;
    elem = queue->data[queue->front];
    return true;
}

bool mazepath(int startX, int startY, int endX, int endY)
{
    Box block;
    QuType *queue;
    initQueue(queue);
    block.x = startX;
    block.y = startY;
    block.pre = -1;
    enQueue(queue, block);
    maze[startX][startY] = -1;
    int x, y, dir;
    int x0, y0;
    while (!isEmpty(queue))
    {
        deQueue(queue, block);
        x = block.x;
        y = block.y;
        if (x == endX && y == endY)
        {
            printPath(queue, queue->front);
            destroyQueue(queue);
            return true;
        }
        for (dir = 0; dir < 4; dir++)
        {
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
            {
                block.x = x0;
                block.y = y0;
                block.pre = queue->front;
                enQueue(queue, block);
                maze[x0][y0] = -1;
            }
        }
    }
    destroyQueue(queue);
    return false;
}

void printPath(QuType *queue, int front)
{
    cout << endl;
    int flag;
    do
    {
        flag = front;
        front = queue->data[flag].pre;
        queue->data[flag].pre = -1;
    } while (front != 0);
    cout << "迷宫路径如下：\n";
    while (front < maxSize)
    {
        if (queue->data[front].pre == -1)
            cout << "\t(" << queue->data[front].x << "," << queue->data[front].y << ")\n";
        front++;
    }
}
