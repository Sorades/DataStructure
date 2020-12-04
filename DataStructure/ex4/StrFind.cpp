#include "StringCons.h"

void KMPIndex(QString str, QString substr);
void getNextVal(QString str, int *nextval);

int main()
{
    char s[] = {"abcabcabcd"};
    char t[] = {"abcab"};
    QString strS, strT;
    strAssign(strS, s);
    strAssign(strT, t);
    KMPIndex(strS, strT);

    return 0;
}


void KMPIndex(QString str, QString substr)
{
    int *next = new int[str.length];
    int *answer = new int(-1);
    int count = 0;
    getNextVal(substr, next);
    int i = 0, j = 0;
    while (i < str.length)
    {
        if (j == -1 || str.data[i] == substr.data[j])
            i++, j++;
        else
            j = next[j];
        if (j >= substr.length&&answer[count-1]!=i-substr.length)
        {
            answer[count++] = i - substr.length;
            i = count;
            j = 0;
        }
    }
    cout << "子串出现" << count << "次，字串首位置如下：\n";
    for(int i=0;i<count;i++)
        cout << answer[i] << "\t";
    cout << endl;
}
void getNextVal(QString str, int *nextval)
{
    nextval[0] = -1;
    int ptr = 0, nextnum = -1;
    while (ptr < str.length)
    {
        if (nextnum == -1 || str.data[ptr] == str.data[nextnum])
        {
            ptr++;
            nextnum++;
            if (str.data[ptr] != str.data[nextnum])
                nextval[ptr] = nextnum;
            else
                nextval[ptr] = nextval[nextnum];
        }
        else
            nextnum = nextval[nextnum];
    }
}
