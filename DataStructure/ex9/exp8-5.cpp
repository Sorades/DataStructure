#include <iostream>
#define maxV 6
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
void prim(MatGraph *mat);

int main()
{
    MatGraph *mat = creatMat(map);
    cout <<"最小生成树如下：\n";
    prim(mat);
    return 0;
}
MatGraph *creatMat(int matrix[][maxV])
{
    MatGraph *mat = (MatGraph *)malloc(sizeof(MatGraph));
    int i, e = 0;
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
    mat->e = e, mat->n = i;
    return mat;
}
void prim(MatGraph *mat)
{
    int lowcost[maxV];
    int MIN, k;
    int closest[maxV];
    for (int i = 0; i < mat->n; i++)
    {
        lowcost[i] = mat->edges[0][i];
        closest[i] = 0;
    }
    for (int i = 1; i < mat->n; i++)
    {
        MIN = INF;
        for (int j = 0; j < mat->n; j++)
            if (lowcost[j] != 0 && lowcost[j] < MIN)
            {
                MIN = lowcost[j];
                k = j;
            }
        cout << "边(" << closest[k] << "," << k << ")权为：" << MIN << endl;
        lowcost[k] = 0;
        for (int j = 0; j < mat->n; j++)
            if (lowcost[j] != 0 && mat->edges[k][j] < lowcost[j])
            {
                lowcost[j] = mat->edges[k][j];
                closest[j] = k;
            }
    }
}