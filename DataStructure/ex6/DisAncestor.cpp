#include "Structure.cpp"

bool findAncestor(BTNode *btree, char *temp, int flag, char x);

int main()
{
    BTNode *tree = creatBTree(bt);
    char *temp = new char;
    char x;
    cout << "������x���ֵ��";
    cin >> x;
    if (!findAncestor(tree, temp, 0, x))
        cout << "�����ڸý��\n";
}

bool findAncestor(BTNode *btree, char *temp, int flag, char x)
{
    bool isFind = false;
    if (btree != NULL)
    {
        if (btree->data == x)
        {
            cout << "�ý����������ȣ�\n";
            for (int i = 0; i <= flag; i++)
                cout << temp[i] << "\t";
            cout << endl;
            return true;
        }
        temp[flag] = btree->data;
        flag++;
        if (!isFind)
            isFind = findAncestor(btree->lChild, temp, flag, x);
        temp[flag] = '\0';
        if (!isFind)
            isFind = findAncestor(btree->rChild, temp, flag, x);
        temp[flag] = '\0';
    }
    return isFind;
}
