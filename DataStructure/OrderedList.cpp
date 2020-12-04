#include <iostream>
using namespace std;
struct OdList
{
    int num;
    int length;
    OdList *next;
};

OdList *creat(int *a, int length);
OdList *unionList(OdList *LA, OdList *LB);
void output(OdList *L);
int main()
{
    int la[] = {1, 3, 5, 9, 11};
    int lb[] = {0, 5, 6, 7, 8};
    OdList *LA, *LB;
    LA = creat(la, sizeof(la) / sizeof(la[0]));
    LB = creat(lb, sizeof(lb) / sizeof(lb[0]));
    OdList *LC = unionList(LA, LB);
    output(LC);
    return 0;
}
OdList *creat(int *a, int length)
{
    OdList *head, *node, *end;
    head = new OdList;
    head->length = length;
    end = head;
    for (int i = 0; i < length; i++)
    {
        node = new OdList;
        node->num = a[i];
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
OdList *unionList(OdList *LA, OdList *LB)
{
    int i = 0, j = 0, k = 0;
    OdList *head, *node, *end;
    OdList *pa = LA, *pb = LB;
    head = new OdList;
    end = head;
    pa = pa->next;
    pb = pb->next;
    while (i < LA->length && j < LB->length)
    {
        if (pa->num < pb->num)
        {
            node = new OdList;
            node->num = pa->num;
            i++, k++;
            pa = pa->next;
        }
        else
        {
            node = new OdList;
            node->num = pb->num;
            j++, k++;
            pb = pb->next;
        }
        end->next = node;
        end = node;
    }
    while (i < LA->length)
    {
        node = new OdList;
        node->num = pa->num;
        end->next = node;
        end = node;
        i++, k++;
        pa = pa->next;
    }
    while (i < LB->length)
    {
        node = new OdList;
        node->num = pb->num;
        end->next = node;
        end = node;
        j++, k++;
        pb = pb->next;
    }
    end->next = NULL;
    head->length = k;
    return head;
}
void output(OdList *L)
{
    OdList *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        cout << p->num << "\t";
    }
    cout << endl;
}