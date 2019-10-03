/*
函数
1.加法题
2.减法题
3.乘法题
4.除法题
5.加法判断
6.减法判断
7.除法判断
8.乘法判断
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
#define RANGE 100
#define RIGHT 1
#define WRONG 0
#define TRUE 1

int AddFuc(int firstNum,int secondNum);
int SubFuc(int firstNum,int secondNum);
int MulFuc(int firstNum,int secondNum);
int DivFuc(int firstNum,int secondNum);

int Total=0,Right=0;   // 总题数和正确题数 
void SelectAdd()//加法 
{
	printf("\n\n欢迎进入加法题库\n");
	while(TRUE)
	{
		Total++;
		if(AddFuc(rand()%RANGE,rand()%RANGE))   //生成题目并测试 
			Right++;
			printf("无聊的人总是爱做无聊的题啊，输入Y或者y继续\n，输入其它则回主菜单\n");
			char c=getchar();
			getchar();
			if(c!='Y'&&c!='y')break;
			printf("恭喜你继续无聊，看题吧\n"); 
		
	}
	
}

void SelectSub()//减法 
{
	printf("\n\n欢迎进入减法题库\n");
	while(TRUE)
	{
		Total++;
		if(SubFuc(rand()%RANGE,rand()%RANGE))
			Right++;
			printf("无聊的人总是爱做无聊的题啊，输入Y或者y继续\n，输入其它则回主菜单\n");
			char c=getchar();
			getchar();
			if(c!='Y'&&c!='y')break;
			printf("恭喜你继续无聊，看题吧\n"); 
		
	}
	
}

void SelectMul()//乘法 
{
	printf("\n\n欢迎进入乘法题库\n");
	while(TRUE)
	{
		Total++;
		if(MulFuc(rand()%RANGE,rand()%RANGE))
			Right++;
			printf("无聊的人总是爱做无聊的题啊，输入Y或者y继续\n，输入其它则回主菜单\n");
			char c=getchar();
			getchar();
			if(c!='Y'&&c!='y')break;
			printf("恭喜你继续无聊，看题吧\n"); 
		
	}
	
}

void SelectDiv()//除法 
{
	printf("\n\n欢迎进入除法题库\n");
	while(TRUE)
	{
		Total++;
		if(DivFuc(rand()%RANGE,rand()%RANGE))
			Right++;
		printf("无聊的人总是爱做无聊的题啊，输入Y或者y继续\n，输入其它则回主菜单\n");
		char c=getchar();
		getchar();
		if(c!='Y'&&c!='y')break;
		printf("恭喜你继续无聊，看题吧\n"); 
		
	}

}

int AddFuc(int firstNum,int secondNum)//判断加法 
{
	int answer,result;
	printf("%d+%d=",firstNum,secondNum);
	while(scanf("%d",&answer)!=1)
	{
		printf("输入格式有误啦，请再输入一次\n"); 
		getchar();
		printf("%d+%d=",firstNum,secondNum);
		getchar();
	}
	getchar();
	result=firstNum+secondNum;
	if(result==answer)
	{
		printf("恭喜你，无聊度+1\n");
		return RIGHT;
	}
	else 
	{
		printf("这你都没做对 也太蠢了点了\n");
		printf("正确答案是%d\n",result);
		return WRONG;
	}
	
} 

int SubFuc(int firstNum,int secondNum)
{
	int answer,result;
	printf("%d-%d=",firstNum,secondNum);
	while(scanf("%d",&answer)!=1)
	{
		printf("输入格式有误啦，请再输入一次\n"); 
		getchar();
		printf("%d-%d=",firstNum,secondNum);
		getchar();
	}
	getchar();
	result=firstNum-secondNum;
	if(result==answer)
	{
		printf("恭喜你，无聊度+1\n");
		return RIGHT;
	}
	else 
	{
		printf("这你都没做对 也太蠢了点了\n");
		printf("正确答案是%d\n",result);
		return WRONG;
	}
}

int MulFuc(int firstNum,int secondNum)
{
	
	int answer,result;
	printf("%d*%d=",firstNum,secondNum);
	while(scanf("%d",&answer)!=1)
	{
		printf("输入格式有误啦，请再输入一次\n"); 
		getchar();
		printf("%d*%d=",firstNum,secondNum);
		getchar();
	}
	getchar();
	result=firstNum*secondNum;
	if(result==answer)
	{
		printf("恭喜你，无聊度+1\n");
		return RIGHT;
	}
	else 
	{
		printf("这你都没做对 也太蠢了点了\n");
		printf("正确答案是%d\n",result);
		return WRONG;
	}
}

int DivFuc(int firstNum,int secondNum)
{
	int answer,result;
	printf("(保留整数)%d/%d=",firstNum,secondNum);
	while(scanf("%d",&answer)!=1)
	{
		printf("输入格式有误啦，请再输入一次\n"); 
		getchar();
		printf("(保留整数)%d/%d=",firstNum,secondNum);
		getchar();
	}
	getchar();
	result=firstNum/secondNum;
	if(result==answer)
	{
		printf("恭喜你，无聊度+1\n");
		return RIGHT;
	}
	else 
	{
		printf("这你都没做对 也太蠢了点了\n");
		printf("正确答案是%d\n",result);
		return WRONG;
	}
}

void GetSummary()
{
	printf("你看过了%d个无聊的题，你的无聊值是%d\n\n\n",Total,Right);

}

void ClearSummary()
{
	Right=0;
	Total=0;

}

void Menu()
{
	printf("-------------------------------\n");
	printf("1.做加法题\n");
	printf("2.做减法题\n");
	printf("3.做乘法题\n");
	printf("4.做除法题\n");
	printf("5.分数统计\n");	
	printf("6.分数清零\n");
	printf("7.退出\n");
	printf("                       by:fay\n");
	printf("-------------------------------\n");
	printf("请选择序号\n"); 
	
}


int main(int argc, char *argv[])
{
	int choiceNum;
	int end=0;
	srand((unsigned int)time(NULL));
	printf("欢迎来到小学生数学题库\n");
	printf("来了就别走了 你就是小学生了 恭喜你\n");
	while(1)
	{
		Menu();
		while(scanf("%d",&choiceNum))
		{
			if(choiceNum<=7&&choiceNum>=1)
				break;
			else
				printf("选择一个菜单里有的哦\n");
			Menu();
		}
		switch(choiceNum)
		{
			case 1:SelectAdd();break;
			case 2:SelectSub();break;
			case 3:SelectMul();break;
			case 4:SelectDiv();break;
			case 5:GetSummary();break;
			case 6:ClearSummary();break;
			case 7:	end =1;break;
		} 
		if(end==1)
		{
			printf("fay祝你天天开心啊\n");
			break;
		}
		
	}
	return 0;
}



