#include <iostream>
#define m 4
#define n 3
using namespace std;

int B[m][n] = {1, 2, 3,
               3, 4, 5,
               4, 5, 6,
               5, 6, 7};
int val = 7, count = 0;

int main()
{
    int i, j;
    for (int k = 0; k < m; k++)
    {
        count++;
        if (B[k][0] <= val)//�Ƚ�����
        {
            if (B[k][n - 1] >= val)//�Ƚ���β
                for (int f = 0; f < n; f++)
                {
                    count++;
                    if (B[k][f] == val)
                        i = k, j = f;
                }
            else
                continue;
        }
        else
            continue;
    }
    cout << "�ܹ��Ƚ�" << count << "��\ni = " << i << ", j = " << j << endl;
    return 0;
}
