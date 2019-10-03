#include<stdio.h>
#include<stdlib.h>

/*int main(int argc, char *argv[]) {
	return 0;
}*/

//�������Ŀ�ʼ

/* 	�����б� 
	1.�ж�����
	2.ÿ���м���
	3.��һ��ȷ����ʱ��  1900.1.1����һ λ�ã�2���������µ����� 
	4.���µ�һ�ŵ�λ��
	5. ��ʾ����
	������:
	�����Ѻ�
	��ʾ����
*/

int IsLeapYear(int y)
{
	if(y%4==0&&y%100!=0||y%400==0) return 1;
	else return 0;
} 

int GetDaysofMonth(int y,int m)
{
	int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(IsLeapYear(y)) days[2]=29;
	return days[m];
}

int GetTotalDays(int y,int m)
{
	int j,i;
	int daysum=0;
	for(i=1900;i<y;i++)
	{
		if(IsLeapYear(i))
			daysum+=366;
		else daysum+=365;
	}//������� 
	for(j=1;j<m;j++)
	{
		daysum+=GetDaysofMonth(y,j);
	}//������� 
	printf("%d\n",daysum);
	return daysum;
	
}

int GetFirstDayInTable(int y,int m)
{
	int firstday=2;
	firstday+=GetTotalDays(y,m)%7;
	return firstday;
}


void ShowDate(int y,int m)
{
	printf("\n");
	printf("             %d��%d��\n",y,m);
	int i;
	int firstday=GetFirstDayInTable(y,m);
	int x=0;
	printf("-----------------------------------\n");//5*7=35���ո�����
	printf("   ��   һ   ��   ��   ��   ��   ��\n");
	for(i=1;i<=35;i++)
	{
		if(i<firstday) printf("     ");
		else if(i>=firstday+GetDaysofMonth(y,m))printf("     ");
		else printf("%5d",i-firstday+1);
		x++;
		if(x%7==0)
		{
			printf("\n");
			x=0;
		}
	}
	printf("-----------------------------------\n");
	 
}

void Menu()
{
	printf("------------------\n\n"); 
	printf(" ��ӭ��ʹ��������~\n\n"); 
	printf("�˵���\n");
	printf("1.���²�ѯ\n");
	printf("2.�˳�\n"); 
	printf("          by:fay\n");
	printf("------------------\n");
}


int main(int argc, char *argv[])
{
	int year,month;
	int choice;
	while(1)
	{
		Menu();
		printf("�������Ӧ�����\n");
		scanf("%d",&choice);
		getchar();
		if(choice!=1&&choice!=2)
		printf("�������ܻ��ڿ�����Ŷ~\n");
		else if(choice==2)
		{
			printf("\n---------fayף���������---------\n\n");
			return 0;
			
		}
		else
		{
			printf("\n\n���²�ѯ��\n\n");
			printf("˵����������֧�ֲ�ѯ1900��������һ��������\n");
			printf("��������Ҫ��ѯ�����\n");
			scanf("%d",&year);
			while(year<1900)		
			{
			printf("�˼�ֻ�ܲ���1900��֮����,������һ��Ŷ\n");
			scanf("%d",&year);
			}
			printf("��������Ҫ��ѯ���·�\n");
			scanf("%d",&month);
			while(month>12||month<1)
			{
				printf("��������һ������һ�°���������һ��Ŷ\n");
				scanf("%d",&month);
			}
			ShowDate(year,month);
			printf("\n \n"); 
		}
	}
	return 0;
	
}



