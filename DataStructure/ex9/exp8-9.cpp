#include "graph.cpp"

struct KeyNode
{
    int ino;
    int eno;
};

bool topSort(AdjGraph *G, int topseq[]);
bool keyPath(AdjGraph *G, int &iNode, int &eNode, KeyNode keynode[], int &d);
void dispKeynode(AdjGraph *G);

int main()
{
    MatGraph *mat = creatMat(map);
    AdjGraph *G = creatAdj(mat);
    cout << "建立图邻接表...\n";
    cout << "图的邻接表：\n";
    disAdj(G);
    dispKeynode(G);
    disAdj(G);
    return 0;
}
bool topSort(AdjGraph *G, int topseq[])
{
    int stack[maxV], top = -1;
    int n = 0, i, j;
    ArcNode *p;
    for (i = 0; i < G->n; i++)
        G->adjList[i].count = 0;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjList[i].firstArc;
        while (p != NULL)
        {
            G->adjList[p->adjvex].count++;
            p = p->nextArc;
        }
    }
    for (i = 0; i < G->n; i++)
        if (G->adjList[i].count == 0)
            stack[++top] = i;
    while (top > -1)
    {
        i = stack[top--];
        topseq[n] = i;
        n++;
        p = G->adjList[i].firstArc;
        while (p != NULL)
        {
            j = p->adjvex;
            G->adjList[j].count--;
            if (G->adjList[j].count == 0)
                stack[++top] = j;
            p = p->nextArc;
        }
    }
    if (n < G->n)
        return false;
    else
    {
        cout << "拓扑序列：\n";
        for (i = 0; i < n; i++)
            cout << (char)(topseq[i] + 'A');
        cout << endl;
        return true;
    }
}
bool keyPath(AdjGraph *G, int &iNode, int &eNode, KeyNode keynode[], int &d)
{
    int topseq[maxV];
    ArcNode *p;
    int w;
    if (!topSort(G, topseq))
        return false;
    iNode = topseq[0];
    eNode = topseq[G->n - 1];
    int ve[maxV];
    int vl[maxV];
    for (int i = 0; i < G->n; i++)
        ve[i] = 0;
    for (int i = 0; i < G->n; i++)
    {
        p = G->adjList[i].firstArc;
        while (p != NULL)
        {
            w = p->adjvex;
            if (ve[i] + p->weight > ve[w])
                ve[w] = ve[i] + p->weight;
            p = p->nextArc;
        }
    }
    for (int i = 0; i < G->n; i++)
        vl[i] = ve[eNode];
    for (int i = G->n - 2; i >= 0; i--)
    {
        p = G->adjList[i].firstArc;
        while (p != NULL)
        {
            w = p->adjvex;
            if (vl[w] - p->weight < vl[i])
                vl[i] = vl[w] - p->weight;
            p = p->nextArc;
        }
    }
    d = -1;
    for (int i = 0; i < G->n; i++)
    {
        p = G->adjList[i].firstArc;
        while (p != NULL)
        {
            w = p->adjvex;
            if (ve[i] == vl[w] - p->weight)
            {
                d++;
                keynode[d].ino = i;
                keynode[d].eno = w;
            }
            p = p->nextArc;
        }
    }
    return true;
}
void dispKeynode(AdjGraph *G)
{
    int iNode, eNode, d, i;
    KeyNode keyNode[maxV];
    if (keyPath(G, iNode, eNode, keyNode, d))
    {
        cout << "从源点" << char(iNode + 'A') << "到汇点" << char(eNode + 'A') << "的关键活动：";
        for (int i = 0; i <= d; i++)
            cout << "(" << char(keyNode[i].ino + 'A') << "," << char(keyNode[i].eno + 'A') << ")";
        cout << endl;
    }
    else
        cout << "不能求关键活动\n";
}
