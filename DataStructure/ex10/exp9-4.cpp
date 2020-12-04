#include "bst.cpp"
int main(){
    BSTNode *btree;
    int path[maxSize];
    keyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    cout << "创建BST树：\n";
    btree = creatBST(a, n);
    cout << "BST:";
    dispBST(btree);
    cout << endl;
    if(judgeBST(btree))
        cout << "是一棵BST";
    else
        cout << "不是BST";
    cout << "\n查找" << k << "关键字（递归）:";
    searchBST1(btree, k, path, -1);
    cout << "查找" << k << "关键字（非递归）:";
    searchBST2(btree, k);
    cout << "\n删除：\n";
    cout << "\t原BST：";
    dispBST(btree);
    cout << endl
         << "\t删除结点4：";
    deleteBST(btree, 4);
    dispBST(btree);
    cout << "\n\t删除节点5：";
    deleteBST(btree, 5);
    dispBST(btree);
    cout << "\n销毁BST\n";
    destroyBST(btree);
    return 0;
}