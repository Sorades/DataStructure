/**
 * 使两个集合的元素个数差d<=1
 * 其中一个集合存从小到大的排序，另一个集合从大到小的排序
 * 若n为偶数，则d=0，分别求两集合元素和的差即可
 * 若n为奇数，则d=1，有两种情况，n1更大，或n2更大，最后选取元素和之差最大的情况
 * 考虑到集合元素为正整数，选择基数排序
*/
#include <iostream>
#define maxR 10
using namespace std;
typedef int keyType;
typedef struct Node
{
    keyType data;
    struct Node *next;
} NodeType; //数据的节点类型

int src[] = {99, 85, 43, 46, 888, 94, 11, 2, 6};

NodeType *creatList(keyType data[], int length);
int maxbit(NodeType *node);
void radixSort(NodeType *node, int length);

int main()
{

    NodeType *List = creatList(src, (sizeof(src) / sizeof(src[0])));
    return 0;
}

NodeType *creatList(keyType data[], int length)
{
    NodeType *head = new NodeType, *end = head;
    for (int i = 0; i < length; i++)
    {
        NodeType *node = new NodeType;
        node->data = data[i];
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
