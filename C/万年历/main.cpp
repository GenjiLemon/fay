#include<stdio.h>
#include<stdlib.h>

/*int main(int argc, char *argv[]) {
	return 0;
}*/

//万年历的开始

/* 	函数列表 
	1.判断闰年
	2.每月有几天
	3.从一个确定的时间  1900.1.1（周一 位置：2）到所求月的天数 
	4.该月的一号的位置
	5. 显示日历
	主函数:
	界面友好
	显示日历
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
	}//往年相加 
	for(j=1;j<m;j++)
	{
		daysum+=GetDaysofMonth(y,j);
	}//往月相加 
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
	printf("             %d年%d月\n",y,m);
	int i;
	int firstday=GetFirstDayInTable(y,m);
	int x=0;
	printf("-----------------------------------\n");//5*7=35个空格区域
	printf("   日   一   二   三   四   五   六\n");
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
	printf(" 欢迎您使用万年历~\n\n"); 
	printf("菜单：\n");
	printf("1.按月查询\n");
	printf("2.退出\n"); 
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
		printf("请输入对应的序号\n");
		scanf("%d",&choice);
		getchar();
		if(choice!=1&&choice!=2)
		printf("其他功能还在开发中哦~\n");
		else if(choice==2)
		{
			printf("\n---------fay祝您生活愉快---------\n\n");
			return 0;
			
		}
		else
		{
			printf("\n\n按月查询：\n\n");
			printf("说明：本程序支持查询1900年后的任意一个月日历\n");
			printf("请输入需要查询的年份\n");
			scanf("%d",&year);
			while(year<1900)		
			{
			printf("人家只能查找1900年之后啦,再输入一次哦\n");
			scanf("%d",&year);
			}
			printf("请输入需要查询的月份\n");
			scanf("%d",&month);
			while(month>12||month<1)
			{
				printf("笨蛋，哪一年有这一月啊，再输入一次哦\n");
				scanf("%d",&month);
			}
			ShowDate(year,month);
			printf("\n \n"); 
		}
	}
	return 0;
	
}



