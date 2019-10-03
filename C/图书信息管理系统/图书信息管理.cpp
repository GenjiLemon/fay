#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h> 
#include<windows.h>
#define LEN sizeof(struct book)
#define M 100 
#define N 6
 
typedef int Status;
typedef int ElemType;
typedef struct{
	char num[100],nam[100],aut[100],pub[100],tim[100],pri[100];
}book;
book info[100];
int m,j,n,k;
int i=0;
FILE *fp;
int a[M];
void menu();        //主菜单 
void returnmenu();         	 //按任意键返回到主页
void readfile();  //从文件读取图书信息
void lrmain();    //图书信息录入文件 
void llmain();      //图书信息浏览
void crmain();      //插入图书信息
void cxmain();      //查询图书信息
void pxmain();      //图书信息排序 
void xgmain();      //修改图书信息
void scmain();      //删除图书信息
void tcmain();     	//退出图书管理系统 

int main()
{
	system("color F0\n"); 
	readfile();
	while(1)
	{
		menu();
	}                           //主菜单 
	             	  	 //按任意键返回到主页
	
	return 0;
}

void menu()
{
	int num=0;
	system("cls");
	printf("----------------------------------------\n");
	printf("||                                    ||\n");
	printf("||     欢迎进入图书信息管理系统       ||\n");
	printf("||                                    ||\n");
	printf("||输入数字以完成对应功能：            ||\n");
	printf("||                                    ||\n");
	printf("||1.图书信息录入                      ||\n");
	printf("||2.图书信息浏览                      ||\n");
	printf("||3.插入图书信息                      ||\n");
	printf("||4.查询图书信息                      ||\n");
	printf("||5.图书信息排序                      ||\n");
	printf("||6.修改图书信息                      ||\n");
	printf("||7.删除图书信息                      ||\n");
	printf("||8.退出图书管理系统                  ||\n");
	printf("----------------------------------------\n"); 
	printf("请输入数字以完成对应功能：");
	scanf("%d",&num);
	if(num!=1&&num!=2&&num!=3&&num!=4&&num!=5&&num!=6&&num!=7&&num!=8)
	{

		printf("\n输入有误！请按任意键返回主菜单。\n");
	}	
	else
	{
		switch(num)
		{	
			case 1:lrmain();break;
			case 2:llmain();break;
			case 3:crmain();break;
			case 4:cxmain();break;
			case 5:pxmain();break;
			case 6:xgmain();break;
			case 7:scmain();break;
			case 8:tcmain();break;	
		}	
	}

}

void readfile(){
	FILE *fp;
	fp=fopen("d:BookInfo.txt","r");
	if(!fp) 
	{
		printf("图书信息文件读取出错！");
		exit(0);
	}
	while((	fscanf(fp,"%s%s%s%s%s%s",info[i].num,info[i].nam,info[i].aut,info[i].pub,info[i].tim,info[i].pri))!=EOF)
	{
		i++;
	}
	fclose(fp);
} 

void lrmain(){
	int j;
	FILE *fp;
	fp = fopen("BookInfo.txt","w");
	for(j=0;j<i;j++)
	{
		fprintf(fp,"%s %s %s %s %s %s\n",info[j].num,info[j].nam,info[j].aut,info[j].pub,info[i].tim,info[j].pri);
	}
	fclose(fp);
}

void llmain()
{	
	FILE *fpRead;
	fpRead=fopen("d:BookInfo.txt","r");
	if(!fpRead) 
	{
		printf("图书信息文件读取出错！");
		exit(0);
	}
	else
	{
		while((	fscanf(fpRead,"%s%s%s%s%s%s",info[i].num,info[i].nam,info[i].aut,info[i].pub,info[i].tim,info[i].pri))!=EOF)
	{
		printf("%s %s %s %s %s %s",info[i].num,info[i].nam,info[i].aut,info[i].pub,info[i].tim,info[i].pri);
		printf("\n");
		i++;
	}
	}
	printf("输入0返回主菜单\n");
	int aaaaa;
	scanf("%d",&aaaaa);
	if(!aaaaa)return ;
	
	fclose(fpRead);
}

void crmain()
{
	FILE *fp;
	int j,k;
	book NewBook;
	printf("\n\n 请输入图书编号 ");
	scanf("%s",NewBook.num);
	for(j=0;j<i;j++)
	{
		if(strcmp(NewBook.num,info[j].num)==0)
		{
			printf("\n ******************************\n"
				   " 图书已存在！\n");
			return;
		}
		if(strcmp(NewBook.num,info[j].num)<0)
		{
			break;
		}
	}
	for(k=i-1;k>=j;k--)
	{
		info[k+1]=info[k];
	}
	
	printf(" 请输入书名 ");
	scanf("%s",NewBook.nam);
	printf(" 请输入作者 ");
	scanf("%s",NewBook.aut);
	printf(" 请输入出版社 ");
	scanf("%s",NewBook.pub);
	printf(" 请输入出版时间 ");
	scanf("%s",NewBook.tim);
	printf(" 请输入价格 ");
	scanf("%s",NewBook.pri);
	info[j]=NewBook;
	i++;
	fp = fopen("d:BookInfo.txt","a");
	fprintf(fp,"%s ",NewBook.num);	
	fprintf(fp,"%s ",NewBook.nam);
	fprintf(fp,"%s ",NewBook.aut);
	fprintf(fp,"%s ",NewBook.pub);
	fprintf(fp,"%s ",NewBook.tim);
	fprintf(fp,"\n%s",NewBook.pri);
	fclose(fp);
	
	printf( "\n 成功添加图书！\n" );
}

void cxmain(){
	system("cls");
	int j = 0;
	char num[20];
	printf("\n\n 请输入图书编号 ");
	scanf("%s", num);
	int iii=0;         //检验是否有图书 
	for (j = 0; j < i; j++)
	{
		if (strcmp(num, info[j].num) == 0)
		{
			iii++; 
			printf("\n ********************************************************************************\n"
			       "  书名                    作者            出版社               价格\n\n");
			printf("  %-24s%-16s%-20s %s\n", info[j].nam, info[j].aut, info[j].pub, info[j].pri);
			

		}
	}
	
	if (!iii)
	{
		printf("\n ******************************\n"
			   " 图书不存在！\n");

	}
	printf("输入1继续查询，输入0返回主菜单\n");
	int aaaa;
	scanf("%d",&aaaa);
	if(aaaa)cxmain();
	else return;
}

void pxmain(){
	
}

void xgmain(){
	int j;
	char num[20];
	printf("请输入修改的图书编号：");
	scanf("%s", num);
	while(1)
	{	for (j = 0; j <= i; j++)
			if (strcmp(num, info[j].num) == 0)
				goto A;
			printf("图书编号不存在，请重新输入\n");
			scanf("%s", num);			
	}

	
	A:printf(" 书名修改为： ");
	scanf("%s",info[j].nam);
	printf("\n 作者修改为： ");
	scanf("%s",info[j].aut);
	printf("\n 出版社修改为： ");
	scanf("%s",info[j].pub);
	printf("\n 出版时间修改为： ");
	scanf("%s",info[j].tim);
	printf("\n 价格修改为： ");
	scanf("%s",info[j].pri);	
	printf( "\n 成功修改图书！\n" );
	Sleep(500); 

	
	lrmain();
}

void scmain(){
	int j;
	char num[20];
	while(1)
	{
		printf("请输入需要修改的图书的编号\n");
		scanf("%s", num);
		for (j = 0; j <= i; j++)
			if (strcmp(num, info[j].num) == 0)
				goto  B;
		printf("不存在该图书编号，请重试\n");
		Sleep(500);
		
	}
   B:for (; j < i; j++)
	{
		info[j]=info[j+1];
	}
	--i;
	printf("删除成功！\n");
	Sleep(500);
	lrmain();
}

void tcmain()
{
	int num=0;
	system("cls");
	printf("\n **************************\n"
	       " *                        *\n"
		   " *     您确定要退出吗?    *\n"
		   " *    [1]确定   [2]取消   *\n"
		   " *                        *\n"
		   " *                        *\n"
	       " **************************\n"
		   " 请输入操作对应的编号 ");
	scanf("%d",&num);
	switch(num)
	{
		case 1:
			system("cls");
			printf("\n **************************\n"
	       		   " *                        *\n"
	       		   " *                        *\n"
		   		   " *         再见！         *\n"
		   		   " *                        *\n"
		  		   " *                        *\n"
	       		   " **************************\n"
		   		  );
			exit(0);
		default:menu();
	}
}

/*void returnmenu()
{
	printf("\n ********************************************************************************\n"
				   " 请按任意键返回主菜单。");

	menu();
}*/

