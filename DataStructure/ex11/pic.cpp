/**
 * ʹ�������ϵ�Ԫ�ظ�����d<=1
 * ����һ�����ϴ��С�����������һ�����ϴӴ�С������
 * ��nΪż������d=0���ֱ���������Ԫ�غ͵Ĳ��
 * ��nΪ��������d=1�������������n1���󣬻�n2�������ѡȡԪ�غ�֮���������
 * ���ǵ�����Ԫ��Ϊ��������ѡ���������
*/
#include <iostream>
#include <cmath>
#define maxR 10
using namespace std;

int src[] = {99, 85, 43, 46, 888, 94, 11, 2, 6};

int maxbit(int data[], int n);
void radixSort(int data[], int n);
int sum(int data[], int n, int length, bool flag);
void output(int data[], int n, int length, bool flag);
void solution(int data[], int n);

int main()
{
    solution(src, 9);
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
        for (int j = n - 1; j > n; j--)
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
        for (int i = length - 1; i >= n; i++)
            sum += data[i];
    return sum;
}
void output(int data[], int n, int length, bool flag)
{
    if (flag)//flagΪtrue�����ǰ��
    { 
        for(int i=0;i<n;i++)
            cout << "\t" << data[i];
        cout << endl;
    }
    else
    {
        for(int i=n;i<length;i++)
            cout << "\t" << data[i];
        cout << endl;
    }
    
}
void solution(int data[], int n)
{
    int n1, n2;
    int sum1, sum2;
    radixSort(data, n);
    if (n % 2 == 1)
    {
        n1 = n / 2;//��һ�����
        sum1 = abs(sum(data, n1, n, true) - sum(data, n1, n, false));
        n2 = n / 2 + 1;//�ڶ������
        sum2 = abs(sum(data, n2, n, true) - sum(data, n2, n, false));
        if(sum1>sum2)
        {
            cout << "S1:\n";
            output(data, n1, n, true);
            cout << "S2:\n";
            output(data, n - n1, n, false);
        }else
        {
            cout << "S1:\n";
            output(data, n2, n, true);
            cout << "S2:\n";
            output(data, n - n2, n, false);
        }
        
    }
    else
    {
        n1 = n2 = n / 2;
        cout << "S1:\n";
        output(data, n1, n, true);
        cout << "S2:\n";
        output(data, n2, n, false);
    }
}
