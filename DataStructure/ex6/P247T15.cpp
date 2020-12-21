#include "P247.h"

int leafCount(binaryT *btree, int k)
{
    if (BTHeight(btree) < k)
        return 0;
    Queue *queue = initQueue();
    binaryT *temp;
    int levelCount = 1, leafCount = 0;
    enQueue(queue, btree);
    enQueue(queue, NULL);
    while (!isEmpty(queue))
    {
        dedQueue(queue, temp);
        if (levelCount == k)
        {
            while (temp != NULL)
            {
                if (temp->lChild == NULL && temp->rChild == NULL)
                    leafCount++;
                dedQueue(queue, temp);
            }
            destoryQueue(queue);
            return leafCount;
        }
        if (temp == NULL)
        {
            enQueue(queue, NULL);
            levelCount++;
            continue;
        }
        if (temp->lChild != NULL)
            enQueue(queue, temp->lChild);
        if (temp->rChild != NULL)
            enQueue(queue, temp->rChild);
    }
}

int main()
{
    binaryT *tree = creatBTree(bt);
    cout << "�������b��k���Ҷ�ӽڵ������\nk = ";
    int k;
    cin >> k;
    int count = leafCount(tree, k);
    if (count > 0)
        cout << "������" << count << endl;
    else
        cout << "����û��" << k << "��\n";
    return 0;
}
