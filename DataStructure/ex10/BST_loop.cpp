#include <iostream>
using namespace std;

typedef int keyType;
typedef char infortype;

typedef struct node
{
    keyType key;                  //关键字项
    infortype data;               //数据域
    struct node *lChild, *rChild; //左右孩子
} BSTNode;
bool insertBST(BSTNode *&btree, keyType k);
BSTNode *creatBST(keyType a[], int n);
BSTNode *searchBST(BSTNode *btree, keyType k);

int main()
{

    return 0;
}

bool insertBST(BSTNode *&btree, keyType k)
{
    if (btree == NULL)
    {
        btree = new BSTNode;
        btree->key = k;
        btree->lChild = NULL;
        btree->rChild = NULL;
        return true;
    }
    else if(k==btree->key)
        return false;
    else if(k<btree->key)
        return insertBST(btree->lChild, k);
    else
        return insertBST(btree->rChild, k);
}
BSTNode *creatBST(keyType a[], int n){
    BSTNode *node = NULL;
    int i = 0;
    while (i<n)
    {
        insertBST(node, a[i]);
        i++;
    }
    return node;
}
BSTNode *searchBST(BSTNode *btree, keyType k){
    if(btree==NULL||btree->key==k)
        return btree;
    if(k<btree->key)
        return searchBST(btree->lChild, k);
    else
        return searchBST(btree->rChild, k);
}

