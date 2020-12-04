#include "StringCons.h"

int find(QString s, QString t);

int main()
{
    char cs[] = {"abcdabcabc"};
    char ct[] = {"d*c"};
    QString s, t;
    strAssign(s, cs);
    strAssign(t, ct);

    cout<<"对于s，模板t的一个字串的位置为：" << find(s, t) << endl;
    return 0;
}
int find(QString s, QString t)
{
    int ps = 0, pt = 0;
    int i;
    while (ps < s.length && pt < t.length)
    {
        if (t.data[pt] == '*')
        {
            i = find(subStr(s, ps + 2, s.length - ps - 1), subStr(t, pt + 2, t.length - pt - 1));
            pt++;
            if (i > -1)
                return ps - 1;
            else
                return -1;
        }
        else if (s.data[ps] == t.data[pt])
            ps++, pt++;
        else
        {
            ps = ps - pt + 1;
            pt = 0;
        }
    }
    if (pt >= t.length)
        return ps - 1;
    else
        return -1;
}