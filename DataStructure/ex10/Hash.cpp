#include <iostream>
#define maxSize 13
#define NULLKEY -1
#define DELKEY -2
using namespace std;
typedef int keyType;
typedef char *infoType;
typedef struct hash
{
    keyType key;
    infoType data;
    int count;
} HashTable;

void creatHT(HashTable ha[], int &n, int m, int p, keyType keys[], int n1);
void insertHT(HashTable ha[], int &n, int m, int p, keyType k);
int searchHT(HashTable ha[], int p, int m, keyType k);

int main()
{
    int n1 = 11, n = 0;
    keyType keys[n1] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
    HashTable ha[maxSize];
    int p = maxSize;
    creatHT(ha, n, maxSize, p, keys, n1);
    //cout << searchHT(ha, p, maxSize, 16);
    for(int i=0;i<n1;i++)
        cout << keys[i] << ":" << searchHT(ha, p, maxSize, keys[i]) << endl;
    return 0;
}

void creatHT(HashTable ha[], int &n, int m, int p, keyType keys[], int n1)
{
    for (int i = 0; i < m; i++)
    {
        ha[i].key = NULLKEY;
        ha[i].count = 0;
    }
    n = 0;
    for (int i = 0; i < n1; i++)
        insertHT(ha, n, m, p, keys[i]);
}
void insertHT(HashTable ha[], int &n, int m, int p, keyType k)
{
    int i, adr;
    adr = k % p;
    if (ha[adr].key == NULLKEY || ha[adr].key == DELKEY)
    {
        ha[adr].key = k;
        ha[adr].count = 1;
    }
    else
    {
        i = 1;
        do
        {
            adr = (adr + 1) % m;
            i++;
        } while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY);
        ha[adr].key = k;
        ha[adr].count = i;
    }
    n++;
}

int searchHT(HashTable ha[], int p, int m, keyType k)
{
    int adr, adr1, i = 1, sign;
    adr = adr1 = k % p; //求哈希函数值
    sign = 1;
    while (ha[adr].key != NULLKEY && ha[adr].key != k)
    {
        adr = (adr1 + sign * i * i) % m;
        if (sign == 1)
            sign = -1;
        else
        {
            sign = 1;
            i++;
        }
        
    }
    if (ha[adr].key == k)
        return adr; //查找成功
    else
        return -1; //查找失败
}
