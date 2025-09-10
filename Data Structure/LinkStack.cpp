//链栈
#include <iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef int Status;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}*LinkStack, StackNode;

//初始化
Status InitStack(LinkStack &S)
{
    S = NULL;
    return 0;
}

//入栈
Status Push(LinkStack &S, ElemType e)
{

    LinkStack p = new StackNode; //生成新结点
    p->data = e; 
    p->next = S; //插到栈顶
    S = p; //修改栈顶指针为p

    return OK;
}

//出栈
Status Pop(LinkStack &S, ElemType &e)
{
    if(S==NULL) return ERROR;
    LinkStack p = new StackNode;
    e = S->data;
    p = S; //p临时保存栈顶元素空间，以备释放
    S = S->next;
    delete p;

    return OK;
}

//取栈顶元素
Status GetTop(LinkStack &S)
{
    if(S!=NULL)
        return S->data;
}

//主函数
int main()
{
    
}