#include <cmath>
#include <iostream>
#include <memory.h>
#define maxSize 200
using namespace std;

typedef char elemType;

struct BTNode
{
    elemType data;
    BTNode *lChild;
    BTNode *rChild;
};
char bt[] = {"A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))"};
BTNode *creatBTree(char *str);
void sequence(BTNode *btree, elemType *ch, int num);
void trans(BTNode *btree, elemType *ch, int &num);

int main()
{
    BTNode *tree = creatBTree(bt);
    elemType ch[maxSize];
    memset(ch, '#', sizeof(ch));
    int num = 0;
    trans(tree, ch, num);
    cout << "链式二叉树转换为括号表示的串如下：\n";
    for (int i = 0; ch[i] != '#'; i++)
        cout << ch[i];
    cout << endl;
    memset(ch, '#', sizeof(ch));
    sequence(tree, ch, 1);
    cout << "转换为顺序储存结构如下：\n";
    for (int i = 0; i < maxSize; i++)
        if (ch[i] != '#')
            cout << ch[i];
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
            ptr = new BTNode;
            ptr->data = ch;
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
void sequence(BTNode *btree, elemType *ch, int num)
{
    if (btree != NULL)
    {
        ch[num] = btree->data;
        sequence(btree->lChild, ch, num * 2);
        sequence(btree->rChild, ch, num * 2 + 1);
    }
}