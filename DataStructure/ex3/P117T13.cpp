#include <iostream>
#define maxSize 10
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

void outPut();
QuType *linkAll(QuType *queue[]);

int main()
{
    outPut();
    return 0;
}

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

QuType *linkAll(QuType *queue[])
{
    QuType *link = initQueue();
    for (int i = 0; i < 10; i++)
    {
        if (!isEmpty(queue[i]))
        {
            if (isEmpty(link))
            {
                link->front = queue[i]->front;
                link->rear = queue[i]->rear;
            }
            else
            {
                link->rear->next = queue[i]->front;
                link->rear = queue[i]->rear;
            }
        }
    }
    return link;
}

void outPut()
{
    QuType *queue[10];
    for (int i = 0; i < 10; i++)
        queue[i] = initQueue();
    cout << "输入n：";
    int n, num, index = 0;
    cin >> n;
    cout << "请输入n（由用户输入）个十以内的数（空格隔开）：\n";
    while (index < n)
    {
        cin >> num;
        if (num >= 0 && num <= 9)
        {
            enQueue(queue[num], num);
            index++;
        }
        else
            cout << "输入错误！\n";
    }
    QuType *link = linkAll(queue);
    QuNode *ptr = link->front;
    cout << "输出连接后的链：\n";
    while (ptr != NULL)
    {
        cout << ptr->data<<endl;
        ptr = ptr->next;
    }
}