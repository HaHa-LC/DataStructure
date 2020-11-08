#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

/*存储空间初始分配量*/
#define MAXSIZE 20
typedef int ElemType;
/*Status是函数的类型，其值是函数结果状态代码*/
typedef int Status;

Status visit(ElemType c){
    printf("%d ",c);
    return OK;
}

typedef struct 
{
    /* data */
    ElemType data[MAXSIZE];    /*数组，存储数据元素*/
    int length;     /*线性表当前长度*/
}SqList;

/*初始化顺序线性表*/
Status InitList(SqList *L){
    L->length=0;
    return OK;
}

/*初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE*/
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

//初始条件：顺序线性表L已存在。操作结果：将L重置为空表
Status ClearList(SqList *L){
    L->length=0;
    return OK;
}

int ListLength(SqList L){
    return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L,int i,ElemType *e){
    if(L.length==0 || i<1 || i>L.length)
        return ERROR;
    *e = L.data[i-1];
    return OK;
}

/*初始条件：顺序线性表L已存在
操作结果：返回L中第一个与e满足关系的数据元素的位序
若这样的数据元素不存在，则返回值为0
*/
int LocateElem(SqList L,ElemType e){
    int i;
    if(L.length==0)
        return 0;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e)
            break;
    }
    if(i>=L.length)
        return 0;
    return i+1;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L,int i,ElemType e){
    int k;
    if(L->length==MAXSIZE)  /*顺序线性表已经满*/
        return ERROR;
    if(i<1 || i>L->length+1)    /*当i比第一位置小或者比最后一位置后一位置还要大时*/
        return ERROR;
    if(i<=L->length)    /*若插入数据位置不在表尾*/
    {
        for ( k = L->length-1; k >= i-1; k--)
        {
            L->data[k+1]=L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e){
    int k;
    if(L->length==0)
        return ERROR;
    if(i<1 || i>L->length)
        return ERROR;
    *e=L->data[i-1];
    if(i<L->length){
        for ( k = i; i < L->length; k++)
        {
            L->data[k-1]=L->data[k];
        }   
    }
    L->length--;
    return OK;
}

//输出数据元素
Status ListTraverse(SqList L){
    int i;
    for(i=0;i<L.length;i++){
        visit(L.data[i]);
    }
    printf("\n");
    return OK;
}

void unionL(SqList *La,SqList Lb){
    int La_len,Lb_len,i;
    ElemType e;
    La_len=ListLength(*La);
    Lb_len=ListLength(Lb);
    for(i=1;i<=Lb_len;i++){
        GetElem(Lb,i,&e);
        if(!LocateElem(*La,e))
            ListInsert(La,++La_len,e);
    }
}

int main(){
    SqList L;
    SqList Lb;

    ElemType e;
    Status i;

    int j,k;
    i=InitList(&L);
    printf("初始化L后：L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 
    
    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);


    return 0;
}



