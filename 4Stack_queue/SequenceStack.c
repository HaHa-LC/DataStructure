#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType;

/*顺序栈结构*/
typedef struct 
{           
    SElemType data[MAXSIZE];
    int top;
}SqStack;

Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}

/*构造空栈s*/
Status InitStack(SqStack *s)
{
    s->top=-1;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        return OK;
}

/*判断栈是否为空*/
Status StackEmpty(SqStack s)
{
    if(s.top==-1)
        return TRUE;
    else
    {
        return FALSE;
    }
    
}

int StackLength(SqStack S)
{
    return S.top+1;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S,SElemType *e)
{
    if(S.top==-1)
        return ERROR;
    else
    {
        *e=S.data[S.top];
    }
    return OK;
}

/*插入元素e为新的栈顶元素*/
Status Push(SqStack *S,SElemType e)
{
    if(S->top==MAXSIZE-1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}

/*出栈*/
Status Pop(SqStack *S,SElemType *e)
{
    if(S->top==-1)
    {
        return ERROR;
    }
    *e=S->data[S->top];
    S->top--;
    return OK;
}

Status StackTraverse(SqStack S)
{
    int i;
    i=0;
    while (i<=S.top)
    {           
         visit(S.data[i++]);
    }
    printf("\n");
    return OK;
}

int main()
{
    int j;
    SqStack s;
    int e;
    if(InitStack(&s)==OK)
        for(j=1;j<=10;j++)
            Push(&s,j);
    printf("栈中元素依次为：");
    StackTraverse(s);
    Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        
    return 0;
}
