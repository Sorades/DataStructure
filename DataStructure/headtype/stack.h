#include <iostream>
using namespace std;

typedef int elemType;

struct QuNode
{
    elemType data;
    QuNode *next;
};
struct QuType
{
    QuNode *front;
    QuNode *rear;
};
QuType *initQueue();
void destroyQueue(QuType *&queue);
bool isEmpty(QuType *queue);
void enQueue(QuType *&queue, elemType elem);
bool deQueue(QuType *&queue, elemType &elem);


QuType *initQueue()
{
    QuType *queue = new QuType;
    queue->front = queue->rear = NULL;
}
void destroyQueue(QuType *&queue)
{
    QuNode *pre = queue->front, *p;
    if (pre != NULL)
    {
        p = pre->next;
        while (p != NULL)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
    delete queue;
}
bool isEmpty(QuType *queue)
{
    return (queue->rear == NULL);
}
void enQueue(QuType *&queue, elemType elem)
{
    QuNode *node = new QuNode;
    node->data = elem;
    node->next = NULL;
    if (isEmpty(queue))
        queue->front = queue->rear = node;
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
}
bool deQueue(QuType *&queue, elemType &elem)
{
    QuNode *node = new QuNode;
    if (isEmpty(queue))
        return false;
    node = queue->front;
    if (queue->front == queue->rear)
        queue->front = queue->rear = NULL;
    else
        queue->front = queue->front->next;
    elem = node->data;
    delete node;
    return true;
}
