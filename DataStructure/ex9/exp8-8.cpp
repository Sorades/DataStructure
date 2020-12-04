#include <iostream>
#define maxV 6
#define INF 0x3f3f3f
using namespace std;
typedef char infoType;
int map[][maxV] = {0, 5, INF, 7, INF, INF,
                   INF, 0, 4, INF, INF, INF,
                   8, INF, 0, INF, INF, 9,
                   INF, INF, 5, 0, INF, 6,
                   INF, INF, INF, 5, 0, INF,
                   3, INF, INF, INF, 1, 0};
struct VertexType
{
    int no;
    infoType info;
};
struct MatGraph
{
    int edges[maxV][maxV];
    int num, side;
    VertexType vex[maxV];
};
MatGraph *creatMat(int map[][maxV]);
void Floyd(MatGraph *G);
void Dispath(MatGraph *g, int A[][maxV], int path[][maxV]);

int main()
{
    MatGraph *mat = creatMat(map);
    Floyd(mat);
    return 0;
}

MatGraph *creatMat(int map[][maxV])
{
    MatGraph *mat = new MatGraph;
    int i, side = 0;
    for (i = 0; i < maxV; i++)
    {
        mat->vex[i].no = i;
        for (int j = 0; j < maxV; j++)
        {
            mat->edges[i][j] = map[i][j];
            if (map[i][j] != INF && map[i][j] != 0)
                side++;
        }
    }
    mat->side = side, mat->num = i;
    return mat;
}
void Floyd(MatGraph *G)
{
    int A[maxV][maxV], path[maxV][maxV];
    for (int i = 0; i < G->num; i++)
        for (int j = 0; j < G->num; j++)
        {
            A[i][j] = G->edges[i][j];
            if (i != j && G->edges[i][j] < INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    for (int k = 0; k < G->num; k++)
    {
        for (int i = 0; i < G->num; i++)
            for (int j = 0; j < G->num; j++)
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
    }
    Dispath(G, A, path);
}
void Dispath(MatGraph *g, int A[][maxV], int path[][maxV])
{
    int apath[maxV], k, d;
    for (int i = 0; i < g->num; i++)
        for (int j = 0; j < g->num; j++)
        {
            if (A[i][j] != INF && i != j)
            {
                cout << "从" << i << "到" << j << "的路径为：";
                k = path[i][j];
                d = 0;
                apath[d] = j;
                while (k != -1 && k != i)
                {
                    d++;
                    apath[d] = k;
                    k = path[i][k];
                }
                d++;
                apath[d] = i;
                cout << apath[d];
                for (int s = d - 1; s >= 0; s--)
                    cout << "," << apath[s];
                cout << "\t路径长度为：" << A[i][j] << endl;
            }
        }
}
