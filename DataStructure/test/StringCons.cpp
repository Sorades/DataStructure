#include <iostream>
#define maxSize 100
using namespace std;
class QString
{
public:
    char data[maxSize];
    int len;
    void strAssign(QString &str, char cstr[]);
    void destroyStr(QString &str);
    void strCopy(QString &str, QString matrix);
    bool isEqual(QString str, QString target);
    int length(QString str);
    QString connect(QString str1, QString str2);
    QString subStr(QString str, int head, int end);
    QString insStr(QString matrix, int index, QString str);
    QString delStr(QString str, int head, int num);
    QString repStr(QString str, int head, int end, QString sub);
    QString dispStr(QString str);
};
int main()
{

    return 0;
}
void QString::strAssign(QString &str, char cstr[])
{
    int i = 0;
    for (i = 0; cstr[i] != '\0'; i++)
        str.data[i] = cstr[i];
    str.len = i;
}
void QString::destroyStr(QString &str)
{
}
void QString::strCopy(QString &str, QString matrix)
{
    for (int i = 0; i < matrix.len; i++)
    {
        str.data[i] = matrix.data[i];
    }
    str.len = matrix.len;
}
bool QString::isEqual(QString str, QString target)
{
    int i;
    if (str.len != target.len)
        return false;
    else
        for (int i = 0; i < str.len; i++)
            if (str.data[i] != target.data[i])
                return false;
    return true;
}
int QString::length(QString str)
{
    return str.len;
}
QString QString::connect(QString str1, QString str2)
{
    QString str;
    str.len = str1.len + str2.len;
    for (int i = 0; i < str1.len; i++)
        str.data[i] = str1.data[i];
    for (int i = 0; i < str2.len; i++)
        str.data[i] = str2.data[i];
    return str;
}
//第head个字符开始的，由num个连续字符组成的字串
QString QString::subStr(QString str, int head, int num)
{
    QString s;
    s.len = 0;
    if (head <= 0 || num < 0 || head > str.len || head + num - 1 > str.len)
        return s;
    for (int i = 0; i < head + num; i++)
        s.data[i] = str.data[i + head - 1];
    s.len = num;
    return s;
}
//将str插入matrix的第index个位置上
QString QString::insStr(QString matrix, int index, QString str)
{
    QString temp;
    str.len = 0;
    if (index <= 0 || index > matrix.len + 1 || matrix.len + str.len > maxSize)
        return temp;
    temp = subStr(matrix, 1, index - 1);
    for (int i = 0; i < str.len; i++)
        temp.data[index + i - 1] = str.data[i];
    for (int i = index; i < matrix.len; i++)
        temp.data[str.len + i - 1] = matrix.data[i];
    return temp;
}
QString QString::delStr(QString str,int head,int num){
    
}
