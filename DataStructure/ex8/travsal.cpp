#include <iostream>
using namespace std;
#define maxV 20
#define maxSize 200
#define INF 0x3f3f3f
using namespace std;
typedef char infoType;
const int length = 6;
int matrix[][length] = {{0, 5, INF, 7, INF, INF},
                        {INF, 0, 4, INF, INF, INF},
                        {8, INF, 0, INF, INF, 9},
                        {INF, INF, 5, 0, INF, 6},
                        {INF, INF, INF, 5, 0, INF},
                        {3, INF, INF, INF, 1, 0}};
int visited[maxSize] = {0};
//邻接矩阵
typedef struct
{
    int no;
    infoType info;
} VertexType;
typedef struct
{
    int edges[maxV][maxV];
    int n, e;
    VertexType vex[maxV];
} MatGraph;
//邻接表
typedef struct ANode
{
    int adjvex;
    struct ANode *nextArc;
    int weight;
} ArcNode;
typedef struct VNode
{
    infoType info;
    ArcNode *firstArc;
} VerNode;
typedef struct
{
    VNode adjList[maxV];
    int n, e;
} AdjGraph;
//队列
typedef struct
{
    int data[maxV];
    int front, rear;
} SqQueue;

//创建邻接矩阵
MatGraph *creatMat(int matrix[][length])
{
    MatGraph *mat = (MatGraph *)malloc(sizeof(MatGraph));
    int i, e = 0;
    for (i = 0; i < length; i++)
    {
        mat->vex[i].no = i;
        for (int j = 0; j < length; j++)
        {
            mat->edges[i][j] = matrix[i][j];
            if (matrix[i][j] != 0 && matrix[i][j] != INF)
                e++;
        }
    }
    mat->e = e, mat->n = i;
    return mat;
}
//创建邻接表
AdjGraph *creatAdj(MatGraph *mat)
{
    AdjGraph *G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (int i = 0; i < mat->n; i++)
        G->adjList[i].firstArc = NULL;
    ArcNode *node;
    for (int i = 0; i < mat->n; i++)
        for (int j = mat->n - 1; j >= 0; j--)
            if (mat->edges[i][j] != 0 && mat->edges[i][j] != INF)
            {
                node = (ArcNode *)malloc(sizeof(ArcNode));
                node->adjvex = j;
                node->nextArc = G->adjList[i].firstArc;
                node->weight = mat->edges[i][j];
                G->adjList[i].firstArc = node;
            }
    G->n = mat->n, G->e = mat->e;
    return G;
}
//创建队列
SqQueue *initQueue()
{
    SqQueue *queue = (SqQueue *)malloc(sizeof(SqQueue));
    queue->front = queue->rear = -1;
    return queue;
}
//进队列
bool enQueue(SqQueue *&queue, int elem)
{
    if ((queue->rear + 1) % maxSize == queue->front)
        return false;
    queue->rear = (queue->rear + 1) % maxSize;
    queue->data[queue->rear] = elem;
    return true;
}
//出队列
bool deQueue(SqQueue *&queue, int &elem)
{
    if (queue->front == queue->rear)
        return false;
    queue->front = (queue->front + 1) % maxSize;
    elem = queue->data[queue->front];
    return true;
}

void disAdj(AdjGraph *G)
{
    cout << "邻接表如下：\n";
    ArcNode *node;
    for (int i = 0; i < G->n; i++)
    {
        node = G->adjList[i].firstArc;
        cout << i << ":\t";
        while (node != NULL)
        {
            cout << node->adjvex << "[" << node->weight << "]    ";
            node = node->nextArc;
        }
        cout << "∧" << endl;
    }
}
void disMat(MatGraph *mat)
{
    cout << "邻接矩阵如下：\n";
    for (int i = 0; i < mat->n; i++)
    {
        for (int j = 0; j < mat->n; j++)
        {
            if (mat->edges[i][j] == INF)
                cout << "INF\t";
            else
                cout << mat->edges[i][j] << "\t";
        }
        cout << endl;
    }
}
