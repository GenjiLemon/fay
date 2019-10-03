


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define LIST_INIT_MAX 10      //长表为10
#define LIST_INCREMENT 2     //短表为2
int m, n,a,b,e;
char op;

typedef struct
{
    int * elem;               //采用动态存储分配结构
    int length;
    int listsize;
}sqlist;
                    //线性表操作集合                
void InitList(sqlist *L);              //初始化，动态分配一块存储空间
void DestroyList(sqlist *L);        //释放这一段存储空间（撤销对应于动态）
void ClearList(sqlist *L);
void ListEmpty(sqlist L);
int ListLength(sqlist L);
int GetElem(sqlist L, int i, int &e); 
int LocateList(sqlist L, int e);     //在表中查找值为e的元素
int PriorElem(sqlist L, int cur_e, int *pri_e);  //求当前元素的前驱
int NextElem(sqlist L, int cur_e, int *Nex_e); //求当前元素的后继
int ListInsert(sqlist &L, int i, int e);    //插入操作
int ListDelete(sqlist &L, int i, int &e); //删除操作
void TravelList(sqlist L);                //便历操作

void InitList(sqlist *L)
{
    L->elem = (int *)malloc(LIST_INIT_MAX*sizeof(int)); //初始化指针
    if (!L->elem)
        exit(-1);
    L->length = 0;           //初始化当前元素个数
    L->listsize = LIST_INIT_MAX;  //初始化表长
}




void DestroyList(sqlist *L)
{
    free(L->elem);         //释放空间
    L->elem = NULL;      //将指针置空
    L->length = 0;         //当前元素个数为0
    L->listsize = 0;        //表长为0
}



void ClearList(sqlist *L)
{
    *L->length = 0;  //令当前元素个数为0
}



void ListEmpty(sqlist L)
{
    if (L.length == 0)
        printf("表为空.\n");
    else
        printf("表不为空.\n");
}



int ListLength(sqlist L)
{
    return L.length;  //返回表的当前元素个数
}



void GetElem(sqlist L, int i, int &e) //1<= i <=L.length
{
    if (i<1 || i>L.length)
    {
        printf("取值位置不正确。\n");
        return 0;
    }
    e = *(L.elem + i - 1);
    
}


int LocateElem(sqlist L, int e)
{
    int i;
    int * p = L.elem;
    
    for (i=0; i<L.length; i++, p++)
        if (*p == e)
        return i+1;      
}




int PriorElem(sqlist L, int cur_e, int *pri_e) //第一个元素无前驱
{
    int i;
    int *p = L.elem;

    for (i=0; i<L.length; i++,p++) //顺序表长度已知，故用for循环
    {
        if (i==0 && *p==cur_e)
        {
            printf("当前元素为第一个元素，无前驱.\n");
            return 0;
        }
        if (*p == cur_e)       //找到了当前元素且不是第一个元素，
      {
           *pri_e = *--p;      //将其前驱赋给引用参数
         return 0;
      }
    }
    printf("顺序表中无当前值%d。\n", cur_e);
    return 0;
}



int NextElem(sqlist L, int cur_e, int *nex_e) //最后一个元素无后继
{
    int i;
    int *p = L.elem;
    
    for (i=0; i<L.length; i++)  //顺序表长度已知，故用for
    {
        if (i==L.length-1 || *p==cur_e)
        {
             printf("当前元素为最后一个元素，无后继.\n");
             return 0;
        }
        if (*p == cur_e)
        {
             *nex_e = *++p;   //将后继赋给引用参数带回
             return 0;
        }
    }
    printf("顺序表中无当前值%d。\n", cur_e);
    return 0;
}




int ListInsert(sqlist *L, int i, int e) //1<= i <=L->length+1
{
    int *newbase, *p, *q;

    if (i<1 || i>L->length+1)   //插入位置不合理
    {
        printf("插入位置不合理.\n");
        return 0;
    }
    if (L->length == L->listsize)   //表已满
    {
        newbase = (int *)realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof (int));  //用newbase指针是为了保护L->elem
        if (!newbase)
        {
            printf("继续分配内存空间失败.\n");
            exit(-1);
        }
        L->listsize += LIST_INCREMENT;
    }
    p = L->elem + i - 1;                 //p指向插入的位置
   q = L->elem + L->length - 1;    //q指向表中元素最后一个位置
   
   for (; q>=p; q--)    //从最后一个元素开始依次向后移动表中元素
        *(q+1) = *q;
    *q = e;              //插入元素
    L->length++;     // 表长增一
   return 0;
}


int ListDelete(sqlist *L, int i, int &e) //1<= i <=L->length
{
    int *p, *q;

    if (i<1 || i>L->length)
    {
        printf("删除位置不合理.\n");
        return 0;
    }
     
    p = L->elem + i - 1;         //p指向要删除的元素的位置
   q = L->elem + L->length - 1;  //q指向表中最后一个元素位置
 
   e = *p;                //将要删除的元素保存起来
   for (; p<=q; p++)   //从要删除元素的后面一个元素开始移动元素
        *p = *(p+1);
    L->length--;          //表长减一
   return 0;
}



void TravelList(sqlist L)
{
    int i;
    int *p = L.elem;

    for (i=0; i<L.length; i++,p++)
    {
        printf("第%d个元素为：%d\n", i+1, *p);
    }

}
int main()
{	int i;
 sqlist L;
	scanf("%d%d",&m,&n);
	InitList(&L);
	for(i=1;i<=m;i++)
	{
		ListInsert(&L,i,i);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&op,&a);
		switch(op)
		{
			case 73: scanf("%d",&b);ListInsert(&L,a,b);break;
			case 68: ListDelete(&L,a,*e);printf("%d\n",e);break;
			case 71: GetElem(L,a,*e);printf("%d\n",e);break;
			case 76: printf("%d",LocateElem(L,a));break;
			case 67: ClearList(&L);break;
		}
		
	}
	return 0;
}

