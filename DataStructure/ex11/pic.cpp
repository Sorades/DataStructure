/**
 * 要满足|n1-n2|最小，则平分该集合
 * 设从第d个元素将该集合划分为两个子集，d=n/2
 * 只要使得d元素之前的元素都比d小，之后的元素都比d大，即满足|S1-S2|最大
 * 故采用快速排序
*/
#include <cmath>
#include <iostream>
#define maxR 10
using namespace std;

int partition(int rec[], int front, int rear);
void quickSort(int rec[], int front, int rear, int &pos, int n);
void solution(int rec[], int n);

int main()
{
    int src[] = {99, 85, 43, 46, 888, 94, 11, 2, 6};
    int sss[] = {0, 51, 56, 33, 84, 89, 12, 23};
    int te[] = {0, 0, 0, 55, 86, 89};
    solution(src, sizeof(src) / sizeof(src[0]) - 1);
    return 0;
}
int partition(int rec[], int front, int rear)
{
    int temp = rec[front];
    while (front < rear)
    {
        while (rear > front && rec[rear] >= temp) //后半部分有小于基准数的则前移
            rear--;
        rec[front] = rec[rear];
        while (front < rear && rec[front] <= temp) //前半部分有大于基准的则后移
            front++;
        rec[rear] = rec[front];
    }
    rec[front] = temp; //基准数归位
    return front;      //返回归位的元素位置
}
void quickSort(int rec[], int front, int rear, int &pos, int n)
{
    if (pos != -1)
        return;
    if (front < rear)
    {
        int i = partition(rec, front, rear);
        if (i == n / 2)
            pos = i;
        quickSort(rec, front, i - 1, pos, n);
        quickSort(rec, i + 1, rear, pos, n);
    }
}
void solution(int rec[], int n)
{
    cout << "划分前：";
    for (int i = 0; i <= n; i++)
        cout << rec[i] << " ";
    cout << endl;
    int pos = -1;
    quickSort(rec, 0, n, pos, n);
    cout << "划分后：\n";
    for (int i = 0; i < n / 2; i++)
        cout << rec[i] << " ";
    cout << endl;
    for (int i = n / 2; i <= n; i++)
        cout << rec[i] << " ";
    cout << endl;
}
