#include <iostream>
#define maxSize 10
using namespace std;

struct QuType
{
    char data[maxSize];
    int front, rear;
};

QuType *initQueue();
void destroyQueue(QuType *&queue);
bool isEmpty(QuType *queue);
bool isFull(QuType *queue);
bool enQueue(QuType *&queue, char elem);
bool deQueue(QuType *&queue, char &elem);

void trans();

int main()
{
    trans();
    return 0;
}

QuType *initQueue()
{
    QuType *queue = new QuType;
    queue->front = queue->rear = 0;
}
void destroyQueue(QuType *&queue)
{
    delete queue;
}
bool isEmpty(QuType *queue)
{
    return (queue->front == queue->rear);
}
bool isFull(QuType *queue)
{
    return ((queue->rear + 1) % maxSize == queue->rear);
}
bool enQueue(QuType *&queue, char elem)
{
    if (isFull(queue))
        return false;
    queue->rear = (queue->rear + 1) % maxSize;
    queue->data[queue->rear] = elem;
    return true;
}
bool deQueue(QuType *&queue, char &elem)
{
    if (isEmpty(queue))
        return false;
    queue->front = (queue->front + 1) % maxSize;
    elem = queue->data[queue->front];
    return true;
}
void trans()
{
    QuType *queue = initQueue();
    cout << "请输入不多于" << maxSize << "个字符：\n";
    string str;
    cin >> str;
    queue->front = queue->rear = 8;
    for (int i = 0; i < str.length(); i++)
        enQueue(queue, str[i]);
    int val[maxSize], len = 0;
    for (int i = queue->front + 1, n = 0; i != queue->rear + 1; i = (i + 1) % maxSize, n++)
    {
        val[n] = queue->data[i];
        len++;
    }
    queue->front = queue->rear = 0;
    for (int i = 0; i < len; i++)
        queue->data[i] = val[i];
    queue->front = maxSize - 1;
    queue->rear = len;
}