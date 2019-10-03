


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define LIST_INIT_MAX 10      //����Ϊ10
#define LIST_INCREMENT 2     //�̱�Ϊ2
int m, n,a,b,e;
char op;

typedef struct
{
    int * elem;               //���ö�̬�洢����ṹ
    int length;
    int listsize;
}sqlist;
                    //���Ա��������                
void InitList(sqlist *L);              //��ʼ������̬����һ��洢�ռ�
void DestroyList(sqlist *L);        //�ͷ���һ�δ洢�ռ䣨������Ӧ�ڶ�̬��
void ClearList(sqlist *L);
void ListEmpty(sqlist L);
int ListLength(sqlist L);
int GetElem(sqlist L, int i, int &e); 
int LocateList(sqlist L, int e);     //�ڱ��в���ֵΪe��Ԫ��
int PriorElem(sqlist L, int cur_e, int *pri_e);  //��ǰԪ�ص�ǰ��
int NextElem(sqlist L, int cur_e, int *Nex_e); //��ǰԪ�صĺ��
int ListInsert(sqlist &L, int i, int e);    //�������
int ListDelete(sqlist &L, int i, int &e); //ɾ������
void TravelList(sqlist L);                //��������

void InitList(sqlist *L)
{
    L->elem = (int *)malloc(LIST_INIT_MAX*sizeof(int)); //��ʼ��ָ��
    if (!L->elem)
        exit(-1);
    L->length = 0;           //��ʼ����ǰԪ�ظ���
    L->listsize = LIST_INIT_MAX;  //��ʼ����
}




void DestroyList(sqlist *L)
{
    free(L->elem);         //�ͷſռ�
    L->elem = NULL;      //��ָ���ÿ�
    L->length = 0;         //��ǰԪ�ظ���Ϊ0
    L->listsize = 0;        //��Ϊ0
}



void ClearList(sqlist *L)
{
    *L->length = 0;  //�ǰԪ�ظ���Ϊ0
}



void ListEmpty(sqlist L)
{
    if (L.length == 0)
        printf("��Ϊ��.\n");
    else
        printf("��Ϊ��.\n");
}



int ListLength(sqlist L)
{
    return L.length;  //���ر�ĵ�ǰԪ�ظ���
}



void GetElem(sqlist L, int i, int &e) //1<= i <=L.length
{
    if (i<1 || i>L.length)
    {
        printf("ȡֵλ�ò���ȷ��\n");
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




int PriorElem(sqlist L, int cur_e, int *pri_e) //��һ��Ԫ����ǰ��
{
    int i;
    int *p = L.elem;

    for (i=0; i<L.length; i++,p++) //˳�������֪������forѭ��
    {
        if (i==0 && *p==cur_e)
        {
            printf("��ǰԪ��Ϊ��һ��Ԫ�أ���ǰ��.\n");
            return 0;
        }
        if (*p == cur_e)       //�ҵ��˵�ǰԪ���Ҳ��ǵ�һ��Ԫ�أ�
      {
           *pri_e = *--p;      //����ǰ���������ò���
         return 0;
      }
    }
    printf("˳������޵�ǰֵ%d��\n", cur_e);
    return 0;
}



int NextElem(sqlist L, int cur_e, int *nex_e) //���һ��Ԫ���޺��
{
    int i;
    int *p = L.elem;
    
    for (i=0; i<L.length; i++)  //˳�������֪������for
    {
        if (i==L.length-1 || *p==cur_e)
        {
             printf("��ǰԪ��Ϊ���һ��Ԫ�أ��޺��.\n");
             return 0;
        }
        if (*p == cur_e)
        {
             *nex_e = *++p;   //����̸������ò�������
             return 0;
        }
    }
    printf("˳������޵�ǰֵ%d��\n", cur_e);
    return 0;
}




int ListInsert(sqlist *L, int i, int e) //1<= i <=L->length+1
{
    int *newbase, *p, *q;

    if (i<1 || i>L->length+1)   //����λ�ò�����
    {
        printf("����λ�ò�����.\n");
        return 0;
    }
    if (L->length == L->listsize)   //������
    {
        newbase = (int *)realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof (int));  //��newbaseָ����Ϊ�˱���L->elem
        if (!newbase)
        {
            printf("���������ڴ�ռ�ʧ��.\n");
            exit(-1);
        }
        L->listsize += LIST_INCREMENT;
    }
    p = L->elem + i - 1;                 //pָ������λ��
   q = L->elem + L->length - 1;    //qָ�����Ԫ�����һ��λ��
   
   for (; q>=p; q--)    //�����һ��Ԫ�ؿ�ʼ��������ƶ�����Ԫ��
        *(q+1) = *q;
    *q = e;              //����Ԫ��
    L->length++;     // ����һ
   return 0;
}


int ListDelete(sqlist *L, int i, int &e) //1<= i <=L->length
{
    int *p, *q;

    if (i<1 || i>L->length)
    {
        printf("ɾ��λ�ò�����.\n");
        return 0;
    }
     
    p = L->elem + i - 1;         //pָ��Ҫɾ����Ԫ�ص�λ��
   q = L->elem + L->length - 1;  //qָ��������һ��Ԫ��λ��
 
   e = *p;                //��Ҫɾ����Ԫ�ر�������
   for (; p<=q; p++)   //��Ҫɾ��Ԫ�صĺ���һ��Ԫ�ؿ�ʼ�ƶ�Ԫ��
        *p = *(p+1);
    L->length--;          //����һ
   return 0;
}



void TravelList(sqlist L)
{
    int i;
    int *p = L.elem;

    for (i=0; i<L.length; i++,p++)
    {
        printf("��%d��Ԫ��Ϊ��%d\n", i+1, *p);
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

