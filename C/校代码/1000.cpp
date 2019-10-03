#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef int ElemType;
#define OK 1
#define List_init_size 10000000
#define Listincreasement 100

typedef struct{
	int length;
	int listsize;
	ElemType *elem;
}Sqlist;

int InitList(Sqlist &L){
	L.elem=(ElemType *)malloc(List_init_size*sizeof(ElemType));
	if(!L.elem)return 0;
	L.length=0;
	L.listsize=List_init_size;
	return OK;
}

int ListDelete(Sqlist &L,int i,int &e){
	if(i<1||i>L.length)return 0;
	int j;
	e=*(L.elem+i-1);
	for(j=i-1;j<L.length-1;++j)*(L.elem+j)=*(L.elem+j+1);
	L.length--;
	return OK;
}

int ListInsert(Sqlist &L,int i,int e){
	int j;
	if(L.length==L.listsize){
	ElemType *newbase=(ElemType *)realloc(L.elem,(L.length+Listincreasement)*sizeof(ElemType));
	free(L.elem);
	L.elem=newbase;
	}
	for(j=L.length-1;j>=i-1;j--)*(L.elem+j+1)=*(L.elem+j);
	*(L.elem+i-1)=e;
	L.length++;
	return OK;
}

int LocateElem(Sqlist L,ElemType e,int ( *compare )(ElemType ,ElemType))
	{
	int j;
	for(j=0;j<L.length;j++)
	if((*compare)(*(L.elem+j),e))return j+1;
	else return 0;
}

int compare(ElemType a,ElemType b)
 {
 return a==b;}
 
int GetElem(Sqlist L,int i,ElemType &e){
	if(i>L.length||i<1)return 0;
	e=*(L.elem+i-1);
	return OK;
}
void ClearList(Sqlist &L){
	L.length=0;
}

int  main()
{
	int j,n,q,k,list;
	 Sqlist L;
	InitList(L);
	n=1;
	for(j=0;j<10000;j++)
	{
	ListInsert(L,j+1,n);}
	
	
	
}
