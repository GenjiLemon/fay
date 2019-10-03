#include<stdio.h>
int main()
{
	int a[10],*p;
	void get(int *p);
	void run(int *p);
	void put(int *p);
	p=a;
	 get(p);
	 run(p);
	 put(p);
	return 0;
}
void get(int *p)
{
	int i;
	for(i=0;i<10;i++)
	scanf("%d",p+i);
}
void run(int *p)
{
	int i,min,temp,s,max,d;
	max=min=*p;
	s=d=0;
	for(i=0;i<10;i++)
	{
	if(*(p+i)<min) {min=*(p+i); s=i;}
	
	}
	temp=*p;
	*p=*(p+s);
	*(p+s)=temp;
	for(i=0;i<10;i++)
	if(*(p+i)>max){max=*(p+i);d=i;}
	
	
	temp=*(p+9);
	*(p+9)=*(p+d);
	*(p+d)=temp;
}

void put(int *p)
{
	int i;
	for(i=0;i<10;i++)
	printf("%d ",*(p+i));

}