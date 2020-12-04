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

void func();

int main()
{
    func();
    return 0;
}

QuType *initQueue()
{
    QuType *queue = new QuType;
    queue->front = queue->rear = 0;
    return queue;
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
    return ((queue->rear + 1) % maxSize == queue->front);
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

void func()
{
    QuType *queue = initQueue();
    string str;
    char ch;
    cout << "请输入一串字符：";
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            enQueue(queue, str[i]);
        else if (str[i] >= 'a' && str[i] <= 'z')
            deQueue(queue, ch);
        else
        {
            cout << "输出结果：";
            for (int j = queue->front; j != queue->rear; j=(j+1)%maxSize)
                cout << queue->data[j] << "\t";
            cout << endl;
        }
    }
}
