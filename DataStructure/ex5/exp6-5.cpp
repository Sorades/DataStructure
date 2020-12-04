#include <iostream>
#define N 6
using namespace std;

void putOut(int X[]);
void putIn(int x[]);
void add(int a[], int b[]);
void multi(int a[], int b[]);

int main()
{
    int a[N*(N+1)/2], b[N*(N+1)/2];
    cout << "A��B��ΪN��N�ĶԳƾ���(N = 6)\n��������������������Ԫ�أ�\nA:\n";
    putIn(a);
    cout << "B:\n";
    putIn(b);
    cout << "����ĺͣ�\n";
    add(a, b);

    cout << "����ĳ˻���\n";
    multi(a, b);

    return 0;
}

void putOut(int X[])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (i >= j)
                cout << X[i * (i + 1) / 2 + j] << "\t";
            else
                cout << X[j * (j + 1) / 2 + i] << "\t";
        cout << endl;
    }
}
void putIn(int x[])
{
    for (int i = 0; i < N; i++)
    {
        cout << "��" << i + 1 << "�У�";
        for (int j = 0; j < i + 1; j++)
            cin >> x[i * (i + 1) / 2 + j];
    }
}
void add(int a[], int b[])
{
    int x[N*(N+1)/2];
    for (int i = 0; i < N * (N + 1) / 2; i++)
        x[i] = a[i] + b[i];
    putOut(x);
}
void multi(int a[], int b[])
{
    int X[N][N] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {

                if (i >= k)
                {
                    if (k >= j)

                        X[i][j] += a[i * (i + 1) / 2 + k] * b[k * (k + 1) / 2 + j];
                    else
                        X[i][j] += a[i * (i + 1) / 2 + k] * b[j * (j + 1) / 2 + k];
                }
                else
                {
                    if (k >= j)
                        X[i][j] += a[k * (k + 1) / 2 + i] * b[k * (k + 1) / 2 + j];
                    else
                        X[i][j] += a[k * (k + 1) / 2 + i] * b[j * (j + 1) / 2 + k];
                }
            }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << X[i][j] << "\t";
        cout << endl;
    }
}
