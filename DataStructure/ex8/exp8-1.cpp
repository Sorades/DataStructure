#include "graph.cpp"
using namespace std;
void destroyAdj(AdjGraph *G);

int main()
{
    MatGraph *mat = creatMat(matrix);
    disMat(mat);
    AdjGraph *G = creatAdj(mat);
    disAdj(G);
    destroyAdj(G);
    return 0;
}
void destroyAdj(AdjGraph *G)
{
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; i++)
    {
        pre = G->adjList[i].firstArc;
        if (pre != NULL)
        {
            p = pre->nextArc;
            while (p != NULL)
            {
                free(pre);
                pre = p;
                p = p->nextArc;
            }
            free(pre);
        }
    }
    free(G);
    cout << "ÒÑÏú»Ù...\n";
}
