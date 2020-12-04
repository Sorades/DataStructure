#include <iostream>
#define maxSize 100
using namespace std;
typedef char elemType;
struct BTNode
{
    elemType data;
    BTNode *lChild;
    BTNode *rChild;
};

BTNode *creatBTree(char *str);
void destroyBTree(BTNode *&btree);
BTNode *findNode(BTNode *btree, elemType x);
BTNode *lChildNode(BTNode *ptr);
BTNode *rChildNode(BTNode *ptr);
int BTHeight(BTNode *btree);
void dispBTree(BTNode *btree);

int main()
{
    return 0;
}
//����������
BTNode *creatBTree(char *str)
{
    BTNode *stack[maxSize], *ptr;
    int top = -1, index = 0, dir;
    char ch;
    BTNode *btree = NULL;
    while (ch != '\0')
    {
        ch = str[index];
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
    }
}
//���ٶ�����
void destroyBTree(BTNode *&btree){
    if(btree!=NULL){
        destroyBTree(btree->lChild);
        destroyBTree(btree->rChild);
        delete btree;
    }
}
//���ҽ��
BTNode *findNode(BTNode *btree, elemType x){
    BTNode *ptr;
    if(btree==NULL)
        return NULL;
    else if(btree->data==x)
        return btree;
    else {
        ptr = findNode(btree->lChild, x);
        if(ptr!=NULL)
            return ptr;
        else
            return findNode(btree->rChild, x);
    }
}
//���ӽ��
BTNode *lChildNode(BTNode *ptr){
    return ptr->lChild;
}
BTNode *rChildNode(BTNode *ptr){
    return ptr->rChild;
}
//��߶�
int BTHeight(BTNode *btree){
    int lChildH, rChildH;
    if(btree==NULL)
        return 0;
    else
    {
        lChildH = BTHeight(btree->lChild);
        rChildH = BTHeight(btree->rChild);
        return (lChildH > rChildH) ? (lChildH + 1) : (rChildH + 1);
    }
    
}
//���������
void dispBTree(BTNode *btree){
    if(btree!=NULL){
        cout << btree->data;
        if(btree->lChild!=NULL||btree->rChild!=NULL){
            cout << "(";
            dispBTree(btree->lChild);
            if(btree->rChild!=NULL)
                cout << ",";
            dispBTree(btree->rChild);
            cout << ")";
        }
    }
}
