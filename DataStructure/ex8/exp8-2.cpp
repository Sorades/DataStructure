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
    cout << "从顶点0开始的深度优先（递归）遍历序列：\n";
    DFS(G, 0);
    cout << "\n=================================\n";
    cout << "从顶点0开始的深度优先（非递归）遍历序列：\n";
    DFS2(G, 0);
    cout << "\n==================================\n";
    cout << "从顶点0开始的广度优先遍历序列：\n";
    BFS(G, 0);
    cout << endl;
    return 0;
}

//深度搜索(递归算法)
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
//深度搜索（非递归）
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
//广度搜索
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