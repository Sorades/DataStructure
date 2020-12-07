#include <iostream>
#define maxSize 4
#define n 6
using namespace std;

struct RecType
{
    int key;
    char info;
};
typedef struct Node
{
    RecType data;
    struct Node *next;
} NodeType;
RecType list[n] = {{0, 'A'}, {1, 'B'}, {3, 'C'}, {2, 'E'}, {1, 'D'}, {0, 'F'}};

NodeType *creatList(RecType list[]);
void radixSort(NodeType *&p, int r, int d);
void output(NodeType *node);

int main()
{
    NodeType *List = creatList(list);
    output(List);
    radixSort(List, 3, 1);
    cout << "=============================================\n";
    output(List);
    return 0;
}
NodeType *creatList(RecType list[])
{
    NodeType *head = new NodeType;
    NodeType *node, *end = head;
    for (int i = 0; i < n; i++)
    {
        node = new NodeType;
        node->data.key = list[i].key;
        node->data.info = list[i].info;
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
void radixSort(NodeType *&p, int r, int d)
{
    NodeType *head[maxSize], *tail[maxSize], *temp;
    NodeType *node = p->next;
    int key;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < maxSize; j++)
            head[j] = tail[j] = NULL;
        while (node != NULL)
        {
            key = node->data.key;
            if (head[key] == NULL)
            {
                head[key] = node;
                tail[key] = node;
            }
            else
            {
                tail[key]->next = node;
                tail[key] = node;
            }
            node = node->next;
        }
        node = NULL;
        for (int j = 0; j < maxSize; j++)
            if (head[j] != NULL)
            {
                if (node == NULL)
                {
                    node = head[j];
                    temp = tail[j];
                }
                else
                {
                    temp->next = head[j];
                    temp = tail[j];
                }
            }
        temp->next = NULL;
    }
}
void output(NodeType *node)
{
    node = node->next;
    while (node != NULL)
    {
        cout << "[" << node->data.key << "," << node->data.info << "]\t";
        node = node->next;
    }
    cout << endl;
}
