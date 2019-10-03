#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;
#define OK 1
typedef struct Lnode{
	unsigned expn;
	float coef;
	struct Lnode *next;
}Lnode,*linklist;

int Initlist(linklist &L,int n){
	L=(linklist)malloc(sizeof(Lnode));
	linklist p,s;
	s=L;
	while(n--)
	{
		p=(linklist)malloc(sizeof(Lnode));
		if(!p)return 0;
		cin>>p->coef>>p->expn;
		s->next=p;
		s=s->next;
	}
	s->next=NULL;
	return OK;
}

void Listplus(linklist &A,linklist B){
	linklist p,q,s;
	linklist C=(linklist)malloc(sizeof(Lnode));
	s=C;
	p=A->next;
	q=B->next;
	while(q&&p)
	{
		if(q->expn<p->expn){
			s->next=q;
			s=s->next;
			q=q->next;
		}
		else if(q->expn>p->expn){
			s->next=p;
			s=s->next;
			p=p->next;
		}
		else if(q->coef+p->coef){
			q->coef=q->coef+p->coef;
			s->next=q;
			s=s->next;
		}
		else {p=p->next;q=q->next;}
	}
	if(p){
		s->next=p;
	}
	 if(q){
		s->next=q;
	
	}
	free(B);
	A->next=C;
	p=q=s=NULL;

}
/*void Listplus(linklist &A,linklist B)
{
	linklist pa,pb,pc,pd;
	pa =A->next;  pb=B->next; pc=A;
	while (pa&&pb) {
         if (pa->expn == pb->expn)
		 	{
              pa->coef = pa->coef+pb->coef;
              if (pa->coef != 0)
                  {  pc->next=pa;  pc=pa;  pa=pa->next;pd=pb;pb=pb->next;free(pd); }
             else
                  { pd=pa; pa=pa->next;free(pd);pd=pb;pb=pb->next; free(pd); }
				  }
        else if (pa->expn < pb->expn)
                  {    pc->next=pa;   pc=pa;    pa=pa->next;    }
          else if (pa->expn > pb->expn)
                  {    pc->next=pb;   pc=pb;    pb=pb->next;   }
      }
if (pa!=NULL)  pc->next=pa;
if (pb!=NULL)  pc->next=pb;
free(B);
}

void Putlist(linklist L){
	linklist s;
	s=L->next;
	while(s){
		
		cout<<s->coef<<' '<<s->expn<<endl;
		s=s->next;
	}
}*/

int main()
{
	linklist A,B;
	int n,m;
	cin>>n;
	Initlist(A,n);
	cin>>m;
	Initlist(B,m);
	Listplus(A,B);
	Putlist(A);
	return 0;
}
