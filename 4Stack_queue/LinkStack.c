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

typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
}LinkStack;

Status visit(SElemType c){
    printf("%d",c);
    return OK;
}

/*构造空栈*/
Status InitStack(LinkStack *S){
    S->top=(LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top)
        return ERROR;
    S->top=NULL;
    S->count=0;
    return OK;
}

/*把s设置为空栈*/
Status ClearStack(LinkStack *S)
{
    LinkStackPtr p,q;
    p = S->top;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

/*若栈S为空栈，则返回TRUE，否则返回FALSE*/
Status StackEmpty(LinkStack S)
{
    if (S.count == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*返回S的元素个数，则栈的长度*/
int StackLength(LinkStack S)
{
    return S.count;
}

/*若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR*/
Status GetTop(LinkStack S, SElemType *e)
{
    if (S.top == NULL)
    {
        return ERROR;
    }
   else
   {
       *e = S.top->data;
   }
    return OK;
}

/*插入元素e为新的栈顶元素*/
Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data  = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if (StackEmpty(*S))
    {
        return ERROR;
    }
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}

Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p = S.top;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    int j;
    LinkStack s;
    int e;
    if (InitStack(&s) == OK)
    {
        for (j = 0; j <= 10; j++)
        {
            Push(&s, j);
        }
    }
    printf("栈中元素依次为：");
    StackTraverse(s);

    Pop(&s, &e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    GetTop(s, &e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));

    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    return 0;
}