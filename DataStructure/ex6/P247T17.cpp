#include "P247.h"
void preOrder(binaryT *btree)
{
    if (btree != NULL)
    {
        cout << btree->data << "\t";
        preOrder(btree->lChild);
        preOrder(btree->rChild);
    }
}

void preOrder(binaryT *btree, elemType x)
{
    if (btree != NULL)
    {
        if (btree->data == x)
        {
            cout << x << "������ڵ����£�\n";
            preOrder(btree->lChild);
            preOrder(btree->rChild);
        }
        preOrder(btree->lChild, x);
        preOrder(btree->rChild, x);
    }
}

int main(){
    binaryT *tree = creatBTree(bt);
    cout << "������ֵ��";
    elemType x;
    cin >> x;
    preOrder(tree, x);
    cout << endl;
    return 0;
}