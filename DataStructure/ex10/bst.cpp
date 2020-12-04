#include <iostream>
using namespace std;
#define maxSize 100
typedef int keyType;
typedef char infoType;
typedef struct node
{
    keyType key;
    infoType data;
    struct node *lChild, *rChild;
} BSTNode;
void dispBST(BSTNode *b);
bool insertBST(BSTNode *&btree, keyType k)
{
    if (btree == NULL)
    {
        btree = new BSTNode;
        btree->key = k;
        btree->lChild = btree->rChild = NULL;
        return true;
    }
    else if (k == btree->key)
        return false;
    else if (k < btree->key)
        return insertBST(btree->lChild, k);
    else if (k > btree->key)
        return insertBST(btree->rChild, k);
}
BSTNode *creatBST(keyType a[], int n)
{
    BSTNode *btree = NULL;
    int i = 0;
    while (i < n)
    {
        if (insertBST(btree, a[i]) == 1)
        {
            cout << "\tµÚ" << i + 1 << "²½£¬²åÈë" << a[i] << ":";
            dispBST(btree);
            cout << endl;
            i++;
        }
    }
    return btree;
}
void delete1(BSTNode *p, BSTNode *&r)
{
    BSTNode *q;
    if (r->rChild != NULL)
        delete1(p, r->rChild);
    else
    {
        p->key = r->key;
        p->data = r->data;
        q = r;
        r = r->lChild;
        delete q;
    }
}
void Delete(BSTNode *&p)
{
    BSTNode *q;
    if (p->rChild == NULL)
    {
        q = p;
        p = p->lChild;
        delete q;
    }
    else if (p->lChild == NULL)
    {
        q = p;
        p = p->rChild;
        delete q;
    }
    else
        delete1(p, p->lChild);
}
bool deleteBST(BSTNode *&btree, keyType k)
{
    if (btree == NULL)
        return false;
    else
    {
        if (k < btree->key)
            return deleteBST(btree->lChild, k);
        else if (k > btree->key)
            return deleteBST(btree->rChild, k);
        else
        {
            Delete(btree);
            return true;
        }
    }
}
void searchBST1(BSTNode *btree, keyType k, keyType path[], int i)
{
    int j;
    if (btree == NULL)
        return;
    else if (k == btree->key)
    {
        path[i + 1] = btree->key;
        for (int j = 0; j <= i + 1; j++)
            cout << path[j] << "  ";
        cout << endl;
    }
    else
    {
        path[i + 1] = btree->key;
        if (k < btree->key)
            searchBST1(btree->lChild, k, path, i + 1);
        else
            searchBST1(btree->rChild, k, path, i + 1);
    }
}
int searchBST2(BSTNode *btree, keyType k)
{
    if (btree == NULL)
        return 0;
    else if (k == btree->key)
    {
        cout << btree->key << "  ";
        return 1;
    }
    else if (k < btree->key)
        searchBST2(btree->lChild, k);
    else
        searchBST2(btree->rChild, k);
    cout << btree->key << "  ";
}
void dispBST(BSTNode *btree)
{
    if (btree != NULL)
    {
        cout << btree->key;
        if (btree->lChild != NULL || btree->rChild != NULL)
        {
            cout << "(";
            dispBST(btree->lChild);
            if (btree->rChild != NULL)
                cout << ",";
            dispBST(btree->rChild);
            cout << ")";
        }
    }
}
keyType predT = -0x7fff;
bool judgeBST(BSTNode *btree)
{
    bool b1, b2;
    if (btree == NULL)
        return true;
    else
    {
        b1 = judgeBST(btree->lChild);
        if (b1 == false || predT >= btree->key)
            return false;
        predT = btree->key;
        b2 = judgeBST(btree->rChild);
        return b2;
    }
}
void destroyBST(BSTNode *btree)
{
    if (btree != NULL)
    {
        destroyBST(btree->lChild);
        destroyBST(btree->rChild);
        delete btree;
    }
}
