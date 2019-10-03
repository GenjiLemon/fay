#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<string.h>


char s1[100];
char s2[100];
int ups1[100];
int ups2[100];
int res[200];
void add();
void mul();
void jian();
void GetDig();
void PrintDig(int model);
void menu();
int compare(char a[],char b[]);
void UpDig()
{
	int i,end;
	for(i=0;s1[i];i++);
		end=i-1;
	for(i=0;i<=end;i++)
		 ups1[i]=s1[end-i]-'0';
 	for( i=0;s2[i];i++);
		end=i-1;
	for(i=0;i<=end;i++)
		 ups2[i]=s2[end-i]-'0';
}

int compare(char a[],char b[])
{
	int alen=strlen(a),blen=strlen(b);
	if(alen!=blen)
		return alen>blen;
	 return strcmp(a,b);
}

void add()
{
	UpDig();
	int flag=0;				//进位标致 
	for(int i=0;i<100;i++)
	{
		res[i]=ups1[i]+ups2[i]+flag;
		if(res[i]>=10)
		{
			res[10]%=10;
			flag=1;
		}
		else flag=0;
	}

	PrintDig(1);
	
	
}

void mul()
{
	UpDig();
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			res[i+j]+=ups1[i]*ups2[j];
					
		for(int i=0;i<200;i++)
		{
			if(res[i]>=10)
			{
			res[i+1]+=res[i]/10;
			res[i]%=10;	
			}
		} 
	PrintDig(3);
}

void jian()											//求差的绝对值				
{
	UpDig();
	int swa=compare(s1,s2);						//swa=1说明大于 不用换 
	bool flag=0;  									//0代表没借位  1代表有借位； 
	if(swa>=0)
	{
		for(int i=0;i<100;i++)
		{
			res[i]=ups1[i]-ups2[i]-flag;
			if(res[i]<0)
			{
				res[i]+=10;
				flag=1;
			}
			else flag=0;
		}
	}
	else 
	{
		for(int i=0;i<100;i++)
		{
			res[i]=ups2[i]-ups1[i]-flag;
			if(res[i]<0)
			{
				res[i]+=10;
				flag=1;
			}
			else flag=0;
		}
		
	}

	PrintDig(2);
}

void GetDig()
{
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	printf("请输入第一个数字以回车结束\n");
	gets(s1);
	printf("\n请输入第二个数字以回车结束\n");
	gets(s2);
	printf("输入成功！\n"); 
	Sleep(1000);
	menu();
}

void PrintDig(int model)
{
	int i,begin;
	for(i=200;(!res[i])&&(i>=0);i--);
		begin=i;
	switch(model)
	{
		case 1:printf("两数相加答案为：\n");break;
		case 2:printf("两数相减答案为：\n");break;
		case 3:printf("两数相乘答案为：\n");break;		
	}
		
	if((model==2)&&(compare(s1,s2)<0))
		printf("-");
	if((model==2)&&(compare(s1,s2)==0))
		{
			printf("0\n"); 
			goto A;
		}
	for(i=begin;i>=0;i--)
	
		printf("%d",res[i]);

	
	A:printf("\n输入0返回主菜单,输入其他键退出程序\n");
	char sel[100];
	gets(sel);
	if(strcmp(sel,"0")) exit(0);
	memset(res,0,sizeof(res));
	menu();
	 
}
void menu()
{
	A:system("cls");
	printf("    欢迎来到高精度计算器  本程序支持100位以内加减乘法\n");
	printf("-------------------------\n");
	printf("1.输入两个正整数\n");
	printf("2.高精度加法\n");
	printf("3.高精度减法\n");
	printf("4.高精度乘法\n");
	printf("0.退出\n"); 
	printf("-------------------------\n");
	printf("请选择：\n");
	int sel;
	scanf("%d",&sel);
	getchar();
	if(((!s1[0])||(!s2[0]))&&(sel==4||sel==2||sel==3))
	{
		printf("你还没有输入数字，请重新选择\n");
		Sleep(500);
		goto A;
	}
	switch(sel)
	{
		case 1:GetDig();break;	
		case 2:add();break;
		case 3:jian();break;
		case 4:mul();break;
		case 0:exit(0);
		default:printf("输入错误！请重新输入！\n");Sleep(1000);menu();
	}
	
}
int main()
{	
	menu();
	return 0;
}
