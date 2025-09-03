//顺序表
#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef int Status;
typedef int ElemType;
#define OK 1
#define ERROR 0

typedef struct
{
    ElemType *elem; //存储空间的基地址
    int  length; //顺序表长度
}SqList;

//建立顺序表
Status CreateList(SqList *&L, ElemType a[], int n)
{
    L = (SqList*)malloc(sizeof(SqList));
    for(int i = 0; i < n; i++){
        L->elem[i] = a[i];
    }
    return OK;
}

//初始化顺序表
Status InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE]; //分配空间
    if(!L.elem){  //存储分配失败退出
        exit(OVERFLOW);
    }
    L.length = 0;
    
    return OK;
}

//取值
Status GetElem(SqList &L, int i, ElemType &e)
{
    if(i<1 || i>L.length) return ERROR; //判断要取的第i个值是否合理
    e = L.elem[i-1];  //将第i个元素L.elem[i-1]赋值给e，通过e返回第i个元素的传值

    return OK;
}

//插入
Status InsertList(SqList &L, int i, ElemType e)
{
    if(i<1 || i>L.length+1) //i值不合理 
        return ERROR;
    if(L.length == MAXSIZE) //当前存储空间已满
        return ERROR; 
    
    for(int j=L.length-1; j>i-1; j--)
    {
        //从最后一个元素开始往前遍历到第i个位置，分别将它们向后移动一个位置
        L.elem[j+1] = L.elem[j];    
    }
    L.elem[i-1] = e;
    L.length++;  //表长加1

    return OK;
}

//输出顺序表
void DispList(SqList &L, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}

//实现
//主函数
int main()
{

}