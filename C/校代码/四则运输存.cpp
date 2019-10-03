#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 10000
#define OVERFLOW -1
#include<iostream>
using namespace std;


typedef int Status;

/*
	1.����ջ
	2.������ �����  ��׺ʽ  ����ջ
	3.�� ����ǲ���������ջ���������һ�����ȼ� ��� ���1 ��˵���µĴ���ջ������չ
		���С  ���ջ�����׺ջ  ���Ѵ𰸷��������ջ 
	4.����� ���������
	
	��Ҫ����
	1.�жϲ�������С 
	2.���㺯�� 
	3.������ �����ַ���  �����׺��  ���ֵ 

*/

typedef struct {
	char *base;
	char *top;
	int stacksize;
}Stack;

Status InitStack(Stack &S)
{
	S.base=(char*)malloc(MAXSIZE*sizeof(char));
	if(!S.base)return ERROR;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}

Status PushStack(Stack &S,char e)
{
	if(S.top-S.base==MAXSIZE)return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}

Status PopStack(Stack &S,char &e)
{
	if(S.base==S.top)return ERROR;
	S.top--;
	e=*S.top;
	return e;
}

Status GetTop(Stack S)
{
	if(S.top==S.base)return ERROR;
	return *(S.top-1);
}

bool JudOper(char ch)//�ж��Ƿ��ǲ�����  ��Ϊ1 
{
	if(ch>='0'&&ch<='9')return 0;
	return 1;
}

int EvaOper(char now,char top)  //�Ƚ϶����ջ��Ԫ�ص����ȼ�   ���ڷ���1  ��ȷ���-1 (����now��վ��1 )
{
	char a=now,b=top;
	switch(b)
	{
		case '+':
		{
			if(a=='('||a=='*'||a=='/') return 1;
			else return 0;    
		}
		case '-':
		{
			if(a=='('||a=='*'||a=='/') return 1;
			else return 0;    
		}
		case '*':
		{
			if(a=='(')return 1;
			else return 0;
		}  
		case '/':
		{
			if(a=='(')return 1;
			else return 0;
		}
		case '(':
		{
			if(a==')')return -1;
  			else return 1;
		}
		
		case '#':
		{
			if(a=='#')return -1;
			else return 1;	
		}
	} 
	
}

char Calculate(char a,char b,char oper)
{
	int f=a-'0';
	int s=b-'0';
	switch(oper)
	{
		case '+':return f+s+'0';
		case '-':return f-s+'0';
		case '*':return f*s+'0';
		case '/':return f/s+'0';
		
	}
}

Status TransfoPost(char *ch,Stack &behindbds)
{
	char e;
	 Stack pre,temp;
	 PushStack(pre,'#');
	while(ch)
	{
		if(!JudOper(*ch))
			PushStack(pre,*ch);
		else
		{
			if(EvaOper(*ch,GetTop(temp))==1)
				PushStack(temp,*ch);
			else if(EvaOper(*ch,GetTop(temp))==0)			//�����ջ��С ����ջ�� 
			{
				PopStack(temp,e);	
				PushStack(pre,e);
				while(EvaOper(*ch,GetTop(temp))==0)		//	�������ջ��С ���� 
				{
			 		e=PopStack(temp,e);	
					PushStack(pre,e);
				}
				if(GetTop(temp)=='(')
				PopStack(temp,e);
				 PushStack(temp,*ch);
			}
			else	PopStack(temp,e);
			
		}
				
		ch++;
		
	}
	while(GetTop(temp)!='#')
			{
				PopStack(temp,e);
				PushStack(pre,e);
			}
	while(GetTop(pre))
	{
		PopStack(pre,e);
		PushStack(behindbds,e);
	}
	return OK;
}

Status Analysize(Stack &oper,Stack &dig,Stack &behindbds)        //�����׺���ʽ ���з��� 
{
	char e,ch;
	PushStack(oper,'#');
	while(PopStack(behindbds,ch))
	{
		if(JudOper(ch))
		{
			if(EvaOper(ch,GetTop(oper))==-1)
			{
				if(ch=='#')return OK;
				else 
				{	PopStack(oper,e);
					continue;
				}
			}
			else if(EvaOper(ch,GetTop(oper))==1)
			{
				PushStack(oper,ch);
				continue;
			}
			else{
				char  a,b,res;
				PopStack(dig,b);
				PopStack(dig,a);
				PushStack(dig,Calculate(a,b,ch));
				continue;
			}
		}
		else PushStack(dig,ch);
		
	}
}



void ClearStack(Stack &S)
{
	S.top=S.base;
}




int main()
{
	Stack oper,dig,behindbds;
	InitStack(oper);
	InitStack(dig);
	InitStack(behindbds);
	char ch[1000];
	
	while(gets(ch))
	{
		ClearStack(oper);
		ClearStack(dig);
		ClearStack(behindbds);
		TransfoPost(ch,behindbds);
		Analysize(oper,dig,behindbds);
		printf("%d\n",GetTop(dig));
	}
	return 0;
}
