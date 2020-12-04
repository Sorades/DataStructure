#include "Structure.cpp"


int nodeCount(BTNode *btree);
int leafNoCot(BTNode *btree);
int locate(BTNode *btree, char ch, int height);
int width(BTNode *btree);

int main()
{
    BTNode *tree = creatBTree(bt);
    cout << "count = " << nodeCount(tree) + 1 << endl;
    cout << "leafnode = " << leafNoCot(tree) << endl;
    char ch;
    cout << "请输入指定结点值：";
    cin >> ch;
    cout << "层次：" << locate(tree, ch, 1) << endl;
    cout << "树的宽度：" << width(tree) << endl;
    return 0;
}


void destroyBTree(BTNode *&btree)
{
    if (btree != NULL)
    {
        destroyBTree(btree->lChild);
        destroyBTree(btree->rChild);
        delete btree;
    }
}
int nodeCount(BTNode *btree)
{
    int count = 0;
    if (btree != NULL)
    {
        count += btree->degree;
        count += nodeCount(btree->lChild) + nodeCount(btree->rChild);
    }
    return count;
}
int leafNoCot(BTNode *btree)
{
    int count = 0;
    if (btree != NULL)
    {
        if (btree->lChild == NULL && btree->rChild == NULL)
            count++;
        count += leafNoCot(btree->lChild) + leafNoCot(btree->rChild);
    }
    return count;
}

int locate(BTNode *btree, char ch, int height)
{
    int l = 0;
    if (btree == NULL)
        return 0;
    else if (btree->data == ch)
        return height;
    else
    {
        l = locate(btree->lChild, ch, height + 1);
        if (l == 0)
            return locate(btree->rChild, ch, height + 1);
        else
            return l;
    }
}
int width(BTNode *btree)
{
    if (btree == NULL)
        return 0;
    int tempnum = 0, max = 0;
    BTNode *ptr;
    tQueue *queue = initQueue();
    enQueue(queue, btree);
    while (queue->front < queue->rear)
    {
        deQueue(queue, ptr);
        tempnum++;
        if (ptr->lChild != NULL)
            enQueue(queue, ptr->lChild);
        if (ptr->rChild != NULL)
            enQueue(queue, ptr->rChild);
        if (queue->front == queue->last)
        {
            queue->last = queue->rear;
            if (tempnum > max)
                max = tempnum;
            tempnum = 0;
        }
    }
    return max;
}