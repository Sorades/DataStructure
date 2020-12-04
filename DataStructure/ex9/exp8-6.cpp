#include <iostream>
#define maxV 6
#define maxSize 20
#define INF 0x3f3f3f
using namespace std;
typedef char infoType;
int map[][maxV] = {0, 5, 8, 7, INF, 3,
                   5, 0, 4, INF, INF, INF,
                   8, 4, 0, 5, INF, 9,
                   7, INF, 5, 0, 5, 6,
                   INF, INF, INF, 5, 0, 1,
                   3, INF, 9, 6, 1, 0};
typedef struct
{
    int head;
    int end;
    int weight;
} Edge;
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
MatGraph *creatMat(int matrix[][maxV]);
void kruskal(MatGraph *G);
void insertSort(Edge *e, int sides);

int main()
{
    MatGraph *mat = creatMat(map);
    cout << "最小生成树如下：\n";
    kruskal(mat);
    return 0;
}
MatGraph *creatMat(int matrix[][maxV])
{
    MatGraph *mat = new MatGraph;
    int e = 0, i;
    for (i = 0; i < maxV; i++)
    {
        mat->vex[i].no = i;
        for (int j = 0; j < maxV; j++)
        {
            mat->edges[i][j] = matrix[i][j];
            if (matrix[i][j] != 0 && matrix[i][j] != INF)
                e++;
        }
    }
    mat->e = e / 2, mat->n = i;
    return mat;
}
void kruskal(MatGraph *G)
{
    int vset[maxV];
    Edge E[maxSize];
    int ei = 0; //e数组的下标
    for (int i = 0; i < G->n; i++)
        for (int j = 0; j <= i; j++)
            if (G->edges[i][j] != 0 && G->edges[i][j] != INF)
            {
                E[ei].head = i;
                E[ei].end = j;
                E[ei].weight = G->edges[i][j];
                ei++;
            }
    insertSort(E, G->e);
    for (int i = 0; i < G->n; i++)
        vset[i] = i;
    ei = 0;
    int side = 1;
    int headT, endT, sn1, sn2;
    while (side < G->n)
    {
        headT = E[ei].head;
        endT = E[ei].end;
        sn1 = vset[headT];
        sn2 = vset[endT];
        if (sn1 != sn2)
        {
            cout << "(" << headT << "," << endT << "):" << E[ei].weight << endl;
            ei++;
            for (int i = 0; i < G->n; i++)
                if (vset[i] == sn2)
                    vset[i] = sn1;
        }
        side++;
    }
}
void insertSort(Edge *e, int sides)
{
    int j, i;
    Edge temp;
    for (i = 1; i < sides; i++)
    {
        j = i;
        temp = e[i];
        while (j > 0 && temp.weight < e[j - 1].weight)
        {
            e[j] = e[j - 1];
            j--;
        }
        e[j] = temp;
    }
}
