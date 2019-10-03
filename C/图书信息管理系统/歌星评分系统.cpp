#include<stdio.h>
#include<math.h>
#define N 13
#define M 15
float mark[M][N];
float stuave[M];
float teacave[N];
FILE *fp;
int main()
{
	void show();
	int i,j;
	fp=fopen("d:music.txt","r");
	for(i=1;i<M;i++)
		for(j=1;j<N;j++)
			fscanf(fp,"%f",&mark[i][j]);
	float ave;
	for(i=1;i<M;i++)
	{
		int max,min;
		max=min=1;
		for(int m=1;m<N;m++)
		{
			if(mark[i][m]<mark[i][min])min=m;
			if(mark[i][m]>mark[i][max])max=m;
		}

		ave=0;
		for(j=1;j<N;j++)
			if((j!=max)&&(j!=min))
			ave+=1.0*mark[i][j]/10;
		stuave[i]=ave;
	}
	
	for(j=1;j<N;j++)	
	{
		ave=0;
		for(i=1;i<M;i++)
			ave+=fabs(mark[i][j]-stuave[i]);
		teacave[j]=ave;
	}	


	show();

		
	
	
	return 0;
		
}

void show()
{
	printf(" 歌星名次    歌星序号    歌星得分\n");
	printf("------------------------------------\n");
	int stu[M]={0};

	for(int i=1;i<M;i++)	
	{
		int max=0;
		for(int i=1;i<M;i++)
		 if(!stu[i])
	 		if(stuave[i]>stuave[max]||max==0)max=i;	 
 		printf("%6d     %6d       %6.4f",i,max,stuave[max]);
 		printf("\n");
 		stu[max]=1;	
	}
	printf("\n");
	printf(" 评委名次     评委序号    评委得分\n");
	printf("------------------------------------\n");
	int tea[N]={0};
		for(int i=1;i<N;i++)	
	{
		int min=0;
		for(int i=1;i<N;i++)
		 if(!tea[i])
	 		if(teacave[i]<teacave[min]||min==0)min=i;
 		printf("%6d     %6d       %6.4f",i,min,teacave[min]);
 		printf("\n");
		 tea[min]=1;
		 
	}
}