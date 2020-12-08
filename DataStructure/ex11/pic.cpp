/**
 * Ҫ����|n1-n2|��С����ƽ�ָü���
 * ��ӵ�d��Ԫ�ؽ��ü��ϻ���Ϊ�����Ӽ���d=n/2
 * ֻҪʹ��dԪ��֮ǰ��Ԫ�ض���dС��֮���Ԫ�ض���d�󣬼�����|S1-S2|���
 * �ʲ��ÿ�������
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
        while (rear > front && rec[rear] >= temp) //��벿����С�ڻ�׼������ǰ��
            rear--;
        rec[front] = rec[rear];
        while (front < rear && rec[front] <= temp) //ǰ�벿���д��ڻ�׼�������
            front++;
        rec[rear] = rec[front];
    }
    rec[front] = temp; //��׼����λ
    return front;      //���ع�λ��Ԫ��λ��
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
    cout << "����ǰ��";
    for (int i = 0; i <= n; i++)
        cout << rec[i] << " ";
    cout << endl;
    int pos = -1;
    quickSort(rec, 0, n, pos, n);
    cout << "���ֺ�\n";
    for (int i = 0; i < n / 2; i++)
        cout << rec[i] << " ";
    cout << endl;
    for (int i = n / 2; i <= n; i++)
        cout << rec[i] << " ";
    cout << endl;
}
