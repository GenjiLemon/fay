#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define OK 1
using namespace std;
typedef char ElemType;
typedef int Status;

typedef struct Stack{
	struct Stack *next;
	ElemType data;
	struct Stack *top;
}Stack,*Linkstack;
 

	
Status InitStack(Linkstack &S){
	S=(Linkstack)malloc(sizeof(Stack));
	if(!S)return 0;
	S->top=NULL;
	S->next=NULL;
	return OK;
}
void Push(Linkstack &S,ElemType e){
	Linkstack p=(Linkstack)malloc(sizeof(Stack));
	p->next=S->top;
	p->data=e;
	S->top=p;
}
Status Pop(Linkstack &S,ElemType &e){
	if(!S->top)return  0;
	e=S->top->data;
	Linkstack p;
	p=S->top;
	S->top=p->next;
	free(p);
	return OK;
}

int main()
{
	char kh[10000],e;
	int i,statu;
	Linkstack S;
	InitStack(S);
	while(scanf("%s",kh)!=EOF)
	{
		i=0;statu=1;
		
		while(kh[i])
		{
			if(kh[i]==']'||kh[i]==')')
				{
				if (!S->top){statu =0;break;}
				
				else if(kh[i]==']'){Pop(S,e);if(e!='['){statu=0;break;}
				}
				else 
				{Pop(S,e);if(e!='('){statu=0;break;}}
				}
			if(kh[i]=='['||kh[i]=='(')Push(S,kh[i]);
			i++;
		}
		if(S->top)statu=0;
		statu? printf("yes\n"):printf("no\n");
		
	}
	return 0;
}

