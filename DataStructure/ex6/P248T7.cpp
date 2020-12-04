#include "Structure.cpp"

void preOrder(BTNode *btree, char *temp, int num);

void preOrder(BTNode *btree, char *temp, int num, int height, char *output);
void longest(BTNode *btree, char *temp, int num);

void postOrder(BTNode *btree);

void levelOrder(BTNode *btree);

int main()
{
    char *temp = new char;
    BTNode *tree = creatBTree(bt);
    cout << "（1）\n";
    preOrder(tree, temp, 0);
    cout << "=====================================\n（2）" << endl;
    longest(tree, temp, 0);
    cout << "=====================================\n（3）" << endl;
    postOrder(tree);
    cout << "=====================================\n（4）" << endl;
    levelOrder(tree);
    return 0;
}

void preOrder(BTNode *btree, char *temp, int num)
{
    if (btree != NULL)
    {

        temp[num] = btree->data;
        preOrder(btree->lChild, temp, num + 1);
        preOrder(btree->rChild, temp, num + 1);
        //检测到叶子节点后输出该路径
        if (btree->lChild == NULL && btree->rChild == NULL)
        {
            for (int i = num; i >= 0; i--)
                cout << temp[i] << "\t";
            cout << endl;
        }
    }
}
void preOrder(BTNode *btree, char *temp, int num, int height, char *output)
{
    if (btree != NULL)
    {
        temp[num] = btree->data;
        preOrder(btree->lChild, temp, num + 1, height, output);
        preOrder(btree->rChild, temp, num + 1, height, output);
    }
    if (num == height)
    {
        for (int i = 0; i <= num; i++)
            output[i] = temp[i];
        output[num + 1] = '\0';
    }
}
void longest(BTNode *btree, char *temp, int num)
{
    char *out = new char;
    preOrder(btree, temp, num, BTHeight(btree), out);
    for (int i = 0; out[i] != '\0'; i++)
        cout << out[i] << "\t";
    cout << endl;
}

void postOrder(BTNode *btree)
{
    tStack *stack = initStack();
    BTNode *ptr, *visited;
    char *temp = new char; //存结点
    int num = 0;           //结点的标记
    bool flag = false, leave = false;
    ptr = btree;
    do
    {
        while (ptr != NULL)
        {
            temp[num++] = ptr->data;
            push(stack, ptr);
            if (ptr->lChild == NULL && ptr->rChild == NULL)
                leave = true;
            else
                leave = false;
            ptr = ptr->lChild;
        }
        temp[num] = '\0';
        visited = NULL;
        flag = true;
        if (leave)
        {
            for (int i = num - 1; i >= 0; i--)
                cout << temp[i] << "\t";
            cout << endl;
            leave = false;
        }
        while (!isEmpty(stack) && flag)
        {
            getTop(stack, ptr);
            if (ptr->rChild == visited)
            {
                pop(stack, ptr);
                temp[--num] = '\0';
                visited = ptr;
            }
            else
            {
                ptr = ptr->rChild;
                flag = false;
            }
        }

    } while (!isEmpty(stack));
    destroyStack(stack);
}
void levelOrder(BTNode *btree)
{
    sQueue *queue;
    initQueue(queue);
    BTNode *temp = btree;
    enQueue(queue, temp, -1);
    while (queue->front < queue->rear)
    {
        deQueue(queue, temp);
        if (temp->lChild == NULL && temp->rChild == NULL)
        {
            queue->parent = queue->front;
            while (queue->data[queue->parent].P != -1)
            {
                cout << queue->data[queue->parent].node->data << "\t";
                queue->parent = queue->data[queue->parent].P;
            }
            cout << queue->data[queue->parent].node->data << endl;
        }
        if (temp->lChild != NULL)
            enQueue(queue, temp->lChild, queue->front);
        if (temp->rChild != NULL)
            enQueue(queue, temp->rChild, queue->front);
    }
}