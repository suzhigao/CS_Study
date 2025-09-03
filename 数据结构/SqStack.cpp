//顺序栈
#include <iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef char SElemType;
typedef int Status;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;    
}SqStack;

//初始化栈
Status InitStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE]; //动态分配最大容量为MAXSIZE的数组
    if(!S.base) exit(EOVERFLOW);
    S.top = S.base; //空栈
    S.stacksize = MAXSIZE;;
    return OK;
}

//判断栈是否为空
bool StackEmpty(SqStack &S)
{
    return (*S.top == -1);
}

//入栈
Status Push(SqStack &S, SElemType e)
{
    if(S.top-S.base==S.stacksize)
        return ERROR;
    *S.top++ = e;
    /*
    *S.top = e;
    S.top++;
    */
   return OK;
}

//出栈
Status Pop(SqStack &S, SElemType &e)
{
    if(S.top==S.base)
        return ERROR;
    S.top--;
    e = *S.top;
    //e = *--S.top;
    return OK;
}

//取栈顶元素
Status GetTop(SqStack &S)
{
    if(S.top!=S.base)
    {
        return *(S.top-1);
    }
    return OK;
}

int main()
{
    SElemType e;
    SqStack s;
    cout<<"（1）初始化栈："<<endl;
    InitStack(s);
    cout<<"（2）依次进栈元素a,b,c,d,e"<<endl;
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');

    cout<<"出栈序列：";
    while(!StackEmpty(s))
    {
        Pop(s,e);
        cout<<e<<" ";
    }
    cout<<endl;

    return 0;
}