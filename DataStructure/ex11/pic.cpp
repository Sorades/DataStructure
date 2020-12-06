/**
 * ʹ�������ϵ�Ԫ�ظ�����d<=1
 * ����һ�����ϴ��С�����������һ�����ϴӴ�С������
 * ��nΪż������d=0���ֱ���������Ԫ�غ͵Ĳ��
 * ��nΪ��������d=1��ѡȡԪ�غ�֮�������������������ķֶ�ǰ���ȡֵ��Ϊn��һ��
 * ���ǵ�����Ԫ��Ϊ��������ѡ���������
*/
#include <cmath>
#include <iostream>
#define maxR 10
using namespace std;

int src[] = {99, 85, 43, 46, 888, 94, 11, 2, 6};
int sss[] = {0, 51, 56, 33, 84, 89, 12, 23};
int te[] = {0, 0, 0, 55, 86, 89};

int maxbit(int data[], int n);
void radixSort(int data[], int n);
int sum(int data[], int n, int length, bool flag);
void output(int data[], int n, int length);
void solution(int data[], int n);

int main()
{
    int length = sizeof(src) / sizeof(src[0]);
    solution(src, length);
    cout << "=========================\n";
    length = sizeof(sss) / sizeof(sss[0]);
    solution(sss, length);
    cout << "=========================\n";
    length = sizeof(te) / sizeof(te[0]);
    solution(te, length);
    return 0;
}
int maxbit(int data[], int n)
{
    int maxData = data[0];
    for (int i = 0; i < n; i++)
        if (maxData < data[i])
            maxData = data[i];
    int d = 0;
    while (maxData > 0)
    {
        maxData /= 10;
        d++;
    }
    return d;
}
void radixSort(int data[], int n)
{
    int d = maxbit(data, n);
    int *temp = new int[n];
    int *count = new int[10];
    int radix = 1;
    int tab;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < 10; j++)
            count[j] = 0;
        for (int j = 0; j < n; j++)
        {
            //ͨ��data[j]ĳλ��ֵ��������Ͱ�еı�ǩtab
            tab = (data[j] / radix) % 10;
            count[tab]++;
        }
        for (int j = 1; j < 10; j++)
            //��ǰλ�ۼӣ��õ�data[j]��temp�е�λ��
            count[j] += count[j - 1];
        for (int j = n - 1; j >= 0; j--)
        {
            tab = (data[j] / radix) % 10;
            //��data[j]�ŵ�temp����Ӧ��λ�ã���count[j]�õ���
            temp[--count[tab]] = data[j];
        }
        for (int j = 0; j < n; j++)
            //temp��Ϊ�µ�data
            data[j] = temp[j];
        radix = radix * 10; //�л���λ
    }
    delete[] temp;
    delete[] count;
}
int sum(int data[], int n, int length, bool flag)
{
    int sum = 0;
    if (flag) //flagΪtrue��ǰ��/С�����
        for (int i = 0; i < n; i++)
            sum += data[i];
    else //������/�����
        for (int i = n; i < length; i++)
            sum += data[i];
    return sum;
}
void output(int data[], int n, int length)
{
    cout << "S1:";
    for (int i = 0; i < n; i++)
        cout << "\t" << data[i];
    cout << endl;
    cout << "S2:";
    for (int i = n; i < length; i++)
        cout << "\t" << data[i];
    cout << endl;
}
void solution(int data[], int n)
{
    radixSort(data, n);
    output(data, n / 2, n);
}
