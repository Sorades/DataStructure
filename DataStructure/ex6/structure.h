#include <iostream>
using namespace std;
#define maxSize 100

struct BTNode
{
    char data;
    int degree;
    BTNode *lChild;
    BTNode *rChild;
};
struct sNode
{
    BTNode *node;
    int P; //存放双亲结点在队列中的位置
};
struct tQueue
{
    BTNode *data[maxSize];
    int front, rear, last;
};
struct tStack
{
    BTNode *data;
    tStack *next;
};
struct sQueue
{
    sNode data[maxSize];
    int front, rear;
    int parent; 
};

char bt[] = {"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"};

BTNode *creatBTree(char *str);
int BTHeight(BTNode *btree);

tQueue *initQueue();
void initQueue(sQueue *&queue);
bool enQueue(tQueue *&queue, BTNode *elem);
bool enQueue(sQueue *&queue, BTNode *elem, int parent);
bool deQueue(tQueue *&queue, BTNode *&elem);
bool deQueue(sQueue *queue, BTNode *&elem, int &p);
void destroyQueue(tQueue *&queue) { delete queue; }
void destroyQueue(sQueue *&queue) { delete queue; }
bool isEmpty(sQueue *queue) { return (queue->front < queue->rear); }

tStack *initStack();
void destroyStack(tStack *&stack);
bool isEmpty(tStack *stack);
bool pop(tStack *&stack, BTNode &e);
void push(tStack *&stack, BTNode e);
bool getTop(tStack *&stack, BTNode *&e);