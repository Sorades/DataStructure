#include "bst.cpp"
int main(){
    BSTNode *btree;
    int path[maxSize];
    keyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    cout << "����BST����\n";
    btree = creatBST(a, n);
    cout << "BST:";
    dispBST(btree);
    cout << endl;
    if(judgeBST(btree))
        cout << "��һ��BST";
    else
        cout << "����BST";
    cout << "\n����" << k << "�ؼ��֣��ݹ飩:";
    searchBST1(btree, k, path, -1);
    cout << "����" << k << "�ؼ��֣��ǵݹ飩:";
    searchBST2(btree, k);
    cout << "\nɾ����\n";
    cout << "\tԭBST��";
    dispBST(btree);
    cout << endl
         << "\tɾ�����4��";
    deleteBST(btree, 4);
    dispBST(btree);
    cout << "\n\tɾ���ڵ�5��";
    deleteBST(btree, 5);
    dispBST(btree);
    cout << "\n����BST\n";
    destroyBST(btree);
    return 0;
}