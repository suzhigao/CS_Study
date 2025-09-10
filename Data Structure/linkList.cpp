//单链表
#include <iostream>
using namespace std;

typedef char ElemType;
typedef int Status;
#define OK 1
#define ERROR 0

typedef struct Node
{
    ElemType data;
    struct Node *next;
}LNode, *linkList;

//初始化
Status InitList(linkList &L)
{
    L = (linkList)malloc(sizeof(linkList));
    L ->next = NULL;
}

//取值
Status GetElem(linkList L, int i, ElemType *e)
{
    int j;
    linkList p;
    p = L->next;
    j = 1;

    while(p && j<i)
    {
        p = p->next;
        j++;
    }
    if(!p || j>i)
        return ERROR;
    *e = p->data;
    return OK;
}

//插入
Status InsertList(linkList *L, int i, ElemType e)
{
    linkList p;
    int j = 1;
    p = *L;
    while(p && j<i)
    {
        p = p->next;
        j++;
    }
    if(!p || j>i)  //第i个元素不存在
        return ERROR;
    
    linkList s;
    s = (linkList)malloc(sizeof(Node)); //生成新结点
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

//删除
Status DeleteList(linkList *L, int i, ElemType *e)
{
    linkList p, q;
    int j = 1;
    p = *L;
    while(p->next && j<i)
    {
        p = p->next;
        j++;
    }
    if(!(p->next) || j>i)  //第i个元素不存在
        return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q); //回收该结点，释放内存

    return OK;
}

//头插法创建单链表
Status CreateListF(linkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    for(int i=0; i<n; i++)
    {
        linkList p = new LNode; //生成新结点
        cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
    return OK;
}

//尾插法创建单链表
Status CreateListR(linkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    linkList r = L; //为了使最新的结点插到表尾，增加一个尾指针指向链表尾结点
    for(int i=0; i<n; i++)
    {
        linkList p = new LNode; //生成新结点
        cin>>p->data;
        r->next = p;
        p->next = NULL;
        r = p;
    }
    return 0;
}

//输出单链表
Status DisList(linkList &L)
{
    linkList p = L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}

int main()
{
    LNode *h;
    ElemType e;
    
    cout<<"单链表的基本运算如下："<<endl;
    cout<<"(1) 初始化单链表"<<endl;
    InitList(h);

    cout<<"(2) 头插法创建单链表:"<<endl;
    CreateListF(h,3);
    DisList(h);
}