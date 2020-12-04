#include "structure.h"

BTNode *creatBTree(char *str)
{
    BTNode *stack[maxSize], *ptr;
    int top = -1, index = 0, dir;
    char ch = str[index];
    BTNode *btree = NULL;
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
            ptr = new BTNode;
            ptr->data = ch;
            ptr->lChild = ptr->rChild = NULL;
            ptr->degree = 0;
            if (btree == NULL)
                btree = ptr;
            else
            {
                switch (dir)
                {
                case 1:
                    ptr->degree++;
                    stack[top]->lChild = ptr;
                    break;
                case 2:
                    ptr->degree++;
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
int BTHeight(BTNode *btree)
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

tQueue *initQueue()
{
    tQueue *queue = new tQueue;
    queue->front = queue->rear = -1;
    queue->last = 0;
    return queue;
}
void initQueue(sQueue *&queue)
{
    queue = new sQueue;
    queue->front = queue->rear = queue->parent = -1;
}
bool enQueue(tQueue *&queue, BTNode *elem)
{
    if ((queue->rear + 1) % maxSize == queue->front)
        return false;
    queue->rear = (queue->rear + 1) % maxSize;
    queue->data[queue->rear] = elem;
    return true;
}
bool enQueue(sQueue *&queue, BTNode *elem, int parent)
{
    if (queue->rear >= maxSize)
        return false;
    queue->rear++;
    queue->data[queue->rear].node = elem;
    queue->data[queue->rear].P = parent;
    return true;
}
bool deQueue(tQueue *&queue, BTNode *&elem)
{
    if (queue->front == queue->rear)
        return false;
    queue->front = (queue->front + 1) % maxSize;
    elem = queue->data[queue->front];
    return true;
}
bool deQueue(sQueue *queue, BTNode *&elem,int &p)
{
    if (!isEmpty(queue))
        return false;
    queue->front++;
    elem = queue->data[queue->front].node;
    queue->data[p].P = p;
    return true;
}
bool deQueue(sQueue *queue, BTNode *&elem){
    if (!isEmpty(queue))
        return false;
    queue->front++;
    elem = queue->data[queue->front].node;
    return true;
}

tStack *initStack()
{
    tStack *stack = new tStack;
    stack->next = NULL;
    return stack;
}
void destroyStack(tStack *&stack)
{
    tStack *ptr = stack, *p = stack->next;
    while (p != NULL)
    {
        delete ptr;
        ptr = p;
        p = p->next;
    }
    delete ptr;
}
bool isEmpty(tStack *stack)
{
    return stack->next == NULL;
}
bool pop(tStack *&stack, BTNode *&e)
{
    if (isEmpty(stack))
        return false;
    tStack *node = stack->next;
    e = node->data;
    stack->next = node->next;
    delete node;
    return true;
}
void push(tStack *&stack, BTNode *e)
{
    tStack *node = new tStack;
    node->data = e;
    node->next = stack->next;
    stack->next = node;
}
bool getTop(tStack *&stack, BTNode *&e)
{
    if (isEmpty(stack))
        return false;
    e = stack->next->data;
    return true;
}
