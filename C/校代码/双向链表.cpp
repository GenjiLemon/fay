#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include<iostream>
#define OK 1
#define OVWEFLOW -1
typedef int ELemType;
typedef struct Lnode{
	Lnode *prior;
	Lnode *next;
	ELemType data;
}Lnode,linklist;

int InitList(linklist &L){
	L=(linklist)malloc(sizeof(Lnode));
	if(!L)return 0;
	L.next=L.prior=NULL;
	return OK;
}

int InsertElem(linklist &L,int i,ElemType e){
	if(i<1)return 0;
	int j;
	linklist p=L->next,s;
	for(j=1;j<i-1;j++)//j<=length+1;
	if(!p)return 0;
	else p=p->next;
	if(!p->next)
	{
		s=(linklist)malloc(sizeof(Lnode));
		s->next=NULL;
		s->prior=p;
		p->next=s;
		s->data=e;
		free(s);
	}
	else
	{
		s=(linklist)malloc(sizeof(Lnode));
		s->data=e;
		s->next=p->next;
		s->prior=p;
		p->next=s;
		p->next->prior=s;
		free(s);	
	}

	return OK;
}

int DeleteElem(linklist &L,int i,ElemType e){
	int j;
	linklist p=L->next,s;
	for(j=1;j<i;j++)
	if(!p->next)return 0;
	else p=p->next;
	if(!p->next){
		s=p->prior;
		s->next=NULL;
		e=p->data;
		free(p);
	}
	else{
		s=p->prior;
		s->next=p->next;
		p->next->prior=s;
		e=p->data;
	}
	
	
	
	
	
	
	
}


