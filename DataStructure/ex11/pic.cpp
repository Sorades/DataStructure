/**
 * ʹ�������ϵ�Ԫ�ظ�����d<=1
 * ����һ�����ϴ��С�����������һ�����ϴӴ�С������
 * ��nΪż������d=0���ֱ���������Ԫ�غ͵Ĳ��
 * ��nΪ��������d=1�������������n1���󣬻�n2�������ѡȡԪ�غ�֮���������
 * ���ǵ�����Ԫ��Ϊ��������ѡ���������
*/
#include <iostream>
#define maxR 10
using namespace std;
typedef int keyType;
typedef struct Node
{
    keyType data;
    struct Node *next;
} NodeType; //���ݵĽڵ�����

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
int maxbit(NodeType *node)
{
    NodeType *temp = node->next;
    int maxData = temp->data;
    while (temp != NULL)
    {
        if (maxData < temp->data)
            maxData = temp->data;
        temp = temp->next;
    }
    int d = 0;
    while (maxData > 0)
    {
        maxData /= 10;
        d++;
    }
    return d;
}
void radixSort(NodeType *node, int length)
{
    int d = maxbit(node);
    keyType *temp = new keyType[length];
    int *count = new int[10];
    int radix = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < 10; j++)
            count[j] = 0;
        for (int j = 0; j < length;j++){
            
        }
            for (int j = 1; j < 10; j++)
                count[j] += count[j - 1];
        
    }
}
