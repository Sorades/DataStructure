#include <iostream>
#define maxSize 200
using namespace std;

struct BTNode
{
    char data;
    BTNode *lChild;
    BTNode *rChild;
    bool lTag;
    bool rTag;
};
char bt[] = {"A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))"};
char ex[] = {"A(B(D(,G),),C(E,F)))"};
BTNode *creatBTree(char *str);
BTNode *pre;
void inThreading(BTNode *btree);
BTNode *creatThread(BTNode *btree);
void destroyThread(BTNode *btree);

void outPut(BTNode *btree);
void outPut1(BTNode *btree);

int main()
{
    BTNode *tree = creatBTree(bt);
    BTNode *thread = creatThread(tree);
    cout << "·ÇµÝ¹é£º\n";
    outPut(thread);
    cout << "µÝ¹é£º\n";
    outPut1(thread->lChild);
    cout << endl;
    return 0;
}
BTNode *creatBTree(char *str)
{
    BTNode *stack[maxSize], *ptr, *btree = NULL;
    int top = -1, index = 0, dir;
    char ch = str[index];
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            stack[++top] = ptr;
            dir = 1;
            break;
        case ',':
            dir = 2;
            break;
        case ')':
            top--;
            break;
        default:
            ptr = (BTNode *)malloc(sizeof(BTNode));
            ptr->data = ch;
            ptr->lTag = ptr->rTag = false;
            ptr->lChild = ptr->rChild = NULL;
            if (btree == NULL)
                btree = ptr;
            else
            {
                switch (dir)
                {
                case 1:
                    stack[top]->lChild = ptr;
                    break;
                case 2:
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
void inThreading(BTNode *btree)
{
    if (btree != NULL)
    {
        inThreading(btree->lChild);
        if (btree->lChild == NULL)
        {
            btree->lChild = pre;
            btree->lTag = true;
        }
        if (pre->rChild == NULL)
        {
            pre->rTag = true;
            pre->rChild = btree;
        }
        pre = btree;
        inThreading(btree->rChild);
    }
}
BTNode *creatThread(BTNode *btree)
{
    BTNode *root;
    root = (BTNode *)malloc(sizeof(BTNode));
    root->lTag = 0;
    root->rTag = 1;
    root->rChild = btree;
    if (btree == NULL)
        root->lChild = root;
    else
    {
        root->lChild = btree;
        pre = root;
        inThreading(btree);
        pre->rChild = root;
        pre->rTag = 1;
        root->rChild = pre;
    }
    return root;
}
void outPut(BTNode *btree)
{
    BTNode *ptr = btree->lChild;
    while (ptr != btree)
    {
        while (ptr->lTag == 0)
            ptr = ptr->lChild;
        cout << ptr->data;
        while (ptr->rTag == 1 && ptr->rChild != btree)
        {
            ptr = ptr->rChild;
            cout << ptr->data;
        }
        ptr = ptr->rChild;
    }
    cout << endl;
}
void outPut1(BTNode *btree)
{
    if (btree->lChild != NULL && btree->lTag == 0)
        outPut1(btree->lChild);
    cout << btree->data;
    if (btree->rChild != NULL && btree->rTag == 0)
        outPut1(btree->rChild);
}


//´ýÊµÏÖ
void destroyThread(BTNode *btree)
{
    BTNode *ptr = btree->lChild;
    BTNode *del;
    while (ptr != btree)
    {
        while (ptr->lTag == 0)
            ptr = ptr->lChild;
        del = ptr;
        while (ptr->rTag == 1 && ptr->rChild != btree)
        {
            ptr = ptr->rChild;
            free(del);
            del = ptr;
        }
        ptr = ptr->rChild;
    }
}
