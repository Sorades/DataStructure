#include <iostream>
#define maxV 9
#define INF 0x3f3f3f
using namespace std;
typedef char infoType;
const int length = 9;
int map[][maxV] = {0, 6, 4, 5, INF, INF, INF, INF, INF,
                   INF, 0, INF, INF, 1, INF, INF, INF, INF,
                   INF, INF, 0, INF, 1, INF, INF, INF, INF,
                   INF, INF, INF, 0, INF, INF, INF, 2, INF,
                   INF, INF, INF, INF, 0, 9, 7, INF, INF,
                   INF, INF, INF, INF, INF, 0, INF, INF, 2,
                   INF, INF, INF, INF, INF, INF, 0, INF, 4,
                   INF, INF, INF, INF, INF, INF, INF, 0, 4,
                   INF, INF, INF, INF, INF, INF, INF, INF, 0};
typedef struct
{
    int no;        //顶点的编号
    infoType info; //顶点的其他信息
} VertexType;
typedef struct
{
    int edges[maxV][maxV]; //邻接矩阵数组
    int n, e;
    VertexType vex[maxV];
} MatGraph;

typedef struct ANode
{
    int adjvex;
    struct ANode *nextArc;
    int weight;
} ArcNode;
typedef struct VNode
{
    infoType info;
    int count;
    ArcNode *firstArc;
} VerNode;
typedef struct
{
    VNode adjList[maxV];
    int n, e;
} AdjGraph;

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

AdjGraph *creatAdj(MatGraph *mat)
{
    AdjGraph *G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (int i = 0; i < mat->n; i++)
        G->adjList[i].firstArc = NULL;
    ArcNode *node;
    for (int i = 0; i < mat->n; i++)
        for (int j = mat->n - 1; j >= 0; j--)
            if (mat->edges[i][j] != INF && mat->edges[i][j] != 0)
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
