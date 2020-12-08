#include <iostream>
#define n 10
using namespace std;

struct RecType
{
    int key;
    char info;
};

void sift(RecType R[], int low, int high);
void HeapSort(RecType R[]);

int main()
{
    RecType src[n + 1] = {{}, {6, 'A'}, {8, 'E'}, {7, 'F'}, {9, 'C'}, {0, 'G'}, {1, 'B'}, {3, 'J'}, {2, 'K'}, {4, 'H'}, {5, 'I'}};
    cout << "堆排序之前：\n";
    for (int i = 1; i <= n; i++)
        cout << "[" << src[i].key << "," << src[i].info << "] ";
    cout << "\n堆排序之后：\n";
    HeapSort(src);
    for (int i = 1; i <= n; i++)
        cout << "[" << src[i].key << "," << src[i].info << "] ";
    cout << endl;
    return 0;
}
void sift(RecType R[], int low, int high)
{
    int root = low, p = 2 * root;
    RecType temp = R[root];
    while (p <= high)
    {
        if (p < high && R[p].key < R[p + 1].key)
            p++;
        if (temp.key < R[p].key)
        {
            R[root] = R[p];
            root = p;
            p = 2 * root;
        }
        else
            break;
    }
    R[root] = temp;
}
void HeapSort(RecType R[])
{
    RecType temp;
    for (int i = n / 2; i >= 1; i--) //n/2为最后的叶子节点的双亲结点
        sift(R, i, n);
    for (int i = n; i >= 2; i--)
    {
        temp = R[i];
        R[i] = R[1];
        R[1] = temp;
        sift(R, 1, i - 1);
    }
}