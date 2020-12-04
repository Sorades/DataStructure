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
        if (B[k][0] <= val)//比较行首
        {
            if (B[k][n - 1] >= val)//比较行尾
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
    cout << "总共比较" << count << "次\ni = " << i << ", j = " << j << endl;
    return 0;
}
