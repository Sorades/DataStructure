
#define maxSize 100
typedef char elemType;

struct TSonNode{
    elemType data;//结点的值
    TSonNode *sons[maxSize];//孩子链式储存结构中的结点类型
};