#include <iostream>
using namespace std;
int *func(int a[], int n);
int main()
{
    int n = 6;
    int a[n] = {3, 5, 2, 4, 1, 6};
    int *b = func(a, n);
    cout << "排序后的数组：\n";
    for(int i=0;i<n;i++)
        cout << b[i] << ",";
    return 0;
}
int *func(int a[], int n)
{
    int *b = new int[n];
    for (int i = 0; i < n; i++)
        b[a[i]-1] = a[i];
    return b;
}
