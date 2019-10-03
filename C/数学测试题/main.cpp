/*
����
1.�ӷ���
2.������
3.�˷���
4.������
5.�ӷ��ж�
6.�����ж�
7.�����ж�
8.�˷��ж�
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

int Total=0,Right=0;   // ����������ȷ���� 
void SelectAdd()//�ӷ� 
{
	printf("\n\n��ӭ����ӷ����\n");
	while(TRUE)
	{
		Total++;
		if(AddFuc(rand()%RANGE,rand()%RANGE))   //������Ŀ������ 
			Right++;
			printf("���ĵ������ǰ������ĵ��Ⱑ������Y����y����\n����������������˵�\n");
			char c=getchar();
			getchar();
			if(c!='Y'&&c!='y')break;
			printf("��ϲ��������ģ������\n"); 
		
	}
	
}

void SelectSub()//���� 
{
	printf("\n\n��ӭ����������\n");
	while(TRUE)
	{
		Total++;
		if(SubFuc(rand()%RANGE,rand()%RANGE))
			Right++;
			printf("���ĵ������ǰ������ĵ��Ⱑ������Y����y����\n����������������˵�\n");
			char c=getchar();
			getchar();
			if(c!='Y'&&c!='y')break;
			printf("��ϲ��������ģ������\n"); 
		
	}
	
}

void SelectMul()//�˷� 
{
	printf("\n\n��ӭ����˷����\n");
	while(TRUE)
	{
		Total++;
		if(MulFuc(rand()%RANGE,rand()%RANGE))
			Right++;
			printf("���ĵ������ǰ������ĵ��Ⱑ������Y����y����\n����������������˵�\n");
			char c=getchar();
			getchar();
			if(c!='Y'&&c!='y')break;
			printf("��ϲ��������ģ������\n"); 
		
	}
	
}

void SelectDiv()//���� 
{
	printf("\n\n��ӭ����������\n");
	while(TRUE)
	{
		Total++;
		if(DivFuc(rand()%RANGE,rand()%RANGE))
			Right++;
		printf("���ĵ������ǰ������ĵ��Ⱑ������Y����y����\n����������������˵�\n");
		char c=getchar();
		getchar();
		if(c!='Y'&&c!='y')break;
		printf("��ϲ��������ģ������\n"); 
		
	}

}

int AddFuc(int firstNum,int secondNum)//�жϼӷ� 
{
	int answer,result;
	printf("%d+%d=",firstNum,secondNum);
	while(scanf("%d",&answer)!=1)
	{
		printf("�����ʽ����������������һ��\n"); 
		getchar();
		printf("%d+%d=",firstNum,secondNum);
		getchar();
	}
	getchar();
	result=firstNum+secondNum;
	if(result==answer)
	{
		printf("��ϲ�㣬���Ķ�+1\n");
		return RIGHT;
	}
	else 
	{
		printf("���㶼û���� Ҳ̫���˵���\n");
		printf("��ȷ����%d\n",result);
		return WRONG;
	}
	
} 

int SubFuc(int firstNum,int secondNum)
{
	int answer,result;
	printf("%d-%d=",firstNum,secondNum);
	while(scanf("%d",&answer)!=1)
	{
		printf("�����ʽ����������������һ��\n"); 
		getchar();
		printf("%d-%d=",firstNum,secondNum);
		getchar();
	}
	getchar();
	result=firstNum-secondNum;
	if(result==answer)
	{
		printf("��ϲ�㣬���Ķ�+1\n");
		return RIGHT;
	}
	else 
	{
		printf("���㶼û���� Ҳ̫���˵���\n");
		printf("��ȷ����%d\n",result);
		return WRONG;
	}
}

int MulFuc(int firstNum,int secondNum)
{
	
	int answer,result;
	printf("%d*%d=",firstNum,secondNum);
	while(scanf("%d",&answer)!=1)
	{
		printf("�����ʽ����������������һ��\n"); 
		getchar();
		printf("%d*%d=",firstNum,secondNum);
		getchar();
	}
	getchar();
	result=firstNum*secondNum;
	if(result==answer)
	{
		printf("��ϲ�㣬���Ķ�+1\n");
		return RIGHT;
	}
	else 
	{
		printf("���㶼û���� Ҳ̫���˵���\n");
		printf("��ȷ����%d\n",result);
		return WRONG;
	}
}

int DivFuc(int firstNum,int secondNum)
{
	int answer,result;
	printf("(��������)%d/%d=",firstNum,secondNum);
	while(scanf("%d",&answer)!=1)
	{
		printf("�����ʽ����������������һ��\n"); 
		getchar();
		printf("(��������)%d/%d=",firstNum,secondNum);
		getchar();
	}
	getchar();
	result=firstNum/secondNum;
	if(result==answer)
	{
		printf("��ϲ�㣬���Ķ�+1\n");
		return RIGHT;
	}
	else 
	{
		printf("���㶼û���� Ҳ̫���˵���\n");
		printf("��ȷ����%d\n",result);
		return WRONG;
	}
}

void GetSummary()
{
	printf("�㿴����%d�����ĵ��⣬�������ֵ��%d\n\n\n",Total,Right);

}

void ClearSummary()
{
	Right=0;
	Total=0;

}

void Menu()
{
	printf("-------------------------------\n");
	printf("1.���ӷ���\n");
	printf("2.��������\n");
	printf("3.���˷���\n");
	printf("4.��������\n");
	printf("5.����ͳ��\n");	
	printf("6.��������\n");
	printf("7.�˳�\n");
	printf("                       by:fay\n");
	printf("-------------------------------\n");
	printf("��ѡ�����\n"); 
	
}


int main(int argc, char *argv[])
{
	int choiceNum;
	int end=0;
	srand((unsigned int)time(NULL));
	printf("��ӭ����Сѧ����ѧ���\n");
	printf("���˾ͱ����� �����Сѧ���� ��ϲ��\n");
	while(1)
	{
		Menu();
		while(scanf("%d",&choiceNum))
		{
			if(choiceNum<=7&&choiceNum>=1)
				break;
			else
				printf("ѡ��һ���˵����е�Ŷ\n");
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
			printf("fayף�����쿪�İ�\n");
			break;
		}
		
	}
	return 0;
}



