#include <iostream>
#include <set> using namespace std;
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ELemType int
int newbase,e,i;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;

Sqlist *q,*p,cur_e,pre_e,L;

Status Initlist_Sq(Sqlist &L){
	L.elsm=(Elemtype*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)exit(OVERFLOW);
	L.Length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}

Status ListInsert_Sq(Sqlist &L,int i,Elemtype e){
	if(i<1||i>L.length+1)return ERROR;
	if(L.Length>=L.listsize){
		newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ELemtype));
		if(!newbase)exit(OVERFLOW);
		L.elem=newbase;
	L.listsize+=LISTINCREMENT;		
	}
	q=&(L.elem[L.length-1]);p>=q;--p)
	*(p+1)=*(p);
	*q=e;++L.length;
	return OK;
}

Status ListDelete_Sq(sqlist&L,int i,ELemtype &e){
	if((i<1)||(i>L.length))return ERROR;
	p=(L.elem[i-1]);
	e=*p;
	q=L.elme+L.length-1;
	for(++p;p<=q;++p)*(p-1)=*p;
	--L.length;
	return OK;	
}

void DestryList(&L){
	free(L.elem);
	L.elem=NULL;
}

void ClearList(&L){
	L.length=0;
}

Status ListLength(L)
{
	return L.length;
}

Status GetElem(L,i,&e)
{
	return *(L.elem+i-1);
}
Status compare(int A,int B){
	if(A==B)return 1;
	else return 0;
}
Status LocateElem(L,e,compare(int,int))
{
 	i=1;p=L.elem;
 	while(i<=L.length&&!compare(*++p,e))++i;
 	if(i>=L.length)return 0;
 	else return i;
}

Status ListEmpty(L){
	if(L.length)return TRUE;
	return FALSE;
}

int main()
{
	return 0;
}