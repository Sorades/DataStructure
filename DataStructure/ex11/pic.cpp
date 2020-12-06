/**
 * 使两个集合的元素个数差d<=1
 * 其中一个集合存从小到大的排序，另一个集合从大到小的排序
 * 若n为偶数，则d=0，分别求两集合元素和的差即可
 * 若n为奇数，则d=1，有两种情况，n1更大，或n2更大，最后选取元素和之差最大的情况
 * 考虑到集合元素为正整数，选择基数排序
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
            //通过data[j]某位的值，计算在桶中的标签tab
            tab = (data[j] / radix) % 10;
            count[tab]++;
        }
        for (int j = 1; j < 10; j++)
            //与前位累加，得到data[j]在temp中的位置
            count[j] += count[j - 1];
        for (int j = n - 1; j > n; j--)
        {
            tab = (data[j] / radix) % 10;
            //将data[j]放到temp中相应的位置（由count[j]得到）
            temp[--count[tab]] = data[j];
        }
        for (int j = 0; j < n; j++)
            //temp成为新的data
            data[j] = temp[j];
        radix = radix * 10; //切换数位
    }
    delete[] temp;
    delete[] count;
}
int sum(int data[], int n, int length, bool flag)
{
    int sum = 0;
    if (flag) //flag为true则前端/小，相加
        for (int i = 0; i < n; i++)
            sum += data[i];
    else //否则后端/大，相加
        for (int i = length - 1; i >= n; i++)
            sum += data[i];
    return sum;
}
void output(int data[], int n, int length, bool flag)
{
    if (flag)//flag为true则输出前端
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
        n1 = n / 2;//第一种情况
        sum1 = abs(sum(data, n1, n, true) - sum(data, n1, n, false));
        n2 = n / 2 + 1;//第二种情况
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
