#include <iostream>
#define maxSize 100
using namespace std;
struct QString
{
    char data[maxSize];
    int length;
};

void strAssign(QString &str, char cstr[])
{
    int i = 0;
    for (i = 0; cstr[i] != '\0'; i++)
        str.data[i] = cstr[i];
    str.length = i;
}
void destroyStr(QString &str)
{
}
void strCopy(QString &str, QString matrix)
{
    for (int i = 0; i < matrix.length; i++)
    {
        str.data[i] = matrix.data[i];
    }
    str.length = matrix.length;
}
bool isEqual(QString str, QString target)
{
    int i;
    if (str.length != target.length)
        return false;
    else
        for (i = 0; i < str.length; i++)
            if (str.data[i] != target.data[i])
                return false;
    return true;
}
int length(QString str)
{
    return str.length;
}
QString connect(QString str1, QString str2)
{
    QString str;
    str.length = str1.length + str2.length;
    for (int i = 0; i < str1.length; i++)
        str.data[i] = str1.data[i];
    for (int i = 0; i < str2.length; i++)
        str.data[i] = str2.data[i];
    return str;
}
//第head个字符开始的，由num个连续字符组成的字串
QString subStr(QString str, int head, int num)
{
    QString s;
    s.length = 0;
    if (head <= 0 || num < 0 || head > str.length || head + num - 1 > str.length)
        return s;
    for (int i = 0; i < head + num; i++)
        s.data[i] = str.data[i + head - 1];
    s.length = num;
    return s;
}
//将str插入matrix的第index个位置上
QString insStr(QString matrix, int index, QString str)
{
    QString temp;
    str.length = 0;
    if (index <= 0 || index > matrix.length + 1 || matrix.length + str.length > maxSize)
        return temp;
    temp = subStr(matrix, 1, index - 1);
    for (int i = 0; i < str.length; i++)
        temp.data[index + i - 1] = str.data[i];
    for (int i = index; i < matrix.length; i++)
        temp.data[str.length + i - 1] = matrix.data[i];
    return temp;
}
QString delStr(QString str, int head, int num)
{
    QString s;
    str.length = 0;
    if (head <= 0 || head > str.length || head + num > str.length + 1)
        return s;
    for (int i = 0; i < head - 1; i++)
        s.data[i] = str.data[i];
    for (int i = head + num - 1; i < str.length; i++)
        s.data[head - num] = str.data[i];
    s.length = str.length - num;
    return s;
}
QString repStr(QString str, int head, int end, QString sub)
{
    QString s;
    s.length = 0;
    if (head <= 0 || head > str.length || head + end - 1 > str.length)
        return str;
    for (int i = 0; i < head - 1; i++)
        s.data[i] = str.data[i];
    for (int i = 0; i < sub.length; i++)
        s.data[head + i - 1] = sub.data[i];
    for (int i = head + end - 1; i < str.length; i++)
        s.data[sub.length + i - end] = str.data[i];
    s.length = str.length - end;
    return s;
}
void dispStr(QString str)
{
    if (str.length > 0)
    {
        for (int i = 0; i < str.length; i++)
            cout << str.data[i];
        cout << endl;
    }
}