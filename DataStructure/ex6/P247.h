#include <iostream>
#define maxSize 100
using namespace std;

typedef char elemType;

struct binaryT
{
    elemType data;
    binaryT *lChild;
    binaryT *rChild;
};

struct Queue
{
    binaryT *btData[maxSize];
    int front, rear;
};
char bt[] = {"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"};
binaryT *creatBTree(char *str)
{
    binaryT *stack[maxSize], *ptr;
    int top = -1, index = 0, dir;
    char ch = str[index];
    binaryT *btree = NULL;
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            top++;
            stack[top] = ptr;
            dir = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            dir = 2;
            break;
        default:
            ptr = new binaryT;
            ptr->data = ch;
            ptr->lChild = ptr->rChild = NULL;
            if (btree == NULL)
                btree = ptr;
            else
            {
                switch (dir)
                {
                case 1:
                    stack[top]->lChild = ptr;
                    break;
                case 2:
                    stack[top]->rChild = ptr;
                    break;
                }
            }
        }
        index++;
        ch = str[index];
    }
    return btree;
}
int BTHeight(binaryT *btree)
{
    int lChildH, rChildH;
    if (btree == NULL)
        return 0;
    else
    {
        lChildH = BTHeight(btree->lChild);
        rChildH = BTHeight(btree->rChild);
        return (lChildH > rChildH) ? (lChildH + 1) : (rChildH + 1);
    }
}

Queue *initQueue()
{
    Queue *queue = new Queue;
    queue->front = queue->rear = -1;
    return queue;
}
void destoryQueue(Queue *queue) { delete queue; }
bool isEmpty(Queue *queue) { return queue->front == queue->rear; }
bool enQueue(Queue *&queue, binaryT *elem)
{
    if ((queue->rear + 1) % maxSize == queue->front)
        return false;
    queue->rear = (queue->rear + 1) % maxSize;
    queue->btData[queue->rear] = elem;
    return true;
}
bool dedQueue(Queue *queue, binaryT *&elem)
{
    if (isEmpty(queue))
        return false;
    queue->front = (queue->front + 1) % maxSize;
    elem = queue->btData[queue->front];
    return true;
}
