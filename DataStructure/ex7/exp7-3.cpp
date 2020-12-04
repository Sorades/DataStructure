#include <iostream>
#include <memory.h>
#define maxSize 200
using namespace std;

typedef char elemType;
char preList[] = {"ABDEHJKLMNCFGI"};
char midList[] = {"DBJHLKMNEAFCGI"};
char posList[] = {"DJLNMKHEBFIGCA"};

struct BTNode
{
    elemType data;
    BTNode *lChild;
    BTNode *rChild;
};

void trans(BTNode *btree, elemType *ch, int &num);
char *swap(char *temp, int length);
BTNode *recur(elemType *midList, elemType *posList, int num);

BTNode *creatBT1(elemType *preList, elemType *midList, int num);
BTNode *creatBT2(elemType *midList, elemType *posList, int num);

void disByBrack(BTNode *btree);
void disByConcav(BTNode *btree, int num);

int main()
{
    int length = sizeof(preList) - 1;
    BTNode *tree1 = creatBT1(preList, midList, length);
    cout << "由先中序历遍序列创建的链式二叉树括号表示法如下：\n";
    disByBrack(tree1);
    cout << "凹入表示法如下：\n";
    disByConcav(tree1, 0);
    cout << "=========================================\n";
    BTNode *tree2 = creatBT2(midList, posList, length);
    cout << "由中后序历遍序列创建的链式二叉树括号表示法如下：\n";
    disByBrack(tree2);
    cout << "凹入表示法如下：\n";
    disByConcav(tree2, 0);
    return 0;
}

BTNode *creatBT1(elemType *preList, elemType *midList, int num)
{
    BTNode *ptr;
    if (num <= 0)
        return NULL;
    ptr = (BTNode *)malloc(sizeof(BTNode));
    ptr->data = *preList;
    int pos; //pos是左子树的结点总数
    for (pos = 0; pos < num; pos++)
        if (midList[pos] == *preList)
            break;
    ptr->lChild = creatBT1(preList + 1, midList, pos);
    //+1包括根节点
    ptr->rChild = creatBT1(preList + pos + 1, midList + pos + 1, num - pos - 1);
    return ptr;
}
BTNode *creatBT2(elemType *midList, elemType *posList, int num)
{
    char *nMid = swap(midList, num - 1);
    char *nPos = swap(posList, num - 1);
    return recur(nMid, nPos, num);
}
BTNode *recur(elemType *midList, elemType *posList, int num)
{
    BTNode *ptr;
    if (num <= 0)
        return NULL;
    ptr = (BTNode *)malloc(sizeof(BTNode));
    ptr->data = *posList;
    int pos; //pos是右子树的结点总数
    for (pos = 0; pos < num; pos++)
        if (midList[pos] == *posList)
            break;
    ptr->rChild = recur(midList, posList + 1, pos);
    ptr->lChild = recur(midList + pos + 1, posList + pos + 1, num - pos - 1);
    return ptr;
}
void trans(BTNode *btree, elemType *ch, int &num)
{
    if (btree != NULL)
    {
        ch[num++] = btree->data;
        if (btree->lChild != NULL || btree->rChild != NULL)
        {
            ch[num++] = '(';
            if (btree->lChild != NULL)
                trans(btree->lChild, ch, num);
            ch[num++] = ',';
            if (btree->rChild != NULL)
                trans(btree->rChild, ch, num);
            ch[num++] = ')';
        }
    }
}
//倒置中后序表
char *swap(char *temp, int length)
{
    char *newStr = new char;
    for (int i = 0; i <= length; i++)
        newStr[i] = temp[length - i];
    newStr[length + 1] = '\0';
    return newStr;
}

void disByBrack(BTNode *btree)
{
    elemType ch[maxSize];
    memset(ch, '#', sizeof(ch));
    int num = 0;
    trans(btree, ch, num);
    for (int i = 0; ch[i] != '#'; i++)
        cout << ch[i];
    cout << endl;
}
void disByConcav(BTNode *btree, int num)
{
    if (btree != NULL)
    {
        for (int i = 0; i < num; i++)
            cout << " ";
        cout << btree->data << endl;
        disByConcav(btree->lChild, num + 1);
        disByConcav(btree->rChild, num + 1);
    }
}