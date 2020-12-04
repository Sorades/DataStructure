#include <iostream>
#define N 6
using namespace std;
typedef int elemType;
struct TupNode
{
    int r; //行
    int c; //列
    elemType d;
};
struct TSMatrix
{
    int rows; //行数
    int cols; //列数
    int nums; //非零元素个数
    TupNode data[N * N];
};
void creatMat(TSMatrix &ts, elemType max[N][N]);
int diagCal(TSMatrix ts);

int main()
{
    int B[N][N] = {0, 0, 0, 5, 1, 0,
                   0, 5, 0, 0, 0, 0,
                   3, 0, 1, 6, 0, 6,
                   0, 0, 0, 8, 0, 0,
                   2, 0, 1, 0, 3, 0,
                   0, 0, 0, 0, 0, 1};
    TSMatrix TS;
    creatMat(TS, B);
    cout << "该稀疏矩阵的对角线之和为：" << diagCal(TS) << endl;
    return 0;
}

void creatMat(TSMatrix &ts, elemType max[N][N])
{
    ts.rows = ts.cols = N;
    ts.nums = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (max[i][j] != 0)
            {
                ts.data[ts.nums].r = i;
                ts.data[ts.nums].c = j;
                ts.data[ts.nums].d = max[i][j];
                ts.nums++;
            }
        }
}

int diagCal(TSMatrix ts)
{
    int sum = 0;
    for (int i = 0; i < ts.nums; i++)
    {
        if (ts.data[i].r == ts.data[i].c)
            sum += ts.data[i].d;
        if(ts.data[i].r+ts.data[i].c==N-1)
            sum += ts.data[i].d;
    }
    return sum;
}
