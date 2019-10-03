#include<stdio.h>
int main()
{
	int x,y,mx,my,a[23][23],g[23][23],i,j;
	for(i=0;i<23;i++)
	for(j=0;j<23;j++)
	a[i][j]=g[i][j]=0;
	scanf("%d%d%d%d",&x,&y,&mx,&my);
	x+=2,y+=2,mx+=2,my+=2;
	g[mx][my]=g[mx+1][my+2]=g[mx+2][my+1]=g[mx-1][my-2]=g[mx-2][my-1]=g[mx+1][my-2]=g[mx+2][my-1]=g[mx-1][my+2]=g[mx-2][my+1]=1;
	a[2][2]=1;
	for(i=3;i<=x;i++)a[2][i]=a[i][2]=1;
	for(j=3;j<=y;j++)
	for(i=3;i<=x;i++)
	{
		if(g[i][j])a[i][j]=0;
		else a[i][j]=a[i-1][j]+a[i][j-1];
	}
	printf("%d ",a[x][y]);
}