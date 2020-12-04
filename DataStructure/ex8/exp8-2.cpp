#include "travsal.cpp"

void DFS(AdjGraph *G, int v);
void BFS(AdjGraph *G, int v);
void DFS2(AdjGraph *G, int v);

int main()
{
    MatGraph *mat = creatMat(matrix);
    disMat(mat);
    AdjGraph *G = creatAdj(mat);
    disAdj(G);
    cout << "�Ӷ���0��ʼ��������ȣ��ݹ飩�������У�\n";
    DFS(G, 0);
    cout << "\n=================================\n";
    cout << "�Ӷ���0��ʼ��������ȣ��ǵݹ飩�������У�\n";
    DFS2(G, 0);
    cout << "\n==================================\n";
    cout << "�Ӷ���0��ʼ�Ĺ�����ȱ������У�\n";
    BFS(G, 0);
    cout << endl;
    return 0;
}

//�������(�ݹ��㷨)
void DFS(AdjGraph *G, int v)
{
    ArcNode *node;
    visited[v] = 1;
    node = G->adjList[v].firstArc;
    cout << v << ",";
    while (node != NULL)
    {
        if (visited[node->adjvex] == 0)
            DFS(G, node->adjvex);
        node = node->nextArc;
    }
}
//����������ǵݹ飩
void DFS2(AdjGraph *G, int v)
{
    SqQueue *queue = initQueue();
    ArcNode *node;
    int temp;
    int visited[maxV];
    for (int i = 0; i < maxV; i++)
        visited[i] = 0;
    enQueue(queue, v);
    while (queue->front!=queue->rear)
    {
        deQueue(queue, v);
        visited[v] = 1;
        node = G->adjList[v].firstArc;
        cout << v << ",";
        while (node != NULL)
        {
            if (visited[node->adjvex] == 0)
            {
                enQueue(queue,node->adjvex);
                temp = node->adjvex;
                break;
            }
            node = node->nextArc;
        }
    }
}
//�������
void BFS(AdjGraph *G, int v)
{
    SqQueue *queue = initQueue();
    ArcNode *node;
    int temp;
    int visited[maxV];
    for (int i = 0; i < maxV; i++)
        visited[i] = 0;
    cout << v << ",";
    visited[v] = 1;
    enQueue(queue, v);
    while (queue->front != queue->rear)
    {
        deQueue(queue, temp);
        node = G->adjList[temp].firstArc;
        while (node != NULL)
        {
            if (visited[node->adjvex] == 0)
            {
                cout << node->adjvex << ",";
                visited[node->adjvex] = 1;
                enQueue(queue, node->adjvex);
            }
            node = node->nextArc;
        }
    }
}