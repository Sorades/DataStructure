#include <iostream>
#define maxV 5
#define INF 0x3f3f3f3f
using namespace std;
typedef char infoType;
int a[maxV][maxV] = {0, 8, INF, 5, INF,
                     INF, 0, 3, INF, INF,
                     INF, INF, 0, INF, 6,
                     INF, INF, 9, 0, INF,
                     INF, INF, INF, INF, 0};

typedef struct ANode
{
    int adjvex;//该边的邻接点编号
    struct ANode *nextArc;//该边的邻接点编号
    int weight; //边结点的类型
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

AdjGraph *creatAdj(int a[maxV][maxV], int n, int e);
void disAdj(AdjGraph *G);
void destroyAdj(AdjGraph *&G);

AdjGraph *creatAdj(int a[maxV][maxV], int n, int e)
{
    AdjGraph *G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (int i = 0; i < n; i++)
        G->adjList[i].firstArc = NULL;
    ArcNode *node;
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            if (a[i][j] != INF && a[i][j] != 0)
            {
                node = (ArcNode *)malloc(sizeof(ArcNode));
                node->adjvex = j;
                node->nextArc = G->adjList[i].firstArc;
                node->weight = a[i][j];
                G->adjList[i].firstArc = node;
            }
    G->n = n, G->e = e;
    return G;
}
void disAdj(AdjGraph *G)
{
    ArcNode *node;
    for (int i = 0; i < G->n; i++)
    {
        node = G->adjList[i].firstArc;
        cout << i << ":";
        while (node != NULL)
        {
            cout << node->adjvex << "[" << node->weight << "]";
            node = node->nextArc;
        }
        cout << endl;
    }
}
void destroyAdj(AdjGraph *&G)
{
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; i++)
    {
        pre = G->adjList[i].firstArc;
        if(pre!=NULL){
            p = pre->nextArc;
            while (p!=NULL)
            {
                free(pre);
                pre = p;
                p = pre->nextArc;
            }
            free(pre);
        }
    }
    free(G);
}
