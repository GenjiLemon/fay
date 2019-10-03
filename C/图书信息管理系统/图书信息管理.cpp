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
void menu();        //���˵� 
void returnmenu();         	 //����������ص���ҳ
void readfile();  //���ļ���ȡͼ����Ϣ
void lrmain();    //ͼ����Ϣ¼���ļ� 
void llmain();      //ͼ����Ϣ���
void crmain();      //����ͼ����Ϣ
void cxmain();      //��ѯͼ����Ϣ
void pxmain();      //ͼ����Ϣ���� 
void xgmain();      //�޸�ͼ����Ϣ
void scmain();      //ɾ��ͼ����Ϣ
void tcmain();     	//�˳�ͼ�����ϵͳ 

int main()
{
	system("color F0\n"); 
	readfile();
	while(1)
	{
		menu();
	}                           //���˵� 
	             	  	 //����������ص���ҳ
	
	return 0;
}

void menu()
{
	int num=0;
	system("cls");
	printf("----------------------------------------\n");
	printf("||                                    ||\n");
	printf("||     ��ӭ����ͼ����Ϣ����ϵͳ       ||\n");
	printf("||                                    ||\n");
	printf("||������������ɶ�Ӧ���ܣ�            ||\n");
	printf("||                                    ||\n");
	printf("||1.ͼ����Ϣ¼��                      ||\n");
	printf("||2.ͼ����Ϣ���                      ||\n");
	printf("||3.����ͼ����Ϣ                      ||\n");
	printf("||4.��ѯͼ����Ϣ                      ||\n");
	printf("||5.ͼ����Ϣ����                      ||\n");
	printf("||6.�޸�ͼ����Ϣ                      ||\n");
	printf("||7.ɾ��ͼ����Ϣ                      ||\n");
	printf("||8.�˳�ͼ�����ϵͳ                  ||\n");
	printf("----------------------------------------\n"); 
	printf("��������������ɶ�Ӧ���ܣ�");
	scanf("%d",&num);
	if(num!=1&&num!=2&&num!=3&&num!=4&&num!=5&&num!=6&&num!=7&&num!=8)
	{

		printf("\n���������밴������������˵���\n");
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
		printf("ͼ����Ϣ�ļ���ȡ����");
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
		printf("ͼ����Ϣ�ļ���ȡ����");
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
	printf("����0�������˵�\n");
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
	printf("\n\n ������ͼ���� ");
	scanf("%s",NewBook.num);
	for(j=0;j<i;j++)
	{
		if(strcmp(NewBook.num,info[j].num)==0)
		{
			printf("\n ******************************\n"
				   " ͼ���Ѵ��ڣ�\n");
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
	
	printf(" ���������� ");
	scanf("%s",NewBook.nam);
	printf(" ���������� ");
	scanf("%s",NewBook.aut);
	printf(" ����������� ");
	scanf("%s",NewBook.pub);
	printf(" ���������ʱ�� ");
	scanf("%s",NewBook.tim);
	printf(" ������۸� ");
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
	
	printf( "\n �ɹ����ͼ�飡\n" );
}

void cxmain(){
	system("cls");
	int j = 0;
	char num[20];
	printf("\n\n ������ͼ���� ");
	scanf("%s", num);
	int iii=0;         //�����Ƿ���ͼ�� 
	for (j = 0; j < i; j++)
	{
		if (strcmp(num, info[j].num) == 0)
		{
			iii++; 
			printf("\n ********************************************************************************\n"
			       "  ����                    ����            ������               �۸�\n\n");
			printf("  %-24s%-16s%-20s %s\n", info[j].nam, info[j].aut, info[j].pub, info[j].pri);
			

		}
	}
	
	if (!iii)
	{
		printf("\n ******************************\n"
			   " ͼ�鲻���ڣ�\n");

	}
	printf("����1������ѯ������0�������˵�\n");
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
	printf("�������޸ĵ�ͼ���ţ�");
	scanf("%s", num);
	while(1)
	{	for (j = 0; j <= i; j++)
			if (strcmp(num, info[j].num) == 0)
				goto A;
			printf("ͼ���Ų����ڣ�����������\n");
			scanf("%s", num);			
	}

	
	A:printf(" �����޸�Ϊ�� ");
	scanf("%s",info[j].nam);
	printf("\n �����޸�Ϊ�� ");
	scanf("%s",info[j].aut);
	printf("\n �������޸�Ϊ�� ");
	scanf("%s",info[j].pub);
	printf("\n ����ʱ���޸�Ϊ�� ");
	scanf("%s",info[j].tim);
	printf("\n �۸��޸�Ϊ�� ");
	scanf("%s",info[j].pri);	
	printf( "\n �ɹ��޸�ͼ�飡\n" );
	Sleep(500); 

	
	lrmain();
}

void scmain(){
	int j;
	char num[20];
	while(1)
	{
		printf("��������Ҫ�޸ĵ�ͼ��ı��\n");
		scanf("%s", num);
		for (j = 0; j <= i; j++)
			if (strcmp(num, info[j].num) == 0)
				goto  B;
		printf("�����ڸ�ͼ���ţ�������\n");
		Sleep(500);
		
	}
   B:for (; j < i; j++)
	{
		info[j]=info[j+1];
	}
	--i;
	printf("ɾ���ɹ���\n");
	Sleep(500);
	lrmain();
}

void tcmain()
{
	int num=0;
	system("cls");
	printf("\n **************************\n"
	       " *                        *\n"
		   " *     ��ȷ��Ҫ�˳���?    *\n"
		   " *    [1]ȷ��   [2]ȡ��   *\n"
		   " *                        *\n"
		   " *                        *\n"
	       " **************************\n"
		   " �����������Ӧ�ı�� ");
	scanf("%d",&num);
	switch(num)
	{
		case 1:
			system("cls");
			printf("\n **************************\n"
	       		   " *                        *\n"
	       		   " *                        *\n"
		   		   " *         �ټ���         *\n"
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
				   " �밴������������˵���");

	menu();
}*/

