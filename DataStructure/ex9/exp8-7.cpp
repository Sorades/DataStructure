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
void dijkstra(MatGraph *G, int v);
void dispath(MatGraph *G, int dist[], int path[], int S[], int v);

int main()
{
    MatGraph *mat = creatMat(map);
    dijkstra(mat, 0);
    return 0;
}
MatGraph *creatMat(int map[][maxV])
{
    MatGraph *mat = new MatGraph;
    int side = 0, i;
    for (i = 0; i < maxV; i++)
    {
        mat->vex[i].no = i;
        for (int j = 0; j < maxV; j++)
        {
            mat->edges[i][j] = map[i][j];
            if (map[i][j] != 0 && map[i][j] != INF)
                side++;
        }
    }
    mat->num = i, mat->side = side;
    return mat;
}
void dijkstra(MatGraph *G, int v)
{
    int dist[maxV], path[maxV];
    int S[maxV];
    int minDis, u;
    for (int i = 0; i < G->num; i++)
    {
        dist[i] = G->edges[v][i];
        S[i] = 0;
        if (G->edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    S[v] = 1;
    path[v] = 0;
    for (int i = 0; i < G->num - 1; i++)
    {
        minDis = INF;
        for (int j = 0; j < G->num; j++)
            if (S[j] == 0 && dist[j] < minDis)
            {
                u = j;
                minDis = dist[j];
            }
        S[u] = 1;
        for (int j = 0; j < G->num; j++)
            if (S[j] == 0)
                if (G->edges[u][j] < INF && dist[u] + G->edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + G->edges[u][j];
                    path[j] = u;
                }
    }
    dispath(G, dist, path, S, v);
}
void dispath(MatGraph *G, int dist[], int path[], int S[], int v)
{
    int apath[maxV], d, k;
    for (int i = 0; i < G->num; i++)
        if (S[i] == 1 && i != v)
        {
            cout << "从顶点" << v << "到顶点" << i << "的路径长度为：" << dist[i] << "\t路径为：";
            d = 0;
            apath[d] = i;
            k = path[i];
            if (k == -1)
                cout << "无路径\n";
            else
            {
                while (k != v)
                {
                    d++;
                    apath[d] = k;
                    k = path[k];
                }
                d++;
                apath[d] = v;
                cout << apath[d];
                for (int j = d - 1; j >= 0; j--)
                    cout << "," << apath[j];
                cout << endl;
            }
        }
}